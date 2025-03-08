#include <stdio.h>
#include "card.h"

void print_hand(const Card *hand, const int hand_size, const int row_size) {
    printf("| ");
    for (int i = 0; i < hand_size; ++i) {
        const Card card = hand[i];
        char buf[4];
        if (card.face == ' ')
            snprintf(buf, sizeof(buf), "%s%d", card.value == 10 ? "" : " ", card.value);
        else
            snprintf(buf, sizeof(buf), " %c", card.face);

        if (i % row_size == 0 && i != 0)
            printf("\n| ");

        printf("%s %s | ",
               card.suit == CLUBS ? "♣" : card.suit == DIAMONDS ? "♦" : card.suit == HEARTS ? "♥" : "♠",
               buf);
    }
    printf("\n");
}
