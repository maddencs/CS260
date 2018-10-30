#ifndef PROJECT1_SONG_H
#define PROJECT1_SONG_H
#include <fstream>

using namespace std;

class Song{
public:
    char * getTitle();
    int getLikes();
    int getViews();
    float getSongLength();
    friend ostream & operator<<(ostream &, const Song&);

    Song(char *, float, int, int);
    ~Song();
private:
    char * title = nullptr;
    float songLength = 0.0;
    int numberOfViews = 0;
    int numberOfLikes = 0;
};

#endif //PROJECT1_SONG_H
