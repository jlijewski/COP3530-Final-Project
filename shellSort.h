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
//#include <bits/stdc++.h>
#include <math.h>
#include <algorithm>
using namespace std;

class shellSort{
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
    vector<Movie> shell;
    int counter = 0;
public:
    void insertMovie(string title, string year, string genre, double rating, double tenRating, int movieVotes, string runTime);
    vector<string> getMax();
    void sort();
};
