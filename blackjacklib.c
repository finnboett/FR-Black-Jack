#include <stdio.h>
#include <stdlib.h>
#include "./blackjacklib.h"


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

void handOpenCardPlayer(table_t *table){
  int card = rand() % 311;
  int count = 0;
  while(table->stack->Cards[card].face == -1 && count < 311){
    int card = rand() % 311;
    count++;
  }

  for(int i=0; i<21; i++){
    if(table->player->cards[i].face == -1){
      table->player->cards[i].face = table->stack->Cards[card].face;
      table->player->cards[i].color = table->stack->Cards[card].color;
      table->stack->Cards[card].face = -1;
      table->stack->Cards[card].color = -1;
      break;
    }
  }
}

void handOpenCardDealer(table_t *table){
  int card = rand() % 311;
  int count = 0;
  while(table->stack->Cards[card].face == -1 && count < 311){
    int card = rand() % 311;
    count++;
  }

  for(int i=0; i<21; i++){
    if(table->dealer->cards[i].face == -1){
      table->dealer->cards[i].face = table->stack->Cards[card].face;
      table->dealer->cards[i].color = table->stack->Cards[card].color;
      table->stack->Cards[card].face = -1;
      table->stack->Cards[card].color = -1;
      break;
    }
  }
}

table_t *generateTable(stack_t *stack) {
    table_t *table = malloc(sizeof(stack) + 2*21*sizeof(card));
    if (!table) {
        printf("this shouldnt have happened\n");
        exit(-1);
    }
    table->stack = stack;
    hand_t *dealerHand = malloc(21*sizeof(card));
    hand_t *playerHand = malloc(21*sizeof(card));
    for (int i=0; i<21; i++) {
        dealerHand->cards[i].color=-1;
        dealerHand->cards[i].face=-1;
        playerHand->cards[i].color=-1;
        playerHand->cards[i].face=-1;
    }
    table->dealer = dealerHand;
    table->player = playerHand;
}


void drawTable(table_t *table) {
    printf("--------------------------------------\n");
    printf("dealer:\n");
    for (int i=0; i<21; i++) {
        if(table->dealer->cards[i].face == -1) {
            break;
        }
        printf("%i", table->dealer->cards[i].color);
        printf("|");
    }
    printf("\n");
    for (int i=0; i<21; i++) {
        if(table->dealer->cards[i].face == -1) {
            break;
        }
        printf("%i", table->dealer->cards[i].face);
        printf("|");
    }
    printf("\nplayer:\n");
    for (int i=0; i<21; i++){
        if(table->player->cards[i].face == -1) {
            break;
        }
        printf("%i", table->player->cards[i].color);
        printf("|");
    }
    printf("\n");
    for (int i=0; i<21; i++) {
        if(table->player->cards[i].face == -1) {
            break;
        }
        printf("%i", table->player->cards[i].face);   
        printf("|");
    }
    printf("\n");
}

int getValue(hand_t *hand) {
    unsigned char value = 0;
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
    while (aces > 0) {
        if (aces > 1 && value + aces-1 + 11 <= 21) {
            value += 11;
        } else {
            value += 1;
        }
        aces--;
    }
    return (value);
}
