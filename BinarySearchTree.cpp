#include <iostream>
using namespace std;

class Node
{
public:
  int info;
  Node *leftchild;
  Node *rightchild;

  // Construktor for the Node class
  Node()
  {
    leftchild = nullptr; // Initialize left child to null
    rightchild = nullptr; // Initialize right child to null
  }
};

class BinaryTree
{
public:
  Node *ROOT;

  BinaryTree()
  {
    ROOT = nullptr; // Initializing ROOT to null
  }

  void insert()
  {
    int x;
    cout << "Masukkan nilai: ";
    cin >> x;

    // Step 1: Allocated memory for the new node
    Node *newNode = new Node();

    // Step 2: Assingn value to the data field of new node
    newNode->info = x;

    // Step 3: Make the left and right child of the new node point to NULL
    newNode->leftchild = nullptr;
    newNode->rightchild = nullptr;

    // Step 4: Locate the node which will be the parent of the node tobe inserted
    Node *parent = nullptr;
    Node *currentNode = nullptr;
    search(x, parent, currentNode);

    // Step 5: if parent is NULL (Tree is empty)
    if (parent == nullptr)
    {
      // 5a: Mark the new node as ROOT
      ROOT = newNode;

      // 5b: exit
      return;
    }
  }
};

int main()
{

}