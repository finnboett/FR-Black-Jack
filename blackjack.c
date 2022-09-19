#include "blackjacklib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
    srand(time(NULL));
    stack_t *stack = generateStack();
    table_t *table = generateTable(stack);
    handOpenCardDealer(table);
    handOpenCardDealer(table);
    handOpenCardPlayer(table);
    handOpenCardPlayer(table);
    drawTable(table);

    unsigned char running = 1;
    while(running){
        printf("hit(h) or stand(s)\n");
        char c = getc(stdin);
        switch (c)
        {
        case 'h':
            handOpenCardPlayer(table);
            drawTable(table);
            break;
        case 's':
            running = 0;
            break;
        default:
            break;
        }
    }
    if (getValue(table->player) > 21) {
        printf("lose(player over 21)\n");
        exit(0);
    }
    while (getValue(table->dealer) < 21) {
        handOpenCardDealer(table);
        drawTable(table);
    }
    if (getValue(table->dealer) > 21) {
        printf("win (dealer over 21)\n");
    } else {
        printf("lose (dealer over player)");
    }
}