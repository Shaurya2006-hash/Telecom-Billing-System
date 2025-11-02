# Telecom Billing System

This project is a **console-based Telecom Billing System** implemented in **C**.  
It helps manage customer records, calculate bills, and display billing information efficiently.

---

## 🧾 Features

- Add new customer details  
- Generate and display bills  
- Search, modify, and delete customer records  
- View all stored customer billing information  
- Simple menu-driven interface for ease of use  

---

## ⚙️ Technologies Used

- **C Programming Language**
- **File Handling in C** for storing and retrieving customer data

---

## 🪜 How the Program Works

1. When the program starts, a menu is displayed with options (Add, Search, Modify, Delete, Display).
2. The user selects an option by entering a choice number.
3. The system performs the corresponding action (for example, adding customer details or generating a bill).
4. Data is saved in a text file to maintain records between program runs.

---

## 💻 Installation and Usage

### 1. Clone the repository
```bash
git clone https://github.com/Shaurya2006-hash/Telecom-Billing-System.git
2. Navigate to the project directory
cd Telecom-Billing-System

3. Compile the source code using GCC
gcc telecom_billing_system.c -o telecom_billing_system

4. Run the program
./telecom_billing_system

🕹️ Usage

Run the program in your terminal.

You will see a menu like this:

TELECOM BILLING SYSTEM
1. Add new record
2. Search record
3. Modify record
4. Delete record
5. Display all records
6. Exit
Enter your choice:


Follow the on-screen prompts to perform any action.
The system will automatically save your updates in the file.

📁 File Structure
Telecom-Billing-System/
├── telecom_billing_system.c   # Main C source file
├── customer_records.txt       # Data file storing customer records (auto-created)
└── README.md                  # Project documentation

📤 Example Output
TELECOM BILLING SYSTEM

1. Add new record
2. Search record
3. Modify record
4. Delete record
5. Display all records
6. Exit

Enter your choice: 1

Enter customer name: John Doe
Enter phone number: 9876543210
Enter bill amount: 550.75

Record added successfully!
