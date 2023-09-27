#include <iostream>
// #include "linked_list.c++"
#include "circular_ll.c++"
using namespace std;

bool isCircularLList(Node *head)
{
 // empty list
 if (head == NULL)
 {
  return true;
 }

 Node *temp = head->next;
 while (temp != NULL && temp != head)
 {
  temp = temp->next;
 }

 if (temp == head)
 {
  return true;
 }

 return false;
}
int main()
{
 Node *tail = NULL;

 insertNode(tail, 5, 3);
 insertNode(tail, 3, 5);


 if (isCircularLList(tail))
 {
  cout << " Linked List is Circular in nature" << endl;
 }
 else
 {
  cout << "Linked List is not Circular " << endl;
 }

 return 0;
}