#include <SFML/Graphics.hpp>
#include <cmath>

sf::RenderWindow window(sf::VideoMode(800, 600), "Lesson02");
int particleCount = 2000;
sf::VertexArray ParticleSystem(sf::Points, particleCount);


sf::Vector2f velociti(0, 0);
int main (){

    for (int i = 0; i < particleCount; ++i)
    {
    float x = static_cast<float>(rand() % 800);
    float y = static_cast<float>(rand() % 600);

    ParticleSystem[i].position = sf::Vector2f(x, y);
    ParticleSystem[i].color = sf::Color(150, 50 + rand() % 150, 0);
    }   

    sf::Clock clock;

    while (window.isOpen())
    {   
        float DT = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                for (int i = 0; i < particleCount; ++i)
                {   
                    sf::Vector2f mousPos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                    sf::Vector2f direction = mousPos - ParticleSystem[i].position;

                    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);
                    
                    sf::Vector2f force(0.f, 0.f); 

                    if (distance > 1.f )
                    {
                        sf::Vector2f normalizedDir = direction / distance;

                        float forceMagnitude = 50000.f / distance;

                        force += normalizedDir * forceMagnitude;

                        ParticleSystem[i].position.x += force.x * DT * 200 ;
                        ParticleSystem[i].position.y += force.y * DT * 200;  
                        
                    }
                }
            }
            
            window.clear(sf::Color::Black);

            window.draw(ParticleSystem);

            window.display();


        }
        
    }

    return 0;
}