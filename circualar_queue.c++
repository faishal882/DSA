#include <iostream>
using namespace std;

class CircularQueue {
private:
  int *arr;
  int front;
  int rear;
  int size;

public:
  CircularQueue(int n) {
    size = n;
    arr = new int[size];
    front = -1;
    rear = -1;
  }

  void enqueue(int data) {
    if ((front == 0 && rear == size - 1) ||
        (rear == (front - 1) % (size - 1))) {
      cout << "Queue is full" << endl;
    } else if (front == -1) { // first element to push
      front = rear = 0;
      arr[rear] = data;
    } else if (rear == size - 1 && front != 0) {
      rear = 0;
      arr[rear] = data;
    } else {
      rear++;
      arr[rear] = data;
    }
  }

  int dequeue() {
    if (front == -1) {
      cout << "Queue is Empty" << endl;
      return -1;
    }
    int ans = arr[front];
    arr[front] = -1;
    if (front == rear) {
      front = rear = -1;
    } else if (front == size - 1) {
      front = 0;
    } else {
      front++;
    }

    return ans;
  }
};

int main() {
  CircularQueue s(5);
  s.enqueue(1);
  s.enqueue(2);
  s.enqueue(3);
  s.dequeue();
  s.enqueue(5);

  cout << s.dequeue() << endl;

  return 0;
}
