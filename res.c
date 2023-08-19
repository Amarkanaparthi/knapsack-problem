#include<stdio.h>

double maxProfit(int capacity, int weights[], int profits[], int numItems, double ratios[]) {
    double totalProfit = 0.0;
    int remainingCapacity = capacity;
    int i = 0;

    int weightsCopy[numItems];
    int profitsCopy[numItems];
    double ratiosCopy[numItems];

    for (i = 0; i < numItems; i++) {
        weightsCopy[i] = weights[i];
        profitsCopy[i] = profits[i];
        ratiosCopy[i] = ratios[i];
    }

    while (remainingCapacity != 0 && numItems > 0) {
        int maxProfitIndex = 0;
        int max = profitsCopy[0];

        for (i = 0; i < numItems; i++) {
            if (profitsCopy[i] > max) {
                max = profitsCopy[i];
                maxProfitIndex = i;
            }
        }

        if (weightsCopy[maxProfitIndex] <= remainingCapacity) {
            totalProfit +=profitsCopy[maxProfitIndex] ;
            remainingCapacity -= weightsCopy[maxProfitIndex];
            printf("\n %d \t %d \t %d \n",profitsCopy[maxProfitIndex] , weightsCopy[maxProfitIndex], remainingCapacity);
        } else {
            totalProfit +=(ratiosCopy[maxProfitIndex] * remainingCapacity) ;

            printf("\n %lf \t %d \t %d \n ", (ratiosCopy[maxProfitIndex] * remainingCapacity), remainingCapacity,0);
            remainingCapacity = 0;
        }

        for (i = maxProfitIndex; i < numItems - 1; i++) {
            profitsCopy[i] = profitsCopy[i + 1];
            weightsCopy[i] = weightsCopy[i + 1];
            ratiosCopy[i] = ratiosCopy[i + 1];
        }
        numItems--;
    }

    return totalProfit;
}


double minWeight(int capacity, int weights[], int profits[], int numItems, double ratios[]) {
    double totalProfit = 0.0;
    int remainingCapacity = capacity;
    int i = 0;

    int weightsCopy[numItems];
    int profitsCopy[numItems];
    double ratiosCopy[numItems];

    for (i = 0; i < numItems; i++) {
        weightsCopy[i] = weights[i];
        profitsCopy[i] = profits[i];
        ratiosCopy[i] = ratios[i];
    }

    while (remainingCapacity != 0 && numItems > 0) {
        int minWeightIndex = 0;
        int min = weightsCopy[0];

        for (i = 0; i < numItems; i++) {
            if (weightsCopy[i] < min) {
                min = weightsCopy[i];
                minWeightIndex = i;
            }
        }

        if (weightsCopy[minWeightIndex] <= remainingCapacity) {
            totalProfit += profitsCopy[minWeightIndex];
            remainingCapacity -= weightsCopy[minWeightIndex];
            printf("\n %d \t %d \t %d \n",profitsCopy[minWeightIndex] , weightsCopy[minWeightIndex], remainingCapacity);
        } else {
            totalProfit += (ratiosCopy[minWeightIndex] * remainingCapacity);
            printf("\n %lf \t %d \t %d \n ", (ratiosCopy[minWeightIndex] * remainingCapacity), remainingCapacity,0);
                  remainingCapacity = 0;

        }

        for (i = minWeightIndex; i < numItems - 1; i++) {
            profitsCopy[i] = profitsCopy[i + 1];
            weightsCopy[i] = weightsCopy[i + 1];
            ratiosCopy[i] = ratiosCopy[i + 1];
        }
        numItems--;
    }

    return totalProfit;
}

double maxRatio(int capacity, int weights[], int profits[], int numItems, double ratios[]) {
    double totalProfit = 0.0;
    int remainingCapacity = capacity;
    int i = 0;

    int weightsCopy[numItems];
    int profitsCopy[numItems];
    double ratiosCopy[numItems];

    for (i = 0; i < numItems; i++) {
        weightsCopy[i] = weights[i];
        profitsCopy[i] = profits[i];
        ratiosCopy[i] = ratios[i];
    }

    while (remainingCapacity != 0 && numItems > 0) {
        int maxRatioIndex = 0;
        double max = ratiosCopy[0];

        for (i = 0; i < numItems; i++) {
            if (ratiosCopy[i] > max) {
                max = ratiosCopy[i];
                maxRatioIndex = i;
            }
        }

        if (weightsCopy[maxRatioIndex] <= remainingCapacity) {
            totalProfit += profitsCopy[maxRatioIndex];
            remainingCapacity -= weightsCopy[maxRatioIndex];
            printf("\n %d \t %d \t %d \n",profitsCopy[maxRatioIndex] , weightsCopy[maxRatioIndex], remainingCapacity);
        } else {
            totalProfit += (ratiosCopy[maxRatioIndex] * remainingCapacity);
            printf("\n %lf \t %d \t %d \n ", (ratiosCopy[maxRatioIndex] * remainingCapacity),remainingCapacity,0);
                        remainingCapacity = 0;

        }

        for (i = maxRatioIndex; i < numItems - 1; i++) {
            profitsCopy[i] = profitsCopy[i + 1];
            weightsCopy[i] = weightsCopy[i + 1];
            ratiosCopy[i] = ratiosCopy[i + 1];
        }
        numItems--;
    }

    return totalProfit;
}






int main() {
    int capacity, numItems;

    printf("Welcome to the Knapsack Problem Solver!\n");

    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    int weights[numItems];
    int profits[numItems];

    for (int i = 0; i < numItems; i++) {
        printf("Enter weight and profit for item %d: ", i + 1);
        scanf("%d %d", &weights[i], &profits[i]);
    }


         double ratios[numItems];
        int i,j;
        double a;

    for (int i = 0; i < numItems; i++) {
        ratios[i] = (double)profits[i] / weights[i];
    }

      for (i = 0; i < numItems; i++)
        {
            for (j = i + 1; j < numItems; j++)
            {
                if (ratios[i] < ratios[j])
                {
                    a = profits[i];
                    profits[i] = profits[j];
                    profits[j] = a;

                     a = weights[i];
                    weights[i] = weights[j];
                    weights[j] = a;

                     a = ratios[i];
                    ratios[i] = ratios[j];
                    ratios[j] = a;

                }
            }
        }
    printf("weight \t profit \t ratio\n");
    for(i=0;i<numItems;i++)
    {
        printf("%d \t %d \t %lf \n",weights[i],profits[i],ratios[i]);
    }


    double maxTotalProfit = 0.0;
    double minWeightProfit = 0.0;
    double maxRatioProfit = 0.0;

    int choice;
       do {
        printf("\nMenu:\n");
        printf("1. max profit\n");
        printf("2. min weight\n");
        printf("3. max profit per unit weight\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                maxTotalProfit = maxProfit(capacity, weights, profits, numItems,ratios);
                printf("Maximum total profit with max ratio: %.2lf\n", maxTotalProfit);
                break;
//
           case 2:
                minWeightProfit = minWeight(capacity, weights, profits, numItems,ratios);
                printf("Maxmium profit with minimum weight: %.2lf\n", minWeightProfit);
                break;
             case 3:
                maxRatioProfit = maxRatio(capacity,weights, profits, numItems,ratios);
                printf("Maximum profit with max ratio: %.2lf\n", maxRatioProfit);
                break;

            case 4:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please choose again.\n");
        }
    } while (1);

    return 0;

}


