#include<iostream>
using namespace std;


// https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbU55Q0xLSE52S1ZXa3dldU1YR3FVUXl2SHp0UXxBQ3Jtc0ttSTJYbUczOWU0NUZySzBSWjdMblphTl81WGhJTHZIenJMTkI3LXRRbjFEek9iUTVmdHp1LVFSNV9vbU9Eei1ubE5IdHNBejIwc0llaVRKQkM5ZXNqMTJoWDE3b0dFOGY5OUZ3X3gxWVVySXZkRmxFQQ&q=https%3A%2F%2Fwww.codingninjas.com%2Fcodestudio%2Fguided-paths%2Fbasics-of-c%2Fcontent%2F118817%2Foffering%2F1382190&v=i_5pvt7ag7E


class Hero {
    
    //properties
    private:
    int health;

    public:
    char *name;
    char level;
    static int timeToComplete;

    Hero() {
        cout << "Simple constructor called" << endl;
        name = new char[100];
    }

    //Paramerterised Constructor
    Hero(int health) {
        this -> health = health;
    }

    Hero(int health, char level) {
        this -> level = level;
        this -> health = health;
    }

    //copy constructor
    Hero(Hero& temp) {

        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this->name = ch;

        cout << "Copy constructor called" << endl;
        this->health = temp.health;
        this->level = temp.level;
    }

    void print(){
        cout << endl;
        cout << "[ Name: " << this->name<< " ,";
        cout << "health: " << this->health << " ,";
        cout <<"level: " << this->level << " ]";
        cout << endl << endl;
    }

    int getHealth() {
        return health;
    }

    char getLevel() {
        return level;
    }

    void setHealth(int h) {
        health = h;
    }

    void setLevel(char ch) {
        level = ch;
    }

    void setName(char name[]) {
        strcpy(this->name, name);
    }

    static int random() {
        return timeToComplete ;
    }

    //Destructor
    ~Hero() {   
        cout << "Destructor bhai called" << endl;
    }

};

int Hero::timeToComplete = 5;

int main() {

    //cout << Hero::timeToComplete << endl;
    // a static function 
    // they do not have this keyword pointer
    // it can access static members only
    cout << Hero::random() << endl;




    // Hero a;

    // cout << a.timeToComplete << endl;
    // but calling it this way is not recommended
    // recommended is 
    // cout << Hero::timeToComplete << endl;

    // Hero b;
    // b.timeToComplete = 10 ;
    // cout  << a.timeToComplete << endl;
    // cout << b.timeToComplete << endl;



    // //Static
    // Hero a;

    // //Dynamic
    // Hero *b = new Hero();
    // //manually destructor call
    // delete b;



//     Hero hero1;

//     hero1.setHealth(12);
//     hero1.setLevel('D');

//      depp copy | shallow copy ??

//     char name[7] = "Babbar";
//     hero1.setName(name);

//     //hero1.print();

//     //use default copy constructor

//     Hero hero2(hero1);
//     //hero2.print();
// //    Hero hero2 = hero1;

//     hero1.name[0] = 'G';
//     hero1.print();

//     hero2.print();

//     hero1 = hero2;

//     hero1.print();

//     hero2.print();



    // //Hero tt;

    // //object created statically
    // Hero ramesh(10);
    // //cout << "Address of ramesh " << &ramesh << endl;
    // ramesh.print();

    // //dynamically
    // Hero *h =  new Hero(11);
    // h->print();

    // Hero temp(22, 'B');
    // temp.print();



    /*
    //static allocation
    Hero a;
    a.setHealth(80);
    a.setLevel('B');
    cout << "level is  " << a.level << endl;
    cout << " health is " << a.getHealth() << endl;
    //dynamicallly
    Hero *b = new Hero;
    b->setLevel('A');
    b->setHealth(70);
    cout << "level is  " << (*b).level << endl;
    cout << " health is " << (*b).getHealth() << endl;
    cout << "level is  " << b->level << endl;
    cout << " health is " << b->getHealth() << endl;
    */
    


    // //creation of Object
    // Hero ramesh;   
    // cout << "Size of Ramesh is " << sizeof(ramesh) << endl;

    // cout << "Ramesh health is " << ramesh.getHealth() << endl;
    // //use setter
    // ramesh.setHealth(70);
    // ramesh.level = 'A';


    // cout << "health is: " << ramesh.getHealth() << endl; 
    // cout << "Level is: " << ramesh.level << endl; 

    // //cout << "size : " << sizeof(h1) << endl;


    // getter | setter defintition sdekh lena

    return 0;
}