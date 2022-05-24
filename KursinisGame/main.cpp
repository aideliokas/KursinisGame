
#include <iostream>
#include "Game.h"
#include <time.h>

#include <SFML/Graphics.hpp>





int main()
{
    // Inicijuojam random seed'a

    srand(static_cast<unsigned>(time(0)));


  Game game;

  game.start();


    //Programos pabaiga
   return 0;
}

