/*
 * ShortestPath.cpp
 *
 *  Created on: Aug 21, 2017
 *      Author: tolis
 */

#include "ShortestPath.hpp"
#include "PriorityQueue.hpp"

ShortestPath::ShortestPath(Graph*& graph):graph(graph)
{
    // TODO Auto-generated constructor stub

}

ShortestPath::~ShortestPath()
{
    // TODO Auto-generated destructor stub
}

void ShortestPath::createPath(const vector<int>& previous, int dest, vector<int>& pathSeq)
{
	if (dest < 0)
	{
		return;
	}
	else
	{
		this->createPath(previous, previous.at(dest), pathSeq);
		pathSeq.push_back(dest);
	}
}

void  ShortestPath::printPath(ostream& out) const
{
	if (this->pathSequence.size() == 0)
	{
		out << "There is no path to print!" << endl;
	}
	else
	{
		out << "The shortest path from " << pathSequence.front() << " to " << pathSequence.back() << " is:" << endl;
		out << pathSequence.front();
		for (auto i = 1; i < pathSequence.size(); i++)
		{
			out << "->" << pathSequence.at(i);
		}

		out << endl;
	}
}

vector<int> ShortestPath::path(const int& src, const int& dest)
{
	int V = graph->getV();
	PriorityQueue openSet(V);
	
	vector<double> distance(V, this->maxDistance);

	for (auto i = 0; i < V; i++)
	{
		openSet.insert(i, distance.at(i));
	}

	openSet.chgPriority(src, 0);

	distance.at(src) = 0.0;

	vector<bool> closedSet(V, false);

	closedSet.at(src) = true;

	vector<int> prev(V, -1);


	while (!openSet.isEmpty() && closedSet.at(dest) != true)
	{
		PQNode *tempV = openSet.minPriority();

		int tempIdx = tempV->n;

		AdjVertex *vIterator = graph->getAdjListVec().at(tempIdx).head;

		while (vIterator != nullptr)
		{
			int destIdx = vIterator->getNextVertexId();

			if (openSet.contains(destIdx) &&
				distance.at(tempIdx) != maxDistance &&
				vIterator->getEdgeCost() + distance.at(tempIdx) < distance.at(destIdx))
			{
				distance.at(destIdx) = distance.at(tempIdx) + vIterator->getEdgeCost();
				prev.at(destIdx) = tempIdx;
				openSet.chgPriority(destIdx, distance.at(destIdx));
			}

			vIterator = vIterator->getNextVertex();

		}

		closedSet.at(tempIdx) = true;

	}

	createPath(prev, dest, this->pathSequence);
	pathSize = distance.at(dest);

	return this->pathSequence;
}

ostream& operator<<(ostream& out, ShortestPath& sp)
{
	sp.printPath(out);
	return out;
}