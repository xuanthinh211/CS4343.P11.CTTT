// Full Name: NGUYEN XUAN THINH
// STUDENT ID: 20521967
// CLASS: CS4343.P11.CTTT

#include <iostream>
#include <vector>

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

    // Function to search for nodes with value X and return their addresses
    std::vector<Node*> search(int x) {
        std::vector<Node*> addresses; // Vector to store addresses of found nodes
        Node* current = head;
        while (current) {
            if (current->data == x) {
                addresses.push_back(current); // Store the address of the node
            }
            current = current->next; // Move to the next node
        }
        return addresses; // Return vector of addresses
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

    std::cout << "Enter the number of elements in the linked list: ";
    std::cin >> n;

    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> value; // Read each element
        list.append(value); // Append it to the list
    }

    std::cout << "Linked list: ";
    list.display(); // Display the linked list

    int x;
    std::cout << "Enter the value to search for: ";
    std::cin >> x; // Read the value to search for

    std::vector<Node*> foundNodes = list.search(x); // Search for nodes with value x

    if (!foundNodes.empty()) {
        std::cout << "Found nodes with value " << x << " at addresses: ";
        for (Node* node : foundNodes) {
            std::cout << node << " "; // Print the addresses of found nodes
        }
        std::cout << std::endl;
    } else {
        std::cout << "Value " << x << " not found in the list." << std::endl;
    }

    return 0;
}
