#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
private:
    bool isPalindrome(string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    void BackTrack(string &s, int start, vector<string> &current, vector<vector<string>> &result) {
        if (start == s.length()) {
            result.push_back(current);
            return;
        }

        // if (!memo[start].empty()) {
        //     result.insert(result.end(), memo[start].begin(), memo[start].end());
        //     return;
        // }

        for (int end = start; end < s.length(); end++) {
            if (isPalindrome(s, start, end)) {
                current.push_back(s.substr(start, end - start + 1));
                BackTrack(s, end + 1, current, result);
                current.pop_back();
            }
        }

        //memo[start] = result;
        // return result;
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> current;
        //vector<vector<string>> memo(s.length());
        BackTrack(s, 0, current, result);
        return result;
    }
};