#include <iostream>
#include <cstring>
#include <fstream>
#include "Node.h"

void getInput(char* in); //Gets console input, stores into in
void read(Node* root, char* in); //Gets file input, stores into in, sequentially adds into rbt
int getAction(char* in); //Gets input and decides on a specific number corresponding to an action
void add(Node* &current, int toAdd); //Insert int into tree
void print(Node* current); //Prints the tree
void help(); //Prints list of commands

using namespace std;

//Main program
int main(){
  //Variable that stores user input
  char inArr[999];
  char* in = &inArr[0];

  //Root node of the red black tree
  Node* root = NULL;

  //We should have a program loop
  bool running = true;
  while(running){
    //Ask user for their file name input, and input into tree
    read(root, in);

    cout << "Now entering the modding tree phase! Enter \"help\" for a list of commands." << endl;
    //Editing tree loop
    bool moddingTree = true;
    while(moddingTree){
      //Ask the user what they want to do. 
      switch(getAction(in)){
        //Add
      case 2:
        cout << "Ok, please enter the number that you would like to add." << endl;
        getInput(in);
        add(root, atoi(in));
        cout << "\"" << atoi(in) << "\" has been added to the tree." << endl;
        break;
        //Print
      case 3:
        print(root);
        break;
        //Help
      case 4:
        //Print list of commands
        help();
        break;
        //Quit
      case 5:
        cout << "Thank you for choosing bubbles!" << endl;
        moddingTree = false;
        break;
      }
    }
    cout << "Would you like to create another tree? (y/n)" << endl;
    while(true){
      getInput(in);
      in[0] = toupper(in[0]);
      if(strcmp(in, "Y") == 0){
        //Reset variables
        root = NULL;
        break;
      }else if(strcmp(in, "N") == 0){
        running = !running;
        break;
      }
      cout << "Please enter (y/n)!" << endl;
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
void read(Node* root, char* in){
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
  //Split input, convert into int, then call insertion
  char* buffer = new char[4];
  int counter = 0;
  int inLen = strlen(in);
  for(int a = 0; a <= inLen; ++a){
    if(in[a] == ' ' || a == inLen){
      //Pass into insert function
      add(root, atoi(buffer));
      //Then reset counter and buffer
      buffer = new char[4];
      counter = 0;
      continue;
    }
    buffer[counter++] = in[a];
  }
}

//This function gets input using getInput() and strcmps to return a number to be used in the modding tree phase
int getAction(char* in){
  //Prompt user for a command
  cout << "Please enter a command." << endl;
  while(true){
    //Get input
    getInput(in);
    //Set everything to caps
    int inLen = strlen(in);
    for(int a = 0; a < inLen; ++a){
      in[a] = toupper(in[a]);
    }
    //Return a number corresponding to the command, or notify user of incorrect input.
    if(strcmp(in, "ADD") == 0){
      return 2;
    }else if(strcmp(in, "PRINT") == 0){
      return 3;
    }else if(strcmp(in, "HELP") == 0){
      return 4;
    }else if(strcmp(in, "QUIT") == 0){
      return 5;
    }
    cout << "\"" << in << "\" is not recognized as a command. Please type \"help\" for a list of commands!" << endl;
  }
}

//Inserts int into tree
void add(Node* &current, int toAdd){
  return;
}

//Tries to print all nodes in the red black tree, with color, sideways
void print(Node* current){
  
}

//Prints a list of all commands and their functions
void help(){
  cout << "\n----------\nEnter \"add\" to add a number to the tree,\n\"print\" to print the tree,\nor \"quit\" to exit the modding tree phase.\nType \"help\" again to reprint this list.\n----------\n" << endl;
}
