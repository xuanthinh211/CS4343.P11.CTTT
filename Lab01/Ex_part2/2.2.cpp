// Full Name: NGUYEN XUAN THINH
// STUDENT ID: 20521967
// CLASS: CS4343.P11.CTTT

#include <iostream>
#include <unordered_map>

struct Node {
    int val;
    Node* next;
    Node* random;
    Node(int x) : val(x), next(nullptr), random(nullptr) {}
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Step 1: Create copy nodes and insert them next to the original nodes
        Node* curr = head;
        while (curr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        // Step 2: Set random pointers for the copied nodes
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Step 3: Separate the original list and the copied list
        Node* newHead = head->next;
        curr = head;
        while (curr) {
            Node* copy = curr->next;
            curr->next = copy->next; // restore next pointer for the original list
            if (copy->next) {
                copy->next = copy->next->next; // set next for the copied list
            }
            curr = curr->next;
        }

        return newHead;
    }
};

// Helper function to print the list
void printList(Node* head) {
    while (head) {
        std::cout << "Value: " << head->val;
        if (head->random) {
            std::cout << ", Random: " << head->random->val;
        } else {
            std::cout << ", Random: nullptr";
        }
        std::cout << std::endl;
        head = head->next;
    }
}

// Function to create the list from user input
Node* createList() {
    int n;
    std::cout << "Enter the number of nodes in the list: ";
    std::cin >> n;

    if (n <= 0) return nullptr;

    std::cout << "Enter values for each node:\n";
    Node* head = nullptr;
    Node* tail = nullptr;
    std::unordered_map<int, Node*> nodeMap;

    for (int i = 0; i < n; ++i) {
        int value;
        std::cin >> value;
        Node* newNode = new Node(value);
        nodeMap[i] = newNode; // store the node in the map

        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Set random pointers
    for (int i = 0; i < n; ++i) {
        int randomIndex;
        std::cout << "Enter random index for node " << nodeMap[i]->val << " (or -1 if none): ";
        std::cin >> randomIndex;
        if (randomIndex >= 0 && randomIndex < n) {
            nodeMap[i]->random = nodeMap[randomIndex];
        } else {
            nodeMap[i]->random = nullptr;
        }
    }

    return head;
}

// Example usage
int main() {
    Node* head = createList();
    
    Solution solution;
    Node* copiedList = solution.copyRandomList(head);
    
    std::cout << "Original List:" << std::endl;
    printList(head);
    
    std::cout << "Copied List:" << std::endl;
    printList(copiedList);

    return 0;
}
