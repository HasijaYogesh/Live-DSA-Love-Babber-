/*Pointer basics*/
/*
#include <iostream>
using namespace std;

int main() {
    int a = 5;
    int b = 5;
    cout<<&b<<endl;
    cout<<&a<<endl;

    return 0;
}
*/


/*
#include <iostream>
using namespace std;

int main() {
    int a = 5;
    // create pointer
    int* ptr = &a;

    cout<<ptr<<endl;

    // access the value ptr is pointing to
    cout<<*ptr<<endl;

    return 0;
}
*/


/*Size of diffrent data type pointer*/
/*
#include <iostream>
using namespace std;

int main() {
    int a = 5;
    int* p = &a;

    cout<<sizeof(p)<<endl;

    char ch = 'b';
    char* c = &ch;

    cout<<sizeof(c)<<endl;

    double dtr = 5.03;
    double* d = &dtr;

    cout<<sizeof(d)<<endl;

    return 0;
}
*/


/*
#include <iostream>
using namespace std;

int main() {
    // Bad practice

    // int* p;
    // cout<<*p<<endl;


    // Null pointer

    int* ptr = 0;

    if(ptr == 0) {
        cout<<"Its a null pointer";
    }
    else {
        cout<<*ptr<<endl;
    }
    
    return 0;
}
*/


/*
#include <iostream>
using namespace std;

int main() {
    int a = 5;
    int* ptr = &a;

    // Copy of pointer
    int* dursaPtr = ptr;

    cout<<ptr<<endl;
    cout<<dursaPtr<<endl;
    cout<<*ptr<<endl;
    cout<<*dursaPtr<<endl;


    return 0;
}
*/


/*Pointer excercise*/
/*
#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int* p = &a;
    int* q = p;
    int* r = q;

    cout<<a<<endl; // 10
    cout<<&a<<endl; // address of a
    cout<<p<<endl; // address of a
    cout<<&p<<endl; // address of p
    cout<<*p<<endl; // value of a : 10
    cout<<q<<endl; // address of a
    cout<<&q<<endl; // address of q
    cout<<*q<<endl; // value of a : 10
    cout<<r<<endl; // address of a
    cout<<&r<<endl; // address of r
    cout<<*r<<endl; // value of a : 10
    cout<<(*p + *q + *r)<<endl; // 30
    cout<<(*p)*2 + (*r)*3<<endl; // 50
    cout<<(*p/2) - (*q)/2<<endl; // 0

    return 0;
}
*/


/*
#include <iostream>
using namespace std;

int main() {
    int arr[4] = {12,14,16,18};

    cout << arr << endl;
    cout << arr[0] << endl;
    cout << &arr << endl;
    cout << &arr[0] << endl;

    int* p = arr;
    cout << p << endl;
    cout << &p << endl;

    return 0;
}
*/


/*
#include <iostream>
using namespace std;

int main() {
    int arr[4] = {12,14,16,18};

    // cout<<*arr<<endl;
    // cout<<*arr + 1<<endl;
    // cout<<*(arr) + 1<<endl;
    // cout<<*(arr + 1)<<endl;
    // cout<<arr[1]<<endl;
    // cout<<*(arr + 2)<<endl;
    // cout<<arr[2]<<endl;
    // cout<<*(arr + 3)<<endl;
    // cout<<arr[3]<<endl;

    for(int i=0 ; i<4; i++) {
        // All will give same value
        cout<<arr[i]<<" ";
        cout<<i[arr]<<" ";
        cout<<*(arr+i)<<" ";
        cout<<*(i+arr)<<" ";
        cout<<endl;
    } 

    return 0;
}
*/


/*
#include <iostream>
using namespace std;

int main() {
    int arr[4] = {1,2,3,4};
    // Error
    // arr = arr + 2;

    // Can change pointer address
    int* p = arr;
    p = p + 2;


    return 0;
}
*/


/*
#include <iostream>
using namespace std;

int main() {
    
    int arr[10];
    cout<<sizeof(arr)<<endl;
    cout<<sizeof(&arr)<<endl;

    int* p = arr;
    cout<<sizeof(p)<<endl;
    cout<<sizeof(*p)<<endl;

    return 0;
}
*/


/*
#include <iostream>
using namespace std;

int main() {
    char ch[10] = "Babbar";

    char* c = ch;

    cout<<ch<<endl;
    cout<<&ch<<endl;
    cout<<ch[0]<<endl;

    cout<<&c<<endl;
    cout<<*c<<endl;
    cout<<c<<endl;

    return 0;
}
*/


/*
#include <iostream>
using namespace std;

int main() {
    char name[10] = "babbar";

    cout << name << endl;

    // Bad practice
    char* c = "babbar";
    cout << c << endl;


    return 0;
}
*/


/*
#include <iostream>
using namespace std;

void solve(int arr[]) {
    arr[0] = 50;

    cout<<"arr: "<<arr<<endl;
    cout<<"&arr: "<<&arr<<endl;

    cout<<"Inside solve function"<<endl;
    for(int i=0;i<10;i++) {
        cout<<arr[i]<<" ";
    } cout<<endl;
}

int main() {
    int arr[10] = {1,2,3,4};

    cout<< sizeof(arr)<<endl;

    for(int i=0;i<10;i++) {
        cout<<arr[i]<<" ";
    } cout<<endl;

    cout<<endl<<" Now calling solve function"<<endl;

    solve(arr);

    cout<<" Wapas  main function me aagye he"<<endl;

    for(int i=0;i<10;i++) {
        cout<<arr[i]<<" ";
    } cout<<endl;


    return 0;
}
*/


/*
#include <iostream>
using namespace std;

void update(int *p) {
    cout<<"Addres stored inside p is: "<<p<<endl;
    cout<<"Addres of p is: "<<&p<<endl;
    *p = *p + 10;
}

int main() {
    int a = 5;
    cout<<"Address of a is: "<<&a<<endl;
    int* ptr = &a;
    cout<<"Address store in ptr is: "<<ptr<<endl;
    cout<<"Address of ptr is: "<<&ptr<<endl;
    cout<<"value of a is: "<<a<<endl;
    update(ptr);
    cout<<"value of a is: "<<a<<endl;


    return 0;
}
*/


/*Pointer to pointer*/
/*
#include <iostream>
using namespace std;

int main() {
    int a = 5;
    int* p = &a;

    int** q = &p;

    cout<<&a<<endl;
    cout<<a<<endl;
    cout<<p<<endl;
    cout<<&p<<endl;
    cout<<*p<<endl;
    cout<<q<<endl;
    cout<<&q<<endl;
    cout<<*q<<endl;
    cout<<**q<<endl;

    return 0;
}
*/


/*
#include <iostream>
using namespace std;

void util(int* p) {
    *p = *p + 1;
}

int main() {
    int a = 5;
    int* p = &a;

    cout<<"Before"<<endl;
    cout<<a<<endl;
    cout<<p<<endl;
    cout<<*p<<endl;

    util(p);

    cout<<"After"<<endl;
    cout<<a<<endl;
    cout<<p<<endl;
    cout<<*p<<endl;

    return 0;
}
*/


/*
#include <iostream>
using namespace std;

void solve(int** ptr) {
    **ptr = **ptr + 1; 
}

int main() {
    int x = 12;
    int* p = &x;
    int** q = &p;

    solve(q);

    cout<<x<<endl;

    return 0;
}
*/


/*
#include <iostream>
using namespace std;

int main() {
    int a = 5;

    // creating reference variable
    int& b = a;

    cout<<a<<endl;
    cout<<b<<endl;
    b = b + 1;
    cout<<a<<endl;
    cout<<b<<endl;

    a = a + 1;
    cout<<a<<endl;
    cout<<b<<endl;

    return 0;
}
*/


/*
#include <iostream>
using namespace std;

void solve(int& b) {
    b++;
}

int main() {
    int a = 5;

    cout<<a<<endl;
    solve(a);
    cout<<a<<endl;

    return 0;
}
*/


/*
#include <iostream>
using namespace std;

int main() {
    char st[] = "ABCD";

    for(int i=0; st[i] != '\0'; i++) {
        cout<< st[i] << " " << *(st)+i << " " << *(i+st) << " " << i[st] << endl; 
    }

    return 0;
}
*/


/*
#include <iostream>
using namespace std;

int main() {
    float a = 10.5;
    cout<<sizeof(a)<<endl;

    return 0;
}
*/


// ******* BASIC POINTERS *******
/* 
#include <iostream>
using namespace std;

int main() {
    int a = 5;
    int* ptr = &a;

    cout<<"Address of a - "<<&a<<endl;
    cout<<"Value of ptr - "<<ptr<<endl;
    cout<<"Value at address stored in ptr - "<<*ptr<<endl;
    cout<<"Address of pointer - "<<&ptr<<endl;
    cout<<"Size of pointer ptr - "<<sizeof(ptr)<<endl;

    return 0;
}
*/


// ******* NULL POINTER ********
/*
#include <iostream>
using namespace std;

int main() {
    int* ptr = 0;

    cout<<*ptr<<endl;


    return 0;
}
*/


// ******* REFRENCE VARIABLE ******
/*
#include <iostream>
using namespace std;

void solve(int& b) {
    b--;
}

int main() {
    int a = 5;

    cout<<a<<endl;
    solve(a);
    cout<<a<<endl;

    return 0;
}
*/


//
/*
#include <iostream>
using namespace std;

int* solve() {
    int a = 5;
    int *ans = &a;
    cout<<*ans<<endl;
    return ans;
}

int main() {
    
    cout<<*solve()<<endl; 


    return 0;
}
*/


// ********* SIEVE OF ERATOSTHENIS **********
/*
#include <iostream>
#include <vector>
using namespace std;

vector<bool> Sieve(int n) {
    // create a sieve array of N size telling isPrime
    vector<bool>sieve(n+1, true);
    sieve[0] = sieve[1]=false;  

    for(int i=2; i*i<=n; i++) {
        cout<<i<<" ";
        if(sieve[i] == true) {
            int j = i*i;
            while(j<=n) {
                if(sieve[j] ==true) {
                    sieve[j]=false;
                }
                j += i;
            }
        }
    }

    return sieve;
}

int main() {
    vector<bool> sieve = Sieve(25);
    cout<<endl;
    for(int i=0; i<25; i++) {
        if(sieve[i]) {
            cout<<i<<" ";
        }
    }

    return 0;
}
*/


// ********** SEGMENTED SIEVE ********
/*
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<bool> Sieve(int n) {
    // create a sieve array of N size telling isPrime
    vector<bool>sieve(n+1, true);
    sieve[0] = sieve[1]=false;  

    for(int i=2; i*i<=n; i++) {
        if(sieve[i] == true) {
            int j = i*i;
            while(j<=n) {
                if(sieve[j] ==true) {
                    sieve[j]=false;
                }
                j += i;
            }
        }
    }

    return sieve;
}

vector<bool> segSieve(int L, int R) {
    // Get me a prime array, i will use it to mark seg sieve.
    vector<bool> sieve = Sieve(sqrt(R));
    vector<int> basePrime;
    for(int i=0; i<sieve.size(); i++) {
        if(sieve[i] == true) {
            basePrime.push_back(i);
        }
    }

    vector<bool> segSieve(R-L+1, true);
    if(L==0 || L==1) {
        segSieve[L] == false;
    }

    for(auto prime: basePrime) {
        int first_mul = (L/prime) * prime;
        if(first_mul < L) {
            first_mul += prime;
        }
        int j = max(first_mul, prime*prime);
        while(j<=R) {
            segSieve[j - L]=false;
            j+=prime;
        }
    }
    return segSieve;
}

int main() {
   
    int L = 110;
    int R = 130;

    vector<bool> ss = segSieve(L, R);
    for(int i=0; i<ss.size(); i++) {
        if(ss[i]) {
            cout<<i + L<<" ";
        }
    }

    return 0;
}
*/