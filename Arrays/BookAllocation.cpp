class Solution 
{
public:
    bool isPossible(int A[], int N, int M, int mid) {
        int studentCount = 1;  // number of students needed
        int pageSum = 0;  // current sum of pages

        for(int i = 0; i < N; i++) {
            if (pageSum + A[i] > mid) {  
                studentCount++; 
                pageSum = A[i]; 
                if (studentCount > M || A[i] > mid) { 
                    return false;
                }
            } else {
                pageSum += A[i];
            }
        }
        return true;  
    }

    int findPages(int A[], int N, int M) {
        if (M > N) return -1;  

        int s = 0;
        for (int i = 0; i < N; i++) {
            s = max(s, A[i]);  
        }
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += A[i];  
        }
        int e = sum;
        int ans = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2; 
            if (isPossible(A, N, M, mid)) {
                ans = mid;  
                e = mid - 1; 
            } else {
                s = mid + 1; 
            }
        }
        return ans;  
    }
};