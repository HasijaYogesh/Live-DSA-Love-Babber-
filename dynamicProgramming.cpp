// ********* FIBONACCI SERIES USING DP *********
/*
#include <iostream>
#include <vector>
using namespace std;

// Normal recursive solution
int recSolve(int n) {
    // base case
    if( n == 1 || n == 0) {
        return n;
    }

    int ans = recSolve(n-1) + recSolve(n-2);

    return ans;
}

// DP solution
// Recursion + Memoisation
int topDownSolve(int n, vector<int>& dp) {
    // base case
    if( n == 1 || n == 0) {
        return n;
    }
    // Step 3: check if answer already exists
    if(dp[n] != -1) {
        return dp[n];
    }

    // Step 2: replace ans with dp[n]
    dp[n] = topDownSolve(n-1, dp) + topDownSolve(n-2, dp);

    return dp[n];
}

// Bottom to up iterative approach
//Tabulation method
int bottomUpSolve(int n) {
    // Step 1: create dp array
    vector<int> dp(n+1, -1);

    // Step 2: Observe base case in above solution
    dp[0] = 0;
    dp[1] = 1;

    // Step 3: 
    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

// Space optimal solution - TC O(n), SC O(1)
int spaceOptSolve(int n) {
    int prev2 = 0;
    int prev1 = 1;  

    if(n == 0) {
        return prev2;
    }
    if(n == 1) {
        return prev1;
    }

    int curr;

    for(int i=2; i<=n; i++) {
        curr = prev1+prev2;

        // shifting
        prev2 = prev1;
        prev1 = curr;
    }

    return curr;
}

int fib(int n) {
    // Normal recursive call
    // int ans = recSolve(n);
    // return ans;

    // DP solution

    // Step 1: create dp array
    vector<int> dp(n+1, -1);

    // int ans = topDownSolve(n, dp);
    int ans = spaceOptSolve(n);
    return ans;
}

int main() {
    
    int ans = fib(8);
    cout<<"Answer is "<<ans<<endl;


    return 0;
}
*/


// ******* LEET CODE 322 - COIN CHANGE USING DP*********
/*
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// Normal recurion approach
int solveUsingRecursion(vector<int>& coins, int amount) {
    // base case
    if(amount == 0) {
        return 0;
    }

    if(amount < 0) {
        return INT_MAX;
    }

    int mini = INT_MAX;

    for(int i=0; i<coins.size(); i++) {
        int ans = solveUsingRecursion(coins, amount-coins[i]);

        if(ans != INT_MAX) {
            mini = min(mini, 1 + ans);
        }
    }

    return mini;
}

// Top down approach with DP
int solveMem(vector<int>& coins, int amount, vector<int>& dp) {
        // base case
    if(amount == 0) {
        return 0;
    }

    if(amount < 0) {
        return INT_MAX;
    }

    // Step 3:-
    if(dp[amount] != -1) {
        dp[amount];
    }

    int mini = INT_MAX;

    for(int i=0; i<coins.size(); i++) {
        int ans = solveMem(coins, amount-coins[i], dp);

        if(ans != INT_MAX) {
            mini = min(mini, 1 + ans);
        }
    }
    // Step 2 :-
    dp[amount] = mini;
    return dp[amount];
}

// Tabulisation method
int solveTab(vector<int>& coins, int amount) {
    // step 1 - create dp array
    vector<int> dp(amount, INT_MAX);

    // step 2 - base case dekho
    dp[0] = 0;

    // step 3 - check the range and flow of top down approach and code accordingly
    for(int target=1; target<=amount; target++) {

        int mini = INT_MAX;

        for(int i=0; i<coins.size(); i++) {

            if(target - coins[i] >= 0) {
                int ans = dp[target-coins[i]];

                if(ans != INT_MAX) {
                    mini = min(mini, 1 + ans);
                }
            }            
        }
        dp[target] = mini;
    }
    return dp[amount];
}

int coinChange(vector<int>& coins, int amount) {
    // Using normal recursion
    // int ans = solveUsingRecursion(coins, amount);
    // if(ans == INT_MAX) {
    //     return -1;
    // }
    // else {
    //     return ans;
    // }

    // Top down approach
    // Step 1 :-
    // vector<int> dp(amount+1, -1);

    // int ans = solveMem(coins, amount, dp);
    // if(ans == INT_MAX) {
    //     return -1;
    // }
    // else {
    //     return ans;
    // }


    // Tabulation method
    int ans = solveTab(coins, amount);
    if(ans == INT_MAX) {
        return -1;
    }
    else {
        return ans;
    }
}

int main() {

    vector<int> coins{1,2,5};

    int amount = 11;

    cout<<"Answer is "<<solveUsingRecursion(coins, amount);


    return 0;
}
*/


// ******* LEET CODE 198 - HOUSE ROBBER *********
/*
#include <iostream>
#include <vector>
using namespace std;

// n - represent the index of current house
int solveUsingRecurion(vector<int>& nums, int n) {
    if(n < 0) {
        return 0;
    }

    if(n == 0) {
        return nums[0];
    }

    // include
    int include = solveUsingRecurion(nums, n-2) + nums[n];
    int exclude = solveUsingRecurion(nums, n-1) + 0;

    return max(include, exclude);
}

// Top down approach
int solveUsingMem(vector<int>& nums, int n, vector<int>& dp) {
     if(n < 0) {
        return 0;
    }

    if(n == 0) {
        return nums[0];
    }

    if(dp[n] != -1) {
        return dp[n];
    }

    // include
    int include = solveUsingMem(nums, n-2, dp) + nums[n];
    int exclude = solveUsingMem(nums, n-1, dp) + 0;

    dp[n] =  max(include, exclude);
    return dp[n];
}

int solvesUsingTabulation(vector<int>& nums, int n) {
    vector<int> dp(n+1, 0);

    dp[0] = nums[0];

    for(int i=1;i<=n; i++) {
        
        int temp = 0;
        if(i-2 >= 0 ) {
            temp = dp[i-2];
        }
        
        int include = temp + nums[i];
        int exclude = dp[i-1] + 0;

        dp[i] =  max(include, exclude);
    }
    return dp[n];
}

int spaceOptimisedSolution(vector<int>& nums, int n) {
    int prev2 = 0;
    int prev1 = nums[0];
    int curr = 0;

    for(int i=1;i<=n; i++) {
        
        int temp = 0;
        if(i-2 >= 0 ) {
            temp = prev2;
        }
        
        int include = temp + nums[i];
        int exclude = prev1 + 0;

        curr =  max(include, exclude);
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

int rob(vector<int>& nums) {
    int n = nums.size() - 1;
    // return solveUsingRecurion(nums, n);

    // vector<int> dp(n+1, -1);
    // return solveUsingMem(nums, n, dp);

    // return solvesUsingTabulation(nums, n);

    return spaceOptimisedSolution(nums, n);
}

int main() {
    
    vector<int> v{1,2,3,1};

    cout<<"Answer is "<<rob(v)<<endl;


    return 0;
}
*/


// *********** PAINTING FENCE ALGORITHM ********
/*
#include <iostream>
#include <vector>
using namespace std;

int solveUsingRecursion(int n, int k) {
    if(n == 1) {
        return k;
    }
    if(n == 2) {
        return (k+(k*(k-1)));
    }

    int ans = (solveUsingRecursion(n-2, k) + solveUsingRecursion(n-1, k))*(k-1);
    return ans;
}

int solveUsingMem(int n, int k, vector<int>& dp) {
    if(n == 1) {
        return k;
    }
    if(n == 2) {
        return (k+(k*(k-1)));
    }
    if(dp[n] != -1) {
        return dp[n];
    }

    dp[n] = (solveUsingMem(n-2, k, dp) + solveUsingMem(n-1, k, dp))*(k-1);
    return dp[n];
}

int solveUsingTab(int n, int k) {
    vector<int> dp(n+1, 0);
    dp[1] = k;
    dp[2] = (k+(k*(k-1)));

    for(int i=3; i<=n; i++) {
        dp[i] = (dp[i-2] + dp[i-1])*(k-1);
    }
    return dp[n];
}

int solveSpaceOptimised(int n, int k) {
    int prev2 = k;
    int prev1 = (k+(k*(k-1)));
    int curr;

    for(int i=3; i<=n; i++) {
        curr = (prev2 + prev1)*(k-1);
        // shift -> gayi hoti he galti bachho se
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

int main() {
    int n = 4;
    int k = 3;
    // int ans = solveUsingRecursion(n, k);
    // cout<<"Answer is "<<ans<<endl;

    // vector<int> dp(n+1, -1);
    // int ans = solveUsingMem(n, k, dp);
    // cout<<"Answer is "<<ans<<endl;

    // int ans = solveUsingTab(n, k);
    // cout<<"Answer is "<<ans<<endl;

    int ans = solveSpaceOptimised(n, k);
    cout<<"Answer is "<<ans<<endl;


    return 0;
}
*/


// ********** KNAPSAKE WEIGHT *********
/*
#include <iostream>
#include <vector>
using namespace std;

// index here -> index of last element
int solveUsingRecursion(int weight[], int value[], int index, int capacity) {
    // base case -> onlt 1 item
    if(index == 0) {
        if(weight[0] <= capacity) {
            return value[0];
        }
        else {
            return 0;
        }
    }

    // include and exclude
    int include = 0;
    if(weight[index] <= capacity) {
        include = value[index] + solveUsingRecursion(weight, value, index-1, capacity - weight[index]);
    }
    int exclude = 0 + solveUsingRecursion(weight, value, index-1, capacity);

    int ans =  max(include, exclude);
    return ans;
}

int solveUsingMem(int weight[], int value[], int index, int capacity, vector<vector<int> >& dp) {
    // base case -> onlt 1 item
    if(index == 0) {
        if(weight[0] <= capacity) {
            return value[0];
        }
        else {
            return 0;
        }
    }

    if(dp[index][capacity] != -1) {
        return dp[index][capacity];
    }

    // include and exclude
    int include = 0;
    if(weight[index] <= capacity) {
        include = value[index] + solveUsingMem(weight, value, index-1, capacity - weight[index], dp);
    }
    int exclude = 0 + solveUsingMem(weight, value, index-1, capacity, dp);

    dp[index][capacity] =  max(include, exclude);
    return dp[index][capacity];
}

int solveUsingTabulation(int weight[], int value[], int n, int capacity) {
    vector<vector<int> > dp(n, vector<int>(capacity+1, 0));

    for(int w=weight[0]; w<=capacity; w++) {
        if(weight[0] <= capacity) {
            dp[0][w] = value[0];
        }
        else {
            dp[0][w] =  0;
        }
    }

    for(int index=1; index<n; index++) {
        for(int wt=0; wt<=capacity; wt++) {
            int include = 0;
            if(weight[index] <= wt) {
                include = value[index] + dp[index-1][wt - weight[index]];
            }
            int exclude = 0 + dp[index-1][wt];

            dp[index][wt] =  max(include, exclude);
        }
    }
    return dp[n-1][capacity];
}

int solveUsingSpaceOptimisation(int weight[], int value[], int n, int capacity) {
    
    vector<int> prev(capacity+1, 0);
    vector<int> curr(capacity+1, 0);

    for(int w=weight[0]; w<=capacity; w++) {
        if(weight[0] <= capacity) {
            prev[w] = value[0];
        }
        else {
            prev[w] =  0;
        }
    }

    for(int index=1; index<n; index++) {
        for(int wt=0; wt<=capacity; wt++) {
            int include = 0;
            if(weight[index] <= wt) {
                include = value[index] + prev[wt - weight[index]];
            }
            int exclude = 0 + prev[wt];

            curr[wt] = max(include, exclude);
        }
        // shift -> yahi galti hoti he
        prev = curr;
    }
    return prev[capacity];
}

int solveUsingMoreSpaceOptimisation(int weight[], int value[], int n, int capacity) {

    vector<int> curr(capacity+1, 0);

    for(int w=weight[0]; w<=capacity; w++) {
        if(weight[0] <= capacity) {
            curr[w] = value[0];
        }
        else {
            curr[w] =  0;
        }
    }

    for(int index=1; index<n; index++) {
        for(int wt=capacity; wt>=0; wt--) {
            int include = 0;
            if(weight[index] <= wt) {
                include = value[index] + curr[wt - weight[index]];
            }
            int exclude = 0 + curr[wt];

            curr[wt] = max(include, exclude);
        }
    }
    return curr[capacity];
}

int main() {
    int weigth[] = {4,5,1};
    int value[] = {1,2,3};
    int n = 3;
    int capacity = 4;

    // int ans = solveUsingRecursion(weigth, value, n-1, capacity);  
    // cout<<"Answer is "<<ans<<endl;

    // vector<vector<int> > dp(n, vector<int>(capacity+1, -1));
    // int ans = solveUsingMem(weigth, value, n-1, capacity, dp);
    // cout<<"Answer is "<<ans<<endl;

    // int ans = solveUsingTabulation(weigth, value, n, capacity);
    // cout<<"Answer is "<<ans<<endl;

    // int ans = solveUsingSpaceOptimisation(weigth, value, n, capacity);
    // cout<<"Answer is "<<ans<<endl;

    int ans = solveUsingMoreSpaceOptimisation(weigth, value, n, capacity);
    cout<<"Answer is "<<ans<<endl;

    return 0;
}
*/


// ********** LLET CODE 416 PARTITION EQUAL SUBSET SUM ********
/*
#include <iostream>
#include <vector>
using namespace std;

bool solveUsingRecursion(int index, vector<int>& nums, int target) {
    // base case
    int n = nums.size();
    if(index >= n) {
        return 0;
    }

    if(target < 0) {
        return 0;
    }

    if(target == 0) {
        return 1;
    }

    int include = solveUsingRecursion(index+1, nums, target-nums[index]);
    int exclude = solveUsingRecursion(index+1, nums, target);

    return (include || exclude);
}

bool solveUsingMem(int index, vector<int>& nums, int target, vector<vector<int> >& dp) {
    // base case
    int n = nums.size();
    if(index >= n) {
        return 0;
    }

    if(target < 0) {
        return 0;
    }

    if(target == 0) {
        return 1;
    }

    if(dp[index][target] != -1) {
        return dp[index][target];
    }

    int include = solveUsingMem(index+1, nums, target-nums[index], dp);
    int exclude = solveUsingMem(index+1, nums, target, dp);

    dp[index][target] = (include || exclude);
    return dp[index][target];
}

bool solveUsingTabulation(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<int> > dp(n+1, vector<int>(target+1, -1));

    for(int i=0; i<n; i++) {
        dp[i][0] = 1;
    }

    for(int index=n-1; index>=0; index--) {
        for(int t=1; t>=target; t++) {

            bool include = 0;
            if(t-nums[index] >= 0) {
                include = dp[index+1][t-nums[index]];
            }
            bool exclude = dp[index+1][t];

            dp[index][t] = (include || exclude);
        }
    }
    return dp[0][target];
}

bool solveUsingTabulationSpaceOptimised(vector<int>& nums, int target) {
    int n = nums.size();

    vector<int> curr(target+1, 0);
    vector<int> next(target+1, 0);

    curr[0] = 1;
    next[0] = 1;

    for(int index=n-1; index>=0; index--) {
        for(int t=1; t<=target; t++) {

            bool include = 0;
            if(t-nums[index] >= 0) {
                include = next[t-nums[index]];
            }
            bool exclude = next[t];

            curr[t] = (include || exclude);
        }
        // shift 
        next = curr;
    }
    return next[target];
}

bool canPartition(vector<int>& nums) {
    int sum = 0;
    for(int i=0; i<nums.size(); i++) {
        sum += nums[i];
    }

    // yaha hi galti hoti he
    if(sum & 1) {
        return 0;
    }

    int target = sum/2;
    int index = 0;

    // Using recursion
    // bool ans = solveUsingRecursion(index, nums, target);


    // Using top down approach
    // vector<vector<int> > dp(nums.size(), vector<int>(target+1, -1));
    // int ans = solveUsingMem(index, nums, target, dp);
    // return ans;

    // Using tabulasation
    // int ans = solveUsingTabulation(nums, target);
    // return ans;

    // Using space optimisation
    return solveUsingTabulationSpaceOptimised(nums, target);
}

int main() {
    
    vector<int> nums{1,5,5,11};

    bool ans = canPartition(nums);
    cout<<"Answer is "<<ans<<endl;


    return 0;
}
*/


// ********* NO. OF DICE ROLE WITH TARGET SUM ********
/*
#include <iostream>
#include <vector>
using namespace std;

int solveUsingRecursion(int n, int k, int target) {
    // base case
    if(n < 0) {
        return 0;
    }

    if(n == 0 && target == 0) {
        return 1;
    }

    if(n == 0 && target != 0) {
        return 0;
    }

    if(n != 0 && target == 0) {
        return 0;
    }

    int ans = 0;
    for(int i=1; i<=k; i++) {
        ans += solveUsingRecursion(n-1, k, target-i);
    }

    return ans;
}

int solveUsingMem(int n, int k, int target, vector<vector<int>>& dp) {
    // base case
    if(n < 0) {
        return 0;
    }

    if(n == 0 && target == 0) {
        return 1;
    }

    if(n == 0 && target != 0) {
        return 0;
    }

    if(n != 0 && target == 0) {
        return 0;
    }

    if(dp[n][target] != -1) {
        return dp[n][target];
    }

    int ans = 0;
    for(int i=1; i<=k; i++) {
        int recAns = 0;
        if(target-i >= 0) {
            recAns = solveUsingMem(n-1, k, target-i, dp);
        }
        ans += recAns;
    }
    dp[n][target] = ans;
    return dp[n][target];
}

int solveUsingTabulation(int n, int k, int target) {
    vector<vector<int> >dp(n+1, vector<int> (target+1, 0));

    dp[0][0] = 1;

    for(int index = 1; index <= n; index++) {
        for(int t=1; t<=target; t++) {
            int ans = 0;
            for(int i=1; i<=k; i++) {
                int recAns = 0;
                if(t-i >= 0) {
                    recAns = dp[index-1][t-i];
                }
                ans += recAns;
            }
            dp[index][t] = ans;
        }
    }
    return dp[n][target];
}

int solveUsingTabulationSpaceOptimised(int n, int k, int target) {
    vector<int> prev(target+1, 0);
    vector<int> curr(target+1, 0);

    prev[0] = 1;

    for(int index = 1; index <= n; index++) {
        for(int t=1; t<=target; t++) {
            int ans = 0;
            for(int i=1; i<=k; i++) {
                int recAns = 0;
                if(t-i >= 0) {
                    recAns = prev[t-i];
                }
                ans += recAns;
            }
            curr[t] = ans;
        }
        // shifting
        prev = curr;
    }
    return prev[target];
}

int numRollsToTarget(int n, int k, int target) {
    vector<vector<int> >dp(n+1, vector<int> (target+1, -1));
    // return solveUsingRecursion(n,k,target);

    // return solveUsingMem(n,k,target,dp);

    // return solveUsingTabulation(n,k,target);

    return solveUsingTabulationSpaceOptimised(n,k,target);
}

int main() {
    int n = 2;
    int k = 6;
    int target = 7;

    int ans = numRollsToTarget(n,k,target);

    cout<<"Answer is "<<ans<<endl;


    return 0;
}
*/


// ********* LEET CODE 375 - GUESS NUMBER HIGER OR LOWER 2 *********
/*
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int solveUsingRecursion(int start, int end) {
    if(start >= end) {
        return 0;
    }

    int ans = INT_MAX;
    for(int i=start; i<=end; i++) {
        ans = min(ans, i + max(solveUsingRecursion(start,i-1), solveUsingRecursion(i+1, end)));
    }

    return ans;
}

int solveUsingMem(int start, int end, vector<vector<int>>& dp) {
    if(start >= end) {
        return 0;
    }
    if(dp[start][end] != -1) {
        dp[start][end];
    }

    int ans = INT_MAX;
    for(int i=start; i<=end; i++) {
        ans = min(ans, i + max(solveUsingMem(start,i-1, dp), solveUsingMem(i+1, end, dp)));
    }
    dp[start][end] = ans;
    return dp[start][end];
}

int solveUsingTab(int n) {
    vector<vector<int> > dp(n+2, vector<int>(n+2, 0));

    for(int start=n; start>=1; start--) {
        for(int end=1; end<=n; end++) {
            if(start >= end) {
                continue;
            }
            else {
                int ans = INT_MAX;
                for(int i=start; i<=end; i++) {
                    ans = min(ans, i+max(dp[start][i-1], dp[i+1][end]));
                }
                dp[start][end] = ans;
            }
        }
    }
    return dp[1][n];    
}

int getMoneyAmount(int n) {
    // int ans = solveUsingRecursion(1,n);

    // vector<vector<int> > dp(n+1, vector<int>(n+1, -1));
    // int ans = solveUsingMem(1,n,dp);

    int ans = solveUsingTab(n);
    return ans;
}

int main() {
    int n = 5;
    int ans = getMoneyAmount(n);

    cout<<"Answer is "<<ans<<endl;


    return 0;
}
*/


// ******** LEET CODE 1130 - MINIMUM COST TREE FROM LEAF VALUES *********
/*
#include <iostream>
#include <vector>
#include <map>
#include <limits.h>
using namespace std;

int solveUsingRecursion(vector<int>& arr, map<pair<int,int>,int>& maxi, int left, int right) {
    // base case
    if(left == right) {
        return 0;
    }

    int ans = INT_MAX;
    for(int i=left; i<right; i++) {
        ans = min(ans, 
        maxi[{left,i}] * maxi[{i+1, right}]
        + solveUsingRecursion(arr,maxi, left, i) 
        + solveUsingRecursion(arr,maxi, i+1, right));
    }

    return ans;
}

int solveUsingMem(vector<int>& arr, map<pair<int,int>,int>& maxi, int left, int right, vector<vector<int> >& dp) {
    // base case
    if(left == right) {
        return 0;
    }

    if(dp[left][right] != -1) {
        return dp[left][right];
    }

    int ans = INT_MAX;
    for(int i=left; i<right; i++) {
        ans = min(ans, 
        maxi[{left,i}] * maxi[{i+1, right}]
        + solveUsingMem(arr,maxi, left, i, dp) 
        + solveUsingMem(arr,maxi, i+1, right, dp));
    }

    dp[left][right] = ans;

    return dp[left][right];
}

int solveUsingTab(vector<int>& arr, map<pair<int,int>,int>& maxi) {
    int n = arr.size();

    vector<vector<int> >dp(n+1, vector<int>(n+1, 0));

    for(int left = n-1; left >= 0; left--) {
        for(int right = 0; right <= n-1; right++) {
            if(left >= right) {
                continue;
            }
            else {
                // valid range
                int ans = INT_MAX;
                for(int i=left; i<right; i++) {
                    ans = min(ans, 
                    maxi[{left,i}] * maxi[{i+1, right}]
                    + dp[left][i] 
                    + dp[i+1][right]);
                }
                dp[left][right] = ans;
            }
        }
    }
    return dp[0][n-1];
}

int mctFromLeafValuesI(vector<int>& arr) {
    map<pair<int,int>,int> maxi;
    // pre-computation
    for(int i=0; i<arr.size(); i++) {
        maxi[{i,i}] = arr[i];
        for(int j=i+1; j<arr.size(); j++) {
            maxi[{i,j}] = max(arr[j], maxi[{i,j-1}]);
        }
    }

    int n = arr.size();

    // int ans = solveUsingRecursion(arr, maxi, 0, n-1);

    // vector<vector<int> >dp(n+1, vector<int>(n+1, -1));
    // int ans = solveUsingMem(arr, maxi, 0, n-1, dp);

    int ans = solveUsingTab(arr, maxi);

    return ans;
}

int main() {
    vector<int> arr{6,2,4};

    int ans = mctFromLeafValuesI(arr);
    cout<<"Answer is "<<ans<<endl;


    return 0;
}
*/


// ********LEET CODE 1143 - LONGEST COMMON SUBSEQUENCE ********
/*
#include <iostream>
#include <vector>
using namespace std;

int solveUsingRecursion(string a, string b, int i, int j) {
    // base case
    if(i == a.length()) {
        return 0;
    }
    if(j == b.length()) {
        return 0;
    }

    int ans = 0;

    if(a[i] == b[j]) {
        ans = 1 + solveUsingRecursion(a,b,i+1,j+1);
    }

    else {
        ans =  0 + max(solveUsingRecursion(a,b,i,j+1), solveUsingRecursion(a,b,i+1,j));
    }

    return ans;
}

int solveUsingMem(string& a, string& b, int i, int j, vector<vector<int>>& dp) {
    // base case
    if(i == a.length()) {
        return 0;
    }
    if(j == b.length()) {
        return 0;
    }

    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    int ans = 0;

    if(a[i] == b[j]) {
        ans = 1 + solveUsingMem(a,b,i+1,j+1, dp);
    }

    else {
        ans =  0 + max(solveUsingMem(a,b,i,j+1, dp), solveUsingMem(a,b,i+1,j, dp));
    }

    dp[i][j] = ans;

    return dp[i][j];
}

int solveUsingTab(string a, string b) {
    vector<vector<int> >dp(a.length()+1, vector<int> (b.length()+1, 0));

    for(int i=a.length()-1; i>=0; i--) {
        for(int j=b.length()-1; j>=0; j--) {
            int ans = 0;
            if(a[i] == b[j]) {
                ans = 1 + dp[i+1][j+1];
            }

            else {
                ans =  0 + max(dp[i][j+1], dp[i+1][j]);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}

int solveUsingTabSpaceOptimised(string a, string b) {
    vector<int> curr(b.length()+1, 0);
    vector<int> next(b.length()+1, 0);

    for(int i=a.length()-1; i>=0; i--) {
        for(int j=b.length()-1; j>=0; j--) {
            int ans = 0;
            if(a[i] == b[j]) {
                ans = 1 + next[j+1];
            }

            else {
                ans =  0 + max(curr[j+1], next[j]);
            }
            curr[j] = ans;
        }
        // shift
        next = curr;
    }
    return next[0];
}

int longestCommomSubsequence(string text1, string text2) {
    // int i = 0;
    // int j = 0;
    // vector<vector<int> >dp(text1.length(), vector<int> (text2.length(), -1)); 

    // return solveUsingRecursion(text1, text2, i, j);

    // return solveUsingMem(text1, text2, i, j, dp);

    // return solveUsingTab(text1, text2);

    return solveUsingTabSpaceOptimised(text1, text2);
}

int main() {
    
    string a = "abcde";
    string b = "ace";

    int ans = longestCommomSubsequence(a,b);

    cout<<"Answer is "<<ans<<endl;

    return 0;
}
*/


// ********** CONVERT ONE WORD INTO ANOTHER WITH MINIMUM NUMBER OF OPEARTIONS ********
/*
#include <iostream>
#include <vector>
using namespace std;

int solveUsingRecursion(string& a, string& b, int i, int j) {
    // base case
    if(i == a.length()) {
        return b.length() - j;
    }
    if(j == b.length()) {
        return a.length() - i;
    }

    int ans = 0;

    if(a[i] == b[j]) {
        ans = solveUsingRecursion(a,b,i+1,j+1);
    }
    else {
        // operation perform karo
        int insert = 1 + solveUsingRecursion(a,b,i,j+1);
        int deleted = 1 + solveUsingRecursion(a,b,i+1,j);
        int replace = 1 + solveUsingRecursion(a,b,i+1,j+1);

        ans = min(insert, min(deleted, replace));
    }

    return ans;
}

int solveUsingMem(string& a, string& b, int i, int j, vector<vector<int> >& dp) {
    // base case
    if(i == a.length()) {
        return b.length() - j;
    }
    if(j == b.length()) {
        return a.length() - i;
    }

    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    int ans = 0;

    if(a[i] == b[j]) {
        ans = solveUsingMem(a,b,i+1,j+1, dp);
    }
    else {
        // operation perform karo
        int insert = 1 + solveUsingMem(a,b,i,j+1, dp);
        int deleted = 1 + solveUsingMem(a,b,i+1,j, dp);
        int replace = 1 + solveUsingMem(a,b,i+1,j+1, dp);

        ans = min(insert, min(deleted, replace));
    }

    dp[i][j] =  ans;

    return dp[i][j];
}

int solveUsingTab(string a, string b) {
    vector<vector<int> > dp(a.length()+1, vector<int>(b.length()+1, -1));

    for(int j=0; j<b.length(); j++) {
        dp[a.length()][j] = b.length()-j;
    }
    for(int i=0; i<=a.length(); i++) {
        dp[i][b.length()] = a.length()-i;
    }

    for(int i=a.length()-1; i>=0; i--) {
        for(int j=b.length()-1; j>=0; j--) {
            int ans = 0;

            if(a[i] == b[j]) {
                ans = dp[i+1][j+1];
            }
            else {
                // operation perform karo
                int insert = 1 + dp[i][j+1];
                int deleted = 1 + dp[i+1][j];
                int replace = 1 + dp[i+1][j+1];

                ans = min(insert, min(deleted, replace));
            }
            dp[i][j] =  ans;
        }

    }
    return dp[0][0];
}


int solveUsingTabSpaceOptimised(string a, string b) {
    //vector<vector<int> > dp(a.length()+1, vector<int>(b.length()+1, -1));

    vector<int> curr(b.length()+1, 0);
    vector<int> next(b.length()+1, 0);

    for(int j=0; j<b.length(); j++) {
        next[j] = b.length()-j;
    }

    for(int i=a.length()-1; i>=0; i--) {
        // every row starts here
        // yaha galti hogi
        curr[b.length()] = a.length()-i;

        for(int j=b.length()-1; j>=0; j--) {
            int ans = 0;

            if(a[i] == b[j]) {
                ans = next[j+1];
            }
            else {
                // operation perform karo
                int insert = 1 + curr[j+1];
                int deleted = 1 + next[j];
                int replace = 1 + next[j+1];

                ans = min(insert, min(deleted, replace));
            }
            curr[j] =  ans;
        }
        // shift 
        next = curr;
    }
    return next[0];
}

int minDistance(string word1, string word2) {
    if(word1.length() == 0) {
        return word2.length();
    }

    if(word2.length() == 0) {
        return word1.length();
    }

    int i = 0;
    int j = 0;

    // return solveUsingRecursion(word1, word2, i, j);

    //vector<vector<int> > dp(word1.length(), vector<int>(word2.length(), -1));

    // return solveUsingMem(word1,word2,i,j,dp);

    // return solveUsingTab(word1, word2);

    return solveUsingTabSpaceOptimised(word1, word2);
}

int main() {
    string a = "horse";
    string b = "ros";

    int ans = minDistance(a,b);

    cout<<"Answer is "<<ans<<endl;



    return 0;
}
*/


// ********** LONGEST INCRESING SUBSEQUENCE **********
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solveUsingRecursion(vector<int>& arr, int curr, int prev) {
    // base case
    if(curr >= arr.size()) {
        return 0;
    }

    // include
    int include = 0;
    if(prev == -1 || arr[curr] > arr[prev]) {
        include = 1 + solveUsingRecursion(arr, curr+1, curr);
    }

    // exclude
    int exclude = 0 + solveUsingRecursion(arr, curr+1, prev);

    int ans = max(include, exclude);

    return ans;
}

int solveUsingMem(vector<int>& arr, int curr, int prev, vector<vector<int>>& dp) {
    // base case
    if(curr >= arr.size()) {
        return 0;
    }
    
    if(dp[curr][prev+1] != -1) {
        return dp[curr][prev+1];
    }

    // include
    int include = 0;
    if(prev == -1 || arr[curr] > arr[prev]) {
        include = 1 + solveUsingMem(arr, curr+1, curr, dp);
    }

    // exclude
    int exclude = 0 + solveUsingMem(arr, curr+1, prev, dp);

    dp[curr][prev+1] = max(include, exclude);

    return dp[curr][prev+1];
}

int solveUsingTab(vector<int>& arr) {
    int n = arr.size();
    vector<vector<int> >dp(n+1, vector<int>(n+1, 0));

    for(int curr=n-1; curr>=0; curr--) {
        for(int prev=curr-1; prev>=-1; prev--) {
            // include
            int include = 0;
            if(prev == -1 || arr[curr] > arr[prev]) {

                include = 1 + dp[curr+1][curr+1];
            }

            // exclude
            int exclude = 0 + dp[curr+1][prev+1];

            dp[curr][prev+1] = max(include, exclude);
        }
    }
    return dp[0][-1+1];
}

int solveUsingTabSpaceOptimised(vector<int>& arr) {
    int n = arr.size();
    vector<int> currRow(n+1, 0);
    vector<int> nextRow(n+1, 0);

    for(int curr=n-1; curr>=0; curr--) {
        for(int prev=curr-1; prev>=-1; prev--) {
            // include
            int include = 0;
            if(prev == -1 || arr[curr] > arr[prev]) {

                include = 1 + nextRow[curr+1];
            }

            // exclude
            int exclude = 0 + nextRow[prev+1];

            currRow[prev+1] = max(include, exclude);
        }
        nextRow = currRow;
    }
    return nextRow[-1+1];
}

int solveOptimal(vector<int>& arr) {
    if(arr.size() == 0) {
        return 0;
    }
    vector<int> ans;

    ans.push_back(arr[0]);

    for(int i=1; i<arr.size(); i++) {
        if(arr[i] > ans.back()) {
            // include
            ans.push_back(arr[i]);
        }
        else {
            // overwrite
            // find index of just bada element
            int index = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
            ans[index] = arr[i];
        }
    }
    return ans.size();
}

int lengthOfLIS(vector<int>& nums) {
    int curr = 0;
    int prev = -1;
    // int ans = solveUsingRecursion(nums, curr, prev);
    int n = nums.size();
    vector<vector<int> >dp(n, vector<int>(n+1, -1));

    // int ans = solveUsingMem(nums, curr, prev, dp);

    // int ans = solveUsingTab(nums);

    // int ans = solveUsingTabSpaceOptimised(nums);

    int ans = solveOptimal(nums);
    return ans;
}

int main() {
    vector<int> nums{10,9,2,5,3,7,101,18};

    int ans = lengthOfLIS(nums);

    cout<<"Answer is "<<ans<<endl;


    return 0;
}
*/


// ********** LEET CODE 1691 - MAXIMUM HEIGHT BY STACKING CUBOIDS ********
/*
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& a, vector<int>& b) {
    if(b[0] <= a[0] && b[1] <= a[1] && b[2] <= a[2]) {
        return true;
    }
    else {
        return false;
    }
}

int solveUsingTabSpaceOptimised(vector<vector<int>>& arr) {
    int n = arr.size();
    vector<int> currRow(n+1, 0);
    vector<int> nextRow(n+1, 0);

    for(int curr=n-1; curr>=0; curr--) {
        for(int prev=curr-1; prev>=-1; prev--) {
            // include
            int include = 0;
            if(prev == -1 || check(arr[curr], arr[prev])) {
                include = arr[curr][2] + nextRow[curr+1];
            }

            // exclude
            int exclude = 0 + nextRow[prev+1];

            currRow[prev+1] = max(include, exclude);
        }
        nextRow = currRow;
    }
    return nextRow[-1+1];
}

int maxHeight(vector<vector<int>>& cuboids) {
    // sort every arrays
    for(auto &a: cuboids) {
        sort(a.begin(), a.end());
    }

    // sort the 2D array
    sort(cuboids.begin(), cuboids.end());

    // apply lis logic
    int ans = solveUsingTabSpaceOptimised(cuboids);
    return ans;
}

int main() {
    
    vector<vector<int> > cuboids{{50,45,20},{95,37,53},{45,23,12}};

    int ans = maxHeight(cuboids);
    cout<<"Answer is - "<<ans<<endl;


    return 0;
}
*/


// ********* LEET CODE 279 - PERFECT SQAURES ************
/*
#include <iostream>
#include <vector>
#include <math.h>
#include <limits.h>
using namespace std;

// Top down DP
int numSquareHelper(int n, vector<int>& dp) {
    // base case
    if(n == 0) {
        return 1;
    }
    if(n < 0) {
        return 0;
    }

    if(dp[n] != -1) {
        return dp[n];
    }

    int ans = INT_MAX;
    int i = 1;
    int end = sqrt(n);
    while(i <= end) {
        int perfectSquare = i*i;
        int numberOfPerfectSqaures = 1 + numSquareHelper(n - perfectSquare, dp);
        if(numberOfPerfectSqaures < ans) {
            ans = numberOfPerfectSqaures;
        }
        i++;
    }

    dp[n] = ans;
    return dp[n];
}

// Bottom Up Dp
int numSquareHelperBU(int n, vector<int>& dp) {
    // base case
    dp[0] = 1;

    for(int i=1; i<=n; i++) {
        int ans = INT_MAX;
        int start = 1;
        int end = sqrt(i);
        while(start <= end) {
            int perfectSquare = start*start;
            int numberOfPerfectSqaures = 1 + dp[i - perfectSquare];
            if(numberOfPerfectSqaures < ans) {
                ans = numberOfPerfectSqaures;
            }
            start++;
        }

        dp[i] = ans;
    }
    return dp[n];
}

int numSquares(int n) {
    vector<int> dp(n+1, -1);
    // top down
    // return numSquareHelper(n, dp) - 1;

    // bottom up
    return numSquareHelperBU(n, dp) - 1;
}

int main() {
    
    int n = 13;

    int ans = numSquares(n);

    cout<<"Asnwer is: "<<ans<<endl;

    return 0;
}
*/


// ********** LEET CODE 983 - MINIMUM COST FOR TICKETS *********
/*
#include <iostream>
#include <vector>
using namespace std;

// top down dp
int minCostsTickets_helper(vector<int>& days, vector<int>& costs, int i, vector<int>& dp) {
    // base case
    if( i>= days.size()) {
        return 0;
    }

    if(dp[i] != -1) {
        return dp[i];
    }
    
    // solution for one case
    // 1 day pass taken
    int cost1 = costs[0] + minCostsTickets_helper(days, costs, i+1, dp);

    // 7 days pass taken
    int passEndDay = days[i] + 7 - 1;
    int j = i;
    while( j < days.size() && days[j] <= passEndDay) {
        j++;
    }
    int cost7 = costs[1] + minCostsTickets_helper(days, costs, j, dp);


    // 30 days pass taken
    passEndDay = days[i] + 30 - 1;
    j = i;
    while( j < days.size() && days[j] <= passEndDay) {
        j++;
    }
    int cost30 = costs[2] + minCostsTickets_helper(days, costs, j, dp);

    dp[i] = min(cost1, min(cost7, cost30));

    return dp[i];
}

// bottom up dp
int minCostsTickets_helperBU(vector<int>& days, vector<int>& costs, int i, vector<int>& dp) {
    // base case
    dp[days.size()] = 0;

    for(int i=days.size()-1; i>=0; i--) {
        // solution for one case
        // 1 day pass taken
        int cost1 = costs[0] + dp[i+1];

        // 7 days pass taken
        int passEndDay = days[i] + 7 - 1;
        int j = i;
        while( j < days.size() && days[j] <= passEndDay) {
            j++;
        }
        int cost7 = costs[1] + dp[j];


        // 30 days pass taken
        passEndDay = days[i] + 30 - 1;
        j = i;
        while( j < days.size() && days[j] <= passEndDay) {
            j++;
        }
        int cost30 = costs[2] + dp[j];

        dp[i] = min(cost1, min(cost7, cost30));
    }
    return dp[0];
}

int minCostTickets(vector<int>& days, vector<int>& costs) {
    // vector<int> dp(days.size(), -1);
    // return minCostsTickets_helper(days, costs, 0, dp); 

    vector<int> dp(days.size()+1, -1);
    return minCostsTickets_helperBU(days, costs, 0, dp);    
}

int main() {
    
    vector<int> days = {1,4,6,7,8,20};
    vector<int> costs = {2,7,15};

    int ans = minCostTickets(days, costs);

    cout<<"Answer is "<<ans<<endl;

    return 0;
}
*/