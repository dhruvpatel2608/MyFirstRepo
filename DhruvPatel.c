/*
* FILE : f7.cpp
* PROJECT : focused Assignment #7
* PROGRAMMER : Dhruv Patel
* FIRST VERSION : 2024-03-19
* DESCRIPTION : program to give you practice at creating text and binary files.
* The functions in this file are used to create text and binary file.
*/

#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable: 4996) 

int main() {

    FILE* textFile = fopen("myTextFile.txt", "r");

    if (textFile == NULL) {
        fprintf(stderr, "Error opening file myTextFile.txt\n");
        exit(1);
    }
    fprintf(textFile, "This is line 1.\n");
    fprintf(textFile, "This is line 2.\n");

    fclose(textFile);

    const unsigned short kBinaryData[] = { 26946, 24942, 31090, 25632, 29793, 8289, 28518, 8306, 28537, 33141, 39308 };
    // Declare and initialize a file pointer for binary file operations
    FILE* binaryFile = fopen("myEvenDataList.data", "rb");

    if (binaryFile == NULL) {

        fprintf(stderr, "Error opening file myEvenDataList.data\n");
        exit(1);

    }

    // Declare and initialize an integer counter for loop iterations
    int i = 0;
    do
    {

        if (kBinaryData[i] % 2 == 0) {

            if (fwrite(&kBinaryData[i], sizeof(unsigned short), 1, binaryFile) != 1) {
                fprintf(stderr, "Error writing to file myEvenDataList.data\n");
                exit(1);

            }

        }
        i++;
    } while (i < sizeof(kBinaryData) / sizeof(kBinaryData[0]));

    fclose(binaryFile);

    return 0;
}