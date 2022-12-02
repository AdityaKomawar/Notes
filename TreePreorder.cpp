// Online C++ compiler to run C++ program online
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

void inorder(TreeNode *node) {
    if(node == NULL) return;
    
    inorder(node->left);
    cout << node->data << "    ";
    inorder(node->right);
}

void postorder(TreeNode *node) {
    if(node == NULL) return;
    
    postorder(node->left);
    postorder(node->right);
    cout << node->data << "    ";
}

void preorderIterative1(TreeNode *root) {
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

void preorderIterative2(TreeNode *node) {
    stack<TreeNode*> st;
    while(node != NULL || !st.empty()) {
        if(node != NULL) {
            cout << node->data << "    ";
            st.push(node);
            node = node->left;
        } else {
            node = st.top();
            st.pop();
            node = node->right;
        }
    }
    cout << endl;
}

void inorderIterative(TreeNode *node) {
    stack<TreeNode *> st;
    while(node != NULL || !st.empty()) {
        if(node != NULL) {
            st.push(node);
            node = node->left;
        } else {
            node = st.top();
            st.pop();
            cout << node->data << "    ";
            node = node->right;
        }
    }
}

void postorderIterative(TreeNode *node) {
    stack<TreeNode *> st;
    map<long int, int> mp;
    while(node != NULL || !st.empty()) {
        if(node != NULL) {
            st.push(node);
            mp.insert(pair<long int, int>((long int)node, 0));
            node = node->left;
        } else {
            node = st.top();
            st.pop();
            if(mp[(long int)node] == 0) {
                st.push(node);
                mp[(long int)node] = 1;
                node = node->right;
            } else {
                cout << node->data << "    ";
                node = NULL;
            }
        }
    }
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    preorder(root);
    cout << endl;
    preorderIterative1(root);
    preorderIterative2(root);
    cout << endl;
    inorder(root);
    cout << endl;
    inorderIterative(root);
    cout << endl;
    postorder(root);
    cout << endl;
    postorderIterative(root);

    return 0;
}
