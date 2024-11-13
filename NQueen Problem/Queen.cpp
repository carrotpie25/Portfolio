#include <iostream>
#include <vector>
#include <string>

using namespace std;

int const queen = 1;

// Make the chess board
// The size of the board follows the number of input 
void printBoard(vector<vector<int>>& chessBoard) {
    for (int i = 0; i < chessBoard.size(); i++) {
        for (int j = 0; j < chessBoard.size(); j++) {
            cout << chessBoard[i][j] << " ";
        }
        cout << endl;
    }
}

bool validPosition(vector<vector<int>>& chessBoard, int row, int col) {
    // Check column
    for (int i = 0; i < chessBoard.size(); i++) {
        if (chessBoard[i][col] == 1) {
            return false;
        }
    }

    // Check diagonal to upper left
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (chessBoard[i][j] == 1) {
            return false;
        }
    }

    // Check diagonal to upper right
    for (int i = row - 1, j = col + 1; i >= 0 && j < chessBoard.size(); i--, j++) {
        if (chessBoard[i][j] == 1) {
            return false;
        }
    }
    return true;
}

bool findQueensSolutions(vector<vector<int>>& chessBoard, int row, int& totalSolution) {
    if (row == chessBoard.size()) {
        // Solution founded!
        totalSolution++;
        printBoard(chessBoard);
        cout << endl;
        return true;
    }
    // Recursive: Try to place a queen at each column of the current row
    for (int col = 0; col < chessBoard.size(); col++) {
        if (validPosition(chessBoard, row, col)) {
            chessBoard[row][col] = 1; 
            // Place queen at current position
            if (findQueensSolutions(chessBoard, row + 1, totalSolution)); { // Recursively solve the problem for the next row
                chessBoard[row][col] = 0; // Backtrack and remove the last added queen
            }
        }
    }
    return false; // No solution found at this level

}

bool isWholeNumber(const string& str) { // Check if input is a whole number
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

int main() {
    string input;
    cout << "Please input the number of desired queens:" << endl;

    if (!(cin >> input) || !isWholeNumber(input)) { // If input is not a whole number
        cout << "Invalid input! n must be a positive whole number" << endl;
    }
    else {
        int n = stoi(input); // Convert string into integer

        if (n <= 0) {
            cout << "Invalid input! n must be a positive whole number" << endl;
        }
        else if (n < 4) {
            cout << "There are no solutions to the " << n << "-Queen problem" << endl;
        }
        else {  //(n >= 4)
            vector<vector<int>> chessBoard(n, vector<int>(n, 0));
            int totalSolution = 0; // Count all the possible solutions to the problem

            findQueensSolutions(chessBoard, 0, totalSolution);
            cout << "There are " << totalSolution << " possible solutions to the " << n << "-Queens problem." << endl;
        }
        
    }
    return 0;
}
