#pragma once

#include "AssetsManager.h"
#include "StateManager.h"
#include <SFML/Graphics/RenderWindow.hpp>

struct Context {
	AssetsManager& GetAssetsManager() const { return *m_AssetsManager; }
	StateManager& GetGameState() const { return *m_GameState; }
	sf::RenderWindow& GetWindow() const { return *m_Window; }

	sf::Vector2u GetWindowCenter() const { return sf::Vector2u(m_Window->getSize().x / 2, m_Window->getSize().y / 2); }
private:
	Context()
		: m_AssetsManager(std::make_unique<AssetsManager>()),
		m_GameState(std::make_unique<StateManager>()),
		m_Window(std::make_unique<sf::RenderWindow>())
	{}
	~Context() = default;

	Context& operator=(Context& other) = delete;
	Context& operator=(const Context&& other) = delete;

	std::unique_ptr<AssetsManager> m_AssetsManager;
	std::unique_ptr<StateManager> m_GameState;
	std::unique_ptr<sf::RenderWindow> m_Window;

	friend class Game; // Only Game class can create Context, as the constructor is private
};