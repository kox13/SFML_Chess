#include "Button.h"


const sf::Color Button::s_DEFAULT_TEXT_COLOR = sf::Color::White;
const sf::Color Button::s_DEFAULT_BACKGROUND_COLOR = sf::Color::Transparent;

Button::Button(std::shared_ptr<sf::Font> font, const std::string& text, int x, int y, int width, int height, sf::Color textColor, sf::Color backgroundColor)
	: m_Font(font), m_Rect(sf::Vector2f(width, height)), m_TextColor(textColor), m_BackgroundColor(backgroundColor)
{
	m_Text.setString(text);
	m_Text.setPosition(x, y);
	m_Rect.setPosition(x, y);
}

Button::Button(std::shared_ptr<sf::Font> font, const std::string& text, int x, int y, int width, int height)
	: m_Font(font), m_Rect(sf::Vector2f(width, height)), m_TextColor(s_DEFAULT_TEXT_COLOR), m_BackgroundColor(s_DEFAULT_BACKGROUND_COLOR)
{
	m_Text.setString(text);
	m_Text.setPosition(x, y);
	m_Rect.setPosition(x, y);
}

void Button::SetTextColor(sf::Color color) {
	m_TextColor = color;
}

void Button::SetBackgroundColor(sf::Color color) {
	m_BackgroundColor = color;
}

void Button::Draw(sf::RenderWindow& window) const {
	window.draw(m_Rect);
	window.draw(m_Text);
}

void Button::SetOnClick(void(*function)()) {
	assert(function != nullptr);
	m_OnClick = function;
}
