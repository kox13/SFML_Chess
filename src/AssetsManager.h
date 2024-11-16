#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>

#include <unordered_map>
#include <memory>

// TODO: Multiple fonts?????
class AssetsManager {
public:
	AssetsManager() = default;
	~AssetsManager() = default;

	void AddTexture(unsigned int id, const std::string& path);
	void SetFont(const std::string& path);

	std::shared_ptr<sf::Texture> GetTexture(unsigned int id) const { return m_Textures.find(id) == m_Textures.end() ? nullptr : m_Textures.at(id); }
	std::shared_ptr<sf::Font> GetFont() const { return m_Font; }
private:
	std::unordered_map<unsigned int, std::shared_ptr<sf::Texture>> m_Textures;
	std::shared_ptr<sf::Font> m_Font;
};

