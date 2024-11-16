#pragma once

#include "AssetsManager.h"
#include "StateManager.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>

struct Context {
	AssetsManager& GetAssetsManager() const { return *m_AssetsManager; }
	StateManager& GetGameState() const { return *m_GameState; }
	sf::RenderWindow& GetWindow() const { return *m_Window; }

private:
	Context()
		: m_AssetsManager(std::make_unique<AssetsManager>()),
		m_GameState(std::make_unique<StateManager>(*this)),
		m_Window(std::make_unique<sf::RenderWindow>())
	{}
	~Context() = default;

	Context& operator=(Context& other) = delete;
	Context& operator=(const Context&& other) = delete;

	std::unique_ptr<AssetsManager> m_AssetsManager;
	std::unique_ptr<StateManager> m_GameState;
	std::unique_ptr<sf::RenderWindow> m_Window;

	friend class Game;
};

class Game {
public:
	Game();
	~Game() = default;

	void Run();
private:
	bool m_Run;
	Context m_Context;
};

