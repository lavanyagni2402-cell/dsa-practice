#include <stdio.h>

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int totalGas = 0, totalCost = 0;
    int tank = 0;
    int start = 0;

    for (int i = 0; i < gasSize; i++) {
        totalGas += gas[i];
        totalCost += cost[i];

        tank += gas[i] - cost[i];

        if (tank < 0) {
            start = i + 1;
            tank = 0;
        }
    }

    if (totalGas < totalCost)
        return -1;

    return start;
}

int main() {
    int gas[] = {1, 2, 3, 4, 5};
    int cost[] = {3, 4, 5, 1, 2};
    int n = sizeof(gas) / sizeof(gas[0]);

    printf("%d\n", canCompleteCircuit(gas, n, cost, n));

    return 0;
}