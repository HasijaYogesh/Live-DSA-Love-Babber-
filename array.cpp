
/*
#include <iostream>
using namespace std;

int main() {

    int arr[500];

    int n;
    cout<<"How many numbers you want to enter?"<<endl;
    cin>>n;

    cout<<"Enter the numbers"<<endl;
    for(int i=0;i<n; i++) {
        cin>>arr[i];
    }

    cout<<"Doubles are :-"<<endl;
    for(int i=0;i<n;i++) {
        cout<<2*arr[i]<<" ";
    }

    return 0;
}
*/

/*
#include <iostream>
using namespace std;

int main() {

    int arr[5] = {1,3,5,7,9};

    for(int i=0; i<5;i++) {
        arr[i]=1;
    }

    for(int i=0;i<5;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
*/

/*
#include <iostream>
using namespace std;

int main() {

    int arr[] = {0,0,1,0,1,1,1,0,1,0,1,0,1,0,1};

    int size = 15;
    int numZero = 0;
    int numOne = 0;

    for(int i=0; i<size; i++) {
        if(arr[i]==0) numZero++;
        if(arr[i]==1) numOne++;
    }

    cout<<"Zeros are "<<numZero<<endl;
    cout<<"Ones are "<<numOne<<endl;

    return 0;
}
*/

/*
#include <iostream>
using namespace std;

int main() {
    int arr[11] = {0,8,3,6,9,15,48,96,36,105,85};
    int size = 11;
    int maxNum = INT8_MIN;
    int minNum = INT8_MAX;

    for(int i=0;i<size;i++) {
        if(arr[i]>maxNum) {
            maxNum = arr[i];
        }
        if(arr[i]<minNum) {
            minNum = arr[i];
        }
    }

    cout<<"Max Number is "<<maxNum<<endl;
    cout<<"Min Number is "<<minNum<<endl;

    return 0;
}
*/

/*
#include <iostream>
using namespace std;

int main()
{
    int arr[7] = {10, 20, 30, 40, 50, 60, 70};
    int size = 7;

    int start = 0;
    int end = size - 1;

    while (start <= end)
    {
        if (start == end)
        {
            cout << arr[start] << endl;
            break;
        }
        else
        {
            cout << arr[start] << " " << arr[end] << endl;
            start++;
            end--;
        }
    }

    return 0;
}
*/


/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[6] = {10,20,30,40,50,60};
    int size = 6;
    int start = 0;
    int end = size-1;

    while(start<=end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }

    for(int i=0; i<size;i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}
*/


/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // create vector
    vector<int> arr;

    int ans = (sizeof(arr)/sizeof(int));

    cout<<"Ans - "<<ans<<endl;
    cout<<"Size of arr - "<<arr.size()<<endl;
    cout<<"Capacity - "<<arr.capacity()<<endl;

    arr.push_back(5);
    arr.push_back(6);

    for(int i=0; i<arr.size();i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    arr.pop_back();

    for(int i=0; i<arr.size();i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    vector<int> brr(10, -101);
    cout<<"Size of brr - "<<brr.size()<<endl;
    cout<<"Capacity of brr - "<<brr.capacity()<<endl;

    return 0;
}
*/


/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> crr{10,20,30,40,50};

    for(int i=0; i<crr.size();i++) {
        cout<<crr[i]<<" ";
    }
    cout<<endl;

    cout<<"crr is empty - "<<crr.empty()<<endl;

    vector<int> drr;
    cout<<"drr is empty - "<<drr.empty()<<endl;

    return 0;
}
*/


/*
#include <iostream>
#include <vector>
using namespace std;

int findUnique(vector<int> arr) {
    int ans = 0;

    for(int i=0;i<arr.size();i++) {
        ans = ans ^ arr[i];
    }

    return ans;
}

int main() {
    int n;
    cout<<"Enter N"<<endl;
    cin>>n;

    vector<int> arr(n);

    cout<<"Enter the elements - "<<endl;
    for(int i=0; i<arr.size();i++) {
        cin>>arr[i];
    }

    int uniqueEle = findUnique(arr);

    cout<<"Unique element is - "<<uniqueEle<<endl;


    return 0;
}
*/


/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr{1,2,3,4};
    vector<int> brr{5,6};
    vector<int> crr;
    for(int i=0;i<arr.size();i++) {
        crr.push_back(arr[i]);
    }
    for(int i=0;i<brr.size();i++) {
        crr.push_back(brr[i]);
    }
    for(int i=0;i<crr.size();i++) {
        cout<<crr[i]<<" ";
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
    vector<int> arr{1,2,3,3,4,5,6};
    vector<int> brr{9,3,3,8,11,4};

    vector<int> ans;

    for(int i=0; i<arr.size();i++) {
        int ele = arr[i];
        for(int j=0; j<brr.size();j++) {
            if(ele == brr[j]) {
                brr[j] = -1;
                ans.push_back(ele);
            }
        }
    }

    for(auto value: ans) {
        cout<<value<<" ";
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
    
    vector<int> arr{10,20,40,60,70};

    for(int i=0; i<arr.size();i++) {
        int element = arr[i];

        for(int j=i+1; j<arr.size();j++) {
            if(arr[j]+element == 80) {
                cout<<"Pair with sum 80 is - ("<<element<<","<<arr[j]<<")"<<endl;
            }
        }
    }

    return 0;
}
*/


/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr{10,20,30,40};
    int sum = 100;
    for(int i=0;i<arr.size();i++) {
        int ele1 = arr[i];
        for(int j=i+1;j<arr.size();j++) {
            int ele2 = arr[j];
            for(int k=j+1;k<arr.size();k++) {
                int ele3 = arr[k];
                for(int l=k+1;l<arr.size();l++) {
                    int ele4 = arr[l];
                    if(ele1+ele2+ele3+ele4 == sum) {
                    cout<<"4 numbers eqauls to sum are - ("<<ele1<<","<<ele2<<","<<ele3<<","<<ele4<<")"<<endl;
                    }
                }
            }
        }
    }    
    return 0;
}
*/


/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr{0,1,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,1,0,1,1,0};
    int start = 0;
    int end = arr.size()-1;
    int i = 0;

    while(start<end) {
        if(arr[i]==0) {
            //swap from left
            swap(arr[start++],arr[i++]);
        }
        else if(arr[i]==1) {
            //swap from end
            swap(arr[end--],arr[i]);
        }
    }

    for(auto value: arr) {
        cout<<value<<" ";
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
    vector<int> arr{0,1,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,1,0,1,1,0};
    int start = 0;
    int end = arr.size()-1;
    
    while(start<end) {
        if(arr[start]==1) {
            swap(arr[start],arr[end]);
            end--;
        }
        else {
            start++;
        }
    }
    for(auto value: arr) {
        cout<<value<<" ";
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
    int arr[3][3];

    int brr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    cout<<"Row wise print"<<endl;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cout<<brr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Column wise print"<<endl;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cout<<brr[j][i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
*/


/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    int arr[4][3];
    int rows = 4, col = 3;

    cout<<"Row wise input"<<endl;
    for(int i=0;i<rows;i++) {
        for(int j=0;j<col;j++) {
            cin>>arr[i][j];
        }
    }
    cout<<"Print row wise"<<endl;
    for(int i=0; i<rows;i++) {
        for(int j=0;j<col;j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
*/


/*
#include <iostream>
#include <vector>
using namespace std;

void printRowWiseSum(int arr[][4], int rows, int cols) {
    // row sum -> row wise traversal
    for(int i=0;i<rows;i++) {
        int sum = 0;
        for(int j=0; j<cols;j++) {
            sum = sum + arr[i][j];
        }
        cout<<sum<<endl;
    }
}

int main() {
    int arr[5][4] = {{1,2,3,4},{2,3,4,1},{5,6,1,3},{2,4,6,8},{1,9,9,6}};

    // for(int i=0; i<5;i++) {
    //     int sum=0;
    //     for(int j=0;j<4;j++) {
    //         sum += arr[i][j];
    //     } 
    //     cout<<"Sum of Row "<<i+1<<" is "<<sum<<endl;
    // }

    // with function
    printRowWiseSum(arr, 5, 4);
    return 0;
}
*/


/*
#include <iostream>
using namespace std;

int main() {
    int arr[][3] = 
    {{1,2,3},
    {5,6,0},
    {7,8,7}};

    for(int i=0; i<3;i++) {
        int sum=0;
        for(int j=0;j<3;j++) {
            sum += arr[j][i];
        } 
        cout<<"Sum of Col "<<i+1<<" is "<<sum<<endl;
    }

    return 0;
}
*/


/*
#include <iostream>
#include <vector>
using namespace std;

bool findKey(int arr[][3], int rows, int cols, int key) {
    for(int i=0; i<rows;i++) {
        for(int j=0;j<cols;j++) {
            if(arr[i][j] == key) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int arr[][3] = 
    {{1,2,3},
    {5,6,0},
    {7,8,7}};

    if(findKey(arr, 3, 3, 17)) {
        cout<<"True"<<endl;
    }
    else {
        cout<<"False"<<endl;
    }

    return 0;
}
*/


/*
#include <iostream>
#include <limits.h>
using namespace std;

int getMax(int arr[][3], int rows, int cols){
    int maxi = INT8_MIN;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols;j++) {
            if(arr[i][j]>maxi) {
                maxi = arr[i][j];
            }
        }
    }
    return maxi;
}

int getMin(int arr[][3], int rows, int cols){
    int mini = INT8_MAX;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols;j++) {
            if(arr[i][j]<mini) {
                mini = arr[i][j];
            }
        }
    }
    return mini;
}

int main() {
    
    int arr[][3] = 
    {{1,2,3},
    {5,6,1},
    {7,11,7}};

    cout<<getMax(arr, 3, 3)<<endl;
    cout<<getMin(arr, 3, 3)<<endl;

    return 0;
}
*/


/*
#include <iostream>
using namespace std;

void transpose(int arr[][3], int r, int c, int trans[][3]) {
    for(int i=0; i<r; i++) {
        for(int j=0; j<c;j++) {
            trans[i][j] = arr[j][i];
        }
    }
}

void printArr(int arr[][3], int r, int c) {
    for(int i=0; i<r;i++) {
        for(int j=0;j<c;j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    
    int arr[][3] = 
    {{1,2,3},
    {4,5,6},
    {7,8,9}};

    cout<<"Print actual array :-"<<endl;
    printArr(arr, 3, 3);
    int trans[3][3];
    transpose(arr, 3, 3, trans);
    cout<<"Printing Transpose Array :-"<<endl;
    printArr(trans, 3, 3);

    return 0;
}
*/


/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    vector<vector<int> >arr;

    vector<int>a{1,2,3};
    vector<int>b{2,4,6,4,8};
    vector<int>c{1,3,7};

    arr.push_back(a);
    arr.push_back(b);
    arr.push_back(c);

    for(int i=0; i<arr.size();i++) {
        for(int j=0; j<arr[i].size();j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
*/


/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int row = 3;
    int col = 5;
    vector<vector<int> >arr(row,vector<int>(col,101));
    for(int i=0; i<arr.size();i++) {
        for(int j=0; j<arr[i].size();j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
*/

/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int>arr{2,5,3,6,9,9,7};

    for(int i=0; i<arr.size();i++) {
        for(int j=i+1;j<arr.size();j++) {
            if(arr[i]==arr[j]) {
                cout<<"Duplicate element is - "<<arr[j];
                break;
            }
        }
    }

    return 0;
}
*/


/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int>arr{5,-8,6,8,-3,5};

    int start = 0, end = arr.size()-1;

    while(start<=end) {
        if(arr[start]>0) {
            swap(arr[start],arr[end--]);
        }
        else if(arr[start]<0){
            start++;
        }
    }

    for(auto value: arr) {
        cout<<value<<" ";
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
    vector<int>arr{0,1,0,2,1,2,0,2,0,1,2,0};

    int start = 0;
    int mid = 0;
    int end = arr.size()-1;

    while(mid<=end) {
        if(arr[mid]==0) {
            swap(arr[start], arr[mid]);
            start++;
            mid++;
        }
        else if(arr[mid]==2) {
            swap(arr[mid],arr[end]);
            end--;
        }
        else if(arr[mid]==1) {
            mid++;
        }
    }

    for(auto value:arr) {
        cout<<value<<" ";
    }
    cout<<endl;

    return 0;
}
*/


/*
#include <iostream>
using namespace std;

int main() {
    int n = 15;
    int k = 3;
    int mask = 1 << k;
    int ans = n | mask;
    cout<<ans<<endl;

    return 0;
}
*/


/*
#include <iostream>
using namespace std;

void rotateArray(int arr[], int size) {
    int first = arr[0];

    for(int i=0;i<size;i++) {
        arr[i] = arr[i+1];
    }

    arr[size-1] = first;
}

void printArray(int arr[], int size) {
    for(int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int arr[10]={11,12,13,14,15,16,17,18,19,20};
    int size = 10;
    int rotate;
    cout<<"Enter number of rotation - "<<endl;
    cin>>rotate;

    cout<<"Array before Rotating :-"<<endl;
    printArray(arr, 10);

    for(int i=0;i<rotate;i++) {
        rotateArray(arr, 10);
    }
    
    cout<<"Array after Rotating :-"<<endl;
    printArray(arr, 10);

    return 0;
}
*/


/*
#include <iostream>
using namespace std;

int main() {
    int arr[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    for(int i=0; i<9; i++) {
        for(int j=i; j<3; j++) {
            if(i!=j) {
                swap(arr[i][j],arr[j][i]);
                cout<<"Swaping of "<<i<<" & "<<j<<endl;
                cout<<"Valriables are "<<arr[i][j]<<" & "<<arr[j][i]<<endl;
            }
        }
    }

    for(int i=0; i<3; i++) {
        for(int j=0; j<3/2; j++) {
            swap(arr[i][3-j-1], arr[i][j]);
        }
    }

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cout<<arr[i][j]<<" ";
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
    int arr[8] = {3,1,4,8,7,2,13,5};
    int size = 8;
    int min = arr[0];
    int profit = 0;

    for(int i=0; i<size; i++) {
        if(arr[i]<min) {
            min = arr[i];
        }
        if((arr[i]-min)>profit) {
            profit = arr[i]-min;
        }
    }

    cout<<"Maximum Profit is "<<profit<<endl;

    return 0;
}
*/


/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int arr[6] = {1,2,3,4,5,5};
    int brr[5] = {6,9,8,5,1};
    int crr[5] = {1,10,85,96,5};

    vector<int> v;

    for(int i=0; i<6; i++) {
        for(int j=0; j<5; j++) {
            if(arr[i]==brr[j]) {
                for(int k=0; k<5; k++) {
                    if(arr[i]==brr[j] && arr[i]==crr[k]) {
                        cout<<arr[i]<<" ";
                        brr[j] = INT8_MIN;
                        crr[k] = INT8_MIN;
                    }
                }
            }
        }
    }

    return 0;
}
*/


/*
#include <iostream>
#include <vector>
using namespace std;

void spiralPrint(int arr[][4], int row, int col) {
    int top = 0;
    int bottom = col - 1;
    int left = 0;
    int right = row-1;
    int dir = 0;

    while(top<=bottom && row<=col) {
        if(dir==0) {
            for(int i=top;i<=right;i++) {
                cout<<arr[top][i]<<" ";
                top++;
            }
        }
        else if(dir==1) {
            for(int i=top;i<=bottom;i++) {
                cout<<arr[i][right]<<" ";
            }
        }
        else if(dir==2) {
            for(int i=right; i>=left;i--) {
                cout<<arr[left][i]<<" ";
                right--;
            }
        }
        else if(dir==3) {
            for(int i=bottom; i>=top; i--) {
                cout<<arr[top][i];
                bottom--;
            }
        }
        dir = (dir+1) % 4;
    }
}

void printArray(int arr[][10], int row, int col) {
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int arr[5][5] = {
        { 1, 2, 3, 4, 5},
        { 5, 6, 7, 8, 2},
        { 9,10,11,12,16},
        {13,14,15,16,25},
        {26,27,28,29,30}
    };
    int row = 5, col = 5;
    int top = 0;
    int bottom = col - 1;
    int left = 0;
    int right = row - 1;
    int dir = 0;

    while(top<=bottom) {
        if(dir==0) {
            for(int i=left;i<=right;i++) {
                cout<<arr[top][i]<<" ";
            }
            top++;
        }
        else if(dir==1) {
            for(int i=top;i<=bottom;i++) {
                cout<<arr[i][right]<<" ";
            }
            right--;
        }
        else if(dir==2) {
            for(int i=right; i>=left;i--) {
                cout<<arr[bottom][i]<<" ";
            }
            bottom--;
        }
        else if(dir==3) {
            for(int i=bottom; i>=top; i--) {
                // cout<<"i "<<i<<" top "<<top<<endl;
                cout<<arr[i][top-1]<<" ";
            }
            left++;
        }
        dir = (dir+1) % 4;
    }

    return 0;
}
*/


/*
#include <iostream>
using namespace std;

int main() {
    int arr[5][5] = {
        { 1, 2, 3, 4, 5},
        { 5, 6, 7, 8, 2},
        { 9,10,11,12,16},
        {13,14,15,16,25},
        {26,27,28,29,30}
    };
    int cols = 5;
    int rows = 5;
    for(int col=0; col<cols; col++) {
        if(col%2==0) {
            for(int row=0; row<rows; row++) {
            cout<<arr[row][col]<<" ";
            }
        }
        else {
            for(int row=rows-1; row>=0; row--) {
            cout<<arr[row][col]<<" ";
            }
        }        
    }
    return 0;
}
*/


/*
#include <iostream>
using namespace std;

void moveAllNegToLeft(int* a, int n) {
    // Dutch national flag algo.
    int l = 0, h = n - 1;
    while(l<h) {
        if(a[l]<0) {
            l++;
        }
        else if(a[h]>0) {
            h--;
        }
        else {
            swap(a[l],a[h]);
        }
    }
}

int main() {
    int a[] = {1,2,-3,4,-5,6};
    int n = sizeof(a)/sizeof(int);

    moveAllNegToLeft(a, n);

    for(int i=0; i<n; i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    return 0;
}
*/


/*
#include <iostream>
using namespace std;

void findMissing(int *a, int n) {
    //visited method
    for(int i=0;i<n;i++) {
        int index = abs(a[i]);
        if(a[index-1]>0) {
            a[index-1] *= -1;
        }
    }

    for(int i=0;i<n;i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    for(int i=0;i<n;i++) {
        if(a[i]>0) {
            cout<<i+1<<" ";
        }
    }
}

int main() {
    int n;
    int a[]={1,3,5,3,4};
    n = sizeof(a)/sizeof(int);
    findMissing(a,n);

    return 0;
}
*/


/*Find common element in thre sorted array*/
/*
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    vector<int> arr{1,5,10,20,40,80,80};
    vector<int> brr{6,7,20,80,100,80};
    vector<int> crr{3,4,15,20,30,70,80,80,120};
    int i = 0, j = 0, k = 0;
    set<int> ans;
    while(i<arr.size() && j<brr.size() && k<crr.size()) {
        if(arr[i] == brr[j] && brr[j] == crr[k]) {
            ans.insert(arr[i]);
            i++;
            j++;
            k++;
        }
        else if(arr[i]<brr[j]) {
            i++;
        }
        else if(brr[j]<crr[k]) {
            j++;
        }
        else {
            k++;
        }
    }
    for(auto value: ans) {
        cout<<value<<" ";
    }
    cout<<endl;
    return 0;
}
*/


/*Print 2d array in wave pattern*/
/*
#include <iostream>
#include <vector>
using namespace std;

void wavePrintMatrix(vector<vector<int>> v) {
    int m = v.size();
    int n = v[0].size();

    for(int startCol=0; startCol<n; startCol++) {
        // even no. of col -> top to bottom
        if((startCol & 1)==0) {
            for(int i=0; i<m; i++) {
                cout<<v[i][startCol]<<" ";
            }
        }
        else {
            // odd number of col -> bottom to top
            for(int i=m-1; i>=0; i--) {
                cout<<v[i][startCol]<<" ";
            }
        }
    }
}

int main() {
    vector<vector<int>> v {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16},
        {17,18,19,20}
    };

    wavePrintMatrix(v);


    return 0;
}
*/


/*spiral print a 2d array*/
/*
#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> matrix) {
    vector<int> ans;
    int m=matrix.size();
    int n=matrix[0].size();
    int total_element = m*n;

    int startingRow = 0;
    int endingCol = n-1;
    int endingRow = m-1;
    int startingCol = 0;

    int count = 0;
    while(count<total_element) {
        //print starting row
        for(int i=startingCol;i<=endingCol && count<total_element;i++) {
            ans.push_back(matrix[startingRow][i]);
            count++;
        }
        startingRow++;
        //print ending col
        for(int i=startingRow;i<=endingRow && count<total_element;i++) {
            ans.push_back(matrix[i][endingCol]);
            count++;
        }
        endingCol--;
        //print ending row
        for(int i=endingCol;i>=startingCol && count<total_element;i--) {
            ans.push_back(matrix[endingRow][i]);
            count++;
        }
        endingRow--;
        //print starting col
        for(int i=endingRow;i>=startingRow && count<total_element;i--) {
            ans.push_back(matrix[i][startingCol]);
            count++;
        }
        startingCol++;
    }
    return ans;
}

int main() {
    vector<vector<int>> arr = {
        { 1, 2, 3, 4, 5, 6},
        { 7, 8, 9,10,11,12},
        {13,14,15,16,17,18},
        {19,20,21,22,23,24},
        {25,26,27,28,29,30}
    };
    
    vector<int> ans = spiralOrder(arr);

    for(auto i: ans) {
        cout<<i<<" ";
    }

    return 0;
}
*/


/*find the factorial of large number*/
/*
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> factorial(int N) {
    vector<int> ans;
    ans.push_back(1);
    int carry = 0;

    for(int i=2; i<=N; i++) {
        for(int j=0; j<ans.size();j++) {
            int x = ans[j]*i+carry;
            ans[j] = x%10;
            carry = x/10;
        }
        while(carry) {
            ans.push_back(carry%10);
            carry/=10;
        }
        carry = 0;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main() {
    int N = 100;
    vector<int> ans = factorial(N);

    for(auto i: ans) {
        cout<<i;
    }cout<<endl;

    return 0;
}
*/

/*
#include <iostream>
using namespace std;

int main() {
    int arr[5];
    cout<<"Enter the value in array - "<<endl;
    for (int i=0; i<5; i++) {
        cin >> arr[i];
    }
    for (int i=0; i<5; i++) {
        cout << arr[i] * 2<< " ";
    }

    return 0;
}
*/

// **********FIND UNIQUE ELEMENT ***********             
/*
#include <iostream>
#include <vector>
using namespace std;

int findUnique(vector<int> arr) {
    int ans = 0;

    for(int i=0; i<arr.size(); i++) {
        ans = ans ^ arr[i];
    }

    return ans;
}

int main() {
    int n;
    cout<< "Enter the size of array "<<endl;
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter the elements "<<endl;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    int uniqueElement = findUnique(arr);
    cout<< "Unique element is "<<uniqueElement<<endl;

    return 0;
}
*/


// ************** UNION OF TWO ARRAYS ***************
/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int arr[] = {1,3,5,7,9};
    int sizeA = 5;
    int brr[] = {2,4,6,8};
    int sizeB = 4;

    vector<int> ans;

    for(int i=0; i<sizeA; i++) {
        ans.push_back(arr[i]);
    }
    for(int i=0; i<sizeB; i++) {
        ans.push_back(brr[i]);
    }

    for(auto val: ans) {
        cout<<val<<" ";
    }

    return 0;
}
*/


// ********** INTERSECTION OF ARRAY ******
/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr{1,2,3,3,4,5,6,8};
    vector<int> brr{3,3,4,10};
    vector<int> ans;

    for(int i=0; i<arr.size();i++) {
        int element = arr[i];
        for(int j=0; j<brr.size(); j++) {
            if(brr[j] == element) {
                ans.push_back(element);
                // Marking that the element is already checked
                brr[j] = -1;
            }
        }
    }

    for(auto val: ans) {
        cout<<val<<" ";
    } cout<<endl;


    return 0;
}
*/


// ************ PAIR SUM IN ARRAY *************
/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr{10,20,40,60,70};
    int target = 80;
    //outer loop will traverse for each element
    for(int i=0; i<arr.size(); i++) {
        int element = arr[i];
        
        // for every element, will traverse on elements which are ahead of that element
        for(int j=i+1; j<arr.size(); j++) {
            if(element + arr[j] == target) {
                cout<<"Pair is - "<<arr[i]<<","<<arr[j]<<endl;
            }
        }
    }

    return 0;
}
*/


/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr{10,20,30,40,50,60};
    int size = arr.size();
    int sum = 100;
    for(int i=0; i<size; i++) {
        for(int j=i+1; j<size; j++) {
            for(int k=j+1; k<size; k++) {
                for(int l=k+1; l<size; l++) {
                    if(arr[i]+arr[j]+arr[k]+arr[l] == sum) {
                        cout<<arr[i]<<","<<arr[j]<<","<<arr[k]<<","<<arr[l]<<endl;
                    }
                }
            }
        }
    }

    return 0;
}
*/


// ********* SORT 0s AND 1s *********
/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr{1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0};

    int start = 0;
    int end = arr.size() - 1;

    while(start<=end) {
        if(arr[start]==1) {
            swap(arr[start],arr[end]);
            end--;
        }
        if(arr[end]==1) {
            end--;
        }
        if(arr[start]==0) {
            start++;
        }
    }

    for(auto val : arr) {
        cout<<val<<" ";
    }cout<<endl;

    return 0;
}
*/


// ******** 2D ARRAYs **********
/*
#include <iostream>
using namespace std;

int main() {
    int brr[3][3] = {{1,2,3},{4,5,6},{2,4,8}};
    // Row wise print
    // outer loop
    for(int i=0; i<3; i++) {

        // inner loop, we need to print value in each column
        for(int j=0; j<3; j++) {
            cout<<brr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    // Column wise print
    // outer loop
    for(int i=0; i<3; i++) {

        // inner loop, we need to print value in each column
        for(int j=0; j<3; j++) {
            cout<<brr[j][i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
*/


//
/*
#include <iostream>
using namespace std;

int main() {
    int brr[3][3] = {
    {1,2,3},
    {5,6,0},
    {7,8,7}};

    for(int i=0; i<3; i++) {
        int sum = 0;
        for(int j=0; j<3; j++) {
            sum = sum + brr[j][i];
        }
        cout<<"Sum is "<<sum<<endl;
    }

    return 0;
}
*/


// ******* LINEAR SEARCH IN 2D ARRAY **********
/*
#include <iostream>
using namespace std;

bool findKey(int arr[][3], int rows, int cols, int key) {
    for(int i=0; i<rows; i++) {

        for(int j=0; j<cols; j++) {
            if(arr[i][j] == key) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int brr[3][3] = {{1,2,3},{1,3,7},{4,6,8}};

    cout<< findKey(brr, 3, 3, 3);


    return 0;
}
*/


// ******* FIND MINIMUM AND MAXIMUM ELEMENT IN 2D ARRAY *********
/*
#include <iostream>
using namespace std;

int findMax(int arr[][4], int rows, int cols) {
    int max = INT8_MIN;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if(arr[i][j]>max) {
                max = arr[i][j];
            }
        }
    }
    return max;
}

int findMin(int arr[][4], int rows, int cols) {
    int min = INT8_MAX;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if(arr[i][j]<min) {
                min = arr[i][j];
            }
        }
    }
    return min;
}


int main() {
    int crr[4][4] = {{-11,2,3,4},{5,6,7,8},{9,99,11,12},{13,14,55,16}};

    int max = findMax(crr, 4, 4);

    int min = findMin(crr, 4, 4);

    cout<<"Maximum element is "<<max<<endl;
    cout<<"Minimum element is "<<min<<endl;

    return 0;
}
*/


// ********* LINEAR SEARCH 2D ARRAY **********
/*
#include <iostream>
using namespace std;

bool findKey(int arr[][3], int rows, int cols, int key) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if(arr[i][j] == key) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

    int ans = findKey(arr, 3, 3, 10);
    if(ans) {
        cout<<"Found"<<endl;
    }
    else {
        cout<<"Not found"<<endl;
    }

    return 0;
}
*/


// ******** TRANSPOSE AN ARRAY *********
/*
#include <iostream>
using namespace std;

void printArray(int arr[][3], int row, int col) {
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cout<<arr[i][j]<< " ";
        } cout<<endl;
    }
    cout<<endl;
}

void transpose(int arr[][3], int row, int col, int brr[][3]) {
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
          brr[j][i] = arr[i][j];
        } 
    }
}

int main() {
    int arr[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}};

    printArray(arr, 3, 3);

    int brr[3][3];
    transpose(arr, 3, 3, brr);

    printArray(brr, 3, 3);

    return 0;
}
*/


// ******** 2D VECTOR / VECTOR OF VECTOR ********
/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int> >arr;

    vector<int> a{1,2,3};
    vector<int> b{2,4,6,8,2,9};
    vector<int> c{1,3};

    arr.push_back(a);
    arr.push_back(b);
    arr.push_back(c);

    for(int i=0; i<arr.size(); i++) {
        for(int j=0; j<arr[i].size(); j++) {
            cout<<arr[i][j]<< " ";
        }cout<<endl;
    }

    return 0;
}
*/


/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int> > arr(5, vector<int> (5, -8));

    for(int i=0; i<arr.size(); i++) {
        for(int j=0; j<arr[i].size(); j++) {
            cout<<arr[i][j]<< " ";
        }cout<<endl;
    }

    return 0;
} 
*/


// ****** SORT 0s, 1s & 2s IN AN ARRAY *********
/*
#include <iostream>
using namespace std;

int main() {
    int arr[] = {0,2,0,2,1,0,1,2,0,1};
    int s = 0;
    int i = 0;
    int e = 9;
    while(i<=e) {
        if (arr[i]==0) {
            swap(arr[i],arr[s]);
            i++;
            s++;
        }
        else if(arr[i] == 1) {
            i++;
        }
        else if(arr[i] == 2) {
            swap(arr[i],arr[e]);
            e--;
        }
    }
    for(int i=0; i<10; i++) {
        cout<<arr[i]<<" ";
    } cout<<endl;
    return 0;
}
*/


// ******* MOVE ALL NEGATIVE TO LEFT **********
/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr{2,8,1,-1,-3,1,-9,5,2,-6,6,-5,8,5,1,-10};
    int s = 0;
    int e = arr.size() - 1;
    while(s<=e) {
        if (arr[s] < 0) {
            s++;
        }
        if (arr[s] >= 0) {
            swap(arr[s],arr[e]);
            e--;
        }
    }
    for(auto val: arr) {
        cout<<val<<" ";
    } cout<<endl;

    return 0;
}
*/


// ****** FIND THE REPEATING ELEMENT IN AN ARRAY *******
/*
#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int>& nums) {
    
    while(nums[0] != nums[nums[0]]) {
        swap(nums[0],nums[nums[0]]);
    }
    return nums[0];

}

int main() {
    
    vector<int> arr{4,1,3,4,2};

    cout<<"Ans is - "<<findDuplicate(arr)<<endl;


    return 0;
}
*/


// *********** FIND MISSING ELEMENT IN AN ARRAY (VISITED METHOD) *********
/*
#include <iostream>
using namespace std;

void findMissing(int a[], int n) {
    // visited method
    for(int i=0; i<n; i++) {
        int index = abs(a[i]);
        if(a[index-1] > 0) {
            a[index-1] *= -1;
        }
    }

    for(int i=0; i<n; i++) {
        cout<<a[i]<<" ";
    } cout<<endl;

    for(int i=0; i<n; i++) {
        if(a[i] > 0) {
            cout<<i+1<<" ";
        }
    }
}

int main() {
    int n;
    int a[] = {1,3,3,3,4};
    n = sizeof(a)/sizeof(int);

    findMissing(a, n);


    return 0;
}
*/


// *********** FIND MISSING ELEMENT IN AN ARRAY (CORRECT POSITION AS INDEX) *********
/*
#include <iostream>
using namespace std;

void findMissing(int a[], int n) {
    int i=0;
    while(i<n) {
        int index = a[i] - 1;

        if(a[i] != a[index]) {
            swap(a[i],a[index]);
        }
        else {
            i++;
        }
    }
    for(int i=0; i<n; i++) {
        if(a[i] != i+1) {
            cout<<i+1<<" ";
        }
    }
}

int main() {
    int n;
    int a[] = {1,3,5,3,4};
    n = sizeof(a)/sizeof(int);

    findMissing(a, n);

    return 0;
}
*/


// ******* FIND THE FIRST REPEATED ELEMENT INDEX **********
/*
#include <iostream>
#include <vector>
using namespace std;

int findRepeatedElement(vector<int> arr) {
    for(int i=0; i<arr.size();i++) {
        for(int j=i+1; j<arr.size(); j++) {
            if(arr[i]==arr[j]) {
                return i+1;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> arr{1,2,3,4,5,6,7,2,4};

    cout<< "Ans is "<<findRepeatedElement(arr)<<endl;


    return 0;
}
*/


// ********** FIND FIRST REPEATED ELEMENT IN AN ARRAY *********
/*
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int firstRepeated(vector<int> a) {
    unordered_map<int, int> hash;
    for(int i=0; i<a.size(); i++) {
        hash[a[i]]++;
    }
    for(int i=0; i<a.size(); i++) {
        if(hash[a[i]] > 1) {
            return i+1;
        }
    }
    return -1;
} 

int main() {
    vector<int> arr{1,2,3,4,5,6,7,4};
    cout<< "Ans is "<<firstRepeated(arr)<<endl;

    return 0;
}
*/


// ******** FIND COMMON ELEMENT IN THREE SORTED ARRAYS ***********
/*
#include <iostream>
#include <vector>
#include <set>
using namespace std;

set<int> findCommonElement(vector<int> arr, vector<int> brr, vector<int> crr) {

    set<int> drr;
    int i = 0, j = 0, k = 0;
    
    while(i<arr.size() && j<brr.size() && k<crr.size()) {
        if(arr[i] == brr[j] && arr[i] == crr[k]) {
            drr.insert(arr[i]);
            i++;
            j++;
            k++;
        }
        else if(arr[i] < brr[j] && arr[i] < crr[k]) {
            i++;
        }
        else if(brr[j] < arr[i] && brr[j] < crr[k]) {
            j++;
        }
        else if(crr[k] < arr[i] && crr[k] < brr[j]) {
            k++;
        }
    }
    return drr;
}

int main() {
    vector<int> arr{1,5,10,20,20,40,80,80};
    vector<int> brr{6,7,20,20,80,80,100};
    vector<int> crr{3,4,15,20,20,30,70,80,80,120};

    set<int> drr = findCommonElement(arr, brr, crr);
    for(auto val : drr) {
        cout<<val<<" ";
    }

    return 0;
}
*/


// ******** WAVE PRINT AN ARRAY COLUMN WISE **********
/*
#include <iostream>
#include <vector>
using namespace std;

void wavePrint(vector<vector<int> > arr) {
    for(int i=0; i<arr[0].size(); i++) {
        // even number of column - top to bottom
        if((i & 1) == 0) {
            for(int j=0; j<arr.size(); j++) {
            cout<<arr[j][i]<<" ";
        }
        cout<<endl;
        }
        // odd number of column - bottom to top 
        else {
            for(int j=arr.size()-1; j>=0; j--) {
                cout<<arr[j][i]<< " ";
            }
            cout<<endl;
        }
    }
}

int main() {
    vector<vector<int> > arr{
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };

    wavePrint(arr);

    return 0;
}
*/


// ******** WAVE PRINT AN ARRAY ROW WISE **********
/*
#include <iostream>
#include <vector>
using namespace std;

void wavePrint(vector<vector<int> > arr) {
    for(int i=0; i<arr.size(); i++) {
        if((i & 1) == 0 ) {
            for(int j=0; j<arr[0].size(); j++) {
                cout<<arr[i][j]<< " ";
            } cout<<endl;
        }
        else {
            for(int j=arr[0].size()-1; j>=0; j--) {
                cout<<arr[i][j]<< " ";
            } cout<<endl;
        }
    }
}

int main() {
    vector<vector<int> > arr{
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };

    wavePrint(arr);

    return 0;
}
*/


// ******** SPIRAL PRINT AN 2D ARRAY **********
/*
#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int> > matrix) {
    vector<int> ans;

    int m = matrix.size();
    int n = matrix[0].size();
    int total_elements = m * n;

    int startingRow = 0;
    int endingCol = n - 1;
    int endingRow = m - 1;
    int startingCol = 0;

    int count = 0;

    while(count < total_elements) {
        // Print starting ka row
        for(int i=startingCol; i<=endingCol && count<total_elements; i++) {
            ans.push_back(matrix[startingRow][i]);
            count++;
        }
        startingRow++;

        // Print ending ka col
        for(int i=startingRow; i<=endingRow && count<total_elements; i++) {
            ans.push_back(matrix[i][endingCol]);
            count++;
        }
        endingCol--;

        // Print ending ka row
        for(int i=endingCol; i>=startingCol  && count < total_elements; i--) {
            ans.push_back(matrix[endingRow][i]);
            count++;
        }
        endingRow--;

        // print starting ka col
        for(int i=endingRow; i>=startingRow && count < total_elements; i--) {
            ans.push_back(matrix[i][startingCol]);
            count++;
        }
        startingCol++;
    }
    return ans;
}


int main() {
    vector<vector<int> > arr{
        { 1, 2, 3, 4, 5, 6},
        { 7, 8, 9,10,11,12},
        {13,14,15,16,17,18},
        {19,20,21,22,23,24},
        {25,26,27,28,29,30}
    };

    vector<int> v = spiralOrder(arr);

    for(auto val: v) {
        cout<<val<<" ";
    }

    return 0;
}
*/


// ******* SPIRAL PRINT AN 2D ARRAY **********
/*
#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralPrint(vector<vector<int>> arr) {
    vector<int> ans;
    
    int m = arr.size();
    int n = arr[0].size();
    int total_elements = m * n;

    int startingRow = 0;
    int endingCol = n - 1;
    int endingRow = m - 1;
    int startingCol = 0;

    int count = 0;

    while(count < total_elements) {

        // Starting Row
        for(int i=startingCol; i<=endingCol && count<total_elements; i++) {
            ans.push_back(arr[startingRow][i]);
            count++;
        }
        startingRow++;

        // Ending Col
        for(int i=startingRow; i<=endingRow && count<total_elements; i++) {
            ans.push_back(arr[i][endingCol]);
            count++;
        }
        endingCol--;

        // Ending Row
        for(int i=endingCol; i>=startingCol && count<total_elements; i--) {
            ans.push_back(arr[endingRow][i]);
            count++;
        }
        endingRow--;

        // Starting Col
        for(int i=endingRow; i>=startingRow && count<total_elements; i--) {
            ans.push_back(arr[i][startingCol]);
            count++;
        }
        startingCol++;
    }   
    return ans;
}
 
int main() {
    vector<vector<int> > arr{
        { 1, 2, 3, 4, 5},
        { 6, 7, 8, 9,10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {21,22,23,24,25}
    };

    vector<int> ans = spiralPrint(arr);

    for(int val: ans) {
        cout<<val<<" ";
    }

    return 0;
}
*/


// ********* SPIRAL PRINT AN ARRAY ********
/*
#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralPrint(vector<vector<int> > arr) {
    vector<int> ans;

    int m = arr.size();
    int n = arr[0].size();
    int total_elements = m * n;
    int count = 0;

    int startingRow = 0;
    int endingRow = m - 1;
    int startingCol = 0;
    int endingCol =  n - 1;  

    while(count<total_elements) {
        // Print startng row
        for(int i=startingCol; i<=endingCol && count<total_elements; i++) {
            ans.push_back(arr[startingRow][i]);
            count++;
        }
        startingRow++;
        // Print ending col
        for(int i=startingRow; i<=endingRow && count<total_elements; i++) {
            ans.push_back(arr[i][endingCol]);
            count++;
        }
        endingCol--;
        // Print ending Row
        for(int i = endingCol; i>=startingCol && count<total_elements; i--) {
            ans.push_back(arr[endingRow][i]);
            count++;
        }
        endingRow--;
        // Print starting col
        for(int i = endingRow; i>=startingRow && count<total_elements; i--) {
            ans.push_back(arr[i][startingCol]);
            count++;
        }
        startingCol++;
    }
    return ans;
}

int main() {
    vector<vector<int> > arr{
        { 1, 2, 3, 4},
        { 5, 6, 7, 8},
        { 9,10,11,12},
        {13,14,15,16},
        {17,18,19,20}
    };

    vector<int> ans = spiralPrint(arr);

    for(auto val: ans) {
        cout<<val<<" ";
    }cout<<endl;

    return 0;
}
*/


// ******* FIND FACTORIAL OF LARGE NUMBER *********
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printArray(vector<int> a) {
    for(auto val: a) {
        cout<<val;
    } cout<<endl;
}

vector<int> factorial(int N) {
    vector<int> ans;
    ans.push_back(1);
    int carry = 0;

    for(int i=2; i<=N; i++) {
        for(int j=0; j<ans.size(); j++) {
            int x = ans[j] * i + carry;
            ans[j] = x%10;
            carry = x/10;
        }

        while(carry) {
            ans.push_back(carry%10);
            carry /= 10;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main() {
    vector<int> ans = factorial(50);

    for(auto val: ans) {
        cout<<val;
    }
    cout<<endl;

    return 0;
}
*/


// ********** FIND FACTORIAL OF LARGEST NUMBER *********
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> factorial(int N) {
    vector<int> ans;
    ans.push_back(1);

    int carry = 0;

    for(int i=2; i<=N; i++) {
        for(int j=0; j<ans.size(); j++) {
            int x = ans[j] * i + carry;
            ans[j] = x%10;
            carry = x/10;
        }
        while(carry) {
            ans.push_back(carry%10);
            carry /= 10;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main() {
    vector<int> ans = factorial(500);

    for(auto val: ans) {
        cout<<val;
    } cout<<endl;

    return 0;
}
*/


// ******* SPIRAL PRINT AN ARRAY ********
/*
#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralPrint(vector<vector<int> > arr) {
    vector<int> ans;

    int m = arr.size();
    int n = arr[0].size();
    int total_elements = m * n;

    int startingRow = 0;
    int startingCol = 0;
    int endingRow = m - 1;
    int endingCol = n - 1;
    int count = 0;

    while(count<total_elements) {
        for(int i=startingCol; i<=endingCol && count<total_elements; i++) {
            ans.push_back(arr[startingRow][i]);
            count++;
        }
        startingRow++;

        for(int i=startingRow; i<=endingRow && count<total_elements; i++) {
            ans.push_back(arr[i][endingCol]);
            count++;
        }
        endingCol--;

        for(int i=endingCol; i>=startingCol && count<total_elements; i--) {
            ans.push_back(arr[endingRow][i]);
            count++;
        }
        endingRow--;

        for(int i=endingRow; i>=startingRow; i--) {
            ans.push_back(arr[i][startingCol]);
            count++;
        }
        startingCol++;
    }
    return ans;
}

int main() {
    vector<vector<int> > arr{
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {21,22,23,24,25}
    };

    vector<int> ans = spiralPrint(arr);

    for(auto val: ans) {
        cout<<val<<" "; 
    } cout<<endl;

    return 0;
}
*/


// ******* FIND FACTORIAL OF LARGE NUMBER *******
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> factorial(int N) {

    vector<int> ans;
    ans.push_back(1);
    int carry = 0;
    
    for(int i=2; i<=N; i++) {
        for(int j=0; j<ans.size(); j++) {
            int x = ans[j] * i + carry;
            ans[j] = x % 10;
            carry = x / 10;
        }
        while(carry) {
            ans.push_back(carry);
            carry = carry / 10;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main() {
    int N;
    cout<<"Enter the number for factorial - "<<endl;
    cin >> N;

    vector<int> ans = factorial(N);

    for(auto val: ans) {
        cout<<val;
    } cout<<endl;

    return 0;
}
*/