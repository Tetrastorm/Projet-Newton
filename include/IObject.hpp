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

    virtual bool const &IsHidden(void) const = 0;
    virtual void SetIsHidden(bool const &) = 0;

    virtual void Tick(float const &) = 0;
    virtual void Render(sf::RenderWindow &) const = 0;
};
