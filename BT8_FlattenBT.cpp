/*/ INTO LINKED LIST
 mtlb order m ek linked list k andar daalna hai 
 or haan ye INPLACE krna hai 
 mtlb or extra memory use nhi krni hai
 
 agar LOT/inorder/preorder/postorder krke krenge toh sc complexity bhi O(n) ho jayegi 
 pr yha O(1) me ye flatten krna h
 // isliye toh morris traversal sikha tha ;)

 approach
 1: 
    travrse krta jaunga or new LL nodes create krta jaunga
    // but this is wrong since is not inplace
 2:
    we can use recursion but SC badh jayega
 3:
    using morris traversal   hota toh ye bhi preorder NLR hai 
    isme inorder predecessor ko link krenge root->right k sath
    abb N ko L ke sath kr denge connect
    
*/

void flattenToLL(Node* root){
    ListNode* curr = root; // this is listNode i think
    while( curr != NULL){

        if( curr -> left){
            Node* pred = curr-> left;
            while( pred -> right ){
                pred = pred -> right;
            }
            pred -> right = curr -> right ;
            curr -> right = curr -> left;
            curr -> left = NULL; // jiska kaam nhi ab usse null krdenge 
        }
        curr = curr -> right;
    }
}//  TC O(n) and SC O(1)
