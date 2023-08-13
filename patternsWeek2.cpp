/*
#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter N"<<endl;
    cin>>n;

    for(int row=0; row<n; row++) {
        for(int col=0;col<n-row-1;col++) {
            cout<<" ";
        }
        for(int col=0; col<row+1;col++) {
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
    cout<<"Enter N"<<endl;
    cin>>n;
    for(int row=0; row<n;row++) {
        for(int col=0;col<row;col++) {
            cout<<" ";
        }
        for(int col=0; col<n-row;col++) {
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}
*/

//------------Solid Diamond-------------
/*
#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter N"<<endl;
    cin>>n;
    for(int row=0; row<n; row++) {
        for(int col=0;col<n-row-1;col++) {
            cout<<" ";
        }
        for(int col=0; col<row+1;col++) {
            cout<<"* ";
        }
        cout<<endl;
    } 
    for(int row=0; row<n;row++) {
        for(int col=0;col<row;col++) {
            cout<<" ";
        }
        for(int col=0; col<n-row;col++) {
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}
*/


//----------Hollow Diamond-----------
/*
#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter N"<<endl;
    cin>>n;
    for(int row=0;row<n;row++) {
        for(int col=0;col<n-row-1;col++) {
            cout<<" ";
        }        
        for(int col=0; col<2*row+1;col++) {
            if(col==0) {
                cout<<"*";
            }
            else if(col==2*row) {
                cout<<"*";
            }
            else {
                cout<<" ";
            }
        }
        cout<<endl;
    }
    for(int row=0; row<n; row++) {

        for(int col=0; col<row; col++) {
            cout<<" ";
        }
        for(int col=0; col<2*n-2*row-1; col++) {
            if(col==0) {
                cout<<"*";
            }
            else if (col == 2*n-2*row-2) {
                cout<<"*";
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


// Fillep Solid-------------
/*
#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter N"<<endl;
    cin>>n;

    for(int row=0;row<n;row++) {
        for(int col=0; col<n-row;col++) {
            cout<<"*";
        }
        for(int col=0; col<2*row+1;col++) {
            cout<<" ";
        }
        for(int col=0; col<n-row;col++) {
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
    cout<<"Enter N"<<endl;
    cin>>n;

    for(int row=0;row<n;row++) {
        for(int col=0; col<row+1;col++) {
            cout<<row+1;
            if(col!=row) {
                cout<<"*";
            }
        }
        cout<<endl;
    }
    for(int row=0;row<n;row++) {
        for(int col=0; col<n-row;col++) {
            cout<<n-row;
            if(col!= n-row-1) {
                cout<<"*";
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
    for(int row=0;row<n;row++) {
        for(int col=0;col<row+1;col++) {
            int ans = col+1;
            char ch = ans + 'A' - 1;
            cout<<ch;
        }
        for(int col=row;col>=1;col--) {
            int ans = col;
            char ch = ans + 'A' - 1;
            cout<<ch;
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

    for(int row=0; row<n;row++) {
        
        for(int col=0;col<n-row-1;col++) {
            cout<<" ";
        }
        int start = 1;
        for(int col=0; col<2*row+1;col++) {
            if(row==0 || row==n-1) {
                if(col%2==0) {
                    cout<<start;
                    start = start+1;
                }
                else {
                    cout<<" ";
                }
            }
            else {
                if(col==0) {
                    cout<<1;
                }
                else if(col==2*row) {
                    cout<<row+1;
                }
                else {
                    cout<<" ";
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
*/


// **********
// ****  ****
// ***    ***
// **      **
// *        *
// *        *
// **      **
// ***    ***
// ****  ****
// **********
/*
#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter N"<<endl;
    cin>>n;

    int even = n-2;
    for(int row=0;row<(n/2);row++) {
        for(int col=0;col<(n/2)-row;col++) {
            cout<<"*";
        }
        for(int col=0;col<row*2;col++) {
            cout<<" ";
        }
        for(int col=0;col<(n/2)-row;col++) {
            cout<<"*";
        }
        cout<<endl;
    }

    for(int row=n/2;row<n;row++) {
        for(int col=(n/2)-1;col<row;col++) {
            cout<<"*";
        }
        for(int col=0;col<even;col++) {
            cout<<" ";
        }
        even = even - 2;
        for(int col=(n/2)-1;col<row;col++) {
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
    cout<<"Enter N"<<endl;
    cin>>n;

    for(int row=0;row<n;row++) {
        for(int col=0;col<n;col++) {
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
    cout<<"Enter N"<<endl;
    cin>>n;

    for(int row=0;row<n;row++) {
        if(row==0 || row==n-1) {
            for(int col=0;col<n;col++) {
            cout<<"* ";
            }
        }
        else {
            for(int col=0;col<n;col++) {
                if(col==0 || col==n-1) {
                    cout<<"* ";
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

// ******
// *   *
// *  *
// * *
// *
/*
#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter N"<<endl;
    cin>>n;

    for(int row=0;row<n;row++) {
        for(int col=0;col<n-row;col++) {
            if(row==0 || row==n-1) {
                cout<<"*";
            }
            else {
                if(col==0 || col==n-row-1) {
                    cout<<"*";
                }
                else {
                    cout<<" ";
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

    for(int row=0;row<n;row++) {
        for(int col=0;col<row+1;col++) {
            if(row==0 || row==n-1) {
                cout<<col+1<<" ";
            }
            else {
                if(col==0 || col==row) {
                    cout<<col+1<<" ";
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

    for(int row=0; row<n; row++) {
        int num = row + 1;
        for(int col=0; col<n-row;col++) {
            if(row==0 || row==n-1) {
                cout<<num;
            }
            else {
                if(col==0 || col==n-row-1) {
                    cout<<num;
                }
                else {
                    cout<<" ";
                }
            }
            num++;
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

    for(int row=0; row<n; row++) {
        for(int col=0;col<n-row-1;col++) {
            cout<<"  "; 
        }
        for(int col=0;col<row+1;col++) {
            cout<<col+1<<" ";
        }
        int num = row;
        for(int col=0; col<row;col++) {
           if(row!=0) {
                cout<<num<<" ";
                num--;
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
    int star = n+3;
    for(int row=0; row<n; row++) {
        for(int col=0; col<star; col++) {
            cout<<"*";
        }
        for(int col=0; col<row+1; col++) {
            cout<<row+1<<"*";
        }
        for(int col=0; col<star-1; col++) {
            cout<<"*";
        }
        star--;
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
    
    if(n%2==0) {
        n = n - 1;
    }

    for(int row=0; row<n; row++) {
        int countStar;
        if(row<=(n/2)-1) {
            countStar = row+1;
        }
        else {
            countStar = n-row;
        }
        for(int col=0; col<countStar; col++) {
            cout<<"*";
        }
        cout<<endl;
    }
    cout<<endl;

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
    for(int row=0;row<n;row++) {
        for(int col=0; col<row+1;col++) {
            cout<<num<<" ";
            num++;
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
    cout<<endl;
    int spaces = (n*2) - 2;
    int spaces2 = 0;
    for(int row=0; row<n; row++) {
        for(int col=0; col<row+1; col++) {
            cout<<"*";
        }
        for(int col=0; col<spaces; col++) {
            cout<<" ";
        }
        for(int col=0; col<row+1; col++) {
            cout<<"*";
        }
        spaces=spaces-2;
        cout<<endl;
    }

    for(int row=0; row<n; row++) {
        for(int col=0; col<n-row; col++) {
            cout<<"*";
        }
        for(int col=0; col<spaces2; col++) {
            cout<<" ";
        }
        for(int col=0; col<n-row; col++) {
            cout<<"*";
        }
        spaces2 = spaces2 + 2;
        cout<<endl;
    }

    return 0;
}
*/