#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};


class Queue {
private:
    Node* front;
    Node* rear;
public:
    
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    
    bool isEmpty() {
        return (front == nullptr);
    }

    
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        if (isEmpty()) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Element " << value << " added to the queue.\n";
    }

    
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return -1;
        }
        int value = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;
        cout << "Element " << value << " dequeued from the queue.\n";
        return value;
    }

    
    bool search(int value) {
        Node* current = front;
        while (current != nullptr) {
            if (current->data == value) {
                cout << "Value " << value << " found in the queue.\n";
                return true;
            }
            current = current->next;
        }
        cout << "Value " << value << " not found in the queue.\n";
        return false;
    }

    
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue: ";
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    
    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
        cout << "Queue cleared.\n";
    }
};


int main() {
    Queue queue;

    
    queue.enqueue(12);
    queue.enqueue(50);
    queue.enqueue(60);

    
    queue.display();

    
    queue.search(12);
    queue.search(40);

    
    queue.dequeue();
    queue.display();

    
    queue.clear();
    queue.display();

    return 0;
}
