#ifndef PROJECT1_ARTIST_H
#define PROJECT1_ARTIST_H

#include "LinkedList.h"
#include "Song.h"

class Artist{
public:
    void addSong(Song *);
    char *getName() const;
    void setName(char *name);
    char *getStory() const;
    void setStory(char *story);
    char *getDescription() const;
    void setDescription(char *description);
    int deleteUnpopularSongs(int);
    void printSongs() const;
    void writeSongsToFile(ofstream&);
    void popularitySort();
    friend ostream & operator<<(ostream &, const Artist&);


    ~Artist();
    Artist(char*, char*, char*);
private:
    char * name = nullptr;
    char * story = nullptr;
    char * description = nullptr;
    LinkedList<Song> * songList = new LinkedList<Song>;
};

#endif //PROJECT1_ARTIST_H
