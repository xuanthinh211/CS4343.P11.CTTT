// Full Name: NGUYEN XUAN THINH
// STUDENT ID: 20521967
// CLASS: CS4343.P11.CTTT

#include <iostream>

struct Node {
    int data;       // Data of the node
    Node* next;     // Pointer to the next node
    Node(int val) : data(val), next(nullptr) {} // Constructor
};

class LinkedList {
private:
    Node* head; // Head pointer of the linked list

public:
    LinkedList() : head(nullptr) {} // Constructor initializes head to nullptr

    // Function to append a new value to the list
    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode; // If list is empty, new node is the head
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next; // Traverse to the end of the list
        }
        temp->next = newNode; // Link the new node at the end
    }

    // Function to reverse the linked list
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current) {
            next = current->next;  // Store next node
            current->next = prev;  // Reverse the link
            prev = current;        // Move prev up
            current = next;        // Move current up
        }
        head = prev; // Update head to the new first node
    }

    // Function to display the linked list
    void display() const {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " "; // Print the data
            temp = temp->next; // Move to the next node
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList list;
    int n, value;

    std::cout << "\n Enter the number of elements in the list: ";
    std::cin >> n;

    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> value; // Read each element
        list.append(value); // Append it to the list
    }

    std::cout << "Original linked list: ";
    list.display(); // Display the original list

    list.reverse(); // Reverse the linked list

    std::cout << "Reversed linked list: ";
    list.display(); // Display the reversed list

    return 0;
}
