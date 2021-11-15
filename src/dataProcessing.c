#include "dataProcessing.h"

/* Reading data in binary form */
int *dataProcessing(float *inputData, int numberOfSensors, int counter)
{
    int *barCode = (int *)malloc(sizeof(int) * counter);
    if (!barCode)
    {
        perror("Failed to allocate memory for the barcode array");
        return NULL;
    }

    int i = 0, j = 0;
    for (i = 0; i < numberOfSensors; i++)
    {
        if (inputData[i] == 0)
        {
            if (inputData[i + 1] == 0 && i + 1 < numberOfSensors)
            {
                barCode[j] = 1;
                i++;
            }
            else
            {
                barCode[j] = 0;
            }
            j++;
        }
    }
    return barCode;
}

/* Cast data from integer to char */
char *castToChar(int *barCode, int counter)
{
    int n = 0;

    char *charBarCode = (char *)malloc(sizeof(char) * counter);
    if (!charBarCode)
    {
        perror("Failed to allocate memory for the charBarCode");
        return NULL;
    }

    for (int i = 0; i < counter; i++)
    {
        sprintf(&charBarCode[n], "%d", barCode[i]);
        n++;
    }
    return charBarCode;
}

/* Split the Array and code the binary numbers in numbers from 0 to 9 */
char *equalPart(char *charBarCode, int counter)
{
    //puts(charBarCode);

    int equalPart = counter / 5;
    int i = 0, j = 0;

    int len = strlen(charBarCode);
    int chars = len / equalPart;
    
    char *result = (char *)malloc(sizeof(char) * equalPart);
    if (!result)
    {
        perror("Failed to allocate memory for the result array");
        return NULL;
    }

    if (equalPart <= 1)
    {
        reverseArray(charBarCode, counter);
    }
    if (len % equalPart != 0 || equalPart == 0)
    {
        printf("Sorry this string cannot be divided into %d equal parts, because the length is: %d", equalPart, len);
    }
    else
    {
        changeTheValue(charBarCode, result, counter, chars);
    }
    return result;
}


char *changeTheValue(char *charBarCode, char *result, int counter, int chars)
{
    char stringPart[chars + 1];
    int len = strlen(charBarCode);
    int startIndex = 0, stopIndex = 0;
    int startStop = 0;
    int index = 0;
    
    for (int i = 0; i < len; i = i + chars)
    {
        counter = 0;
        while (counter < chars)
        {
            stringPart[counter] = charBarCode[i + counter];
            counter++;
        }
        stringPart[counter] = '\0';
        for (int j = 0; j < 12; j++)
        {
            if (strcmp(stringPart, symbols[j]) == 0)
            {
                if (j == 10)
                {
                    strcpy((result + index), "-");
                    index++;
                }
                else if (j == 11)
                {
                    startStop++;
                    if (startStop == 2)
                    {
                        stopIndex = i / 5;
                        break;
                    }
                    else
                    {
                        if (i == 0 && startStop == 1)
                        {
                            startIndex = i;
                        }
                        else
                        {
                            reverseArray(charBarCode, counter);
                        }
                    }
                }
                else
                {
                    strcpy((result + index), numbers[j]);
                    index++;
                }
            }
        }
    }
    return result;
}

/* Reverse Array */
int reverseArray(char *charBarCode, int counter)
{
    static int reversedBarcode = 0;
    reversedBarcode++;
    if (reversedBarcode == 2)
    {
        char *search = strstr(charBarCode, symbols[11]);
        if (search == NULL)
        {
            printf("Barcode is invalid!");
            exit(0);
        }
        else
        {
            printf("Barcode truncated. Try moving the scanner to the left and right!");
            exit(1);
        }
    }
    else
    {
        equalPart(strrev(charBarCode), counter);
    }
    return reversedBarcode;
}