#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define DECK_SIZE 52
#define CARD_WIDTH 7
#define CARD_HEIGHT 5
#define SLEEP_TIME 50

long long final = 0; //�����̫��Ĺ����
const char* face[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "t", "J", "Q", "K" }; //�w�q�P���ƭ�
const char* suit[] = { "H", "B", "C", "D" }; //�w�q�P�����
const char* card_back[] = { //�w�q�P���I��
	"�z�w�w�w�w�w�{",
	"�x�w�w�w�w�w�x",
	"�x�w�w�w�w�w�x",
	"�x�w�w�w�w�w�x",
	"�|�w�w�w�w�w�}" };

void clear_screen() {
	system("cls");
}

typedef struct card {
	const char* face;
	const char* suit;
	int value;
}Card;










void initializeDeck(Card deck[]) { // ��l�Ƽ��J�P
	
}

void shuffle(Card* const wDeck) { // �~�P
	
}

/*-----rayyu-----*/
int rull(Card card1, Card card2, Card dragonCard, int bet, int big_or_small) { //�P�_��Ĺ
	if () {

	}
}
/*---------------*/
int main() {
	srand(time(NULL));
	

	system("pause");
	return 0;
}