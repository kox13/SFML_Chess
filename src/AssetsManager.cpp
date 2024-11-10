#include "AssetsManager.h"
#include "Graphics.h"
#include <filesystem>

namespace fs = std::filesystem;

static AssetsManager* s_Instance = nullptr;

AssetsManager& AssetsManager::Instance() {
	return *s_Instance;
}

bool AssetsManager::Initialize() {
	// TODO: Log if s_Instance is already initialized
	if (!s_Instance) {
		s_Instance = new AssetsManager;

		if (s_Instance->LoadFont() && s_Instance->LoadTextures())
			return true;
	}

	return false;
}

void AssetsManager::Shutdown() {
	delete s_Instance;
}

bool AssetsManager::LoadFont() {
	// TODO: Handle edge cases
	fs::path fontDir = fs::current_path() / "assets" / "font";

	// Even though the game uses only one .ttf file the program should still loop through all files in case 
	// other files were put in the directory
	for (const auto& entry : fs::directory_iterator(fontDir)) {
		fs::path path = entry.path();

		if (path.extension() == ".ttf") {
			std::shared_ptr<sf::Font> font(Graphics::LoadFontFromFile(path.string()));
			m_Font = font;

			return true;
		}
	}

	return false;
}

bool AssetsManager::LoadTextures() {
	// TODO: Handle edge cases
	fs::path texturesDir = fs::current_path() / "assets" / "textures";

	for (const auto& entry : fs::directory_iterator(texturesDir)) {
		fs::path path = entry.path();

		if (path.extension() == ".png") {
			std::shared_ptr<sf::Texture> texture(Graphics::LoadTextureFromFile(path.string()));
			m_Textures[path.stem().string()] = texture;
		}
	}

	// TODO: Check if all default textures were loaded
	if (m_Textures.size() < 6)
		return false;

	return true;
}
