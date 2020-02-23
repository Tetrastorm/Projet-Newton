/*
** EPITECH PROJECT, 2020
** - Project name
** File description:
** - File description
*/

#include "PlanetFactory.hpp"

std::unique_ptr<Planet> PlanetFactory::MakePlanet(sf::Vector2<float> const &start_position,
                                                  float const &start_rotation,
                                                  sf::Vector2<float> const &start_scale,
                                                  sf::Vector2<float> const &start_speed,
                                                  std::string const &texture_path,
                                                  float const &body_mass,
                                                  float const &rotate_speed,
                                                  std::unique_ptr<Planet> gravity_center)
{
    return std::make_unique<Planet>(Planet(start_position, start_rotation, start_scale, start_speed, texture_path, body_mass, rotate_speed, std::move(gravity_center)));
}
