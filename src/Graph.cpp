/*
 * Graph.cpp
 *
 *  Created on: Aug 20, 2017
 *      Author: tolis
 */

#include "Graph.hpp"

Graph::Graph(int V): V(V)
{

    this->E = 0;

    //adjListVec.reserve(V);

    for(int i = 0; i < V; i++)
    {
        this->adjListVec.push_back(AdjList(nullptr));
    }

}

Graph::~Graph()
{
    // TODO Auto-generated destructor stub
}

bool Graph::isAdjacent(const int& v1, const int& v2) const
{
    AdjVertex *src  = this->adjListVec.at(v1).head;


    while (src != nullptr)
    {
        if(src->getNextVertexId() == v2)
        {
            return true;
        }

        src = src->getNextVertex();
    }
    return false;
}

bool Graph::vertexExists(const int& v)
{
    if (v >= 0 && v < V)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Graph::addVertex(const int& v)
{
    if (v >= 0 && !vertexExists(v))
    {
        this->adjListVec.push_back(AdjList(nullptr));
        V++;
    }
    else
    {
        /*! TODO: add an exception */
    }
}

void Graph::addEdge(const int& v1,const int& v2,const double& cost)
{
    int oldE = E;

    this->addVertex(v1);
    this->addVertex(v2);

    if (!this->isAdjacent(v1,v2))
    {
        AdjVertex* vertex = new AdjVertex(v2, cost, this->adjListVec.at(v1).head);
        this->adjListVec.at(v1).head = vertex;

        // Graph is undirected so we set the edge on both vertices
        AdjVertex* vertex2 = new AdjVertex(v1, cost, this->adjListVec.at(v2).head);
        this->adjListVec.at(v2).head = vertex2;
        
        E++;
    }
}

void Graph::printGraph(ostream& out) const
{

    out << "Number of Vertices is: " << V << endl;
    out << "Number of Edges is: " << E << endl;
    out << "Adjacency Lists:" << endl;
    for (auto i = 0; i < V; i++)
    {
        out << "Adjacency List of vertex: " << i << endl;
        AdjVertex *vertex = adjListVec.at(i).head;
        out << "head(" << i << "): ";
        while (vertex != nullptr)
        {
            out << vertex->getNextVertexId();
            out << "->(" << vertex->getEdgeCost() << "), ";
            vertex = vertex->getNextVertex();
        }
        out << endl;
    }

}

ostream& operator<<(ostream& out, Graph& g)
{
    g.printGraph(out);
    return out;
}
