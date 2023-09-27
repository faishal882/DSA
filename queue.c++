#include <iostream>
using namespace std;

class Queue {
private:
  int *arr;
  int front;
  int rear;
  int size;

public:
  Queue(int n) {
    size = n;
    arr = new int[size];
    front = 0;
    rear = 0;
  }

  bool isEmpty() {
    if (front == rear)
      return true;
    else
      return false;
  }

  void enqueue(int data) {
    if (rear == size - 1) {
      cout << "Queue is full" << endl;
    } else {
      arr[rear] = data;
      rear++;
    }
  }

  int dequeue() {
    if (front == rear) {
      cout << "Queue is Empty" << endl;
      return -1;
    } else {
      int ans = arr[front];
      arr[front] = -1;
      front++;
      if (front == rear) {
        front = 0;
        rear = 0;
      }
      return ans;
    }
  }
};

int main() {
  Queue s(5);
  s.enqueue(1);
  s.enqueue(2);
  s.enqueue(3);
  s.dequeue();
  s.enqueue(5);

  cout << s.dequeue() << endl;

  return 0;
}
