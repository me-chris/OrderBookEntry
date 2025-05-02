#ifndef ORDERBOOKENTRY_H
#define ORDERBOOKENTRY_H

#include <string>

class OrderBookEntry {
public:
    std::string timestamp;
    std::string product;
    std::string orderType; // "bid" or "ask"
    double price;
    double amount;

    OrderBookEntry(std::string ts, std::string prod, std::string type, double pr, double amt)
        : timestamp(ts), product(prod), orderType(type), price(pr), amount(amt) {}
};

#endif
