#ifndef ALLWAYSSTAYPLOT_H
#define ALLWAYSSTAYPLOT_H

#include <QtGui/QWidget>

#include <qwt_plot.h>
#include <qwt_series_data.h>
#include <qwt_column_symbol.h>
#include <qwt_plot_histogram.h>

class AllwaysStayPlot : public QwtPlot 
{
    Q_OBJECT
    
        QVector<QwtIntervalSample> data;
        QwtPlotHistogram graph;
        QwtColumnSymbol symbol;

    public:
        //Constants
    
        //Constructor
        AllwaysStayPlot(int count = 5000);
        virtual ~AllwaysStayPlot();

};

#endif  //ALLWAYSSTAYPLOT_H
