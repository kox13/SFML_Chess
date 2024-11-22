#pragma once

#include "State.h"
#include "Button.h"

class MainMenuState : public State {
public:
	MainMenuState(Context& context);
	~MainMenuState() override = default;

	void Initialize() override;
	void Cleanup() override {};

	void ProcessInput(sf::Event& event) override;
	void Update(float deltaTime) override {};
	void Draw() override;

private:
	Button* m_StartButton;
	Button* m_QuitButton;

	void StartGame();
	void QuitGame();
};

