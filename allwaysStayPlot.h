#ifndef ALLWAYSSTAYPLOT_H
#define ALLWAYSSTAYPLOT_H

#include <QtGui/QWidget>

#include <qwt_plot.h>
#include <qwt_series_data.h>

class AllwaysStayPlot : public QwtPlot 
{
    Q_OBJECT
    
        QVector<QwtIntervalSample> data;

    public:
        //Constants
    
        //Constructor
        AllwaysStayPlot(int count = 5000);
        ~AllwaysStayPlot(){};

};

#endif  //ALLWAYSSTAYPLOT_H
