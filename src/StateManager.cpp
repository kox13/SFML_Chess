#include "StateManager.h"
#include "State.h"

#include <cassert>

StateManager::StateManager()
	: m_Replace(false), m_NewState(nullptr)
{}

void StateManager::Initialize() {}

void StateManager::Cleanup() {}

void StateManager::Replace(std::unique_ptr<State> state) {
	assert(state != nullptr);

	m_NewState = std::move(state);
	m_Replace = true;
}

void StateManager::Push(std::unique_ptr<State> state) {
	assert(state != nullptr);

	m_NewState = std::move(state);
}

void StateManager::Pop() {
	if (!m_States.empty())
		m_States.pop();
}

void StateManager::ChangeState() {
	if (m_NewState == nullptr)
		return;

	if(m_Replace)
		Pop();

	m_States.push(std::move(m_NewState));

	if(State* state = GetCurrent())
		state->Initialize();

	m_NewState = nullptr;
	m_Replace = false;
}

void StateManager::Update(float deltaTime) {
	if (State* state = GetCurrent())
		state->Update(deltaTime);
}

void StateManager::ProcessInput(sf::Event& event, sf::RenderWindow& window) {
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
			break;
		}

		if (State* state = GetCurrent())
			state->ProcessInput(event);
	}
}

void StateManager::Draw(sf::RenderWindow& window) {
	if (State* state = GetCurrent()) {
		window.clear();
		state->Draw();
		window.display();
	}
}
