#pragma once

class State {
public:
	State() = default;
	virtual ~State() = default;

	virtual void Initialize() = 0;
	virtual void Cleanup() = 0;

	virtual void Pause() {}
	virtual void Resume() {}

	virtual void ProcessInput() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Draw() = 0;
};

