#include<stdio.h>

int main()
{
    int groupSize, children, adults, seniors, billingChoice;
    int age, n, i, totalPrice = 0, adultCount = 0;

    printf("\t*** WELCOME TO SUNRISE AMUSEMENT PARK ***\n");

    printf("\nEnter the number of people present in the group: ");
    scanf("%d", &groupSize);

    if (groupSize >= 5) {
        printf("\n10 percent discount will be applied.\n");
    } else {
        printf("\nNo discount.\n");
    }

    printf("\nAge Classification:");
    printf("\n - Age 3 to 15: Children");
    printf("\n - Age 15 to 60: Adults");
    printf("\n - Age above 60: Seniors\n");

    printf("\nEnter the number of children: ");
    scanf("%d", &children);
    printf("Entry price for one child is ₹100.\n");

    printf("\nEnter the number of adults: ");
    scanf("%d", &adults);
    printf("Entry price for one adult is ₹150.\n");

    printf("\nEnter the number of seniors: ");
    scanf("%d", &seniors);
    printf("Entry price for one senior is ₹250.\n");

    printf("\nEnter 0 to go to billing section: ");
    scanf("%d", &billingChoice);

    if (billingChoice == 0) {
        printf("\n\t*** WELCOME TO BILLING SECTION ***\n");

        printf("\nEnter the number of members : ");
        scanf("%d", &n);

        for (i = 1; i <= n; i++) {
            printf("\nEnter age of member %d: ", i);
            scanf("%d", &age);

            if (age >= 3 && age <= 15) {
                printf("Free entry as a child.\n");
            } else if (age > 15 && age <= 60) {
                printf("Entry fee is ₹100.\n");
                totalPrice += 100;
                adultCount++;
            } else if (age > 60) {
                printf("Free entry as a senior citizen.\n");
            } else {
                printf("Invalid age entered.\n");
            }
        }

        printf("\nTotal adult entries billed: %d", adultCount);
        printf("\nTotal amount before discount: ₹%d", totalPrice);

        if (groupSize >= 5) {
            int discount = totalPrice * 0.10;
            int finalPrice = totalPrice - discount;
            printf("\n10%% group discount applicable: ₹%d", discount);
            printf("\nTotal amount after discount: ₹%d", finalPrice);
        } else {
            printf("\nNo group discount applied.");
        }
    }

    return 0;
}
