#include <bits/stdc++.h>

using namespace std;

class TreeNode {
    public:
    
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preorder(TreeNode *node) {
    if(node == NULL) return;
    
    cout << node->data << "    ";
    preorder(node->left);
    preorder(node->right);
}

void preorderIterative(TreeNode *root) {
    stack<TreeNode*> st;
    if(root) {
        st.push(root);
    }
    
    while(!st.empty()) {
        TreeNode *node = st.top();
        st.pop();
        cout << node->data << "    ";
        
        if(node->right) {
            st.push(node->right);
        }
        
        if(node->left) {
            st.push(node->left);
        }
    }
    cout << endl;
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    preorder(root);
    cout << endl;
    preorderIterative(root);

    return 0;
}
