#include <QtGui/QApplication>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

#include <qwt_plot_histogram.h>
#include <qwt_series_data.h>
#include <qwt_global.h>
#include <qwt_plot.h>
#include <qwt_column_symbol.h>

#include <stdio.h>
#include <iostream>

#include "experiment.h"

int main( int argc, char *argv[] )
{

    unsigned int n, m;
    m = 100000;
    int sumSwitch = 0;
    int sumStay = 0;

    QApplication a (argc, argv);
    QwtPlot pSwitch, pStay;
    Experiment e;

    pSwitch.setTitle( "Allways Switch" );
    pStay.setTitle( "Allways Stay" );
    
    

    //Setup Histogram Plot
    QwtPlotHistogram *hSwitch = new QwtPlotHistogram( "allwaysSwitch" );
    QwtPlotHistogram *hStay = new QwtPlotHistogram( "allwaysStay" );
    QwtColumnSymbol *symbol = new QwtColumnSymbol( QwtColumnSymbol::Box );
    symbol->setFrameStyle( QwtColumnSymbol::Raised );
    symbol->setPalette(Qt::darkCyan);
    hSwitch->setSymbol(symbol);
    hStay->setSymbol(symbol);
    hSwitch->setBaseline(0);
    hStay->setBaseline(0);


    for(n = 0; n<m;n++)
    {
        int curResult = e.conductExperiment(Experiment::allwaysSwitch);
        sumSwitch += curResult;

        curResult = e.conductExperiment(Experiment::allwaysStay);
        sumStay += curResult;

        if((n%1000)==0)
        {
            QVector<QwtIntervalSample> dataSwitch;
            dataSwitch.append( QwtIntervalSample(n,0,1));
            dataSwitch.append( QwtIntervalSample(sumSwitch,1,2));
            dataSwitch.append( QwtIntervalSample(n-sumSwitch,2,3));

            QVector<QwtIntervalSample> dataStay;
            dataStay.append( QwtIntervalSample(n,5,6));
            dataStay.append( QwtIntervalSample(sumStay,6,7));
            dataStay.append( QwtIntervalSample(n-sumStay,7,8));
            
            hSwitch->setSamples(dataSwitch);
            hStay->setSamples(dataStay);
            hSwitch->attach(&pSwitch);
            hStay->attach(&pStay);
            pSwitch.replot();
            pStay.replot();
            pSwitch.show();
            pStay.show();
            std::cout << "\r";
            std::cout << (n/(double)m)*100 << "%";
        }
    }
    std::cout << "\r";
    std::cout << "Allways Switching" << std::endl;
    std::cout << "Number of Wins: " << sumSwitch << std::endl;
    std::cout << "Number of Loses: " << m-sumSwitch << std::endl;

    std::cout << "Allways Staying" << std::endl;
    std::cout << "Number of Wins: " << sumStay << std::endl;
    std::cout << "Number of Loses: " << m-sumStay << std::endl;



    return a.exec();
}
