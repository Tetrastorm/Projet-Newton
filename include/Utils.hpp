/*
** EPITECH PROJECT, 2020
** - Project name
** File description:
** - File description
*/

#pragma once

#include <string>
#include <memory>
#include <SFML/Graphics.hpp>
#include "NewtonType.hpp"

namespace Utils {
    std::shared_ptr<sf::Texture> const &TextureLoader(std::string const &texture_path);
    sf::Vector2<float> &RelativeToOnScreenPosition(sf::Vector2<float> &position);
    sf::Vector2<float> GetPositionOnScreen(float x, float y);
};
