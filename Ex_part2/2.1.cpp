// Full Name: NGUYEN XUAN THINH
// STUDENT ID: 20521967
// CLASS: CS4343.P11.CTTT

#include <iostream>

struct Node {
    int data;
    Node* next;
};

// Function to append a new node to the linked list
void append(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to insert a new node before or after a node with a specific key
void insertAfterKey(Node*& head, int key, int value, bool insertAfter) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == key) {
            Node* newNode = new Node();
            newNode->data = value;

            if (insertAfter) {
                newNode->next = temp->next;
                temp->next = newNode;
            } else {
                newNode->next = temp;
                if (temp == head) {
                    head = newNode; // Update head if inserting before the head
                } else {
                    Node* prev = head;
                    while (prev->next != temp) {
                        prev = prev->next;
                    }
                    prev->next = newNode;
                }
            }
            return;
        }
        temp = temp->next;
    }
    std::cout << "Key not found in the list!" << std::endl;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Function to free the memory of the linked list
void freeList(Node* head) {
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;
    int n, value;

    std::cout << "Enter the number of elements in the list: ";
    std::cin >> n;

    std::cout << "Enter the values: " << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> value;
        append(head, value);
    }

    std::cout << "Current linked list: ";
    printList(head);

    // Input key to add numbers
    int key, newValue1, newValue2;
    bool insertAfter;

    std::cout << "Enter the key to add numbers: ";
    std::cin >> key;

    std::cout << "Enter the first number to add to the list: ";
    std::cin >> newValue1;

    std::cout << "Insert after key? (1: yes, 0: no): ";
    std::cin >> insertAfter;

    insertAfterKey(head, key, newValue1, insertAfter);

    std::cout << "Enter the second number to add to the list: ";
    std::cin >> newValue2;

    std::cout << "Insert after key? (1: yes, 0: no): ";
    std::cin >> insertAfter;

    insertAfterKey(head, key, newValue2, insertAfter);

    std::cout << "Linked list after adding 2 numbers: ";
    printList(head);

    // Free the memory
    freeList(head);
    return 0;
}
