#include <QtGui/QApplication>

#include <qwt_plot.h>
#include "allwaysStayPlot.h"
#include "allwaysSwitchPlot.h"

int main( int argc, char *argv[] )
{

    int m = 1000;

    QApplication a (argc, argv);
    QwtPlot *plot1 = new AllwaysStayPlot(m);
    QwtPlot *plot2 = new AllwaysSwitchPlot(m);

    plot1->replot();
    plot2->replot();
    plot1->show();
    plot2->show();

    return a.exec();
}
