#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient {
    int id;
    char name[100];
    int severity;
    struct Patient *next;
};

struct Patient *head = NULL;

void addPatient(int id, char *name, int severity) {
    struct Patient *newPatient = (struct Patient *)malloc(sizeof(struct Patient));
    newPatient->id = id;
    strcpy(newPatient->name, name);
    newPatient->severity = severity;
    if (head == NULL || severity > head->severity) {
        newPatient->next = head;
        head = newPatient;
    } else {
        struct Patient *temp = head;
        while (temp->next != NULL && temp->next->severity >= severity) {
            temp = temp->next;
        }
        newPatient->next = temp->next;
        temp->next = newPatient;
    }
    printf("Patient added: ID %d, Name %s, Severity %d\n", id, name, severity);
}

void treatPatient() {
    if (head == NULL) {
        printf("No patients in queue.\n");
        return;
    }
    struct Patient *temp = head;
    head = head->next;
    printf("Treated patient: ID %d, Name %s, Severity %d\n", temp->id, temp->name, temp->severity);
    free(temp);
}

void displayQueue() {
    if (head == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Patient *temp = head;
    printf("Current queue:\n");
    while (temp != NULL) {
        printf("ID: %d, Name: %s, Severity: %d\n", temp->id, temp->name, temp->severity);
        temp = temp->next;
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nMenu:\n1. Add patient\n2. Treat patient\n3. Display queue\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            int id, severity;
            char name[100];
            printf("Enter patient ID: ");
            scanf("%d", &id);
            getchar();
            printf("Enter patient name: ");
            fgets(name, 100, stdin);
            name[strcspn(name, "\n")] = 0;
            printf("Enter severity (1-10): ");
            scanf("%d", &severity);
            addPatient(id, name, severity);
        } else if (choice == 2) {
            treatPatient();
        } else if (choice == 3) {
            displayQueue();
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }
    printf("\nTesting with 10 patients:\n");
    addPatient(1, "Patient A", 5);
    addPatient(2, "Patient B", 8);
    addPatient(3, "Patient C", 3);
    addPatient(4, "Patient D", 10);
    addPatient(5, "Patient E", 5);
    addPatient(6, "Patient F", 8);
    addPatient(7, "Patient G", 2);
    addPatient(8, "Patient H", 7);
    addPatient(9, "Patient I", 10);
    addPatient(10, "Patient J", 4);
    displayQueue();
    treatPatient();
    treatPatient();
    displayQueue();
    struct Patient *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}