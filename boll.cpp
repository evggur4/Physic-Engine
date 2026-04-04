#include <SFML/Graphics.hpp>

sf::RenderWindow window(sf::VideoMode(800.f, 600.f), "Boll");

int main(){
    sf::CircleShape boll(10.f);
    boll.setOrigin(10.f, 10.f);
    boll.setPosition(400.f, 300.f);

    sf::Vector2f velocity(100 + std::rand() % 50, 100 + std::rand() % 50);

    sf::Clock clock;

    sf::Event event;
    while (window.isOpen()){
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed){
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    velocity.x *= 2;
                    velocity.y *= 2;
                }else{
                    velocity.x /= 2;
                    velocity.y /= 2;
                }
            }
            if (event.type == sf:: Event::KeyPressed){
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
                        boll.setPosition(10 + rand() % 750, 10 + rand() % 550);
                        velocity.x = 0 + rand() % 200;
                        velocity.y = 0 + rand() % 200;
                    }
                }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
                    velocity.x = velocity.x * 64;
                    velocity.y = velocity.y * 64;
                }
            }
        

        float dt = clock.restart().asSeconds();

        float top = boll.getRadius(), bottom = 600.f - boll.getRadius();
        float left = boll.getRadius(), right = 800.f - boll.getRadius();

        boll.setPosition(boll.getPosition().x + velocity.x * dt, boll.getPosition().y + velocity.y *dt);


        if (boll.getPosition().x > right){boll.setPosition(right, boll.getPosition().y); velocity.x = -velocity.x;}
        if (boll.getPosition().x < left){boll.setPosition(left, boll.getPosition().y); velocity.x = -velocity.x ;}
        if (boll.getPosition().y > bottom){boll.setPosition(boll.getPosition().x, bottom); velocity.y = -velocity.y;}
        if (boll.getPosition().y < top){boll.setPosition(boll.getPosition().x, top); velocity.y = -velocity.y;}

        boll.setFillColor(sf::Color::Green);

        window.clear(sf::Color::Black);
        window.draw(boll);
        window.display();
    }
    return 0;   
}