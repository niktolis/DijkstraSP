//!
//! \name       main.cpp.
//! \author     Nikolaos Tolis.
//! \version    1.0.
//! \copyright  No Copyright.
//! \brief      C++ for C Programmers, Part A, 2nd and 3rd Assignment.
//! \details    TODO: Write the details

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "Graph.hpp"
#include "PriorityQueue.hpp"
#include "HWM.hpp"
#include "ShortestPath.hpp"


using namespace std;

int main(void)
{
	HWM homeWorkMgr;

	vector<int> test;
	vector<int> test1;

	Graph *myGraph;
	homeWorkMgr.generateExampleGraph(myGraph);

	cout << *myGraph;

	ShortestPath sp(myGraph);
	ShortestPath sp1(myGraph);

	sp.path(0, 3);

	sp1.path(2, 4);


	cout << sp;

	cout << sp1;

}
