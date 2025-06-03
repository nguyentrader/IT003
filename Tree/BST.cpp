//                         
//
//       69696969                         69696969
//    6969    696969                   696969    6969
//  969    69  6969696               6969  6969     696
// 969        696969696             696969696969     696
//969        69696969696           6969696969696      696
//696      9696969696969           969696969696       969
// 696     696969696969             969696969        969
//  696     696  96969      _=_      9696969  69    696
//    9696    969696      q(-_-)p      696969    6969
//       96969696         '_) (_`         69696969
//          96            /__/  \            69
//          69          _(<_   / )_          96
//         6969        (__\_\_|_/__)        9696
//
//         Buddha shines, no bugs alive
//         God Bless        Never Crash

#include <bits/stdc++.h>
using namespace std;

struct treeNode {
    int data;
    treeNode* left;
    treeNode* right;
};

treeNode* createNode(int value) {
    treeNode* newNode = new treeNode;
    if (newNode == nullptr) {
        cerr << "Memory allocation failed!" << endl;
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void insert(treeNode*& root, int value) {
    if (root == nullptr) {
        root = createNode(value);
    } else if (value < root->data) {
        insert(root->left, value);
    } else {
        insert(root->right, value);
    }
}

// Function to search for a value in the BST
bool search(treeNode* root, int value) {
    if (root == nullptr) {
        return false; // Value not found
    }
    if (root->data == value) {
        return true; // Value found
    } else if (value < root->data) {
        return search(root->left, value); // Search in the left subtree
    } else {
        return search(root->right, value); // Search in the right subtree
    }
}

// Traversal Left, Root, Right (Inorder)
void inorderTraversal(treeNode* root) {
    if (root != nullptr) {
        inorderTraversal(root->left); // Visit left subtree
        cout << root->data << " "; // Visit root
        inorderTraversal(root->right); // Visit right subtree
    }
}

// Traversal Root, Left, Right (Preorder)
void preorderTraversal(treeNode* root) {
    if (root != nullptr) {
        cout << root->data << " "; // Visit root
        preorderTraversal(root->left); // Visit left subtree
        preorderTraversal(root->right); // Visit right subtree
    }
}

// Traversal Left, Right, Root (Postorder)
void postorderTraversal(treeNode* root) {
    if (root != nullptr) {
        postorderTraversal(root->left); // Visit left subtree
        postorderTraversal(root->right); // Visit right subtree
        cout << root->data << " "; // Visit root
    }
}

// Function to find the minimum value in the BST
int findMin(treeNode* root) {
    if (root == nullptr) {
        cerr << "Tree is empty." << endl;
        return -1; // Meaningful value indicating empty tree
    }
    while (root->left != nullptr) {
        root = root->left;
    }
    return root->data;
}

// Function to find the maximum value in the BST
int findMax(treeNode* root) {
    if (root == nullptr) {
        cerr << "Tree is empty." << endl;
        return -1; // Meaningful value indicating empty tree
    }
    while (root->right != nullptr) {
        root = root->right;
    }
    return root->data;
}

// Function to delete a node from the BST
treeNode* deleteNode(treeNode* root, int value) {
    if (root == nullptr) {
        return root; // Value not found
    }
    if (value < root->data) {
        root->left = deleteNode(root->left, value); // Search in left subtree
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value); // Search in right subtree
    } else {
        // Node with one child or no child
        if (root->left == nullptr) {
            treeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            treeNode* temp = root->left;
            delete root;
            return temp;
        }
        // Node with two children: Get the inorder successor (smallest in the right subtree)
        treeNode* temp = createNode(findMin(root->right));
        root->data = temp->data; // Copy the inorder successor's content to this node
        root->right = deleteNode(root->right, temp->data); // Delete the inorder successor
    }
    return root;
}

// Function to find parent of a node with a given value
treeNode* findParent(treeNode* root, int value) {
    if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
        return nullptr; // No parent found
    }
    if ((root->left != nullptr && root->left->data == value) || 
        (root->right != nullptr && root->right->data == value)) {
        return root; // Parent found
    }
    if (value < root->data) {
        return findParent(root->left, value); // Search in left subtree
    } else {
        return findParent(root->right, value); // Search in right subtree
    }
}

// Fuction to find the height of the BST
int findHeight(treeNode* root) {
    if (root == nullptr) {
        return -1; // Height of an empty tree is -1
    }
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return max(leftHeight, rightHeight) + 1; // Height of the tree
}

void clearTree(treeNode*& root) {
    if (root != nullptr) {
        clearTree(root->left);
        clearTree(root->right);
        delete root;
        root = nullptr;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //my code
    return 0;
}

//          _.-/`)
//         // / / )
//      .=// / / / )
//     //`/ / / / /
//     // /     ` /
//   ||         /
//    \       /
//     ))    .'
//         //    /
//         /
