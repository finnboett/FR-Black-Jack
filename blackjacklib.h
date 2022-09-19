/*
const char *DIAMONDS_STRING = "D";
const char *HEARTS_STRING = "H";
const char *SPADES_STRING = "S";
const char *CLUB_STRING = "+"
const char *A_STRING = "A";
const char *TWO_STRING = "2";
const char *THREE_STRING = "3";
const char *FOUR_STRING = "4";
const char *FIVE_STRING = "5";
const char *SIX_STRING = "6";
const char *SEVEN_STRING = "7";
const char *EIGHT_STRING = "8";
const char *NINE_STRING = "9";
const char *TEN_STRING = "10";
const char *J_STRING = "J";
const char *Q_STRING = "Q";
const char *K_STRING = "K";
*/

enum Color {Diamonds, Hearts, Spades, Club};
enum Face {A, two, three, four, five, six, seven, eight, nine, ten, J, Q, K};

typedef struct Card {
    enum Color color;
    enum Face face;
} card;

typedef struct Hand {
    card cards[21];
} hand_t;

typedef struct Deck {
  card Cards[52];
} deck_t;

deck_t generteDeck();

typedef struct Stack {
    card Cards[312];
} stack_t;

typedef struct Table {
    stack_t *stack;
    hand_t *dealer;
    hand_t *player;
} table_t;

stack_t *generateStack();

table_t *generateTable(stack_t *stack);

void drawTable(table_t *table);
