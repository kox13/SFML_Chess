#include "MainMenuState.h"
#include "Context.h"
#include "Logger.h"

MainMenuState::MainMenuState(Context& context)
	: State(context), m_StartButton(nullptr), m_QuitButton(nullptr)
{}

void MainMenuState::Initialize() {
	sf::RenderWindow& window = m_Context.GetWindow();
	sf::Vector2u center = m_Context.GetWindowCenter();

	m_StartButton = new Button(*m_Context.GetAssetsManager().GetFont(), "Start", center.x - 100, center.y - 50, 200, 50);
	m_QuitButton = new Button(*m_Context.GetAssetsManager().GetFont(), "Quit", center.x - 100, center.y + 50, 200, 50);

	m_StartButton->SetOnClick<MainMenuState>(&MainMenuState::StartGame, this);
	m_QuitButton->SetOnClick<MainMenuState>(&MainMenuState::QuitGame, this);
}

void MainMenuState::ProcessInput(sf::Event& event) {
	if (event.type == sf::Event::MouseButtonPressed) {
		m_StartButton->ProcessInput(event);
		m_QuitButton->ProcessInput(event);
	}
}

void MainMenuState::Draw() {
	m_StartButton->Draw(m_Context.GetWindow());
	m_QuitButton->Draw(m_Context.GetWindow());
}

void MainMenuState::StartGame() {
	LOG_CMESSAGE(Logger::Color::BLUE, "Button works!");
}

void MainMenuState::QuitGame() {
	m_Context.GetWindow().close();
}
