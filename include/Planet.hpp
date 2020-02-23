/*
** EPITECH PROJECT, 2020
** - Project name
** File description:
** - File description
*/

#pragma once

#include <exception>
#include <memory>
#include <SFML/Graphics.hpp>
#include "IObject.hpp"

class Planet : public IObject {
public:
    Planet(sf::Vector2<float> const &start_position,
                    float const &start_rotation,
                    sf::Vector2<float> const &start_scale,
                    sf::Vector2<float> const &start_speed,
                    std::string const &texture_path,
                    float const &body_mass,
                    float const &rotate_speed,
                    std::shared_ptr<Planet> &gravity_center);
    Planet(sf::Vector2<float> const &start_position,
                    float const &start_rotation,
                    sf::Vector2<float> const &start_scale,
                    sf::Vector2<float> const &start_speed,
                    std::string const &texture_path,
                    float const &body_mass,
                    float const &rotate_speed);
    ~Planet(void) override = default;

    bool const &IsHidden(void) const override;
    void SetIsHidden(bool const &) override;

    void Tick(float const &delta_time) override;
    void Render(sf::RenderWindow &window) const override;

private:
    std::shared_ptr<sf::Texture> texture;
    sf::CircleShape shape;
    float rotateSpeed;
    float mass;
    sf::Vector2<float> speed;
    std::shared_ptr<Planet> gravityCenter;
    bool bHidden;
};
