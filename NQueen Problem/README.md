# NQueen-Problem (C++)
The N Queens problem entails the placement of N chess queens on a chessboard in a way that no two queens attack each other. There are many different algorithms for solving the N queen problem. In this project, the recursive backtracking algorithm was used.

## System Process Design

The recursive backtracking algorithm works by recursively placing the queen on the chessboard one by one, and constantly checking if they are safe from each other. If a queen is under attack, the algorithm backtracks to the previous queen and find a different position where the queen can be safe. This process will continue until all queens are safely placed on the chessboard without attacking each other.
This code enables user to input the number of queens, and will construct an NxN chessboard and print out all the solutions.


<img align="left" alt="image" src="https://github.com/user-attachments/assets/3a30a96f-4f95-4a22-82bd-9b53096247f5"> 
&nbsp; 
<img align="left" alt="image" src="https://github.com/user-attachments/assets/dd7a86b0-ea7a-4b26-a422-e88608b4c12a">

However, for certain values of ‘n’, there might not be a solution to the N Queens problem. When N= 1,2 or 3, there will be no solutions because there is no possible way to put two queens in a way they do not threaten each other. These are the smallest values of N for where no solution exists. To address this, the code above includes a check in the ‘main’ function to ensure that the input value of ‘n’ is valid according to the following the criteria: 

*	When n<=0, there are no solution and the code will print out an invalid input message
*	When n= 1,2,3, the code will return false and print out that there are no solutions to the n queen problem
*	When n=>4, the code will print out all possible solutions to the n queen problem
*	In addition, when n is not an integer or a whole number, the code will print out an invalid input message and ask user to input a whole number

<img align="left" alt="image" src="https://github.com/user-attachments/assets/9da442d4-4bd0-4b5f-8331-84cbf12c287e"> <br/>
