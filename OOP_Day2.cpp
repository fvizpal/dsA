// ------- Encapsulation ---------------
wrapping up data members and functions

// Fully encapsulated class
All data members are marked private: , so you can only access them in same class

Advantages:
- Hiding data | mark it private, security increase
- if we want we can make class "read ony"
- code REUSABILITY
- unit testing

class Hero {
  private: // this is encapsulation
  int age;

  public:
  int gerAge() { // getter
    return this->age;
  }
};

// ---------- INHERITANCE ---------------
inheriting properties (sub class or child class ) or behaviour from 
another class (parent class or super class)

class Human {
  private:
  int height;

  public: 
  int weight;

  private:
  int age;

  public:
  int getAge() {
      return this->age;
  }

  void setWeight(int w) {
    this->weight = w;
  }
};

// child class : parent class // its accessing in private mode here // can in public too
class Male: private Human {

  public:
  string color;

  void sleep() {
      cout << "Male Sleeping" << endl;[]
  }

  int getHeight() {
    return this->height;
  }
};

int main() {

  Male m1;
  //cout << m1.height << endl;

  /*
  Male object1;
  cout << object1.age << endl;  // can be accessed when inheriting in public mode only
  cout << object1.weight << endl; // see that table of mode of inheritance
  
  // if base class private marked but inheritance mode is public then cannot access in sub class
  // there are total 9 such combinations

  cout << object1.height << endl;

  cout << object1.color << endl;

  object1.setWeight(84);
  cout << object1.weight << endl;
  object1.sleep();
  */

  return 0;
}

// ---- access modifiers ---------

// ---- single inheritance -------
from a class A a class B inherites properties from A 

class Animal {
    public:
    int age;
    int weight;


    public:
    void speak() {
      cout << "Speaking " << endl;
    }
};

class Dog: public Animal {

};

int main() {
  Dog d;
  d.speak();
  cout << d.age << endl;

  return 0;
}


// ---- multilevel inheritance ----
A -> B -> C -> D

class Animal {
  public:
  int age;
  int weight;

  public:
  void speak() {
    cout << "Speaking " << endl;
  }
};

class Dog: public Animal {

};

class GermanShepherd: public Dog {

};

// ---- multiple inheritance ----
A -> B and C -> B;
comma separated inheritance defination

class Animal {

  public:
  int age;
  int weight;


  public:
  void bark() {
    cout << "Barking " << endl;
  }
};

class Human {
  public:
  string color;

  public:
  void speak() {
    cout << "Speaking " << endl;
  }
};

//Multiple Inheritance
class Hybrid: public Animal, public Human {

};

int main() {
  Hybrid obj1;
  obj1.speak();
  obj1.bark();
  
  return 0;
}

// ---- heirarchical inheritance ---
one class serves as parent to more than one class

class A {
  public:
  void func1() {
    cout << "Inside Funcion 1" << endl;
  }
};

class B: public A {
  public:
  void func2() {
    cout << "Inside Funcion 2" << endl;
  }
};

//Hierarchical Inheritance
class C: public A {
  public:
  void func3() {
    cout << "Inside Funcion 3" << endl;
  }
};

int main() {
  A object1;
  object1.func1();

  B object2;
  object2.func1();
  object2.func2();

  C object3;
  object3.func1();
  object3.func3();

  return 0;
}

// ---- hybrid inheritance ----



// ---- Inheritance Ambiguity --


class A {
  public:

  void func() {
    cout << " I am A" << endl;
  }
};

class B {
  public:

  void func() {
    cout << " I am B" << endl;
  }
};

class C: public A, public B {

};

int main() {

  C obj;
  //obj.func();

  obj.A::func() ;
  obj.B::func();

  return 0;
}

// ---- Polymorphism ----
poly - many, morph - forms


class A {
    public:
    void sayHello() {
        cout << "Hello Love Babbar" << endl;
    }
    
    int sayHello(char name) {
        cout << "Hello Love Babbar" << endl;
        return 1;
    }

    void sayHello(string name) {
        cout << "Hello " << name  << endl;
    }
};

class B {
    public:
    int a;
    int b;

    public: 
    int add() {
      return a+b;
    }

    void operator+ (B &obj) {
      /*
        int value1 = this -> a;
        int value2 = obj.a;
        cout << "output " << value2 - value1 << endl; 
      */
      cout << "Hello Babbar" << endl;
    }

    void operator() () {
        cout << "main Bracket hu " << this->a << endl;
    }

};

class Animal {
    public:
    void speak() {
      cout << "Speaking "<< endl;
    }
};

class Dog: public Animal {
    public:
    void speak() {
        cout << "Barking " << endl;
    }
};

int main() {

    Dog obj;
    obj.speak();


  /*
    B obj1, obj2;

    obj1.a = 4;
    obj2.a = 7;

    obj1 + obj2;
    obj1();*/


  /*
    A obj;
    obj.sayHello();

  */


    return 0;
}