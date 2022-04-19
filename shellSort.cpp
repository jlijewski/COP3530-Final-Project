#include "shellSort.h"

void shellSort::insertMovie(string title, string year, string genre, double rating, double tenRating, int movieVotes,
                            string runTime) {
    Movie testMovie = Movie(title, runTime, year, genre, rating, tenRating, movieVotes);
    shell.push_back(testMovie);
    
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
    //cout << shell[0].title << " " << shell[0].rating << endl;
}

vector<string> shellSort::getMax() {
    sort();
    vector<string> maxToReturn;
    maxToReturn.push_back(shell.at(counter).title);
    maxToReturn.push_back(to_string(shell.at(counter).tenRating));
    maxToReturn.push_back(shell.at(counter).genre);
    counter++;
    return maxToReturn;
}

