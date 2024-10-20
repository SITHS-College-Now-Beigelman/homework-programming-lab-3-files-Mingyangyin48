// Mingyang Michelle Yin  
// Oct 15, 2024
// HW 3 Part 2

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

main () 
{
    // reads and writes in both files
    ifstream inFile;
    ofstream outFile;

    // opens both files
    inFile.open("transactions.txt");
    outFile.open("printout.txt");

        // setting variables
    int transactions;
    double totalMoney;
    double totalDebit = 0;
    double totalCredit = 0;
        
    inFile >> totalMoney; // reads what the total money is
    outFile << "THE USER HAS A STARTING BALANCE OF $ " << totalMoney << endl; // writes the total money in the output file
    outFile << endl;
    outFile << "TYPE" << setw (12) << setfill('.') << "AMOUNT" << setw (18) << setfill('.') << "BALANCE" << endl;
    // setting the formating of the output file

    while (!inFile.eof()) // while it is not the end of the read file 
    {
            // setting variables
        double transactionAmount;
        char transactionType; 
        char transactionName;
        inFile >> transactionType >> transactionAmount; // find what the transaction type and amount is

        switch (transactionType)
        {
            case 'D': // if in the case of deposits add to D and the total transaction amount
            {
                transactionName = 'D';
                totalCredit += transactionAmount;
                totalMoney += transactionAmount;
                break;
            }

            case 'W': // if in the case of withdraws add to W and subtact to the total transaction amount
            {
                transactionName = 'W';
                totalDebit += transactionAmount;
                totalMoney -= transactionAmount; 
                break;
            }
        }
        outFile << " " << transactionName << setw (10) << setfill('.') << "$" << transactionAmount << setw (14) << setfill('.') << "$" << totalMoney << endl;
        // sets the formating for the transaction type, amount and total money
    }

        // end of file
    outFile << endl;
    outFile << "ENDING BALANCE: $" << totalMoney << endl; // total ending amount
    outFile << "TOTAL WITHDRAWALS: $" << totalDebit << endl; // total withdraws
    outFile << "TOTAL DEPOSITS: $" << totalCredit << endl; // total deposits

    // closes both files
    inFile.close();
    outFile.close();

    return 0;
}

/*

                //OUTPUT//

    THE USER HAS A STARTING BALANCE OF $ 5000

    TYPE......AMOUNT...........BALANCE
    W.........$200.............$4800
    W.........$800.............$4000
    W.........$40.............$3960
    D.........$90.............$4050
    D.........$100.............$4150
    D.........$1000.............$5150
    W.........$20.............$5130

    ENDING BALANCE: $5130
    TOTAL WITHDRAWALS: $1060
    TOTAL DEPOSITS: $1190

*/