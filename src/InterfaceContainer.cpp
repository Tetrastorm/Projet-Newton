/*
** EPITECH PROJECT, 2020
** - Project name
** File description:
** - File description
*/

#include "InterfaceContainer.hpp"

InterfaceContainer::InterfaceContainer(void)
{
    bHidden = true;
}

bool const &InterfaceContainer::IsHidden(void) const
{
    return (bHidden);
}

void InterfaceContainer::SetIsHidden(bool const &new_value)
{
    bHidden = new_value;
}

void InterfaceContainer::AddElem(std::unique_ptr<UIElement> &elem)
{
    ui_elem_list.push_back(std::move(elem));
}

void InterfaceContainer::RemoveElem(std::unique_ptr<UIElement> &elem)
{

}

void InterfaceContainer::Render(sf::RenderWindow &window) const
{
    if (!bHidden) {
        for (std::unique_ptr<UIElement> const &elem : ui_elem_list) {
            elem->Render(window);
        }
    }
}
