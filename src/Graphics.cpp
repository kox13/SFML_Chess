#include "Graphics.h"

sf::Texture* Graphics::LoadTextureFromFile(const std::string& filename) {
	// TODO: Check if a file has the correct extension
	sf::Texture* texture = new sf::Texture;
	texture->loadFromFile(filename); // TODO: Handle errors

	return texture;
}

sf::Font* Graphics::LoadFontFromFile(const std::string& filename) {
	// TODO: Check if a file has the correct extension
	sf::Font* font = new sf::Font;
	font->loadFromFile(filename); // TODO: Handle errors

	return nullptr;
}

sf::Text* Graphics::CreateText(const std::string& text, unsigned int characterSize, sf::Color fillColor, sf::Text::Style textStyle) {
	// TODO

	return nullptr;
}
