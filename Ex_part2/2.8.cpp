// Full Name: NGUYEN XUAN THINH
// STUDENT ID: 20521967
// CLASS: CS4343.P11.CTTT

#include <iostream>
#include <cstdlib>
#include <ctime>

struct Node {
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        Node* current = head;
        Node* nextNode = nullptr;
        while (current) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void append(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void printList() const {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    std::srand(std::time(0)); // Seed for random number generation

    LinkedList list;
    int numEntries = std::rand() % 21 + 39; // Randomly choose between 39 and 59

    for (int i = 0; i < numEntries; ++i) {
        int value = std::rand() % 199 - 99; // Random value between -99 and 99
        list.append(value);
    }

    std::cout << "Random Linked List: ";
    list.printList();

    return 0;
}
