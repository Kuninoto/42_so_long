# so_long (42Porto - 42Cursus) <img src="https://github.com/devicons/devicon/blob/master/icons/c/c-original.svg" title="C" alt="C Logo" width="55" height="55" align="right" />&nbsp;  

## Grade: 110/100

###  Screenshot:
<img src="https://github.com/Kuninoto/42_so_long/blob/master/extras/showcase1.png"/>

### Installing and running the project:

1- Installing mlx dependencies

	sudo apt-get install make xorg libxext-dev zlib1g-dev libbsd-dev

2- Clone this repository
	
	git clone https://github.com/Kuninoto/42_so_long
3- Navigate to _lvl_2_so_long_ and run `make`
	
	cd 42_so_long/lvl_2_so_long
   	make
4- `make clean` so that you don't keep those object files that you won't need anymore

	make clean
5- Run your new, extremely sexy, game, with a map of your choice!

	./so_long maps/[which_ever_map_you_want].ber

### Creating new maps:

	'0' - Free space;  
	'1' - Wall;  
	'C' - Collectible;  
	'E' - Exit;  
	'P' - Player's starting position;  
	To be valid a map must respect the following:  
		- Be in .ber format;  
		- Be closed by walls;  
		- Be retangular;  
		- Contain only one P;  
		- Contain only one E;  
		- Contain at least one C;  
		- All elements must be accessible (not closed by walls);  
		- Be composed only by valid characters i.e 0, 1, C, E, P;  
	(You can check examples of valid maps on maps folder);

###  Subject: [so_long en_subject](./extras/en.subject_so_long.pdf)

#### Makefile Available Targets:  
`make` or `make all` - compiles so_long   
`make bonus` - same as `all` (added for subject purposes)   
`make clean` - wipes all object files   
`make fclean` - deletes so_long and all object files   
`make re` - fclean  + all   

### Useful links:  
- https://harm-smits.github.io/42docs/libs/minilibx/introduction.html  
- https://itch.io/  
- https://opengameart.org/  

#### Assets Credit:    
- https://jamiecross.itch.io/8-bit-dungeon-tilesetsprites

## Disclaimer
> At [42School](https://en.wikipedia.org/wiki/42_(school)), almost every project must be written in accordance to the [Norm](./extras/en_norm.pdf), the schools' coding standard. As a result, the implementation of certain parts may appear strange and for sure had room for improvement.

---
Made by Nuno Carvalho (Kuninoto) | nnuno-ca@student.42porto.com  
<div id="badge"> <a href="https://www.linkedin.com/in/nuno-carvalho-218822247"/> <img src="https://img.shields.io/badge/LinkedIn-blue?style=for-the-badge&logo=linkedin&logoColor=white" alt="LinkedIn Badge"/>&nbsp;
