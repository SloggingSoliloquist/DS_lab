#include <stdio.h>

struct student {
    char name[50];
    int rollNo;
    char grade;
};

// Function to read student info
void readStudents(struct student s[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter details of student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Roll No: ");
        scanf("%d", &s[i].rollNo);
        printf("Grade: ");
        scanf(" %c", &s[i].grade); // space before %c to ignore newline
    }
}

// Function to display student info
void displayStudents(struct student s[], int n) {
    printf("\n%-10s %-10s %-10s\n", "Name", "RollNo", "Grade");
    for (int i = 0; i < n; i++) {
        printf("%-10s %-10d %-10c\n", s[i].name, s[i].rollNo, s[i].grade);
    }
}

// Function to sort students by rollNo (ascending order)
void sortStudents(struct student s[], int n) {
    struct student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i].rollNo > s[j].rollNo) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct student students[n];

    readStudents(students, n);

    printf("\n--- Student Information (Unsorted) ---\n");
    displayStudents(students, n);

    sortStudents(students, n);

    printf("\n--- Student Information (Sorted by Roll No) ---\n");
    displayStudents(students, n);

    return 0;
}
