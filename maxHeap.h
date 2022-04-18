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


using namespace std;



class maxHeap{

    struct Movie
    {
        string title;
        string year;
        string runTime;
        string genre;
        double rating;
        double tenRating;
        int movieVotes;

        Movie(string _title, string _runTime, string _year ,string _genre,double _rating, double _tenRating, int _movieVotes)
        {
            title = _title;
            runTime = _runTime;
            year= _year ;
            genre= _genre;
            rating= _rating;
            tenRating = _tenRating;
            movieVotes = _movieVotes;
        }
    };


    
    vector<Movie> heap;
   public:

    void insertMovie(string title, string year, string genre, double rating, double tenRating, int movieVotes, string runTime){
	 //maxHeap * newNode = new Movie( title, year, genre, rating,tenRating, movieVotes, runTime);
	  //heap.push_back(newNode);
      heapifyup(heap.size() -1);

    }

    void heapifyUp(int rating){

    if (in >= 0 && par(rating) >= 0 && heap[par(rating)] > heap[rating]) {
          int temp = heap[rating];
          heap[rating] = heap[par(rating)];
          heap[par(rating)] = temp;
          heapifyup(par(rating));
       }


    }


    void heapifyDown(int rating){

    int child = l(rating);

       int child1 = r(rating);

       if (child >= 0 && child1 >= 0 && heap[child] > heap[child1]) {
          child = child1;
       }

       if (child > 0 && heap[rating] > heap[child]) {

          int t = heap[rating];
          heap[rating] = heap[child];
          heap[child] = t;
          heapifydown(child);

       }



    };
    void getMax();
    void deleteMax();
    


    

};