#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ids[100], customerCount = 0, isPrepaids[100];
char names[100][50], phones[100][15];
float balances[100];

void addCustomer() {
    printf("Enter Customer ID: ");
    scanf("%d", &ids[customerCount]);
    printf("Enter Customer Name: ");
    scanf("%s", names[customerCount]);
    printf("Enter Phone Number: ");
    scanf("%s", phones[customerCount]);
    printf("Enter Customer Type (1 for Prepaid, 0 for Postpaid): ");
    scanf("%d", &isPrepaids[customerCount]);
    balances[customerCount] = 0;
    customerCount++;
    for(int i=1;i<=50;i++)
    printf("-");
    printf("\n\tStatus : Customer added successfully!\n");
    for(int i=1;i<=50;i++)
    printf("-");
    printf("\n");
}

void addCharge(int id, float charge) {
    for (int i = 0; i < customerCount; i++) {
        if (ids[i] == id) {
            balances[i] += charge;
            for(int i=1;i<=50;i++)
            printf("-");
            printf("\n");
            printf("\tStatus : Charge added successfully!\n");
            for(int i=1;i<=50;i++)
            printf("-");
            printf("\n");
            return;
        }
    }
    printf("Customer not found.\n\n");
}

void displayCustomers() {
    if (customerCount == 0) {
        printf("No customers available.\n");
        return;
    }
    for(int i=1;i<=30;i++)
    printf("*");
    printf("\n-- CUSTOMER LIST --\n");
    for(int i=1;i<=30;i++)
    printf("*");
    printf("\n");
    for (int i = 0; i < customerCount; i++) {
        printf("ID : %d\n", ids[i]);
        printf("Name : %s\n", names[i]);
        printf("Phone : %s\n", phones[i]);
        printf("Balance : %.2f\n", balances[i]);
        printf("Type : %s\n", isPrepaids[i] ? "Prepaid" : "Postpaid");
        printf("\n");
    }
}

void updateCustomer(int id) {
    for (int i = 0; i < customerCount; i++) {
        if (ids[i] == id) {
            printf("Enter the new name: ");
            scanf("%s", names[i]);
            printf("Enter new phone number: ");
            scanf("%s", phones[i]);
            printf("\nStatus : Customer details updated successfully!\n\n");
            return;
        }
    }
    printf("Status : Customer with ID %d not found.\n", id);
}

void searchCustomer(char *searchTerm, int searchType) {
    int found = 0;
    for (int i = 0; i < customerCount; i++) {
        int match = 0;
        if (searchType == 1 && ids[i] == atoi(searchTerm)) {
            match = 1; 
        } else if (searchType == 2 && strcmp(names[i], searchTerm) == 0) {
            match = 1; 
        } else if (searchType == 3 && strcmp(phones[i], searchTerm) == 0) {
            match = 1; 
        } else if (searchType == 4 && balances[i] == atof(searchTerm)) {
            match = 1; 
        }

        if (match) {
            if (!found) {
                for(int i=1;i<=20;i++)
                printf("*");
                printf("\nCustomers found:\n");
                for(int i=1;i<=20;i++)
                printf("*");
                printf("\n");
                found = 1;
            }
            printf("ID : %d\n", ids[i]);
            printf("Name : %s\n", names[i]);
            printf("Phone : %s\n", phones[i]);
            printf("Balance : %.2f\n", balances[i]);
            printf("Type : %s\n\n", isPrepaids[i] ? "Prepaid" : "Postpaid");
        }
    }
    if (!found) {
        printf("No customers found for the given search criteria.\n\n");
    }
}

void deleteCustomer(int id) {
    int found = 0;
    for (int i = 0; i < customerCount; i++) {
        if (ids[i] == id) {
            found = 1;
            for (int j = i; j < customerCount - 1; j++) {
                ids[j] = ids[j + 1];
                strcpy(names[j], names[j + 1]);
                strcpy(phones[j], phones[j + 1]);
                isPrepaids[j] = isPrepaids[j + 1];
                balances[j] = balances[j + 1];
            }
            customerCount--;
            printf("\nStatus : Customer deleted successfully!\n\n");
            break;
        }
    }
    if (!found) {
        printf("Status : Customer with ID %d not found.\n", id);
    }
}

void rechargeBalance(int id, float amount) {
    for (int i = 0; i < customerCount; i++) {
        if (ids[i] == id) {
            balances[i] += amount;
            printf("\nStatus : Balance recharged successfully!\n\n");
            return;
        }
    }
    printf("Status : Customer with ID %d not found.\n", id);
}

void generateDetailedBill(int id) {
    float totalCharge;
    int minutes;

    for (int i = 0; i < customerCount; i++) {
        if (ids[i] == id) {
            printf("Enter total call minutes: ");
            scanf("%d", &minutes);

            totalCharge = minutes * 5;

            if (isPrepaids[i]) {
                if (balances[i] >= totalCharge) {
                    balances[i] -= totalCharge;
                    printf("\n-- DETAILED PREPAID BILL GENERATED --\n");
                    printf("Customer ID : %d\n", ids[i]);
                    printf("Customer Name : %s\n", names[i]);
                    printf("Phone Number : %s\n", phones[i]);
                    printf("Total Minutes : %d\n", minutes);
                    printf("Charge per Minute : 5.00\n");
                    printf("Total Charge : %.2f\n", totalCharge);
                    printf("Remaining Balance : %.2f\n\n", balances[i]);
                } else {
                    printf("\nInsufficient balance. Please recharge!\n\n");
                }
            } else {
                balances[i] += totalCharge;
                printf("\n-- DETAILED POSTPAID BILL GENERATED --\n");
                printf("Customer ID : %d\n", ids[i]);
                printf("Customer Name : %s\n", names[i]);
                printf("Phone Number : %s\n", phones[i]);
                printf("Total Minutes : %d\n", minutes);
                printf("Charge per Minute : 5.00\n");
                printf("Total Charge : %.2f\n", totalCharge);
                printf("Updated Balance : %.2f\n\n", balances[i]);
            }
            return;
        }
    }
    printf("Customer not found.\n\n");
}

void sortCustomersByName() {
    for (int i = 0; i < customerCount - 1; i++) {
        for (int j = i + 1; j < customerCount; j++) {
            if (strcmp(names[i], names[j]) > 0) {
                int tempId = ids[i];
                ids[i] = ids[j];
                ids[j] = tempId;

                char tempName[50];
                strcpy(tempName, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], tempName);

                char tempPhone[15];
                strcpy(tempPhone, phones[i]);
                strcpy(phones[i], phones[j]);
                strcpy(phones[j], tempPhone);

                int tempType = isPrepaids[i];
                isPrepaids[i] = isPrepaids[j];
                isPrepaids[j] = tempType;

                float tempBalance = balances[i];
                balances[i] = balances[j];
                balances[j] = tempBalance;
            }
        }
    }
    printf("Customers sorted by name.\n");
    displayCustomers();
}

void displayCustomerDetails(int id) {
    for (int i = 0; i < customerCount; i++) {
        if (ids[i] == id) {
            for(int i=1;i<=30;i++)
            printf("*");
            printf("\n-- CUSTOMER DETAILS --\n");
            for(int i=1;i<=30;i++)
            printf("*");
            printf("\n");
            printf("ID : %d\n", ids[i]);
            printf("Name : %s\n", names[i]);
            printf("Phone : %s\n", phones[i]);
            printf("Balance : %.2f\n", balances[i]);
            printf("Type : %s\n", isPrepaids[i] ? "Prepaid" : "Postpaid");
            for(int i=1;i<=25;i++)
            printf("*");
            printf("\n");
            printf("Total Charges : %.2f\n", balances[i] > 0 ? balances[i] : -balances[i]);
            for(int i=1;i<=25;i++)
            printf("*");
            printf("\n");
            return;
        }
    }
    printf("Status : Customer with ID %d not found.\n\n", id);
}

void generateEnhancedBill(int id) {
    float totalCharge;
    int minutes;

    for (int i = 0; i < customerCount; i++) {
        if (ids[i] == id) {
            printf("Enter total call minutes: ");
            scanf("%d", &minutes);

            totalCharge = minutes * 5;

            if (isPrepaids[i]) {
                if (balances[i] >= totalCharge) {
                    balances[i] -= totalCharge;
                    for(int i=1;i<=45;i++)
                    printf("*");
                    printf("\n-- DETAILED PREPAID BILL GENERATED --\n");
                    for(int i=1;i<=45;i++)
                    printf("*");
                    printf("\n");
                    printf("Customer ID : %d\n", ids[i]);
                    printf("Customer Name : %s\n", names[i]);
                    printf("Phone Number : %s\n", phones[i]);
                    printf("Total Minutes : %d\n", minutes);
                    printf("Charge per Minute : 5.00\n");
                    printf("Total Charge : %.2f\n", totalCharge);
                    printf("Remaining Balance : %.2f\n", balances[i]);
                    for(int i=1;i<=25;i++)
                    printf("*");
                    printf("\n");
                    printf("Total Charges : %.2f\n", balances[i] + totalCharge);
                    for(int i=1;i<=25;i++)
                    printf("*");
                    printf("\n");
                } else {
                    printf("\nInsufficient balance. Please recharge!\n\n");
                }
            } else {
                balances[i] += totalCharge;
                for(int i=1;i<=45;i++)
                printf("*");
                printf("\n-- DETAILED POSTPAID BILL GENERATED --\n");
                for(int i=1;i<=45;i++)
                printf("*");
                printf("\n");
                printf("Customer ID : %d\n", ids[i]);
                printf("Customer Name : %s\n", names[i]);
                printf("Phone Number : %s\n", phones[i]);
                printf("Total Minutes : %d\n", minutes);
                printf("Charge per Minute : 5.00\n");
                printf("Total Charge : %.2f\n", totalCharge);
                printf("Updated Balance : %.2f\n", balances[i]);
                for(int i=1;i<=25;i++)
                printf("*");
                printf("\nTotal Charges : %.2f\n", balances[i]);
                for(int i=1;i<=25;i++)
                printf("*");
                printf("\n");
            }
            return;
        }
    }
    printf("Customer not found.\n\n");
}

void displayStatistics() {
    int prepaidCount = 0, postpaidCount = 0;
    float totalBalance = 0;

    for (int i = 0; i < customerCount; i++) {
        if (isPrepaids[i]) {
            prepaidCount++;
        } else {
            postpaidCount++;
        }
        totalBalance += balances[i];
    }

    for(int i=1;i<=30;i++)
    printf("*");
    printf("\n-- CUSTOMER STATISTICS --\n");
    for(int i=1;i<=30;i++)
    printf("*");
    printf("\n");
    printf("Total Customers : %d\n", customerCount);
    printf("Prepaid Customers : %d\n", prepaidCount);
    printf("Postpaid Customers : %d\n", postpaidCount);
    for(int i=1;i<=25;i++)
    printf("*");
    printf("\n");
    printf("Total Balance : %.2f\n", totalBalance);
    for(int i=1;i<=25;i++)
    printf("*");
    printf("\n");
}

int main() {
    int choice, id;
    float charge, amount;
    char name[50], phone[15];
    float balance;

    for(int i=1;i<=50;i++)
        printf("*");
    printf("\n");
    printf("\t\tTELECOM BILLING SYSTEM\n");
    for(int i=1;i<=50;i++)
        printf("*");
    printf("\n");
    
    while (1) {
        for(int i=1;i<=50;i++)
            printf("-");
        printf("\n");

        printf("1.  Add Customer\n");
        printf("2.  Add Charge\n");
        printf("3.  Display Customers\n");
        printf("4.  Update Customer\n");
        printf("5.  Search Customer\n");
        printf("6.  Delete Customer\n");
        printf("7.  Recharge Balance\n");
        printf("8.  Generate Detailed Bill\n");
        printf("9.  Sort Customers by Name\n");
        printf("10. Display Customer Details\n");
        printf("11. Display Statistics\n");
        printf("12. Exit\n");

        for(int i=1;i<=50;i++)
            printf("-");
        printf("\n");
        printf("\tEnter your choice: ");
        scanf("%d", &choice);
        for(int i=1;i<=50;i++)
            printf("-");
        printf("\n");

       switch (choice) {
            case 1:
                addCustomer();
                break;
            case 2:
                printf("Enter Customer ID: ");
                scanf("%d", &id);
                printf("Enter Charge: ");
                scanf("%f", &charge);
                addCharge(id, charge);
                break;
            case 3:
                displayCustomers();
                break;
            case 4:
                printf("Enter Customer ID: ");
                scanf("%d", &id);
                updateCustomer(id);
                break;
            case 5:
                printf("Enter Customer's (ID/Name/PhoneNo./Balance): ");
                char searchTerm[50];
                scanf("%s", &searchTerm);
                printf("Select search type (1 for ID, 2 for Name, 3 for PhoneNo., 4 for Balance): ");
                int searchType;
                scanf("%d", &searchType);
                searchCustomer(searchTerm, searchType);
                break;
            case 6:
                printf("Enter Customer ID: ");
                scanf("%d", &id);
                deleteCustomer(id);
                break;
            case 7:
                printf("Enter Customer ID: ");
                scanf("%d", &id);
                printf("Enter Recharge Amount: ");
                scanf("%f", &amount);
                rechargeBalance(id, amount);
                break;
            case 8:
                printf("Enter Customer ID: ");
                scanf("%d", &id);
                generateDetailedBill(id);
                break;
            case 9:
                sortCustomersByName();
                break;
            case 10:
                printf("Enter Customer ID: ");
                scanf("%d", &id);
                displayCustomerDetails(id);
                break;
            case 11:
                displayStatistics();
                break;
            case 12:
                for(int i=1;i<=50;i++)
                    printf("*");
                printf("\n\t\tTHANK YOU !\n");
                for(int i=1;i<=50;i++)
                    printf("*");
                return 0;
            default:
                printf("\tInvalid choice. Please try again.\n");
        }
    }
}