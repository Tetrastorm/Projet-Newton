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

std::shared_ptr<sf::Texture> const &Utils::TextureLoader(std::string const &texture_path)
{
    static std::vector<std::pair<const std::string, std::shared_ptr<sf::Texture>>> list_loaded_texture;
    std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();

    for (std::pair<const std::string, std::shared_ptr<sf::Texture>> &pair : list_loaded_texture) {
        if (pair.first == texture_path) {
            Debug::Log("[TEXTURE LOADER]\tReuse " + texture_path + " texture");
            return (pair.second);
        }
    }
    Debug::Log("[TEXTURE LOADER]\tLoad " + texture_path + " texture");
    if (!texture->loadFromFile(texture_path)) {
        throw std::runtime_error("[TEXTURE LOADER]\tInvalid texture file fail to be load.");
    }
    Debug::Log("[TEXTURE LOADER]\tTexture loaded");
    list_loaded_texture.emplace_back(std::pair<const std::string, std::shared_ptr<sf::Texture>>(texture_path, texture));
    return (list_loaded_texture.back().second);
}

sf::Vector2<float> &Utils::RelativeToOnScreenPosition(sf::Vector2<float> &position) {
    position.x *= static_cast<float>(WINDOW_SIZE[0]);
    position.y *= static_cast<float>(WINDOW_SIZE[1]);
    return (position);
}

sf::Vector2<float> Utils::GetPositionOnScreen(float x, float y) {
    sf::Vector2<float> position = {x, y};
    position.x *= static_cast<float>(WINDOW_SIZE[0]);
    position.y *= static_cast<float>(WINDOW_SIZE[1]);
    return (position);
}
