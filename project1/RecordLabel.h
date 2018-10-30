#ifndef PROJECT1_RECORDLABEL_H
#define PROJECT1_RECORDLABEL_H
#include "LinkedList.h"
#include "Artist.h"
#include "Song.h"
#include <iostream>

class RecordLabel{
private:
    char * artistsFileName = nullptr;
    char * songsFileName = nullptr;
    LinkedList<Artist> *artistList = nullptr;
    void loadArtists(std::ifstream&);
    void loadArtistSongs(std::ifstream&);
public:
    Artist * addArtist(char *name, char *topStory, char *description);
    bool removeArtist(Artist*);
    Artist * getArtistByName(char * name);
    void printArtists();
    void saveToFile();
    int deleteUnpopularSongs(int);

    ~RecordLabel();
    RecordLabel(char *, char*);
};

#endif //PROJECT1_RECORDLABEL_H
