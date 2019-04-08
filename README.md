# PSU_2016_tetris

Tetris is one of the first year project in Epitech. <br/>
This is a game where you have what we call "tetromino" which are geometric shape falling from the top.<br/>
The goal is to form line with this tetromino on the bottom to win points. Each line formed will be destroyed.<br/>
The game have different levels where the tetromino fall faster. In this one the possibility to turn the tetromino is disabled.<br/>

![alt text](https://github.com/Setanas/PSU_2016_tetris/branch/ressources/tetris.png)

## Getting Started

This game is programmed in C on a Linux environment.

### Prerequisites

To compile we are using gcc.  
The bonus use the ncruses library.

### Installing

To install the game please use the Makefile to compile the original game.

```
$> make
```

If you want to try the bonus

```
$> cd bonus
$> make
```

At the end you should have a "matchstick" binary in your current folder.

## Running the programm

To run the original : 

Replace {nbr lines} by a number representing the number of lines in the pyramid.  
Replace {max match} by a number representing the max number of match to take in a round.
```
$> ./matchstick {nbr lines} {max match}
```

To run the bonus : 

Replace {nbr lines} by a number representing the number of lines in the pyramid.  
Replace {max match} by a number representing the max number of match to take in a round.  
Replace {IA level} by a number representing the level of the IA (0, 1 or 2).

```
$> ./matchstick {nbr lines} {max match} {IA level}
```


## Authors

* **Sébastien Tan** - *Developer* - [Setanas](https://github.com/Setanas)