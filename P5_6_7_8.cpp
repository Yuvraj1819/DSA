#include <iostream>
using namespace std;

// Tree node structure
struct Tree {
    int data;
    Tree *left;
    Tree *right;
};

// BST class
class BST {
private:
    Tree *root; // Root of the BST

public:
    // Constructor
    BST() {
        root = nullptr;
    }

    // Insert a value into the BST
    void insert(int value) {
        Tree *newNode = new Tree;
        newNode->data = value;
        newNode->left = nullptr;
        newNode->right = nullptr;

        if (root == nullptr) {
            root = newNode;
        } else {
            Tree *node = root;
            Tree *parent = nullptr;

            while (node != nullptr) {
                parent = node;

                if (value > node->data) {
                    node = node->right;
                } else {
                    node = node->left;
                }
            }

            if (value > parent->data) {
                parent->right = newNode;
            } else {
                parent->left = newNode;
            }
        }
    }

    // Search for a value in the BST
    void search(int value) {
        if (root == nullptr) {
            cout << "\nThe tree is empty.";
            return;
        }

        Tree *node = root;
        while (node != nullptr) {
            if (node->data == value) {
                cout << value << " is found.\n";
                return;
            } else if (value < node->data) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
        cout << value << " is not found.\n";
    }

    // Recursive In-order traversal (Left, Root, Right)
    void inOrder(Tree *node) {
        if (node != nullptr) {
            inOrder(node->left);
            cout << node->data << " ";
            inOrder(node->right);
        }
    }

    // Recursive Pre-order traversal (Root, Left, Right)
    void preOrder(Tree *node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    // Recursive Post-order traversal (Left, Right, Root)
    void postOrder(Tree *node) {
        if (node != nullptr) {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->data << " ";
        }
    }

    // Compute depth of the BST
    int depth(Tree *node) {
        if (node == nullptr) {
            return 0;
        }

        int lh = depth(node->left);
        int rh = depth(node->right);

        return (max(lh, rh) + 1);
    }

    // Print all leaf nodes of the BST
    void printLeafNodes(Tree *node) {
        if (node == nullptr) {
            return;
        }

        if (node->left == nullptr && node->right == nullptr) {
            cout << node->data << " ";
        } else {
            if (node->left) {
                printLeafNodes(node->left);
            }
            if (node->right) {
                printLeafNodes(node->right);
            }
        }
    }

    // Delete a node from the BST
    Tree* deleteNode(Tree* node, int value) {
        if (!node) {
            return nullptr; // If the root is null, the tree is empty or we've reached a leaf
        }

        // Recursively find the node to delete
        if (value > node->data) {
            node->right = deleteNode(node->right, value);
            return node;
        } else if (value < node->data) {
            node->left = deleteNode(node->left, value);
            return node;
        } else {
            // Node to be deleted is found

            // Case 1: Node has no children (leaf node)
            if (!node->left && !node->right) {
                delete node;
                return nullptr;
            }
            // Case 2: Node has one child
            else if (!node->left) {
                Tree* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Tree* temp = node->left;
                delete node;
                return temp;
            }
            // Case 3: Node has two children
            else {
                Tree* parent = node;
                Tree* child = node->left;

                // Find the in-order successor (rightmost node of the left subtree)
                while (child->right) {
                    parent = child;
                    child = child->right;
                }

                // Replace root with the in-order successor
                if (parent != node) {
                    parent->right = child->left; // Detach the successor
                    child->left = node->left;
                    child->right = node->right;
                } else {
                    child->right = node->right;
                }

                delete node;
                return child;
            }
        }
    }

    // Public method to return root
    Tree* getRoot() {
        return root;
    }

    // Public method to update root
    void updateRoot(Tree* newRoot) {
        root = newRoot;
    }
};

// Main function
int main() {
    BST bst;
    int choice, value;

    do {
        cout << "\nMenu: ";
        cout << "\n1. Insert a value";
        cout << "\n2. Delete a value";
        cout << "\n3. Search for a value";
        cout << "\n4. Display In-order traversal";
        cout << "\n5. Display Pre-order traversal";
        cout << "\n6. Display Post-order traversal";
        cout << "\n7. Compute Depth of the BST";
        cout << "\n8. Display Leaf nodes";
        cout << "\n9. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                bst.insert(value);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                bst.updateRoot(bst.deleteNode(bst.getRoot(), value));
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                bst.search(value);
                break;

            case 4:
                cout << "In-order Traversal: ";
                bst.inOrder(bst.getRoot());
                cout << endl;
                break;

            case 5:
                cout << "Pre-order Traversal: ";
                bst.preOrder(bst.getRoot());
                cout << endl;
                break;

            case 6:
                cout << "Post-order Traversal: ";
                bst.postOrder(bst.getRoot());
                cout << endl;
                break;

            case 7:
                cout << "Depth of the BST: " << bst.depth(bst.getRoot()) << endl;
                break;

            case 8:
                cout << "Leaf Nodes: ";
                bst.printLeafNodes(bst.getRoot());
                cout << endl;
                break;

            case 9:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 9);

    return 0;
}
