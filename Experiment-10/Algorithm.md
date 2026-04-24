# Distinct Subsequences

## Problem

Given two strings `s` and `t`, return the number of distinct subsequences of `s` that equals `t`.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not).

## Approach

We use dynamic programming to solve this problem. The idea is to count the number of ways to form the string `t` as a subsequence of `s`.

We define `dp[i][j]` as the number of distinct subsequences of the first `i` characters of `s` that match the first `j` characters of `t`.

To optimize space, we use two arrays: `prev` and `curr`, where `prev[j]` represents the number of ways for the previous row (i-1), and `curr[j]` for the current row (i).

### Initialization
- `prev[0] = 1`: There is 1 way to form an empty string (by doing nothing).

### Transition
For each character in `s` (from index 0 to n1-1):
- `curr[0] = 1`: Always 1 way to form empty string.
- For each position `j` in `t` (from 1 to n2):
  - If `s[i-1] == t[j-1]`, then we have two choices:
    - Use this character: `prev[j-1]` (ways to match first j-1 chars)
    - Don't use this character: `prev[j]` (ways without this char)
    - So `curr[j] = prev[j-1] + prev[j]`
  - Else, we can't use this character, so `curr[j] = prev[j]`

Then set `prev = curr` for the next iteration.

### Result
The answer is `prev[n2]`, the number of ways to match the entire string `t`.

## Code

```cpp
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int n1 = s.size(), n2 = t.size();
        vector<double> prev(n2 + 1, 0), curr(n2 + 1, 0);

        prev[0] = 1;
        for (int i = 1; i <= n1; i++)
        {
            curr[0] = 1;
            for (int j = 1; j <= n2; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    curr[j] = prev[j - 1] + prev[j];
                }
                else
                {
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }

        return (int)prev[n2];
    }
};
```

## Time Complexity

O(n1 * n2), where n1 is the length of `s` and n2 is the length of `t`.

## Space Complexity

O(n2), using two vectors of size n2+1.

## Notes

- The code uses `vector<double>` to handle potentially large numbers, but in practice, for large inputs, we might need to use `long long` or handle overflow differently.
- This is a classic dynamic programming problem for subsequence counting.