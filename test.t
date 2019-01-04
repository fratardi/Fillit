All figures on the top left total 4 + 1 + 2 + 6 + 4  = 17
____________________________________________________________________________________
|	0x4C80 = 19584	|	0cC600 = 50688  |  0c6C00 = 27648   |	0x8C40 = 35904  | z |
|___________________|___________________|___________________|___________________|___|
| [0][/][0][0] 0100 | [.][.][0][0] 1100 | [0][/][/][0] 0110 | [/][0][0][0] 1000 |
| [/][/][0][0] 1100 | [0][.][.][0] 0110 | [/][/][0][0] 1100 | [/][/][0][0] 1100 |
| [/][0][0][0] 1000 | [0][0][0][0] 0000 | [0][0][0][0] 0000 | [0][/][0][0] 0100 |
| [0][0][0][0] 0010 | [0][0][0][0] 0000 | [0][0][0][0] 0000 | [0][0][0][0] 0000 |
|___________________|___________________|___________________|___________________|
| 0xCC00 = 52224	|	Square	|			
|___________________|___________|
| [1][1][.][.] 1100 |
| [1][1][.][.] 1100 |
| [.][.][.][.] 0000 |
| [.][.][.][.] 0000 |
|___________________|_________________________
| 0x8888 = 34952    | 0xF000 = 61440    | Bar |
|___________________|___________________|_____|
| [1][0][0][0] 1000 | [1][1][1][1] 1111 |
| [1][0][0][0] 1000 | [0][0][0][0] 0000 |
| [1][0][0][0] 1000 | [0][0][0][0] 0000 |
| [1][0][0][0] 1000 | [0][0][0][0] 0000 |
____________________|___________________|__________________________________________________________________________________
| OxE800 = 59392 	| 0xC440 = 50240    |	0xC880 = 51328	| 0xE200 = 57856    | 0x8E00 = 36352	| 0x2E00 = 11776	|L|
|___________________|___________________|___________________|___________________|___________________|___________________|_|
| [1][1][1][0] 1110	| [1][1][0][0] 1100 | [1][1][0][0] 1100 | [1][1][1][0] 1110 | [1][0][0][0] 1000 | [0][0][1][0] 0010 |
| [1][0][0][0] 1000 | [0][1][0][0] 0100 | [1][0][0][0] 1000 | [0][0][1][0] 0010 | [1][1][1][0] 1110 | [1][1][1][0] 1110 |
| [0][0][0][0] 0000	| [0][1][0][0] 0100 | [1][0][0][0] 1000 | [0][0][0][0] 0000 | [0][0][0][0] 0000 | [0][0][0][0] 0000 |
| [0][0][0][0] 0000	| [0][0][0][0] 0000 | [0][0][0][0] 0000 | [0][0][0][0] 0000 | [0][0][0][0] 0000 | [0][0][0][0] 0000 |
|___________________|___________________|___________________|___________________|___________________|___________________|
|	0xE400 = 58368	|  0x4E00 = 19968   |   0x8C80 = 35968  |   0x4C40 = 19520	|T |
|___________________|___________________|___________________|___________________|__|
|[1][1][1][0] 1110  | [0][1][0][0] 0100 | [1][0][0][0] 1000 | [0][1][0][0] 0100 |
|[0][1][0][0] 0100  | [1][1][1][0] 1110 | [1][1][0][0] 1100 | [1][1][0][0] 1100 |
|[0][0][0][0] 0000	| [0][0][0][0] 0000 | [1][0][0][0] 1000 | [0][1][0][0] 0100 |
|[0][0][0][0] 0000	| [0][0][0][0] 0000 | [0][0][0][0] 0000 | [0][0][0][0] 0000 |
|___________________|___________________|___________________|___________________|

* longlonglong int

to convert the buff to the unsigned short

iterate a << (bite drift ? to right) over each created value until it reaches 0 or one of the matching tetri value

apply or of the selected value to an unsigned short pre defined to 0

/* Check 
**
**  check if arguments are valid
**
		** Validity of the input
		how  to check if input is valid ?
		check if the file only contains {'#','.','\n','\0'}	
		check if each rows contain only 5  or 1 char 
		buffconvert can pass over the buffer and return a value different than 0
**
*/

/* Convert
**
				** how to convert the  ((4  +  1) x 5) + 1 = 26 characters into one unsigned short
				V	done 			

 d
 				** how to stock values ???
						maybe use a structure containing the grid positions of the tetrimino , the shape of the tetrimino and the order of arrival 
						into  a chained list 
				V done   
 **
** 
*/

how to apply masks over tetriminoes to only keep one line of it inside an onther value

for example i want to display only the first line oof the tetriminos 1000 1110 0000 0000 = 0x8E00 = 36352
	i use a & mask of the selected mask to keep the value            1111 0000 0000 0000 = 0xF000 = 61440
													that gives us 	 1000 0000 0000 0000 = 0x8000 = 32768
so we could either set the top 0xF000 = 61440 = 1111 0000 0000 0000
and use 					   0xF00  =	3840  = 0000 1111 0000 0000
							   0xF0	  = 240	  =	0000 0000 1111 0000
							   0xF	  = 15	  =	0000 0000 0000 1111

positionate the tetri according to its position on the grid before applying checks 
instead of making a grid for check 
check if every line of each tetriminos can fit over each line preseted at 0 every time 
add each tetri line as layer and check if tetriminos don't overlap each other ...


Eventually we could : check if can 

So how to check if every line of the tetrimino 
----  
****
----
/* ???????????????????????????????????????
check if i can put the tetri on the grid
??????????????????????????????????????????
check it the line stil valid after i place the tetrimino on the line ;
*/

/* Organize
**   
 				** how to handle every unsigned short over grids 
**
**
*/

/*
		**prepare grid ??
*/

/* Solve
**     How to make a map able to handle the result
**
**
**
**
**
**      
**
**
*/

/* return
** 
**
**
**
**
*/

/*
**	Display  
**
**
*/
