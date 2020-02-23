/*
** EPITECH PROJECT, 2020
** - Project name
** File description:
** - File description
*/

#pragma once

#include <exception>
#include <SFML/Graphics.hpp>

class Planet {
public:
    explicit Planet(sf::Vector2<float> const &start_position,
                    float const &start_rotation,
                    sf::Vector2<float> const &start_scale,
                    sf::Vector2<float> const &start_speed,
                    std::string const &texture_path,
                    float const &body_mass,
                    float const &rotate_speed,
                    std::unique_ptr<Planet> gravity_center);
    Planet(Planet const &planet);
    ~Planet(void) = default;

    void UpdateBody(float const &delta_time);
    void Render(sf::RenderWindow &window) const;

private:
    sf::Texture texture;
    sf::CircleShape shape;
    float rotateSpeed;
    float mass;
    sf::Vector2<float> speed;
    std::unique_ptr<Planet> gravityCenter;
};
