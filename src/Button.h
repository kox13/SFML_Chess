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

// TODO: MouseEntered and MouseLeft events
class Button {
public:
	Button(sf::Font& font, const std::string& text, float x, float y, float width, float height, sf::Color textColor, sf::Color backgroundColor);
	Button(sf::Font& font, const std::string& text, float x, float y, float width, float height);
	~Button() = default;	

	void SetTextColor(sf::Color color);
	void SetBackgroundColor(sf::Color color);

	template<typename T>
	void SetOnClick(void(T::*function)(), T* instance);
	void SetOnClick(void(*function)());

	void Draw(sf::RenderWindow& window) const;
	void ProcessInput(sf::Event& event);

private:
	bool IsInBounds(float x, float y) const;

private:
	sf::RectangleShape m_Rect;
	sf::Text m_Text;
	std::function<void()> m_OnClick;

	static const sf::Color s_DEFAULT_TEXT_COLOR;
	static const sf::Color s_DEFAULT_BACKGROUND_COLOR;
};

template<typename T>
inline void Button::SetOnClick(void(T::*function)(), T* instance) {
	assert(instance != nullptr && function != nullptr);
	m_OnClick = std::bind(function, instance);
}