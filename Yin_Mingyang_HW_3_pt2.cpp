// Mingyang Michelle Yin  
// Oct 15, 2024
// HW 3 Part 2

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

main () 
{
    // setting variables

    ifstream inFile;
    ofstream outFile;

    inFile.open("transactions.txt");
    outFile.open("printout.txt");

    int transactions;
    double totalMoney;
    double totalDebit = 0;
    double totalCredit = 0;
        

    inFile >> totalMoney;
    outFile  << "THE USER HAS " << totalMoney << " IN THEIR ACCOUNT." << endl;
    outFile  << endl << endl;

    while (!inFile.eof())
    {
        double transactionAmount;
        char transactionType; 
        char transactionName;
        inFile >> transactionType >> transactionAmount;

        switch (transactionType)
        {
            case 'D':
            {
                transactionName = 'D';
                totalCredit += transactionAmount;
                totalMoney += transactionAmount;

                break;
            }

            case 'W':
            {
                transactionName = 'W';
                totalDebit += transactionAmount;
                totalMoney -= transactionAmount; 
                break;
            }
        }

        cout << transactionName << setw (10) << '.' <<  << transactionAmount << endl;
        cout << "The total amount in the user's account is: " << totalMoney << endl;
    }

    cout << endl;
    cout << "The final amount in the user's account is: " << totalMoney << endl;
    cout << "Total credit transactions: " << totalCredit << " Total debit transactions: " << totalDebit << endl;

    inFile.close();
    outFile.close();

    return 0;
}