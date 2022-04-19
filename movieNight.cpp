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
#include "shellSort.h"
#include <chrono>



using namespace std;
using namespace std::chrono;



int main() {

    cout<<"WELCOME TO MOVIE-NIGHT:TYPE ANYTHING TO BEGIN"<<endl;
    string start;
    cin>>start;
    
    
    cout<<"LOADING MOVIE INFORMATION..."<<endl;
    
    vector<string> personalList;
    maxHeap movieList;
    shellSort shellList;
    
    
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
    
    int64_t heapTimeTaken;
    int64_t shellTimeTaken;
    chrono::duration<double> heapTime;
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

                    auto heapStart = chrono::system_clock::now();
                    movieList.insertMovie(moviePrimaryTitle, movieStartYear, movieGenre, compareRating, rating, votes, movieRunTime);
                    auto heapStop = chrono::system_clock::now();
                    heapTime = (heapStop - heapStart);
                    //heapTimeTaken += heapTime.count();

                    
                    shellList.insertMovie(moviePrimaryTitle, movieStartYear,movieGenre, compareRating, rating, votes, movieRunTime);
                    
                }
            }
        }
        
        
    }
    vector<string> heapTop;
    vector<string> shellTop;

    cout<<"------FIRST MOVIE------"<<endl;
    cout<<endl;
    cout<<"MOVIE FROM HEAP-SORT:"<<endl;
    heapTop = movieList.getMax();
    cout<<heapTop.at(0)<<" "<<heapTop.at(1)<< " "<< heapTop.at(2)<<endl;
    cout<<"TIME TAKEN FOR HEAP-SORT: "<< heapTime.count() << "seconds"<<endl;

    cout<<"MOVIE FROM SHELL-SORT:"<<endl;
    auto shellStart = chrono::system_clock::now();
    shellTop = shellList.getMax();
    auto shellStop = chrono::system_clock::now();
    chrono::duration<double> shellTime = (shellStop - shellStart);
    cout<<shellTop.at(0)<<" "<<shellTop.at(1)<< " "<< shellTop.at(2)<<endl;
    cout<<"TIME TAKEN FOR SHELL-SORT: "<< shellTime.count() << "seconds"<<endl;

    cout<<"ADD FIRST MOVIE TO LIST?(y/n)"<<endl;

    string firstInput;
    cin>>firstInput;

    if(firstInput == "y")
    {
        personalList.push_back(heapTop.at(0));
        cout<< "ADDED TO LIST!"<<endl;
    }

    bool continueBool = true;
    while(continueBool)
    {
        cout<<"------NEXT MOVIE------"<<endl;
        cout<<endl;
        cout<<"MOVIE:"<<endl;
        heapTop = movieList.getMax();
        cout<<heapTop.at(0)<<" "<<heapTop.at(1)<< " "<< heapTop.at(2)<<endl;

        
        cout<<"ADD MOVIE TO LIST?(y/n)"<<endl;

        string firstInput;
        cin>>firstInput;

        if(firstInput == "y")
        {
            personalList.push_back(heapTop.at(0));
            cout<< "ADDED TO LIST!"<<endl;
        }

        cout<<"TYPE 1 TO CONTINUE OR 2 TO EXIT"<<endl;

        string nextInput;
        cin>> nextInput;

        if(nextInput == "2")
        {
            continueBool = false;
        }


    }

    cout<<endl;
    cout<<"YOUR LIST:"<<endl;
    for(int i = 0; i < personalList.size(); i++)
    {
        cout<<personalList.at(i)<<endl;
    }

    
    
    
    



    
    
    return 0;
}