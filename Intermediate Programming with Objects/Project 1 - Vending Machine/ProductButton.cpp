/*
* Vending Machine Project
* CSE-40477
*
* ProductButton.cpp
* YOU MUST IMPLEMENT THE FUNCTIONS IN THIS FILE.
*/
#include <cstring>
using std::strcpy;

#include "ProductButton.h"

Project1::ProductButton::ProductButton(ProductRack &productRack)
    : productRack(productRack)
{
    // Empty, check initialization list
}

bool
Project1::ProductButton::press()
{
    // Check if intended product is available
    if (productRack.isEmpty()) {
        return false;
    }

    // Begin deliver process
    productRack.deliverProduct();
    return true;
}

unsigned
Project1::ProductButton::getProductPriceCents() const
{
    return productRack.getProductPriceCents();
}
