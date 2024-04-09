class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        std::vector<int> squares;

        for (int num : nums) {
            squares.push_back(num * num);
        }

        std::sort(squares.begin(), squares.end());

        return squares;
    }
};