#include <SFML/Graphics.hpp>
#include <math.h>
#include <chrono>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Pendulum - RK4");

    sf::Font font("Arial.ttf");

    sf::Text text(font);
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(20); // in pixels

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
    float lineLength = 1; // meters

    // Initial conditions
    float t_0 = 0;
    float h = 0.0001;
    float theta_0 = M_PI / 15;
    float omega_0 = 0;

    // Initial k's
    float k1_theta = omega_0;
    float k1_omega = theta_0;

    // Run the program as long as the window is open
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
        // k's
        float k2_theta = omega_0 + k1_omega * h /2;
        float k2_omega = - gravity / lineLength * std::sin(theta_0 + k1_theta * h / 2);

        float k3_theta = omega_0 + k2_omega * h /2;
        float k3_omega = - gravity / lineLength * std::sin(theta_0 + k2_theta * h / 2);

        float k4_theta = omega_0 + k3_omega * h;
        float k4_omega = - gravity / lineLength * std::sin(theta_0 + k3_theta * h);
        
        // Omega
        float omega;
        omega = omega_0 + h * (k1_omega + 2*k2_omega + 2*k3_omega + k4_omega) / 6;
        // Theta
        float theta;
        theta = theta_0 + h * (k1_theta + 2*k2_theta + 2*k3_theta + k4_theta) / 6;
        
        omega_0 = omega;
        theta_0 = theta;  
        k1_theta = omega_0;
        k1_omega = - gravity / lineLength * std::sin(theta_0);

        float scale = 0.1f; // pixels per meter
        circle.setPosition({center_x - radius + scale * lineLength * pixels * std::sin(theta),
                            center_y - radius + scale * lineLength * pixels * std::cos(theta)});

        line[1].position.x = center_x + scale * lineLength * pixels * std::sin(theta);
        line[1].position.y = scale * lineLength * pixels * std::cos(theta);
            
        float energy = omega*omega / 2 - std::cos(theta);
        text.setString("(not exactly) Energy: " + std::to_string(energy));

        window.clear();
        window.draw(line.data(), line.size(), sf::PrimitiveType::Lines);
        window.draw(circle);
        window.draw(text);
        window.display();
    }
}