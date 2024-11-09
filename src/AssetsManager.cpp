#include "AssetsManager.h"
#include <filesystem>

static AssetsManager* s_Instance;

AssetsManager::AssetsManager() {
	LoadTextures();
	LoadFont();
}

AssetsManager& AssetsManager::Instance() {
	return *s_Instance;
}

void AssetsManager::Initialize() {
	if(!s_Instance)
		s_Instance = new AssetsManager;
}

void AssetsManager::Shutdown() {
	delete s_Instance;
}

void AssetsManager::LoadFont() {
	// TODO
}

void AssetsManager::LoadTextures() {
	// TODO
}
