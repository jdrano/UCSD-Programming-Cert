/*
* Vending Machine Project
* CSE-40477
*
* DeliveryChute.cpp
* YOU MUST IMPLEMENT THE FUNCTIONS IN THIS FILE.
*/
#include "DeliveryChute.h"

Project1::DeliveryChute::DeliveryChute(StatusPanel &statusPanel)
    : statusPanel(statusPanel),
    pProduct(0)
{
    // Empty, check initialization list
}

Project1::DeliveryChute::~DeliveryChute()
{
    // No assets
    delete pProduct;
}

bool
Project1::DeliveryChute::insertProduct(Product *pProduct)
{
    // Check if the delivery chute is full
    // Displays the proper error code to the status panel
    if (containsProduct()) {
        statusPanel.displayMessage(StatusPanel::MESSAGECODE_CHUTE_FULL);
        return false;
    }

    // Relinquish ownership of product from rack to delivery chute
    this->pProduct = pProduct;
    return true;
}

Project1::Product *
Project1::DeliveryChute::retrieveProduct()
{
    // Relinquish ownership of product from delivery chute to buyer
    Product *tmp = pProduct;
    pProduct = 0;

    return tmp;
}

bool
Project1::DeliveryChute::containsProduct() const
{
    if (pProduct) {
        return true;
    }

    return false;
}