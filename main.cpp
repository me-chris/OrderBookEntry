#include <iostream>
#include <vector>
#include <limits>
#include "OrderBookEntry.h"
#include "CSVReader.h"

double computeAveragePrice(const std::vector<OrderBookEntry>& entries) {
    double total = 0;
    for (const auto& e : entries)
        total += e.price;
    return entries.empty() ? 0 : total / entries.size();
}

double computeLowPrice(const std::vector<OrderBookEntry>& entries) {
    double low = std::numeric_limits<double>::max();
    for (const auto& e : entries)
        if (e.price < low) low = e.price;
    return entries.empty() ? 0 : low;
}

double computeHighPrice(const std::vector<OrderBookEntry>& entries) {
    double high = std::numeric_limits<double>::lowest();
    for (const auto& e : entries)
        if (e.price > high) high = e.price;
    return entries.empty() ? 0 : high;
}

double computePriceSpread(const std::vector<OrderBookEntry>& entries) {
    return computeHighPrice(entries) - computeLowPrice(entries);
}

int main() {
    std::vector<OrderBookEntry> orderBook = readCSV("orders.csv");

    for (const auto& entry : orderBook) {
        std::cout << entry.timestamp << " "
                  << entry.product << " "
                  << entry.orderType << " "
                  << entry.price << " "
                  << entry.amount << "\n";
    }

    std::cout << "Average Price: " << computeAveragePrice(orderBook) << "\n";
    std::cout << "Low Price: " << computeLowPrice(orderBook) << "\n";
    std::cout << "High Price: " << computeHighPrice(orderBook) << "\n";
    std::cout << "Price Spread: " << computePriceSpread(orderBook) << "\n";

    return 0;
}
