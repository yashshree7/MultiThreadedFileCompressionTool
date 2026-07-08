#include <stdio.h>
#include <stdlib.h>
#include "../include/compression.h"
#include "../include/thread_handler.h"

int main()
{
    int choice;

    while (1)
    {
        system("cls");

        printf("\n=====================================================\n");
        printf("      MULTI-THREADED FILE COMPRESSION TOOL\n");
        printf("=====================================================\n");

        printf("1. Compress File\n");
        printf("2. Decompress File\n");
        printf("3. Compress Multiple Files\n");
        printf("4. Compression Statistics\n");
        printf("5. Exit\n");

        printf("=====================================================\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                compressFile();
                break;

            case 2:
                decompressFile();
                break;

            case 3:
                compressMultipleFiles();
                break;

           case 4:
                compressionStatistics();
                break;

            case 5:
                printf("\nThank you for using the File Compression Tool.\n");
                return 0;

            default:
                printf("\nInvalid choice!\n");
        }

        printf("\nPress Enter to continue...");
        getchar();
        getchar();
    }

    return 0;
}