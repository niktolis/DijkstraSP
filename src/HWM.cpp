/*
 * HWM.cpp
 *
 *  Created on: Aug 21, 2017
 *      Author: tolis
 */

#include "HWM.hpp"
#include <cstdlib>
#include <ctime>

HWM::HWM(const double density,
    const double minWeight,
    const double maxWeight,
    const int size) : density(density), minW(minWeight), maxW(maxWeight), size(size)
{
        Graph *HwGraph; 

    // Generate the random graph with the selected attributes
    this->generateRandomGraph(HwGraph);

    // Print the adjacency lists of the graph
    cout << *HwGraph;




}


HWM::~HWM()
{
    // TODO Auto-generated destructor stub
}

void HWM::generateExampleGraph(Graph*& g)
{

    g = new Graph(static_cast<int>(graphMat.size()));

    for (auto i = 0; i < graphMat.size(); i++)
    {
        for (auto j = 0; j < graphMat.size(); j++)
        {
            if (graphMat[i][j] > 0.0)
            {
                g->addEdge(i, j, graphMat[i][j]);
            }
        }
    }
}

void HWM::generateRandomGraph(Graph*& g)
{
    srand(static_cast<unsigned int>(time(0)));
    
    g = new Graph(size);

    for (auto i = 0; i < size; i++)
    {
        for (auto j = 0; j < size; j++)
        {
            double weight = (prob() < density) * randW();
            if (weight > 0.0)
            {
                g->addEdge(i, j, weight);
            }
        }
    }
}

inline double HWM::prob()
{
    return (static_cast<double>(rand()) / RAND_MAX);
}

inline double HWM::randW()
{
    return ((maxW - minW) * (static_cast<double>(rand()) / static_cast<double>(RAND_MAX)) + minW);
}

