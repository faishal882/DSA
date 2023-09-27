#include <iostream>
using namespace std;

class Node
{
public:
 int data;
 Node *next;

 Node(int data)
 {
  this->data = data;
  this->next = NULL;
 }

 // destructor
 ~Node()
 {
  int value = this->data;
  if (this->next != NULL)
  {
   delete next;
   this->next = NULL;
  }
  cout << " Memory is free with data " << value << endl;
 }
};

void InsertAtTail(Node *&tail, int d)
{
 Node *temp = new Node(d);
 tail->next = temp;
 tail = tail->next;
}

void insertAtHead(Node *&head, int d)
{
 Node *temp = new Node(d);
 temp->next = head;
 head = temp;
}

void insertAtPosition(Node *&head, Node *&tail, int position, int d)
{

 if (position == 1)
 {
  insertAtHead(head, d);
  return;
 }
 Node *temp = head;
 int count = 1;

 while (count < position - 1)
 {
  temp = temp->next;
  count++;
 }

 // insert at last position
 if (temp->next == NULL)
 {
  InsertAtTail(tail, d);
  return;
 }

 // creating a node for insertion
 Node *nodeToInsert = new Node(d);
 nodeToInsert->next = temp->next;
 temp->next = nodeToInsert;
}

void deleteAtPosition(Node *&head, int position)
{
 // deleting first or start node
 if (position == 1)
 {
  Node *temp = head;
  head = head->next;
  // free memory
  temp->next = NULL;
  delete temp;
 }
 else
 {
  // deleting any midddle or last node
  Node *curr = head;
  Node *prev = NULL;

  int cnt = 1;
  while (cnt < position)
  {
   prev = curr;
   curr = curr->next;
   cnt++;
  }

  prev->next = curr->next;
  curr->next = NULL;
  delete curr;
 }
}

void print(Node *&head)
{
 Node *temp = head;

 while (temp != NULL)
 {
  cout << temp->data << " ";
  temp = temp->next;
 }
 cout << endl;
}

// int main()
// {
//  Node *node1 = new Node(10);
//  cout << node1->data << endl;
//  cout << node1->next << endl;

//  // head pointed to meet
//  Node *head = node1;
//  Node *tail = node1;
//  // insertAtHead(head, 12);
//  // insertAtHead(head, 15);
//  InsertAtTail(tail, 17);
//  InsertAtTail(tail, 20);
//  insertAtPosition(head, tail, 4, 19);
//  print(head);

//  cout << "head " << head->data << endl;
//  cout << "tail " << tail->data << endl;

//  deleteAtPosition(head, 3);
//  print(head);

//  cout << "head " << head->data << endl;
//  cout << "tail " << tail->data << endl;

//  return 0;
// }