// ******* CREATING THE CLASS ******
/*
#include <iostream>
using namespace std;

class Animal {
    private:
    int weight;

    public:
    // State or properties
    int age;
    string type;

    // Default Constructor
    Animal() {
        this->weight = 0;
        this->age = 0;
        this->type = "";
        cout<<"Constructror Called"<<endl;
    }

    // Parameterised Constructor
    Animal(int age) {
        this->age = age;
        cout<<"Parameterised Constructor called"<<endl;
    }

    Animal(int age, int weight) {
        this->age = age;
        this->weight = weight;
        cout<<"Parameterised Constructor 2 called"<<endl;
    }

    Animal(int age, int weight, string name) {
        this->age = age;
        this->weight = weight;
        this->type = name;
        cout<<"Parameterised Constructor 3 called"<<endl;
    }

    // Copy constructor
    Animal (Animal& obj) {
        this->age = obj.age;
        this->weight = obj.weight;
        this->type = obj.type;
        cout<<"Inside copy constructor"<<endl;
    }

    // Behaviour
    void eat() {
        cout<<"Eating"<<endl;
    }
    void sleep() {
        cout<<"Sleeping"<<endl;
    }

    // Getters and setters
    int getWeight() {
        return weight;
    }

    void setWeight(int weight) {
        this->weight = weight;
    }


    // Destructor
    ~Animal() {
        cout<<"Inside destructor"<<endl;
    }
};

int main() {
    // Size of a class
    // cout<<"Size of empty class is: "<<sizeof(Animals)<<endl;
    */
    /*
    // Object creation
    // Static 
    Animal ramesh;
    ramesh.age = 12;
    ramesh.type = "Lion";
    cout<<"Age of ramesh is "<<ramesh.age<<endl;
    cout<<"Name of ramesh is "<<ramesh.type<<endl;
    ramesh.eat();
    ramesh.sleep();
    // cout<<"Weight of ramesh is "<<ramesh.weight<<endl; // Uable to access private variables
    // To access private members, we use getter and setter
    ramesh.setWeight(101);
    cout<<"Weight of ramesh is "<<ramesh.getWeight()<<endl;
    */

    // Dynamic Memory
    /*
    Animal* suresh = new Animal;
    (*suresh).age = 15;
    (*suresh).type = "Billi";
    // alternate for above
    suresh->age = 17;
    suresh->type = "chuha";

    suresh->eat();
    suresh->sleep();

    delete suresh;
    */

   /*
   Animal a(10, 100, "Babbar");
   cout<<"Age of a is: "<<a.age<<endl;
   Animal* b = new Animal(10, 100);
   cout<<"Age of a is: "<<b->age<<endl;
   */

    /*
    // Copy object
    Animal a(10, 100, "Babbar");
    Animal* b = new Animal(10, 100);

    Animal c = a;
    Animal d(a);
    */

   /*
   cout<<"Obj A creation"<<endl;
   Animal a;
   a.age = 5;
    cout<<endl;
   cout<<"Obj B creation"<<endl;
   Animal *b = new Animal();
   b->age = 12;
    
    // destruction manually
    delete b;
    */
   /*

    return 0;
}
*/


// ****** INHERITANCE *******
/*
#include <iostream>
using namespace std;

class Animal{
    public: 
    int age;
    int weight;

    void eat() {
        cout<<"Eating"<<endl;
    }
};

class Dog: public Animal {

};

int main() {
    
    Dog d1;
    d1.eat();


    return 0;
}
*/


// ******** SINGLE INHERITANCE ********
/*
#include <iostream>
using namespace std;

class Car {
    public:
    string name;
    int weight;
    int age;

    void speedUp() {
        cout<<"Speeding up"<<endl;
    }
    void breakMarro() {
        cout<<"Break maardi"<<endl;
    }
};

class Scorpio: public Car {
    
};

int main() {
    Scorpio sc;

    sc.speedUp();


    return 0;
}
*/


// ******* MULTI LEVEL INHERITANCE ********
/*
#include <iostream>
using namespace std;

class Fruit {
    public:
    string name;
};


class Mango: public Fruit {
    public: 
    int weight;
};

class Alphanso: public Mango {
    public:
    int sugarLevel;
};

int main() {
    Alphanso a;
    cout<<a.name<<endl;
    cout<<a.weight<<endl;
    cout<<a.sugarLevel<<endl;


    return 0;
}
*/


// ******** MULTIPLE INHERITANCE *******
/*
#include <iostream>
using namespace std;

class A {
    public:
    int physics;
};

class B {
    public:
    int chemistry;
};

class C: public A, public B {
    public:
    int maths;
};

int main() {
    C obj;
    cout<<obj.chemistry<<" "<<obj.physics<<" "<<obj.maths<<endl;

    return 0;
}
*/


// ******* AMBIGUITY PROBLEM IN MULTIPLE INHERITANCE ********
/*
#include <iostream>
using namespace std;

class A {
    public:
    int chemistry;

    A() {
        chemistry = 101;
    }
};

class B {
    public:
    int chemistry;
    B() {
        chemistry = 410;
    }
};

class C: public A, public B {
    public:
    int maths;
};

int main() {
    C obj;
    cout<<obj.A::chemistry<<endl;
    cout<<obj.B::chemistry<<endl;

    return 0;
}
*/


// ********** HEIRARCHICAL INHERITANCE ********
/*
#include <iostream>
using namespace std;

class Car {
    public:
    int age;
    int weight;
    string name;

    void speedUp() {
        cout<<"Speeding up"<<endl;
    }
};

class Scorpio: public Car {

};

class Fortuner: public Car {

};

int main() {
    Scorpio s1;
    Fortuner f1;

    s1.speedUp();
    f1.speedUp();


    return 0;
}
*/


// ********* COMPILE TIME POLYMORPYISM *******
/*
#include <iostream>
using namespace std;

class Maths {
    public:

    int sum(int a, int b) {
        cout<<"In sum 1 func"<<endl;
        return a + b;
    }
    int sum(int a, int b, int c) {
        cout<<"In sum 2 func"<<endl;
        return a + b + c;
    }
    int sum(int a, double b) {
        cout<<"In sum 3 func"<<endl;
        return a+b+10;
    }
    int sum(int a, float b) {
        cout<<"In sum 4 func"<<endl;
        return a+b+100;
    }
};

int main() {
    
    Maths obj;

    cout<<obj.sum(2, 5)<<endl;
    cout<<obj.sum(2,5,3)<<endl;
    cout<<obj.sum(2,5.10)<<endl;
    cout<<obj.sum(2,5.10f)<<endl;

    return 0;
}
*/


// ******** OPERATOR OVERLOADING *********
/*
#include <iostream>
using namespace std;

class Param {
    public:
    int val;

    void operator+(Param& obj2) {
        int value1 = this->val;
        int value2 = obj2.val;
        cout<<(value2-value1)<<endl;
    }    
};

int main() {
    Param obj1, obj2;  

    obj1.val = 2;
    obj2.val = 7;

    // this should print the diffrenece between them
    obj1 + obj2;

    return 0;
}
*/

// ****** RUN TIME POLYMORPHISM - FUNCTION / METHOD OVERIDING ********
/*
#include <iostream>
using namespace std;

class Animal {
    public:
    void speak() {
        cout<<"Speaking"<<endl;
    }
};

class Dog: public Animal {
    public:
    // override speak function of Animal class
    void speak() {
        cout<<"Barking"<<endl;
    }
};

int main() {
    Animal a;
    a.speak();

    Dog d;
    d.speak();


    return 0;
}
*/


// ******* UPCASTING, DOWNCASTING AND VIRTUAL KEYWORD ********
/*
#include <iostream>
using namespace std;

class Animal {
    public:
    virtual void speak() {
        cout<<"Speaking"<<endl;
    }
};

class Dog: public Animal {
    public:
    // override speak function of Animal class
    void speak() {
        cout<<"Barking"<<endl;
    }
};

int main() {
    
    // Upcasting
    Animal* a = new Dog();
    a->speak();

    // Downcasting
    Dog* b = (Dog*)new Animal();
    b->speak();

    return 0;
}
*/


// ******* TWO D ARRAY USING DYNAMIC MEMORY ALLOCATION *********
/*
#include <iostream>
using namespace std;

int main() {
    int row = 5;
    int col = 3;
    int** arr = new int*[row];

    // Dynamic memory allocation
    for(int i=0; i<row; i++) {
        arr[i] = new int[col];
    }

    // Printing
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cout<<arr[i][j]<<" ";
        } cout<<endl;
    }

    // Freeing up the memory
    // Step 1 - Deleting column
    for(int i=0; i<row; i++) {
        delete []arr[i];
    }
    // Step 2 - Deleting row
    delete []arr;

    return 0;
}
*/


// ********* CREATING 2D VECTOR **********
/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> arr(5, vector<int>(5,0));

    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            cout<<arr[i][j]<<" "; 
        }
        cout<<endl;
    }

    return 0;
}
*/


// ******* CONST KEYWORD ********
/*
#include <iostream>
using namespace std;

int main() {
    
    // initialision can be done but we can't reassign a variable
    // const int x = 5;
    // cout<<x<<endl;

    // this will not work in mordern compiler
    // int *p = &x
    // *p = 10;
    // cout<<x<<endl;

    //  CONST data, NON-CONST pointer
    // const int *a = new int(2); //  CONST data, NON-CONST pointer
    // int const *a = new int(2); // same as line number 553
    // cout<<*a<<endl;
    // *a = 2; // cant change the content of data
    // cout<<*a<<endl;
    // delete a;

    // int b = 5;
    // a = &b; // pointer can be reassigned
    // cout<<*a<<endl;

    
    // CONST pointer, but NON-CONST data
    // int *const a = new int(2);
    // cout<<*a<<endl;

    // *a = 20;
    // cout<<*a<<endl;

    // int b = 50;
    // a = &b;
    

    // CONST pointer and NON CONST data
    // const int *const a  = new int(10);
    // cout<<*a<<endl;

    // *a = 50; //  not possible
    // int b = 5;
    // a = &b; //  not possible

    return 0;
}
*/


// ********** MACROS **********
/*
#include <iostream>
using namespace std;

#define PI 3.14159465

#define MAXX(x, y) (x > y ? x : y)

float circleArea(float r) {
    return PI*r*r;
}

float circlePerimeter(float r) {
    return 2*PI*r;
}

void func() {
    int x = 6;
    int b = 17;

    int c = MAXX(x,b);
    cout<<c<<endl;
}

int main() {
    
    cout<<circleArea(10)<<endl;
    cout<<circlePerimeter(10)<<endl;

    func();

    return 0;
}
*/