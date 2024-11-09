#pragma once
#include <SFML/Graphics.hpp>
#include <string>

namespace Graphics {
	sf::Texture* LoadTextureFromFile(const std::string& filename);
	sf::Font* LoadFontFromFile(const std::string& filename);
	sf::Text* CreateText(const std::string& text, unsigned int characterSize = 16, 
						 sf::Color fillColor = sf::Color::White, sf::Text::Style textStyle = sf::Text::Regular);
}