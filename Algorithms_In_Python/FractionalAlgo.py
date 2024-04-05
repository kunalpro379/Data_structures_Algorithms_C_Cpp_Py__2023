def FractionalKnapSack(weights,vals,capacity):
    valueperweight = [(vals[i]/weights[i], weights[i], vals[i]) for i in range(len(weights))]

    valueperweight.sort(reverse=True)
    totalvalue=0#selected items 
    remainingcapacity=capacity
    for valueperweight, weights, vals in valueperweight:
        if remainingcapacity>=weights:
            totalvalue+=vals*weights
            remainingcapacity-=weights
        else:
            totalvalue+=vals*valuesperweight
            remainingcapacity=0
            break
    return totalvalue
if __name__ == "__main__":
    weights = [10, 20, 30]
    values = [60, 100, 120]
    capacity = 50
    max_total_value = FractionalKnapSack(weights, values, capacity)
    print("Maximum total value:", max_total_value)
