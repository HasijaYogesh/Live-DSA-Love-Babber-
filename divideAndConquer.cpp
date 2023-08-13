// ******* MERGE SORT *********
/*
#include <iostream>
using namespace std;

void merge(int* arr, int s, int e) {
    int mid = (s+e)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int* left = new int[len1];
    int* right = new int[len2];

    // copy value
    int k = s;
    for(int i=0; i<len1; i++) {
        left[i] = arr[k];
        k++;
    }

    k = mid+1;
    for(int i=0; i<len1; i++) {
        right[i] = arr[k];
        k++;
    }

    // merge logic
    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = s;

    while(leftIndex<len1 && rightIndex<len2) {
        if(left[leftIndex] < right[rightIndex]) {
            arr[mainArrayIndex++] = left[leftIndex++];
        }
        else {
            arr[mainArrayIndex++] = right[rightIndex++];
        }
    }

    // copy logic for left array
    while(leftIndex<len1) {
        arr[mainArrayIndex++] = left[leftIndex++];
    }

    // copy logic for right array
    while(rightIndex<len2) {
        arr[mainArrayIndex++] = right[rightIndex++];
    }

    // To do item -> delete left and right newly created array
}

void mergeSort(int* arr, int s, int e) {
    // base case
    // s == e -> single element
    // s > e -> invalid array
    if(s>=e) {
        return;
    }

    int mid = (s+e) / 2;
    // left part sort by recursion
    mergeSort(arr, s, mid);

    // right part sort by recursion
    mergeSort(arr, mid+1, e);

    // now merge two sorted array
    merge(arr, s, e);
}

int main() {
    int arr[] = {4,5,13,2,12,13,2};
    int n = 7;

    int s = 0;
    int e = n-1;

    mergeSort(arr, s, e);

    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}
*/


// ******* QUICK SORT ********
/*
#include <iostream>
using namespace std;

int partition(int arr[], int s, int e) {
    // step 1: choose pivot element
    int pivotIndex = s;
    int pivotElement = arr[s];

    // Step 2: Find right position for pivot element and place it
    int count = 0;

    for(int i=s+1; i<=e; i++) {
        if(arr[i] <= pivotElement) {
            count++;
        }
    }

    // when out of loop, I have a right position of pivot element
    int rightIndex = s + count;
    swap(arr[pivotIndex], arr[rightIndex]);
    pivotIndex = rightIndex;

    // Step 3: small element on left and large on right
    int i = s;
    int j = e;

    while(i<pivotIndex && j>pivotIndex) {
        while(arr[i] <= pivotElement) {
            i++;
        }
        while(j > pivotElement) {
            j--;
        }
        // two possible case
        // A -> you found the element to swap
        // B -> no need to swap
        if(i<pivotIndex && j>pivotIndex) {
            swap(arr[i], arr[j]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e) {
    // base case
    if(s>=e) {
        return;
    }

    // partition logic, return pivot
    int p = partition(arr, s, e);

    // recursion call
    // pivot element -> left
    quickSort(arr, s, p-1);

    // pivot element -> right
    quickSort(arr, p+1, e);
}

int main() {
    int arr[] = {8,1,3,4,20,50,30};
    int n = 7;
    int s = 0;
    int e = n-1;

    quickSort(arr, s, e);

    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}
*/



// ******* PERMUTATION ANS BACK TRACKING ********
/*
#include <iostream>
using namespace std;

void printPermutation(string &str, int i) {
    // base case
    if(i >= str.length()) {
        cout<<str<<" ";
    }

    // swapping 
    for(int j=i; j<str.length(); j++) {
        // swap
        swap(str[i], str[j]);

        // recursion call
        printPermutation(str, i+1);

        // back tracking
        swap(str[i], str[j]);
    }
}

int main() {
    string str = "abc";
    int i = 0;
    printPermutation(str, i);

    return 0;
}
*/


// ********* RAT IN A MAZE PROBLEM *******
/*
#include <iostream>
#include <vector>
using namespace std;

int dx[] = {1,0,0,-1};
int dy[] = {0,-1,1,0};
char direction[] = {'D', 'L', 'R', 'U'};

bool isSafe(int i, int j, int row, int col, int arr[4][4], vector<vector<bool>> &visited) {
    if( ((i>=0 && i<row) && (j>=0 && j<col)) && arr[i][j] == 1 && visited[i][j] == false) {
        return true;
    }
    else {
        return false;
    }
}

void solveMaze(int arr[4][4], int row, int col, int i, int j,vector<vector<bool>> &visited, vector<string> &path, string& output) {
    // base case
    if(i == row-1 && j == col-1) {
        // answer found
        path.push_back(output);
        return;
    }

    // loop for directions
    for(int k=0; k<4; k++) {
        int newx = i + dx[k];
        int newy = j + dy[k];
        char dir = direction[k];

        if(isSafe(newx, newy, row, col, arr, visited)) {
            visited[newx][newy] = true;
            output.push_back(dir);
            solveMaze(arr, row, col, newx, newy, visited, path, output);

            // back tracking
            output.pop_back();
            visited[newx][newy] = false;
        }
    }

    // No need of below code becasue we have shorten this code to above for loop

    // // Down -> i+1, j
    // if(isSafe(i+1, j, row, col, arr, visited)) {
    //     visited[i+1][j] = true;
    //     string newOutput = output + 'D';
    //     solveMaze(arr, row, col, i+1, j, visited, path, newOutput);
    //     visited[i+1][j] = false;
    // }

    // // Left -> i, j-1
    // if(isSafe(i, j-1, row, col, arr, visited)) {
    //     visited[i][j-1] = true;
    //     string newOutput = output + 'L';
    //     solveMaze(arr, row, col, i, j-1, visited, path, newOutput);
    //     visited[i][j-1] = false;
    // }

    // // Right -> i, j+1
    // if(isSafe(i, j+1, row, col, arr, visited)) {
    //     visited[i][j+1] = true;
    //     string newOutput = output + 'R';
    //     solveMaze(arr, row, col, i, j+1, visited, path, newOutput);
    //     visited[i][j+1] = false;
    // }

    // // Up -> i-1, j
    // if(isSafe(i-1, j, row, col, arr, visited)) {
    //     visited[i-1][j] = true;
    //     string newOutput = output + 'U';
    //     solveMaze(arr, row, col, i-1, j, visited, path, newOutput);
    //     visited[i-1][j] = false;
    // }
}

int main() {
    int maze[4][4] = {{1,0,0,0}, 
                     {1,1,0,1}, 
                     {1,1,0,0},
                     {0,1,1,1}};
    
    int row = 4;
    int col = 4;

    // edge case
    if(maze[0][0] == 0) {
        cout<<"No path exists!"<<endl;
        return 0;
    }

    vector<vector<bool> > visited(row, vector<bool>(col, false));
    // src ki value k true marke kredete he
    visited[0][0] = true;

    vector<string>path;
    string output = "";

    solveMaze(maze, row, col, 0, 0,visited, path, output);

    cout<<"Printing the results :-"<<endl;
    if(path.size() == 0) {
        cout<<"No path exists";
    }

    for(int i=0; i<path.size(); i++) {
        cout<<path[i]<<endl;
    }

    return 0;
}
*/


// *********** PLACE N QUEEN PROBLEM ********
/*
#include <iostream>
#include <vector>
using namespace std;

void printSolution(vector<vector<char>>& board, int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<board[i][j]<<" ";
        } cout<<endl;
    }
    cout<<endl;
}

bool isSafe(vector<vector<char>>& board, int row, int col, int n) {
    // check karna chahte he, k kya mein current cell per queen rakh sakta hu ya nhi
    int i = row;
    int j = col;

    // check row
    while(j>=0) {
        if(board[i][j] == 'Q') {
            return false;
        }
        j--;
    } 

    // check upper left digonal
    i = row;
    j = col;
    while(i>=0 && j>=0) {
        if(board[i][j] == 'Q') {
            return false;
        }
        i--;
        j--;
    }

    // check bottom left digonal
    i = row;
    j = col;
    while(i<n && j>=0) {
        if(board[i][j] == 'Q') {
            return false;
        }
        i++;
        j--;
    }

    // kahin per bhi queen nhi mili, ye position sahi he, return kardo true
    return true;
}

void solve(vector<vector<char>>& board, int col, int n) {
    // base case
    if(col >= n) {
        printSolution(board, n);
        return;
    }

    // ek case solve krna he, baki recursion sambal lega
    for(int row=0; row<n; row++) {
        if(isSafe(board, row, col, n)) {
            // rakh do
            board[row][col] = 'Q';

            // recursion solution laega
            solve(board, col+1, n);

            // back tracking
            board[row][col] = '-';
        }
    }
}

int main() {
    int n = 5;
    vector<vector<char>> board(n, vector<char>(n, '-'));
    // 0 -> empty cell
    // 1 -> Queen at the cell
    int col = 0;
    solve(board, col, n);

    return 0;
}
*/


// ******* PLACE N QUEEN PROBLEM WITH ISSAFE FUNCTION OPTIMIZATION WITH UNORDERED MAP *********
/*
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int, bool> rowCheck;
unordered_map<int, bool> upperLeftDiagonalCheck;
unordered_map<int, bool> bottomLeftDiagonalCheck;



void printSolution(vector<vector<char>>& board, int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<board[i][j]<<" ";
        } cout<<endl;
    }
    cout<<endl;
}

bool isSafe(vector<vector<char>>& board, int row, int col, int n) {
    // check karna chahte he, k kya mein current cell per queen rakh sakta hu ya nhi
    if(rowCheck[row] == true) {
        return false;
    }
    if(upperLeftDiagonalCheck[n-1+col-row] == true) {
        return false;
    } 
    if(bottomLeftDiagonalCheck[row+col] == true) {
        return false;
    }
    return true;
}

void solve(vector<vector<char>>& board, int col, int n) {
    // base case
    if(col >= n) {
        printSolution(board, n);
        return;
    }

    // ek case solve krna he, baki recursion sambal lega
    for(int row=0; row<n; row++) {
        if(isSafe(board, row, col, n)) {
            // rakh do
            board[row][col] = 'Q';
            rowCheck[row] = true;
            upperLeftDiagonalCheck[n-1+col-row] = true;
            bottomLeftDiagonalCheck[row+col] = true;

            // recursion solution laega
            solve(board, col+1, n);

            // back tracking
            board[row][col] = '-';
            rowCheck[row] = false;
            upperLeftDiagonalCheck[n-1+col-row] = false;
            bottomLeftDiagonalCheck[row+col] = false;
        }
    }
}

int main() {
    int n = 4;
    vector<vector<char>> board(n, vector<char>(n, '-'));
    // 0 -> empty cell
    // 1 -> Queen at the cell
    int col = 0;
    solve(board, col, n);

    return 0;
}
*/


// ********* GENERATE PARANTHESIS *********
/*
#include <iostream>
#include <vector>
using namespace std;

void solve(vector<string>& ans, int n, int open, int close, string& output) {
    // base case
    if(open == 0 && close == 0) {
        ans.push_back(output);
        return;
    }

    // include open brackets
    if(open > 0) {
        output.push_back('(');
        solve(ans, n, open-1, close, output);
        output.pop_back();
    }

    // include close bracket
    if(close > open) {
        output.push_back(')');
        solve(ans, n, open, close-1, output);
        output.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    int open = n;
    int close = n;
    string output = "";
    solve(ans, n, open, close, output);
    return ans;
}

int main() {
    
    vector<string> ans = generateParenthesis(5);

    for(auto val: ans) {
        cout<<val<<endl;
    }

    return 0;
}
*/


// ****** LETTER COMBINATIONI OF PHONE NUMBER *********
/*
#include <iostream>
#include <vector>
using namespace std;

void solve(vector<string>& ans, int index, string output, string digits, vector<string>& mapping) {
    // base case
    if(index >= digits.length()) {
        ans.push_back(output);
        return;
    }

    //  case solve krdo, baki recursion sambhal lega
    int digit = digits[index] - '0';
    string value = mapping[digit];
    for(int i=0; i<value.length(); i++) {
        char ch = value[i];
        output.push_back(ch);
        solve(ans, index+1, output, digits, mapping);
        output.pop_back();
    }
}

vector<string> letterCombination(string digits) {
    vector<string> ans;
    if(digits.length() == 0) {
        return ans;
    }

    int index = 0;
    string output = "";
    vector<string> mapping(10);
    mapping[2] = "def";
    mapping[3] = "abc";
    mapping[4] = "ghi";
    mapping[5] = "jkl";
    mapping[6] = "mno";
    mapping[7] = "pqrs";
    mapping[8] = "tuv";
    mapping[9] = "wxyz";

    solve(ans, index, output, digits, mapping);

    return ans;
}

int main() {
    string digits = "23";
    vector<string> ans = letterCombination(digits);
    
    for(auto val: ans) {
        cout<<val<<" ";
    }

    return 0;
}
*/


// ******** SUDOKU SOLVER ********* 
/*
#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int value, int board[9][9], int curr_row, int curr_col) {
    // row check
    for(int col=0; col<9; col++) {
        if(board[curr_row][col] == value) {
            return false;
        }
    }

    // column check
    for(int row=0; row<9; row++) {
        if(board[row][curr_col] == value) {
            return false;
        }
    }

    // 3*3 box check
    for(int i=0; i<9; i++) {
        if(board[3*(curr_row/3) + (i/3)][3*(curr_col/3) + (i/3)] == value) {
            return false;
        }
    }
    return true;
}

// This function return true or false, basis on we found solution or not
bool sudokuSolver(int board[9][9], int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            // check for empty cell
            if(board[i][j] == 0) {
                for(int value=1; value<=9; value++) {
                    if(isSafe(value, board, i, j)) {
                        // insert
                        board[i][j] = value;
                        // baki recursion sambhal lega
                        bool aageKaSolution = sudokuSolver(board, n);
                        if(aageKaSolution == true) {
                            return true;
                        }
                        // backtracking
                        board[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    int board[9][9] = {
        {4,5,0,0,0,0,0,0,0},
        {0,0,2,0,7,0,6,3,0},
        {0,0,0,0,0,0,0,2,8},
        {0,0,0,9,5,0,0,0,0},
        {0,8,6,0,0,0,2,0,0},
        {0,2,0,6,0,0,7,5,0},
        {0,0,0,0,0,0,4,7,6},
        {0,7,0,0,4,5,0,0,0},
        {0,0,8,0,0,9,0,0,0},
    };
    int n = 9;

    int ans = sudokuSolver(board, n);
    cout<<"Answer is "<<ans<<endl;
    cout<<"Printing the solution"<<endl;
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
*/


// ********** SUDOKU SOLVER (SOLVING AGAIN)***********
/*
#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col, vector<vector<char> >& board, char value) {
    int n = board.size();
    
    for(int i=0; i<n; i++) {
        // row check
        if(board[row][i] == value) {
            return false;
        }
        // col check
        if(board[i][col] == value) {
            return false;
        }
        // 3*3 box check
        if(board[3*(row/3) + (i/3)][3*(col/3) + (i%3)] == value) {
            return false;
        }
    }
    return true;
}

bool solveSudoku(vector<vector<char> >& board) {
    int n = board.size();

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            // check for empty cell
            if(board[i][j] == '.') {
                // try to fill with values ranging from 1 to 9
                for(char val = '1'; val<='9'; val++) {
                    if(isSafe(i, j, board, val)) {
                        // insert
                        board[i][j] = val;

                        // recursion sambhal lega
                        bool aageKaSolution = solveSudoku(board);
                        if(aageKaSolution == true) {
                            return true;
                        }
                        else {
                            // backtracking
                            board[i][j] = '.';
                        }
                    }
                }
                // if 1 se 9 tak koi bhi value ke solution nhi nikla , 
                // that means piche kahin per galti he,
                // go bak by returning false
                return false;
            }
        }
    }
    // all cells filled
    return true;
}

int main() {
    vector<vector<char> > board {
        {'4','5','.','.','.','.','.','.','.'},
        {'.','.','2','.','7','.','6','3','.'},
        {'.','.','.','.','.','.','.','2','8'},
        {'.','.','.','9','5','.','.','.','.'},
        {'.','8','6','.','.','.','2','.','.'},
        {'.','2','.','6','.','.','7','5','.'},
        {'.','.','.','.','.','.','4','7','6'},
        {'.','7','.','.','4','5','.','.','.'},
        {'.','.','8','.','.','9','.','.','.'},
    };

    int ans = solveSudoku(board);
    cout<<"Answer is "<<ans<<endl;
    cout<<"Printing the solution"<<endl;
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
*/


// ******** COUNT INVERSION ********
/*
#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int>& arr, vector<int>& temp, int start, int mid, int end) {
    int i = start;
    int j = mid+1;
    int k = start;
    int c = 0;
    while(i<=mid && j<=end) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        // arr[i] > arr[j] && inversion count case
        else {
            c += mid - i + 1;
            temp[k++] = arr[j++];
        }
    }
    while(i<=mid) {
        temp[k++] = arr[i++];
    }
    while(j<=end) {
        temp[k++] = arr[j++];
    }
    while(start <= end) {
        arr[start] = temp[start];
        ++start;
    }

    return c;
}

int mergeSort(vector<int>& arr, vector<int>& temp, int start, int end) {
    if(start >= end) {
        return 0;
    }
    int c = 0;
    int mid = start + (end - start)/2;
    c += mergeSort(arr, temp, start, mid);
    c += mergeSort(arr, temp, mid+1, end);
    c += merge(arr, temp, start, mid, end);

    return c;
}

int countInversions(vector<int> arr) {
    int c = 0; // inversion counts
    int n = arr.size();

    vector<int>temp{n, 0};

    c = mergeSort(arr, temp, 0, n-1);

    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return c;
}

int main() {
    vector<int> arr{4,3,2,1};

    int ans = countInversions(arr);
    cout<<"Answer is "<<ans<<endl;

    return 0;
}
*/


// ************ MERGE SORT PRACTICE ********
/*
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, vector<int>& temp, int start, int mid, int end) {
    int i = start, j = mid+1, k=start;

    while(i<=mid && j<=end) {
        if(arr[i] <= arr[j]) {
            temp[k] = arr[i];
            k++, i++;
        }
        else {
            temp[k] = arr[j];
            k++, j++;
        }
    }
    while(i<=mid) {
        temp[k] = arr[i];
        k++, i++;
    }
    while(j<=end) {
        temp[k] = arr[j];
        k++, j++;
    }
    while(start <= end) {
        arr[start] = temp[start];
        start++;
    }
}

void mergeSort(vector<int>& arr, vector<int>& temp, int start, int end) {
    if(start >= end) {
        return;
    }
    int mid = (start+end)/2;
    mergeSort(arr, temp, start, mid);
    mergeSort(arr, temp, mid+1, end);
    merge(arr, temp, start, mid, end);
}

vector<int> sortArray(vector<int>& arr) {
    int n = arr.size();
    vector<int> temp(n, 0);
    mergeSort(arr, temp, 0, n-1);
    return arr;
}

int main() {
    vector<int> arr{10,8,6,7,2,1,3,5,4,9,0};

    vector<int> ans = sortArray(arr);
    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    } cout<<endl;       

    return 0;
}
*/


// ******** IN PLACE MERGE SORT WITHOUT TEMP ********
/*
#include <iostream>
#include <vector>
using namespace std;

void mergeInPlace(vector<int>& arr, int start, int mid, int end) {
    int total_length = end - start + 1;
    int gap = total_length/2 + total_length % 2; //ceil
    while(gap > 0) {
        int i = start;
        int j = start + gap;
        while(j<=end) {
            if(arr[i] >arr[j]) {
                swap(arr[i], arr[j]);
            }
            ++i, ++j;
        }
        gap = gap<=1 ? 0 : (gap/2) + (gap%2);
    }
}

void mergeSort(vector<int>& arr, int start, int end) {
    if(start >= end) {
        return;
    }
    int mid = (start+end)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    mergeInPlace(arr, start, mid, end);
}

vector<int> sortArray(vector<int>& arr) {
    int n = arr.size();
    mergeSort(arr, 0, n-1);
    return arr;
}

int main() {
    vector<int> arr{10,8,6,7,2,1,3,5,4,9,0};

    vector<int> ans = sortArray(arr);
    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    } cout<<endl;       

    return 0;
}
*/


// ******** MERGE TWO ARRAYS WITHOUT TEMP (IN PLACE) USING GAP ******* 
/*
#include <iostream>
#include <vector>
using namespace std;

void mergeInPlace(vector<int>& arr, vector<int>& brr) {
    int m = arr.size();
    int n = brr.size();
    int total_length = m+n;

    int gap = (total_length/2) + (total_length%2);

    while(gap>0) {
        int i = 0;
        int j = gap;

        while(j<total_length) {
            if(j<m && arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
            else if(j >= m && i<m && arr[i] > brr[j-m]) {
                swap(arr[i], brr[j-m]);
            }
            else if(i>=m && j>=m && brr[i-m] > brr[j-m]) {
                swap(brr[i-m], brr[j-m]);
            }
            i++, j++;
        }
        gap = gap <= 1 ? 0 : (gap/2) + (gap%2);
    } 
}

int main() {
    vector<int> arr{1,2,8,9,12,13};
    vector<int> brr{3,4,7,10};

    mergeInPlace(arr, brr);

    cout<<"Printing arr - "<<endl;
    for(int i=0; i<arr.size(); i++) {
        cout<<arr[i]<<" ";
    } cout<<endl;

    cout<<"Printing brr - "<<endl;
    for(int i=0; i<brr.size(); i++) {
        cout<<brr[i]<<" ";
    } cout<<endl;

    return 0;
}
*/


// ******* MAX SUBARRAY SUM *******
/*
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int maxSubArrayHelper(vector<int>& v, int start, int end) {
    if(start == end) {
        return v[start];
    }
    int maxLeftBorderSum = INT_MIN;
    int maxRightBorderSum = INT_MIN;
    int mid = start + ((end - start) >> 1);

    int maxLeftSum = maxSubArrayHelper(v, start, mid);
    int maxRightSum = maxSubArrayHelper(v, mid+1, end);

    // Max cross border sum.
    int leftBorderSum = 0;
    int rightBorderSum = 0;
    for(int i = mid; i>=start; i--) {
        leftBorderSum += v[i];
        if(leftBorderSum > maxLeftBorderSum) {
            maxLeftBorderSum = leftBorderSum;
        }
    }
    for(int i = mid+1; i<=end; i++) {
        rightBorderSum += v[i];
        if(rightBorderSum > maxRightBorderSum) {
            maxRightBorderSum = rightBorderSum;
        }
    }
    int crossBorderSum = maxLeftBorderSum + maxRightBorderSum;
    return max(maxLeftSum, max(maxRightSum, crossBorderSum));
}

int maxSubArray(vector<int>& arr) {
    return maxSubArrayHelper(arr, 0, arr.size()-1);
}

int main() {
    vector<int> arr{-2,1,-3,4,-1,2,1,-5,4};
    int ans = maxSubArray(arr);
    cout<<"Answer is "<<ans<<endl;

    return 0;
}
*/


// ******* QUICK SORT WITH END AS PIVOT ********
/*
#include <iostream>
using namespace std;

void quickSort(int a[], int start, int end) {
    if(start >= end) {
        return;
    }
    int pivot = end;
    int i = start-1;
    int j = start;

    while(j<pivot) {
        if(a[j] < a[pivot]) {
            ++i;
            swap(a[i], a[j]);
        }
        j++;
    }
    ++i;
    // i is the right position for the pivot element
    swap(a[i], a[pivot]);

    quickSort(a, start, i-1);
    quickSort(a, i+1, end);
}

int main() {
    int arr[8] = {7,2,1,8,6,3,5,4};

    quickSort(arr, 0, 7);

    for(int i=0; i<8; i++) {
        cout<<arr[i]<<" ";
    } cout<<endl;


    return 0;
}
*/


// ******** COMBINATION SUM 1 *********
/*
#include <iostream>
#include <vector>
using namespace std;

void combinationSumHelper(vector<int>& candidates, int target, vector<int>& v, vector<vector<int>>& ans, int index) {
    // base case
    if(target == 0) {
        ans.push_back(v);
        return;
    }
    if(target < 0) {
        return;
    }

    for(int i=index; i<candidates.size(); i++) {
        v.push_back(candidates[i]);
        combinationSumHelper(candidates, target-candidates[i], v, ans, i);
        v.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> v;
    combinationSumHelper(candidates, target, v, ans, 0);
    return ans;
}

int main() {
    vector<int> v{2,3,6,7};
    int target = 7;

    vector<vector<int>> ans = combinationSum(v, target);

    for(int i=0; i<ans.size(); i++) {
        cout<<i+1<<" - ";
        for(int j=0; j<ans[i].size(); j++) {
            cout<<ans[i][j]<<" ";
        } cout<<endl;
    }

    return 0;
}
*/


// ******** COMBINATION SUM 2 *********
/*
#include <iostream>
#include <vector>
#include <set>
#include <bits/stdc++.h>
using namespace std;

void combinationSumHelper(vector<int>& candidates, int target, vector<int>& v, vector<vector<int>>& ans, int index) {
    // base case
    if(target == 0) {
        ans.push_back(v);
        return;
    }
    if(target < 0) {
        return;
    }

    for(int i=index; i<candidates.size(); i++) {
        if(i>index && candidates[i] == candidates[i-1]) {
            continue;
        }
        v.push_back(candidates[i]);
        combinationSumHelper(candidates, target-candidates[i], v, ans, i+1);
        v.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> v;
    combinationSumHelper(candidates, target, v, ans, 0);

    // ******* Below code is also right, but it gets TLE on leetcode *******
    // set<vector<int>> st;
    // for(auto e: ans) {
    //     st.insert(e);
    // }
    // ans.clear();
    // for(auto e: st) {
    //     ans.push_back(e); // only unique values in ans
    // }
    return ans;
}

int main() {
    vector<int> v{2,5,2,1,2};
    int target = 5;

    vector<vector<int>> ans = combinationSum(v, target);

    for(int i=0; i<ans.size(); i++) {
        cout<<i+1<<" - ";
        for(int j=0; j<ans[i].size(); j++) {
            cout<<ans[i][j]<<" ";
        } cout<<endl;
    }

    return 0;
}
*/


// ******** PERMUTATIONS 2 ********
/*
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void permuteUniqueHelper(vector<int>&nums ,vector<vector<int>>& ans, int start) {
    // base case
    if(start==nums.size()) {
        ans.push_back(nums);
        return;
    }
    unordered_map<int, bool> visited;
    for(int i=start; i<nums.size(); i++) {
        if(visited.find(nums[i]) != visited.end()) {
            continue;
        }
        visited[nums[i]] = true;
        swap(nums[i], nums[start]);
        permuteUniqueHelper(nums, ans, start+1);
        swap(nums[i], nums[start]);
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> ans;

    permuteUniqueHelper(nums, ans, 0);

    return ans;
}

int main() {
    vector<int> v{1,1,2};

    vector<vector<int>> ans = permuteUnique(v);

    for(int i=0; i<ans.size(); i++) {
        cout<<i+1<<" - ";
        for(int j=0; j<ans[i].size(); j++) {
            cout<<ans[i][j]<<" ";
        } cout<<endl;
    }

    return 0;
}
*/


// ******** BEAUTIFUL ARRAGNEMENT *******
/*
#include <iostream>
#include <vector>
using namespace std;

void countArrangementHelper(vector<int>&v, int&n, int&ans, int currNum) {
    // base condition
    if(currNum == n+1) {
        for(int i=1; i<=n; i++) {
            cout<<v[i]<<" ";
        } cout<<endl;
        ans++;
        return;
    }

    for(int i=1; i<=n; i++) {
        if(v[i] == 0 && (currNum % i == 0 || i % currNum == 0) ) {
            v[i] = currNum;
            countArrangementHelper(v, n, ans, currNum+1);
            v[i] = 0;
        }
    }
}

int countArrangement(int n) {
    vector<int>v(n+1);
    int ans = 0;
    countArrangementHelper(v, n, ans, 1);

    return ans;
}

int main() {
    
    int ans = countArrangement(3);

    cout<<"Answer is - "<<ans<<endl;

    return 0;
}
/*


// ********* DISTRIBUTE REPEATING INTEGERS **********
/*
#include <iostream>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

bool canDistributeHelper(vector<int>& counts, vector<int>& quantity, int ithCustomer) {
    // base case
    if(ithCustomer == quantity.size()) {
        return true;
    }

    for(int i=0; i<counts.size(); i++) {
        if(counts[i] >= quantity[ithCustomer]) {
            counts[i] -+ quantity[ithCustomer];
            if(canDistributeHelper(counts, quantity, ithCustomer+1)) {
                return true;
            }
            // back track
            counts[i] += quantity[ithCustomer];
        }
    }
    return false;
}

bool canDistribute(vector<int>& nums, vector<int>& quantity) {
    unordered_map<int, int> countMap;
    for(auto num: nums) {
        countMap[num]++;
    }
    vector<int> counts;
    for(auto it: countMap) {
        counts.push_back(it.second);
    }
    sort(quantity.rbegin(), quantity.rend()); // sort desc.
    return canDistributeHelper(counts, quantity, 0);
}

int main() {
    vector<int> nums{1,1,2,2,2,2,3,3};
    vector<int> quantity{2,2,3};

    bool ans = canDistribute(nums, quantity);
    cout<<"Answer is - "<<ans<<endl;

    return 0;
}
*/