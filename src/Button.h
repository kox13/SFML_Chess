#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <memory>
#include <string>
#include <functional>
#include <cassert>

class Button {
public:
	Button(std::shared_ptr<sf::Font> font, const std::string& text, int x, int y, int width, int height, sf::Color textColor, sf::Color backgroundColor);
	Button(std::shared_ptr<sf::Font> font, const std::string& text, int x, int y, int width, int height);
	~Button() = default;	

	void SetTextColor(sf::Color color);
	void SetBackgroundColor(sf::Color color);
	void Draw(sf::RenderWindow& window) const;

	template<typename T>
	void SetOnClick(void(*function)(), T* instance);
	void SetOnClick(void(*function)());

private:
	sf::RectangleShape m_Rect;
	std::shared_ptr<sf::Font> m_Font;
	sf::Text m_Text;
	std::function<void()> m_OnClick;
	sf::Color m_TextColor = s_DEFAULT_TEXT_COLOR;
	sf::Color m_BackgroundColor = s_DEFAULT_BACKGROUND_COLOR;

	static const sf::Color s_DEFAULT_TEXT_COLOR;
	static const sf::Color s_DEFAULT_BACKGROUND_COLOR;
};

template<typename T>
inline void Button::SetOnClick(void(*function)(), T* instance) {
	assert(instance != nullptr && function != nullptr);
	m_OnClick = std::bind(function, instance);
}
