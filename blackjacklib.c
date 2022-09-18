#include <stdio.h>
#include "./blackjacklib.h"

deck_t generteDeck() {
  for (int color = Diamonds; color <= Club; ++color){
    for(int face = A; face <= K; ++face){
      printf("%i\n",face);
    }
  }
}

stack_t generateStack() {

}

void main(){
    printf("hello world");
}
