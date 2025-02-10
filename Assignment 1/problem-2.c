#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SHOWS 100

typedef struct {
    char showName[100];
    int totalTickets;
    int availableTickets;
} Show;

void addShow(Show *listings, int *numShows) {
    if (*numShows < MAX_SHOWS) {
        printf("Name of the show: ");
        scanf(" %[^\n]s", listings[*numShows].showName); // Improved input handling
        printf("Total tickets: ");
        scanf("%d", &listings[*numShows].totalTickets);
        printf("Tickets currently available: ");
        scanf("%d", &listings[*numShows].availableTickets);

        if(listings[*numShows].availableTickets > listings[*numShows].totalTickets){
            printf("Error: Available tickets cannot exceed total tickets.\n");
            return;
        }

        (*numShows)++;
        printf("Show added successfully!\n");

    } else {
        printf("Maximum number of shows reached.\n");
    }
}

void bookTicket(Show *listings, int numShows, char *showName) {
    for (int i = 0; i < numShows; i++) {
        if (strcmp(listings[i].showName, showName) == 0) {
            if (listings[i].availableTickets > 0) {
                listings[i].availableTickets--;
                printf("You have successfully booked a ticket!\n");
                return;
            } else {
                printf("Oops! There is no ticket left.\n");
                return;
            }
        }
    }
    printf("Show not found.\n");
}

void displayShows(Show *listings, int numShows) {
    for (int i = 0; i < numShows; i++) {
        printf("Show no %d\n", i + 1);
        printf("Name of the show: %s\n", listings[i].showName);
        printf("Total tickets: %d\n", listings[i].totalTickets);
        printf("Tickets currently available: %d\n", listings[i].availableTickets);
    }
}

int main() {
    Show listings[MAX_SHOWS];
    int numShows = 0;
    int choice;
    char showName[100];

    while(1) {
        printf("1. Add a show\n");
        printf("2. Book a ticket\n");
        printf("3. List out the shows\n");
        printf("4. Exit\n");
        printf("What do you want? ");
        scanf("%d", &choice);

        if (choice == 1){
            addShow(listings, &numShows);
        } else if(choice == 2) {
            printf("Enter show name: ");
            scanf("%[^\n]s", showName);
            bookTicket(listings, numShows, showName);
        } else if (choice == 3){
            displayShows(listings, numShows);
        } else if (choice == 4) {
            printf("Exiting............\n");
            break;
        } else {
            printf("Invalid Choice. Please Try Again later \n");
        }
    }
    return 0;
}
