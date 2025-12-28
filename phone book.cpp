#include <stdio.h>
#include <string.h>

#define MAX 100

// Contact structure
struct Contact {
    char name[30];
    char phone[15];
};

// Function declarations
void addContact(struct Contact contacts[], int *count);
void viewContacts(struct Contact contacts[], int count);
void searchContact(struct Contact contacts[], int count);

int main() {
    struct Contact contacts[MAX];
    int choice = 0;
    int count = 0;

    printf("** Welcome to Phone Book Application **\n");

    do {
        printf("\nSelect an Option\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addContact(contacts, &count);
                break;

            case 2:
                viewContacts(contacts, count);
                break;

            case 3:
                searchContact(contacts, count);
                break;

            case 4:
                printf("Thank you for using Phone Book\n");
                break;

            default:
                printf("Invalid option! Please select 1 - 4\n");
        }

    } while(choice != 4);

    return 0;
}

// Add contact
void addContact(struct Contact contacts[], int *count) {
    if (*count >= MAX) {
        printf("Phone book is full!\n");
        return;
    }

    printf("Enter Name: ");
    scanf("%s", contacts[*count].name);

    printf("Enter Phone Number: ");
    scanf("%s", contacts[*count].phone);

    (*count)++;
    printf("Contact added successfully!\n");
}

// View contacts
void viewContacts(struct Contact contacts[], int count) {
    if (count == 0) {
        printf("No contacts available.\n");
        return;
    }

    printf("\n--- Contact List ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Name: %s | Phone: %s\n",
               i + 1,
               contacts[i].name,
               contacts[i].phone);
    }
}

// Search contact
void searchContact(struct Contact contacts[], int count) {
    char searchName[30];
    int found = 0;

    if (count == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    printf("Enter name to search: ");
    scanf("%s", searchName);

    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            printf("Contact Found: %s - %s\n",
                   contacts[i].name,
                   contacts[i].phone);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}
