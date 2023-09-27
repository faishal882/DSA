#include <iostream>
// #include "linked_list.c++"
#include "circular_ll.c++"
using namespace std;

Node* floydDetectLoop(Node *head)
{
 // empty list
 if (head == NULL)
 {
  return NULL;
 }

 Node *slow = head;
 Node *fast = head;
 while(slow != NULL && fast != NULL) {
    fast = fast->next;
    if(fast->next != NULL) {
        fast = fast->next;
    }
    slow = slow->next;

    if(slow==fast) {
        cout <<"present at" <<slow->data <<endl;
        return slow;
    }
 }

 return NULL;
}

Node *getStartingNode(Node* head) {
    if(head==NULL) {
        return NULL;
    }

    Node* intersection = floydDetectLoop(head);
    Node *slow = head;

    while(slow != intersection) {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

void removeLoopNode(Node* head) {
    if(head==NULL) {
        return;
    }

    Node *startOfLoop = getStartingNode(head);
    Node *temp = startOfLoop;
    while(temp->next != startOfLoop) {
        temp = temp->next;
    }

    temp->next = NULL;
}

int main()
{
 Node *tail = NULL;

  insertNode(tail, 5, 3);
  insertNode(tail, 3, 5);
  insertNode(tail, 5, 7);
  insertNode(tail, 7, 9);
  insertNode(tail, 5, 6);  
  insertNode(tail, 9, 10);
  insertNode(tail, 3, 4);
  removeLoopNode(tail);

 return 0;
}