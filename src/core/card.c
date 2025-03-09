#include <stdio.h>
#include "card.h"

#include "deck.h"

const char *suit_to_string(const Suit suit) {
    return suit == CLUBS ? "♣" : suit == DIAMONDS ? "♦" : suit == HEARTS ? "♥" : "♠";
}

void value_to_string(char *buf, const Card card) {
    if (card.face == ' ')
        snprintf(buf, sizeof(buf), "%s%d", card.value == 10 ? "" : " ", card.value);
    else
        snprintf(buf, sizeof(buf), " %c", card.face);
}

void deal_cards(Card *deck, const int deck_size, const int hand_size, const int row_size, const bool shuffle, const int starting_index) {
    printf("| ");
    int index = starting_index;
    for (int i = 0; i < hand_size; ++i) {
        const Card card = deck[index++];

        if (i % row_size == 0 && i != 0)
            printf("\n| ");

        char buf[4];
        value_to_string(buf, card);
        printf("%s %s | ",
               suit_to_string(card.suit),
               buf);

        if (index == deck_size) {
            if (shuffle)
                shuffle_deck(deck, deck_size);
            index = 0;
        }
    }
    puts("");
}
