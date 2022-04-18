#include "shellSort.h"

void shellSort::insertMovie(string title, string year, string genre, double rating, double tenRating, int movieVotes,
                            string runTime) {
    Movie testMovie = Movie(title, runTime, year, genre, rating, tenRating, movieVotes);
    shell.push_back(testMovie);
    sort();
}
void shellSort::sort(){
    int gap = (int) shell.size()/2;
    while(gap > 0){
        for(int x = gap; x < shell.size(); x++){
            for(int y = x; y >= gap; y -= gap){
                if(shell[y - gap].rating < shell[y].rating)
                    swap(shell[y - gap], shell[y]);
                else
                    break;
            }
        }
        gap /= 2;
    }
    cout << shell[0].title << " " << shell[0].rating << endl;
}

void shellSort::getMax() {
    cout<< shell[0].title << " "<< shell[0].tenRating << " "<< shell[0].movieVotes<< endl;
}

