/*
** EPITECH PROJECT, 2020
** - Project name
** File description:
** - File description
*/

#include "UIElement.hpp"

void UIElement::Tick(float const &delta_time)
{
    (void)delta_time;
}

void UIElement::Render(sf::RenderWindow &window) const
{
    window.draw(*sprite);
}
