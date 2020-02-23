/*
** EPITECH PROJECT, 2020
** - Project name
** File description:
** - File description
*/

#pragma once

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "IContainer.hpp"
#include "UIElement.hpp"

class InterfaceContainer : public IContainer {
public:
    explicit InterfaceContainer(void) = default;
    ~InterfaceContainer(void) override = default;

    void AddElem(std::unique_ptr<UIElement> &elem);
    void RemoveElem(std::unique_ptr<UIElement> &elem);
    void Render(sf::RenderWindow &window) const override;

private:
    std::vector<std::unique_ptr<UIElement>> ui_elem_list;
};
