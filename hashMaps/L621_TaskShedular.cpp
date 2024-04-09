
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        ///frequecny of each task
        unordered_map<char,int>Taskfreq;
        for(char task: tasks){
            Taskfreq[task]++;
        }
        // task with the max frequency
        int maxFreq=0;
        for(const auto& pair: Taskfreq){
            maxFreq=max(maxFreq,pair.second);
        }
        //getting total time
        int totalTime=(maxFreq-1)*(n+1);

// Considering cooldown periods
int numMaxFreqTasks = 0; 
for (const auto& pair : Taskfreq) {
    if (pair.second == maxFreq) {
        numMaxFreqTasks++; // Increment here
    }
}
        totalTime+=numMaxFreqTasks;
        return max(totalTime,static_cast<int>(tasks.size()));//keep cooldown period not longer than the no of tasks


    }
};
