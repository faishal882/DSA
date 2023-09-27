#include <iostream>
#include "linked_list.c++"

Node *reverseLinkedList(Node *head)
{

 if (head == NULL || head->next == NULL)
 {
  return head;
 }
 Node *prev = NULL;
 Node *curr = head;
 Node *next = NULL;

 while (curr != NULL)
 {
  next = curr->next;
  curr->next = prev;
  prev = curr;
  curr = next;
 }

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
 print(head);
 Node *reverse = reverseLinkedList(head);
 // Node *reverse = reverseLinkedList(head);
 print(reverse);

 return 0;
}