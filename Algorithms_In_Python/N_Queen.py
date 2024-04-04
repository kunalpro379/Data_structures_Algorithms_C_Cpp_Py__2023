

# n rani code in backtracking
#

def N_RANI_UTIL(board ,col):
    #i f all quens are placed then return true
    if col>=n:
        return True
    #placing rani at safe place
    for i in range(n):
        if IS_RANI_SAFE(board,i,col):
            board[i][col]=1
            #checking for next column
            if N_RANI_UTIL(board,col+1)==True:
                return True
            #if rani isnt placed in company
            board[i][col]=0#backtracking
    return False
def IS_RANI_SAFE(board,row,col):
    #checking row on the left side
    for i in range(col):
        if board[row][i]==1:
            return False
    #checking upper diagonal on the left side
    i=row
    j=col
    while i>=0 and j>=0:
        if board[i][j]==1:
            return False
        i-=1
        j-=1

    #checking lower diagonal on the left side
    i=row
    j=col
    while i<n and j>=0:
        if board[i][j]==1:
            return False
        i+=1
        j-=1

    return True
            
def printSolution(board):
    for i in range(n):
        for j in range(n):
            print(board[i][j],end=" ")
        print()
def N_RANI(n):
    #creating chess board
    board=[[0 for x in range(n) ]for x in range(n)]

    #checking rani's placement is safe or not
    if N_RANI_UTIL(board ,0)==False:
        print("solution nahi banega")
        return False
    printSolution(board)

if __name__ == "__main__":
    board=[[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0]]
    n=4
    N_RANI(n)
    

