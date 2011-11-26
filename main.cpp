#include <QtGui/QApplication>
#include <stdio.h>
#include <iostream>

#include "experiment.h"

int main( int argc, char *argv[] )
{
    int n, m;
    m = 5000;
    int sum = 0;
    QApplication a (argc, argv);
    
    Experiment e;
    for(n = 0; n<m;n++)
    {
        int curResult = e.conductExperiment(Experiment::allwaysSwitch);
        std::cout << "Result: " << curResult << std::endl << std::endl;
        sum += curResult;
    }
    std::cout << "Number of Wins: " << sum << std::endl;

}
