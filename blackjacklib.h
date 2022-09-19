//hand

//stack

//table

const int NUMBER_OF_CARDS = 312;


enum Color {Diamonds, Hearts, Spades, Club};
enum Face {A, two, three, four, five, six, seven, eight, nine, ten, J, Q, K};

typedef struct Card {
    enum Color color;
    enum Face face;
} card;

typedef struct Deck {
  card Cards[52];
} deck_t;

deck_t generteDeck();

typedef struct Stack {
    card Cards[312];
} stack_t;

typedef struct Table {
    stack_t Stack;
} table_t;

stack_t *generateStack();
