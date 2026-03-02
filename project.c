#include <stdio.h>

int main() {
    int length, breadth;

    printf("Enter the length of the rectangle: ");
    if (scanf("%d", &length) != 1 || length <= 0) {
        printf("Invalid input! Length must be a positive integer.\n");
        return 1;
    }

    printf("Enter the breadth of the rectangle: ");
    if (scanf("%d", &breadth) != 1 || breadth <= 0) {
        printf("Invalid input! Breadth must be a positive integer.\n");
        return 1;
    }

    int area = length * breadth;
    printf("Rectangle dimensions: %d x %d\n", length, breadth);
    printf("The area of the rectangle is: %d\n", area);

    return 0;
}
