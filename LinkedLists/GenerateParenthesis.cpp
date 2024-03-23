#include <vector>
#include <string>

class Solution {
public:
    void generate(std::vector<std::string>& res, std::string cur, int open, int close, int n) {
        if (cur.length() == 2 * n) {
            res.push_back(cur);
            return;
        }

        if (open < n)
            generate(res, cur + '(', open + 1, close, n);

        if (close < open)
            generate(res, cur + ')', open, close + 1, n);

        return;
    }

    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> res;
        generate(res, "", 0, 0, n);
        return res;
    }
};
