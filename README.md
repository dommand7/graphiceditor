# graphiceditor


# Getting Started 

This graphical editor understands 7 commands:
I M N... creates MxN table and sets all elements to 'O'

L X Y C... colours the pixel (X,Y) with colour C

C... clears the table

V X Y1 Y2 C... draws a vertical segment of colour C in column X between rows Y1 and Y2

H X1 X2 Y C... draws a horizontal segment of colour C in row Y between columns X1 and X2

F X Y C... fills the region R with the colour C.R is defined as: pixel (X,Y) belongs to R.Any other
pixel which is the same colour as (X,Y) and shares a common side with any pixel in R also belongs
to this region

S... shows the table

X... terminates the session


## Prerequisites

How to compile:
open terminal by pressing Win+R,type "cmd" and press Enter

type cd <directoryname> in terminal to change the current working directory to where you want to work

type git clone https://github.com/dommand7/graphiceditor.git 

type dir if you want to list files in current directory, 
then type cd graphiceditor to change directory where the program is

type gcc testruby.c to compile source code and create an executable file 

by gcc -o <name> testruby.c we name our executable file ,
and then run it by typing <name> and pressing enter

input are commands given above in "Getting Started" section

# Code explanation

I used stdio.h,stdbool.h and stdlib.h libraries. In main function in the while loop user writes commands accordingly and the switch-case directs the program based on the first letter of the users command. For the I command, the program allocates memory for the matrix using 'malloc' and sets all elements to 'O'. In case of L, it sets the pixel (X, Y) to 'C'. Commands L, V, H and C work similarly. For the command F, recursive function 'regija' is used. The function has four arguments, the coordinates of the pixel, the colour of the pixel and the colour that the region needs to be coloured. In 'regija', the same function is called for all the pixels that share a common side with (X, Y) and are the same colour. It also checks if the function is called for nonexistent pixels, like the ones outside of the matrix, whose coordinates are bigger than M-1, N-1 or smaller than 0. If a user presses 'X', the loop is interrupted and it is done. 





