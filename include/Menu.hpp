/***********************************************************************
* This Source Code Form is subject to the terms of the Mozilla Public *
* License, v. 2.0. If a copy of the MPL was not distributed with this *
* file, You can obtain one at http://mozilla.org/MPL/2.0/.            *
***********************************************************************/

#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED

/**
 * @file Menu.hpp
 * @author Lucas LAZARE
 * @version 0.0
 * @license Mozilla Public License, v. 2.0
 * @brief Defines the Menu Class
 */

#include <string>
#include <vector>
#include <iostream>
#include <Coord.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <enum.hpp>
#include <Game.hpp>
#include <NetworkGame.hpp>
#include <dirent.h>

#if defined(_WIN32) || defined(_WIN64) || defined(WIN32) || defined(WIN64)
#include <windows.h>
#define OS_WINDOWS
#else

#include <unistd.h>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>

#endif

#define MINIMAL_Y_MOUSE               205

#define MENU_X_RESOLUTION             800
#define MENU_Y_RESOLUTION             600
#define ABOUT_X_RESOLUTION            500
#define ABOUT_Y_RESOLUTION            350

#define TITLE_HEIGHT                  216

#define LOCAL_TXT                     "Local"
#define NETWORK_TXT                   "Network"
#define ABOUT_TXT                     "About"
#define EXIT_TXT                      "Exit"
#define BACK_TXT                      "back"
#define NO_MAPS_TXT                   "No maps found"
#define SERVER_TXT                    "Host a Game"
#define CLIENT_TXT                    "Join a Game"
#define MAIN_FONT_SIZE                44
#define MAP_FONT_SIZE                 34

#define MAIN_BUTTON_HEIGHT            50
#define MAIN_BUTTON_WIDTH             400
#define MAIN_BUTTON_SPACE             30
#define MAP_BUTTON_HEIGHT             50
#define MAP_BUTTON_WIDTH              600
#define MAP_BUTTON_SPACE              20
#define OUTLINE_THICKNESS             5

#define BUTTON_FILL_COLOR             sf::Color(5, 195, 5, 225)
#define SELECTED_OUTLINE_COLOR        sf::Color(0, 0, 200, 255)
#define NORMAL_OUTLINE_COLOR          sf::Color(150, 100, 255, 175)
#define TXT_COLOR                     sf::Color(20, 72, 169, 255)

#define MAPS_PATH                     "maps/"
#define RES_PATH                      "res/"
#define BIOME_PATH                    "none"
#define DUCKS_PATH                    "ducks/"
#define MENU_PATH                     "menu/"

#define TEXTURE_TITLE                 "BgFixed"
#define TEXTURE_BACKGROUND            "BgScrolling"
#define TEXTURE_ABOUT                 "About"
#define TEXTURE_FILETYPE              ".png"
#define BACKGROUND_LOOP_WIDTH         3296
#define REFRESH_SLOWNESS              20

/**
 * @class Menu Menu.hpp
 * @brief Defines the Menu Class
 */
class Menu {

public:

	Menu( );

	void setBiome(std::string chosen_biome);

	~Menu( ) { };

	void mainMenu( );

	std::string mapMenu( );

	char networkMenu( );

private:

	int bg_pos;
	sf::Music title_theme;
	sf::RenderWindow window, about_window;
	sf::Font font;
	sf::Texture title_texture;
	sf::Texture background_texture;
	sf::Texture about_texture;
	sf::Sprite title_sprite;
	sf::Sprite background_sprite;
	sf::Sprite about_sprite;

	std::string res_path, biome_path, ducks_path, maps_path, map_path, menu_path;
};

#endif /* MENU_HPP_INCLUDED */
