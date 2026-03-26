#include <SFML/Graphics.hpp>
#include <math.h>
#include <chrono>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Pendulum");

    float pixels = 3779.5275591;
    // Center of circunference of movement
    float center_x = 400; // pixels
    float center_y = 0; // pixels

    
    // Circle
    float radius = 20;
    sf::CircleShape circle(radius);
    circle.setFillColor(sf::Color::White);
    circle.setPosition({center_x - radius, center_y - radius});
    // Line
    std::array line =
        {
            sf::Vertex{sf::Vector2f(center_x, 0)}, // the center of circunference
            sf::Vertex{sf::Vector2f(center_x, center_y)}};
 

    float gravity = 9.8 ;     // meters per second^2 
    float lineLength = 0.1; // meters

    float theta = M_PI / 4;
    float omega = 0;

    // Time
    using clock = std::chrono::high_resolution_clock;

    auto t0 = std::chrono::high_resolution_clock::now();

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        auto t1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> dt = t1 - t0;
        t0 = t1;

        float deltaTime = dt.count();
        //float dt = 0.00001; // clock.restart().asSeconds(); // delta time

        // Dynamics
        float alpha = -(gravity / lineLength) * std::sin(theta);
        omega += alpha * deltaTime;
        theta += omega * deltaTime;

        circle.setPosition({center_x - radius + lineLength * pixels * std::sin(theta),
                            center_y - radius + lineLength * pixels * std::cos(theta)});

        line[1].position.x = center_x + lineLength * pixels * std::sin(theta);
        line[1].position.y =   lineLength * pixels * std::cos(theta);

        window.clear();
        window.draw(line.data(), line.size(), sf::PrimitiveType::Lines);
        window.draw(circle);
        window.display();
    }
}