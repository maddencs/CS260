#include <cstring>
#include <iostream>
#include <fstream>
#include "RecordLabel.h"
#include "Node.h"

using namespace std;

const int MAX_LINE_SIZE = 500;

Artist * RecordLabel::addArtist(char *name= nullptr,
        char *topStory= nullptr,
        char *description= nullptr) {
    auto *artist = new Artist(name, topStory, description);
    auto *node = new Node<Artist>(artist);
    artistList->add(node);
    return artist;
}

bool RecordLabel::removeArtist(Artist * artist) {
    artistList->remove(artist);
    return true;
}

RecordLabel::~RecordLabel() {
    delete[] artistsFileName;
    delete[] songsFileName;
    delete artistList;
}

RecordLabel::RecordLabel(char * artistsFileName, char * songFileName) {
    this->artistsFileName = new char[strlen(artistsFileName) + 1];
    this->songsFileName = new char[strlen(songFileName) + 1];
    strcpy(this->artistsFileName, artistsFileName);
    strcpy(this->songsFileName, songFileName);
    artistList = new LinkedList<Artist>;
    ifstream artistFile;
    artistFile.open(artistsFileName);
    loadArtists(artistFile);
    artistFile.close();
    ifstream songFile;
    songFile.open(songFileName);
    loadArtistSongs(songFile);
    Node<Artist> * node = artistList->getHead();
    while(node){
        node->getItem()->popularitySort();
        node = node->getNext();
    }
    songFile.close();
}

Artist *RecordLabel::getArtistByName(char *name) {
    Node<Artist> * node = artistList->getHead();
    while(node){
        if(strcmp(node->getItem()->getName(), name) == 0)
            return node->getItem();
        node = node->getNext();
    }
    return nullptr;
}

void RecordLabel::loadArtists(ifstream &file) {
    char * line = new char[MAX_LINE_SIZE];
    char **artistAttrs = new char*[4];
    char *pch;
    Node<Artist> * node;
    while(file.getline(line, MAX_LINE_SIZE)){
        for(int i=0; i < 3; i++){
            artistAttrs[i] = new char[MAX_LINE_SIZE];
        }
        pch = strtok(line, ";");
        int attrCount = 0;
        while(pch != nullptr){
            strcpy(artistAttrs[attrCount++], pch);
            pch = strtok(NULL, ";");
        }
        Artist * artist = new Artist(artistAttrs[0], artistAttrs[1], artistAttrs[2]);
        node = new Node<Artist>(artist);
        artistList->add(node);
        for(int i=0; i < 3; i++){
            delete[] artistAttrs[i];
        }
    }
    delete[] artistAttrs;
    delete[] line;
}

void RecordLabel::loadArtistSongs(std::ifstream &file) {
    char * line = new char[MAX_LINE_SIZE];
    char **songAttrs = new char*[5];
    char *pch;
    while(file.getline(line, MAX_LINE_SIZE)){
        for(int i=0; i < 5; i++){
            songAttrs[i] = new char[MAX_LINE_SIZE];
        }
        pch = strtok(line, ";");
        int attrCount = 0;
        while(pch != nullptr){
            strcpy(songAttrs[attrCount++], pch);
            pch = strtok(NULL, ";");
        }
        Artist * artist = getArtistByName(songAttrs[0]);
        if(artist == nullptr){
            artist = new Artist(songAttrs[0], NULL, NULL);
        }
        Song * song = new Song(songAttrs[1], atof(songAttrs[2]), atoi(songAttrs[3]), atoi(songAttrs[4]));
        artist->addSong(song);
        for(int i=0; i < 5; i++){
            delete[] songAttrs[i];
        }
    }
    delete[] songAttrs;
    delete[] line;

}

void RecordLabel::printArtists() {
    Node<Artist> * current = artistList->getHead();
    while(current){
        std::cout << *current->getItem();
        current = current->getNext();
    }
}

void RecordLabel::saveToFile() {
    ofstream artistFile;
    ofstream songFile;
    artistFile.open(artistsFileName, ios::trunc);
    songFile.open(songsFileName, ios::trunc);

    Node<Artist> * artistNode = artistList->getHead();
    while(artistNode != nullptr){
        Artist * artist = artistNode->getItem();
        artistFile << artist->getName() << ";"
        << artist->getStory() << ";"
        << artist->getDescription() << endl;
        artist->writeSongsToFile(songFile);
        artistNode = artistNode->getNext();
    }
    artistFile.close();
    songFile.close();
}

int RecordLabel::deleteUnpopularSongs(int minimumViews) {
    int deleted = 0;
    Node<Artist> * artistNode = artistList->getHead();
    while(artistNode != nullptr){
        Artist * artist = artistNode->getItem();
        deleted += artist->deleteUnpopularSongs(minimumViews);
        artistNode = artistNode->getNext();
    }
    return deleted;
}

