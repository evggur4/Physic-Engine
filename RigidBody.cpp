#include <SFML/Graphics.hpp>

struct RigidBody 
{
    sf::Vector2f position;
    sf::Vector2f velocity;

    float mass;
    float inverseMass;
    sf::Vector2f netForce;

    RigidBody(float m) {
        mass = m;
        if (mass > 0.0f){
            inverseMass = 1.0f / mass;
        }else{
            inverseMass = 0.0f;
            mass = 0.0f;
        }
    }

    void addForce(const sf::Vector2f& force) {
        netForce += force;
    }

    void clearForces() {
        netForce = sf::Vector2f(0.0f, 0.0f);
    }

    void updatePhysics(RigidBody& body, float dt){
        sf::Vector2f acceleration = body.netForce * dt;

        body.velocity += acceleration * dt;

        body.position += body.velocity * dt;
        
        body.clearForces();    
    }

};

int main()
{
    RigidBody body(1.0);

    const sf::Vector2f gravity(0.0f, 9.8f);
    float dragCoefficient = 0.5f;
    sf::Vector2f dragForce = -body.velocity * dragCoefficient;

    body.addForce(gravity * body.mass);
    body.addForce(dragForce);


}