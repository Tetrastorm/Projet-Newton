/*
** EPITECH PROJECT, 2020
** - Project name
** File description:
** - File description
*/

#include "Interface.hpp"

void InterfaceContainer::AddElem(std::unique_ptr<UIElement> &elem)
{
    ui_elem_list.push_back(std::move(elem));
}

void InterfaceContainer::RemoveElem(std::unique_ptr<UIElement> &elem)
{

}

void InterfaceContainer::Render(sf::RenderWindow &window) const
{
    for (std::unique_ptr<UIElement> const &elem : ui_elem_list) {
        elem->Render(window);
    }
}
