#pragma once
#include <string>
#include <cassert>
#include <SFML/Graphics.hpp>

//Thread-unsafe
//Example of Singleton pattern usage
//Here I just create only one unique texture

class ResourceManager
{
	std::string m_path;
	std::string m_filename;
	sf::Texture m_texture;

	ResourceManager(const std::string& path, const std::string& filename);

public:
	static ResourceManager* m_manager;
	ResourceManager(ResourceManager&) = delete; //copy-constructor isn't allowed
	void operator=(const ResourceManager&) = delete; //operator= isn't allowed
	
	static ResourceManager* getInstance(const std::string& path, const std::string& filename);

	const sf::Texture &getTexture();
};