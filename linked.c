#include <stdio.h> 
#define MAX_BLOCKS 100

int blocks[MAX_BLOCKS]; // Array to track allocated blocks

// Function to allocate blocks using linked allocation
void allocateFile(int start, int num_blocks) {
    int count = 0;
    int block_num = start;

    while (count < num_blocks) {
        // Check for out-of-bounds access
        if (block_num >= MAX_BLOCKS) {
            printf("Error: Not enough space. Allocation failed!\n");
            return;
        }

        // Check if the block is already allocated
        if (blocks[block_num] == 0) {
            blocks[block_num] = 1; // Allocate the block
            printf("Block no: %d ----> Allocated\n", block_num);
            count++;
        }
        block_num++; // Move to the next block
    }

    printf("File allocated successfully with %d blocks.\n", num_blocks);
}

int main() {
    int num_allocated, allocated_blocks[10], num_blocks, start_block, choice, i;

    // Initialize all blocks as free (0)
    for (i = 0; i < MAX_BLOCKS; i++) {
        blocks[i] = 0;
    }

    // Input: Already allocated blocks
    printf("Enter the number of blocks which are already allocated: ");
    scanf("%d", &num_allocated);

    printf("Enter the blocks which are already allocated: ");
    for (i = 0; i < num_allocated; i++) {
        scanf("%d", &allocated_blocks[i]);

        // Check for valid block numbers
        if (allocated_blocks[i] < 0 || allocated_blocks[i] >= MAX_BLOCKS) {
            printf("Invalid block number: %d\n", allocated_blocks[i]);
            return 1;
        }

        blocks[allocated_blocks[i]] = 1; // Mark as allocated
    }

    // Menu-driven interface to allocate files
    do {
        printf("\n1. Add file\n2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Input: Number of blocks and starting block
                printf("Enter the number of blocks to be allocated and the starting block: ");
                scanf("%d %d", &num_blocks, &start_block);

                // Validate inputs
                if (start_block < 0 || start_block >= MAX_BLOCKS) {
                    printf("Invalid starting block!\n");
                    break;
                }

                allocateFile(start_block, num_blocks);
                break;

            case 2:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please enter 1 or 2.\n");
                break;
        }
    } while (choice != 2);

    return 0;
}
