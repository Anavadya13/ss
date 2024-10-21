#include <stdio.h>   // Correct include statement
#include <string.h>   // For string handling functions

struct FileAllocation {
    char file_name[20];
    int start_block;
    int length;
};

int main() {
    int num_files;

    printf("Enter the number of files to be allocated: ");
    scanf("%d", &num_files);

    // Ensure valid number of files
    if (num_files <= 0) {
        printf("Invalid number of files.\n");
        return 1;
    }

    struct FileAllocation files[num_files];  // Array of structures

    // Input file details
    for (int i = 0; i < num_files; i++) {
        printf("Enter the name of the file %d: ", i + 1);
        scanf("%19s", files[i].file_name);  // Prevent overflow

        printf("Enter the start block of the file %d: ", i + 1);
        scanf("%d", &files[i].start_block);

        // Validate that start block is non-negative
        if (files[i].start_block < 0) {
            printf("Invalid start block. It must be non-negative.\n");
            return 1;
        }

        printf("Enter the length of the file %d: ", i + 1);
        scanf("%d", &files[i].length);

        // Validate that length is positive
        if (files[i].length <= 0) {
            printf("Invalid file length. It must be greater than zero.\n");
            return 1;
        }
    }

    // Print the file allocation table
    printf("\nFile Allocation Table\n");
    printf("%-10s %-12s %-10s\n", "File Name", "Start Block", "Length");

    for (int i = 0; i < num_files; i++) {
        printf("%-10s %-12d %-10d\n", 
               files[i].file_name, files[i].start_block, files[i].length);
    }

    return 0;
}
