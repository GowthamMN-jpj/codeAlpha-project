#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Use structures + file handling to store data permanently[cite: 2].
typedef struct {
    int rollNo;
    char name[50];
    float marks;
} Student;

const char *FILE_NAME = "students.dat";

// Function Prototypes for the required features[cite: 2]
void addRecord();
void displayRecords();
void searchRecord();
void updateRecord();
void deleteRecord();

int main() {
    int choice;

    // Create a menu-driven C program to manage student records[cite: 2].
    while (1) {
        printf("\n=== Student Record Management ===\n");
        printf("1. Add Record\n");     //[cite: 2]
        printf("2. Display Records\n"); //[cite: 2]
        printf("3. Search Record\n");   //[cite: 2]
        printf("4. Update Record\n");   //[cite: 2]
        printf("5. Delete Record\n");   //[cite: 2]
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addRecord(); break;
            case 2: displayRecords(); break;
            case 3: searchRecord(); break;
            case 4: updateRecord(); break;
            case 5: deleteRecord(); break;
            case 6: 
                printf("Exiting system...\n"); 
                exit(0);
            default: 
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

// Feature: Add records[cite: 2]
void addRecord() {
    FILE *file = fopen(FILE_NAME, "ab"); // Append binary
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Student s;
    printf("Enter Roll Number: ");
    scanf("%d", &s.rollNo);
    
    while (getchar() != '\n'); // Clear input buffer
    
    printf("Enter Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = 0; // Remove trailing newline
    
    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(Student), 1, file);
    printf("Record added successfully.\n");

    fclose(file);
}

// Feature: Display records[cite: 2]
void displayRecords() {
    FILE *file = fopen(FILE_NAME, "rb"); // Read binary
    if (file == NULL) {
        printf("No records found.\n");
        return;
    }

    Student s;
    printf("\n--- All Student Records ---\n");
    printf("%-10s %-30s %-10s\n", "Roll No", "Name", "Marks");
    printf("--------------------------------------------------\n");
    
    while (fread(&s, sizeof(Student), 1, file)) {
        printf("%-10d %-30s %-10.2f\n", s.rollNo, s.name, s.marks);
    }

    fclose(file);
}

// Feature: Search records[cite: 2]
void searchRecord() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("No records found.\n");
        return;
    }

    int targetRoll, found = 0;
    Student s;
    printf("Enter Roll Number to search: ");
    scanf("%d", &targetRoll);

    while (fread(&s, sizeof(Student), 1, file)) {
        if (s.rollNo == targetRoll) {
            printf("\nRecord Found:\n");
            printf("Roll No: %d\nName: %s\nMarks: %.2f\n", s.rollNo, s.name, s.marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Record with Roll Number %d not found.\n", targetRoll);
    }

    fclose(file);
}

// Feature: Update records[cite: 2]
void updateRecord() {
    FILE *file = fopen(FILE_NAME, "rb+"); // Read & Write binary
    if (file == NULL) {
        printf("No records found.\n");
        return;
    }

    int targetRoll, found = 0;
    Student s;
    printf("Enter Roll Number to update: ");
    scanf("%d", &targetRoll);

    while (fread(&s, sizeof(Student), 1, file)) {
        if (s.rollNo == targetRoll) {
            printf("Record found. Enter new marks: ");
            scanf("%f", &s.marks);
            
            // Move file pointer back by one record to overwrite
            fseek(file, -sizeof(Student), SEEK_CUR);
            fwrite(&s, sizeof(Student), 1, file);
            
            printf("Record updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Record with Roll Number %d not found.\n", targetRoll);
    }

    fclose(file);
}

// Feature: Delete records[cite: 2]
void deleteRecord() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("No records found.\n");
        return;
    }

    FILE *tempFile = fopen("temp.dat", "wb"); // Temporary file
    if (tempFile == NULL) {
        printf("Error creating temporary file.\n");
        fclose(file);
        return;
    }

    int targetRoll, found = 0;
    Student s;
    printf("Enter Roll Number to delete: ");
    scanf("%d", &targetRoll);

    // Copy all records except the one to delete into temp file
    while (fread(&s, sizeof(Student), 1, file)) {
        if (s.rollNo != targetRoll) {
            fwrite(&s, sizeof(Student), 1, tempFile);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(FILE_NAME);             // Delete original file
        rename("temp.dat", FILE_NAME); // Rename temp file to original name
        printf("Record deleted successfully.\n");
    } else {
        remove("temp.dat");            // Clean up temp file if no target was found
        printf("Record with Roll Number %d not found.\n", targetRoll);
    }
}