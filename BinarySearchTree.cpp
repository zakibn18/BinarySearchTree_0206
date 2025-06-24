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
    leftchild = nullptr;  // Initialize left child to null
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

    // Step 6: If the value in the data field of new node os less than that of parent
    if (x < parent->info)
    {
      // 6a: Make the left child of the parent point to the new node
      parent->leftchild = newNode;

      // 6b: exit
      return;
    }
    // Step 7: of the va;ue in the data field of the new node is greater than that of the parent
    else if (x > parent->info)
    {
      // 7a: Make the right child of parent point to the new node
      parent->rightchild = newNode;

      // 7b: exit
      return;
    }
  }

  void search(int element, Node *&parent, Node *&currentNode)
  {
    // This fungtion searches the currentNode of the specified Node as well as the current Node is parent
    currentNode = ROOT;
    parent = nullptr;
    while ((currentNode != nullptr) && (currentNode->info != element))
    {
      parent = currentNode;
      if (element < currentNode->info)
        currentNode = currentNode->leftchild;
      else
        currentNode = currentNode->rightchild;
    }
  }

  void inorder(Node *ptr)
  {
    if (isEmpty())
    {
      cout << "Tree is Empty" << endl;
      return;
    }
    if (ptr == nullptr)
      return;

    inorder(ptr->leftchild);
    cout << ptr->info;
    inorder(ptr->rightchild);
  }

  void preorder(Node *ptr)
  {
    if (isEmpty())
    {
      cout << "Tree is Empty" << endl;
      return;
    }
    if (ptr == nullptr)
      return;

    cout << ptr->info;
    preorder(ptr->leftchild);
    preorder(ptr->rightchild);
  }

  void postorder(Node *ptr)
  {
    if (isEmpty())
    {
      cout << "Tree is Empty" << endl;
      return;
    }
    if (ptr == nullptr)
      return;

    postorder(ptr->leftchild);
    postorder(ptr->rightchild);
    cout << ptr->info;
  }

  bool isEmpty()
  {
    // Checks if the tree is empty
    return ROOT == nullptr;
  }
};

int main()
{
  BinaryTree x;
  while (true)
  {
    cout << "\nMenu" << endl;
    cout << "1. Implement insert operation" << endl;
    cout << "2. Perform inorder traversal" << endl;
    cout << "3. Perform preorder traversal" << endl;
    cout << "4. Perform postorder traversal" << endl;
    cout << "5. Exit" << endl;
    cout << "\nEnter your choice (1-5) : ";

    char ch;
    cin >> ch;
    cout << endl;

    switch (ch)
    {
    case '1':
    {
      x.insert();
      break;
    }
    case '2':
    {
      x.inorder(x.ROOT);
      break;
    }
    case '3':
    {

      x.preorder(x.ROOT);
      break;
    }
    case '4':
    {

      x.postorder(x.ROOT);
      break;
    }
    case '5':
      return 0;
    default:
    {
      cout << "Invalid option" << endl;
      break;
    }
    }
  }
}