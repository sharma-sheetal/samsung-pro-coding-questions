// ****************************************************** START ***************************************************

/*
You will be given a necklace having only red and blue stones in it. Your task is to make the number of blue and red stones equal. 
Stones can only be removed from either the left or right end. 
Return the minimum number of stones that are to be removed to complete the given task.

For eg, input: BBRRBRBRBRBBR
            output: 1

//  try this
Length of string - (longest length of subarray with equal no of “A” and ‘B’) 
/*
*/


// Method-1

#include <iostream>
#include <map>
#include <string>
using namespace std;


int main(){
    string s;
    cin >> s;
    int n = s.size(), maxLen = 0, prefix = 0;
    map<int, int> first;
    first[0] = -1;


    for (int i = 0; i < n; i++){
        prefix += (s[i] == 'R' ? 1 : -1);
        if (first.find(prefix) == first.end())
            first[prefix] = i;
        else {
            int len = i - first[prefix];
            if (len > maxLen) maxLen = len;
        }
    }
   
    cout << n - maxLen << "\n";
    return 0;
}


// Method-2


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void solve() {
string s;
if (!(cin >> s)) return;
int n = s.length();
// Instead of an unordered_map which has O(1) average but O(N) worst-case
// due to hash collisions, we use a raw vector for guaranteed strict O(1) lookups.
// The prefix sum can range from -N (all 'B's) to +N (all 'R's).
// Therefore, we need an array of size 2N + 1, and we offset the sum by N.
vector<int> first_occurrence(2 * n + 1, -2);
int current_sum = 0;
int max_len = 0;
// Base case: A prefix sum of 0 conceptually exists at index -1
// (before the string even starts). Offset by +n.
first_occurrence[0 + n] = -1;
for (int i = 0; i < n; i++) {
// Treat 'R' as +1 and 'B' as -1 (the assignment order doesn't matter)
current_sum += (s[i] == 'R' ? 1 : -1);
// If we have seen this prefix sum before, the subarray between that
// previous index and our current index evaluates to exactly 0 (Equal Rs and Bs).
if (first_occurrence[current_sum + n] != -2) {
max_len = max(max_len, i - first_occurrence[current_sum + n]);
} else {
// If this is the first time seeing this sum, record its earliest index
first_occurrence[current_sum + n] = i;
}
}
// The minimum stones to remove is the total length minus the longest valid subarray
cout << n - max_len << "\n";
}
int main() {
// Fast I/O for Competitive Programming
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;
}

******************************************************** DONE ***********************************************************
