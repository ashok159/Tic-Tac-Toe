//Ashok Surujdeo
//Tic Tac Toe Game in C++ (using console)

#include <iostream>
#include <stdlib.h>
using namespace std;

//Creating a 2d array as the board
char grid[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

//Creating variables required
int choose;
int row;
int column;
char turn = 'X';
bool tie = false;

//Function that displays the current status of the board

void display_grid()
{
    cout << "PLAYER - 1 [X]       PLAYER - 2 [O]" << endl << endl;

    cout << "     |     |     " << endl;
    cout << "  " << grid[0][0] << "  |  " << grid[0][1] << "  |  " << grid[0][2] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << grid[1][0] << "  |  " << grid[1][1] << "  |  " << grid[1][2] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << grid[2][0] << "  |  " << grid[2][1] << "  |  " << grid[2][2] << endl;

    cout << "     |     |     " << endl << endl;
}

//Function to retrieve player input and update the board accordingly

void player_turn()
{
    if(turn == 'X'){
        cout << "Player - 1 [X] turn: ";
    }
    
    else if(turn == 'O'){
        cout << "Player - 2 [O] turn: ";
    }

    //Take input from the user
    //Update board with choice and reassigning the turn 
    cin >> choose;

    //Switch case that gets the row and column to be updated
    switch(choose){
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
        default:
            cout<<"Invalid Move";
    }

    if(turn == 'X' && grid[row][column] != 'X' && grid[row][column] != 'O'){
        //Updating the position for 'X' symbol if it is not already occupied
        grid[row][column] = 'X';
        turn = 'O';
    }
    else if(turn == 'O' && grid[row][column] != 'X' && grid[row][column] != 'O'){
        //Updating the position for 'O' symbol if it is not already occupied
        grid[row][column] = 'O';
        turn = 'X';
    }
    else{
        //If input position is already filled
        cout<<"Box already filled, Please choose another" << endl << endl;
        player_turn();
    }
}

//Function to retrieve the game status (Game Won, Game Draw, etc.)

bool end_game()
{
    //Checking the win for rows and columns
    for(int i = 0; i < 3; i++){
        if(grid[i][0] == grid[i][1] && grid[i][0] == grid[i][2] || grid[0][i] == grid[1][i] && grid[0][i] == grid[2][i])
            return false;
    }

    //Checking the win for both diagonals
    if(grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2] || grid[0][2] == grid[1][1] && grid[0][2] == grid[2][0])
        return false;
    
    //Checking if the game is in continue mode
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(grid[i][j] != 'X' && grid[i][j] != 'O')
                return true;
        }
    }

    //Checking if the game is already in a draw
    tie = true;
    return false;
}

//Main function for program
int main()
{
    cout << "\n\n\tTic Tac Toe\n\n";
    while(end_game()){
        display_grid();
        player_turn();
        end_game();
    }
    if(turn == 'X' && tie == false){
        cout << "Congratulations! Player with 'O' has won the game!" << endl << endl;
    }
    else if(turn == 'O' && tie == false){
        cout << "Congratulations! Player with 'X' has won the game!" << endl << endl;
    }
    else{
        cout << "Game Draw!" << endl << endl;
    }
}
