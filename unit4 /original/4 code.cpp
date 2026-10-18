
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void inorder(Node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

Node* deleteOneChild(Node* root, int key, bool& deleted)
{
    if (root == NULL)
        return NULL;

    if (key < root->data)
        root->left = deleteOneChild(root->left, key, deleted);
    else if (key > root->data)
        root->right = deleteOneChild(root->right, key, deleted);
    else
    {
        int children = 0;

        if (root->left != NULL)
            children++;

        if (root->right != NULL)
            children++;

        if (children != 1)
        {
            cout << "Node does not have exactly one child.\n";
            return root;
        }

        Node* child;

        if (root->left != NULL)
            child = root->left;
        else
            child = root->right;

        delete root;
        deleted = true;
        return child;
    }

    return root;
}

int main()
{
    Node* root = NULL;
    int n, value, key;
    bool deleted = false;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter BST values: ";

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        root = insert(root, value);
    }

    cout << "Original BST (Inorder): ";
    inorder(root);

    cout << "\nEnter node to delete: ";
    cin >> key;

    root = deleteOneChild(root, key, deleted);

    if (deleted)
        cout << "Node deleted successfully.\n";

    if (!deleted)
        cout << "Node not deleted.\n";

    cout << "Updated BST (Inorder): ";
    inorder(root);
    cout << endl;

    return 0;
}
