/**
* \file Graph.hpp
*
* \brief An undirected weighted graph
*
* \author TolisN
*
* \version 1.0
*
* \date September, 2017
*
*/
#ifndef GRAPH_HPP_
#define GRAPH_HPP_

#include <vector>
#include <iostream>

using namespace std;

/**
*	\class   AdjVertex
*
*	\brief   Adjacent Vertex class
*
*	Helper class that holds the information for the
*	adjacent vertex of the source
*/ 
class AdjVertex
{
public:

    /// \brief Constructor method of AdjVertex
    /// \details
    /// \param dest
    /// \param cost
    AdjVertex(int vIndex, double cost, AdjVertex* next = nullptr) :
        nextVIdx(vIndex), cost(cost), next(next) {}

	/// <summary>
	/// 
	/// </summary>
    ~AdjVertex() {}

	/// <summary>
	/// </summary>
    int getNextVertexId() const noexcept { return nextVIdx; }
    double getEdgeCost() const noexcept { return cost; }
    AdjVertex* getNextVertex() const noexcept { return next; }

private:
    int nextVIdx;
    double cost;
    AdjVertex* next;
};

class Graph
{

private:

    class AdjList
    {
    public:
        AdjList(AdjVertex *head) : head(head) {}
        AdjVertex *head;
    };

    int V; ///< Number of vertices in the graph
    int E; ///< Number of edges in the graph
    vector<AdjList> adjListVec;

public:

    /// \brief   Constructor method of Graph.
    /// \details Creates the graph object by passing
    ///          the number of vertices of the graph.
    /// \param V The number of vertices of the graph.
    Graph(int V);

    /// \brief   Destructor method of Graph.
    /// \details Destroys the graph object.
    virtual ~Graph();

    /// \brief
    /// \details
    /// \param v
    bool vertexExists(const int& v);

    /// \brief
    /// \details
    /// \param v
    void addVertex(const int& v);

    int getV() const { return this->V; }

    /// \brief
    /// \details
    /// \param v1
    /// \param v2
    /// \return
    bool isAdjacent(const int& v1, const int& v2) const;

    /// \brief      addEdge method of Graph.
    /// \details    If v1 and v2 vertices exists adds and
    ///             edge among them with a given cost.
    /// \param v1   The first vertex.
    /// \param v2   The second vertex.
    /// \param cost The cost of the edge.
    void addEdge(const int& v1, const int& v2, const double& cost);

    /// \brief     printGraph method of Graph.
    /// \details   Creates the output stream that is representing
    ///            the graph.
    /// \param out The reference to the output stream.
    void printGraph(ostream& out) const;

    /// \brief
    /// \details
    /// \param out
    /// \param g
    /// \return
    friend ostream& operator<<(ostream& out, Graph& g);

    const vector<AdjList> getAdjListVec() { return this->adjListVec; }

};

#endif /* GRAPH_HPP_ */
