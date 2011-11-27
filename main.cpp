#include <QtGui/QApplication>
#include <qwt_plot_histogram.h>
#include <qwt_series_data.h>
#include <qwt_global.h>
#include <qwt_plot.h>
#include <stdio.h>
#include <iostream>
#include <qwt_column_symbol.h>
#include <qpen.h>
#include "experiment.h"

int main( int argc, char *argv[] )
{

    unsigned int n, m;
    m = 100000;
    int sumSwitch = 0;
    int sumStay = 0;

    QApplication a (argc, argv);
    QwtPlot w;
    Experiment e;

    w.setTitle( "Wins/Loses" );

    //Setup Histogram Plot
    QwtPlotHistogram *h = new QwtPlotHistogram();
    QwtColumnSymbol *symbol = new QwtColumnSymbol( QwtColumnSymbol::Box );
    symbol->setFrameStyle( QwtColumnSymbol::Raised );
    symbol->setPalette(Qt::darkCyan);
    h->setSymbol(symbol);
    h->setBaseline(0);


    for(n = 0; n<m;n++)
    {
        int curResult = e.conductExperiment(Experiment::allwaysStay);
        sumStay += curResult;

        curResult = e.conductExperiment(Experiment::allwaysSwitch);
        sumSwitch += curResult;

        if((n%1000)==0)
        {
            QVector<QwtIntervalSample> data;
            data.append( QwtIntervalSample(n,0,1));
            data.append( QwtIntervalSample(sumSwitch,1,2));
            data.append( QwtIntervalSample(n-sumSwitch,2,3));
            data.append( QwtIntervalSample(n,5,6));
            data.append( QwtIntervalSample(sumStay,6,7));
            data.append( QwtIntervalSample(n-sumStay,7,8));
            
            h->setSamples(data);
            h->attach(&w);
            w.replot();
            w.show();
            std::cout << "\r";
            std::cout << (n/(double)m)*100 << "%";
        }
    }
    std::cout << "Number of Wins: " << sumStay << std::endl;
    std::cout << "Number of Loses: " << m-sumStay << std::endl;

    std::cout << "Number of Wins: " << sumSwitch << std::endl;
    std::cout << "Number of Loses: " << m-sumSwitch << std::endl;



    return a.exec();
}
