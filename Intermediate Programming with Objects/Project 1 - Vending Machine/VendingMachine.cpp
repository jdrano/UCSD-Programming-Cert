/*
* Vending Machine Project
* CSE-40477
*
* VendingMachine.cpp
* YOU MUST IMPLEMENT THE FUNCTIONS IN THIS FILE.
*/
#include "VendingMachine.h"
#include <iostream>

Project1::VendingMachine::VendingMachine(
    ostream &statusPanelStream,
    const char *productNames[NUM_PRODUCT_RACKS],
    unsigned productPrices[NUM_PRODUCT_RACKS])
    : statusPanel(statusPanelStream),
    deliveryChute(statusPanel),
    numCoins(0),
    unspentMoneyCents(0)
{
    // Create the product racks and their associated buttons for each product
    for (int curr_rack = 0; curr_rack < NUM_PRODUCT_RACKS; curr_rack++) {
        this->productRacks[curr_rack] = new ProductRack(statusPanel, productNames[curr_rack], deliveryChute, productPrices[curr_rack]);
        this->productButtons[curr_rack] = new ProductButton(*this->productRacks[curr_rack]);
    }

    // Initialize the coinbox to be empty
    for (int curr_coin = 0; curr_coin < MAX_COINS; curr_coin++) {
        coinBox[curr_coin] = nullptr;
    }


}

Project1::VendingMachine::~VendingMachine()
{
    // Delete each rack along with the buttons
    for (int curr_rack = 0; curr_rack < NUM_PRODUCT_RACKS; curr_rack++) {
        delete productRacks[curr_rack];
        delete productButtons[curr_rack];
    }

    for (int curr_coin = 0; curr_coin < MAX_COINS; curr_coin++) {
        delete coinBox[curr_coin];
    }

}

bool
Project1::VendingMachine::insertCoin(Coin *pCoin)
{
    // Check if the vending machine is full of coins
    if (numCoins == MAX_COINS) {
        return false;
    }

    // Check if the coin entered is bad
    // Displays the proper error code to the status panel
    if (pCoin->getDenomination() == 0) {
        statusPanel.displayMessage(StatusPanel::MESSAGECODE_BAD_COIN);
        return false;
    }

    // Add coin into the vending machine
    for (int curr_coin = 0; curr_coin < MAX_COINS; curr_coin++) {

        // Add a coin in the first available spot and increase total 
        if (coinBox[curr_coin] == nullptr) {
            coinBox[curr_coin] = pCoin;
            numCoins++;
            unspentMoneyCents += pCoin->getValueCents();
            return true;
        }
    }
    return false;
}

bool
Project1::VendingMachine::pressButton(int button)
{
    // Check if the button is a valid enter
    // Displays the proper error code to the status panel
    if (button > NUM_PRODUCT_RACKS) {
        statusPanel.displayMessage(StatusPanel::MESSAGECODE_WRONG_BUTTON);
        return false;
    }

    // Check if the machine as enough money for the purchase
    // Displays the proper error code to the status panel
    if (unspentMoneyCents < this->productRacks[button]->getProductPriceCents()) {
        statusPanel.displayMessage(StatusPanel::MESSAGECODE_INSUFFICIENT_MONEY);
        return false;
    }

    // Check if the product is available to be bought
    // Displays the proper error code to the status panel
    if (productRacks[button]->isEmpty()) {
        statusPanel.displayMessage(StatusPanel::MESSAGECODE_SOLD_OUT);
        return false;
    }

    // Buy the product and begin delivery process
    unspentMoneyCents -= productRacks[button]->getProductPriceCents();
    this->productButtons[button]->press();
    return true;
}

Project1::Product *
Project1::VendingMachine::retrieveProduct()
{
    return deliveryChute.retrieveProduct();
}

bool
Project1::VendingMachine::addProduct(Product *pProduct)
{
    // Check every rack to add the product to the proper spot
    for (int curr_rack = 0; curr_rack < NUM_PRODUCT_RACKS; curr_rack++) {

        // Add product to the rack that matches the name
        if (productRacks[curr_rack]->isCompatibleProduct(pProduct->getName())) {
            return productRacks[curr_rack]->addProduct(pProduct);
        }
    }

    // Displays the proper error code to the status panel
    statusPanel.displayMessage(StatusPanel::MESSAGECODE_NO_RACK_FOR_PRODUCT);
    return false;
}

unsigned
Project1::VendingMachine::getProductCount(const char *productName) const
{
    // Check every rack for matching product name
    for (int curr_rack = 0; curr_rack < NUM_PRODUCT_RACKS; curr_rack++) {

        // Once matched return product amount
        if (productRacks[curr_rack]->isCompatibleProduct(productName)) {
            return productRacks[curr_rack]->getNumProductsInRack();
        }
    }

    return 0;
}

unsigned
Project1::VendingMachine::countTill() const
{
    unsigned value = 0;

    // Add the value of all coins currently in the machine
    for (int curr_coin = 0; curr_coin < getNumCoinsInCoinBox(); curr_coin++) {
        value += coinBox[curr_coin]->getValueCents();
    }

    return value;
}

unsigned
Project1::VendingMachine::getNumCoinsInCoinBox() const
{
    return numCoins;
}
