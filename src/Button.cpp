#include "Button.h"

#include <SFML/Window/Event.hpp>

const sf::Color Button::s_DEFAULT_TEXT_COLOR = sf::Color::White;
const sf::Color Button::s_DEFAULT_BACKGROUND_COLOR = sf::Color::Red;

Button::Button(sf::Font& font, const std::string& text, float x, float y, float width, float height, sf::Color textColor, sf::Color backgroundColor)
	: m_Rect(sf::Vector2f(width, height))
{
	m_Text.setFont(font);
	m_Text.setString(text);
	m_Text.setFillColor(textColor);
	m_Text.setPosition(x, y);
	m_Rect.setPosition(x, y);
	m_Rect.setFillColor(backgroundColor);
}

Button::Button(sf::Font& font, const std::string& text, float x, float y, float width, float height)
	: m_Rect(sf::Vector2f(width, height))
{
	m_Text.setFont(font);
	m_Text.setString(text);
	m_Text.setFillColor(s_DEFAULT_TEXT_COLOR);
	m_Text.setPosition(x, y);
	m_Rect.setPosition(x, y);
	m_Rect.setFillColor(s_DEFAULT_BACKGROUND_COLOR);
}

void Button::SetTextColor(sf::Color color) {
	m_Text.setFillColor(color);
}

void Button::SetBackgroundColor(sf::Color color) {
	m_Rect.setFillColor(color);
}

void Button::Draw(sf::RenderWindow& window) const {
	window.draw(m_Rect);
	window.draw(m_Text);
}

void Button::ProcessInput(sf::Event& event) {
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left &&
		IsInBounds(event.mouseButton.x, event.mouseButton.y) && m_OnClick) {
		m_OnClick();
		return;
	}
}

bool Button::IsInBounds(float x, float y) const {
	return m_Rect.getGlobalBounds().contains(x, y);
}

void Button::SetOnClick(void(*function)()) {
	assert(function != nullptr);
	m_OnClick = function;
}
