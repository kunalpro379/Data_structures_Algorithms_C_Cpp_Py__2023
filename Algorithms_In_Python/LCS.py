def longestCommonSubString(s1,s2):
    m,n=len(s1),len(s2)
    #initializing the table
    dp=[[0]*(n+1) for _ in range(m+1)]
    maxLen=0
    endInd=0
    for i in range(1,m+1):
        for j in range(1,n+1):
            if s1[i-1]==s2[j-1]:
                dp[i][j]=dp[i-1][j-1]+1
                if dp[i][j]>maxLen:
                    maxLen=dp[i][j]
                    endInd=i
            else:
                dp[i][j]=0
    return s1[endInd-maxLen:endInd]


if __name__=="__main__":
    s1 = "abcdefg"
    s2 = "xyzabcde"
    print("Longest Common Substring:", longestCommonSubString(s1, s2))