


def knapsack(weights,values,capacity):
    n =len(weights)
    dp=[[0]* (capacity+1) for _ in range(n+1)]
    #filling the table
    for i in range(1,n+1):
        for w in range(1,capacity+1):
            #if current items weight is less than or equal to capacity
            if weights[i-1]<=w:
                dp[i][w]=max(values[i-1]+dp[i-1][w-weights[i-1]],dp[i-1][w])
            else:
                dp[i][w]=dp[i-1][w]
    return dp[n][capacity]

if __name__ == "__main__":
    weights = [10, 20, 30]
    values = [60, 100, 120]
    capacity = 50
    max_total_value = knapsack(weights, values, capacity)
    print("Maximum total value:", max_total_value)
