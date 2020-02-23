/*
** EPITECH PROJECT, 2020
** - Project name
** File description:
** - File description
*/

#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include <IObject.hpp>

class UIElement : public IObject {
public:
    explicit UIElement(void);
    virtual ~UIElement(void) override = default;

    bool const &IsHidden(void) const override;
    void SetIsHidden(bool const &) override;

    void Tick(float const &delta_time) override;
    void Render(sf::RenderWindow &window) const override;

private:
    std::unique_ptr<sf::Drawable> sprite;
    bool bHidden;
};
