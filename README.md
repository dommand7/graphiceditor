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

I used Codeblocks IDE with MinGW32 compiler on Windows 10,but it can be compiled with any other C compiler

# Code explanation

I used stdio.h and stdlib libraries.In main function in the while loop user writes commands accordingly and the switch-case directs the program based on the first letter of the users command.For the I command, the program allocates memory for the matrix using 'malloc' and sets all elements to 'O'.In case of L,it sets the pixel (X,Y) to 'C'.Commands L, V, H and C work similarly.For the command F,recursive function 'regija' is used.The function has four arguments,the coordinates of the pixel,the colour of the pixel and the colour that the region needs to be coloured.In 'regija', the same function is called for all the pixels that share a common side with (X,Y) and are the same colour.It also checks if the function is called for nonexistent pixels,like the ones outside of the matrix,whose coordinates are bigger than M-1,N-1 or smaller than 0.If a user presses 'X',the loop is interrupted and it is done. 





