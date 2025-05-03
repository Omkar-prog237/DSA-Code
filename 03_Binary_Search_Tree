#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Insert function
void insert(Node*& root, Node* temp) {
    Node* current = nullptr;
    Node* parent = nullptr;

    if (root == nullptr) {
        root = temp;
    }
    else {
        current = root;
        while (current != nullptr) {
            parent = current;
            if (current->data > temp->data) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
        if (parent->data < temp->data) {
            parent->right = temp;
        }
        else {
            parent->left = temp;
        }
    }
}

// Inorder function (left, root, right)
void inorder(Node* temp) {
    if (temp != nullptr) {
        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }
}

// Preorder function (root, left, right)
void preorder(Node* temp) {
    if (temp != nullptr) {
        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }
}

// Postorder function (left, right, root)
void postorder(Node* temp) {
    if (temp != nullptr) {
        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data << " ";
    }
}

// Search function
Node* search(Node* root, int value) {
    while (root != nullptr) {
        if (root->data > value) {
            root = root->left;
        }
        else if (root->data < value) {
            root = root->right;
        }
        else {
            cout << "Element found: " << root->data << endl;
            return root;
        }
    }
    cout << "Element not found." << endl;
    return nullptr;
}

// Function to find the smallest node (leftmost node)
Node* smallest(Node* root) {
    while (root != nullptr && root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Function to find the longest path (height of the tree)
int longestpath(Node* root) {
    if (root == nullptr)
        return 0;
    int leftHeight = longestpath(root->left);
    int rightHeight = longestpath(root->right);
    return max(leftHeight, rightHeight) + 1;
}

// Function to swap the left and right children at every node
void swapChildren(Node* root) {
    if (root == nullptr) {
        return;
    }
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    swapChildren(root->left);
    swapChildren(root->right);
}

// Display the menu
void showMenu() {
    cout << "\nMenu:\n";
    cout << "1. Insert a node\n";
    cout << "2. Perform Inorder, Preorder, Postorder Traversal\n";
    cout << "3. Search for an element\n";
    cout << "4. Find the smallest element\n";
    cout << "5. Find the longest path\n";
    cout << "6. Swap left and right children at every node\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
}

// Driver's code
int main() {
    Node* root = nullptr;
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                int n;
                cout << "Enter number of nodes you want to enter: ";
                cin >> n;
                while (n--) {
                    int value;
                    cout << "Enter value of node: ";
                    cin >> value;
                    Node* t = new Node(value);
                    insert(root, t);
                }
                break;
            }
            case 2: {
                cout << "\nInorder traversal: ";
                inorder(root);
                cout << "\nPreorder traversal: ";
                preorder(root);
                cout << "\nPostorder traversal: ";
                postorder(root);
                cout << endl;
                break;
            }
            case 3: {
                int key;
                cout << "\nEnter element to be searched: ";
                cin >> key;
                search(root, key);
                break;
            }
            case 4: {
                Node* smallestNode = smallest(root);
                if (smallestNode) {
                    cout << "\nSmallest element: " << smallestNode->data << endl;
                }
                break;
            }
            case 5: {
                int longest = longestpath(root);
                cout << "\nLongest path: " << longest << endl;
                break;
            }
            case 6: {
                swapChildren(root);
                cout << "\nInorder traversal after swapping: ";
                inorder(root);
                cout << "\nPreorder traversal after swapping: ";
                preorder(root);
                cout << "\nPostorder traversal after swapping: ";
                postorder(root);
                cout << endl;
                break;
            }
            case 7:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
