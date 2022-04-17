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

struct Movie{
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

class maxHeap{


    private:
    vector<Movie> heap;
   public:


    void insertMovie(string title, string year, string genre, double rating, double tenRating, int movieVotes, string runTime){// Rudolph will write
maxHeap * newNode = new Movie( title, year, genre, rating,tenRating, movieVotes, runTime);

vector.push_back(newNode);
    }

   /*Movie* search(string movieName){
   int n =  heap.size();
   vector<int>::iterator it;
    for (it = heap.begin(); t != heap.end();it++){
if (heap->title = movieName){
cout<< heap->title;
       cout<< heap-> year;
      cout<< heap-> runTime;
       cout<< heap-> genre;
       cout<< heap->  rating;
        cout <<heap->tenRating;
       cout <<heap-> movieVotes;
}*
    }
else{
cout<< "not found";

}
    }*/

    void heapsort(){


    }

};