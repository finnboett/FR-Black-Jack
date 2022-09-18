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


stack_t generateStack() {

}

void main(){
  deck_t *deck1 = generateDeck();

  for (int i = 0; i <= 51; i++){

    //printf(deck1->Cards[1].color, deck1->Cards[1].face);
    printf("%i: %i, %i\n", i, deck1->Cards[i].color, deck1->Cards[i].face);

  }


}
