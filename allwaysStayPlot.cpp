#include "allwaysStayPlot.h"
#include "experiment.h"



AllwaysStayPlot::AllwaysStayPlot(int count)
{
    Experiment ex;

    int sum, n;
    n = sum = 0;

    /*Setting up Look*/
    this->setTitle( "Allways Stay" );

    symbol.setFrameStyle( QwtColumnSymbol::Raised );
    symbol.setPalette( Qt::darkCyan );
    symbol.setStyle( QwtColumnSymbol::Box );
    graph.setSymbol(&symbol);
    graph.setBaseline(0);


    for(n = 0; n < count; n++)
    {
        int curResult = ex.conductExperiment( Experiment::allwaysSwitch );
        sum += curResult;
    }
    
    
    data.append( QwtIntervalSample(count, 0, 1));
    data.append( QwtIntervalSample(sum, 1, 2));
    data.append( QwtIntervalSample(count-sum, 2, 3));

    graph.setSamples( data );
    graph.attach( this );
    
}
