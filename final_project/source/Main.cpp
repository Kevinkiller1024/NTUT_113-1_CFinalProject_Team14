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

int rull();

struct card {
	const char* face;
	const char* suit;
	int value;
};
typedef struct card Card;

Card drawCard(Card deck[], int* deckIndex) { //抽一張牌
	if (*deckIndex >= DECK_SIZE) {
		printf("\n牌已經抽完了！\n");
		exit(1);
	}
	return deck[(*deckIndex)++];
}

void display_two_card(const char* face1, const char* suit1, const char* face2, const char* suit2) {
	printf("┌─────┐\t\t┌─────┐\n");
	printf("│%s    │\t\t│%s    │\n", suit1, suit2);
	printf("│  %s  │\t\t│  %s  │\n", face1, face2);
	printf("│    %s│\t\t│    %s│\n", suit1, suit2);
	printf("└─────┘\t\t└─────┘\n\n");
}

void card_front(const char* face, const char* suit, int show) {
	switch (show) {
	case 4:
		printf("\t┌─────┐\n");
	case 3:
		printf("\t│%s    │\n", suit);
	case 2:
		printf("\t│  %s  │\n", face);
	case 1:
		printf("\t│    %s│\n", suit);
	case 0:
		printf("\t└─────┘\n");
	}
}

void draw_card(const char* card[], int y, const char* face1, const char* suit1, const char* face2, const char* suit2) {   // 顯示撲克牌在指定位置
	clear_screen();
	display_two_card(face1, suit1, face2, suit2);
	for (int i = 0; i < y; i++) {
		printf("\n");
	}
	for (int i = 0; i < CARD_HEIGHT; i++) {
		printf("\t%s\n", card[i]);
	}
}

void card_fly_and_flip(int start_y, const char* face, const char* suit, const char* face1, const char* suit1, const char* face2, const char* suit2) {
	for (int y = start_y; y >= CARD_HEIGHT; y--) {
		draw_card(card_back, y, face1, suit1, face2, suit2);
		Sleep(SLEEP_TIME);
	}
	for (int step = 0; step < CARD_HEIGHT; step++) {
		for (int i = 0; i < CARD_HEIGHT; i++) {
			printf("\n");
		}
		for (int j = 0; j < CARD_HEIGHT; j++) {
			clear_screen();
			display_two_card(face1, suit1, face2, suit2);
			card_front(face, suit, step);
		}
		Sleep(SLEEP_TIME / 5);
	}
}

void initializeDeck(Card deck[]) { // 初始化撲克牌
	int index = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			deck[index].face = (char*)face[j];
			deck[index].suit = (char*)suit[i];
			deck[index].value = j + 1;
			index++;
		}
	}
}

void shuffle(Card* const wDeck) { // 洗牌
	int i;
	int j;
	Card temp;

	for (i = 0; i < DECK_SIZE; i++) {
		j = rand() % DECK_SIZE;
		temp = wDeck[i];
		wDeck[i] = wDeck[j];
		wDeck[j] = temp;
	}
}

int rull() {
	return 1;
}

int main() {
	srand(time(NULL));
	Card deck[DECK_SIZE];
	int deckIndex = 0;
	int choise, count = 0;

	do {
		clear_screen();
		printf("歡迎來到射龍門遊戲！\n\n");

		initializeDeck(deck);
		shuffle(deck);
		Card card1 = drawCard(deck, &deckIndex);
		Card card2 = drawCard(deck, &deckIndex);

		if (card1.value > card2.value) {
			Card temp = card1;
			card1 = card2;
			card2 = temp;
		}
		display_two_card(card1.face, card1.suit, card2.face, card2.suit);

		int play_or_fault = 0;
		int bet;
		while (play_or_fault == 0) {
			printf("要玩還是棄牌(0棄牌，1下注)：");
			scanf("%d", &play_or_fault);
			if (play_or_fault == 1)
				break;
			card1 = drawCard(deck, &deckIndex);
			card2 = drawCard(deck, &deckIndex);
			if (card1.value > card2.value) {
				Card temp = card1;
				card1 = card2;
				card2 = temp;
			}
			clear_screen();
			display_two_card(card1.face, card1.suit, card2.face, card2.suit);
		}
		int big_or_small;
		if (card1.value == card2.value) {
			printf("你要押大還是押小(0押小，1押大)：");
			scanf("%d", &big_or_small);
		}
		printf("請下注金額：");
		scanf("%d", &bet);

		Card dragonCard = drawCard(deck, &deckIndex);
		card_fly_and_flip(20, dragonCard.face, dragonCard.suit, card1.face, card1.suit, card2.face, card2.suit);
		printf("龍門牌是：%s %s\n\n", dragonCard.face, dragonCard.suit);

		rull();

		printf("還要繼續玩嗎？(0：結束 1：繼續)");
		scanf("%d", &choise);
	} while (choise);
	printf("\n感謝遊玩! \n你一共射了%d次\n", count);
	if (final > 0)
		printf("你一共贏了%ld $\n\n", final);
	else if (final < 0)
		printf("一共賠了%d $ 笑死\n\n", -final);
	else
		printf("你一毛沒贏\n\n");
	system("pause");
	return 0;
}