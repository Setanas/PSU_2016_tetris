# PSU_2016_tetris

Tetris is one of the first year project in Epitech. <br/>
This is a game where you have what we call "tetromino" which are geometric shape falling from the top.<br/>
The goal is to form line with this tetromino on the bottom to win points. Each line formed will be destroyed.<br/>
The game have different levels where the tetromino fall faster. In this one the possibility to turn the tetromino is disabled.<br/>

![tetris image](/ressources/tetris.png)

## Getting Started

This game is programmed in C on a Linux environment.

### Prerequisites

To compile we are using gcc.<br/>
The programm use the ncruses library.

### Installing

To install the game please use the Makefile to compile.
 
```
$> make
```

At the end you should have a "tetris" binary in your current folder.

## Creating your own tetromino

You can create your own tetromino by adding a file {name}.tetrimino in the folder "tetriminos".<br/>
(replace {name} by the name you want to give)<br/>
The file must have this format.
```
2 3 7
 *
**
*
```
2 is the length of the tetromino.
3 is the height of the tetromino.
7 is the color of the tetromino. (the color is between 1 and 7)

## Running the programm

To run :<br/>

```
$> ./tetris
```

If you want to see the full usage:
```
$> ./tetris --help
Usage:	./tetris[options]
Options:
  --help		Display this help
  -l --level={num}	Start Tetris at level num (def: 1)
  -kl --key-left={K}	Move the tetrimino LEFT using the K key (def: left arrow)
  -kr --key-right={K}	Move the tetrimino RIGHT using the K key (def: right arrow)
  -kt --key-turn={K}	TURN the tetrimino clockwise 90d using the K key (def: top arrow)
  -kd --key-drop={K}	DROP the tetrimino using the K key (def: down arrow)
  -kq --key-quit={K}	QUIT the game using the K key (def: 'q' key)
  -kp --key-pause={K}	PAUSE/RESTART the game using the K key (def: space bar)
  --map-size={row,col}	Set the numbers of rows and columms of the map (def: 20,10)
  -w --without-next	Hide next tetrimino (def: false)
  -d --debug		Debug mode (def: false)
```

## Authors

* **Sébastien Tan** - *Developer* - [Setanas](https://github.com/Setanas)

## Collaborater

* **Guillaume Chanut** - *Developer*