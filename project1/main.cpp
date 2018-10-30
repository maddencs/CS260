#include <cstring>
#include <iostream>
#include "RecordLabel.h"
#include "Artist.h"

void printMenu();
void evalInput(int, RecordLabel*);

int main(){
    char artistFile[] = "/home/cory/cs260/project1/artists.txt";
    char songFile[] = "/home/cory/cs260/project1/songs.txt";
    RecordLabel * recordLabel = new RecordLabel(artistFile, songFile);

    int input;
    printMenu();
    while(cin >> input){
        if(input == 5){
            break;
        }
        evalInput(input, recordLabel);
        printMenu();
    }
    recordLabel->saveToFile();
    delete recordLabel;
}


void printMenu(){
    cout << "Enter one of the following numbers to perform an action: " << endl
         << "1. Print Artists" << endl
         << "2. Find Artist By Name" << endl
         << "3. Delete Artist By Name" << endl
         << "4. Delete Unpopular Songs" << endl
         << "5. Exit" << endl;
}

void evalInput(int input, RecordLabel * label){
    switch(input){
        case 1:{
            label->printArtists();
            break;
        }
        case 2:{
            char * name = new char[100];
            cout << "Enter artist name: ";
            cin.ignore();
            cin.getline(name, 100);
            Artist * artist = label->getArtistByName(name);
            if(artist != nullptr) {
                cout << *artist;
            } else {
                cout << "An artist matching that criteria does not exist." << endl;
            }
            delete[] name;
            break;
        }
        case 3:{
            char * name = new char[100];
            cout << "Enter name of artist to delete: ";
            cin.ignore();
            cin.getline(name, 100);
            Artist * artist = label->getArtistByName(name);
            label->removeArtist(artist);
            delete[] name;
            break;
        }
        case 4:{
            int minViews;
            cout << "Enter minimum views for a song: ";
            cin.ignore();
            cin >> minViews;
            int deleted = label->deleteUnpopularSongs(minViews);
            printf("Deleted %d", deleted);
            break;
        }
        default:
            break;
    }
}
