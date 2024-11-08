#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Product {
    int productID;
    char productName[50];
    int quantity;
    float price;
};

// global variable rakhsi
struct Product inventory[200];
int numproducts = 0;


void Productshow() 
{

    if (numproducts == 0) {
        printf("No products in inventory.\n");
        return;
    }

    for (int i = 0; i < numproducts; i++) {
        printf("%d    %s    %d    %.2f\n", inventory[i].productID, inventory[i].productName, inventory[i].quantity, inventory[i].price);
    }
}

void addproduct() {

    struct Product newproduct;

    if (numproducts >= 200) {
        printf("Inventory is full. Cannot add more products.\n");
    }
    else 
    {
        scanf("%d", &newproduct.productID);

        scanf("%s", newproduct.productName);

        scanf("%d", &newproduct.quantity);

        scanf("%f", &newproduct.price);

        inventory[numproducts] = newproduct;
        numproducts++;
    }
}

void deleteproduct() 
{
    int productID;
    scanf("%d", &productID);

    for (int i = 0; i < numproducts; i++) 
    {
        if (inventory[i].productID == productID) 
        {
            for (int j = i; j < numproducts - 1; j++)           // shobgulake 1 ghor shamne antesi
            {
                inventory[j] = inventory[j + 1];
            }
            numproducts--;
            break;
        }
    }
}

void orderproduct()
 {
    int productID;
    int quantity;
    scanf("%d", &productID);

    scanf("%d", &quantity);

    for (int i = 0; i < numproducts; i++) 
    {
        if (inventory[i].productID == productID) 
        {
            if( inventory[i].quantity >= quantity ) {
                inventory[i].quantity -= quantity;
            }
            break;
        }
    }

}

void restockproduct() 
{
    int productID;
    int quantity;
    scanf("%d", &productID);

    scanf("%d", &quantity);

    for (int i = 0; i < numproducts; i++) {
        if (inventory[i].productID == productID) {
            inventory[i].quantity += quantity;
            break;
        }
    }
}

int main() {

    
    int choice;

    while (1) {

        printf("1. Add Product\n");
        printf("2. Delete Product\n");
        printf("3. Order Product\n");
        printf("4. Restock Product\n");
        printf("5. Show Products\n");
        printf("6. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        if (choice == 1) {
            addproduct();
        } 
        else if (choice == 2) 
        {
            deleteproduct();
        } 
        else if (choice == 3) 
        {
            orderproduct();
        } 
        else if (choice == 4) 
        {
            restockproduct();
        }
        else if( choice == 5 ) 
        {
            Productshow();
        }
        else if (choice == 6) {
            break;
        }
    }

return 0;
}