/*
Design a stack that supports getMin() in O(1) time and O(1) extra space
 getMin will give the minimum element in the stack
 when it is poped then getMin() shall give minimum element in the new modified stack

 approach1{
    1. make a mini variable with INT_MAX;
    2. push first element
    3. now update mini to this element
    4. push next element and again; if this pushed element is smaller than the prev mini;; update mini to this new pushed element
    5. correction this mini shld not be s variable ;
        we must store minimum element till then after every push to the stack 
    6. ye storage ek aur stack me use kar skte hain
    7. isse hoga ye ki har ek pop ke bad hame leftOver stack ka minimum element pataa hoga

 }
 //par extra space use nhi krna hai // mtlb ki mini ko vector wagera nhi bna skte 
 // only a variable

 approach2{
    1. FOR 1ST element normal push krna hai or
        mini = min( curr, mini);
    2. baki elements ke liye 
        if( curr < mini)
            val = 2*curr - mini
            push( val);
            mini update;
            // what and why the fuck !?
        else 
            normal push karenge
    

 }
 pop me iss push ka ulta kar dena
 pop me 2*mini - curr karenge

*/

class specialStack{
    //defining data member
    stack<int> s;
    int mini = INT_MAX; // optional hai

    public:

    void push( int data){
        //for first element
        if( s.empty()){
            s.push(data);
            mini = data;
        }
        else{
            if( data < mini){
                s.push( 2*data - mini);
                mini = data;
            }
            else{
                s.push(data);
            }
        }
    }

    int pop(){
        if( s.empty()){
            return -1;
        }

        int curr = s.top();
        s.pop();
        if( curr > mini){
            return curr;
        }
        else{
            int prevMin = mini;
            int val = 2*mini - curr;
            mini = val;
            return prevMin;
        }
    }

    int top(){
        if(s.empty())       return -1;\

        int curr = s.top();
        if( curr < mini){
            return mini;
        }
        else{
            return curr;
        }
    }

    bool isEmpty(){
        return s.empty();
    }

    int getMin(){
        if( s.empty()){
            return -1;
        }

        return mini;
    }
};

