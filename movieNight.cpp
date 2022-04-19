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

vector<string>  manageList(vector<string> personalList);
vector<string> deleteMovie(vector<string> personalList, string title);

int main() {

    cout<<"WELCOME TO MOVIE-NIGHT:PICK A GENRE"<<endl;
    cout<< "0. ANY GENRE" << endl;
    cout<< "1. ACTION" << endl;
    cout<< "2. ADVENTURE" << endl;
    cout<< "3. ANIMATION" << endl;
    cout<< "4. BIOGRAPHY" << endl;
    cout<< "5. COMEDY" << endl;
    cout<< "6. CRIME" << endl;
    cout<< "7. DOCUMENTARY" << endl;
    cout<< "8. DRAMA" << endl;
    cout<< "9. FAMILY" << endl;
    cout<< "10. FANTASY" << endl;
    cout<< "11. FILM NOIR" << endl;
    cout<< "12. HISTORY" << endl;
    cout<< "13. HORROR" << endl;
    cout<< "14. MUSIC" << endl;
    cout<< "15. MUSICAL" << endl;
    cout<< "16. MYSTERY" << endl;
    cout<< "17. ROMANCE" << endl;
    cout<< "18. SCI-FI" << endl;
    cout<< "19. SPORT" << endl;
    cout<< "20. THRILLER" << endl;
    cout<< "21. WAR" << endl;
    cout<< "22. WESTERN" << endl;
    int start;
    cin>>start;

    string genre;
    switch(start){
        case 0:
            genre = "Any";
            break;
            case 1:
                genre = "Action";
                break;
                case 2:
                    genre = "Adventure";
                    break;
                    case 3:
                        genre = "Animation";
                        break;
                        case 4:
                            genre = "Biography";
                            break;
                            case 5:
                                genre = "Comedy";
                                break;
                                case 6:
                                    genre = "Crime";
                                    break;
                                    case 7:
                                        genre = "Documentary";
                                        break;
                                        case 8:
                                            genre = "Drama";
                                            break;
                                            case 9:
                                                genre = "Family";
                                                break;
                                                case 10:
                                                    genre = "Fantasy";
                                                    break;
                                                    case 11:
                                                        genre = "Film-Noir";
                                                        break;
                                                        case 12:
                                                            genre = "History";
                                                            break;
                                                            case 13:
                                                                genre = "Horror";
                                                                break;
                                                                case 14:
                                                                    genre = "Music";
                                                                    break;
                                                                    case 15:
                                                                        genre = "Musical";
                                                                        break;
                                                                        case 16:
                                                                            genre = "Mystery";
                                                                            break;
                                                                            case 17:
                                                                                genre = "Romance";
                                                                                break;
                                                                                case 18:
                                                                                    genre = "Sci-Fi";
                                                                                    break;
                                                                                    case 19:
                                                                                        genre = "Sport";
                                                                                        break;
                                                                                        case 20:
                                                                                            genre = "Thriller";
                                                                                            break;
                                                                                            case 21:
                                                                                                genre = "War";
                                                                                                break;
                                                                                                case 22:
                                                                                                    genre = "Western";
                                                                                                    break;
    }



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
                    if(genre == "Any")
                        movieList.insertMovie(moviePrimaryTitle, movieStartYear, movieGenre, compareRating, rating, votes, movieRunTime);
                    else if(movieGenre.find(genre) != -1){
                        movieList.insertMovie(moviePrimaryTitle, movieStartYear, movieGenre, compareRating, rating, votes, movieRunTime);
                    }
                    auto heapStop = chrono::system_clock::now();
                    heapTime = (heapStop - heapStart);
                    //heapTimeTaken += heapTime.count();

                    if(genre == "Any")
                        shellList.insertMovie(moviePrimaryTitle, movieStartYear,movieGenre, compareRating, rating, votes, movieRunTime);
                    else if(movieGenre.find(genre) != -1)
                        shellList.insertMovie(moviePrimaryTitle, movieStartYear,movieGenre, compareRating, rating, votes, movieRunTime);
                }
            }
        }


    }
    vector<string> heapTop;
    vector<string> shellTop;

    if(genre != "Any")
        cout << genre << " MOVIES!" << endl;

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

        cout<<"TYPE 1 TO CONTINUE, 2 TO LOOK AT YOUR LIST, OR 3 TO EXIT"<<endl;

        string nextInput;
        cin>> nextInput;

        if(nextInput == "2"){
            personalList = manageList(personalList);
        }

        if(nextInput == "3")
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

vector<string>  manageList( vector<string> personalList){
    cout<< endl;
    cout<<"YOUR LIST:"<<endl;
    bool continueBool = true;
    int option;
    string title;
    while(continueBool){
        for(int i = 0; i < personalList.size(); i++)
        {
            cout<<personalList.at(i)<<endl;
        }
        cout<<"TYPE 1 TO DELETE A MOVIE, OR 2 TO EXIT" << endl;
        cin >> option;
        if(option == 1){
            cout << "MOVIE TO BE DELETED:" << endl;
            //cin.sync();
            cin.get();
            getline(cin, title);
            personalList = deleteMovie(personalList, title);
        }
        else
            continueBool = false;
    }
    return personalList;
}

vector<string> deleteMovie(vector<string> personalList, string title){
    bool found = false;
    for(int i = 0; i < personalList.size(); i++)
    {
        if(personalList.at(i) == title){
            personalList.erase(personalList.begin()+i);
            found = true;
        }
    }
    if(found)
        cout << "DELETED " << title << " FROM YOUR LIST!" << endl;
    else
        cout << title << " WAS NOT FOUND!" << endl;
    return personalList;
}