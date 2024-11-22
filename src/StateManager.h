#pragma once

#include "State.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include <memory>
#include <stack>

class StateManager {
public:
	StateManager();
	~StateManager() = default;

	void Initialize();
	void Cleanup();

	void Replace(std::unique_ptr<State> state);
	void Push(std::unique_ptr<State> state);
	void Pop();
	void ChangeState();

	State* const GetCurrent() const { return m_States.empty() ? nullptr : m_States.top().get(); }

	void Update(float deltaTime);
	void ProcessInput(sf::Event& event, sf::RenderWindow& window);
	void Draw(sf::RenderWindow& window);

private:
	std::stack<std::unique_ptr<State>> m_States;
	std::unique_ptr<State> m_NewState;
	bool m_Replace;
};

