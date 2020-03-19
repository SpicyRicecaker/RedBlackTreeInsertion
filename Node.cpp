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

//Getters for grandparent
Node* Node::getGrandParent(){
  //If parent isn't null
  if(parent != NULL){
    return parent->getParent();
  }
  return NULL;
}

//Getters for uncle
Node* Node::getUncle(){
  //If the grandparent isn't null
  if(this->getGrandParent() != NULL){
    //Return the opposite of what isn't the parent of parent
    if(this->getGrandParent()->getLeft() == this->getGrandParent()){
      return this->getGrandParent()->getRight();
    }else{
      return this->getGrandParent()->getLeft();
    }
  }
  return NULL;
}


//Getters and setters for color
bool Node::getColor(){
  return color;
}

void Node::setColor(bool newColor){
  color = newColor;
}
