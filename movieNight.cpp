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
#include "maxHeap.h"
using namespace std;



int main() {
    maxHeap movieList;
    
    ifstream movieData("movieData.tsv");
    ifstream ratingData("movieRatings.tsv");
    
    string line1;
    getline(movieData, line1);
    

    string line2;
    getline(ratingData, line2);
    
    
    int counter = 0;
    
    
    while(!movieData.eof()){

    
        string movieNumber;
        getline(movieData, movieNumber, '\t');
    
        string movieType;
        getline(movieData, movieType, '\t');
    
        string moviePrimaryTitle;
        getline(movieData, moviePrimaryTitle, '\t');
    
        string movieOriginalTitle;
        getline(movieData, movieOriginalTitle, '\t');
    
        string movieIsAdult;
        getline(movieData, movieIsAdult, '\t');
    
        string movieStartYear;
        getline(movieData, movieStartYear, '\t');
    
        string movieEndYear;
        getline(movieData, movieEndYear, '\t');
    
        string movieRunTime;
        getline(movieData, movieRunTime, '\t');
    
        string movieGenre;
        getline(movieData, movieGenre, '\n');
    
        string movieRatingNum;
        getline(ratingData, movieRatingNum, '\t');
    
        string movieRating;
        getline(ratingData, movieRating, '\t');
    
        string movieVotes;
        getline(ratingData, movieVotes, '\n');
        double rating = 0;
        int votes;
        try
        {
            rating = stod(movieRating);
            votes = stoi(movieVotes);
        }
        catch(const std::exception& e)
        {
            continue;
        }
        
        
        if(movieType != "movie"|| votes < 50)
        {
            continue;
        }
        else
        {
            counter++;
            double compareRating = rating * (double) votes;
            movieList.insertMovie(moviePrimaryTitle, movieStartYear, movieGenre, compareRating, rating, votes, movieRunTime)
            
        }
        
        
    }
    cout<< "Choose option";
    cout<< "For search movie enter option 1";
    cout<< "option 2";
   int option;
    cin>> option;
    bool end =false
    while(option != 2 || option != 1){
    cout<<"wront option, enter either 1 or 2 ";
    cin >>option
    }
    while(!end){
    cout<< counter<< endl;
cout<< "Enter name to search title";
string nameOfMovie;
cin>> nameOfMovie;
movieList.search(nameOfMovie);
}


    
    
    return 0;
}