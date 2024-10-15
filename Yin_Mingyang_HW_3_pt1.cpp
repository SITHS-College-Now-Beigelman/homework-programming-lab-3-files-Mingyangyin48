// Mingyang Michelle Yin  
// Oct 15, 2024
// HW 3 Part 1

#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main () 
{
    // setting variables

    ifstream inFile;

    inFile.open("transactions.txt");

    int transactions;
    double totalMoney;
    double totalDebit = 0;
    double totalCredit = 0;

    inFile >> totalMoney;
    cout << "The user has " << totalMoney << " in their account." << endl;
    cout << endl;



    for (transactions = 0; transactions < 7; transactions++)
    {
        double transactionAmount;
        char transactionType; 
        string transactionName;
        inFile >> transactionType >> transactionAmount;

        switch (transactionType)
        {
            case 'D':
            {
                transactionName = "credit";
                totalCredit += transactionAmount;
                totalMoney += transactionAmount;

                break;
            }

            case 'W':
            {
                transactionName = "debit";
                totalDebit += transactionAmount;
                totalMoney -= transactionAmount; 
                break;
            }
        }

        cout << "Amount from " << transactionName << " transactions is: " << transactionAmount << endl;
        cout << "The total amount in the user's account is: " << totalMoney << endl;
    }

    cout << endl;
    cout << "The final amount in the user's account is: " << totalMoney << endl;
    cout << "Total credit transactions: " << totalCredit << " Total debit transactions: " << totalDebit << endl;

    inFile.close();

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