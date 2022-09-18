//hand

//stack

//table

const int NUMBER_OF_CARDS = 312;


enum Color {Diamonds, Hearts, Spades, club};
enum Face {A, two, three, four, five, six, seven, eight, nine, ten, J, Q, K};

typedef struct Card {
    Color color;
    Face face;
} card;

typedef struct Stack {
    card cards[NUMBER_OF_CARDS];
} stack_t;

typedef struct Table {
    stack_t Stack;
} table_t;

stack_t generateStack();