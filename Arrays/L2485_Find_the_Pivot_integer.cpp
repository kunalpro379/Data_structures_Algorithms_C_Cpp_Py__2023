class Solution {
public:
    int pivotInteger(int n) {
        int suml = 0;
        int sumr = 0;
        int i = 1;
        int j = n;

        while (i <= j) {
            if (suml < sumr) {
                suml += i;
                i++;
            } else if (suml > sumr) {
                sumr += j;
                j--;
            } else { // suml == sumr
                if (i == j) // 
                    return i;
                else { // i and j not crossed
                    suml += i;
                    sumr += j;
                    i++;
                    j--;
                }
            }
        }
        
        return -1; // No pivot 
    }
};
