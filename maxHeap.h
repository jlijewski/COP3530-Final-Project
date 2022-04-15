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

class maxHeap
{
    struct Movie
    {
        string title;
        string year;
        string genre;
        double rating;
        double tenRating;

        Movie(string _title, string _year, string _genre, double _rating, double _tenRating)
        {
            title = _title;
            year = _year;
            genre = _genre;
            rating = _rating;
            tenRating = _tenRating;
        }
    };
    
};