#include <stdio.h>

#define NUM_MONTHS 12

void readSales(double sales[]) {
    char filename[100]; // Assuming filename won't exceed 100 characters
    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");

    for (int i = 0; i < NUM_MONTHS; i++) {
        fscanf(file, "%lf", &sales[i]);
    }

    fclose(file);
}

void printReport(double sales[], char* months[]) {
    printf("Monthly sales report for 2022:\n\n");

    // Tabular report of month and sales
    printf("Month\tSales\n");
    int i;
    for (i = 0; i < NUM_MONTHS; i++) {
        printf("%-9s $%.2f\n", months[i], sales[i]);
    }

    // Sales summary
    double totalSales = 0;
    double minSales = sales[0];
    double maxSales = sales[0];
    int minMonth = 0;
    int maxMonth = 0;

    for (i = 0; i < NUM_MONTHS; i++) {
        totalSales += sales[i];

        if (sales[i] < minSales) {
            minSales = sales[i];
            minMonth = i;
        }

        if (sales[i] > maxSales) {
            maxSales = sales[i];
            maxMonth = i;
        }
    }

    double averageSales = totalSales / NUM_MONTHS;

    printf("---------------------------------------------------------------\n");
    printf("Sales Summary:\n");
    printf("Minimum sales: $%.2f (%s)\n", minSales, months[minMonth]);
    printf("Maximum sales: $%.2f (%s)\n", maxSales, months[maxMonth]);
    printf("Average sales: $%.2f\n", averageSales);

    // Six-month moving average
    printf("---------------------------------------------------------------\n");
    printf("Six-Month Moving Average Report\n");
	float total;
	for (int i=5; i<12; i++){
		float total=0;
		for (int j= i-5; j<=i; j++)
			total+=sales[j];
		printf("%-9s - %-9s: $%.2f\n", months[i-5], months[i], total/6);
	}


    // Sorted listing of months and sales
    printf("---------------------------------------------------------------\n");
    printf("Sales Report (Highest to Lowest):\n");
    printf("Month\tSales\n");
    double sortedSales[NUM_MONTHS];
    char* sortedMonths[NUM_MONTHS];
    for (i = 0; i < NUM_MONTHS; i++) {
        sortedSales[i] = sales[i];
        sortedMonths[i] = months[i];
    }

    char* tempMonth;
    for (i = 0; i < NUM_MONTHS - 1; i++) {
        for (int j = i + 1; j < NUM_MONTHS; j++) {
            if (sortedSales[i] < sortedSales[j]) {
                double temp = sortedSales[i];
                sortedSales[i] = sortedSales[j];
                sortedSales[j] = temp;
                
                tempMonth = sortedMonths[i];
                sortedMonths[i] = sortedMonths[j];
                sortedMonths[j] = tempMonth;
            }
        }
    }

    for (i = 0; i < NUM_MONTHS; i++) {
        printf("%-9s $%.2f\n", sortedMonths[i], sortedSales[i]);
    }
}

int main() {
    double sales[NUM_MONTHS];
    char* months[NUM_MONTHS] = {"January", "February", "March", "April", "May", "June",
                                 "July", "August", "September", "October", "November", "December"};

    readSales(sales);
    printReport(sales, months);

    return 0;
}
