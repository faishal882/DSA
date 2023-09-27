#include <iostream>
#include "linked_list.c++"

Node *midNode(Node *head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }

    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;

}

Node* reverse(Node *head) {
  Node* curr = head;
  Node* prev = NULL;
  Node* next = NULL;

  while (curr != NULL)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  return prev;
  
}

bool isPalindrome(Node *head) {

    if(head == NULL || head->next == NULL) {
        return true;
    }

    Node *middle = midNode(head);

    Node* temp = middle->next;
    middle->next = reverse(temp);

    Node* head1 = head;
    Node* head2 = middle->next;

    while(head2 != NULL) {
        if(head1->data != head2->data) return false;
        head1 = head1->next;
        head2 = head2->next;
    }

    temp = middle->next;
    middle->next = reverse(temp);

    return true;
}

int main()
{
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;
    InsertAtTail(tail, 2);
    InsertAtTail(tail, 2);
    InsertAtTail(tail, 1);
    print(head);
    bool x = isPalindrome(head);

    cout <<x <<endl;

    return 0;
}