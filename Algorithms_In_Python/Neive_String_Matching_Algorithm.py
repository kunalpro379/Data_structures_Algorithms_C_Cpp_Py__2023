#pattern searching is  searching string wihin another string
# Naive String Matching Algorithm
#complexity O(n*m)
#simplest methiod to search pattern in text
#compares the first charachter in of pattern with searchable text
#if mathc is found pointer in bothe the strings are incremented
#if not found pointer is incremented and pointer of pattern in rest to 0
#complexity O(m*(n-1))
#n- len of text  m- len of pattern

def search(pat, txt):
    m=len(pat)
    n=len(txt)
    for i in range(n-m+1):
#  txt="AABAACAADAABCAAABAA" len ->19    19-4+1=16  to avoid waste of memory and time
# pat="AABA" len ->4
        j=0
        while(j<m):
            if txt[i+j]!=pat[j]:
                break
            j+=1 
        if j==m:#j==4
            print("Pattern found at index",i)
    



if __name__ == "__main__":
                txt = "AABAACAADAABCAAABAA"
                pat = "AABA"
                search(pat, txt)
