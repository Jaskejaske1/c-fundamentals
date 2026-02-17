#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ID_LEN 10
#define STR_LEN 50

typedef struct
{
    char id[ID_LEN];
    char name[STR_LEN];
} CustomerName;

typedef struct
{
    char id[ID_LEN];
    char address[STR_LEN];
} CustomerAddress;

void readNames(CustomerName* arr, int n);
void readAddresses(CustomerAddress* arr, int n);
void printClientData(CustomerName* names, CustomerAddress* addresses, int n);

int main(int argc, char* argv[])
{
    int n;
    CustomerName* namesArray;
    CustomerAddress* addrsArray;

    if (argc < 2)
    {
        printf("Error: Please provide the number of clients.\n");
        printf("Usage Windows: clients.exe <number>\n");
        printf("Usage Linux: ./clients <number>\n");
        return 1;
    }

    // aantal clients van string naar int
    n = atoi(argv[1]);

    if (n <= 0)
    {
        printf("Error: Number of clients must be greater than 0.\n");
        return 1;
    }

    // Memory allocation
    namesArray = (CustomerName*)malloc(n * sizeof(CustomerName));
    addrsArray = (CustomerAddress*)malloc(n * sizeof(CustomerAddress));

    // Memory allocation check
    if (namesArray == NULL || addrsArray == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    readNames(namesArray, n);
    readAddresses(addrsArray, n);

    printClientData(namesArray, addrsArray, n);

    free(namesArray);
    free(addrsArray);

    return 0;
}

void readNames(CustomerName* arr, int n)
{
    int i;
    printf("\nEnter a list of %d customer numbers and corresponding names:\n", n);

    for (i = 0; i < n; i++)
    {
        // id input
        gets(arr[i].id);
        // name input
        gets(arr[i].name);
    }
}

void readAddresses(CustomerAddress* arr, int n)
{
    int i;
    printf("\nEnter a list of %d customer numbers and corresponding addresses (the customer numbers must be identical to the ones above but can be entered in an arbitrary order.)\n", n);

    for (i = 0; i < n; i++)
    {
        // id input
        gets(arr[i].id);
        // address input
        gets(arr[i].address);
    }
}

void printClientData(CustomerName* names, CustomerAddress* addresses, int n)
{
    int i, j;
    int found;

    printf("\nAll customer data:\n");

    for (i = 0; i < n; i++)
    {
        found = 0;

        printf("%s %s ", names[i].id, names[i].name);

        for (j = 0; j < n; j++)
        {

            if (strcmp(names[i].id, addresses[j].id) == 0)
            {
                printf("%s\n", addresses[j].address);
                found = 1;
                break;
            }
        }

        if (!found)
        {
            printf("(Address not found for this ID)\n");
        }
    }
}