// STT:02
// Full Name: NGUYEN XUAN THINH
// STUDENT ID: 20521967
// CLASS: CS4343.P11.CTTT

#include <iostream>
#include <unordered_set>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void insert(Node*& head, int val) {
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

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

Node* findIntersection(Node* head1, Node* head2) {
    std::unordered_set<int> elements;
    Node* intersectionHead = nullptr;

    // Add all elements from the first list to the set
    Node* temp = head1;
    while (temp) {
        elements.insert(temp->data);
        temp = temp->next;
    }

    // Check elements of the second list
    temp = head2;
    while (temp) {
        if (elements.find(temp->data) != elements.end()) {
            insert(intersectionHead, temp->data);
        }
        temp = temp->next;
    }

    return intersectionHead;
}

int main() {
    Node* list1 = nullptr;
    Node* list2 = nullptr;

    int n, val;

    // Input for the first list
    std::cout << "\n Enter the number of elements for the first list: ";
    std::cin >> n;
    std::cout << "Enter the elements of the first list: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> val;
        insert(list1, val);
    }

    // Input for the second list
    std::cout << "Enter the number of elements for the second list: ";
    std::cin >> n;
    std::cout << "Enter the elements of the second list: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> val;
        insert(list2, val);
    }

    // Find intersection
    Node* intersection = findIntersection(list1, list2);

    // Output the result
    if (intersection) {
        std::cout << "Intersection of the two lists: ";
        printList(intersection);
    } else {
        std::cout << "Intersection of the two lists: null" << std::endl;
    }

    return 0;
}
