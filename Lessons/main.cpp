#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

#include "Card.h"

using namespace std;

void printCard(Card c) {
  cout << c.getWord() << endl;
  cout << c.getDefinition() << endl;
  cout << c.getExample() << endl;
  cout << c.getHint() << endl;
}

void printHint(Card c) {
  cout << "Hint: " << c.getHint() << endl;
}

void printExample(Card c) {
  cout << "Example: " << c.getExample() << endl;
}



void testDefinition(Card c, vector<Card> deck, int pos) {
  int correct_choice = rand() % 4;
  correct_choice++;
  int rnd1, rnd2, rnd3;
  rnd1 = rand() % deck.size();
  while (rnd1 == pos) {rnd1 = rand() % deck.size();}
  rnd2 = rand() % deck.size();
  while(rnd2 == rnd1 || rnd2 == pos) {rnd2 = rand() % deck.size();}
  rnd3 = rand() % deck.size();
  while(rnd3 == rnd1 || rnd3 == rnd2 || rnd3 == pos) {rnd3 = rand() % deck.size();}
  int choice = 0;
  if (correct_choice == 1) {
    cout <<"Word is: " <<  c.getWord() << endl;
    cout << "---------------------------------------" << endl;
    cout << "Which of the following is most correct?" << endl;
    cout << "1 " << c.getDefinition() << endl;
    cout << "2 " << deck.at(rnd1).getDefinition() << endl;
    cout << "3 " << deck.at(rnd2).getDefinition() << endl;
    cout << "4 " << deck.at(rnd3).getDefinition() << endl;
    cout << "5 - Hint" << endl;
    cout << "6 - Usage" << endl;
    cin >> choice;
    while(choice != 1) {
      cout << "Hmm, that's not quite right, try again..." << endl;
      cin >> choice;
    }
    if (choice == 1) {
      cout << "That's right! Moving on..." << endl;
    }
  }
    if (correct_choice == 2) {
    cout <<"Word is: " <<  c.getWord() << endl;
    cout << "---------------------------------------" << endl;
    cout << "Which of the following is most correct?" << endl;
    cout << "1 " << deck.at(rnd1).getDefinition() << endl;
    cout << "2 " << c.getDefinition() << endl;
    cout << "3 " << deck.at(rnd2).getDefinition() << endl;
    cout << "4 " << deck.at(rnd3).getDefinition() << endl;
    cout << "5 - Hint" << endl;
    cout << "6 - Usage" << endl;
    cin >> choice;
    while(choice != 2) {
      cout << "Hmm, that's not quite right, try again..." << endl;
      cin >> choice;
    }
    if (choice == 2) {
      cout << "That's right! Moving on..." << endl;
    }
  }
      if (correct_choice == 3) {
    cout <<"Word is: " <<  c.getWord() << endl;
    cout << "---------------------------------------" << endl;
    cout << "Which of the following is most correct?" << endl;
    cout << "1 " << deck.at(rnd1).getDefinition() << endl;
    cout << "2 " << deck.at(rnd2).getDefinition() << endl;
    cout << "3 " << c.getDefinition() << endl;
    cout << "4 " << deck.at(rnd3).getDefinition() << endl;
    cout << "5 - Hint" << endl;
    cout << "6 - Usage" << endl;
    cin >> choice;
    while(choice != 3) {
      cout << "Hmm, that's not quite right, try again..." << endl;
      cin >> choice;
    }
    if (choice == 3) {
      cout << "That's right! Moving on..." << endl;
    }
  }
      if (correct_choice == 4) {
    cout <<"Word is: " <<  c.getWord() << endl;
    cout << "---------------------------------------" << endl;
    cout << "Which of the following is most correct?" << endl;
    cout << "1 " << deck.at(rnd1).getDefinition() << endl;
    cout << "2 " << deck.at(rnd2).getDefinition() << endl;
    cout << "3 " << deck.at(rnd3).getDefinition() << endl;
    cout << "4 " << c.getDefinition() << endl;
    cout << "5 - Hint" << endl;
    cout << "6 - Usage" << endl;
    cin >> choice;
    while(choice != 4) {
      cout << "Hmm, that's not quite right, try again..." << endl;
      cin >> choice;
    }
    if (choice == 4) {
      cout << "That's right! Moving on..." << endl;
    }
  }

}

int main() {
  /*begin initialization logic*/
  fstream myfile;
  string line;
  string w, d, h, e;
  string temp;
  bool card_found = false;
  vector<Card> deck;
  srand(time(NULL));


  myfile.open("flashcards.txt");
  if (myfile.is_open()) {
    while (getline(myfile, line)) {
      if (line[0] == 'w') {
          w = line.substr(3);
      }
      else if (line[0] == 'd') {
        d = line.substr(3);
      }
      else if (line[0] == 'h') {
        h = line.substr(3);
      }
      else if (line[0] == 'e') {
        e = line.substr(3);
        card_found = true;
      }
      if (card_found) {
          Card temp = Card(w, d, h, e);
          deck.push_back(temp);
          card_found = false;
      }
      //cout << line << endl;
    }
  }
  else {
    cout << "Couldn't find flashcards.txt" << endl;
  }
  /*end initialization logic*/

  /*begin test logic*/
  //for_each (deck.begin(), deck.end(), printCard);
  for (int i=0; i<deck.size(); i++) {
    //printCard(deck.at(i));
    testDefinition(deck.at(i), deck, i);
    cout << "\n\n\n\n\n";
  }
  cout << "Congrats! You made it through!" << endl;
}
