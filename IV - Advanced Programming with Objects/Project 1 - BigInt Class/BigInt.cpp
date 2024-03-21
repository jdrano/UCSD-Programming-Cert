//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming IV : Advanced Programming with Objects
// 177752, Prof. Mitchell
// 02/10/24
// BigInt.cpp
// Win10
// Visual Studio 2022
//
//  Contains the implementation for the BigInt class
//

#include <string>
#include <stdexcept>
#include <iostream>
#include <algorithm>
using namespace std;

#include "BigInt.h"
using namespace Project1;

/*******************************************************************************
* 
* Constructors
* 
*******************************************************************************/
BigInt::BigInt()
{
    value = "0";
    positive = true;
}

BigInt::BigInt(const BigInt &other)
{
    this->positive = other.positive;
    this->value= other.value;
}

BigInt::BigInt(long long value)
{
    if (value < 0) 
    {
        positive = false;
    }
    else 
    {
        positive = true;
    }

    this->value = to_string(value);
}

BigInt::BigInt(const string& other)
{
    // Check that string is valid
    validStringCheck(other);
    this->value = simplifyString(other);

    // Check for sign value
    if (value[0] == '-') 
    {
        positive = false;
    }
    else 
    {
        positive = true;
    }
}

/*******************************************************************************
*
* Input and Output Stream functions
*
*******************************************************************************/
ostream&
Project1::operator<<(ostream &os, const BigInt &bi_)
{
    os << bi_.value;
    return os;
}

istream&
Project1::operator>>(istream &in, BigInt &bi_)
{
    in >> bi_.value;
    return in;
}

/*******************************************************************************
*
* Overloads
*
*******************************************************************************/
bool 
Project1::operator<(const BigInt &a, const BigInt &b)
{
    if (a.positive && !b.positive)
    {
        return false;
    }
    
    if (!a.positive && b.positive)
    {
        return true;
    }

    // Algorithm check if signs are both positive
    if (a.positive && b.positive)
    {
        // Check for same length
        if (a.value.size() > b.value.size())
        {
            return false;
        }
        else if (a.value.size() < b.value.size())
        {
            return true;
        }
        else
        {
            int max_length =
                (a.value.size() <= b.value.size()) ?
                b.value.size() : a.value.size();

            // Compare every value until mismatch value occurs
            for (int curr_num = 0; curr_num < max_length; curr_num++)
            {
                int tmp_value;

                int a_num;
                // Safety check in case we reach end of string
                if (curr_num > a.value.size() - 1)
                {
                    a_num = 0;
                }
                else
                {
                    a_num = a.value[curr_num] - '0';
                }

                int b_num;
                // Safety check in case we reach end of string
                if (curr_num > b.value.size() - 1)
                {
                    b_num = 0;
                }
                else
                {
                    b_num = b.value[curr_num] - '0';
                }

                if (a_num < b_num)
                {
                    return true;
                }
                else if (a_num > b_num)
                {
                    return false;
                }
            }
        }
    }

    // Algorithm check if both negative
    else
    {
        string a_str = a.value;
        string b_str = b.value;
        a_str.erase(0, 1);
        b_str.erase(0, 1);

        if (a.value.size() > b.value.size())
        {
            return true;
        }
        else if (a.value.size() < b.value.size())
        {
            return false;
        }
        else
        {
            int max_length =
                (a.value.size() <= b.value.size()) ?
                b.value.size() : a.value.size();

            // Compare every value until mismatch value occurs
            for (int curr_num = 0; curr_num < max_length; curr_num++)
            {
                int tmp_value;

                int a_num;
                // Safety check in case we reach end of string
                if (curr_num > a.value.size() - 1)
                {
                    a_num = 0;
                }
                else
                {
                    a_num = a.value[curr_num] - '0';
                }

                int b_num;
                // Safety check in case we reach end of string
                if (curr_num > b.value.size() - 1)
                {
                    b_num = 0;
                }
                else
                {
                    b_num = b.value[curr_num] - '0';
                }

                if (a_num < b_num)
                {
                    return false;
                }
                else if (a_num > b_num)
                {
                    return true;
                }
            }
        }
    }

    return false;
}

bool
Project1::operator<=(const BigInt& a, const BigInt& b)
{
    if (a.value == b.value)
    {
        return true;
    }
    else
    {
        return a < b;
    }
}
bool
Project1::operator>(const BigInt &a, const BigInt &b)
{
    if (a.positive && !b.positive)
    {
        return true;
    }

    if (!a.positive && b.positive)
    {
        return false;
    }

    // Algorithm check when signs are both positive
    if (a.positive && b.positive)
    {
        if (a.value.size() > b.value.size())
        {
            return true;
        } 
        else if (a.value.size() < b.value.size())
        {
            return false;
        }
        else
        {
            int max_length = 
                (a.value.size() <= b.value.size()) ? 
                b.value.size() : a.value.size();

            // Check for mismatch string
            for (int curr_num = 0; curr_num < max_length; curr_num++)
            {
                int tmp_value;

                int a_num;
                // Safety check in case we reach end of string
                if (curr_num > a.value.size() - 1)
                {
                    a_num = 0;
                }
                else
                {
                    a_num = a.value[curr_num] - '0';
                }

                int b_num;
                // Safety check in case we reach end of string
                if (curr_num > b.value.size() - 1)
                {
                    b_num = 0;
                }
                else
                {
                    b_num = b.value[curr_num] - '0';
                }

                if (a_num < b_num)
                {
                    return false;
                }
                else if (a_num > b_num)
                {
                    return true;
                }
            }
        }
    }
    else
    {
        string a_str = a.value;
        string b_str = b.value;
        a_str.erase(0, 1);
        b_str.erase(0, 1);

        if (a.value.size() > b.value.size())
        {
            return false;
        }
        else if (a.value.size() < b.value.size())
        {
            return true;
        }
        else
        {
            int max_length =
                (a.value.size() <= b.value.size()) ?
                b.value.size() : a.value.size();

            // Check for mismatch string
            for (int curr_num = 0; curr_num < max_length; curr_num++)
            {
                int tmp_value;

                int a_num;
                // Safety check in case we reach end of string
                if (curr_num > a.value.size() - 1)
                {
                    a_num = 0;
                }
                else
                {
                    a_num = a.value[curr_num] - '0';
                }

                int b_num;
                // Safety check in case we reach end of string
                if (curr_num > b.value.size() - 1)
                {
                    b_num = 0;
                }
                else
                {
                    b_num = b.value[curr_num] - '0';
                }

                if (a_num < b_num)
                {
                    return true;
                }
                else if (a_num > b_num)
                {
                    return false;
                }
            }
        }
    }

    return false;
}

bool
Project1::operator>=(const BigInt& a, const BigInt& b)
{
    if (a.value == b.value)
    {
        return true;
    }
    else
    {
        return a > b;
    }
}

bool
Project1::operator==(const BigInt &a, const BigInt &b)
{
    return a.value == b.value;
}

bool
Project1::operator!=(const BigInt &a, const BigInt &b)
{
    return a.value != b.value;
}

BigInt
BigInt::operator+(const BigInt &a)
{

    return addition(*this, a);
}

BigInt
BigInt::operator-(const BigInt& a)
{

    return subtraction(*this, a);
}

const BigInt&
BigInt::operator=(const BigInt &source)
{
    if (this == &source)
    {
        return *this;
    }

    this->positive = source.positive;
    this->value = source.value;

    return *this;
}

const BigInt& 
BigInt::operator+=(const BigInt &other)
{
    *this = addition(*this, other);

    return *this;
}

const BigInt&
BigInt::operator-=(const BigInt& other)
{
    *this = subtraction(*this, other);

    return *this;
}

/*******************************************************************************
*
* Custom functions
*
*******************************************************************************/
string
BigInt::simplifyString(string str)
{
    if ((str[0] == '-' || str[0] == '+') && str[1] == '0')
    {
        str.erase(0, 1);
    }

    if (str[0] == '+')
    {
        str.erase(0, 1);
    }

    return str;
}

void
BigInt::validStringCheck(const string& str)
{
    // Check for empty input
    if (str.empty()) 
    {
        throw invalid_argument("Empty value entered!");
    }

    // Check for single sign entry
    if (str.size() == 1 && (str[0] == '+' || str[0] == '-'))
    {
        throw invalid_argument("Single sign value entered!");
    }
    
    // Check for multiple 0's
    if (str.size() > 1 && str[0] == '0' && str[1] == '0') {
        throw invalid_argument("Multiple leading zeroes entered!");
    }

    // Check for illegal character found in string
    for (int curr_char = 0; curr_char < str.size(); curr_char++)
    {
        if (illegalCharCheck(str[curr_char]))
        {
            throw invalid_argument("Invalid character found!");
        }

        if (curr_char != 0 &&
            (str[curr_char] == '+' || str[curr_char] == '-')) 
        {
                throw invalid_argument(str[curr_char] + " Found after "
                    "valid location!");
        }
    }
}


bool
BigInt::illegalCharCheck(char character)
{
    if (character == '-' || character == '+' || character == '0' || 
        character == '1' || character == '2' || character == '3' || 
        character == '4' || character == '5' || character == '6' || 
        character == '7' || character == '8' || character == '9') 
    {
        return false;
    }

    return true;
}

BigInt
BigInt::addition(const BigInt& a, const BigInt& b)
{
    // Cases where both a and b have different signs
    if ((a.positive && !b.positive) || (!a.positive && b.positive))
    {
        // Check for greater absVal
        string a_str = a.value;
        string b_str = b.value;

        if (a_str[0] == '-')
        {
            a_str.erase(0, 1);
        }
        if (b_str[0] == '-')
        {
            b_str.erase(0, 1);
        }

        BigInt a_abs(a_str);
        BigInt b_abs(b_str);

        // Case a is negative and is smaller abs, -30,800, do 800 - 30 and add a '-'
        if ((a_abs < b_abs) && !a.positive)
        {
            string result = "";
            reverse(a_str.begin(), a_str.end());
            reverse(b_str.begin(), b_str.end());

            int max_length =
                (a_str.size() <= b_str.size()) ? b_str.size() : a_str.size();

            int borrow = 0;
            for (int curr_num = 0; curr_num < max_length; curr_num++)
            {
                int tmp_value;

                int a_num;
                // Safety check in case we reach end of string
                if (curr_num > a_str.size() - 1)
                {
                    a_num = 0;
                }
                else
                {
                    a_num = a_str[curr_num] - '0';
                }

                int b_num;
                // Safety check in case we reach end of string
                if (curr_num > b_str.size() - 1)
                {
                    b_num = 0;
                }
                else
                {
                    b_num = b_str[curr_num] - '0';
                }

                tmp_value = b_num - a_num - borrow;
                if (tmp_value < 0)
                {
                    borrow = 1;
                    tmp_value += 10;
                }
                else
                {
                    borrow = 0;
                }

                result += tmp_value + '0';
            }

            reverse(result.begin(), result.end());
            return BigInt(result);
        }

        // Case a is negative and greater abs, -28260972, 901, do -1 * (28260972 - 901)
        else if ((a_abs > b_abs) && !a.positive)
        {
            string result = "";
            reverse(a_str.begin(), a_str.end());
            reverse(b_str.begin(), b_str.end());

            int max_length =
                (a_str.size() <= b_str.size()) ? b_str.size() : a_str.size();

            int borrow = 0;
            for (int curr_num = 0; curr_num < max_length; curr_num++)
            {
                int tmp_value;

                int a_num;
                // Safety check in case we reach end of string
                if (curr_num > a_str.size() - 1)
                {
                    a_num = 0;
                }
                else
                {
                    a_num = a_str[curr_num] - '0';
                }

                int b_num;
                // Safety check in case we reach end of string
                if (curr_num > b_str.size() - 1)
                {
                    b_num = 0;
                }
                else
                {
                    b_num = b_str[curr_num] - '0';
                }

                tmp_value = a_num - b_num - borrow;
                if (tmp_value < 0)
                {
                    borrow = 1;
                    tmp_value += 10;
                }
                else
                {
                    borrow = 0;
                }

                result += tmp_value + '0';
            }
            
            reverse(result.begin(), result.end());
            result = '-' + result;
            return BigInt(result);
        }

        // Case a is positive and is smaller abs, 30, -200, do 200 - 30 and add a '-'
        else if ((a_abs < b_abs) && !b.positive)
        {
            string result = "";
            reverse(a_str.begin(), a_str.end());
            reverse(b_str.begin(), b_str.end());

            int max_length =
                (a_str.size() <= b_str.size()) ? b_str.size() : a_str.size();

            int borrow = 0;
            for (int curr_num = 0; curr_num < max_length; curr_num++)
            {
                int tmp_value;

                int a_num;
                // Safety check in case we reach end of string
                if (curr_num > a_str.size() - 1)
                {
                    a_num = 0;
                }
                else
                {
                    a_num = a_str[curr_num] - '0';
                }

                int b_num;
                // Safety check in case we reach end of string
                if (curr_num > b_str.size() - 1)
                {
                    b_num = 0;
                }
                else
                {
                    b_num = b_str[curr_num] - '0';
                }

                tmp_value = b_num - a_num - borrow;
                if (tmp_value < 0)
                {
                    borrow = 1;
                    tmp_value += 10;
                }
                else
                {
                    borrow = 0;
                }

                result += tmp_value + '0';
            }

            result += "-";
            reverse(result.begin(), result.end());
            return BigInt(result);
        }

        // Case a is positive and greater abs, 2826,-901, do -1(2826 - 901)
        else
        {
            string result = "";
            reverse(a_str.begin(), a_str.end());
            reverse(b_str.begin(), b_str.end());

            int max_length =
                (a_str.size() <= b_str.size()) ? b_str.size() : a_str.size();

            int borrow = 0;
            for (int curr_num = 0; curr_num < max_length; curr_num++)
            {
                int tmp_value;

                int a_num;
                // Safety check in case we reach end of string
                if (curr_num > a_str.size() - 1)
                {
                    a_num = 0;
                }
                else
                {
                    a_num = a_str[curr_num] - '0';
                }

                int b_num;
                // Safety check in case we reach end of string
                if (curr_num > b_str.size() - 1)
                {
                    b_num = 0;
                }
                else
                {
                    b_num = b_str[curr_num] - '0';
                }

                tmp_value = a_num - b_num - borrow;
                if (tmp_value < 0)
                {
                    borrow = 1;
                    tmp_value += 10;
                }
                else
                {
                    borrow = 0;
                }

                result += tmp_value + '0';
            }

            reverse(result.begin(), result.end());
            return BigInt(result);
        }
        
    }
    // Cases where both a and b are positive or negative
    else
    {
        string a_str = a.value;
        string b_str = b.value;

        bool both_neg = false;
        if (a_str[0] == '-' && b_str[0] == '-')
        {
            a_str.erase(0, 1);
            reverse(a_str.begin(), a_str.end());

            b_str.erase(0, 1);
            reverse(b_str.begin(), b_str.end());
            both_neg = true;
        }
        else
        {
            reverse(a_str.begin(), a_str.end());
            reverse(b_str.begin(), b_str.end());
        }

        string sum;
        int max_length =
            (a_str.size() <= b_str.size()) ? b_str.size() : a_str.size();

        int carry = 0;
        for (int curr_num = 0; curr_num < max_length; curr_num++)
        {
            int tmp_value;

            int a_num;
            // Safety check in case we reach end of string
            if (curr_num > a_str.size() - 1)
            {
                a_num = 0;
            }
            else
            {
                a_num = a_str[curr_num] - '0';
            }

            int b_num;
            // Safety check in case we reach end of string
            if (curr_num > b_str.size() - 1)
            {
                b_num = 0;
            }
            else
            {
                b_num = b_str[curr_num] - '0';
            }

            tmp_value = a_num + b_num + carry;

            if (tmp_value >= 10)
            {
                tmp_value -= 10;
                sum += tmp_value + '0';
                carry = 1;
            }
            else
            {
                sum += tmp_value + '0';
                carry = 0;
            }
        }

        if (carry == 1)
        {
            sum += carry + '0';
        }

        if (both_neg)
        {
            sum += '-';
        }
        reverse(sum.begin(), sum.end());
        return BigInt(sum);
    }
    return BigInt(0);
}

BigInt
BigInt::subtraction(const BigInt& a, const BigInt& b)
{
    if (a.positive && b.positive && a == b)
    {
        return BigInt(0);
    }

    // Case both positive, (1,3)
    if (a.positive && b.positive)
    {
        string result = "";
        string a_str = a.value;
        string b_str = b.value;
        BigInt a_abs(a_str);
        BigInt b_abs(b_str);
        reverse(a_str.begin(), a_str.end());
        reverse(b_str.begin(), b_str.end());

        // Case (1,3) do - 1 * (3 - 1)
        if (a_abs < b_abs)
        {
            int max_length =
                (a_str.size() <= b_str.size()) ? b_str.size() : a_str.size();
            int borrow = 0;
            for (int curr_num = 0; curr_num < max_length; curr_num++)
            {
                int tmp_value;

                int a_num;
                // Safety check in case we reach end of string
                if (curr_num > a_str.size() - 1)
                {
                    a_num = 0;
                }
                else
                {
                    a_num = a_str[curr_num] - '0';
                }

                int b_num;
                // Safety check in case we reach end of string
                if (curr_num > b_str.size() - 1)
                {
                    b_num = 0;
                }
                else
                {
                    b_num = b_str[curr_num] - '0';
                }

                tmp_value = b_num - a_num - borrow;
                if (tmp_value < 0)
                {
                    borrow = 1;
                    tmp_value += 10;
                }
                else
                {
                    borrow = 0;
                }

                result += tmp_value + '0';
            }

            reverse(result.begin(), result.end());
            bool leader_zero = true;
            while (leader_zero)
            {
                if (result[0] == '0')
                {
                    result.erase(0, 1);
                }
                else
                {
                    break;
                }
            }
            result = '-' + result;
            return BigInt(result);
        }
        // Case (123, 1) do 123 - 1
        else
        {
            string result = "";

            int max_length =
                (a_str.size() <= b_str.size()) ? b_str.size() : a_str.size();

            int borrow = 0;
            for (int curr_num = 0; curr_num < max_length; curr_num++)
            {
                int tmp_value;

                int a_num;
                // Safety check in case we reach end of string
                if (curr_num > a_str.size() - 1)
                {
                    a_num = 0;
                }
                else
                {
                    a_num = a_str[curr_num] - '0';
                }

                int b_num;
                // Safety check in case we reach end of string
                if (curr_num > b_str.size() - 1)
                {
                    b_num = 0;
                }
                else
                {
                    b_num = b_str[curr_num] - '0';
                }

                tmp_value = a_num - b_num - borrow;
                if (tmp_value < 0)
                {
                    borrow = 1;
                    tmp_value += 10;
                }
                else
                {
                    borrow = 0;
                }

                result += tmp_value + '0';
            }

            reverse(result.begin(), result.end());
            bool leader_zero = true;
            while (leader_zero)
            {
                if (result[0] == '0')
                {
                    result.erase(0, 1);
                } 
                else
                {
                    break;
                }
            }
            return BigInt(result);
        }
    }

    // Case both negative, (-5, -3)
    else if (!a.positive && !b.positive)
    {
        string result = "";
        string a_str = a.value;
        string b_str = b.value;
        BigInt a_abs(a_str);
        BigInt b_abs(b_str);

        if (a_str[0] == '-')
        {
            a_str.erase(0, 1);
        }
        if (b_str[0] == '-')
        {
            b_str.erase(0, 1);
        }

        reverse(a_str.begin(), a_str.end());
        reverse(b_str.begin(), b_str.end());

        // Case (-21,-10), do -21 - -10, do -21 + 10, do -1 * (21 - 10) 
        if (a_abs < b_abs)
        {
            int max_length =
                (a_str.size() <= b_str.size()) ? b_str.size() : a_str.size();

            int borrow = 0;
            for (int curr_num = 0; curr_num < max_length; curr_num++)
            {
                int tmp_value;

                int a_num;
                // Safety check in case we reach end of string
                if (curr_num > a_str.size() - 1)
                {
                    a_num = 0;
                }
                else
                {
                    a_num = a_str[curr_num] - '0';
                }

                int b_num;
                // Safety check in case we reach end of string
                if (curr_num > b_str.size() - 1)
                {
                    b_num = 0;
                }
                else
                {
                    b_num = b_str[curr_num] - '0';
                }

                tmp_value = a_num - b_num - borrow;
                if (tmp_value < 0)
                {
                    borrow = 1;
                    tmp_value += 10;
                }
                else
                {
                    borrow = 0;
                }

                result += tmp_value + '0';
            }

            reverse(result.begin(), result.end());
            bool leader_zero = true;
            while (leader_zero)
            {
                if (result[0] == '0')
                {
                    result.erase(0, 1);
                }
                else
                {
                    break;
                }
            }
            result = '-' + result;
            return BigInt(result);
        }

        // Case (123, 1) do 123 - 1
        else
        {
            string result = "";
            int max_length =
                (a_str.size() <= b_str.size()) ? b_str.size() : a_str.size();

            int borrow = 0;
            for (int curr_num = 0; curr_num < max_length; curr_num++)
            {
                int tmp_value;

                int a_num;
                // Safety check in case we reach end of string
                if (curr_num > a_str.size() - 1)
                {
                    a_num = 0;
                }
                else
                {
                    a_num = a_str[curr_num] - '0';
                }

                int b_num;
                // Safety check in case we reach end of string
                if (curr_num > b_str.size() - 1)
                {
                    b_num = 0;
                }
                else
                {
                    b_num = b_str[curr_num] - '0';
                }

                tmp_value = b_num - a_num - borrow;
                if (tmp_value < 0)
                {
                    borrow = 1;
                    tmp_value += 10;
                }
                else
                {
                    borrow = 0;
                }

                result += tmp_value + '0';
            }

            reverse(result.begin(), result.end());
            bool leader_zero = true;
            while (leader_zero)
            {
                if (result[0] == '0')
                {
                    result.erase(0, 1);
                }
                else
                {
                    break;
                }
            }
            return BigInt(result);
        }
    }

    // Cases where a and b have different signs
    else
    {
        // Check for greater absVal
        string a_str = a.value;
        string b_str = b.value;

        if (a_str[0] == '-')
        {
            a_str.erase(0, 1);
        }
        if (b_str[0] == '-')
        {
            b_str.erase(0, 1);
        }

        BigInt a_abs(a_str);
        BigInt b_abs(b_str);

        // Case a is negative and is smaller abs, -901,2826, do -901 - 2826, do -1 * (2826+901)
        if ((a_abs < b_abs) && !a.positive)
        {
            BigInt sum = addition(a_abs, b_abs);
            string neg_sum = "-" + sum.value;
            return BigInt(neg_sum);
        }

        // Case a is negative and greater abs, -2826, 901, do -1 * (2826 + 901)
        else if ((a_abs > b_abs) && !a.positive)
        {
            BigInt sum = addition(a_abs, b_abs);
            string neg_sum = "-" + sum.value;
            return BigInt(neg_sum);
        }

        // Case a is positive and is smaller abs, 30, -200, do 200 - 30 and add a '-'
        else
        {
            BigInt sum = addition(a_abs, b_abs);
            return sum;
        }

    }
    return BigInt(0);
}

