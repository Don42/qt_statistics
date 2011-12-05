#include <QtGui/QApplication>

#include <qwt_plot.h>
#include "allwaysStayPlot.h"

int main( int argc, char *argv[] )
{

    int m = 1000;

    QApplication a (argc, argv);
    QwtPlot *plot = new AllwaysStayPlot(m);

    plot->replot();
    plot->show();

    return a.exec();
}
