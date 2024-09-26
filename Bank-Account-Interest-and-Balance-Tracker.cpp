#include <fstream>  // For file handling
#include <iostream> // For console output (optional)

using namespace std;

int main() {
    ofstream outputFile("resources/output.txt");

    if (!outputFile) {
        cout << "Unable to open file!" << endl;
        return 1;
    }

    double interestRate, startingBalance, totalMonths;
    double totalDeposits = 0, totalWithdrawals = 0, totalInterest = 0;
    int withdrawals = 0, deposits = 0;

    cout << "What is the annual interest rate on the account: ";
    cin >> interestRate;
    cout << "What is the starting balance on the account: ";
    cin >> startingBalance;
    cout << "What is the total months the account is collecting interest: ";
    cin >> totalMonths;

    for (int i = 1; i <= totalMonths; i++) {
        double addedBalance = 0, withdrawnBalance = 0;

        do {
            cout << "How much is added to the account after month " << i << ": ";
            cin >> addedBalance;

            if (addedBalance < 0) {
                cout << "Negative number detected. Please enter a valid amount.\n";
            }
        } while (addedBalance < 0);

        if (addedBalance > 0) {
            deposits++;
            totalDeposits += addedBalance;
        }

        do {
            cout << "How much is withdrawn from the account after month " << i << ": ";
            cin >> withdrawnBalance;

            if (withdrawnBalance < 0) {
                cout << "Negative number detected. Please enter a valid amount.\n";
            }
        } while (withdrawnBalance < 0);

        if (withdrawnBalance > 0) {
            withdrawals++;
            totalWithdrawals += withdrawnBalance;
        }

        startingBalance += addedBalance - withdrawnBalance;

        if (startingBalance < 0) {
            outputFile << "The account has been closed due to a negative balance." << endl;
            break;
        }

        double monthlyInterest = (interestRate / 12) * startingBalance;
        totalInterest += monthlyInterest;
        startingBalance += monthlyInterest;


        outputFile << "Balance after month " << i << ": " << startingBalance << endl;
    }

    outputFile << "\nFinal balance: " << startingBalance << endl;

    outputFile << "Total number of deposits: " << deposits << endl;

    outputFile << "Total number of withdrawals: " << withdrawals << endl;

    outputFile << "Total amount deposited: " << totalDeposits << endl;

    outputFile << "Total amount withdrawn: " << totalWithdrawals << endl;

    outputFile << "Total interest earned: " << totalInterest << endl;

    outputFile.close();

    cout << "Text successfully uploaded to output.txt" << endl;

    return 0;
}
