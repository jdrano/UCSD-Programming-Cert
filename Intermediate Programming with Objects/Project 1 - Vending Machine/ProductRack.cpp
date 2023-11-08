/*
* Vending Machine Project
* CSE-40477
*
* ProductRack.cpp
* YOU MUST IMPLEMENT THE FUNCTIONS IN THIS FILE.
*/
#include <cstring>
#include <iostream>
#include <string.h>
using std::strcmp;

#include "ProductRack.h"

Project1::ProductRack::ProductRack(
    StatusPanel &statusPanel,
    const char *allowedProductName,
    DeliveryChute &deliveryChute,
    unsigned productPriceCents)
    : statusPanel(statusPanel),
    deliveryChute(deliveryChute),
    productCount(0),
    productPriceCents(productPriceCents)
{
    // Copy the name of the products passed in into the rack name
    strcpy_s(this->allowedProductName, allowedProductName);

    // Initialize the rack to have no (nullptr) objects
    for (int curr_product = 0; curr_product < MAX_PRODUCTS; curr_product++) {
        products[curr_product] = nullptr;
    }
}

Project1::ProductRack::~ProductRack()
{
    // Delete all the products within the rack
    for (int curr_product = 0; curr_product < MAX_PRODUCTS; curr_product++) {
        delete products[curr_product];
    }

}

bool
Project1::ProductRack::isCompatibleProduct(const char *productName) const
{
    return strcmp(this->allowedProductName, productName) == 0;
}

bool
Project1::ProductRack::isFull() const
{
    return productCount == MAX_PRODUCTS;
}

bool
Project1::ProductRack::isEmpty() const
{
    return productCount == 0;
}

bool
Project1::ProductRack::addProduct(Product* pProduct)
{
    // Check if the product to be added matches the rack name
    // Displays the proper error code to the status panel
    if (!isCompatibleProduct(pProduct->getName())) {
        statusPanel.displayMessage
        (StatusPanel::MESSAGECODE_PRODUCT_DOES_NOT_MATCH_PRODUCT_RACK);
        return false;
    }

    // Check if the rack is full
    // Displays the proper error code to the status panel
    if (isFull()) {
        statusPanel.displayMessage(StatusPanel::MESSAGECODE_RACK_IS_FULL);
        return false;
    }

    // Cycle through each product in the rack looking for 1st empty spot
    for (int curr_product = 0; curr_product < MAX_PRODUCTS; curr_product++) {

        // If current spot is empty, add the product to that spot
        if (products[curr_product] == nullptr) {
            products[curr_product] = pProduct;
            productCount++;
            return true;
        }
    }

    return true;
}

bool
Project1::ProductRack::deliverProduct()
{
    // Check if the rack is empty
    // Displays the proper error code to the status panel
    if (isEmpty()) {
        statusPanel.displayMessage(StatusPanel::MESSAGECODE_SOLD_OUT);
        return false;
    }

    // Cycle through each product in the rack looking for 1st product
    for (int curr_product = 0; curr_product < MAX_PRODUCTS; curr_product++) {

        // If product is available begin delivery process
        if (products[curr_product] != nullptr) {

            // Check if delivery chute is available for product insert
            if (deliveryChute.insertProduct(products[curr_product])) {
                products[curr_product] = nullptr;
                productCount--;
                return true;
            }
            else {
                // Displays the proper error code to the status panel
                statusPanel.displayMessage(StatusPanel::MESSAGECODE_CHUTE_FULL);
                return false;
            }
        }
    }
    return true;
}

unsigned
Project1::ProductRack::getNumProductsInRack() const
{
    return productCount;
}

unsigned
Project1::ProductRack::getProductPriceCents() const
{
    return productPriceCents;
}
