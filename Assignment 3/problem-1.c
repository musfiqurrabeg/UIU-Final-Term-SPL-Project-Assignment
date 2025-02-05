#include <stdio.h>
#include <string.h>
#define MAX_PATIENTS 100

struct Patient {
    char name[50];
    int age;
    char gender;
    int id;
    char condition[50];
};

// Global array
struct Patient patients[MAX_PATIENTS];
int patientCount = 0;

// Functions
void addPatient();
void searchPatient();
void updateCondition();
void displayPatients();


// Main function with menu-driven approach
int main() {
    int choice;

    while (1) {
        printf("\nHospital Patient Management System:\n");
        printf("1. Add a new patient\n");
        printf("2. Search for a patient by ID\n");
        printf("3. Update a patient's condition\n");
        printf("4. Display all patients\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);


        if(choice == 1){
            addPatient(); 
        } else if (choice == 2) {
            searchPatient();
        } else if (choice == 3) {
            updateCondition();
        } else if (choice == 4){
            displayPatients();
        } else if (choice == 5){
            printf("Exiting the program.\n");
            return 0;
        } else {
            printf("Invalid choice! Please enter a valid option.\n");
        }

    }

    return 0;
}

// Function to add a new patient
void addPatient() {
    if (patientCount >= MAX_PATIENTS) {
        printf("Error: Maximum patient limit reached!\n");
        return;
    }

    printf("Enter patient name: ");
    scanf(" %[^\n]", patients[patientCount].name);

    printf("Enter age: ");
    scanf("%d", &patients[patientCount].age);

    printf("Enter gender (M/F): ");
    scanf(" %c", &patients[patientCount].gender);

    printf("Enter ID: ");
    scanf("%d", &patients[patientCount].id);

    printf("Enter condition: ");
    scanf(" %[^\n]", patients[patientCount].condition);

    printf("The patient added successfully.\n");
    patientCount++;
}

// Function to search for a patient by ID
void searchPatient() {
    int searchID;
    printf("Enter patient ID to search: ");
    scanf("%d", &searchID);

    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == searchID) {
            printf("Patient Records:\n");
            printf("ID: %d, Name: %s, Age: %d, Gender: %c, Condition: %s\n",
                   patients[i].id, patients[i].name, patients[i].age,
                   patients[i].gender, patients[i].condition);
            return;
        }
    }
    printf("Patient with ID %d not found!\n", searchID);
}

// Function to update patient condition
void updateCondition() {
    int updateID;
    printf("Enter patient ID to update: ");
    scanf("%d", &updateID);

    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == updateID) {
            printf("Enter new condition: ");
            scanf(" %[^\n]", patients[i].condition);
            printf("Condition updated successfully.\n");
            return;
        }
    }
    printf("Patient with ID %d not found!\n", updateID);
}

// Function to display all patients
void displayPatients() {
    if (patientCount == 0) {
        printf("No patients found!\n");
        return;
    }
    printf("/n");
    printf("Patient Records:\n");

    // Print recovered patients first
    for (int i = 0; i < patientCount; i++) {
        if (strcmp(patients[i].condition, "Recovered") == 0) {
            printf("ID: %d, Name: %s, Age: %d, Gender: %c, Condition: %s\n",
                   patients[i].id, patients[i].name, patients[i].age,
                   patients[i].gender, patients[i].condition);
        }
    }

    // Print remaining patients
    for (int i = 0; i < patientCount; i++) {
        if (strcmp(patients[i].condition, "Recovered") != 0) {
            printf("ID: %d, Name: %s, Age: %d, Gender: %c, Condition: %s\n",
                   patients[i].id, patients[i].name, patients[i].age,
                   patients[i].gender, patients[i].condition);
        }
    }
}