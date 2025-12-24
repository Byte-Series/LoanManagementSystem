# Loan Management System

A comprehensive C++ application for managing loans using a linked list data structure. This system provides a menu-driven interface for performing various loan management operations.

## Features

- **Add Loan**: Create new loan records with customer details
- **View All Loans**: Display all loans with calculated interest and total payable amounts
- **Search Loan**: Find specific loans by Loan ID
- **Update Loan**: Modify existing loan details (amount, interest rate, duration)
- **Delete Loan**: Remove loan records from the system
- **Interest Calculation**: Automatically calculate interest based on principal, rate, and duration
- **Total Amount Calculation**: Display total amount payable including principal and interest

## Technical Details

- **Language**: C++
- **Data Structure**: Singly Linked List
- **Compilation**: Standard C++ compiler (g++)

### Loan Attributes

Each loan record contains:
- **Loan ID**: Unique identifier for the loan
- **Customer Name**: Name of the borrower
- **Amount**: Principal loan amount
- **Interest Rate**: Annual interest rate (in percentage)
- **Duration**: Loan duration in months

### Interest Calculation Formula

```
Interest = (Principal × Rate × Time in Years) / 100
Total Amount = Principal + Interest
```

## Installation & Compilation

### Prerequisites

- A C++ compiler (g++, clang++, or similar)
- C++11 or later standard support

### Compilation Steps

#### Using g++

```bash
g++ -o loan_management loan_management.cpp
```

#### With compiler warnings

```bash
g++ -o loan_management loan_management.cpp -Wall -Wextra
```

#### Using a Makefile (if provided)

```bash
make
```

## Usage

### Running the Application

```bash
./loan_management
```

### Menu Options

Upon running, you'll see the following menu:

```
====== Loan Management System ======
1. Add Loan
2. View All Loans
3. Search Loan
4. Update Loan
5. Delete Loan
6. Exit
Enter your choice:
```

### Example Workflow

1. **Adding a Loan**:
   - Select option 1
   - Enter Loan ID (e.g., 1001)
   - Enter Customer Name (e.g., John Doe)
   - Enter Loan Amount (e.g., 50000)
   - Enter Interest Rate (e.g., 5.5)
   - Enter Duration in months (e.g., 24)

2. **Viewing All Loans**:
   - Select option 2
   - System displays all loans with calculated interest and total amounts

3. **Searching for a Loan**:
   - Select option 3
   - Enter the Loan ID to search
   - System displays the loan details if found

4. **Updating a Loan**:
   - Select option 4
   - Enter the Loan ID to update
   - Enter new amount, interest rate, and duration

5. **Deleting a Loan**:
   - Select option 5
   - Enter the Loan ID to delete
   - System removes the loan from records

6. **Exit**:
   - Select option 6 to exit the application

## Example Output

```
Enter Loan ID: 1001
Enter Customer Name: John Doe
Enter Loan Amount: 50000
Enter Interest Rate (%): 5.5
Enter Duration (months): 24
Loan added successfully!

Loan ID: 1001
Customer Name: John Doe
Amount: 50000
Interest Rate: 5.5%
Duration: 24 months
Interest Amount: 5500
Total Amount Payable after 24 months: 55500
```

## Project Structure

```
LoanManagementSystem/
├── loan_management.cpp    # Main source code
├── loan_management.txt    # Additional notes/documentation
├── README.md              # This file
└── .gitignore            # Git ignore rules
```

## Implementation Details

### Class Structure

**Loan Class**:
- Stores individual loan details
- Implements methods for interest calculation and display
- Contains a pointer to the next loan node (for linked list)

**LoanManagement Class**:
- Manages the linked list of loans
- Implements CRUD operations (Create, Read, Update, Delete)
- Maintains the head pointer of the linked list

### Memory Management

- Dynamic memory allocation using `new` operator
- Proper deallocation using `delete` when removing loans
- Linked list structure for efficient insertion and deletion

## Contributing

Contributions are welcome! Please feel free to submit issues or pull requests.

## Institution

International Islamic University, Islamabad

## License

This project is developed for educational purposes.
