#pragma once

#include <SFML/Window/Event.hpp>

struct Context;

class State {
public:
	State(Context& context) : m_Context(context) {};
	virtual ~State() = default;

	virtual void Initialize() = 0;
	virtual void Cleanup() = 0;

	virtual void Pause() {}
	virtual void Resume() {}

	virtual void ProcessInput(sf::Event& event) = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Draw() = 0;

protected:
	Context& m_Context;
};

