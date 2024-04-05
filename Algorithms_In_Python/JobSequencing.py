def JobSequencing(jobs, t):
    n = len(jobs)

    # Sorting jobs according to decreasing order of profit
    for i in range(n):
        for j in range(n - i - 1):
            if jobs[j][2] < jobs[j + 1][2]:
                jobs[j], jobs[j + 1] = jobs[j + 1], jobs[j]

    result = [False] * t  # To keep track of free time slots
    job = ['-1'] * t  # Storing the job sequence
    max_profit = 0  #  maximum profit

    for i in range(n):
        latest_slot = min(t - 1, jobs[i][1] - 1)
        # Start from the latest possible slot and iterate backwards
        for j in range(latest_slot, -1, -1):
            if not result[j]:
                result[j] = True
                job[j] = jobs[i][0]  # Assign the job ID to the time slot
                max_profit += jobs[i][2]  # Add profit of the scheduled job to max profit
                break

    print("Job sequence:", job)
    print("Maximum profit:", max_profit)

if __name__ == "__main__":
    arr = [['a', 2, 100],  
           ['b', 1, 19],
           ['c', 2, 27],
           ['d', 1, 25],
           ['e', 3, 15]]

    print("Following is maximum profit sequence of jobs")
    JobSequencing(arr, 10)
