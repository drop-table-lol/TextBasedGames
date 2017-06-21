/*NIM -
the game is played by two parties. The stack starts at 21 and players
take anywhere from 1-3 off the stack. The player to remove the stack loses.
*/


#include <iostream>
using namespace std;


void printGreeting();
void playerTurn();
void computerTurn();
void endGame();

int theStack = 21;
bool isGameOver = false;
bool playerWon = true;

int main()
{

    printGreeting();
    while(!isGameOver)
    {
        cout << theStack << endl;
        playerTurn();
        cout << theStack << endl;
        computerTurn();
    }
    endGame();

}


void printGreeting()
{
    cout << "Hello and welcome to Nim. Both players may take 1-3 units off the stack. The last move which removes the stack loses." << endl;
    cout << "Good luck!" << endl;

}

void playerTurn()
{
    int choice;
    cout << "Take 1-3 pieces. )>>" ;
    cin >> choice;
    if(choice > 3 || choice < 1)
        cout << "Invalid choice. Turn lost." << endl;
    else
    {
        if (theStack - choice <= 0)
        {
            isGameOver = true;
            playerWon = false;
            return;
        }
        else
        {
            theStack = theStack - choice;
            return;
        }
    }
}

void computerTurn()
{
    if (isGameOver)
        return;
    if (theStack > 4)
    {
        theStack--;
        cout << "The computer chose 1" << endl;
    }
    else if (theStack == 4)
    {
        theStack = 1;
        cout << "The computer chose 3. " << endl;
    }
    else if (theStack == 3)
    {
        theStack = 1;
        cout << "The computer chose 2. " << endl;
    }
    else if (theStack == 2)
    {
        theStack = 1;
        cout << "The computer chose 1. " << endl;
    }
    else
    {
        cout << "Well played!" << endl;
        isGameOver = true;
        playerWon = true;
    }
}

void endGame()
{
    if (playerWon == true)
    {
        cout << "Good job player! You beat the Easy Al AI.";
    }

    if(playerWon == false)
    {
        cout << "Sorry man, you should bow to your overlord Easy Al AI.";
    }
}
