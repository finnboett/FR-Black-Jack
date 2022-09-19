#include <stdio.h>
#include <stdlib.h>
#include "./blackjacklib.h"
#include <time.h>


deck_t *generateDeck() {
  deck_t *deck = malloc(52*sizeof(card));

  if(!deck){
    printf("Deck geht nicht");

  }

  for (int color = Diamonds; color <= Club; ++color){
    for(int face = A; face <= K; ++face){
      card newCard={
        color, face,
      };
      (deck->Cards[color*13+face])=newCard;

    }
  }
  return deck;
}

stack_t *generateStack() {
  stack_t *stack = malloc(6*sizeof(deck_t));
  deck_t *deck;
  for (int i=0; i<6; i++){
    deck = generateDeck();
    for(int j=0; j<52; j++) {
      stack->Cards[52*i+j].color = deck->Cards[j].color;
      stack->Cards[52*i+j].face = deck->Cards[j].face;
    }
    free(deck);
  }
  return(stack);
}

void main(){
  stack_t *stack1 = generateStack();

  for (int i = 0; i <= 311; i++){

    //printf(deck1->Cards[1].color, deck1->Cards[1].face);
    //printf("%i: %i, %i\n", i, stack1->Cards[i].color, stack1->Cards[i].face);

  }
  handOpenCardPlayer(NULL);
  handOpenCardDealer(NULL);
}

void handOpenCardPlayer(table_t *table){
  srand(time(NULL));
  int card = rand() % 311;
  printf("0\n");
  while(table->stack->Cards[card].face == -1){
    srand(time(NULL));
    int card = rand() % 311;
    printf("1\n");
  }

  for(int i=0; i<21; i++){
    if(table->player->cards[i].face == -1){
      printf("2\n");
      table->player->cards[i].face = table->stack->Cards[card].face;
      table->player->cards[i].color = table->stack->Cards[card].color;
      printf("3\n");
      table->stack->Cards[card].face = -1;
      table->stack->Cards[card].color = -1;
      printf("4\n");
      break;
    }
  }
}

void handOpenCardDealer(table_t *table){
  srand(time(NULL));
  int card = rand() % 311;
  printf("0\n");
  while(table->stack->Cards[card].face == -1){
    srand(time(NULL));
    int card = rand() % 311;
    printf("1\n");
  }

  for(int i=0; i<21; i++){
    if(table->dealer->cards[i].face == -1){
      printf("2\n");
      table->dealer->cards[i].face = table->stack->Cards[card].face;
      table->dealer->cards[i].color = table->stack->Cards[card].color;
      printf("3\n");
      table->stack->Cards[card].face = -1;
      table->stack->Cards[card].color = -1;
      printf("4\n");
      break;
    }
  }
}

table_t *generateTable(stack_t *stack) {
    table_t *table = malloc(sizeof(stack) + 2*21*sizeof(card));
    table->stack = stack;
    hand_t *dealerHand = malloc(21*sizeof(card));
    hand_t *playerHand = malloc(21*sizeof(card));
    for (int i=0; i<21; i++) {
        dealerHand->cards[i].color=-1;
        dealerHand->cards[i].face=-1;
        playerHand->cards[i].color=-1;
        playerHand->cards[i].face=-1;
    }
}


void drawTable(table_t *table) {
    printf("dealer:\n");
    for (int i=0; i<21; i++) {
        printf("%i", table->dealer->cards[i].color);
    }
    printf("\n");
    for (int i=0; i<21; i++) {
        printf("%i", table->dealer->cards[i].face);
    }
    printf("player:\n");
    for (int i=0; i<21; i++){
        printf("%i", table->player->cards[i].color);
    }
    for (int i=0; i<21; i++) {
        printf("%i", table->player->cards[i].face);
    }
}

int getValue(hand_t *hand) {
    unsigned char value;
    unsigned char aces = 0;
    for (int i=0; i<21; i++) {
        unsigned char cardValue = hand->cards[i].face;
        if(cardValue == -1) {
            break;
        } else if (cardValue == 0) {
            aces++;
        } else {
            value += cardValue + 1;
        }
    }
}
