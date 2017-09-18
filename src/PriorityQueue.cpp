/*
 * PriorityQueue.cpp
 *
 *  Created on: Aug 20, 2017
 *      Author: tolis
 */

#include "PriorityQueue.hpp"
#include <iostream>

PriorityQueue::PriorityQueue(int capacity) : capacity(capacity)
{
    size = 0;
}

PriorityQueue::~PriorityQueue()
{

}

void PriorityQueue::swap(PQNode*& n1, PQNode*& n2)
{
    PQNode* temp = n1;
    n1 = n2;
    n2 = temp;
}

void PriorityQueue::reorder(int index)
{
    int smallest, left, right;
    smallest = index;
    left = 2 * index + 1;
    right = 2 * index + 2;


    if(left < size &&
                PQVec.at(left)->weight < PQVec.at(smallest)->weight)
    {
        smallest = left;
    }
    if(right < size &&
                PQVec.at(right)->weight < PQVec.at(smallest)->weight)
    {
        smallest = right;
    }
    if(smallest != index)
    {
        PQNode *smallestNode = this->PQVec.at(smallest);
        PQNode *indexNode = this->PQVec.at(index);

        this->pos.at(smallestNode->n) = index;
        this->pos.at(indexNode->n) = smallest;

        swap(this->PQVec.at(smallest), this->PQVec.at(index));

        reorder(smallest);
    }
}

void PriorityQueue::insert(const int& node, const double& value)
{
    if (size == PQVec.size())
    {
        this->PQVec.push_back(new PQNode(node, value));
        this->pos.push_back(node);
        
    }
    size++;

    reorder(size);
}

bool PriorityQueue::isEmpty()
{
    return (this->size == 0);
}

PQNode* PriorityQueue::minPriority()
{
    if(this->isEmpty())
    {
        return nullptr;
    }
    else
    {
        PQNode* root = PQVec.at(0);

        // Change positions o
        PQNode* lastNode = this->PQVec.at(this->size - 1);
        this->PQVec.at(0) = lastNode;

        this->pos[root->n] = this->size - 1;
        this->pos[lastNode->n] = 0;

        --this->size;
        reorder(0);

        return root;
    }
}


void PriorityQueue::chgPriority(const int& node,const double& value)
{
    
        int i = this->pos[node];
        this->PQVec.at(i)->weight = value;
    

    while (i && (this->PQVec.at(i)->weight
                         < this->PQVec.at((i-1)/2)->weight))
    {
        this->pos[this->PQVec.at(i)->n] = (i-1)/2;
        this->pos[this->PQVec.at((i-1)/2)->n] = i;
        swap(this->PQVec.at(i), this->PQVec.at((i-1)/2));

        i = (i - 1) / 2;
    }
}


bool PriorityQueue::contains(int n)
{
    return (this->pos[n] < this->size);
}
