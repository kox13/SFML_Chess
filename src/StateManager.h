#pragma once

#include "State.h"

#include <memory>
#include <stack>

struct Context;

class StateManager {
public:
	StateManager(Context& context);
	~StateManager() = default;

	void Initialize();
	void Cleanup();

	void Replace(std::unique_ptr<State> state);
	void Push(std::unique_ptr<State> state);
	void Pop();
	void ChangeState();

	State* GetCurrent() const { return m_States.empty() ? nullptr : m_States.top().get(); }

	void Update(float deltaTime);
	void ProcessInput();
	void Draw();

private:
	Context& m_Context;
	std::stack<std::unique_ptr<State>> m_States;
	std::unique_ptr<State> m_NewState;
	bool m_Replace;
};

