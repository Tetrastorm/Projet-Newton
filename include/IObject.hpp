/*
** EPITECH PROJECT, 2020
** - Project name
** File description:
** - File description
*/

#pragma once

#include <SFML/Graphics.hpp>

class IObject {
public:
    virtual ~IObject(void) = default;

    virtual void Tick(float const &delta_time) = 0;
    virtual void Render(sf::RenderWindow &window) const = 0;
};