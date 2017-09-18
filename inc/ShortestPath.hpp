/*
 * ShortestPath.hpp
 *
 *  Created on: Aug 21, 2017
 *      Author: tolis
 */

#ifndef SHORTESTPATH_HPP_
#define SHORTESTPATH_HPP_

#include <vector>
#include "Graph.hpp"

using namespace std;
/*
 *
 */
class ShortestPath
{
public:
    ShortestPath(Graph*& graph);
    ~ShortestPath();
	vector<int> path(const int& src, const int& dest);
	void setMaxDistance(const double& maxDistance) { this->maxDistance = maxDistance; }
	void printPath(ostream& out) const;
	double getPathSize() { return pathSize; }
	friend ostream& operator<<(ostream& out, ShortestPath& sp);

private:
	double maxDistance = 11.0; //! TODO: change it
	double pathSize;
	vector<int> pathSequence;
	Graph* graph;
	void createPath(const vector<int>& previous, int dest, vector<int>& pathSeq);

};

#endif /* SHORTESTPATH_HPP_ */
