/// \class AliMyClass
/// \brief This is a brief description of my class
///
/// \details This is a longer description of the class. This longer description is
///          formatted using the Markdown syntax (see below) and can span on multiple
///          lines.
///
/// Separate the paragraphs by leaving a blank line between them.
///
/// \copyright No Copyright
/// \author    Nikolaos Tolis
/// \date TODO: set the date

#ifndef PRIORITYQUEUE_HPP_
#define PRIORITYQUEUE_HPP_

#include <vector>

using namespace std;


class PQNode
{
public:
    PQNode(int n, double weight): n(n), weight(weight){}
    int n;
    double weight;
};


class PriorityQueue
{
public:


    PriorityQueue(int capacity);
    virtual ~PriorityQueue();
    bool isEmpty();
    PQNode* minPriority();
	void insert(const int& node, const double& value);
    bool contains(int n);
    void chgPriority(const int& node,const double& value);

private:

    int size;
    int capacity;
    vector<int> pos;
    vector<PQNode*> PQVec;
    void reorder(int index);
    void swap(PQNode*& n1, PQNode*& n2);


};

#endif /* PRIORITYQUEUE_HPP_ */
