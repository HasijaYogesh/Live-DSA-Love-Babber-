/*
#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target) {
    int start = 0;
    int end = size - 1;

    int mid = (start+end)/2;

    while(start<=end) {
        if(arr[mid]==target) {
            return mid;
        }
        else if(target < arr[mid]) {
            end = mid - 1;
        }
        else if(target > arr[mid]) {
            start = mid + 1;
        }
        mid = (start+end)/2;
    }
    return -1;
}

int main() {
    int arr[8] = {2,4,8,10,12,16,18,20};
    int size = 8;
    int target = 20;

    int index = binarySearch(arr, size, target);
    if(index==-1) {
        cout<<"Target not found"<<endl;
    }
    else {
        cout<<"Target found at index "<<index<<endl;
    }
    return 0;
}
*/


/*
#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target) {
    int start = 0;
    int end = size - 1;

    int mid = start + (end-start)/2;

    while(start<=end) {
        if(arr[mid]==target) {
            return mid;
        }
        else if(target < arr[mid]) {
            end = mid - 1;
        }
        else if(target > arr[mid]) {
            start = mid + 1;
        }
        mid = start + (end-start)/2;
    }
    return -1;
}

int main() {
    int arr[8] = {2,4,8,10,12,16,18,20};
    int size = 8;
    int target = 12;

    int index = binarySearch(arr, size, target);
    if(index==-1) {
        cout<<"Target not found"<<endl;
    }
    else {
        cout<<"Target found at index "<<index<<endl;
    }
    return 0;
}
*/


/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    
    vector<int> v{1,2,3,4,5,6,};
    int arr[] = {1,2,3,4,5,6,7};
    int size = 7;

    // if(binary_search(v.begin(), v.end(), 3)) {
    //     cout<<"Found"<<endl;
    // }
    // else {
    //     cout<<"Not found"<<endl;
    // }

    if(binary_search(arr, arr+size, 6)) {
        cout<<"Found"<<endl;
    }
    else {
        cout<<"Not found"<<endl;
    }

    return 0;
}
*/


//**********First occurence of element************
/*
#include <iostream>
#include <vector>
using namespace std;

int firstOccurence(vector<int> v, int target) {
    int s = 0;
    int e = v.size()-1;
    int ans = -1;
    int mid = s + (e-s)/2;

    while(s<=e) {
        if(v[mid]==target) {
            ans = mid;
            e = mid - 1;
        }
        else if(target>v[mid]) {
            s = mid + 1;
        }
        else if(target>v[mid]) {
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }

    return ans;
}

int main() {
    vector<int> v{1,2,3,4,4,4,6,7};
    int target = 4;
    int indexOfFirstOcc = firstOccurence(v, target);
    cout<<"Ans is "<<indexOfFirstOcc<<endl;

    return 0;
}
*/


/*
#include <iostream>
#include <vector>
using namespace std;

int lastOcc(vector<int> arr, int target) {
    int s = 0;
    int e = arr.size() - 1;

    int mid = s + (e-s)/2;
    int ans = -1;

    while(s<=e) {
        if(arr[mid] == target) {
            ans = mid;
            s = mid + 1;
        }
        else if(target<arr[mid]) {
            e = mid - 1;
        }
        else if(target > arr[mid]) {
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }

    return ans;
}

int main() {
    vector<int> v{1,3,7,7,7,7,7,7,7,7,9};

    int target = 7;

    int ans = lastOcc(v, target);
    cout<<"Last Ocuurence at "<<ans<<endl;


    return 0;
}
*/


/*
#include <iostream>
#include <vector>
using namespace std;

int findPeakIndex(vector<int> arr) {
    int s = 0;
    int e = arr.size() - 1;
    int mid = s+ (e-s)/2;
    while(s<e) {
        if(arr[mid]<arr[mid+1]) {
            s = mid + 1;
        }
        else {
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}

int main() {
    
    vector<int> arr{0,1,2,5,10,5,2,1,0};
    cout<<"Ans is "<<findPeakIndex(arr);

    return 0;
}
*/


/*
#include <iostream>
#include <vector>
using namespace std;

int findPivot(vector<int> arr) {
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e-s)/2;

    while(s<=e) {
        if(mid+1 < arr.size() && arr[mid] > arr[mid+1]) {
            return mid;
        }
        if( mid-1>=0 && arr[mid-1] > arr[mid]) {
            return mid-1;
        }
        if(arr[s]>=arr[mid]) {
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return -1;
}

int main() {
    vector<int> arr{3,4,5,6,7,1,2};

    int ans = findPivot(arr);

    cout<<"Pivot element is "<<arr[ans]<<endl;

    return 0;
}
*/


/*
#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int target) {
    int start = 0;
    int end = arr.size() - 1;
    int mid = start + (end-start)/2;

    while(start<=end) {
        if(arr[mid]==target) {
            return mid;
        }
        if(target<arr[mid]) {
            end = mid -1;
        }
        else {
            start = mid + 1;
        }
        mid = start + (end-start)/2;
    }
    return -1;
}

int main() {
    vector<int> arr{1,2,3,4,5,6,7,8,9,10};
    int target = 15;

    cout<<"Answer is "<<binarySearch(arr, target)<<endl;

    return 0;
}
*/


