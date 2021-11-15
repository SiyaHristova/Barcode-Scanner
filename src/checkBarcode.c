#include "checkBarcode.h"

/* check C number */
int findC(char *result)
{
    int i, number = 0;
    int sum = 0;
    int len = strlen(result) - 2;

    for (i = 1; i <= len; i++)
    {
        if (result[i - 1] == '-')
        {
            number = 10;
        }
        else
        {
            number = result[i - 1] - '0';
        }
        sum = (((len - i) % 10 + 1) * number);
    }

    sum = sum % 11;
    if (sum == (result[len] - '0'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/* check K number */
int findK(char *result)
{
    int i, number = 0;
    int sum = 0;
    int len = strlen(result) - 2;

    for (i = 1; i <= len + 1; i++)
    {
        if (result[i - 1] == '-')
        {
            number = 10;
        }
        else
        {
            number = result[i - 1] - '0';
        }
        sum += (((len - i + 1) % 9 + 1) * number);
    }

    sum = sum % 11;
    if (sum == (result[len + 1] - '0'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


/* Gets the final result */
char *finalResult(char *result)
{
    int i;
    int len = strlen(result);
    char *finalResult = (char *)malloc(sizeof(char) * len - 1);
    if (!finalResult)
    {
        perror("Failed to allocate memory for the finalResult array");
        return NULL;
    }

    for (i = 0; i < len - 2; i++)
    {
        finalResult[i] = result[i];
    }

    return finalResult;
}