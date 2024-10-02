// Full Name: NGUYEN XUAN THINH
// STUDENT ID: 20521967
// CLASS: CS4343.P11.CTTT

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    // Create a dummy node to simplify the merging process
    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // If there are remaining elements in l1 or l2, append them
    if (l1 != nullptr) {
        tail->next = l1;
    } else {
        tail->next = l2;
    }

    return dummy.next;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

ListNode* createList() {
    int n;
    std::cout << "Enter the number of elements in the list: ";
    std::cin >> n;

    if (n <= 0) return nullptr;

    std::cout << "Enter the sorted elements of the list: ";
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int i = 0; i < n; ++i) {
        int value;
        std::cin >> value;
        ListNode* newNode = new ListNode(value);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

int main() {
    std::cout << "Create the first sorted linked list:\n";
    ListNode* l1 = createList();

    std::cout << "Create the second sorted linked list:\n";
    ListNode* l2 = createList();

    ListNode* mergedList = mergeTwoLists(l1, l2);
    
    std::cout << "Merged sorted linked list: ";
    printList(mergedList);

    return 0;
}