#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>
#include <memory>

class AssetsManager {
public:
	AssetsManager& Instance();

	void Initialize();
	void Shutdown();

	std::shared_ptr<sf::Font> GetFont() const { return m_Font; }

private:
	AssetsManager();
	~AssetsManager() = default;

	void LoadFont();
	void LoadTextures();

private:
	std::unordered_map<std::string, std::shared_ptr<sf::Texture>> m_Textures;
	std::shared_ptr<sf::Font> m_Font;
};

