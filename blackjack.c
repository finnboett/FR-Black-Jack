#include "blackjacklib.h"

void main() {
    stack_t *stack = generateStack();
    table_t *table = generateTable(stack);
    handOpenCardDealer(table);
    handOpenCardDealer(table);
    handOpenCardPlayer(table);
    handOpenCardPlayer(table);
    drawTable(table);

    unsigned char running = 1;
    while(running){
        printf("hit(h) or stand(s)");
        char c = getc();
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
}