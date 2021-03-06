PapraGame Project
============

##About
<br/>
PapraGame is a game featuring ducks ! It is both free as in beer and open souce.

It's a multiplayer versus snake-like (but it may be played in solo aswell). To win, you have to be the first to reach a certain number of duckies, depending on the map (you start with 2).
You can get duckies either by catching an egg, or by stealing one to your opponent(s) (you can steal him/her a ducky by forcing him/her to punch you in the duckies).

Several biomes are available (changes the graphics), and maps can be easily modified.

You may change your keys settings within the ``keys.conf`` file

/!\ Under developement. Latest version : v1.0 -- Temerarium Anatum
<br/>

###Gameplay
<br/>
You can choose the keys for each player in the res/keys.conf file. Default keys are the arrows for player 1

Pause by pressing Escape (the game also pauses if it looses the focus).
When you hit an obstacle, you will be unvulnerable for 5 turns. Strange violet stuff that may appears in a map are warps. Going into a warp will teleport you to another random warp. Beware the walls !

###Maps
<br/>
You can add a map in the folder `./maps/`). Just create a file named ``<map_name>.map`` and edit it with text editor.
The file should be structured according to the following (line by line)
+ Biome (sand, grass, space, snow, magma, psychogwak)
+ ``visible`` if all the map is revealed, ``blind`` otherwise
    + if it's a ``blind`` map, add the Line of Sight of ducks (duckies LOS is halved)
    + Then add ``loop`` if you want the LOS to 'loop' or ``no-loop`` otherwise. (ie : do you want a duck at the very top of the map to see what's at the very bottom of the map ?)
+ The game 'slowness'
+ Number of eggs required to win (0 for infinity)
+ Length of the map
+ Width of the map
+ Map itself with characters :
    + ``o`` for the obstacle (rock, asteroid, cactus, …)
    + ``.`` for the blank tile (grass, void space, sand, …)
    + ``|`` for the 'river' that goes from north to south
    + ``-`` for the east-west one
    + ``1`` for east-south (from the num-keypad)
    + ``3`` for west-south
    + ``7`` for east-north
    + ``9`` for west-north
    + ``x`` for warps
+ Starting direction of player 1 (up, down, left, right)
    + On the same line, starting point of player 1 (x then y) [the origin is on the top left. x increases rightwards, y increases downwards]
+ Same for any other players
+ eof
(eof stands for End Of File)

##Authors
<br/>
+ Maxime PINARD - developer (maxime.pin@live.fr)
+ Lucas LAZARE - developer (lazarelucas@yahoo.fr)
+ Julien BARBIER - developer (a little), graphic designer (julien.barbier@utbm.fr)

##Download
<br/>
You can get the game sources from the Time Winder Dev Team [github repo](https://github.com/TiWinDeTea/PapraGame).

Binaries and sources of the v0.4 are available on [github](https://github.com/TiWinDeTea/PapraGame/releases/tag/v0.4)

v1.0 is downloadable [here](https://github.com/TiWinDeTea/PapraGame/releases/tag/v1.0)
<br/>

##Compilation requirements
<br/>
+ Platform : Linux, Windows, Mac OSX (MAC OSX support is theorical)
+ SFML ≥ 2.1, SFML ≥ 2.3 recommended
+ A compiler that supports c++11
<br/>

##Copyright
<br/>
License : Mozilla Public License Version 2.0

[Read the license file](LICENSE.md)

Extract : Disclaimer of Warranty

    Covered Software is provided under this License on an "as is"
    basis, without warranty of any kind, either expressed, implied, or
    statutory, including, without limitation, warranties that the
    Covered Software is free of defects, merchantable, fit for a
    particular purpose or non-infringing. The entire risk as to the
    quality and performance of the Covered Software is with You.
    Should any Covered Software prove defective in any respect, You
    (not any Contributor) assume the cost of any necessary servicing,
    repair, or correction. This disclaimer of warranty constitutes an
    essential part of this License. No use of any Covered Software is
    authorized under this License except under this disclaimer.

Extract 2 : Limitation of Liability

    Under no circumstances and under no legal theory, whether tort (including
    negligence), contract, or otherwise, shall any Contributor, or anyone who
    distributes Covered Software as permitted above, be liable to You for any
    direct, indirect, special, incidental, or consequential damages of any
    character including, without limitation, damages for lost profits, loss of
    goodwill, work stoppage, computer failure or malfunction, or any and all
    other commercial damages or losses, even if such party shall have been
    informed of the possibility of such damages. This limitation of liability
    shall not apply to liability for death or personal injury resulting from
    such party's negligence to the extent applicable law prohibits such
    limitation. Some jurisdictions do not allow the exclusion or limitation of
    incidental or consequential damages, so this exclusion and limitation may
    not apply to You.

<br/>

##Compile

In order to compile PapraGame executable, go to the project's root with a terminal, and use the command

``$ make`` (1 thread) or ``$ make fast`` (8 threads)

If you are using an SFML version below 2.3, use instead

``$ make DEFINES=-DOLD_SFML_COMPAT`` or ``$ make DEFINES=-DOLD_SFML_COMPAT fast``

(nb: The game won't pause upon losing focus when using OLD_SFML_COMPAT)

<br/>

Note that you might need to configure the Makefile if you don't you g++, for instance

An executable named `PapraGame.elf` should be generated in the `build/` folder

<br/>
After compiling, you may decide to install it using ``# make install``. By default, the game is installed to ``/usr/local/share/PapraGame``

To uninstall the game, simply use ``# make uninstall``

##Contribute

You may contribute easily by trying the game and having fun ! That would make us very happy !

##Thanks

We would like to thanks the [SFML](http://www.sfml-dev.org/) dev team for their work, they're awesome ; And [Gimp](https://www.gimp.org/) for graphics.
