

#ifndef HWM_HPP_
#define HWM_HPP_

#include "Graph.hpp"

class HWM
{
public:
    HWM(const double density = 0.2, 
        const double minWeight = 1.0, 
        const double maxWeight = 10.0,
        const int size = 50);
    ~HWM();
    void generateExampleGraph(Graph*& g);
    void generateRandomGraph(Graph*& g);

private:


    inline double prob();
    inline double randW();

    vector<vector<double>> graphMat = { { 0.0,5.1,0.0,9.1,2.1,0.0 },
                                        { 5.1,0.0,2.1,0.0,0.0,0.0 },
                                        { 0.0,2.1,0.0,3.1,0.0,0.0 },
                                        { 9.1,0.0,3.1,0.0,0.0,2.1 },
                                        { 2.1,0.0,0.0,0.0,0.0,3.1 },
                                        { 0.0,0.0,0.0,2.1,3.1,0.0 } };
    
    double minW;
    double maxW;
    double density;
    int size;
};

#endif /* HWM_HPP_ */
