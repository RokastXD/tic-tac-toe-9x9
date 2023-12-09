#include <iostream>
#include <string>
using namespace std;

char square[9] = {'1', '2', '3' , '4' , '5' , '6' , '7' , '8' , '9' };
char squareMatrix[9][9];

int checkWin(int matrix);
int checkSquare(int matrix);
void fillSquare(int matrix, int choice, char playerMark);
void board();

int main()
{
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            squareMatrix[i-1][j-1] = j + 48;
            cout << squareMatrix[i - 1][j - 1];
        }
    }
	int player = 1,game,choice, matrix;

    char mark;
    do
    {
        board();
        cout << "!" << endl;
        
        player=(player%2)?1:2;
        cout << "Player " << player << ", enter a number of matrix:  ";
        cin >> matrix;
        cout << "Player " << player << ", enter a number of cell:  ";
        cin >> choice;
        matrix -= 1; choice -= 1;
        mark=(player == 1) ? 'X' : 'O';
        

        if (0 <= choice && choice <= 8 && 0 <= matrix && matrix <= 8 && (squareMatrix[matrix][choice] != 'X' && squareMatrix[matrix][choice] != 'O')) {
            squareMatrix[matrix][choice] = mark;
            if (checkSquare(matrix) == 1)
                fillSquare(matrix, choice, mark);
        }
        else
        {
            
            cout<<"Invalid move ";

            player--;
            cin.ignore();
            cin.get();
        }

        

        game=checkWin(matrix);

        player++;
    }while(game==-1);
    board();
    if(game==1)

        cout<<"==>\aPlayer "<<--player<<" win ";
    else
    {
        cout<<"==>\aGame draw";
    }

    cin.ignore();
    cin.get();
    return 0;
}



void fillSquare(int matrix, int choice, char playerMark) {
    for (int i = 0; i < 9; i++) {
        squareMatrix[matrix][i] = playerMark;
        square[matrix] = playerMark;
    }
}

/*********************************************
    FUNCTION TO RETURN CELL STATUS
    1 FOR CELL IS OVER WITH RESULT
    -1 FOR CELL IS IN PROGRESS
    O CELL IS OVER AND NO RESULT
**********************************************/

int checkSquare(int matrix) {
    if (squareMatrix[matrix][0] == squareMatrix[matrix][1] && squareMatrix[matrix][1] == squareMatrix[matrix][2])

        return 1;
    else if (squareMatrix[matrix][3] == squareMatrix[matrix][4] && squareMatrix[matrix][4] == squareMatrix[matrix][5])

        return 1;
    else if (squareMatrix[matrix][6] == squareMatrix[matrix][7] && squareMatrix[matrix][7] == squareMatrix[matrix][8])

        return 1;
    else if (squareMatrix[matrix][0] == squareMatrix[matrix][3] && squareMatrix[matrix][3] == squareMatrix[matrix][6])

        return 1;
    else if (squareMatrix[matrix][1] == squareMatrix[matrix][4] && squareMatrix[matrix][4] == squareMatrix[matrix][7])

        return 1;
    else if (squareMatrix[matrix][2] == squareMatrix[matrix][5] && squareMatrix[matrix][5] == squareMatrix[matrix][8])

        return 1;
    else if (squareMatrix[matrix][0] == squareMatrix[matrix][4] && squareMatrix[matrix][4] == squareMatrix[matrix][8])

        return 1;
    else if (squareMatrix[matrix][2] == squareMatrix[matrix][4] && squareMatrix[matrix][4] == squareMatrix[matrix][6])

        return 1;
    else if (squareMatrix[matrix][0] != '1' && squareMatrix[matrix][1] != '2' && squareMatrix[matrix][2] != '3'
        && squareMatrix[matrix][3] != '4' && squareMatrix[matrix][4] != '5' && squareMatrix[matrix][5] != '6'
        && squareMatrix[matrix][6] != '7' && squareMatrix[matrix][7] != '8' && squareMatrix[matrix][8] != '9')

        return 0;
    else
        return -1;
}

/*********************************************
    FUNCTION TO RETURN GAME STATUS
    1 FOR GAME IS OVER WITH RESULT
    -1 FOR GAME IS IN PROGRESS
    O GAME IS OVER AND NO RESULT
**********************************************/

int checkWin(int matrix)
{
 
    if (square[0] == square[1] && square[1] == square[2])

        return 1;
    else if (square[3] == square[4] && square[4] == square[5])

        return 1;
    else if (square[6] == square[7] && square[7] == square[8])

        return 1;
    else if (square[0] == square[3] && square[3] == square[6])

        return 1;
    else if (square[1] == square[4] && square[4] == square[7])

        return 1;
    else if (square[2] == square[5] && square[5] == square[8])

        return 1;
    else if (square[0] == square[4] && square[4] == square[8])

        return 1;
    else if (square[2] == square[4] && square[4] == square[6])

        return 1;
    else if (square[0] != '1' && square[1] != '2' && square[2] != '3'
        && square[3] != '4' && square[4] != '5' && square[5] != '6'
        && square[6] != '7' && square[7] != '8' && square[8] != '9')

        return 0;
    else
        return -1;

}


/*******************************************************************
     FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
********************************************************************/


void board()
{
    system("cls");
    cout << "\n\n\tTic Tac Toe\n\n";

    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;

    for (int i = 0; i <= 2; i++) {
        int matrixK = i * 3;
        for (int line = 0; line <= 2; line++) {
            int numK = line * 3;
            cout << " ";
            for (int j = 0; j <= 2; j++) {
                for (int k = 0; k <= 2; k++) {
                    cout << squareMatrix[j + matrixK][k + numK];
                    if (j == 2 && k == 2) break;
                    cout << " | ";
                }
            }
            cout << endl;
            for (int m = 0; m < 8; m++) {
                cout << "___|";
            }
            cout << "___" << endl;
        }
    }
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << square[0] << "  |  " << square[1] << "  |  " << square[2] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[3] << "  |  " << square[4] << "  |  " << square[5] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[6] << "  |  " << square[7] << "  |  " << square[8] << endl;

    cout << "     |     |     " << endl << endl;
}