#include "AssetsManager.h"
#include "Logger.h"

void AssetsManager::AddTexture(unsigned int id, const std::string& path) {
	if (m_Textures.find(id) != m_Textures.end()) {
		LOG_WARNING("Texture with id %i, already exists", id);
		return;
	}

	// TODO: Check if the path is correct and if it has a supported SFML extension, 
	// if not log/show error and stop the program

	std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();

	if (texture->loadFromFile(path))
		m_Textures[id] = texture;
	else
		LOG_ERROR("Texture from file %s was not loaded correctly", path);
}

void AssetsManager::SetFont(const std::string& path) {
	if (m_Font) {
		LOG_WARNING("Font is already set");
		return;
	}

	// TODO: Check if the path is correct and if it has a supported SFML extension, 
	// if not log/show error, if m_Font is set do nothing more, if not try to load the default font, else stop the program

	m_Font = std::make_shared<sf::Font>();

	if(!m_Font->loadFromFile(path))
		LOG_ERROR("Font from file %s was not loaded correctly", path);
}
