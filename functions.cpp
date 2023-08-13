/*
#include <iostream>
using namespace std;

int areaOfCircle(int radius) {
    return 3.14 * radius * radius;
}

int main() {

    int radius;
    cout<<"Enter radius"<<endl;
    cin>>radius;

    int ans = areaOfCircle(radius);
    cout<<"Area of circle is "<<ans<<endl;

    return 0;
}
*/

/*
#include <iostream>
using namespace std;

void isEvenOrOdd(int num) {
    if(num%2==0) cout<<"Even";
    else cout<<"Odd";
}

int main() {
    int num;
    cout<<"Enter number"<<endl;
    cin>>num;

    isEvenOrOdd(num);


    return 0;
}
*/

/*
#include <iostream>
using namespace std;

int factorial(int num) {
    int fact=1;

    for(int i=1; i<=num; i++) {
        fact = fact * i;
    }
    return fact;
}

int main() {
    int num;
    cout<<"Enter number"<<endl;
    cin>>num;

    int ans = factorial(num);
    cout<<"Factorial of "<<num<<" is "<<ans<<endl;

    return 0;
}
*/

/*
#include <iostream>
using namespace std;

int checkPrime(int num) {
    for(int i=2; i<num; i++) {
        if (num%i==0) return false;
    }
    return true;
}

int main() {
    int num;
    cout<<"Enter number"<<endl;
    cin>>num;

    for(int i=0; i<=num; i++) {
        bool ans = checkPrime(i);
        if(ans) {
            cout<<i<<" ";
        }
    }


    return 0;
}
*/

/*
#include <iostream>
using namespace std;

int main() {
    int age = 2;
    (age>=18) ? cout<<"Can vote"<<endl : cout<<"Cannot vote"<<endl;

    int num = 6;
    (num%2==0) ? cout<<"Even"<<endl: cout<<"Odd"<<endl;

    return 0;
}
*/

/*
#include <iostream>
using namespace std;
int main() {
  int a = 5;
  int b = 10;

  cout<<(++a)*(--b)<<endl;
  cout<<(++a)*(b--)<<endl;
  cout<<(a++)*(--b)<<endl;
  cout<<(a++)*(b--)<<endl;
  return 0;
}
*/

/*
#include <iostream>
using namespace std;
int main() {
  int num = 5639;
  int num2 = 0;

  while(num!=0) {
    int rem = num%10;
    num2 = (num2*10) + rem;
    num = num / 10;
  }

  cout<<num2<<endl;

  return 0;
}
*/

/*
#include <iostream>
using namespace std;
int main() {
  int n = 7;
  int ans = 0;

  while(n != 0) {
    if( n&1 ) {
      // found one set bit, so increment set bit count
      ans++;
    }
    // right shift
    n = n>>1;
  }
  cout<<"Number of set bits "<<ans<<endl;
  return 0;
}
*/

/*
#include <iostream>
using namespace std;

int main() {

    int n;
    cout<<"N"<<endl;
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=i;
    }
    cout<<sum<<endl;

    return 0;
}
*/

/*
#include <iostream>
using namespace std;

int main() {
  // size of the triangle
  int size = 5;
  // loop to print the pattern
  for (int i = 0; i < size; i++) {
    // print column
    for (int j = 0; j < i+1; j++) {
      cout << "*";
    }
    cout << endl;
  }
  return 0;
}
*/


/*
#include <iostream>
using namespace std;

int main() {
  // size of the pyramid
  int size; cin>>size;
  for (int i = 0; i < size; i++) {
    // print spaces
    for (int j = 0; j < i; j++) {
      cout << " ";
    }
    // print stars
    for (int k = 1; k < 2*(size - i); k++) {
      cout << "*";
    }
    cout << endl;
  }
  return 0;
}
*/


/*
#include <iostream>
using namespace std;

int main() {
    char oper;
    float num1, num2;
    cout << "Enter an operator (+, -, *, /): ";
    cin >> oper;
    cout << "Enter two numbers: " << endl;
    cin >> num1 >> num2;

    switch (oper) {
        case '+':
            cout << num1 << " + " << num2 << " = " << num1 + num2;
            break;
        case '-':
            cout << num1 << " - " << num2 << " = " << num1 - num2;
            break;
        case '*':
            cout << num1 << " * " << num2 << " = " << num1 * num2;
            break;
        case '/':
            cout << num1 << " / " << num2 << " = " << num1 / num2;
            break;
        default:
            // operator is doesn't match any case constant (+, -, *, /)
            cout << "Error! The operator is not correct";
            break;
    }

    return 0;
}
*/


/*
#include <iostream>
using namespace std;

int binaryToDecimal(int b){
    int ans=0;
    int c=0;
    while(b){
        ans=ans+(b % 10) * (1 << c++);
        b/=10;
    }
    return ans;
}

int main() {
    
    cout<<binaryToDecimal(1111);

    return 0;
}
*/

/*
#include <iostream>
using namespace std;

int main() {
  // heart star pattern
  int size;
  cout<<"Enter N"<<endl;
  cin>>size;

  for (int i = size / 2; i < size; i+=2) {
    // print first spaces
    for (int j = 1; j < size - i; j += 2) {
      cout << " ";
    }
    // print first stars
    for (int j = 1; j < i + 1; j++) {
      cout << "*";
    }
    // print second spaces
    for (int j = 1; j < size - i + 1; j++) {
      cout << " ";
    }
    // print second stars
    for (int j = 1; j < i + 1; j++) {
      cout << "*";
    }
    cout << endl;
  }
  // lower part
  // inverted pyramid
  for (int i = 0; i < size; i++) {
    // print spaces
    for (int j = 0; j < i; j++) {
      cout << " ";
    }
    // print stars
    for (int k = 1; k < 2*(size - i); k++) {
      cout << "*";
    }
    cout << endl;
  }
  return 0;
}
*/


