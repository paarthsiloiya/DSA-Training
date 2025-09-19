#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song {
    char songTitle[100];
    char artist[100];
    struct Song *next;
};

struct Song *head = NULL;

void addBeginning() {
    struct Song *newSong = (struct Song *)malloc(sizeof(struct Song));
    printf("Enter song title: ");
    getchar();
    fgets(newSong->songTitle, 100, stdin);
    newSong->songTitle[strcspn(newSong->songTitle, "\n")] = 0;
    printf("Enter artist: ");
    fgets(newSong->artist, 100, stdin);
    newSong->artist[strcspn(newSong->artist, "\n")] = 0;
    newSong->next = head;
    head = newSong;
    printf("Song added at the beginning.\n");
}

void addEnd() {
    struct Song *newSong = (struct Song *)malloc(sizeof(struct Song));
    printf("Enter song title: ");
    getchar();
    fgets(newSong->songTitle, 100, stdin);
    newSong->songTitle[strcspn(newSong->songTitle, "\n")] = 0;
    printf("Enter artist: ");
    fgets(newSong->artist, 100, stdin);
    newSong->artist[strcspn(newSong->artist, "\n")] = 0;
    newSong->next = NULL;
    if (head == NULL) {
        head = newSong;
    } else {
        struct Song *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newSong;
    }
    printf("Song added at the end.\n");
}

void addPosition() {
    int pos;
    printf("Enter position to add (1-based): ");
    scanf("%d", &pos);
    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }
    struct Song *newSong = (struct Song *)malloc(sizeof(struct Song));
    printf("Enter song title: ");
    getchar();
    fgets(newSong->songTitle, 100, stdin);
    newSong->songTitle[strcspn(newSong->songTitle, "\n")] = 0;
    printf("Enter artist: ");
    fgets(newSong->artist, 100, stdin);
    newSong->artist[strcspn(newSong->artist, "\n")] = 0;
    if (pos == 1) {
        newSong->next = head;
        head = newSong;
    } else {
        struct Song *temp = head;
        for (int i = 1; i < pos - 1; i++) {
            if (temp == NULL) {
                printf("Position out of bounds.\n");
                free(newSong);
                return;
            }
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Position out of bounds.\n");
            free(newSong);
            return;
        }
        newSong->next = temp->next;
        temp->next = newSong;
    }
    printf("Song added at position %d.\n", pos);
}

void deleteBeginning() {
    if (head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }
    struct Song *temp = head;
    head = head->next;
    free(temp);
    printf("Song deleted from beginning.\n");
}

void deleteEnd() {
    if (head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        struct Song *temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
    printf("Song deleted from end.\n");
}

void deletePosition() {
    int pos;
    printf("Enter position to delete (1-based): ");
    scanf("%d", &pos);
    if (pos < 1 || head == NULL) {
        printf("Invalid position or empty playlist.\n");
        return;
    }
    if (pos == 1) {
        struct Song *temp = head;
        head = head->next;
        free(temp);
    } else {
        struct Song *temp = head;
        for (int i = 1; i < pos - 1; i++) {
            if (temp->next == NULL) {
                printf("Position out of bounds.\n");
                return;
            }
            temp = temp->next;
        }
        if (temp->next == NULL) {
            printf("Position out of bounds.\n");
            return;
        }
        struct Song *toDelete = temp->next;
        temp->next = toDelete->next;
        free(toDelete);
    }
    printf("Song deleted from position %d.\n", pos);
}

void updatePosition() {
    int pos;
    printf("Enter position to update (1-based): ");
    scanf("%d", &pos);
    if (pos < 1 || head == NULL) {
        printf("Invalid position or empty playlist.\n");
        return;
    }
    struct Song *temp = head;
    for (int i = 1; i < pos; i++) {
        if (temp == NULL) {
            printf("Position out of bounds.\n");
            return;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return;
    }
    int choice;
    printf("What to update? 1: Title, 2: Artist, 3: Duration: ");
    scanf("%d", &choice);
    getchar();
    if (choice == 1) {
        printf("Enter new title: ");
        fgets(temp->songTitle, 100, stdin);
        temp->songTitle[strcspn(temp->songTitle, "\n")] = 0;
    } else if (choice == 2) {
        printf("Enter new artist: ");
        fgets(temp->artist, 100, stdin);
        temp->artist[strcspn(temp->artist, "\n")] = 0;
    } else {
        printf("Invalid choice.\n");
        return;
    }
    printf("Song updated at position %d.\n", pos);
}

void display() {
    if (head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }
    struct Song *temp = head;
    int i = 1;
    printf("Playlist:\n");
    while (temp != NULL) {
        printf("%d. Title: %s, Artist: %s\n", i, temp->songTitle, temp->artist);
        temp = temp->next;
        i++;
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nMenu:\n1. Add song at beginning\n2. Add song at end\n3. Add song at position\n4. Delete from beginning\n5. Delete from end\n6. Delete from position\n7. Update song at position\n8. Display playlist\n9. Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 1) addBeginning();
        else if (choice == 2) addEnd();
        else if (choice == 3) addPosition();
        else if (choice == 4) deleteBeginning();
        else if (choice == 5) deleteEnd();
        else if (choice == 6) deletePosition();
        else if (choice == 7) updatePosition();
        else if (choice == 8) display();
        else if (choice == 9) break;
        else printf("Invalid choice.\n");
    }
    struct Song *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}