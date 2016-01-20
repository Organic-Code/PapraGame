/***********************************************************************
 * This Source Code Form is subject to the terms of the Mozilla Public *
 * License, v. 2.0. If a copy of the MPL was not distributed with this *
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.            *
 ***********************************************************************/

#ifndef DUCKY_CPP_INCLUDED
#define DUCKY_CPP_INCLUDED

#include <Ducky.hpp>

Ducky::Ducky(sf::Window& game_window, sf::Texture textures[4], Coord starting_coordinates){
	st_coordinates = starting_coordinates;
	coordinates = starting_coordinates;
	for (unsigned char i = 4 ; i--;) {
		sprite[i].setTexture(textures[i]);
	}
	direction = LEFT;
	window = game_window;
}

Ducky::Ducky(sf::Window& game_window, sf::Texture textures[4], Coord act_coordinates Coord starting_coordinates, Direction dir){
	st_coordinates = starting_coordinates;
	coordinates = act_coordinates;
	for (unsigned char i = 4 ; i-- ;) {
		sprite[i] = textures[i];
	}
	direction = dir;
	window = game_window;
}

void Ducky::print(){
	sprite[direction].setPosition(coordinates.x * 32, coordinates.y * 32);
	window.draw(sprite[direction]);
}

void Ducky::move(Direction new_dir){
	direction = new_dir;
	switch(direction){
		case UP:
			--coordinates.y;
			break;
		case DOWN:
			++coordinates.y;
			break;
		case LEFT:
			--coordinates.x;
			break;
		case RIGHT:
			++coordinates.x;
			break;
		default:
			break;
	}
	this.print();
}

#endif /* DUCKY_CPP_INCLUDED */
