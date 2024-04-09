class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char , int>CHAR;
        for(auto &ch: s){
            CHAR[ch]++;}
            string result;
        for(auto &ch: order){
            if(CHAR.find(ch)!=CHAR.end()){
                result.append(CHAR[ch], ch);
                CHAR.erase(ch);
            }
        }
        for(auto &ch: CHAR){
            result.append(ch.second, ch.first);
        }
        return result;
    }
};