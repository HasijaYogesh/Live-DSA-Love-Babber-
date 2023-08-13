
/*
#include <iostream>
using namespace std;

int main()
{
    int i = 0;
    i = i + 1;
    cout << i << endl;
    i = i + 1;
    cout << ++i << endl;
}
*/

/*
#include <iostream>
using namespace std;

int main() {

    short i=2300, j=4322;
    cout<<" i + j = "<<(i+j);

    return 0;
}
*/

/*
#include <iostream>
using namespace std;

int main() {
    float l, b;
    float P = 2*(l+b);
    cout<<("Perimeter = ", P);

    return 0;
}
*/

/*
#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter N"<<endl;
    cin>>n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}
*/

/*
#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter Number "<<endl;
    cin >> n;
    bool isPrime = true;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            isPrime = false;
            break;
        }
    }
    if (isPrime) {
        cout << "Prime" << endl;
    }
    else {
        cout << "Not Prime" << endl;
    }
    return 0;
}
*/


/*
#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter N"<<endl;
    cin>>n;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<=n;j++) {
            if(j==i+1 || j == n || i == 0){
                cout<<j;
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}
*/


/*
#include <iostream>
using namespace std;

int main() {
  int n;
  cout<<"Enter N"<<endl;
  cin>>n;
  int num = 1;
  int e = 2;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n - i ; j++) {
      cout<<"  ";
    }
    int p = num;
    for (int j = 1; j <= i; j++) {
      cout<<" "<<p++;
    }
    if(i!=1) {
        int g = e;
        for (int j = 1; j<=i-1; j++) {
        cout<<" "<<g--;
        }
        e = e+2;
    }
    num++;
    cout<<endl;
  }
  return 0;
}
*/


/*
#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter N"<<endl;
    cin>>n;

    for(int i=0;i<n;i++) {
        for(int j=n-i-1;j>=0;j--) {
            cout<<" ";
        }
        if (i==0 || i==1 || i==n-1) {
            for(int k=1;k<=i+1;k++) {
                cout<<k<<" ";
            }
        }
        else {
            for(int k=1;k<=i+1;k++) {
                if(k==1) {
                    cout<<1;
                }
                if(k==i+1) {
                    cout<<i+1;
                }
                else {
                    cout<<"  ";
                }
            }
        }
        cout<<endl;
    }

    return 0;
}
*/


/*
#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter N"<<endl;
    cin>>n;

    for(int i=0;i<n;i++) {
        int k = 0;
        for(int j=0;j<((2*n)-1);j++) {
            if(j<n-i-1) {
                cout<<" ";
            }
            else if(k<2*i+1) {
                cout<<"*";
                k++;
            }
            else {
                cout<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}
*/


/*
#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter N"<<endl;
    cin>>n;

    for(int i=0;i<n;i++) {
        int k = 0;
        for(int j=0;j<((2*n)-1);j++) {
            if(j<n-i-1) {
                cout<<" ";
            }
            else if(k<2*i+1) {
                if( k==0 || k == 2*i || i==n-1) {
                    cout<<"*";
                }
                else {
                    cout<<" ";
                }
                k++;
            }
            else {
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
*/