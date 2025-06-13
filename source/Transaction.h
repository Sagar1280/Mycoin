#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
using namespace std;

struct Transaction {
    string sender;
    string receiver;
    double amount;

    Transaction(const string& sender, const string& receiver, double amount)
        : sender(sender), receiver(receiver), amount(amount) {}
};

#endif