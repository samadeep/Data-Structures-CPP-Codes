#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode 
{
	public:
      int val;
      TreeNode *left;
      TreeNode *right;
};
      

TreeNode* newNode(int x) 
{
	TreeNode* temp = new TreeNode;
	temp->val=x;
	temp->left=NULL;
	temp->right=NULL;
    return temp;
}

void preOrder(TreeNode* root)
{
		vector<int> preOrderTraversal;
        
        stack<TreeNode*> st;

        while (root || !st.empty()) 
        {
             if (root) {

                preOrderTraversal.push_back(root -> val);
                
                if (root -> right) 
                {
                    st.push(root -> right);
                }
                root = root -> left;
            } 

            else {
                root = st.top();
                st.pop();
            }
        }
        
        for(auto x:preOrderTraversal) cout<<x<<" "; cout<<endl;

        return;

}

//Using 1 Stack

void postOrder(TreeNode* root) {
        
        vector<int> post;

        stack<TreeNode*> todo;

        TreeNode* last = NULL;

        while (root || !todo.empty())
        {   
            if (root) 
            {
                todo.push(root);
                root = root -> left;
            }
            else 
            {
                TreeNode* node = todo.top();
                if (node -> right && last != node -> right) 
                {
                    root = node -> right;
                } 
                else {
                    post.push_back(node -> val);
                    last = node;
                    todo.pop();
                }
            }
        }

        cout<<'\n';

        for(auto x:post)
        {
        	 cout<<x<<" ";
        }

	}

TreeNode* build_tree() {
    string data;
    cin >> data;
    if (data == "None") {
        return NULL;
    }
    int value = stoi(data);
    TreeNode* node = newNode(value);
    node->left = build_tree();
    node->right = build_tree();
    return node;
}

int main() {
    TreeNode* root = build_tree();
    
    postOrder(root);
    // preOrder(root);
    
    return 0;
}



// Non Linear Data Structure -> benefits / why? Support Answer with Facts 

// Why did we move from Linear to Non-Linear Data Structure

// Can our tree be full at any point ?




