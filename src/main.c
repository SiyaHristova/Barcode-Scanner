#include "Defines.h"
#include "dataInput.h"
#include "dataProcessing.h"
#include "checkBarcode.h"


int main(void)
{  
    /* gets the number of sensors */
    int numSensors = checkNumberOfSensors();
    float *inputData = (float*)malloc(sizeof(float)* numSensors);

    /* Gets the input data */
    inputData = dataInput(numSensors);
    int newSizeCounter = calcNewArraySize(inputData, numSensors);

    /* Reading data in binary form */
    int *barcode = (int*)malloc(sizeof(int) * newSizeCounter);
    barcode = dataProcessing(inputData, numSensors, newSizeCounter);

    /* Cast data from integer to char */
    char *charBarcode = (char*)malloc(sizeof(char)*newSizeCounter);
    charBarcode = castToChar(barcode, newSizeCounter);

    /* Coding the binary numbers in numbers from 0 to 9 */
    char *charResult = (char*)malloc(sizeof(char)*newSizeCounter);
    charResult = equalPart(charBarcode, newSizeCounter);
    
    /* Gets the final result */
    char *finalBarcode = finalResult(charResult);
    int c = findC(charResult);
    int k = findK(charResult);

    if (c == 1 && k == 1){
        puts(finalBarcode);
    }else
    {
        printf("\nBarcode is invalid!\n");
    }

    /* free */
    free(inputData);
    free(barcode);
    free(charBarcode);
    free(charResult);
    return 0;
}
