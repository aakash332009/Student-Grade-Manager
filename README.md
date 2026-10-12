# Student Grade Manager (C)

A beginner-friendly command-line project written in **C**. It helps you practice student records using structures, arrays, functions, loops, and `switch` statements.

## Features

- Add student roll numbers, names, and marks (0–100)
- View all student records
- Search for a student by roll number
- Calculate the class average
- Prevent duplicate roll numbers

## Requirements

- A C compiler such as GCC
- A terminal or command prompt

## How to run

1. Download or clone this repository.
2. Open a terminal inside the project folder.
3. Compile the program:

   ```bash
   gcc main.c -o student_manager
   ```

4. Run it:

   **Windows (Command Prompt / PowerShell):**
   ```powershell
   .\student_manager.exe
   ```

   **Linux / macOS:**
   ```bash
   ./student_manager
   ```

## Sample output

```text
=== Student Grade Manager ===
1. Add student
2. View all students
3. Search by roll number
4. Show class average
5. Exit
Choose an option: 1
Enter roll number: 101
Enter student name: Priya
Enter mark (0-100): 88
Student added successfully!
```

## Concepts used

- `struct` for student information
- Arrays to store up to 100 students
- Functions to organize the program
- `for` loops and `if` conditions
- `switch` for menu selection
- `scanf` and `printf` for input/output

## Limitations

- Records are stored **only while the program is running**. They are not saved to a file.
- The program is intended for basic numeric menu input; invalid text input exits the program.

## Possible improvements

- Save records to a file
- Edit and delete records
- Add grades (A, B, C, etc.)
- Improve input validation

## License

This project is provided as a learning example. You can modify and extend it.
