// Mingyang Michelle Yin  
// Oct 15, 2024
// HW 3 Part 1

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main () 
{
    ifstream inFile; // reads the file

    inFile.open("transactions.txt"); // opens the file

        // setting variables
    int transactions;
    double totalMoney;
    double totalDebit = 0;
    double totalCredit = 0;

    inFile >> totalMoney; // reading what the total money is 
    cout << "The user has " << totalMoney << " in their account." << endl; // telling the user what the total money is
    cout << endl;

    for (transactions = 0; transactions < 7; transactions++) // there are 7 transactions done.
    {
            // setting variables
        double transactionAmount;
        char transactionType; 
        string transactionName;
        inFile >> transactionType >> transactionAmount; // reading the transaction type and the amount of money

        switch (transactionType)
        {
            case 'D': // if in the case of deposits add to credit and the total transaction amount
            {
                transactionName = "credit";
                totalCredit += transactionAmount;
                totalMoney += transactionAmount;
                break;
            }
            case 'W': // if in the case of withdraws add to debits and subtact to the total transaction amount
            {
                transactionName = "debit";
                totalDebit += transactionAmount;
                totalMoney -= transactionAmount; 
                break;
            }
        }

        cout << "Amount from " << transactionName << " transactions is: " << transactionAmount << endl; // telling user what the trasaction is 
        cout << "The total amount in the user's account is: " << totalMoney << endl; // telling the user how much money is left after that transaction
    }
        // at the end 
    cout << endl;
    cout << "The final amount in the user's account is: " << totalMoney << endl; // tells the user the total amount of money
    cout << "Total credit transactions: " << totalCredit << " Total debit transactions: " << totalDebit << endl; ; 
    // tells the user total amount of credit and debit

    inFile.close(); // closes the file

    return 0;
}

/*

    //OUTPUT//

    The user has 5000 in their account.

    Amount from debit transactions is: 200
    The total amount in the user's account is: 4800
    Amount from debit transactions is: 800
    The total amount in the user's account is: 4000
    Amount from debit transactions is: 40
    The total amount in the user's account is: 3960
    Amount from credit transactions is: 90
    The total amount in the user's account is: 4050
    Amount from credit transactions is: 100
    The total amount in the user's account is: 4150
    Amount from credit transactions is: 1000
    The total amount in the user's account is: 5150
    Amount from debit transactions is: 20
    The total amount in the user's account is: 5130

    The final amount in the user's account is: 5130
    Total credit transactions: 1190 Total debit transactions: 1060

*/