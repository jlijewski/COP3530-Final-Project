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
    
    map<string, vector<string>> ratingMap;
    while(!ratingData.eof())
    {
        string movieRatingNum;
        getline(ratingData, movieRatingNum, '\t');
    
        string movieRating;
        getline(ratingData, movieRating, '\t');
    
        string movieVotes;
        getline(ratingData, movieVotes, '\n');

        vector<string> ratingVector;
        ratingVector.push_back(movieRating);
        ratingVector.push_back(movieVotes);
        ratingMap[movieRatingNum] = ratingVector;
    }
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
    
        
        
        
        
        if(movieType != "movie")
        {
            continue;
        }
        else
        {
            if(ratingMap.find(movieNumber) == ratingMap.end())
            {
                continue;
            }
            else
            {

            
                double rating = 0;
                int votes;
                try
                {
                    rating = stod(ratingMap[movieNumber].at(0));
                    votes = stoi(ratingMap[movieNumber].at(1));
                }
                catch(const std::exception& e)
                {
                    continue;
                }
                if( votes < 50)
                {
                    continue;
                }
                else
                {
                    counter++;
                    double compareRating = rating * (double) votes;
                    movieList.insertMovie(moviePrimaryTitle, movieStartYear, movieGenre, compareRating, rating, votes, movieRunTime);
                }
            }
        }
        
        
    }
    movieList.getMax();
    
    /*cout<< "Choose option";
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
    movieList.search(nameOfMovie);*/



    
    
    return 0;
}