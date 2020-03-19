#include <iostream>
#include "Node.h"

//Constructor
Node::Node(int newValue){
  value = newValue;

  left = NULL;
  right = NULL;
  parent = NULL;
  color = false;
}

//Destructor
Node::~Node(){
  //Nothing to do here apparently
}

//Getters and setters for value
//need to test if passing by value works
int Node::getValue(){
  return value;
}

void Node::setValue(int newValue){
  value = newValue;
}

//Getters and setters for left node
Node* Node::getLeft(){
  return left;
}

void Node::setLeft(Node* newLeft){
  left = newLeft;
}

//Getters and setters for right node
Node* Node::getRight(){
  return right;
}

void Node::setRight(Node* newRight){
  right = newRight;
}


//Getters and setters for parent node
Node* Node::getParent(){
  return parent;
}

void Node::setParent(Node* newParent){
  parent = newParent;
}

//Getters and setters for 
bool Node::getColor(){
  return color;
}

void Node::setColor(bool newColor){
  color = newColor;
}
