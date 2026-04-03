#include <SFML/Graphics.hpp>


float Width = 800.f;
float Hight = 600.f;
sf::RenderWindow window(sf::VideoMode(Width, Hight), "PhysicEngine");

int main(){

    sf::Event event;
    while (window.isOpen()){

        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }

        window.clear(sf::Color::Black);


        window.display();
    }
}