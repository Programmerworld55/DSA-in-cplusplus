#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;

bool isEmpty() {
    return front == nullptr;
}

void enqueue(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (isEmpty()) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty. Cannot dequeue." << endl;
        return;
    }

    Node* temp = front;
    front = front->next;
    delete temp;
}

void showFront() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Element at front is: " << front->data << endl;
    }
}

void displayQueue() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "The queue is:" << endl;
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
}

int main() {
    int ch, val;
    cout << "1) Inserting in queue" << endl;
    cout << "2) Removing from queue" << endl;
    cout << "3) Display display" << endl;
    cout << "4) Show Front" << endl;
    cout << "5) Exit" << endl;
    
    do {
        cout << "Enter choice: ";
        cin >> ch;
        switch (ch) {
            case 1: {
                cout << "Enter value to be inserted in queue: ";
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
                showFront();
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

    // Clean up the remaining nodes in the queue
    while (!isEmpty()) {
        dequeue();
    }

    return 0;
}
