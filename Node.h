#ifndef NODE_H
#define NODE_H
class Node {
 public:
  //Constructor and destructor
  Node(int);
  ~Node();
  //Getters and setters
  int getValue();
  void setValue(int);
  Node* getLeft();
  void setLeft(Node*);
  Node* getRight();
  void setRight(Node*);
  Node* getParent();
  void setParent(Node*);
  //Not sure if we need getters and setters for the grandparent and uncle
  Node* getGrandParent();
  Node* getUncle();
  bool getColor();
  void setColor(bool);
 private:
  //Value
  int value;
  //Left and Right Node
  Node* left;
  Node* right;
  //Parent
  Node* parent;
  //Color, false = red, true = black
  bool color;
};
#endif
