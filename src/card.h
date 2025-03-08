#ifndef CARD_H
#define CARD_H

typedef enum Suit : int {
    CLUBS = 1,
    DIAMONDS,
    HEARTS,
    SPADES,
} Suit;

constexpr int MAX_CARD_VALUE = 10;

typedef enum Rank : int {
    ACE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
} Rank;

typedef struct Card {
    Suit suit;
    int value;
    char face;
} Card;

void print_hand(const Card *hand, int hand_size, int row_size);

#endif
