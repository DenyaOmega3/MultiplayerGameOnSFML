#include "ResourceManager.h"

ResourceManager* ResourceManager::m_manager = nullptr;

ResourceManager::ResourceManager(const std::string &path, const std::string &filename) :
	m_path(path), m_filename(filename)
{
	assert(m_texture.loadFromFile(path+filename),"Cannot be loaded");
}

ResourceManager* ResourceManager::getInstance(const std::string& path, const std::string& filename)
{
	if (m_manager == nullptr) {
		m_manager = new ResourceManager(path, filename);
	}
	return m_manager;
}

sf::Texture ResourceManager::getTexture() {
	return m_texture;
}
