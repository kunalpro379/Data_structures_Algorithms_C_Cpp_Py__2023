#include<iostream>
#include<string.h>
using namespace std;
#include<algorithm>
#include<stdio.h>
/*
Given a text txt[0 . . . N-1] and a pattern pat[0 . . . M-1], 
write a function search(char pat[], char txt[]) that prints all occurrences of pat[]
 in txt[]. You may assume that N > M. 
*/
//longest proper prefixes which is also a suffix
void computeLPSArray(char* pat,int M,int* lps){
int len=0;
lps[0]=0;
int i=1;
//lps[i] 
while(i<M){
if(pat[i]==pat[len]){
len++;

lps[i]=len;
i++;
}
else{
    if(len!=0){
        len=lps[len-1];
    }
    else{
        lps[i]=0;
        i++;
    }
}
}

}
void KMPSearch(char* pat, char* txt) {
    int M = strlen(pat);
    int N = strlen(txt);
    int lps[M];//holding longest prefix suffix 
    computeLPSArray(pat,M,lps);
    int i=0;
    int j=0;
    while(i<N){
        if(pat[j]==txt[i]){i++;j++;}
        if(j==M){cout<<"Pattern Found at index::::"<<i-j<<endl;
        j=lps[j-1];
        }
        else if(i<N&& pat[j]!=txt[i]){
            if(j!=0){j=lps[j-1];}
            else{i=i+1;}
        }
    }

}

//time complexity O(M+N)
//auxiliary space O(M)  
int main()
{
    char txt[] = "ABABDABACDABABCABAB";
    char pat[] = "ABABCABAB";
    KMPSearch(pat, txt);
    return 0;
}