#include <iostream>
#include <cstring>
#include "Client.h"

using namespace std;

int main() {
    char restaurantName[] = "Joe's TexMex";
    Client * client = new Client(restaurantName);
    char * input = new char[10];
    do{
        client->printMenu();
        cout << endl;
        cout << "Enter input: ";
        cin.getline(input, 10);
        if(strcmp(input, "X") != 0){
            client->translateInput(input);
        }
    } while(strcmp(input, "X") != 0);

    delete client;
    delete[] input;
    return 0;
}