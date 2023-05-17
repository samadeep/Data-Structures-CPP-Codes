#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};


// template <typename T>

class BST {
    private:
        Node* root;
        
        Node* insert(Node* node, int data) {
            if (node == nullptr) {
                node = new Node();
                node->data = data;
                node->left = nullptr;
                node->right = nullptr;
                return node;
            }
            if (data < node->data) {
                node->left = insert(node->left, data);
            }
            else if (data > node->data) {
                node->right = insert(node->right, data);
            }
            return node;
        }
        
        
        Node* findMin(Node* node) 
        {
            while (node->left != nullptr) 
            {
                node = node->left;
            }
            return node;
        }
        
        Node* remove(Node* node, int data) {
            
            if (node == nullptr) {
                return node;
            }
            
            if (data < node->data) {
                node->left = remove(node->left, data);
            }
            
            else if (data > node->data) {
                node->right = remove(node->right, data);
            }
            
            else {
                if (node->left == nullptr) {
                    Node* temp = node->right;
                    delete node;
                    return temp;
                }
                else if (node->right == nullptr) {
                    Node* temp = node->left;
                    delete node;
                    return temp;
                }
                else {
                    Node* temp = findMin(node->right);
                    node->data = temp->data;
                    node->right = remove(node->right, temp->data);
                }
            }
            return node;
        }
        
        void inorderTraversal(Node* node) 
        {
            if (node == nullptr) {
                return;
            }
            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
        }
        
    public:
        BST() {
            root = nullptr;
        }
        void insert(int data) {
            root = insert(root, data);
        }
        void remove(int data) {
            root = remove(root, data);
        }
        void printInorder() {
            inorderTraversal(root);
        }
};

int main() {
    BST bst;

    cout<<"Enter the Number of Nodes"<<endl;
    int n; cin>>n;

    int node;

    while(n--)
    {
        cin>>node;
        bst.insert(node);
    }

    int removeNode;
    cout<<"Enter the node to be removed"<<endl;
    cin>>removeNode;


    cout << "Inorder traversal of the BST before removal; "<<endl;
    bst.printInorder();
    cout<<endl;

    bst.remove(removeNode);

    cout << "Inorder traversal after the removal:"<<endl;
    bst.printInorder();
    cout<<endl;

    return 0;
}
