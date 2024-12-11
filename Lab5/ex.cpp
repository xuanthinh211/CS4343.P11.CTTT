#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    TreeNode* root;

    BinaryTree() : root(nullptr) {}

    // 1. Insert a value into the binary tree
    void insert(int val) {
        root = insertHelper(root, val);
    }

    // 2. Delete a value from the binary tree
    void remove(int val) {
        root = removeHelper(root, val);
    }

    // 3. Search for a value in the binary tree
    bool search(int val) {
        return searchHelper(root, val);
    }

    // 4. Traversals
    void preOrder(TreeNode* node) {
        if (!node) return;
        cout << node->val << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    void inOrder(TreeNode* node) {
        if (!node) return;
        inOrder(node->left);
        cout << node->val << " ";
        inOrder(node->right);
    }

    void postOrder(TreeNode* node) {
        if (!node) return;
        postOrder(node->left);
        postOrder(node->right);
        cout << node->val << " ";
    }

    void levelOrder() {
        if (!root) return;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            cout << current->val << " ";
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
    }

    // 5. Height of the binary tree
    int height(TreeNode* node) {
        if (!node) return 0;
        return 1 + max(height(node->left), height(node->right));
    }

    // 6. Check if the tree is height-balanced
    bool isBalanced(TreeNode* node) {
        if (!node) return true;
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return abs(leftHeight - rightHeight) <= 1 && isBalanced(node->left) && isBalanced(node->right);
    }

    // 7. Find the lowest common ancestor (LCA) in a BST
    TreeNode* lowestCommonAncestor(TreeNode* node, int p, int q) {
        if (!node) return nullptr;
        if (node->val > p && node->val > q)
            return lowestCommonAncestor(node->left, p, q);
        if (node->val < p && node->val < q)
            return lowestCommonAncestor(node->right, p, q);
        return node;
    }

    // 8. Level-order traversal with values grouped by level
    vector<vector<int>> levelOrderGrouped() {
        vector<vector<int>> result;
        if (!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                TreeNode* current = q.front();
                q.pop();
                level.push_back(current->val);
                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }
            result.push_back(level);
        }
        return result;
    }

    // 9. Maximum path sum
    int maxPathSum(TreeNode* node, int& maxSum) {
        if (!node) return 0;
        int left = max(0, maxPathSum(node->left, maxSum));
        int right = max(0, maxPathSum(node->right, maxSum));
        maxSum = max(maxSum, left + right + node->val);
        return max(left, right) + node->val;
    }

    int findMaxPathSum() {
        int maxSum = INT_MIN;
        maxPathSum(root, maxSum);
        return maxSum;
    }

    // Helper methods
private:
    TreeNode* insertHelper(TreeNode* node, int val) {
        if (!node) return new TreeNode(val);
        if (val < node->val) node->left = insertHelper(node->left, val);
        else node->right = insertHelper(node->right, val);
        return node;
    }

    TreeNode* removeHelper(TreeNode* node, int val) {
        if (!node) return nullptr;
        if (val < node->val) node->left = removeHelper(node->left, val);
        else if (val > node->val) node->right = removeHelper(node->right, val);
        else {
            if (!node->left) return node->right;
            if (!node->right) return node->left;
            TreeNode* minLargerNode = getMin(node->right);
            node->val = minLargerNode->val;
            node->right = removeHelper(node->right, minLargerNode->val);
        }
        return node;
    }

    TreeNode* getMin(TreeNode* node) {
        while (node->left) node = node->left;
        return node;
    }

    bool searchHelper(TreeNode* node, int val) {
        if (!node) return false;
        if (node->val == val) return true;
        if (val < node->val) return searchHelper(node->left, val);
        return searchHelper(node->right, val);
    }
};

// Main function for testing
int main() {
    BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);

    cout << "In-Order Traversal: ";
    tree.inOrder(tree.root);
    cout << endl;

    cout << "Height: " << tree.height(tree.root) << endl;
    cout << "Is Balanced: " << (tree.isBalanced(tree.root) ? "Yes" : "No") << endl;

    vector<vector<int>> levels = tree.levelOrderGrouped();
    cout << "Level-Order Grouped: \n";
    for (const auto& level : levels) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    cout << "Max Path Sum: " << tree.findMaxPathSum() << endl;

    return 0;
}