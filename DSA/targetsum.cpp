
#include <bits/stdc++.h>
using namespace std;

const int mod = (int)1e9 + 7;

// Function to count the number of ways to achieve the target sum
int findWays(vector<int> &num, int tar) {
    int n = num.size();

    vector<int> prev(tar + 1, 0);

    if (num[0] == 0)
        prev[0] = 2;  // 2 cases - pick and not pick
    else
        prev[0] = 1;  // 1 case - not pick

    if (num[0] != 0 && num[0] <= tar)
        prev[num[0]] = 1;  // 1 case - pick

    for (int ind = 1; ind < n; ind++) {
        vector<int> cur(tar + 1, 0);
        for (int target = 0; target <= tar; target++) {
            int notTaken = prev[target];

            int taken = 0;
            if (num[ind] <= target)
                taken = prev[target - num[ind]];

            cur[target] = (notTaken + taken) % mod;
        }
        prev = cur;
    }
    return prev[tar];
}

// Function to calculate the number of ways to achieve the target sum
int targetSum(int n, int target, vector<int>& arr) {
    int totSum = 0;
    for (int i = 0; i < n; i++) {
        totSum += arr[i];
    }

    // Checking for edge cases
    if (totSum - target < 0 || (totSum - target) % 2 != 0)
        return 0;  // Not possible to achieve the target sum

    return findWays(arr, (totSum - target) / 2);
}

int main() {
    vector<int> arr = {1, 2, 3, 1};
    int n = arr.size();
    int target = 3;

    cout << "The number of subsets found is " << targetSum(n, target, arr) << endl;

    return 0;  // Return 0 to indicate successful program execution
}
