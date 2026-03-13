class Solution {
public:
    vector<vector<string>> ans;
    vector<string> path;

    void backtrack(int start, string& s, vector<vector<bool>>& dp) {
        if (start == s.size()) {
            ans.push_back(path);
            return;
        }

        for (int end = start; end < s.size(); end++) {
            if (dp[start][end]) {
                path.push_back(s.substr(start, end - start + 1));
                backtrack(end + 1, s, dp);
                path.pop_back();
            }
        }
    }n
    vector<vector<string>> partition(string s) {
        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                }
            }
        }
        backtrack(0, s, dp);
        return ans;
    }
};