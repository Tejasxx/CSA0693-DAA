#include <stdio.h>
#include <stdlib.h>
struct Item {
    int value;
    int weight;
};
int compare(const void *a, const void *b) {
    double ratioA = ((double)((struct Item *)a)->value) / ((struct Item *)a)->weight;
    double ratioB = ((double)((struct Item *)b)->value) / ((struct Item *)b)->weight;
    
    if (ratioA > ratioB)
        return -1;
    else if (ratioA < ratioB)
        return 1;
    else
        return 0;
}
double fractionalKnapsack(int capacity, struct Item items[], int n) {
    qsort(items, n, sizeof(struct Item), compare);
    
    double totalValue = 0.0;
    
    for (int i = 0; i < n; i++) {
        if (capacity == 0)
            break;
        
        if (items[i].weight <= capacity) {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            totalValue += ((double)items[i].value / items[i].weight) * capacity;
            capacity = 0;
        }
    }
    
    return totalValue;
}

int main() {
    int n, capacity;
    
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    struct Item items[n];
    
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    
    printf("Enter the values and weights of the items:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }
    
    double maxValue = fractionalKnapsack(capacity, items, n);
    printf("Maximum value in the knapsack: %.2lf\n", maxValue);
    
    return 0;
}

