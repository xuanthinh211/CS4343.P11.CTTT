// Full Name: NGUYEN XUAN THINH
// STUDENT ID: 20521967
// CLASS: CS4343.P11.CTTT

#include <iostream>
#include <stack>

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

    // Function to check if the linked list is a palindrome
    bool isPalindrome() {
        std::stack<int> stack;
        Node* current = head;

        // Push all elements onto the stack
        while (current) {
            stack.push(current->data);
            current = current->next;
        }

        current = head;

        // Check if the elements in the stack match the linked list
        while (current) {
            if (current->data != stack.top()) {
                return false; // Not a palindrome
            }
            stack.pop(); // Remove the top element from the stack
            current = current->next; // Move to the next node
        }
        return true; // Is a palindrome
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

    if (list.isPalindrome()) {
        std::cout << "The linked list is a palindrome." << std::endl;
    } else {
        std::cout << "The linked list is not a palindrome." << std::endl;
    }

    return 0;
}
