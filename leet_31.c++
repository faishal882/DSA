#include <iostream>
#include "linked_list.c++"

Node *reverseInKGroup(Node *&head, int k)
{
 if (head == NULL)
 {
  return NULL;
 }

 // reverse first k nodes
 Node *next = NULL;
 Node *curr = head;
 Node *prev = NULL;
 int count = 0;

 while (curr != NULL && count < k)
 {
  next = curr->next;
  curr->next = prev;
  prev = curr;
  curr = next;
  count++;
 }

 // recursion
 if (next != NULL)
 {
  head->next = reverseInKGroup(next, k);
 }

 // return
 return prev;
}

int main()
{
 Node *node1 = new Node(10);
 Node *head = node1;
 Node *tail = node1;

 InsertAtTail(tail, 17);
 InsertAtTail(tail, 20);
 InsertAtTail(tail, 24);
 InsertAtTail(tail, 25);
 InsertAtTail(tail, 26);
 InsertAtTail(tail, 27);
 print(head);
 Node *output = reverseInKGroup(head, 3);
 print(output);
 return 0;
}