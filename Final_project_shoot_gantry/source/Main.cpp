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
	if (card1.value != card2.value && card2.value != (card1.value + 1) && card2.value != (card1.value + 2)) {
		if (dragonCard.value > card1.value && dragonCard.value < card2.value) {
			printf("���ߡI���b�d�򤺡A�AĹ�F�I\n");
			printf("�A���^�F %d $�I\n\n", bet);
			final += bet;
		}
		else if (dragonCard.value == card1.value || dragonCard.value == card2.value) {
			printf("���W�I�A��F�I�ߨ⭿����\n");
			printf("�A�ߤF %d $�I\n", bet * 2);
			final -= bet * 2;
		}
		else {
			printf("�A��F�I�߿�\n");
			printf("�A�ߤF %d $�I\n\n", bet);
			final -= bet;
		}
	}
	else if (card1.value == card2.value) {
		if (big_or_small == 1) {
			if (dragonCard.value > card1.value) {
				printf("���ߡI�A�����F�I\n");
				printf("�A��o�F %d $�I\n\n", bet);
				final += bet;
			}
			else if (dragonCard.value < card1.value) {
				printf("�A��F�I�����O����\n");
				printf("�A�ߤF %d $�I\n\n", bet);
				final -= bet;
			}
			else {
				printf("���W�I�A��F�I�ߤT������\n");
				printf("�A�ߤF %d $�I\n\n", bet * 3);
				final -= bet * 3;
			}
		}
		else {
			if (dragonCard.value < card1.value) {
				printf("���ߡI�A�����F�I\n");
				printf("�A��o�F %d $�I\n\n", bet * 2);
				final += bet;
			}
			else if (dragonCard.value > card1.value) {
				printf("�A��F�I�����O����\n");
				printf("�A�ߤF %d $�I\n\n", bet);
				final -= bet;
			}
			else {
				printf("���W�I�A��F�I�ߤT������\n");
				printf("�A�ߤF %d $�I\n\n", bet * 3);
				final += bet * 3;
			}
		}
	}
	else if (card2.value == (card1.value + 1)) {
		if (dragonCard.value == card1.value || dragonCard.value == card2.value) {
			printf("���ߡI���W�IĹ�T������\n");
			printf("�A��o�F %d $�I\n\n", bet * 3);
			final += bet * 3;
		}
		else {
			printf("�i���S���I��ʰ�j��\n");
			printf("�A�ߤF %d $�I\n\n", bet);
			final -= bet;
		}
	}
	else {
		if (dragonCard.value > card1.value && dragonCard.value < card2.value) {
			printf("���ߡI���}�IĹ��������\n");
			printf("�A���^�F %d $�I\n\n", bet * 5);
			final += bet * 6;
		}
		else if (dragonCard.value == card1.value || dragonCard.value == card2.value) {
			printf("���W�I�A��F�I�ߨ⭿����\n");
			printf("�A�ߤF %d $�I\n\n", bet * 2);
			final -= bet * 2;
		}
		else {
			printf("�A��F�I�߿�\n");
			printf("�A�ߤF %d $�I\n\n", bet);
			final -= bet;
		}
	}

	int choise;
	printf("�٭n�~�򪱶ܡH(0�G���� 1�G�~��)");
	scanf("%d", &choise);
	return choise;
}
/*---------------*/
int main() {
	srand(time(NULL));
	

	system("pause");
	return 0;
}