#include <stdio.h>

#define CHILD_PRICE 100
#define ADULT_PRICE 150
#define SENIOR_PRICE 250
#define DISCOUNT_RATE 0.10

// Function prototypes
int calculatePrice(int age);
void printBill(int totalAdults, int totalChildren, int totalSeniors, int groupSize);

int main() {
    int groupSize, n, age;
    int totalAdults = 0, totalChildren = 0, totalSeniors = 0;

    printf("\t*** WELCOME TO SUNRISE AMUSEMENT PARK ***\n");

    printf("\nEnter the number of people in the group: ");
    scanf("%d", &groupSize);

    printf("\nAge Classification:");
    printf("\n - Age 3 to 15: Children (₹%d)", CHILD_PRICE);
    printf("\n - Age 16 to 60: Adults (₹%d)", ADULT_PRICE);
    printf("\n - Age above 60: Seniors (₹%d)\n", SENIOR_PRICE);

    printf("\nEnter the number of members for billing: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("\nEnter age of member %d: ", i);
        scanf("%d", &age);

        if (age >= 3 && age <= 15) {
            totalChildren++;
        } else if (age >= 16 && age <= 60) {
            totalAdults++;
        } else if (age > 60) {
            totalSeniors++;
        } else {
            printf("Invalid age entered. Skipping...\n");
        }
    }

    printBill(totalAdults, totalChildren, totalSeniors, groupSize);

    return 0;
}

// Function to calculate price based on age
int calculatePrice(int age) {
    if (age >= 3 && age <= 15) return CHILD_PRICE;
    else if (age >= 16 && age <= 60) return ADULT_PRICE;
    else if (age > 60) return SENIOR_PRICE;
    else return 0;
}

// Function to print the final bill
void printBill(int totalAdults, int totalChildren, int totalSeniors, int groupSize) {
    int totalPrice = (totalAdults * ADULT_PRICE) +
                     (totalChildren * CHILD_PRICE) +
                     (totalSeniors * SENIOR_PRICE);

    printf("\n\t*** BILLING SUMMARY ***\n");
    printf("Children : %d × ₹%d = ₹%d\n", totalChildren, CHILD_PRICE, totalChildren * CHILD_PRICE);
    printf("Adults   : %d × ₹%d = ₹%d\n", totalAdults, ADULT_PRICE, totalAdults * ADULT_PRICE);
    printf("Seniors  : %d × ₹%d = ₹%d\n", totalSeniors, SENIOR_PRICE, totalSeniors * SENIOR_PRICE);

    printf("\nTotal before discount: ₹%d", totalPrice);

    if (groupSize >= 5) {
        int discount = totalPrice * DISCOUNT_RATE;
        int finalPrice = totalPrice - discount;
        printf("\nGroup discount (10%%): -₹%d", discount);
        printf("\nTotal after discount : ₹%d\n", finalPrice);
    } else {
        printf("\nNo group discount applied.\n");
    }
}
