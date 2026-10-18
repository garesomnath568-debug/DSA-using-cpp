
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

Node* deleteOneChild(Node* root, int key)
{
    Node* parent = NULL;
    Node* current = root;

    // Search for the node
    while (current != NULL && current->data != key)
    {
        parent = current;

        if (key < current->data)
            current = current->left;
        else
            current = current->right;
    }

    // Key is absent
    if (current == NULL)
    {
        cout << "Node not found!\n";
        return root;
    }

    int children = 0;

    if (current->left != NULL)
        children++;

    if (current->right != NULL)
        children++;

    // Only nodes with exactly one child can be deleted
    if (children != 1)
    {
        cout << "Node does not have exactly one child.\n";
        return root;
    }

    Node* child;

    if (current->left != NULL)
        child = current->left;
    else
        child = current->right;

    cout << "Deleted Node: " << current->data << endl;
    cout << "Replacement Child: " << child->data << endl;

    if (parent == NULL)
    {
        // Deleting the root
        cout << "Parent: NULL (Root Node)\n";
        cout << "New Root: " << child->data << endl;

        root = child;
    }
    else
    {
        cout << "Parent: " << parent->data << endl;

        if (parent->left == current)
        {
            cout << "Link Changed: Parent's left -> Child\n";
            parent->left = child;
        }
        else
        {
            cout << "Link Changed: Parent's right -> Child\n";
            parent->right = child;
        }
    }

    delete current;
    cout << "Node deleted successfully.\n";

    return root;
}

int main()
{
    Node* root = NULL;
    int n, value, key;

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

    root = deleteOneChild(root, key);

    cout << "Updated BST (Inorder): ";
    inorder(root);
    cout << endl;

    return 0;
}
