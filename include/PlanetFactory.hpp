/*
** EPITECH PROJECT, 2020
** - Project name
** File description:
** - File description
*/

#pragma once

#include <memory>
#include <string>
#include <SFML/System.hpp>
#include "Planet.hpp"

class PlanetFactory {
public:
    PlanetFactory(void) = default;
    ~PlanetFactory(void) = default;

    std::unique_ptr<Planet> MakePlanet(sf::Vector2<float> const &start_position, float const &start_rotation, sf::Vector2<float> const &start_scale, sf::Vector2<float> const &start_speed, std::string const &texture_path, float const &body_mass, float const &rotate_speed, std::unique_ptr<Planet> gravity_center);
};
