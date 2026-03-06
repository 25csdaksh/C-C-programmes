#include <stdio.h>

#define CHILD_PRICE 100
#define ADULT_PRICE 150
#define SENIOR_PRICE 250
#define DISCOUNT_RATE 0.10

#define CHILD_MIN 3
#define CHILD_MAX 15
#define ADULT_MIN 16
#define ADULT_MAX 60
#define SENIOR_MIN 61

// Function prototypes
int calculatePrice(int age);
void printBill(int totalAdults, int totalChildren, int totalSeniors, int groupSize, int n);

int main() {
    int groupSize, n, age;
    int totalAdults = 0, totalChildren = 0, totalSeniors = 0;

    printf("\n\t*** WELCOME TO SUNRISE AMUSEMENT PARK ***\n");

    printf("\nEnter the number of people in the group: ");
    scanf("%d", &groupSize);

    if (groupSize <= 0) {
        printf("Invalid group size. Exiting...\n");
        return 1;
    }

    printf("\nAge Classification:");
    printf("\n - Age %d to %d: Children (₹%d)", CHILD_MIN, CHILD_MAX, CHILD_PRICE);
    printf("\n - Age %d to %d: Adults   (₹%d)", ADULT_MIN, ADULT_MAX, ADULT_PRICE);
    printf("\n - Age %d and above: Seniors (₹%d)\n", SENIOR_MIN, SENIOR_PRICE);

    printf("\nEnter the number of members for billing: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of members. Exiting...\n");
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        printf("\nEnter age of member %d: ", i);
        scanf("%d", &age);

        if (age >= CHILD_MIN && age <= CHILD_MAX) {
            totalChildren++;
        } else if (age >= ADULT_MIN && age <= ADULT_MAX) {
            totalAdults++;
        } else if (age >= SENIOR_MIN) {
            totalSeniors++;
        } else {
            printf("Invalid age entered. Skipping...\n");
        }
    }

    printBill(totalAdults, totalChildren, totalSeniors, groupSize, n);

    return 0;
}

// Function to calculate price based on age
int calculatePrice(int age) {
    if (age >= CHILD_MIN && age <= CHILD_MAX) return CHILD_PRICE;
    else if (age >= ADULT_MIN && age <= ADULT_MAX) return ADULT_PRICE;
    else if (age >= SENIOR_MIN) return SENIOR_PRICE;
    else return 0;
}

// Function to print the final bill
void printBill(int totalAdults, int totalChildren, int totalSeniors, int groupSize, int n) {
    int totalPrice = (totalAdults * ADULT_PRICE) +
                     (totalChildren * CHILD_PRICE) +
                     (totalSeniors * SENIOR_PRICE);

    printf("\n\t*** BILLING SUMMARY ***\n");
    printf("-----------------------------------\n");
    printf("Children : %d × ₹%d = ₹%d\n", totalChildren, CHILD_PRICE, totalChildren * CHILD_PRICE);
    printf("Adults   : %d × ₹%d = ₹%d\n", totalAdults, ADULT_PRICE, totalAdults * ADULT_PRICE);
    printf("Seniors  : %d × ₹%d = ₹%d\n", totalSeniors, SENIOR_PRICE, totalSeniors * SENIOR_PRICE);
    printf("-----------------------------------\n");

    printf("Total members billed: %d\n", n);
    printf("Total before discount: ₹%d\n", totalPrice);

    if (groupSize >= 5) {
        float discount = totalPrice * DISCOUNT_RATE;
        float finalPrice = totalPrice - discount;
        printf("Group discount (10%%): -₹%.2f\n", discount);
        printf("Grand Total          : ₹%.2f\n", finalPrice);
    } else {
        printf("No group discount applied.\n");
        printf("Grand Total          : ₹%d\n", totalPrice);
    }
    printf("-----------------------------------\n");
}
