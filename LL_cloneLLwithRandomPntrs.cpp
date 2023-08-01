

class Solution{

    private:
    void insertAtTail(Node* head ,  Node* tail, int d){
        if ( head == NULL){
            head = newNode ;
            tail = newNode ;
            return;
        } else {
            tail -> next = newNode;
            tail = newNode;
        }
    }

    public:
    Node* copyList(Node* head){

        //step 1 create a clone list
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;

        Node* temp = head;
        while ( temp != head){
            insertAtTail(cloneHead, cloneTail, temp -> data);
            temp = temp -> next;

        }

        //step 2: create a map
        unordered_map < Node*, Node* > oldToNew;

        Node* originalNode = head ;
        Node* cloneNode = cloneHead;
        while ( temp != Null && temp2 != NULL){
            oldToNew[originalNode] = cloneNode;
            originalNode = originalNode -> next;
            cloneNode = cloneNode -> next;

        }

        originalNode = head;
        cloneNode = cloneHead;

        while ( originalNode != NULL){
            cloneNode -> random = oldToNew[orifinalNode -> random];
            originalNode = originalNode -> next;
            cloneNode = cloneNode -> next;
        }
        return cloneHead;
    }
}