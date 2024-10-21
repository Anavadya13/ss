#include <stdio.h>

struct File {
    int start_address;
    int length;
    int num_blocks;
    int blocks[10]; // Assuming a maximum of 10 blocks per file
};

int main() {
    int num_files;

    // Input: Number of files
    printf("Enter the number of files to be added: ");
    scanf("%d", &num_files);

    struct File files[num_files];

    // Input: File details
    for (int i = 0; i < num_files; i++) {
        printf("\nEnter details for File[%d]:\n", i);
        
        printf("Start address: ");
        scanf("%d", &files[i].start_address);
        
        printf("Length: ");
        scanf("%d", &files[i].length);
        
        printf("Number of blocks (max 10): ");
        scanf("%d", &files[i].num_blocks);

        // Validate the number of blocks
        if (files[i].num_blocks > 10) {
            printf("Error: Maximum 10 blocks allowed.\n");
            return 1;
        }

        printf("Enter the blocks allocated: ");
        for (int j = 0; j < files[i].num_blocks; j++) {
            scanf("%d", &files[i].blocks[j]);
        }
    }

    // Display: File Details Table
    printf("\nFile Details:\n");
    printf("%-10s %-12s %-12s %-12s\n", "File No", "No of Blocks", "Length", "Start Addr");
    for (int i = 0; i < num_files; i++) {
        printf("%-10d %-12d %-12d %-12d\n", 
               i, files[i].num_blocks, files[i].length, files[i].start_address);
    }

    // Menu-driven interface to query blocks
    int choice, file_number;
    do {
        printf("\n1. Get the blocks\n2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Query file blocks
                printf("Enter the file number: ");
                scanf("%d", &file_number);

                if (file_number >= 0 && file_number < num_files) {
                    printf("Blocks allocated to File[%d]: ", file_number);
                    for (int j = 0; j < files[file_number].num_blocks; j++) {
                        printf("%d ", files[file_number].blocks[j]);
                    }
                    printf("\n");
                } else {
                    printf("Invalid file number!\n");
                }
                break;

            case 2:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please select 1 or 2.\n");
                break;
        }
    } while (choice != 2);

    return 0;
}
