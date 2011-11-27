#include <stdlib.h>
#include <time.h>

#include "experiment.h"


Experiment::Experiment()
{
    winningDoor = 4;
    choosenDoor = 4;
    //switchingDoor   = 4;
    srand ( time(NULL) );
}

char Experiment::conductExperiment(char switchingMode)
{
    //predetermine where the price is
    winningDoor = rand() % 3;

    //choose a door
    choosenDoor = rand() % 3;

    //open a non-winning, non-choosen door
    do
    {
        openDoor = rand() % 3;
    } while(openDoor==winningDoor||openDoor==choosenDoor);
    
    if(switchingMode == allwaysStay)
    {
        if(choosenDoor == winningDoor)
        {
            return win;
        }
        else
        {
            return lose;
        }
    }
    else if(switchingMode == allwaysSwitch)
    {
        if(choosenDoor != winningDoor)
        {
            return win;
        }
        else return lose;
    }
    return 255;
}
