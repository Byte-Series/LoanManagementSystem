/* 
  Program : Loan Management System
  Language: C++
  International Islamic University, Islamabad
*/

#include <iostream>
#include <string>
using namespace std;

// Loan class to store loan details
class Loan {
private:
    int loanID;
    string customerName;
    float amount;
    float interestRate;
    int duration; // in months
    Loan* next; // pointer to the next loan (linked list implementation)

public:
    Loan() : loanID(0), amount(0.0), interestRate(0.0), duration(0), next(nullptr) {}

    void addLoan(int id, string name, float amt, float rate, int dur) {
        loanID = id;
        customerName = name;
        amount = amt;
        interestRate = rate;
        duration = dur;
        next = nullptr;
    }

    // Function to calculate interest
    float calculateInterest() {
        float durationYears = duration / 12.0; // convert months to years
        float interest = (amount * interestRate * durationYears) / 100;
        return interest;
    }

    // Function to calculate total amount payable
    float calculateTotalAmount() {
        return amount + calculateInterest();
    }

    void displayLoan() {
        cout << "Loan ID: " << loanID << endl;
        cout << "Customer Name: " << customerName << endl;
        cout << "Amount: " << amount << endl;
        cout << "Interest Rate: " << interestRate << "%" << endl;
        cout << "Duration: " << duration << " months" << endl;
        cout << "Interest Amount: " << calculateInterest() << endl;
        cout << "Total Amount Payable after " << duration << " months: " << calculateTotalAmount() << endl;
    }

    int getLoanID() {
        return loanID;
    }

    void updateLoan(float amt, float rate, int dur) {
        amount = amt;
        interestRate = rate;
        duration = dur;
    }

    Loan* getNext() {
        return next;
    }

    void setNext(Loan* nextLoan) {
        next = nextLoan;
    }
};

// LoanManagement class to manage the linked list of loans
class LoanManagement {
private:
    Loan* head; // head pointer for linked list

public:
    LoanManagement() : head(nullptr) {}

    // Add a new loan
    void addLoan() {
        int id, duration;
        string name;
        float amount, rate;

        cout << "Enter Loan ID: ";
        cin >> id;
        cout << "Enter Customer Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Loan Amount: ";
        cin >> amount;
        cout << "Enter Interest Rate (%): ";
        cin >> rate;
        cout << "Enter Duration (months): ";
        cin >> duration;

        Loan* newLoan = new Loan();
        newLoan->addLoan(id, name, amount, rate, duration);

        if (head == nullptr) {
            head = newLoan;
        } else {
            Loan* temp = head;
            while (temp->getNext() != nullptr) {
                temp = temp->getNext();
            }
            temp->setNext(newLoan);
        }

        cout << "Loan added successfully!\n";
    }

    // View details of all loans
    void viewLoans() {
        if (head == nullptr) {
            cout << "No loans to display.\n";
            return;
        }

        Loan* temp = head;
        while (temp != nullptr) {
            temp->displayLoan();
            cout << "-------------------\n";
            temp = temp->getNext();
        }
    }

    // Search for a loan by ID
    void searchLoan() {
        int id;
        cout << "Enter Loan ID to search: ";
        cin >> id;

        Loan* temp = head;
        while (temp != nullptr) {
            if (temp->getLoanID() == id) {
                temp->displayLoan();
                return;
            }
            temp = temp->getNext();
        }
        cout << "Loan not found.\n";
    }

    // Update loan details
    void updateLoan() {
        int id;
        cout << "Enter Loan ID to update: ";
        cin >> id;

        Loan* temp = head;
        while (temp != nullptr) {
            if (temp->getLoanID() == id) {
                float amount, rate;
                int duration;
                cout << "Enter new amount: ";
                cin >> amount;
                cout << "Enter new interest rate (%): ";
                cin >> rate;
                cout << "Enter new duration (months): ";
                cin >> duration;

                temp->updateLoan(amount, rate, duration);
                cout << "Loan updated successfully!\n";
                return;
            }
            temp = temp->getNext();
        }
        cout << "Loan not found.\n";
    }

    // Delete a loan
    void deleteLoan() {
        int id;
        cout << "Enter Loan ID to delete: ";
        cin >> id;

        if (head == nullptr) {
            cout << "No loans to delete.\n";
            return;
        }

        // If loan to be deleted is head
        if (head->getLoanID() == id) {
            Loan* temp = head;
            head = head->getNext();
            delete temp;
            cout << "Loan deleted successfully!\n";
            return;
        }

        Loan* temp = head;
        while (temp->getNext() != nullptr && temp->getNext()->getLoanID() != id) {
            temp = temp->getNext();
        }

        if (temp->getNext() == nullptr) {
            cout << "Loan not found.\n";
        } else {
            Loan* delLoan = temp->getNext();
            temp->setNext(delLoan->getNext());
            delete delLoan;
            cout << "Loan deleted successfully!\n";
        }
    }
};

// Menu-driven system
int main() {
    LoanManagement lm;
    int choice;

    do {
        cout << "====== Loan Management System ======\n";
        cout << "1. Add Loan\n";
        cout << "2. View All Loans\n";
        cout << "3. Search Loan\n";
        cout << "4. Update Loan\n";
        cout << "5. Delete Loan\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            lm.addLoan();
            break;
        case 2:
            lm.viewLoans();
            break;
        case 3:
            lm.searchLoan();
            break;
        case 4:
            lm.updateLoan();
            break;
        case 5:
            lm.deleteLoan();
            break;
        case 6:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
