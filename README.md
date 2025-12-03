Flashcard Learning System in C
Overview

The Flashcard Learning System is a console-based project developed in the C programming language. It is designed to help users study and revise concepts by creating, storing, and reviewing flashcards. The system uses file handling techniques to save flashcard data for future access.

This project demonstrates the practical application of structures, file handling, user-defined functions, string handling, and random access logic in C programming.

Features

Add flashcards with a question and answer

View all stored flashcards

Quiz mode with random question generation

Search flashcards by keyword

Delete flashcards based on keywords

Persistent storage using a text file (flashcards.txt)

Technologies Used
Component	Description
Programming Language	C
Concepts Applied	File Handling, Structures, Functions, String Handling, Randomization
Data Storage	Text file
File Structure
Flashcard-Learning-System/
│
├── flashcard.h          # Header file containing declarations
├── flashcard.c          # Function definitions
├── main.c               # Main program file with menu and execution flow
├── flashcards.txt       # Data file created during runtime
└── README.md            # Project documentation

How to Compile and Run

Open the terminal inside the project folder.

Compile the program:

gcc main.c flashcard.c -o flashcard


Run the compiled program:

./flashcard

Sample Output
====== FLASHCARD LEARNING SYSTEM ======
1. Add Flashcard
2. View Flashcards
3. Quiz Mode
4. Search Flashcard
5. Delete Flashcard
6. Exit
Enter your choice:

Learning Outcomes

By completing this project, the following programming skills are demonstrated:

Working with file I/O in C (fopen, fprintf, fgets, remove, rename)

Implementing modular programming using header files

Creating and using custom data structures

Handling strings and user input safely

Using randomization functions (rand() and srand())

Future Improvements

Edit flashcard functionality

Timer-based quiz mode

Difficulty-based categorization

Export flashcards to PDF or CSV

Graphical user interface version using external libraries
