/*
** EPITECH PROJECT, 2020
** - Project name
** File description:
** - File description
*/

#include "UIElement.hpp"

UIElement::UIElement(void)
{
    bHidden = false;
}

bool const &UIElement::IsHidden(void) const
{
    return (bHidden);
}

void UIElement::SetIsHidden(bool const &new_value)
{
    bHidden = new_value;
}

void UIElement::Tick(float const &delta_time)
{
    (void)delta_time;
}

void UIElement::Render(sf::RenderWindow &window) const
{
    if (!bHidden) {
        window.draw(*sprite);
    }
}
