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
  if(this != NULL){
    return parent;
  }else{
    return NULL;
  }
}

void Node::setParent(Node* newParent){
  parent = newParent;
}

//Getters for grandparent
Node* Node::getGrandParent(){
  return this->getParent()->getParent();
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

void Node::reverseColor(){
  color = !color; 
}

//Left Rotate
void Node::rotateLeft(){
  //Remember the pivot's left subtree
  Node* leftSubtree = NULL;
  if(left!=NULL){
    leftSubtree = right->getLeft();
  }
  //To connect up the parent, first make sure that it's not the root
  if(parent != NULL){
    //If the root was the left subtree
    if(parent->getLeft() == this){
      //Set the parent's left to the pivot
      parent->setLeft(right);
      //If the root was the right subtree
    }else{
      //Set the parent's right to the pivot
      parent->setRight(right);
    }
    //Set the pivot's parent to the parent
    right->setParent(parent);
    //Set the root's parent to be the pivot (right)
    right->setLeft(this);
    parent = right;
    //Then finally, the pivot's left subtree becomes the old root's new right subtree
    right = leftSubtree;
  }else{
    //The root case
  }
}

//Right Rotate (WIP, change from left to right)
void Node::rotateRight(){
  //Remember the pivot's left subtree
  Node* leftSubtree = NULL;
  if(left!=NULL){
    leftSubtree = right->getLeft();
  }
  //To connect up the parent, first make sure that it's not the root
  if(parent != NULL){
    //If the root was the left subtree
    if(parent->getLeft() == this){
      //Set the parent's left to the pivot
      parent->setLeft(right);
      //If the root was the right subtree
    }else{
      //Set the parent's right to the pivot
      parent->setRight(right);
    }
    //Set the pivot's parent to the parent
    right->setParent(parent);
    //Set the root's parent to be the pivot (right)
    right->setLeft(this);
    parent = right;
    //Then finally, the pivot's left subtree becomes the old root's new right subtree
    right = leftSubtree;
  }else{
    //The root case
  }
}
