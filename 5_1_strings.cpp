************************************************** START **************************************************

/*Test - 5 
Q1.
You are given an array of strings. You can merge two strings, arr[i] and arr[j], only if,
i < j  and the last letter of arr[i] == first letter of arr[j]
Eg, you have two strings -> “123” and “389” -> after merging it becomes “123389”
You can keep merging strings like this, but the ‘final’ string you form must be such that the first letter of the string should be the same as the last letter.
Eg, after merging several strings, the ‘final’ string becomes -> “123389…………1”
Print the max length of the ‘final’ string that can be formed in this way.
Test case - 1:
Array of strings = [“14”, “123”, “323”, “321”,  “421”, “535”]
Possible ‘final’ strings -> “323”, “535”, “14421”, “123323321”, “123321”
Ans = 9 (which is the length of “123323321”) 
Test case – 2:
Array of strings = [“14”, “15”, “89”, “22”]
Possible ‘final’ strings -> “22”
Ans = 2 (which is the length+ of “22”)
1 <= ai <=1e9.  1 <=N<= 1e5
/*
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
void solve() {
int n;
if (!(cin >> n)) return;
vector<string> arr(n);
for (int i = 0; i < n; i++) {
cin >> arr[i];
}
// dp[i][j] will store the maximum length of a merged string
// that starts with digit 'i' and ends with digit 'j'.
// Initialized to -1 to represent unreachable/invalid states.
vector<vector<long long>> dp(10, vector<long long>(10, -1));
for (int i = 0; i < n; i++) {
string s = arr[i];
int len = s.length();
int first_digit = s.front() - '0';
int last_digit = s.back() - '0';
// We use a temporary DP table for transitions to ensure we don't
// use the same string multiple times in a single step.
vector<vector<long long>> next_dp = dp;
// 1. Try to append current string 's' to existing valid sequences
// We look for any sequence that ends with our 'first_digit'
for (int start_digit = 0; start_digit <= 9; start_digit++) {
if (dp[start_digit][first_digit] != -1) {
next_dp[start_digit][last_digit] = max(
next_dp[start_digit][last_digit],
dp[start_digit][first_digit] + len
);
}
}
// 2. The current string can also act as the start of a brand new sequence
next_dp[first_digit][last_digit] = max(
next_dp[first_digit][last_digit],
(long long)len
);
// Commit the state for the next iteration
dp = next_dp;
}
// The question asks for a 'final' string where the FIRST letter == LAST letter.
// We check the diagonal of our DP table: dp[0][0], dp[1][1], ..., dp[9][9]
long long max_ans = 0;
for (int i = 0; i <= 9; i++) {
if (dp[i][i] > max_ans) {
max_ans = dp[i][i];
}
}
cout << max_ans << "\n";
}
int main() {
// Fast I/O
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;
}

******************************************** DONE ************************************************************
