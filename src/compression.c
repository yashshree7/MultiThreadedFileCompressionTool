#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/compression.h"

/*
-----------------------------------------------------
Function Name : compressFile()

Description :
Compresses a text file using Run-Length Encoding (RLE).

Parameters :
None

Returns :
None
-----------------------------------------------------
*/

void compressFile()
{
    char inputFile[100];
    char outputFile[100];

    FILE *input, *output;

    clock_t start, end;
    double timeTaken;

    char current, previous;
    int count = 1;

    printf("\nEnter input file name (inside input folder): ");
    scanf("%99s", inputFile);

    sprintf(outputFile, "output/compressed_%s", inputFile);

    char fullPath[150];
    sprintf(fullPath, "input/%s", inputFile);

    input = fopen(fullPath, "r");

    if (input == NULL)
    {
        printf("\nError: Unable to open input file.\n");
        return;
    }

    /* Check whether compressed file already exists */

/* Check whether compressed file already exists */

FILE *checkFile = fopen(outputFile, "r");

if (checkFile != NULL)
{
    fclose(checkFile);

    char choice;

    printf("\n=========================================\n");
    printf("OVERWRITING EXISTING FILE...\n");
    printf("-----------------------------------------\n");
    printf("Old compressed file removed.\n");
    printf("Creating new compressed file...\n");
    printf("=========================================\n");

    if (choice == 'Y' || choice == 'y')
    {
        remove(outputFile);
        printf("\nExisting file deleted.\n");
    }
    else
    {
        printf("\nCompression cancelled.\n");
        fclose(input);
        return;
    }
}

    /* Create output file */

    output = fopen(outputFile, "w");

    if (output == NULL)
    {
    printf("\nError: Unable to create output file.\n");
    fclose(input);
    return;
    }
    
    start = clock();
    previous = fgetc(input);

    if(previous == EOF)
    {
        printf("\nInput file is empty.\n");
        fclose(input);
        fclose(output);
        remove(outputFile);
        return;
    }
    

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

    end = clock();
    timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;

   printf("\n=========================================\n");
   printf("Compression Successful\n");
   printf("-----------------------------------------\n");
   printf("Output File : %s\n", outputFile);
   printf("Time Taken  : %.6f seconds\n", timeTaken);
   printf("=========================================\n");
}

/*
-----------------------------------------------------
Function Name : decompressFile()

Description :
Decompresses an RLE compressed file.

Parameters :
None

Returns :
None
-----------------------------------------------------
*/

void decompressFile()
{
    char inputFile[100];
    char outputFile[100];

    FILE *input, *output;

    char character;
    int count;

    printf("\nEnter compressed file name (inside output folder): ");
    scanf("%99s", inputFile);

    char inputPath[150];
    sprintf(inputPath, "output/%s", inputFile);

    sprintf(outputFile, "output/decompressed_%s", inputFile);

    input = fopen(inputPath, "r");

    if(input == NULL)
    {
        printf("\nUnable to open compressed file.\n");
        return;
    }

    output = fopen(outputFile, "w");

    if(output == NULL)
    {
        printf("\nUnable to create output file.\n");
        fclose(input);
        return;
    }

    while(fscanf(input, "%c%d", &character, &count) == 2)
    {
        for(int i = 0; i < count; i++)
        {
            fputc(character, output);
        }
    }

    fclose(input);
    fclose(output);

    printf("\n=========================================\n");
    printf("Decompression Successful\n");
    printf("-----------------------------------------\n");
    printf("Output File : %s\n", outputFile);
    printf("=========================================\n");
}

/*
-----------------------------------------------------
Function Name : compressionStatistics()

Description :
Displays original file size, compressed file size,
space saved and compression ratio.

Parameters :
None

Returns :
None
-----------------------------------------------------
*/

void compressionStatistics()
{
    char originalFile[100];

    printf("\nEnter original file name (inside input folder): ");
    scanf("%99s", originalFile);

    char originalPath[150];
    char compressedPath[150];

    sprintf(originalPath, "input/%s", originalFile);
    sprintf(compressedPath, "output/compressed_%s", originalFile);

    FILE *original = fopen(originalPath, "rb");
    FILE *compressed = fopen(compressedPath, "rb");

    if (original == NULL || compressed == NULL)
    {
        printf("\nUnable to open file(s).\n");

        if (original != NULL)
            fclose(original);

        if (compressed != NULL)
            fclose(compressed);

        return;
    }

    fseek(original, 0, SEEK_END);
    long originalSize = ftell(original);

    fseek(compressed, 0, SEEK_END);
    long compressedSize = ftell(compressed);

    fclose(original);
    fclose(compressed);

    long spaceSaved = originalSize - compressedSize;

    float ratio = ((float)spaceSaved / originalSize) * 100;

    printf("\n=============================================\n");
    printf("         COMPRESSION STATISTICS\n");
    printf("=============================================\n");

    printf("Original File     : %s\n", originalFile);
    printf("Original Size     : %ld Bytes\n", originalSize);
    printf("Compressed Size   : %ld Bytes\n", compressedSize);
    printf("Space Saved       : %ld Bytes\n", spaceSaved);
    printf("Compression Ratio : %.2f %%\n", ratio);

    printf("=============================================\n");
}