// ********* SELECTION SORT **********
/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr{5,4,3,2,1};
    int n = arr.size();
    // selection sort
    // outer loop - (n-1) rounds
    for(int i=0; i<n-1; i++) {

        int minIndex = i;
        // inner loop -> index of minimum element in range i to n
        for(int j=i+1; j<n; j++) {
            if(arr[minIndex]>arr[j]) {
                // new minimum index
                minIndex = j;
            }
        }
        swap(arr[i],arr[minIndex]);
    }

    for(auto val :arr) {
        cout<<val<<" ";
    }
    cout<<endl;

    return 0;
}
*/


// ********* BUBBLE SORT AN ARRAY********
/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr{60,50,40,30,20,10,70};
    int n = arr.size();

    // Bubble sort
    for(int i=0; i<n-1; i++) {
        bool isSwap = false;
        for(int j=0; j<n-i; j++) {
            if(arr[j] > arr[j+1]) {
                isSwap = true;
                swap(arr[j],arr[j+1]);
            }
        }
        if(isSwap == false) {
            // sort ho chukka he, no need to check in further rounds
            break;
        } 
    }

    for(auto val: arr) {
        cout<<val<<" ";
    } cout<<endl;

    return 0;
}
*/


// ******* INSERTION SORT AN ARRAY ********
/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr{10,1,7,6,14,9};
    int n = arr.size();

    // Insertion sort
    for(int round=1; round<n; round++) {
        // Step A - Fetch
        int val = arr[round];

        // Step B - Comparision
        int j = round - 1;
        for(; j>=0; j--) {
            if(arr[j]>val) {
                // Step C - Shift
                arr[j+1] = arr[j];
            }
            else {
                // Rukna he
                break;
            }
        }

        // Step D - Copy
        arr[j+1] = val;  
    }

    for(auto val: arr) {
        cout<<val<<" ";
    } cout<<endl;

    return 0;
}
*/


// ******** INBUILT SORT FUNCTION *******
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v{10,1,7,6,14,9};

    sort(v.begin(),v.end());

    for(auto val: v) {
        cout<<val<<" ";
    } cout<<endl;

    return 0;
}
*/