/*
* Vending Machine Project
* CSE-40477
*
* Product.cpp
* YOU MUST IMPLEMENT THE FUNCTIONS IN THIS FILE.
*/
#include <cstring>
using std::strcpy;

#include "Product.h"

Project1::Product::Product(const char *brand, const char *name,
    const char *size)
{
    // Copy parameters into the brand, name, and size of the object.
    strncpy_s(this->brand, brand, MAX_BRAND_LENGTH - 1);

    strncpy_s(this->name, name, MAX_NAME_LENGTH - 1);

    strncpy_s(this->size, size, MAX_SIZE_LENGTH - 1);

}

const char *
Project1::Product::getBrand() const
{
    return brand;
}

void
Project1::Product::setBrand(const char *value)
{
    // Copy the brand passed in into the brand of the product
    strcpy_s(brand, value);
}

const char *
Project1::Product::getName() const
{
    return name;
}

void
Project1::Product::setName(const char *value)
{
    // Copy the name passed in into the name of the product
    strcpy_s(name, value);
}

const char *
Project1::Product::getSize() const
{
    return size;
}

void
Project1::Product::setSize(const char *value)
{
    // Copy the size passed in into the size of the product
    strcpy_s(size, value);
}
