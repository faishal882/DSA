#include <iostream>
#include "linked_list.c++"

Node *middleNode(Node *&head)
{
 if (head == NULL || head->next == NULL)
 {
  return head;
 }
 Node *fast = head->next;
 Node *slow = head;
 while (fast != NULL)
 {
  fast = fast->next;
  if(fast != NULL) {
   fast = fast->next;
  }
  slow = slow->next;
 }
 return slow;
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
 // InsertAtTail(tail, 27);

 Node *output = middleNode(head);
 print(head);
 cout << output->data << endl;
 return 0;
}