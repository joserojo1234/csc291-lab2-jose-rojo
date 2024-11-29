#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function prototypes
void processFile(const char *sourceFile, const char *destinationFile);

int main() {
    // Replace "data.txt" with the path to your input file
    const char *sourceFile = "data.txt";
    const char *destinationFile = "valid_floats.txt";

    processFile(sourceFile, destinationFile);

    return 0;
}

void processFile(const char *sourceFile, const char *destinationFile) {
    FILE *src = fopen(sourceFile, "r");
    FILE *dest = fopen(destinationFile, "w");
    
    if (!src) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    if (!dest) {
        perror("Error opening destination file");
        fclose(src);
        exit(EXIT_FAILURE);
    }

    float value;
    int invalidCount = 0;
    while (!feof(src)) {
        if (fscanf(src, "%f", &value) == 1) {
            fprintf(dest, "%.2f\n", value);
        } else {
            invalidCount++;
            fseek(src, 1, SEEK_CUR); // Move past the invalid character
        }
    }

    if (ferror(src)) {
        perror("Error during file processing");
    } else {
        printf("Processing completed successfully.\n");
    }

    printf("Number of invalid values: %d\n", invalidCount);

    fclose(src);
    fclose(dest);
}