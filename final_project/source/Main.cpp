#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int display();
int shuffle();
int rull();


int main() {
	srand(time(NULL));
	

	
	system("pause");
	return 0;
}

int display() {

}

int shuffle() {

}

int rull(int low, int high, int playerGuess) {
    if (low > high) {
        // 確保 low 小於或等於 high
        int temp = low;
        low = high;
        high = temp;
    }

    // 判斷輸贏
    if (playerGuess >= low && playerGuess <= high) {
        return 1; // 玩家贏了
    }
    else {
        return 0; // 玩家輸了
    }
}

        