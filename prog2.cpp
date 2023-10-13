// Name: Emilio Maset
// File Name: prog2.cpp
// Date: 2 October, 2023
// Program Description: Driver file for single-handed poker game
#include <iostream>
#include <fstream>
#include "Cards.h"

using namespace std;

int main(int argc, char* argv[]) {
    Cards *head = NULL;

    int numOfCardsInHand = 0;
    int numOfCardsDrew = 0;
    int totalNumOfCardsInDeck = 0; // value to see how many cards total are in the deck that we are drawing from

    ifstream inFile(argv[1]);
    fileValidityChecker(argc, inFile);

    totalNumOfCardsInDeck = findTotalNumOfCardsInDeck(inFile);


    while (numOfCardsDrew < totalNumOfCardsInDeck) { // keep playing while we have cards left to draw
        drawOneCard(head, inFile);
        numOfCardsDrew++;
        numOfCardsInHand++;
        cout << setw(2) << numOfCardsDrew << ": ";
        printList(head);


        while (numOfCardsInHand >= 4 &&
        (head->rank == head->next->next->next->rank || head->suit == head->next->next->next->suit) ) { // keep modifying the deck while there are matches
            modifyHand(head, numOfCardsInHand); // keep modifying the hand while there's a match
        } // end of inner while

    } // end of outer while
    return 0;
} // end of main