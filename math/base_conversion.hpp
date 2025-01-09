#pragma once
#include "../../Nyaan's library/math/bigint-all.hpp"

string base_conversion(string n, ull m, ull k) {
    ull decimalValue = 0;
    for (char digit : n) {
        decimalValue *= m;
        if ('0' <= digit && digit <= '9') {
            decimalValue += digit - '0';
        } else if ('a' <= digit && digit <= 'z') {
            decimalValue += digit - 'a' + 10;
        } else if ('A' <= digit && digit <= 'Z') {
            decimalValue += digit - 'A' + 10;
        }
    }
    if (decimalValue == 0) {
        return "0";
    }
    string result;
    while (decimalValue > 0) {
        ull remainder = decimalValue % k;
        if (remainder < 10) {
            result.push_back('0' + remainder);
        } else {
            result.push_back('a' + remainder - 10);
        }
        decimalValue /= k;
    }
    reverse(result.begin(), result.end());
    return result;
}

string base_conversion_bigint(string n, bigint m, bigint k) {
    bigint decimalValue = 0;
    for (char digit : n) {
        decimalValue *= m;
        if ('0' <= digit && digit <= '9') {
            decimalValue += digit - '0';
        } else if ('a' <= digit && digit <= 'z') {
            decimalValue += digit - 'a' + 10;
        } else if ('A' <= digit && digit <= 'Z') {
            decimalValue += digit - 'A' + 10;
        }
    }
    if (decimalValue == 0) {
        return "0";
    }
    string result;
    while (decimalValue > 0) {
        bigint remainder = decimalValue % k;
        if (remainder < 10) {
            result.push_back('0' + stoll(remainder.to_string()));
        } else {
            result.push_back('a' + stoll(remainder.to_string()) - 10);
        }
        decimalValue /= k;
    }
    reverse(result.begin(), result.end());
    return result;
}
