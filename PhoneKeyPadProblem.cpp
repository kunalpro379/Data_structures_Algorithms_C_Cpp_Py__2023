//backtracking
/*Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]

*/

class Solution {
public:

void solve(string digit, string output, int index,vector<string>&ans, string mapping[]){
//base case
if(index>=digit.length()){
    ans.push_back(output);
    return;
}
int number=digit[index]-'0';
string value=mapping[number];

for(int i=0;i<value.length();i++){
output.push_back(value[i]);
solve(digit,output,index+1,ans,mapping);
output.pop_back();

}



}


public:

    vector<string> letterCombinations(string digits) {
        
vector<string>ans;
if(digits.length()==0){
return ans;

}
 string output = ""; 
int index=0;
string mapping[10]={"","", "abc", "def","ghi","jkl","mno","pqrs","tuv", "wxyz"};
//creating mappintg
solve(digits,output,index,ans,mapping);
return ans ;



    }
};