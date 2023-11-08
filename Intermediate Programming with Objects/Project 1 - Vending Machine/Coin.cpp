/*
* Vending Machine Project
* CSE-40477
*
* Coin.cpp
* YOU MUST IMPLEMENT THE FUNCTIONS IN THIS FILE.
*/
#include "Coin.h"

Project1::Coin::Coin(CoinType denomination)
    : denomination(denomination)
{
    // Empty, check initialization list
}

Project1::Coin::CoinType
Project1::Coin::getDenomination() const
{
    // Depending on the value of the coin, return the proper Coin enum
    switch (getValueCents()) {
        case 1:
            return COINTYPE_PENNY;
        case  5:
            return COINTYPE_NICKEL;
        case 10:
            return COINTYPE_DIME;
        case 25:
            return COINTYPE_QUARTER;
        case 50:
            return COINTYPE_HALF_DOLLAR;
        case 100:
            return COINTYPE_DOLLAR;
    }

    // Return an invalid coin if none of the cases match
    return Coin::COINTYPE_WOODEN_NICKEL;
}

unsigned
Project1::Coin::getValueCents() const
{
    unsigned value = 0;

    // Depending on the type of coin, return the proper value
    switch (denomination) {
        case COINTYPE_WOODEN_NICKEL:
            value = 0;
            break;
        case COINTYPE_PENNY:
            value = 1;
            break;
        case COINTYPE_NICKEL:
            value = 5;
            break;
        case COINTYPE_DIME:
            value = 10;
            break;
        case COINTYPE_QUARTER:
            value = 25;
            break;
        case COINTYPE_HALF_DOLLAR:
            value = 50; 
            break;
        case COINTYPE_DOLLAR:
            value = 100;
            break;
        default:
            break;
    }


    return value;
}
