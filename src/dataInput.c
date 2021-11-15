#include "dataInput.h"

/* Input the number of sensors */
int checkNumberOfSensors()
{
    int numberOfSensors;
    scanf("%d", &numberOfSensors);
    while (numberOfSensors < 0)
    {
        printf("N must be above 0!\n");
        scanf("%d", &numberOfSensors);
    }
    return numberOfSensors;
}

/* Input the data */
float* dataInput(int numberOfSensors)
{
    float inputNumber = 0;
    if (numberOfSensors == 0)
    {
        perror("Failed!");
    }

    float *inputData = (float *)malloc(sizeof(float) * numberOfSensors);
    if (!inputData)
    {
        perror("Failed to allocate memory for the inputData array");
        return NULL;
    }

    for (int i = 0; i < numberOfSensors; i++)
    {
        scanf("%f", &inputNumber);
        while (inputNumber < 0 || inputNumber > 1)
        {
            printf("Number must be between or equal to 0 and 1:\n");
            scanf("%f", &inputNumber);
        }
       
        inputData[i] = round(inputNumber);
    }
    
    return inputData;
}

/* Calculate the size of new array */
int calcNewArraySize(float *inputData, int numberOfSensors)
{
    int counter = 0;
    for (int i = 0; i < numberOfSensors; i++)
    {
        if (inputData[i] == 0)
        {
            counter++;
            if (inputData[i + 1] == 0)
            {
                i++;
            }
        }
    }
    return counter;
}