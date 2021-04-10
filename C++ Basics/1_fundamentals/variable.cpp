#include <cstdio>

int main() {
    // type identifier = value;
    double price = 99.80;
    double tax = 0.08;

    // type identifier = exp;
    double finalPrice = price * (1 + tax);

    // print finalPrice || %f = to assign float || %.2f = to assing 2decimal float
    printf("The final price is %f. \n", finalPrice);
    printf("The final price is %.2f.", finalPrice);
    return 0;
}