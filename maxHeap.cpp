#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <utility>
#include <vector>
#include <iomanip>
#include <set>
#include <iostream>
#include <fstream>
#include <assert.h>
#include <bits/stdc++.h>
#include <math.h>
#include <algorithm> 
#include "maxHeap.h"
using namespace std;

void maxHeap::insertMovie(string title, string year, string genre, double rating, double tenRating, int movieVotes, string runTime)
{
    Movie testMovie = Movie(title, runTime, year, genre, rating, tenRating, movieVotes);
    heap.push_back(testMovie);

    heapifyUp(heap.size() - 1);
}
void maxHeap::heapifyUp(int index)
{
    int parent = (index - 1) / 2;
    if(parent < 0)
    {
        return;
    }
    else
    {
        if(heap.at(index).rating > heap.at(parent).rating)
        {
            swap(heap.at(index), heap.at(parent));
            heapifyUp(parent);
        }

    }
}
void maxHeap::heapifyDown(int index)
{
    int left = (index + 1) * 2;
    int right = (index + 2) * 2;
    int childToReplace = index;

    if(left < heap.size() && heap.at(left).rating > heap.at(index).rating)
    {
        childToReplace = left;
    }
    if(childToReplace == left)
    {
        if(right < heap.size() && heap.at(right).rating > heap.at(childToReplace).rating)
        {
            childToReplace == right;
        }
    }
    else
    {
        if(right < heap.size() && heap.at(right).rating > heap.at(index).rating)
        {
            childToReplace == right;
        }
    }
    if(childToReplace == index)
    {
        return;
    }
    else
    {
        swap(heap.at(index), heap.at(childToReplace));
        heapifyDown(childToReplace);
    }

}
vector<string> maxHeap::getMax()
{
    vector<string> maxToReturn;
    maxToReturn.push_back(heap.at(counter).title);
    maxToReturn.push_back(to_string(heap.at(counter).tenRating));
    maxToReturn.push_back(heap.at(counter).genre);
    counter++;
    return maxToReturn;
    
}
void maxHeap::deleteMax()
{
    swap(heap.at(0), heap.at(heap.size() - 1));
    heap.pop_back();
    heapifyDown(0);
}
