#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "utils.h"

int oldmain() {
    configureLogger();

    b2Vec2 gravity(0.0f, -10.0f);
    b2World world(gravity);

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position = b2Vec2(0.f, 0.f);
    b2Body *body = world.CreateBody(&bodyDef);

    b2PolygonShape b2shape;
    b2shape.SetAsBox(1.f, 1.f);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &b2shape;
    fixtureDef.density = 0.01f;
    fixtureDef.friction = 0.0f;
    fixtureDef.restitution = 1.0f;
    auto fixture = body->CreateFixture(&fixtureDef);

    // SFML
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");
    window.setFramerateLimit(FRAME_RATE_LIMIT);


    GameObject g(fixture);


    sf::Clock clock;

    while (window.isOpen()) {
        sf::Time elapsedTime = clock.restart();
        world.Step(elapsedTime.asSeconds(), 8, 3);

        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        g.updatePhysics();

        window.clear();
        window.draw(g);
        window.display();
    }

    return 0;
}
