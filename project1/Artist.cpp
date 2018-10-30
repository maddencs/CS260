//
// Created by cory on 10/10/18.
//
#include <cstring>
#include <iostream>
#include "Artist.h"

char *Artist::getName() const {
    return name;
}

void Artist::setName(char *newName) {
    if (name) {
        if (strlen(name) >= strlen(newName)) {
            strcpy(name, newName);
            return;
        }
        delete[] name;
    }
    name = new char[strlen(newName) + 1];
    strcpy(name, newName);
}

char *Artist::getStory() const {
    return story;
}

void Artist::setStory(char *_story) {
    if (story) {
        if (strlen(story) >= strlen(_story)) {
            strcpy(story, _story);
            return;
        }
        delete[] story;
    }
    story = new char[strlen(_story) + 1];
    strcpy(story, _story);
}

char *Artist::getDescription() const {
    return description;
}

void Artist::setDescription(char *_description) {
    if (description) {
        if (strlen(description) >= strlen(_description)) {
            strcpy(description, _description);
            return;
        }
        delete[] description;
    }
    description = new char[strlen(_description) + 1];
    strcpy(description, _description);
}

void Artist::addSong(Song *song) {
    auto *node = new Node<Song>(song);
    songList->add(node);
}

Artist::~Artist() {
    delete songList;
    delete[] story;
    delete[] name;
    delete[] description;
}

int Artist::deleteUnpopularSongs(int minimumViews) {
    int deleted = 0;
    Node<Song> *node = songList->getHead();
    while (node) {
        if (node->getItem()->getViews() < minimumViews) {
            songList->remove(node->getItem());
            deleted++;
        }
        node = node->getNext();
    }
    return deleted;
}

Artist::Artist(char *_name, char *_story, char *_description) {
    setName(_name);
    setStory(_story);
    setDescription(_description);
}

void Artist::printSongs() const {
    Node<Song> *current = songList->getHead();
    while (current) {
        std::cout << *current->getItem() << endl;
        current = current->getNext();
    }
}

ostream &operator<<(ostream &out, const Artist &artist) {
    out << "Arist: " << artist.name << endl
        << "Top Story: " << artist.story << endl
        << "Description: " << artist.description << endl;
    artist.printSongs();
    out << endl;
    return out;
}

void Artist::writeSongsToFile(ofstream &file) {
    Node<Song> *songNode = songList->getHead();
    while (songNode) {
        Song *song = songNode->getItem();
        file << name << ";"
             << song->getTitle() << ";"
             << song->getSongLength() << ";"
             << song->getLikes() << ";"
             << song->getViews() << endl;
        songNode = songNode->getNext();
    }

}

Node<Song> *SORT(Node<Song> *sorted, Node<Song> *unsorted) {
    if (!unsorted || !sorted) {
        return sorted;
    }
    Node<Song> *next = unsorted->getNext();
    Node<Song> *previous = NULL;
    Node<Song> *current = sorted;

    unsorted->setNext(NULL);
    unsorted->setPrev(NULL);
    while (current) {
        if (current->getItem()->getLikes() < unsorted->getItem()->getLikes()) {
            if (current == sorted) {
                sorted->setPrev(unsorted);
                unsorted->setNext(current);
                return SORT(unsorted, next);
            }
            current->getPrev()->setNext(unsorted);
            unsorted->setPrev(current->getPrev());
            current->setPrev(unsorted);
            unsorted->setNext(current);
            break;
//            return SORT(sorted, next);
        }
        previous = current;
        current = current->getNext();
    }
    previous->setNext(unsorted);
    unsorted->setPrev(previous);
    return SORT(sorted, next);
}

void Artist::popularitySort() {
    Node<Song> *idx = songList->getHead();
    Node<Song> *unsorted = idx->getNext();
    idx->setNext(NULL);
    unsorted->setPrev(NULL);
    songList->setHead(SORT(idx, unsorted));
}

