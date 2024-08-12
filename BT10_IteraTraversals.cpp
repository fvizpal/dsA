
// --------- INORDER TRAVERSAL
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* node = root;

        vector<int> inorder;
        while(!st.empty() or node) {
            while(node) {
                st.push(node);
                node = node -> left;
            }

            node = st.top();
            st.pop();

            inorder.push_back(node->val);

            node = node->right;
        }

        return inorder;
    }
};


// ----------- PREORDER TRAVERSAL
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        st.push(root);

        while( !st.empty()){
            TreeNode* currNode = st.top();
            st.pop();
            if( currNode){
                ans.push_back(currNode->val);
                st.push(currNode->right);
                st.push(currNode->left);
            }
        }

        return ans;
    }
};

// --------- POSTORDER TRAVERSAL
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodes;
        stack<TreeNode*> todo;
        TreeNode* last = NULL;
        while (root || !todo.empty()) {
            if (root) {
                todo.push(root);
                root = root -> left;
            } 
            else {
                TreeNode* node = todo.top();
                if (node -> right && last != node -> right) {
                    root = node -> right;
                } 
                else {
                    nodes.push_back(node -> val);
                    last = node;
                    todo.pop();
                }
            }
        }
        return nodes;
    }
};