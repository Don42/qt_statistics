#ifndef EXPERIMENT_H
#define EXPERIMENT_H


class Experiment
{

    public:
        Experiment();
        ~Experiment(){};
    
        char conductExperiment(char Mode);

        static const char allwaysSwitch = 1;
        static const char allwaysStay   = 2;
        static const char win  = 1;
        static const char lose = 0;

    private:
        char winningDoor;
        char choosenDoor;
        //char switchingDoor;
        char openDoor;
        //char remainingDoor;

};
#endif  //EXPERIMENT_H
