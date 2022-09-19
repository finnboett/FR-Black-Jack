#include "blackjacklib.h"

void main() {
    stack_t *stack = generateStack();
    table_t *table = generateTable(stack);
    drawTable(table);
    unsigned char running = 1;
    while(running){
        drawTable(table);
    }
}