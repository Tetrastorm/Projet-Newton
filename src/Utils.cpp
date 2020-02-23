/*
** EPITECH PROJECT, 2020
** - Project name
** File description:
** - File description
*/

#include <utility>
#include <vector>
#include <memory>
#include "Debug.hpp"
#include "Utils.hpp"

std::shared_ptr<sf::Texture> const &Utils::LoadTexture(std::string const &texture_path)
{
    static std::vector<std::pair<const std::string, std::shared_ptr<sf::Texture>>> list_loaded_texture;
    std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();

    for (std::pair<const std::string, std::shared_ptr<sf::Texture>> &pair : list_loaded_texture) {
        if (pair.first == texture_path) {
            Debug::Log("Reuse texture");
            return (pair.second);
        }
    }
    Debug::Log("Load " + texture_path + " texture");
    if (!texture->loadFromFile(texture_path)) {
        throw std::runtime_error("Invalid texture file.");
    }
    list_loaded_texture.emplace_back(std::pair<const std::string, std::shared_ptr<sf::Texture>>(texture_path, texture));
    return (list_loaded_texture.back().second);
}
