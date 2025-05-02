#ifndef CSVREADER_H
#define CSVREADER_H

#include "OrderBookEntry.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<OrderBookEntry> readCSV(const std::string& filename) {
    std::vector<OrderBookEntry> entries;
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Failed to open file.\n";
        return entries;
    }

    std::getline(file, line); // Skip header

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string timestamp, product, orderType, priceStr, amountStr;

        std::getline(ss, timestamp, ',');
        std::getline(ss, product, ',');
        std::getline(ss, orderType, ',');
        std::getline(ss, priceStr, ',');
        std::getline(ss, amountStr, ',');

        try {
            double price = std::stod(priceStr);
            double amount = std::stod(amountStr);
            entries.emplace_back(timestamp, product, orderType, price, amount);
        } catch (...) {
            std::cerr << "Error parsing line: " << line << '\n';
        }
    }

    return entries;
}

#endif
