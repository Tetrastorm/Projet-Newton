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

namespace Utils {
    std::shared_ptr<sf::Texture> const &TextureLoader(std::string const &texture_path);
};
