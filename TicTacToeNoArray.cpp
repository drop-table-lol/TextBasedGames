/*Super simple Tic-tac-toe
* Currently there is no AI, the computer just chooses at random
* Author: John Snevily 2017
* Feel free to modify, comment, tear apart, etc.
*/


#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;


/*__TODO__
- Make 9 positions into 2d array? (This is currently for a teaching example
- Give the AI levels. Level 1 is random, level 2 picks middle, level 3 picks corners
*/

//Global Positions
char top_left = '1';
char top_center = '2';
char top_right = '3';
char middle_left = '4';
char middle_center = '5';
char middle_right = '6';
char bottom_left = '7';
char bottom_center = '8';
char bottom_right = '9';

/*Global Ints */
int player_turn = 1;
int choice = -1;
int total_turns;

/*Global Bools */
bool is_done = false;




//Declare Functions
void printBoard();
void getChoice();
bool checkMove(int);
void changeTile(int);
void checkWin();


int main()
{
    //Initializations
    srand(time(NULL));

    cout << "Welcome to simple Tic-Tac_Toe, featuring Easy Al's AI." << endl;
    cout << "In this version, the player goes first, and the AI chooses a random location." << endl;
    cout << "Good Luck!" << endl;

    while(!is_done && total_turns < 9)
    {
        printBoard();
        getChoice();
        checkWin();
        total_turns++;
    }

    cout << "Thanks for playing!" << endl;




    return 0;
}



void printBoard()
{
    cout << "|" << top_left << "|" << top_center << "|" << top_right <<"|" << endl;
    cout << "|" << middle_left << "|" << middle_center << "|" << middle_right <<"|" << endl;
    cout << "|" << bottom_left << "|" << bottom_center << "|" << bottom_right << "|" << endl;
}


bool checkMove(int choice)
{
    switch(choice)
    {
        case(1):
            if (top_left == '1')
            {
                changeTile(1);
                return true;
            }
            else
            {
                return false;
            }
        case(2):
            if (top_center == '2')
            {
                changeTile(2);
                return true;
            }
            else
            {
                return false;
            }
        case(3):
            if (top_right == '3')
            {
                changeTile(3);
                return true;
            }
            else
            {
                return false;
            }
        case(4):
            if (middle_left == '4')
            {
                changeTile(4);
                return true;
            }
            else
            {
                return false;
            }
        case(5):
            if (middle_center == '5')
            {
                changeTile(5);
                return true;
            }
            else
            {
                return false;
            }
        case(6):
            if (middle_right == '6')
            {
                changeTile(6);
                return true;
            }
            else
            {
                return false;
            }
        case(7):
            if (bottom_left == '7')
            {
                changeTile(7);
                return true;
            }
            else
            {
                return false;
            }
        case(8):
            if (bottom_center == '8')
            {
                changeTile(8);
                return true;
            }
            else
            {
                return false;
            }
        case(9):
            if (bottom_right == '9')
            {
                changeTile(9);

            }
            else
            {
                return false;
            }
        default:
            if (player_turn == 1) //Only notify if the player makes an illegal choice
            {
                cout << "That choice is invalid. Please choose an empty (numbered) square." << endl;
                return false;
            }
    }
    return true;


}



void changeTile(int tile)
{
    if (player_turn == 0) //Computer turn O
    {
        switch(tile)
        {
            case(1):
                if (top_left == '1')
                {
                    top_left = 'O';
                    break;
                }
            case(2):
                if (top_center == '2')
                {
                    top_center = 'O';
                    break;
                }
            case(3):
                if (top_right == '3')
                {
                    top_right = 'O';
                    break;
                }
            case(4):
                if (middle_left == '4')
                {
                    middle_left = 'O';
                    break;
                }
            case(5):
                if (middle_center == '5')
                {
                    middle_center = 'O';
                    break;
                }
            case(6):
                if (middle_right == '6')
                {
                    middle_right = 'O';
                    break;
                }
            case(7):
                if (bottom_left == '7')
                {
                    bottom_left = 'O';
                    break;
                }
            case(8):
                if (bottom_center == '8')
                {
                    bottom_center = 'O';
                    break;
                }
            case(9):
                if (bottom_right == '9')
                {
                    bottom_right = 'O';
                    break;
                }
        }
    }
    else if (player_turn == 1) //Player turn X
        {
        switch(tile)
        {
            case(1):
                if (top_left == '1')
                {
                    top_left = 'X';
                    break;
                }
            case(2):
                if (top_center == '2')
                {
                    top_center = 'X';
                    break;
                }
            case(3):
                if (top_right == '3')
                {
                    top_right = 'X';
                    break;
                }
            case(4):
                if (middle_left == '4')
                {
                    middle_left = 'X';
                    break;
                }
            case(5):
                if (middle_center == '5')
                {
                    middle_center = 'X';
                    break;
                }
            case(6):
                if (middle_right == '6')
                {
                    middle_right = 'X';
                    break;
                }
            case(7):
                if (bottom_left == '7')
                {
                    bottom_left = 'X';
                    break;
                }
            case(8):
                if (bottom_center == '8')
                {
                    bottom_center = 'X';
                    break;
                }
            case(9):
                if (bottom_right == '9')
                {
                    bottom_right = 'X';
                    break;
                }
        }
    }
}


void getChoice()
{
    if (player_turn == 1) //Player
    {
        cout << "Choose a place on the board, 1-9" << endl;
        cout << "Your turn >> ";
        cin >> choice;
        if (checkMove(choice) == false)
        {
            getChoice();
        }
        player_turn = 0;
        return;
    }

    if (player_turn == 0)
    {
        do
        {
            //cout << "AI's Turn" << endl;
            choice = rand() % 9 + 1; //get a random number between 1 and 9, checking it's legaltiy. The computer is currently stupid.
        }
        while (checkMove(choice) == false);
        cout << "Computer chose " << choice << endl;
        player_turn = 1;
        return;
    }
}


void checkWin()
{
    string p1 = "Human!";
    string p2 = "Your new AI overlord!";
    bool won = false;
    //Across the top
    if (top_left == top_center && top_center == top_right)
    {
        won = true;
    }
    //Across the middle
    if (middle_left == middle_center && middle_center == middle_right)
    {
        won = true;
    }
    //Across the bottom
    if (bottom_left == bottom_center && bottom_center == bottom_right)
    {
        won = true;
    }

    //Down the left
    if (top_left == middle_left && middle_left == bottom_left)
    {
        won = true;
    }
    //Down the center
    if (top_center == middle_center && middle_center == bottom_center)
    {
        won = true;
    }
    //Down the right
    if (top_right == middle_right && middle_right == bottom_right)
    {
        won = true;
    }

    //Diagonal
    if (top_right == middle_center && middle_center == bottom_left)
        won = true;
    if (top_left == middle_center && middle_center == bottom_right)
        won = true;


    if (won == true)
    {
        is_done = true;
        if (player_turn == 0) //Human Won
        {
            cout << "Player triumphs over the computer!" << endl;
        }
        else
        {
            cout << "Player should bow to your new AI overlord!" << endl;
        }
        printBoard();
    }
}


