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

void levelorder(TreeNode *node, int i) {
    if(node == NULL) return;
    else if(i == 0) cout << node->data << "    ";
    
    if(node->left) {
        cout << node->left->data << "    ";
    }
    if(node->right) {
        cout << node->right->data << "    ";
    }
        levelorder(node->left, 1);
        levelorder(node->right, 1);
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

void levelorderIterative1(TreeNode *node) {
    queue<TreeNode*> q;
    
    q.push(node);
    
    while(node != NULL || !q.empty()) {
        node = q.front();
        q.pop();
        cout << node->data << "    ";
        
        if(node->left != NULL) {
            q.push(node->left);
        }
        
        if(node->right != NULL) {
            q.push(node->right);
        }
        
        node = NULL;
    }
}

void levelorderIterative2(TreeNode *node) {
    cout << node->data << "    ";
    
    queue<TreeNode*> q;
    q.push(node);
    
    while(!q.empty()) {
        node = q.front();
        q.pop();
        
        if(node->left != NULL) {
            cout << node->left->data << "    ";
            q.push(node->left);
        }
        
        if(node->right != NULL) {
            cout << node->right->data << "    ";
            q.push(node->right);
        }
    }
}

int treeHeight1(TreeNode *node, int h) {
    if(node == NULL) return h;
    
    h = max(max(treeHeight1(node->left, h+1), h), max(treeHeight1(node->right, h+1), h));
    
}

int treeHeight2(TreeNode *node) {
    int x, y;
    if(node != NULL) {
        x = treeHeight2(node->left);
        y = treeHeight2(node->right);
        if(x > y) return x+1;
        else return y+1;
    }
    return 0;
}

int count(TreeNode *node) {
    int x, y;
    if(node != NULL) {
        x = count(node->left);
        y = count(node->right);
        return x+y+1;
    }
    return 0;
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
    cout << endl;
    levelorder(root, 0);
    cout << endl;
    levelorderIterative1(root);
    cout << endl;
    levelorderIterative2(root);
    cout << endl;
    cout << "Height1: " << treeHeight1(root, 0) << endl;
    cout << "Height2: " << treeHeight2(root) << endl;
    cout << "Nodes: " << count(root) << endl;

    return 0;
}
