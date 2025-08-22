#include <stdio.h>

// a) Find length of a string
int strLength(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

// b) Concatenate two strings
void strConcat(char str1[], char str2[], char result[]) {
    int i = 0, j = 0;

    // Copy str1
    while (str1[i] != '\0') {
        result[i] = str1[i];
        i++;
    }
    // Append str2
    while (str2[j] != '\0') {
        result[i] = str2[j];
        i++;
        j++;
    }
    result[i] = '\0'; // null terminate
}

// c) Compare two strings
// returns 0 if equal, >0 if str1 > str2, <0 if str1 < str2
int strCompare(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}

// d) Insert a substring into a string
void insertSubstring(char str[], char sub[], int pos, char result[]) {
    int i = 0, j = 0, k = 0;

    // Copy first part of str before pos
    while (i < pos && str[i] != '\0') {
        result[k++] = str[i++];
    }

    // Copy substring
    while (sub[j] != '\0') {
        result[k++] = sub[j++];
    }

    // Copy remaining part of str
    while (str[i] != '\0') {
        result[k++] = str[i++];
    }

    result[k] = '\0';
}

// e) Delete a substring (first occurrence)
void deleteSubstring(char str[], char sub[], char result[]) {
    int i = 0, j = 0, k = 0, start = -1;
    int lenStr = strLength(str), lenSub = strLength(sub);

    // Find first occurrence of sub in str
    while (i <= lenStr - lenSub) {
        j = 0;
        while (j < lenSub && str[i + j] == sub[j]) {
            j++;
        }
        if (j == lenSub) { // found substring
            start = i;
            break;
        }
        i++;
    }

    if (start == -1) {
        // substring not found, just copy original
        i = 0;
        while (str[i] != '\0') {
            result[k++] = str[i++];
        }
    } else {
        // copy up to start
        for (i = 0; i < start; i++) {
            result[k++] = str[i];
        }
        // skip substring
        for (i = start + lenSub; i < lenStr; i++) {
            result[k++] = str[i];
        }
    }
    result[k] = '\0';
}

// Main function to test
int main() {
    char str1[100], str2[100], result[200];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    // a) Length
    printf("\nLength of first string: %d", strLength(str1));
    printf("\nLength of second string: %d", strLength(str2));

    // b) Concatenation
    strConcat(str1, str2, result);
    printf("\nConcatenation: %s", result);

    // c) Comparison
    int cmp = strCompare(str1, str2);
    if (cmp == 0) printf("\nStrings are equal");
    else if (cmp > 0) printf("\nFirst string is greater");
    else printf("\nSecond string is greater");

    // d) Insert substring
    int pos;
    printf("\nEnter position to insert second string into first: ");
    scanf("%d", &pos);
    insertSubstring(str1, str2, pos, result);
    printf("After insertion: %s", result);

    // e) Delete substring
    deleteSubstring(str1, str2, result);
    printf("\nAfter deleting second string from first (if found): %s", result);

    return 0;
}
