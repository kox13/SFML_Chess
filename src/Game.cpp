#include "Game.h"
#include "AssetsManager.h"
#include "Logger.h"
	
Game::Game() 
    : m_Run(true)
{
    if (!InitializeSystems())
        m_Run = false;
}

Game::~Game() {
    ShutdownSystems();
}

void Game::Run() {
    // TODO: Log error
    if (!m_Run)
        return;

    sf::RenderWindow window(sf::VideoMode(1366, 768), "SFML works!");
    sf::Texture texture;
    texture.loadFromFile("./assets/textures/b_king.png");

    sf::Sprite sprite;
    sprite.setTexture(texture);

    while (window.isOpen() && m_Run) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        window.draw(sprite);
        window.display();
    }
}

bool Game::InitializeSystems() {
	return AssetsManager::Initialize() && 
           Logger::Initialize();
}

void Game::ShutdownSystems() {
	AssetsManager::Shutdown();
    Logger::Shutdown();
}
