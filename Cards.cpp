// Name: Emilio Maset
// File Name: Cards.cpp
// Date: 2 October, 2023
// Program Description: Cards.cpp holding function definitions

#include <iostream>
#include <fstream>
#include "Cards.h"

void fileValidityChecker(int argc, ifstream &inFile) {
    if (argc == 1) { // if argc equals one, that means only the source file name was entered and not a text file as well
        cout << "No file name entered";
        exit(0);
    }

    if (!inFile) {
        cout << "File not found";
        exit(0);
    }

}

//============================================================================================================================================================

int findTotalNumOfCardsInDeck (ifstream &inFile) {
    int count = 0;

    string temp;
    while (getline(inFile, temp)) // while lines are read in from the file, increment count in order to track how many cards are in the deck
        count++;

    inFile.clear();
    inFile.seekg(ios::beg); // reset file read position to the beginning

    return count;
}

//============================================================================================================================================================

void drawOneCard(Cards* &head, ifstream &inFile) {
    Cards* pnew = NULL;
    string oneLineOfFile;
    getline(inFile, oneLineOfFile); // read in a line from the file and store it

   if (!(oneLineOfFile.empty())) { // makes sure line that we read in is not empty
       pnew = new Cards;
       pnew->rank = atoi(oneLineOfFile.c_str()); // parses int value from string for the rank

       if (atoi(oneLineOfFile.c_str()) == 0) { // if there is no int in the string, that means the card is a Jack, Queen, Kind, or Ace
            switch (oneLineOfFile.at(0)) { // gets rank based on J, Q, K, or A
                case 'J':
                    pnew->rank = 11;
                    break;
                case 'Q':
                    pnew->rank = 12;
                    break;
                case 'K':
                    pnew->rank = 13;
                    break;
                case 'A':
                    pnew->rank = 14;
                    break;
            } // end of switch
        }

        if (oneLineOfFile.length() - 1 == 2) // Finds suit of card based on length of string. This is really only needed when the rank is 10
                                             // - 1 to ignore new line characters
            pnew->suit = oneLineOfFile.at(1);
        else if(oneLineOfFile.length() - 1  == 3)
            pnew->suit = oneLineOfFile.at(2);
    }

   if (head == NULL) { // condition for if this is the first card we are adding to our hand
       head = pnew;
   }

   else { // if we have at least one card in our hand, this is used to insert the card at the beginning of the linked list
       pnew->next = head; // make new card node point to "first" card in deck
       head = pnew; // make head point to new first card node
       pnew = NULL;
   }
}

//============================================================================================================================================================

void removeCards1Thru4 (Cards* &head) {
    Cards* temp = NULL;
    for (int i = 1; i <= 4; i++) {
        temp = head; // pointer to point to first card
        head = head->next; // make head point to second card
        delete temp;  // delete first card, and now the second card is the first card
    }
}

//============================================================================================================================================================

void removeCards2And3(Cards* &head) {
    Cards* temp = NULL;

    for (int i = 1; i <= 2; i++) {
        temp = head->next; // pointer to point to second card
        head->next = head->next->next; // make head point to third card
        delete temp; // delete second card, and now third card is the second card
    }
}

//============================================================================================================================================================

void modifyHand(Cards* &head, int &numOfCardsInHand) {

    if (numOfCardsInHand >= 4 && head->rank == head->next->next->next->rank) { // if the first card's rank matches the fourth's card's rank,
                                                                               // delete the first - fourth inclusive cards
        removeCards1Thru4(head);
        numOfCardsInHand -= 4;
        cout << "    "; // just for formatting
        printList(head);
    }

    if (numOfCardsInHand >= 4 && head->suit == head->next->next->next->suit) { // if the first card's suit matches the fourth's card's suit,
                                                                               // delete the second and third cards (nodes)
        removeCards2And3(head);
        numOfCardsInHand -= 2;
        cout << "    "; // just for formatting
        printList(head);
    }
}

//============================================================================================================================================================

void printList(Cards* &head) {
    Cards* walker = head;
    while (walker!= NULL) { // while loop to traverse linked list
        if (walker->rank == 11) // if statements just for formatting
            cout << "J" << walker->suit << " ";

        else if (walker->rank == 12)
            cout << "Q" << walker->suit << " ";

        else if (walker->rank == 13)
            cout << "K" << walker->suit << " ";

        else if (walker->rank == 14)
            cout << "A" << walker->suit << " ";

        else // if ranks are not J, Q, K, or A, just print the rank and suit normally
            cout  << walker->rank << walker->suit << " ";

        walker = walker->next;
    }
    cout << endl;
}

//============================================================================================================================================================
