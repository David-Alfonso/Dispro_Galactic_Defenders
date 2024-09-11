# Dispro_Galactic_Defenders

This project was the final project of the subject Design of Systems with Processors of my group, it was an adaption of the game Space Invaders to C code that can run in Windows Console and can be adapted to Arduino or Unix console.

The .h files are divided so it is easier for the understanding, but for a simpler way of running the game, all of the .h files were incorporated in a single file called "all.h". This also happens with the .c files corresponding to the definition of the functions in the .h files. For running the game you need to compile the main.c and all_c.c files, the all.h file has to be in the same folder.

In respect to how the game works it's relevant to say that the selection of which alien is going to fire is randomized. All of the aliens move from left to right, down, right to left, down and repeats until they all die or reach the player. The player can move from left to right and can be covered with the walls, the walls have 3 stages of life before they die, the player can shoot whenever it wants but it has to wait that the bullet is gone, because of the length of it. 

There are some comments in the code for future possible improvements to the code. 

Please feel free to send me a message if you have questions or comments to make in regard to the code.
