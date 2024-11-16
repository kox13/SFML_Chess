#include "Game.h"

#include <iostream>
#include <SFML/Graphics.hpp>

Game::Game()
	: m_Run(true)
{}

void Game::Run() {
    sf::RenderWindow& window = *m_Context.m_Window;
    window.create(sf::VideoMode(1337, 766), "SFML works!");

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    float deltaTime;
    sf::Clock clock;
    clock.restart();

    while (window.isOpen()) {
        deltaTime = clock.restart().asSeconds();

        m_Context.m_GameState->ChangeState();
        m_Context.m_GameState->ProcessInput();
        m_Context.m_GameState->Update(deltaTime);
        m_Context.m_GameState->Draw();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}
