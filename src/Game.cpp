#include "Game.h"
#include "Logger.h"
#include "MainMenuState.h"

#include <iostream>
#include <SFML/Graphics.hpp>

Game::Game()
	: m_Run(true)
{}

void Game::Run() {
    Logger::Initialize();
    
    StateManager& gameState = m_Context.GetGameState();
    sf::RenderWindow& window = m_Context.GetWindow();
    window.create(sf::VideoMode(1337, 766), "SFML works!");

    m_Context.GetAssetsManager().SetFont("assets/font/RobotoMono-Regular.ttf");

    float deltaTime;
    sf::Clock clock;
    clock.restart();

    MainMenuState* mainMenu = new MainMenuState(m_Context);
    gameState.Push(std::make_unique<MainMenuState>(*mainMenu));

    sf::Event event;

    while (window.isOpen() && m_Run) {
        deltaTime = clock.restart().asSeconds();

        gameState.ChangeState();
        gameState.ProcessInput(event, window);
        gameState.Update(deltaTime);
        gameState.Draw(window);
    }

    Logger::Shutdown();
}
