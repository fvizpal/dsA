
/*
iska fayda is 
TC is O(n) ans sC is O(1)

iterativ way me uppar wapis jaane ka koi tareeka nhi 
here comes morris traversal

temp links bnayenge to node jisse aaye hain

*/
//From geeks for geeks

/* A binary tree tNode has data, a pointer to left child
and a pointer to right child */
struct tNode {
	int data;
	struct tNode* left;
	struct tNode* right;
};

/* Function to traverse the binary tree without recursion
and without stack */
void MorrisTraversal(struct tNode* root)
{
	struct tNode *current, *pre;

	if (root == NULL)
		return;

	current = root;
	while (current != NULL) {

		if (current->left == NULL) {
			cout << current->data << " ";
			current = current->right;
		}
		else {

			/* Find the inorder predecessor of current */
			pre = current->left;
			while (pre->right != NULL
				&& pre->right != current)
				pre = pre->right;

			/* Make current as the right child of its
			inorder predecessor */
			if (pre->right == NULL) {
				pre->right = current;
				current = current->left;
			}

			/* Revert the changes made in the 'if' part to
			restore the original tree i.e., fix the right
			child of predecessor */
			else {
				pre->right = NULL;
				cout << current->data << " ";
				current = current->right;
			} /* End of if condition pre->right == NULL */
		} /* End of if condition current->left == NULL*/
	} /* End of while */
}

/* UTILITY FUNCTIONS */
/* Helper function that allocates a new tNode with the
given data and NULL left and right pointers. */
struct tNode* newtNode(int data)
{
	struct tNode* node = new tNode;
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/* Driver program to test above functions*/
int main()
{

	return 0;
}

// This code is contributed by Sania Kumari Gupta (kriSania804)
// MY try
void MorrisTraversal(Node* root ){

    Node* current, pre;

    if( root == NULL)   return 

    current = root;

    while( current != NULL){
        if( current -> left == NULL){
            cout << current -> data << " ";
            current = current -> right;
        }
        else {
            // finding the inorder predecessor
            pre = current -> left;
            while(pre -> right != NULL && pre-> right != current){
                pre = pre -> right;
            }

            // make current as the right child of its inorder predecessor
            if ( pre -> right == NULL){
                pre-> right = current;
                current = current->left;
            }
            // revert the changes made in of part to restore the original changes
            else{
                pre->right = NULL;
                cout << current -> data;
                current = current ->right; // to go back to wehre this current came from 
        
            }
        }
    }
} // har ek node ko yha 3 baar visit kara jrha hai 
