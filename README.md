# Sealand


## Install Dependencies
the lib ncurses is a mandatory to compile and execute the project so install it
	
    sudo apt-install ncurses
	   */or*/
	brew install ncurses

## Execute the program
there is no Makefile so to execute it open a cmd
	and execute
	
    gcc main.c src/*.c -lncurses
	   */or*/
	clang main.c src/*.c -lncurses
it generate a ./a.out execute it by executing

    ./a.out
    
## what is this program
this program is a simple sea simulation with somme fishes and 
plant the main of this program is to create a simple ncurses engine. Now it's a Sealand simulation but you can simply change that and simulate other thing.
	

