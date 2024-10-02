// Full Name: NGUYEN XUAN THINH
// STUDENT ID: 20521967
// CLASS: CS4343.P11.CTTT

#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void printList() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void removeNodeAtPosition(int position) {
        if (head == nullptr) return; // List is empty

        Node* temp = head;

        // If head needs to be removed
        if (position == 0) {
            head = temp->next; // Change head
            delete temp; // Free old head
            return;
        }

        // Find previous node of the node to be deleted
        for (int i = 0; temp != nullptr && i < position - 1; i++) {
            temp = temp->next;
        }

        // If position is more than the number of nodes
        if (temp == nullptr || temp->next == nullptr) return;

        // Node temp->next is the node to be deleted
        Node* next = temp->next->next;

        delete temp->next; // Free memory
        temp->next = next; // Unlink the deleted node from the list
    }
};

int main() {
    LinkedList list;
    int n, value;

    std::cout << "Enter the number of nodes: ";
    std::cin >> n;

    std::cout << "Enter the values of the nodes: ";
    for (int i = 0; i < n; i++) {
        std::cin >> value;
        list.insert(value);
    }

    std::cout << "Current list: ";
    list.printList();

    int position;
    std::cout << "Enter the position of the node to remove (0-based index): ";
    std::cin >> position;

    list.removeNodeAtPosition(position);

    std::cout << "List after removal: ";
    list.printList();

    return 0;
}
