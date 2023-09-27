#include <iostream>
#include "linked_list.c++"

Node *midNode(Node *head)
{
    if (head == NULL || head->next == NULL)
    { 
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

Node *merge(Node *left, Node *right)
{
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;

    Node *ans = new Node(-1);
    Node *temp = ans;

    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while (left != NULL)
    {
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while (right != NULL)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }

    ans = ans->next;
    return ans;
}

Node *mergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *mid = midNode(head);

    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    // merge
    Node *result = merge(left, right);

    return result;
}

int main()
{
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;
    InsertAtTail(tail, 5);
    InsertAtTail(tail, 7);
    InsertAtTail(tail, 2);
    InsertAtTail(tail, 9);
    InsertAtTail(tail, 8);
    print(head);

    Node *sort = mergeSort(head);
    print(sort);

    return 0;
}