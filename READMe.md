# Library Management System

This is a simple Library Management System implemented in C++. The system allows students to borrow, return, and query books, while administrators can add books, add students, and view available books.

## Classes

The system consists of the following main classes:

1. **Student**
2. **Administrator**
3. **Book**
4. **Library**
5. **Products**
6. **Bake**

### 1. Student Class

This class stores and verifies the identity and passwords of students. It includes methods to get student IDs and passwords.

### 2. Administrator Class

This class stores and verifies the identity and passwords of administrators. It includes methods to get administrator IDs and passwords.

### 3. Book Class

This class stores the titles and quantities of books. It includes a method to decrease the quantity when a book is borrowed.

### 4. Library Class

This class maintains lists of books, students, and administrators. It includes methods for adding books, adding students, adding administrators, borrowing books, and querying books.

### 5. Products Class

This class handles operations related to the products in the library. It manages renting, returning, and querying products.

### 6. Bake Class

This class asks the user whether they want to continue with operations and continues or terminates the program based on the user's response.

## Files

The system uses two main files:

1. **books.txt**: Stores the titles and quantities of books.
2. **student.txt**: Stores the student IDs and passwords.

## How to Run

1. Clone the repository:
   ```sh
   git clone https://github.com/yourusername/library-management-system.git
   cd library-management-system
