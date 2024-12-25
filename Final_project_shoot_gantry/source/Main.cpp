#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define DECK_SIZE 52
#define CARD_WIDTH 7
#define CARD_HEIGHT 5
#define SLEEP_TIME 50

long long final = 0; //紀錄最後輸贏的錢
const char* face[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "t", "J", "Q", "K" }; //定義牌的數值
const char* suit[] = { "H", "B", "C", "D" }; //定義牌的花色
const char* card_back[] = { //定義牌的背面
	"┌─────┐",
	"│─────│",
	"│─────│",
	"│─────│",
	"└─────┘" };

void clear_screen() {
	system("cls");
}

typedef struct card {
	const char* face;
	const char* suit;
	int value;
}Card;










void initializeDeck(Card deck[]) { // 初始化撲克牌
	
}

void shuffle(Card* const wDeck) { // 洗牌
	
}

/*-----rayyu-----*/
int rull(Card card1, Card card2, Card dragonCard, int bet, int big_or_small) { //判斷輸贏
	if () {

	}
}
/*---------------*/
int main() {
	srand(time(NULL));
	

	system("pause");
	return 0;
}