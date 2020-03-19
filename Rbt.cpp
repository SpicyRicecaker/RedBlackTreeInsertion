#include <iostream>
#include <cstring>
#include <fstream>
//#include "Node.h"

void getInput(char* in); //Gets console input, stores into in
void getFileInput(char* in); //Gets file input, stores into in

using namespace std;

//Main program
int main(){
  //Variable that stores user input
  char inArr[999];
  char* in = &inArr[0];

  //We should have a program loop
  bool running = true;
  while(running){
    //Ask user for their file name input
    getFileInput(in);

    //Split input, convert into int, then call insertion
    char* buffer = new char[4];
    int counter = 0;
    int inLen = strlen(in);
    for(int a = 0; a <= inLen; ++a){
      if(in[a] == ' ' || a == inLen){
        //insert(batoi(buffer))
        //debug
        cout << atoi(buffer) << endl;
        //Then reset counter and buffer
        buffer = new char[4];
        counter = 0;
        continue;
      }
      buffer[counter++] = in[a];
    }

    //Editing tree loop
    bool moddingTree = true;
    while(moddingTree){

    }
  }
  return 0;
}

//This function takes in user input and sets the in variable equal to it
void getInput(char* in){
  while(true){
    cin.getline(in, 999);
    cin.clear();
    if(strcmp(in, "") != 0){
      break;
    }
    cout << "Please enter something..." << endl;
  }
}

//This function asks for file input name and sets the in variable equal to it
void getFileInput(char* in){
  ifstream stream;
  while(true){
    cout << "Please enter the name of your file." << endl;
    getInput(in);
    stream.open(in);
    if(stream.good()){
      stream.getline(in, 999);
      break;
    }
    cout << "File not found. Please make sure your file name is correct." << endl;
  }
}
