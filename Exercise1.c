#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MONTHS 12
#define MAX_LINE 20

int main() {

    char line[MAX_LINE];
    float sales[MONTHS]= {23458.01,40112.00,56011.85,37820.88,37904.67,60200.22,72400.31,56210.89,67230.84,68233.12,80950.34,95225.22};
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    // Monthly Sales Report
    printf("Monthly Sales Report for 2024\n");
    printf("Month\tSales\n");
    for (int i = 0; i < MONTHS; i++) {
        printf("%s\t%.2f\n", months[i], sales[i]);
    }

    // Sales Summary Report
    float min_sales = sales[0];
    float max_sales = sales[0];
    float avg_sales = 0;
    char *min_month = months[0];
    char *max_month = months[0];
    for (int i = 0; i < MONTHS; i++) {
        if (sales[i] < min_sales) {
            min_sales = sales[i];
            min_month = months[i];
        }
        if (sales[i] > max_sales) {
            max_sales = sales[i];
            max_month = months[i];
        }
        avg_sales += sales[i];
    }
    avg_sales /= MONTHS;
    printf("\nSales summary report:\n");
    printf("Minimum sales: %.2f (%s)\n", min_sales, min_month);
    printf("Maximum sales: %.2f (%s)\n", max_sales, max_month);
    printf("Average sales: %.2f\n", avg_sales);

    // Six-Month Moving Average Report
    printf("\nSix-Month moving average report:\n");
    for (int i = 0; i < 7; i++) {
        float avg = 0;
        for (int j = 0; j < 6; j++) {
            avg += sales[i + j];
        }
        avg /= 6;
        printf("%s-%s\t%.2f\n", months[i], months[i + 5], avg);
    }

    // Sales Report (Highest to Lowest)
    printf("\nSales report (highest to lowest):\n");
    printf("Month\tSales\n");
    int indices[MONTHS];
    for (int i = 0; i < MONTHS; i++) {
        indices[i] = i;
    }
    for (int i = 0; i < MONTHS; i++) {
        for (int j = i + 1; j < MONTHS; j++) {
            if (sales[indices[i]] < sales[indices[j]]) {
                int temp = indices[i];
                indices[i] = indices[j];
                indices[j] = temp;
            }
        }
    }
    for (int i = 0; i < MONTHS; i++) {
        printf("%s\t$%.2f\n", months[indices[i]], sales[indices[i]]);
    }

    return 0;
}