/***********************************************************************
 * This Source Code Form is subject to the terms of the Mozilla Public *
 * License, v. 2.0. If a copy of the MPL was not distributed with this *
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.            *
 ***********************************************************************/

#ifndef MAP_HPP_INCLUDED
#define MAP_HPP_INCLUDED

#include <Coord.hpp>
#include <SFML/Graphics.hpp>
#include <enum.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

#define NB_TEXTURE         9
#define RESOLUTION_X_IMAGE 32
#define RESOLUTION_Y_IMAGE 32

/**
 * @file Map.hpp
 * @author Julien BARBIER
 * @version 0.0
 * @license Mozilla Public License, v. 2.0
 * @brief Define the Map class
 */

/**
 * @class Map Map.hpp
 * @brief Define the Class Map
 */


class Map {

public :
	/**
	 * @brief Destroy the class Map
	 */
	~Map( ) { };

	/**
	 * @brief Creation of Map by default.
	 */
	Map( ) { };

	/**
	 * @brief Map constructor
	 * @param x    Width of the map
	 * @param y    Height of the map
	 * @param smap The map itself of width x and height y
	 */
	Map(unsigned int x, unsigned int y, std::vector<std::vector<Area>> smap);

	/**
	 * @brief Creation of map with all the parametre needed.
	 * @param x The Width of the map
	 * @param y The Heith of the map
	 * @param smap[x][y] The map itself with the lenght and the width.
	 * @param texture[NB_TEXTURE] Array which will contain the texture for this game.
	 * @param egg_texture Contain the texture of the egg.
	 */
	Map(const unsigned int x, const unsigned int y, std::vector<std::vector<Area>> smap,
	    sf::Texture texture[NB_TEXTURE], sf::Texture* egg_texture);

	/**
	 * @brief Initialises the map
	 */
	void init( );

	/**
	 * @brief Pops an egg at a random non-obstacle tile
	 */
	void popEgg( );

	/**
	 * @brief Sets the coordinates of the egg
	 * @param new_coord New egg's coordinates
	 */
	void popEgg(Coord new_coord);

	/**
	 * @brief Print a send case in the screen.
	 * @param coord The coordinate of the case we want to convert.
	 * @param window the window for sfml and to print the map.
	 */

	void print(Coord coord, sf::RenderWindow& window);

	/**
	 * @brief printAll Print all the map.
	 * @param window the window for sfml and to print the map
	 */
	void print(sf::RenderWindow& window);

	/**
	 * @brief printing function for blinds maps
	 * @param window Game window
	 * @param tile   Coordinates of the center's tile
	 * @param los    Ducks Line of Sight
	 * @param loop   Is the LOS looping ?
	 */
	void print(sf::RenderWindow& window, Coord tile, unsigned short los, bool loop);

	void printEgg(sf::RenderWindow& window);

	/**
	 * @brief Gets the egg's coordinates
	 * @return The egg's coord
	 */
	Coord getEggCoord( ) { return coordinate_egg; }

	/**
	 * @brief returns random warp's coordinates
	 * @param current_tile Coordinates of the current warp
	 * @return             Warp's coordinates
	 */
	Coord getWarp(Coord current_tile);

	/**
	 * @brief tells if a place is a warpzone
	 * @param tile Tile to check
	 * @return     true if the tile is on a warp, false otherwise
	 */
	bool isWarp(Coord tile);

	Map& operator=(const Map& mymap);

	unsigned int x_size;
	unsigned int y_size;
	std::vector<std::vector<Area>> map;

private :

	std::vector<Coord> warp;
	std::vector<Coord> free_tile;
	sf::Sprite sprites[NB_TEXTURE];
	Coord coordinate_egg;
	sf::Sprite egg_sprite;
};

#endif /* MAPP_HPP_INCLUDED */
