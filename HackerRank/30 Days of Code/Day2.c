#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    double mealCost, finalBill;
    int tipPercent, taxPercent;
    scanf("%lf\n",&mealCost);
    scanf("%d\n",&tipPercent);    
     scanf("%d\n",&taxPercent);  
    finalBill = ((double)tipPercent/100)*mealCost + ((double)taxPercent/100)*mealCost + mealCost;
    printf("The total meal cost is %.0lf dollars.",(finalBill));
    
    return 0;
}
