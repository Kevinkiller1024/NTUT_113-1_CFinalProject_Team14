#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display(Card* const wDeck, const char* wFace[], const char* wSuit[]);
void shuffle(Card* const wDeck);
void dealTwoCards(const Card* const wDeck)
int rull();

void dealTwoCards(const Card* const wDeck)
struct card {
	const char* face;
	const char* suit;
};

typedef struct card Card;

int main() {
	srand(time(NULL));
	

	
	system("pause");
	return 0;
}

void display(Card* const wDeck, const char* wFace[], const char* wSuit[]) 
{
	int i;

	for (i = 0; i <= 51; i++) {
		wDeck[i].face = wFace[i % 13];  // 根據索引計算點數
		wDeck[i].suit = wSuit[i / 13];  // 根據索引計算花色
	}
}

void shuffle(Card *const wDeck)
{
	int i;
	int j;
	Card temp;

	for (i = 0;i <= 51;i++) {
		j = rand() % 52;
		temp = wDeck[i];
		wDeck[i] = wDeck[j];
		wDeck[j] = temp;
	}
}
int rull() {

}
void dealTwoCards(const Card* const wDeck)
{
	int index1 = rand() % 52;
	int index2 = rand() % 52;

	while (index2 == index1) { // 確保兩張牌不同
		index2 = rand() % 52;
	}
}
