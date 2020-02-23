/*
** EPITECH PROJECT, 2020
** - Project name
** File description:
** - File description
*/

#include <utility>
#include <vector>
#include <iostream>
#include "Debug.hpp"
#include "Utils.hpp"

sf::Texture &Utils::LoadTexture(std::string const &texture_path)
{
    static std::vector<std::pair<std::string, sf::Texture> > list_loaded_texture;
    sf::Texture texture;

    for (std::pair<std::string, sf::Texture> &pair : list_loaded_texture) {
        if (pair.first == texture_path) {
            Debug::Log("Reuse texture");
            return (pair.second);
        }
    }
    if (!texture.loadFromFile(texture_path)) {
        throw std::runtime_error("Invalid texture file.");
    }
    Debug::Log("Load new texture");
    list_loaded_texture.emplace_back(std::pair<std::string, sf::Texture>(texture_path, texture));
    return (list_loaded_texture.back().second);
}
