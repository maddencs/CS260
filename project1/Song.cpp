#include "Song.h"
#include <cstring>

Song::~Song() {
    delete[] title;
}

Song::Song(char *_title, float length, int numViews, int numLikes) {
    title = new char[strlen(_title) + 1];
    strcpy(title, _title);
    songLength = length;
    numberOfViews = numViews;
    numberOfLikes = numLikes;
}

int Song::getLikes() {
    return numberOfLikes;
}

int Song::getViews() {
    return numberOfViews;
}

float Song::getSongLength() {
    return songLength;
}

char * Song::getTitle() {
    return title;
}

ostream& operator<<(ostream &out, const Song &song){
    out << song.title << " - Duration: " << song.songLength
    << " - Likes: " << song.numberOfLikes
    << " - Views: " << song.numberOfViews;
    return out;
}

