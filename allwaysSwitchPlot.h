#ifndef ALLWAYSSWITCHPLOT_H
#define ALLWAYSSWITCHPLOT_H

#include <QtGui/QWidget>

#include <qwt_plot.h>
#include <qwt_series_data.h>
#include <qwt_column_symbol.h>
#include <qwt_plot_histogram.h>

class AllwaysSwitchPlot : public QwtPlot
{
    Q_OBJECT

        QVector<QwtIntervalSample> data;
        QwtPlotHistogram graph;
        QwtColumnSymbol symbol;

    public:
        //Constants

        //Constructor
        AllwaysSwitchPlot(int count = 5000);
        virtual ~AllwaysSwitchPlot();

};

#endif  //ALLWAYSSWITCHPLOT_H
