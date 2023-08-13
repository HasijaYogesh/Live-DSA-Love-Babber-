/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr{5,4,3,2,1};
    int n = arr.size();
    //selection sort
    //outer loop -> (n-1) round
    for(int i=0; i<n-1;i++) {
        int minIndex = i;
        // inner loop -> index of minimum element in range i->n
        for(int j=i+1;j<n;j++) {
            if(arr[j]<arr[minIndex]) {
                //new minimum 
                minIndex = j;
            }
        }
        //swap 
        swap(arr[i],arr[minIndex]);
    }

    //printing
    for(int i=0; i<n;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
*/


/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr{10,1,7,6,14,9};
    
    int n =arr.size();
    // Bubble sort
    for (int round=1; round<n; round++) {
        bool swapped = false;
        for(int j=0; j<n-round; j++) {
            if(arr[j]>arr[j+1]) {
                swapped = true;
                swap(arr[j], arr[j+1]);
            }
        }
        if(swapped==false) {
            // sort ho chika he, no need to check ahead
            break;
        }
    }
    // printing array
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
*/


/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr{10,1,7,6,14,9};

    int n = arr.size();

    // insertion sort
    for(int round=1; round<n; round++) {
        // step a - fetch
        int val = arr[round];
        // step b - compare
        int j=round-1;
        for( ;j>=0; j--) {
            if(arr[j]>val) {
                //step c - shift
                arr[j+1]=arr[j];
            }
            else {
                //rukna he
                break;
            }
        }
        // step d - copy
        arr[j+1] = val;
    }
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
*/


/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> arr{10,1,7,6,14,9};

    sort(arr.begin(),arr.end());

    for(int i=0; i<arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
*/


/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(char first, char second) {
    return first > second;
}

bool compare(int a, int b) {
    return a > b;
}

int main() {
    string s = "babbar";
    sort(s.begin(),s.end(), cmp);

    cout<<s<<endl;

    vector<int> v{5,3,1,2,4};
    sort(v.begin(),v.end(), compare);

    for(auto i:v) {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}
*/


/*
#include <iostream>
#include <map>
using namespace std;

int main() {
    // creation of map
    map<int, char> meraMap;

    meraMap[0] = 'a';
    meraMap[1] = 'b';
    meraMap[25] = 'z';

    cout<<"Your ans is: "<<meraMap[1]<<endl;

    return 0;
}
*/