// Name: Emilio Maset
// File Name: Cards.h
// Date: 2 October, 2023
// Program Description: Header file containing structure definition and function prototypes
using namespace std;

struct Cards {
    int rank;
    char suit;
    Cards* next;
};

void fileValidityChecker(int argc, ifstream &inFile);
int findTotalNumOfCardsInDeck (ifstream &inFile);
void drawOneCard(Cards* &head, ifstream &inFile); // passing the head by reference so we can modify the linked list in the methods
void removeCards1Thru4 (Cards* &head);
void removeCards2And3(Cards* &head);
void modifyHand(Cards* &head, int &numOfCardsInHand);
void printList(Cards* &head);
