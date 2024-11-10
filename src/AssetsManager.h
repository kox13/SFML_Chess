#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>
#include <memory>

class AssetsManager {
public:
	static AssetsManager& Instance();

	static bool Initialize();
	static void Shutdown();

	std::shared_ptr<sf::Font> GetFont() const { return m_Font; } 
	std::shared_ptr<sf::Texture> GetTexture(const std::string& name) const { return m_Textures.at(name); } //TODO: Handle edge cases

private:
	AssetsManager() = default;
	~AssetsManager() = default;

	bool LoadFont();
	bool LoadTextures();

private:
	std::unordered_map<std::string, std::shared_ptr<sf::Texture>> m_Textures;
	std::shared_ptr<sf::Font> m_Font;
};

