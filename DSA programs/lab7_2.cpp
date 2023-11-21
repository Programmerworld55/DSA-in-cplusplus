#include <iostream>
using namespace std;

#define SIZE 5

int circularQueue[SIZE];
int front = -1;
int rear = -1;

bool isFull() {
    return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
}

bool isEmpty() {
    return front == -1;
}

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue is full. Cannot enqueue." << "\n\n";
        return;
    }

    if (front == -1) {
        front = 0;
        rear = 0;
    } else if (rear == SIZE - 1) {
        rear = 0;
    } else {
        rear++;
    }

    circularQueue[rear] = value;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty. Cannot dequeue.\n" << endl;
        return;
    }

    cout << "Dequeued element: " << circularQueue[front] <<"\n\n";

    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (front == SIZE - 1) {
        front = 0;
    } else {
        front++;
    }
}

void displayFront() {
    if (isEmpty()) {
        cout << "Queue is empty.\n" << endl;
    } else {
        cout << "Front element: " << circularQueue[front] << endl;
    }
}

void displayQueue() {
    if (isEmpty()) {
        cout << "Queue is empty.\n" << endl;
        return;
    }

    cout << "Circular Queue: ";
    if (rear >= front) {
        for (int i = front; i <= rear; i++) {
            cout << circularQueue[i] << " ";
        }
    } else {
        for (int i = front; i < SIZE; i++) {
            cout << circularQueue[i] << " ";
        }
        for (int i = 0; i <= rear; i++) {
            cout << circularQueue[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    int ch, val;
    do {
        cout << "1) Enqueue" << endl;
        cout << "2) Dequeue" << endl;
        cout << "3) Display Queue" << endl;
        cout << "4) Display Front Element" << endl;
        cout << "5) Exit" << endl;
        cout<<"\n\n";
        cout << "Enter choice: ";
        cin >> ch;
       

        switch (ch) {
            case 1: {
                cout << "Enter value to be enqueued: ";
                cin >> val;
                enqueue(val);
                break;
            }
            case 2: {
                dequeue();
                break;
            }
            case 3: {
                displayQueue();
                break;
            }
            case 4: {
                displayFront();
                break;
            }
            case 5: {
                cout << "Exit" << endl;
                break;
            }
            default: {
                cout << "Invalid Choice" << endl;
            }
        }
    } while (ch != 5);

    return 0;
}
