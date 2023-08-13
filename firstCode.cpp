//
/*
#include <iostream>
using namespace std;

int main() {
    cout<<'2';

    return 0;
}
*/

// ********** IF ELSE BASICS ***********
/*
#include <iostream>
using namespace std;

int main() {
    // Declare a int variable
    int age;
    // Print enter the age
    cout<<"Enter the age - ";
    // Take input into age variable
    cin>>age;
    if(age >= 18) {
        cout<<"Can vote"<<endl;
    }
    else {
        cout<<"Cannot vote"<<endl;
    }

    return 0;
}
*/

// ******** IF ELSE IF LADDDER ******
/*
#include <iostream>
using namespace std;

int main()
{
    int marks;
    cout << "Marks -";
    cin >> marks;

    // First Approach
    if (marks >= 90)
    {
        cout << "A grade";
    }
    else
    {
        if (marks >= 80)
        {
            cout << "B grade";
        }
        else
        {
            if (marks >= 60)
            {
                cout << "C grade";
            }
            else
            {
                if (marks >= 40)
                {
                    cout << "D grade";
                }
                else {
                    cout<<"E grade";
                }
            }
        }
    }

    // Second Approach - more logical and readable
    if(marks>=90) {
        cout<<"A"<<endl;
    }
    else if(marks>=80) {
        cout<<"B"<<endl;
    }
    else if(marks>=60) {
        cout<<"C"<<endl;
    }
    else if(marks>=40) {
        cout<<"D"<<endl;
    }
    else {
        cout<<"E"<<endl;
    }

    return 0;
}
*/

// ***** IF ELSE BASICS *******
/*
#include <iostream>
using namespace std;

int main() {
    int broNum;
    cout<<"Enter Number of brothers"<<endl;
    cin>>broNum;

    if(broNum == 0) {
        cout<<"Baat ban jayegi";
    }
    else {
        cout<<"Baat nhi banegi";
    }

    return 0;
}
*/

// ******** FOR LOOP ********
/*
#include <iostream>
using namespace std;

int main()
{

    // for(int i=0; i<5; i++) {
    //     cout<<i<<endl;
    // }

    // for(int i=1; i<=10; i++) {
    //     cout<<2*i<<endl;
    // }

    // for(int i=1; i<=5; i=i+2) {
    //     cout<<i<<endl;
    // }

    // for(int i=100;i>0;i=i/2) {
    //     cout<<i<<endl;
    // }

    // for(int i=5;(i>=0 && i<=10); i=i+1) {
    //     cout<<i<<endl;
    // }

    // int i = 0;
    // for (;;)
    // {
    //     if (i < 5)
    //     {
    //         cout << i << endl;
    //         i++;
    //     }
    // }

    // int n;
    // if(cin>>n) {
    //     cout<<"babbar";
    // }

    // int n;
    // if(cout<<"yogesh") {
    //     cout<<"babbar";
    // }

    return 0;
}
*/


// ********* PATTERNS **********
/*
#include <iostream>
using namespace std;

int main() {
    // Outer loop for row 
    for(int row=0; row<3; row=row+1) {
        // Inner loop for col
        for(int col=0; col<5;col=col+1) {
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
    cout<<"Enter n"<<endl;
    cin>>n;
    
    for(int row=0; row<n; row=row+1) {
        for(int col=0; col<n; col=col+1) {
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

    int rowC;
    int colC;

    cin>>rowC;
    cin>>colC;
    
    for(int row=0; row<rowC; row+=1) {
        // If first and last row, print 5 stars
        if(row==0 || row==rowC-1) {
            for(int col=0;col<colC;col+=1) {
                cout<<"* ";
            }
        }
        else {
            // remaining rows
            cout<<"* ";
            for(int col=0;col<colC-2; col+=1) {
                cout<<"  ";
            }
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
    cout<<"Enter n"<<endl;
    cin>>n;

    for(int row=0; row<n;row++) {
        for(int col=0; col<row+1; col++) {
            cout<<"*";
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
    cout<<"Enter n"<<endl;
    cin>>n;

    for(int row=0; row<n; row++) {
        for(int col=0; col < n-row; col++) {
            cout<<"*";
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
    cout<<"Enter n"<<endl;
    cin>>n;

    for(int row=0;row<n;row++) {
        for(int col=0; col<row+1;col++) {
            cout<<col+1;
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
    cout<<"Enter n"<<endl;
    cin>>n;

    for(int row=0;row<n;row++) {
        for(int col=0;col<n-row;col++) {
            cout<<col+1;
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
    cout<<"Enter n"<<endl;
    cin>>n;

    for(int row=0;row<n;row++) {
        for(int space=n-row; space>0;space--) {
            cout<<" ";
        }
        for(int col=0;col<=row;col++) {
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
    cout<<"Enter n"<<endl;
    cin>>n;

    for(int row=0;row<n;row++) {
        for(int space=0; space<row;space++) {
            cout<<" ";
        }
        for(int col=n-row;col>0;col--) {
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}
*/