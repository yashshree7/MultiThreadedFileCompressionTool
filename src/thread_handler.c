#include <stdio.h>
#include <windows.h>
#include "../include/thread_handler.h"

/*
-----------------------------------------------------
Structure to pass data to thread
-----------------------------------------------------
*/

typedef struct
{
    char filename[100];
} ThreadData;

/*
-----------------------------------------------------
Thread Function
-----------------------------------------------------
*/

DWORD WINAPI compressThread(LPVOID arg)
{
    ThreadData *data = (ThreadData *)arg;

    char inputPath[150];
    char outputPath[150];

    sprintf(inputPath, "input/%s", data->filename);
    sprintf(outputPath, "output/compressed_%s", data->filename);

    FILE *input = fopen(inputPath, "r");

    if (input == NULL)
    {
        printf("\nUnable to open %s\n", data->filename);
        return 1;
    }

    FILE *output = fopen(outputPath, "w");

    if (output == NULL)
    {
        printf("\nUnable to create output file for %s\n",
               data->filename);

        fclose(input);
        return 1;
    }

    char current, previous;
    int count = 1;

    previous = fgetc(input);

    while ((current = fgetc(input)) != EOF)
    {
        if (current == previous)
        {
            count++;
        }
        else
        {
            fprintf(output, "%c%d", previous, count);
            previous = current;
            count = 1;
        }
    }

    fprintf(output, "%c%d", previous, count);

    fclose(input);
    fclose(output);

    printf("\nCompressed -> %s\n", data->filename);

    return 0;
}

/*
-----------------------------------------------------
Compress Multiple Files
-----------------------------------------------------
*/

void compressMultipleFiles()
{
    int n;

    printf("\nHow many files do you want to compress? ");
    scanf("%d", &n);

    if (n <= 0 || n > 10)
    {
        printf("\nPlease enter a value between 1 and 10.\n");
        return;
    }

    HANDLE threads[10];
    ThreadData data[10];

    /* Step 1: Read all file names */
    for (int i = 0; i < n; i++)
    {
        printf("Enter File %d Name : ", i + 1);
        scanf("%99s", data[i].filename);
    }

    printf("\n---------------------------------------\n");
    printf("Starting Compression...\n");
    printf("---------------------------------------\n");

    /* Step 2: Create all threads */
    for (int i = 0; i < n; i++)
    {
        threads[i] = CreateThread(
            NULL,
            0,
            compressThread,
            &data[i],
            0,
            NULL);

        if (threads[i] == NULL)
        {
            printf("Unable to create thread for %s\n", data[i].filename);
        }
    }

    /* Step 3: Wait for all threads */
    WaitForMultipleObjects(n, threads, TRUE, INFINITE);

    /* Step 4: Close thread handles */
    for (int i = 0; i < n; i++)
    {
        CloseHandle(threads[i]);
    }

    printf("\n=====================================\n");
    printf("All Files Processed Successfully\n");
    printf("=====================================\n");
}