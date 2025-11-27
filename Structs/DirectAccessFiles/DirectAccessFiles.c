#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- CONSTANTS & STRUCTURES ---
const char* FILENAME = "inventory.dat";
#define MAX_Input 100

typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} Product;

// --- SAFE INPUT HELPER FUNCTIONS ---

// 1. Remove the \n that fgets adds to the end of strings
void stripNewline(char* str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// 2. Safe String Reader
void readString(const char* prompt, char* destination, int size) {
    printf("%s", prompt);
    // fgets reads up to size-1 characters to prevent buffer overflow
    if (fgets(destination, size, stdin) != NULL) {
        stripNewline(destination);
    }
}

// 3. Safe Integer Reader (Loops until valid number is entered)
int readInt(const char* prompt) {
    char buffer[MAX_Input];
    int value;
    while (1) {
        printf("%s", prompt);
        if (fgets(buffer, MAX_Input, stdin) != NULL) {
            // Try to parse an integer from the string buffer
            if (sscanf(buffer, "%d", &value) == 1) {
                return value;
            }
        }
        printf("Invalid input. Please enter a number.\n");
    }
}

// 4. Safe Float Reader
float readFloat(const char* prompt) {
    char buffer[MAX_Input];
    float value;
    while (1) {
        printf("%s", prompt);
        if (fgets(buffer, MAX_Input, stdin) != NULL) {
            if (sscanf(buffer, "%f", &value) == 1) {
                return value;
            }
        }
        printf("Invalid input. Please enter a decimal number.\n");
    }
}

// --- FILE OPERATIONS (Direct Access Logic) ---

void addProduct(FILE* f) {
    Product p;

    // Using our new safe helpers
    p.id = readInt("Enter ID (1-100): ");

    if (p.id < 1 || p.id > 100) {
        printf("Error: ID must be between 1 and 100.\n");
        return;
    }

    readString("Enter Name: ", p.name, sizeof(p.name));
    p.price = readFloat("Enter Price: ");
    p.quantity = readInt("Enter Quantity: ");

    // CALCULATE OFFSET: (ID - 1) * Size of Record
    long offset = (long)(p.id - 1) * sizeof(Product);

    fseek(f, offset, SEEK_SET);
    fwrite(&p, sizeof(Product), 1, f);

    printf("--> Product saved successfully at byte %ld.\n", offset);
}

void searchProduct(FILE* f) {
    Product p;
    int id = readInt("Enter ID to search: ");

    long offset = (long)(id - 1) * sizeof(Product);

    fseek(f, offset, SEEK_SET);

    // Check if read succeeds AND if ID is not 0 (empty slot)
    if (fread(&p, sizeof(Product), 1, f) == 1 && p.id != 0) {
        printf("\n[FOUND] ID: %d\n", p.id);
        printf("Name: %s\n", p.name);
        printf("Price: $%.2f\n", p.price);
        printf("Qty:  %d\n", p.quantity);
    }
    else {
        printf("--> Record empty or not found for ID %d.\n", id);
    }
}

void updatePrice(FILE* f) {
    Product p;
    int id = readInt("Enter ID to update: ");
    long offset = (long)(id - 1) * sizeof(Product);

    // 1. SEEK to location
    fseek(f, offset, SEEK_SET);

    // 2. READ to memory to verify existence
    if (fread(&p, sizeof(Product), 1, f) == 0 || p.id == 0) {
        printf("--> Product does not exist.\n");
        return;
    }

    printf("Current Price: $%.2f\n", p.price);

    // 3. MODIFY in memory
    p.price = readFloat("Enter New Price: ");

    // 4. SEEK BACK (Vital Step!)
    // fread moved the cursor forward, we must put it back
    fseek(f, offset, SEEK_SET);

    // 5. WRITE updated structure
    fwrite(&p, sizeof(Product), 1, f);
    printf("--> Price updated successfully.\n");
}

void listAll(FILE* f) {
    Product p;
    rewind(f); // Go to start

    printf("\n%-5s %-20s %-10s %-5s\n", "ID", "Name", "Price", "Qty");
    printf("---------------------------------------------\n");

    // Read sequentially
    while (fread(&p, sizeof(Product), 1, f) == 1) {
        if (p.id != 0) {
            printf("%-5d %-20s $%-9.2f %-5d\n", p.id, p.name, p.price, p.quantity);
        }
    }
    printf("\n");
}

// --- MAIN ---

int main() {
    FILE* file;

    // Open for Binary Read/Write (Create if not exists)
    if ((file = fopen(FILENAME, "rb+")) == NULL) {
        if ((file = fopen(FILENAME, "wb+")) == NULL) {
            printf("Fatal Error: Cannot open/create file.\n");
            return 1;
        }
    }

    int choice = 0;
    while (1) {
        printf("\n=== DIRECT ACCESS INVENTORY ===\n");
        printf("1. Add Product\n");
        printf("2. Search Product\n");
        printf("3. Update Price\n");
        printf("4. List All\n");
        printf("5. Exit\n");

        choice = readInt("Select Option: ");

        switch (choice) {
        case 1: addProduct(file); break;
        case 2: searchProduct(file); break;
        case 3: updatePrice(file); break;
        case 4: listAll(file); break;
        case 5: fclose(file); return 0;
        default: printf("Invalid choice. Try 1-5.\n");
        }
    }
}