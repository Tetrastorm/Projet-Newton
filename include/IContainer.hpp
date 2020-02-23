/*
** EPITECH PROJECT, 2020
** - Project name
** File description:
** - File description
*/

#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include "IObject.hpp"

class IContainer {
public:
    virtual ~IContainer(void) = default;

    virtual bool const &IsHidden(void) const = 0;
    virtual void SetIsHidden(bool const &) = 0;

    virtual void AddElem(std::unique_ptr<IObject> &) = 0;
    virtual void RemoveElem(std::unique_ptr<IObject> &) = 0;
    virtual void Render(sf::RenderWindow &) const = 0;
};
