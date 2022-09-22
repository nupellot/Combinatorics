#include <stdio.h>

// Перечислить все 4-значные числа восьмеричные числа, в которых каждая следующая цифра больше предыдущей.

int main(void) {

	int amount = 0;
	
	for (int a = 1; a <= 4; a++) {
		for (int b = a + 1; b <= 5; b++) {
			for (int c = b + 1; c <= 6; c++) {
				for (int d = c + 1; d <= 7; d++) {
					amount++;
					printf("%2d: \033[42m%d%d%d%d\033[0m\n", amount, a, b, c, d);
				}
			}
		}
	}
 }