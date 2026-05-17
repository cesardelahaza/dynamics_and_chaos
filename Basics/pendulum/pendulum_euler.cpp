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
 
    // Parameters
    float gravity = 9.8 ;   // meters per second^2 
    float lineLength = 0.1; // meters

    // Initial conditions
    float t_0 = 0;
    float h = 0.0001;
    float theta_0 = M_PI / 5;
    float omega_0 = 0;

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

        // Dynamics
        float theta;
        float omega;
        omega = h * (-gravity * std::sin(theta_0) / lineLength) + omega_0;
        theta = h * omega_0 + theta_0;
        omega_0 = omega;
        theta_0 = theta;       

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