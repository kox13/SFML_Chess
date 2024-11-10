#include "Graphics.h"
#include "AssetsManager.h"

sf::Texture* Graphics::LoadTextureFromFile(const std::string& filename) {
	// TODO: Check if a file has the correct extension
	sf::Texture* texture = new sf::Texture;

	if (texture->loadFromFile(filename))
		return texture; // TODO: Handle errors

	return texture;
}

sf::Font* Graphics::LoadFontFromFile(const std::string& filename) {
	// TODO: Check if a file has the correct extension
	sf::Font* font = new sf::Font;

	if (font->loadFromFile(filename))
		return font; // TODO: Handle errors

	return nullptr;
}

sf::Text* Graphics::CreateText(const std::string& text, unsigned int characterSize, sf::Color fillColor, sf::Text::Style textStyle) {
	sf::Text* newText = new sf::Text;

	newText->setFont(*AssetsManager::Instance().GetFont());
	newText->setString(text);
	newText->setCharacterSize(characterSize);
	newText->setFillColor(fillColor);
	newText->setStyle(textStyle);

	return newText;
}

sf::Sprite* Graphics::CreateSprite(sf::Texture& texture) {
	sf::Sprite* sprite = new sf::Sprite;

	sprite->setTexture(texture);

	return sprite;
}
