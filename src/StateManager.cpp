#include "StateManager.h"
#include "State.h"

#include <cassert>

StateManager::StateManager(Context& context)
	: m_Context(context), m_Replace(false), m_NewState(nullptr)
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

void StateManager::ProcessInput() {

	if (State* state = GetCurrent())
		state->ProcessInput();
}

void StateManager::Draw() {
	if (State* state = GetCurrent())
		state->Draw();
}
