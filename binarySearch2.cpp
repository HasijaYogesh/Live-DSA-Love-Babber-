/*
#include <iostream>
using namespace std;

int findSqrt(int n) {
    int target = n;
    int s = 0;
    int e = n;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e) {
        if(mid*mid==target) {
            return mid;
        }
        if(mid*mid > target) {
            e = mid - 1;
        }
        else {
            ans = mid;
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main() {
    int n;
    cout<<"Enter Number :- "<<endl;
    cin>>n;
    int ans = findSqrt(n);
    cout<<"Ans is "<<ans<<endl;

    int precision;
    cout<<"Enter the number of floating digits in precision "<<endl;
    cin>>precision;

    double step = 0.1;
    double finalAns = ans;
    for(int i=0; i<precision; i++) {
        for(double j=finalAns; j*j<=n; j=j+step) {
            finalAns = j;
        }
        step = step/10;
    }
    cout<<"Final ans is "<<finalAns<<endl;

    return 0;
}
*/


/*
#include <iostream>
using namespace std;

bool binarySearch(int arr[][4], int rows, int cols, int targets) {
    int s = 0;
    int e = rows*cols - 1;
    int mid = s + (e-s)/2;

    while(s<=e) {
        int rowIndex = mid/cols;
        int colIndex = mid%cols;

        if(arr[rowIndex][colIndex] == targets) {
            return true;
        }
        else if(arr[rowIndex][colIndex]<targets) {
            s = mid + 1;
        }
        else if(arr[rowIndex][colIndex]>targets) {
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return false;
}

int main() {
    int arr[5][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16},{17,18,19,20}};

    int rows = 5;
    int cols = 4;
    int target = 99;

    bool ans = binarySearch(arr, rows, cols, target);
    cout<<"Ans is "<<ans;


    return 0;
}
*/


/*Binary Search in a nearly sorted array*/
/*
#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int target) {
    int s= 0;
    int e= arr.size()-1;
    int mid = s + (e-s)/2;

    while(s<=e) {
        if(arr[mid] == target) {
            return mid;
        }
        if( mid-1>=s && arr[mid-1] == target) {
            return mid-1;
        }
        if( mid+1<=e && arr[mid+1] == target) {
            return mid+1;
        }
        if(target > arr[mid]) {
            s = mid+2;
        }
        else {
            e = mid-2;
        }
        mid = s + (e-s)/2;
    }
    return -1;
}

int main() {
    vector<int> arr{10,3,40,20,50,80,70};
    int target = 70;

    int ans = binarySearch(arr, target);
    cout<<"Index of "<<target<<" is "<<ans<<endl;


    return 0;
}
*/


/*Divide 2 numbers using Binary Search*/
/*
#include <iostream>
using namespace std;

int solve(int dividend, int divisor) {
    int s = 0;
    int e = abs(dividend);
    int mid = s+(e-s)/2;
    int ans = -1;

    while(s<=e) {
        if(abs(mid * divisor) == abs(dividend)) {
            ans = mid;
            break;
        }
        if(abs(mid * divisor) > abs(dividend)) {
            e = mid - 1;
        }
        else {
            ans = mid;
            s = mid + 1;
        }
        mid = s+(e-s)/2;
    }
    if ((divisor<0 && dividend<0) || (divisor>0 && dividend>0)) {
        return ans;
    }
    else {
        return -ans;
    }
}

int main() {
    int dividend = -22;
    int divisor = -7;

    int ans = solve(dividend, divisor);
    cout<<"Ans is "<<ans<<endl;

    return 0;
}
*/


/*Find the odd ocurring element in an array*/
/*
#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> arr) {
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e-s)/2;

    while(s<=e) {
        if(s==e) {
            return s;
        }
        if(mid%2==0) {
            if(arr[mid]==arr[mid+1]) {
                s = mid + 2;
            }
            else {
                e = mid;
            }
        }
        else {
            if(arr[mid]==arr[mid-1]) {
                s = mid + 1;
            }
            else {
                e = mid-1;
            }
        }
        mid = s + (e-s)/2;
    }
    return -1;
}

int main() {
    vector<int> arr{1,1,2,2,3,3,4,4,3,600,600,4,4};

    int ans = solve(arr);
    cout<<"Index is "<<ans<<endl; 
    cout<<"Value is "<<arr[ans]<<endl;

    return 0;
}
*/


/*
#include <iostream>
#include <vector>
using namespace std;

int findPivot(vector<int> arr) {
    int s=0;
    int e=arr.size()-1;
    int mid=s+((e-s)/2);

    while(s<=e) {
        if(s==e) {
            //SIngle element
            return s;
        }
        if(mid<=e && arr[mid] > arr[mid+1]) {
            return mid;
        }
        if(mid-1>=s && arr[mid-1]>arr[mid]) {
            return mid-1;
        }
        if(arr[s]>arr[mid]) {
            e = mid-1;
        }
        else {
            s=mid+1;
        }
        mid = s+(e-s)/2;
    }
    return -1;
}

int main() {
    vector<int> arr{9,10,2,4,6,8};
    int ans = findPivot(arr);

    if(ans==-1) {
        cout<<"Not found"<<endl;
    }
    else {
        cout<<"Ans is at index "<<ans<<endl;
        cout<<"Value of ans is "<<arr[ans]<<endl;
    }

    return 0;
}
*/


/*Get the first repeating element in an array*/
/*
#include <iostream>
#include <unordered_map>
using namespace std;

int firstRepeat(int a[], int n) {
    unordered_map<int, int> hash;
    for(int i=0; i<n; i++) {
        hash[a[i]]++;
    }

    for(int i=0; i<n; i++) {
        if(hash[a[i]]>1) {
            return i+1;
        }
    }
    return -1;
    
}

int main() {
    int a[]={1,5,3,4,3,5,6};

    cout<<"Ans is "<<firstRepeat(a, 7)<<endl;


    return 0;
}
*/


/*
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <set>
using namespace std;

set<pair<int,int>> diffrenecePair(vector<int> arr, int k) {
    sort(arr.begin(),arr.end());
    set<pair<int,int>> ans;
    int i = 0;
    int j = i + 1;
    int n = arr.size();

    while( j < n) {
        if(arr[j]-arr[i]==k) {
            ans.insert({arr[i],arr[j]});
            i++;
            j++;
        }
        else if(arr[j]-arr[i]<k) {
            j++;
        }
        else if(arr[j]-arr[i]>k) {
            i++;
        }
        if(i==j) {
            j++;
        }
    }
    return ans;
}

int main() {
    vector<int> arr{8,5,9,3,6,2,4,7};
    int diff = 4;
    set<pair<int,int>> ans = diffrenecePair(arr, diff);

    return 0;
}
*/


/*
#include <iostream>
#include <vector>
#include <set>
#include <bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int> arr,int s, int target) {
    int e = arr.size()-1;
    int mid = s+(e-s)/2;
    while(s<=e) {
        if(arr[mid]==target) {
            return mid;
        }
        else if(arr[mid]<target) {
            s = mid+1;
        }
        else {
            e = mid-1;
        }
    }
    return -1;
}

set<pair<int,int>> diffrenecePair(vector<int> arr, int k) {
    sort(arr.begin(),arr.end());
    set<pair<int,int>>ans;

    for(int i=0; i<arr.size()-1;i++) {
        int target = arr[i]+k;
        int index = binarySearch(arr,i+1,target);
        if(index!=-1) {
            ans.insert(arr[i],arr[index]);
        }
    }
    return ans;
}

int main() {
    vector<int> arr{3,1,4,1,5};
    int diff = 2;
    set<pair<int,int>> ans = diffrenecePair(arr, diff);
    return 0;
}
*/


// ******** BINARY SEARCH *******
/*
#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int target) {
    int start = 0;
    int end = arr.size() - 1;
    int mid = start +( (end-start)/2);

    while(start<=end) {
        if(arr[mid] == target) {
            return mid;
        }
        else if(target < arr[mid]) {
            end = mid - 1;
        }
        else if(target > arr[mid]) {
            start = mid + 1;
        }
        mid = start + ((end - start)/2);
    }  

    return -1;
}

int main() {

    vector<int> arr{0,1,2,3,4,5,6,7,8,9,10};
    int target = 13;
    int ans = binarySearch(arr, target);

    cout<<"Answer is "<<ans<<endl;


    return 0;
}
*/


// ******** FIRST OCUURENCE USING BINARY SEARCH *********
/*
#include <iostream>
#include <vector>
using namespace std;

int firstOccurence(vector<int> arr, int target) {
    int start = 0;
    int end = arr.size() - 1;
    int mid = start +( (end-start)/2);
    int ans = -1;

    while(start<=end) {
        if(arr[mid] == target) {
            ans = mid;
            end = mid-1;
        }
        else if(target < arr[mid]) {
            end = mid - 1;
        }
        else if(target > arr[mid]) {
            start = mid + 1;
        }
        mid = start + ((end - start)/2);
    }  

    return ans;
}

int main() {

    vector<int> arr{1,1,2,2,2,3,4,5};
    int target =2;
    int ans = firstOccurence(arr, target);

    cout<<"Answer is "<<ans<<endl;


    return 0;
}
*/


// ******** LAST OCUURENCE USING BINARY SEARCH *********
/*
#include <iostream>
#include <vector>
using namespace std;

int lastOccurence(vector<int> arr, int target) {
    int start = 0;
    int end = arr.size() - 1;
    int mid = start +( (end-start)/2);
    int ans = -1;

    while(start<=end) {
        if(arr[mid] == target) {
            ans = mid;
            start = start+1;
        }
        else if(target < arr[mid]) {
            end = mid - 1;
        }
        else if(target > arr[mid]) {
            start = mid + 1;
        }
        mid = start + ((end - start)/2);
    }  

    return ans;
}

int main() {

    vector<int> arr{1,1,2,2,2,2,3,4,5};
    int target = 2;
    int ans = lastOccurence(arr, target);

    cout<<"Answer is "<<ans<<endl;

    return 0;
}
*/


// ******** FIND FISRT, LAST AND TOTAL OCCURENCE IN ANA ARRAY **********
/*
#include <iostream>
#include <vector>
using namespace std;

int firstOccurence(vector<int> arr, int target) {
    int start = 0;
    int end = arr.size() - 1;
    int mid = start +( (end-start)/2);
    int ans = -1;

    while(start<=end) {
        if(arr[mid] == target) {
            ans = mid;
            end = mid-1;
        }
        else if(target < arr[mid]) {
            end = mid - 1;
        }
        else if(target > arr[mid]) {
            start = mid + 1;
        }
        mid = start + ((end - start)/2);
    }  

    return ans;
}

int lastOccurence(vector<int> arr, int target) {
    int start = 0;
    int end = arr.size() - 1;
    int mid = start +( (end-start)/2);
    int ans = -1;

    while(start<=end) {
        if(arr[mid] == target) {
            ans = mid;
            start = start+1;
        }
        else if(target < arr[mid]) {
            end = mid - 1;
        }
        else if(target > arr[mid]) {
            start = mid + 1;
        }
        mid = start + ((end - start)/2);
    }  

    return ans;
}

int main() {

    vector<int> arr{1,1,1,1,1,3,4,5};
    int target = 1;
    int firstOcc = firstOccurence(arr, target);
    int lastOcc = lastOccurence(arr, target);
    int totalOcc = lastOcc - firstOcc + 1;

    cout<<"First occurenece is "<<firstOcc<<" and Last occurence is "<<lastOcc<<endl;
    cout<<"Total occurenece is "<<totalOcc<<endl;


    return 0;
}
*/


// ****** FIND MISSING ELEMENT IN ARRAY FROM 1 TO N *******
/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr{1,2,3,4,5,6,8,9,10};

    int start = 0;
    int end = arr.size() - 1;
    int mid = start + (end - start)/2;
    int ans = -1;

    while(start<=end) {
        if(arr[mid] == mid + 1) {
            start = mid+1;
        }
        else {
            ans = mid + 1;
            end = mid - 1;
        }
        mid = start + (end-start)/2;
    }   

    cout<<"Missing element is "<<ans<<endl;
    
    return 0;
}
*/


// ******** FIND PEAK ELEMENT IN AN ARRAY ********
/*
#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(vector<int> arr) {

    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e-s)/2;

    while(s<e) {
        if(arr[mid] < arr[mid+1]) {
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
    vector<int> arr{1,2,3,4,5,9,8,7,6};

    int ans = findPeakElement(arr);
    cout<<"Ans is "<<ans<<endl;

    return 0;
}
*/


// ******** FIND SQUARE ROOT OF NUMBER USING BINARY SEARCH *******
/*
#include <iostream>
using namespace std;

int squareRoot(int N) {
    int ans = -1;

    int s = 0;
    int e = N;
    int mid = s+(e-s)/2;

    while(s<=e) {
        if(mid*mid == N) {
            return mid;
        }
        else if(mid*mid <= N) {
            ans = mid;
            s = mid + 1;
        }
        else if(mid*mid>N) {
            e = mid - 1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}

int main() {
    int N;
    cout<<"Enter number for square root - "<<endl;
    cin>>N;

    float ans = squareRoot(N);

    int precision;
    cout<<"Enter the precision - "<<endl;
    cin>>precision;

    float step = 0.1;
    for(int i=0; i<precision; i++) {
        for(double j=ans; j*j<=N; j=j+step) {
            ans = j;
        }
        step = step / 10;    
    }

    cout<<"Answer is - "<<ans<<endl;

    return 0;
}
*/


// ******** BINARY SEARCH IN AN 2D ARRAY / MATRIX ********
/*
#include <iostream>
#include <vector>
using namespace std;

bool binarySearch(vector<vector<int> > arr, int target) {
    int n = arr.size();
    int m = arr[0].size();

    int s = 0;
    int e = (m*n) - 1;
    int mid = s+(e-s)/2;

    while(s<=e) {
        int rowIndex = mid / m;
        int colIndex = mid % m;
        if(arr[rowIndex][colIndex] == target) {
            return true;
        }
        else if(arr[rowIndex][colIndex]<target) {
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
        mid = s+(e-s)/2;
    }
    return false;
}

int main() {
    vector<vector<int> > arr{
        { 1, 2, 3, 4},
        { 5, 6, 7, 8},
        { 9,10,11,12},
        {13,14,15,16},
        {17,18,19,20}
    };
    int target = 15;

    bool ans = binarySearch(arr, target);

    if(ans) {
        cout<<"Element found!"<<endl;
    }
    else {
        cout<<"Element not found!!"<<endl;
    }

    return 0;
}
*/


// ********** BINARY SEARCH IN A NEARLY SORTED ARRAY **********
/*
#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int target) {
    int s = 0;
    int e = arr.size() - 1;

    int mid = s+(e-s)/2;

    while(s<=e) {
        if(arr[mid]==target) {
            return mid;
        }
        if(mid-1 >= s && arr[mid-1]==target) {
            return mid-1;
        }
        if(mid+1 < e && arr[mid+1]==target) {
            return mid+1;
        }
        if(target>arr[mid]) {
            s = mid + 2;
        }
        else {
            e = mid - 2;
        }
        mid = s+(e-s)/2;
    }
    return -1;
}

int main() {
    vector<int> arr{10,3,40,20,50,80,60};
    int target = 40;

    int ans = binarySearch(arr, target);

    cout<<"Index of "<<target<<" is "<<ans<<endl;

    return 0;
}
*/


// ******** DIVIDE TWO NUMBERS USING BINARY SEARCH *********
/*
#include <iostream>
using namespace std;

int solve(int dividend, int divisor) {
    int s = 0;
    int e = abs(dividend);

    int mid = s+(e-s)/2;
    int ans = -1;

    while(s<=e) {
        // perfect solution
        if(abs(mid*divisor) == abs(dividend)) {
            ans = mid;
            break;
        }
        //not perfect solution
        if(abs(mid*divisor) > abs(dividend)) {
            // left
            e = mid - 1;
        }
        else {
            // ans store
            ans = mid;
            // right search
            s = mid + 1;
        }
        mid = s+(e-s)/2;
    }

    if((dividend>0 && divisor>0) || (dividend<0 && divisor<0)) {
        return ans;
    }
    return -ans;
}

int main() {
    int dividend = -21;
    int divisor = 7;
    
    int ans = solve(dividend, divisor);
    cout<<"Answer is "<<ans<<endl;

    return 0;
}
*/


// ******** FIND ODD OCCURING ELEMENT BY ME******* 
/*
#include <iostream>
#include <vector>
using namespace std;

int oddOccurence(vector<int> arr) {
    int s = 0;
    int e = arr.size()-1;
    int mid = s+(e-s)/2;

    while(s<=e) {
        if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]) {
            return mid;
        }
        if(arr[mid] == arr[mid+1]) {
            if(mid%2==0) {
                s = mid + 2;
            }
            else {
                e = mid - 1;
            }
        }
        if(arr[mid] == arr[mid-1]) {
            if(mid%2==0) {
                e = mid - 2;
            }
            else {
                s = mid + 1;
            }
        }

        mid = s+(e-s)/2;
    }

    return -1;
}

int main() {
    vector<int> arr{1,1,2,2,3,3,4,4,3,600,600,4,4};

    int ans = oddOccurence(arr);

    cout<<"The answer is - "<<arr[ans]<<endl;

    return 0;
}
*/


// ******** FIND ODD OCCURING ELEMENT BY LB******* 
/*
#include <iostream>
#include <vector>
using namespace std;

int oddOccurence(vector<int> arr) {
    int s = 0;
    int e = arr.size()-1;
    int mid = s + (e-s) / 2;

    while(s<=e) {
        if(s==e) {
            // single element
            return s;
        }
        // 2 cases -> mid - even or mid - odd
        if(mid % 2 == 0) {
            if(arr[mid] == arr[mid+1]) {
                s = mid + 2;
            }
            else {
                e = mid;
            }
        }
        else {
            if(arr[mid] == arr[mid-1]) {
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }
        mid = s + (e-s) / 2;
    }
    return -1;
}

int main() {
    vector<int> arr{1,1,2,2,3,3,4,4,5,4,4,2,2};

    int ans = oddOccurence(arr);

    cout<<"The answer is - "<<arr[ans]<<endl;

    return 0;
}
*/


// ****** FIND PIVOT IN ROTATED ANS SORTED ARRAY *********
/*
#include <iostream>
#include <vector>
using namespace std;

int findPivot(vector<int> arr) {
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e-s) / 2;

    while(s<=e) {
        // single element
        if(s==e) {
            return s;
        }
        if(mid+1<=e && arr[mid]>arr[mid+1]) {
            return mid;
        }
        if(mid-1>=s && arr[mid-1]>arr[mid]) {
            return mid-1;
        }
        if(arr[s]>arr[mid]) {
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
        mid = s + (e-s) / 2;
    }
    return -1;
}

int main() {
    vector<int> arr{76,82,99,11,23,32,44,58,67};
    
    //***** Test cases *******
    // vector<int> arr{1,2,3,4,5,6,7,8,9,10};
    // vector<int> arr{1};

    int ans = findPivot(arr);
    cout<<"Answer is - "<<arr[ans]<<endl;

    return 0;
}
*/


// ******* SEARCH IN ROTATED ANS SORTED ARRAY **********
/*
#include <iostream>
#include <vector>
using namespace std;

int findPivot(vector<int> arr) {
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e-s) / 2;

    while(s<=e) {
        // single element
        if(s==e) {
            return s;
        }
        if(mid+1<=e && arr[mid]>arr[mid+1]) {
            return mid;
        }
        if(mid-1>=s && arr[mid-1]>arr[mid]) {
            return mid-1;
        }
        if(arr[s]>arr[mid]) {
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
        mid = s + (e-s) / 2;
    }
    return -1;
}

int binarySearch(vector<int> arr, int target, int s, int e) {
    int mid = s+(e-s)/2;

    while(s<=e) {
        if (arr[mid]==target) {
            return mid;
        }
        else if(arr[mid]>target) {
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }

        mid = s+(e-s)/2;
    }
    return -1;
}

int search(vector<int> arr, int target) {

    int pivot = findPivot(arr);
    int ans;
    if(target < arr[0]) {
        ans = binarySearch(arr, target, pivot+1, arr.size()-1);
        return ans;
    }
    else {
        ans = binarySearch(arr, target, 0, pivot);
        return ans;
    }
}

int main() {
    vector<int> arr{76,82,99,11,23,32,44,58,67};
    int target = 67;

    int ans = search(arr, target);

    if(ans == -1) {
        cout<<"Not found!"<<endl;
    }
    else {
        cout<<"Found at "<<ans<<endl;
    }

    return 0;
}
*/


// ****** K-DIFF PAIRS IN AN ARRAY WITH TWO POINTER APPROACH *******
/*
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int findPair(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end());

    int i=0, j=1;
    set<pair<int,int>> ans;
    while(j<nums.size()) {
        int diff = nums[j] - nums[i];
        if(diff==k){
            ans.insert({nums[i],nums[j]});
            i++, j++;
        }
        else if(diff>k) {
            i++;
        }
        else {
            j++;
        }
        if(i==j) {
            j++;
        }
    }
    return ans.size();
}

int main() {    
    vector<int> arr{3,1,4,1,5};
    int k = 2;

    int pairCount = findPair(arr, k);
    cout<<"Answer is "<<pairCount<<endl;

    return 0;
}
*/


// ****** K-DIFF PAIRS IN AN ARRAY WITH BINARY SEARCH APPROACH *******
/*
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int binarySearch(vector<int> arr, int s, int e, int target) {
    int mid = s+(e-s)/2;
    while(s<=e) {
        if(arr[mid] == target) {
            return mid;
        }
        else if(arr[mid]>target) {
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
        mid = s+(e-s)/2;
    }
    return -1;
}

int findPairCount(vector<int> arr, int k) {
    sort(arr.begin(),arr.end());
    set<pair<int,int>> ans;

    for(int i=0; i<arr.size(); i++) {
        int element = arr[i];
        int requiredElement = k + arr[i];
        int res = binarySearch(arr, i, arr.size(), requiredElement);

        if(res != -1) {
            ans.insert({arr[i],arr[res]});
        }
    }

    return ans.size();
}

int main() {
    vector<int> arr{1,1,1,1,1};
    int k = 0;

    int ans = findPairCount(arr, k);    
    cout<<"Pair count is - "<<ans<<endl;

    return 0;
}
*/


// ********* FIND K CLOSEST ELEMENT WITH TWO POINTER APPROACH NARROWING OUR WINDOW FROM START TO END ********
/*
#include <iostream>
#include <vector>
using namespace std;

vector<int> twoPtrMethod(vector<int>& arr, int k, int x) {
    int l=0, h = arr.size() - 1;    

    while(h-l >= k) {
        if(x-arr[l] > arr[h] - x) {
            l++;
        }
        else {
            h--;
        }
    }

    // Returning using normal approach
    // vector<int> ans;
    // for(int i=l; i<=h; i++) {
    //     ans.push_back(arr[i]);
    // } 
    // return ans;

    // Returning using STL
    return vector<int> (arr.begin() + l, arr.begin() + h + 1);
}

int main() {
    vector<int> arr{12,16,22,30,35,39,42,45,48,50,53,55,56};
    int k = 4;
    int x = 35;

    vector<int> ans = twoPtrMethod(arr, k, x);
    for(auto val: ans) {
        cout<<val<<" ";
    } cout<<endl;

    return 0;
}
*/


// ********* FIND K CLOSEST ELEMENT WITH SPEARDING OUR WINDOW FOR THE ELEMENT ITSELF (TOP TO BOTTOM APPROACH) ********
/*
#include <iostream>
#include <vector>
using namespace std;

int lowerBound(vector<int> arr, int x) {
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e-s)/2;
    int ans = e;
    while(s<=e) {
        if(arr[mid] >= x) {
            ans = mid;
            e = mid - 1;
        }
        else if(x>arr[mid]) {
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}

vector<int> binarySearchMethod(vector<int>& arr, int k, int x) {
    // Lower bound 
    int h = lowerBound(arr, x);
    int l = h-1;

    while(k--) {
        if(l < 0) {
            h++;
        }
        else if(h>=arr.size()) {
            l--;
        }
        else if(x-arr[l]>arr[h]-x) {
            h++;
        }
        else {
            l--;
        }
    }

    return vector<int> (arr.begin() + l + 1, arr.begin() + h);
}

int main() {
    vector<int> arr{12,16,22,30,35,39,42,45,48,50,53,55,56};
    int k = 4;
    int x = 35;

    vector<int> ans = binarySearchMethod(arr, k, x);
    for(auto val: ans) {
        cout<<val<<" ";
    } cout<<endl;


    return 0;
}
*/


// ******** EXPONENTIAL SEARCH - TIME COMPLEXITY ********
/*
#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int s, int e,  int target) {
    int mid = s+(e-s)/2;
    while(s<=e) {
        if(arr[mid] == target) {
            return mid;
        }
        else if(arr[mid]>target) {
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
        mid = s+(e-s)/2;
    }
    return -1;
}

int expSearch(vector<int> arr, int n, int x) {
    if(arr[0]==x) return 0;

    int i = 1;
    while(i<n && arr[i]<=x) {
        i = i*2; // i*=2; // i=i<<1;
    }

    return binarySearch(arr, i/2, min(i, n-1), x);
}

int main() {
    vector<int> arr{3,4,5,6,11,13,14,15,56,70};
    int n = arr.size();
    int x = 56;

    int ans = expSearch(arr, n, x);
    cout<<"Answer is "<<ans<<endl;

    return 0;
}
*/


// ****** BOOK ALLOCATION PROBLEM ******
/*
#include <iostream>
#include <numeric>
using namespace std;

bool isPossibleSolution(int A[], int N, int M, int sol) {
    int pageSum = 0;
    int count = 1;

    for(int i=0; i<N; i++) {
        if(A[i] > sol) {
            return false;
        }
        if(pageSum + A[i] > sol) {
            count++;
            pageSum = A[i];
            if(count > M) {
                return false;
            }
        }
        else {
            pageSum += A[i];
        }
    }
    return true;
}

int findPages(int A[], int N, int M) {
    if(M>N) {
        return -1;
    }

    int start = 0;
    int end = accumulate(A, A+N, 0);
    int ans = -1;

    while(start <= end) {
        int mid = start + (end - start)/2;
        if(isPossibleSolution(A, N, M, mid)) {
            ans = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    return ans;
}


int main() {
    
    int A[] = {12,34,67,90};
    int N = 4;
    int M = 2;

    int ans = findPages(A, N, M);
    cout<<"Answer is "<<ans<<endl;
    
    return 0;
}
*/


// ******* PAINTERS PARTISION PROBLEM ********
/*
#include <iostream>
#include <numeric>
using namespace std;

bool isPossibleSolution(int arr[], int n, int k, long long mid) {
    long long timeSum = 0;
    int c = 1;

    for(int i=0; i<n; i++) {
        if(arr[i] > mid) {
            return false;
        }
        if(arr[i] + timeSum > mid) {
            c++;
            timeSum = arr[i];
            if(c>k) return false;
        }
        else {
            timeSum += arr[i];
        }
    }
    return true;
}

long long findMinTime(int arr[], int n, int k) {
    long long start = 0;
    long long end = accumulate(arr, arr+n, 0);
    long long ans = -1;

    while(start <= end) {
        long long mid = start + (end-start)/2;

        if(isPossibleSolution(arr, n, k, mid)) {
            ans = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    return ans;
}

int main() {
    int a[] = {10,20,30,40};
    int n = 4;
    int k = 2;

    long long ans = findMinTime(a, n, k);
    cout<<"Answer is "<<ans<<endl;
    
    return 0;
}
*/


// ********* BOOL ALLOCATION PROBLEM **********
/*
#include <iostream>
#include <numeric>
using namespace std;

bool isPossibleSolution(int arr[], int n, int m, int mid) {
    int pageCount = 0;
    int studentCount = 1;
    for(int i=0; i<n; i++) {
        if(arr[i]>mid) {
            return false;
        }
        if(pageCount + arr[i] > mid) {
            studentCount++;
            pageCount = arr[i];
            if(studentCount>m) {
                return false;
            }
        }
        else {
            pageCount = pageCount + arr[i];
        }
    }
    return true;
}

int findPages(int arr[], int n, int m) {
    if (m>n) return -1;

    int start = 0;
    int end = accumulate(arr, arr+n, 0);
    int ans = -1;
    while(start <= end) {
        int mid = start + (end - start)/2;
        cout<<"Mid==="<<mid<<" ";
        int isPossible = isPossibleSolution(arr, n, m, mid);
        cout<<"isPossible=="<<isPossible<<endl;
        if(isPossible) {
            ans = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    return ans;
}

int main() {
    int arr[] = {12,34,67,90};
    int n = 4;
    int m = 2;

    int ans = findPages(arr,n,m);
    cout<<"Answer is "<<ans<<endl;    

    return 0;
}
*/


// ********* AGRESSIVE COWS *********
/*
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool isPossibleSolution(vector<int> stalls, int k, int mid) {
    // can we place k cows, with at least mid distance between cows.
    int c = 1;
    int pos = stalls[0];

    for(int i=0; i<stalls.size(); i++) {
        if(stalls[i] - pos >= mid) {
            c++;
            pos = stalls[i];
        }
        if(c==k) return true;
    }
    return false;
}

int solve(vector<int> stalls, int n, int k) {
    sort(stalls.begin(), stalls.end());
    int start = 0;
    int end = stalls[stalls.size()-1] - stalls[0];
    int ans = -1;

    while(start <= end) {
        int mid = start + (end-start)/2;
        if(isPossibleSolution(stalls, k, mid)) {
            ans = mid;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> stalls{1,2,4,8,9};
    int n = 5;
    int k = 3;

    int ans = solve(stalls, n, k);
    cout<<"Answer is "<<ans<<endl;


    return 0;
}
*/


// ******** EKO SPOJ QUESTION ********
/*
#include <iostream>
using namespace std;

int maxNum(int arr[], int n) {
    int max = INT8_MIN;
    for(int i=0; i<n; i++) {
        if(arr[i]>max) {
            max = arr[i];
        }
    }
    return max;
}

bool isPossibleSolution(int arr[], int n, int wood, int mid) {
    int sum = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] > mid) {
            sum = sum + (arr[i] - mid);
        }
    }
    if(sum >= wood) {
        return true;
    }
    else {
        return false;
    }
}

int ecoSpoj(int arr[], int n, int wood) {
    int start = 0;
    int end = maxNum(arr, n);
    int ans = -1;

    while(start <= end) {
        int mid = start + (end-start)/2;
        int isPossible = isPossibleSolution(arr, n, wood, mid);
        if(isPossible) {
            ans = mid;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return ans;
}

int main() {
    int arr[4] = {20,15,10,17};
    int n = 4;
    int wood = 7;

    int ans = ecoSpoj(arr, n, wood);
    cout<<"Answer is - "<<ans<<endl;

    return 0;
}
*/


// ****** EKO SPOJ ********
/*
#include <iostream>
#include <vector>
using namespace std;

int maxNum(vector<int> arr) {
    int max = INT8_MIN;

    for(auto val: arr) {
        if(val>max) {
            max = val;
        }
    }
    return max;
}

bool isPoosible(vector<int> arr, int wood, int mid) {
    int sum = 0;

    for(int i=0; i<arr.size(); i++) {
        if(arr[i] >= mid) {
            sum += arr[i] - mid;
        }
    }
    if(sum >= wood) {
        return true;
    }
    return false;
}

int ecoSPoj(vector<int> arr, int wood) {
    int start = 0;
    int end = maxNum(arr);
    int ans = -1;
    while(start <= end) {
        int mid = start + (end - start)/2;
        if(isPoosible(arr, wood, mid)) {
            ans = mid;
            start = mid + 1; 
        }
        else {
            end = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr{20,15,10,17};
    int wood = 7;

    int ans = ecoSPoj(arr, wood);
    cout<<"Answer is - "<<ans<<endl;

    return 0;
}
*/


// ******** PRATA SPOJ *******
/*
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int maxTime(vector<int> arr, int prata) {
    int max = INT8_MIN;
    for(int i=0; i<arr.size(); i++) {
        if(arr[i]>max) max=arr[i];
    }
    int maxTimeTaken = max*prata*(prata+1)/2;
    return maxTimeTaken;
}

bool isPossible(vector<int> arr, int prata, int mid) {
    int prataCount = 0;
    for(int i=0; i<arr.size(); i++) {
        int timeTaken = 0;
        int rank = arr[i];
        int step = 1;
        while(timeTaken + step * rank <= mid) {
            timeTaken += step*rank;
            prataCount++;
            step++;
        }
    }
    if(prataCount >= prata) {
        return true;
    }
    return false;
}

int prataSpoj(vector<int> arr, int prata) {
    int start = 0;
    int end = maxTime(arr, prata);
    int ans = -1;

    while(start <= end) {
        int mid = start + (end-start)/2;
        if(isPossible(arr, prata, mid)) {
            ans = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
}

int main() {
    vector<int> arr{1};
    int prata = 8;
    sort(arr.begin(), arr.end());
    int ans = prataSpoj(arr, prata);
    cout<<"Answer is - "<<ans<<endl;

    return 0;
}
*/


// ******** PRATA SPOJ **********
/*
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool isPossibleSolution(vector<int> arr, int mid, int prata) {
    int prataCount = 0;
    
    for (int i=0; i<arr.size(); i++) {
        int timeTaken = 0;
        int rank = arr[i];
        int step = 1;
        while(rank * step + timeTaken <= mid) {
            prataCount++;
            timeTaken += rank * step;
            step++;
        }
    }
    if(prataCount >= prata) {
        return true;
    }
    return false;
}

int prataSpoj(vector<int> arr, int prata) {
    sort(arr.begin(), arr.end());
    int start = 0;
    int end = arr[arr.size()-1] * prata * (prata+1) /2;
    int ans = -1;

    while(start <= end) {
        int mid = start + (end - start) / 2;
        bool flag = isPossibleSolution(arr, mid, prata);
        if(flag) {
            ans = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr{1, 1, 1, 1, 1, 1, 1, 1};
    int prata = 8;

    int ans = prataSpoj(arr, prata);
    cout<<"Answer is "<<ans<<endl;

    return 0;
}
*/