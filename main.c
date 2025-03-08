#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <getopt.h>
#include "card.h"
#include "deck.h"

constexpr int DEFAULT_ROW_SIZE = 4;
constexpr int DEFAULT_HAND_SIZE = 1;
constexpr int CARDS_PER_DECK = 52;

int row_size = DEFAULT_ROW_SIZE;
int hand_size = DEFAULT_HAND_SIZE;
int deck_size = CARDS_PER_DECK;

struct timeval get_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv;
}

int strtoint(const char *str, const int default_value) {
    char *endptr;
    const int value = strtol(str, &endptr, 10);
    if (endptr == str || *endptr != '\0') {
        return default_value;
    }
    return value;
}

void process_arguments(const int argc, char *argv[]) {
    static struct option long_options[] = {
        {"row-size", required_argument, nullptr, 'r'},
        {"cards", required_argument, nullptr, 'c'}
    };

    int ch;
    while ((ch = getopt_long(argc, argv, "r:c:", long_options, NULL)) != -1) {
        switch (ch) {
            case 'r':
                row_size = strtoint(optarg, DEFAULT_ROW_SIZE);
                row_size = row_size < 1 ? 1 : row_size;
                break;
            case 'c':
                hand_size = strtoint(optarg, DEFAULT_HAND_SIZE);
                hand_size = hand_size < 1 ? 1 : hand_size;
                deck_size = (hand_size / CARDS_PER_DECK + 1) * 52;
                break;
            default:
                exit(EXIT_FAILURE);
        }
    }
}

void generate_and_print_hand(const int deck_size) {
    Card *deck = malloc(deck_size * sizeof(Card));

    generate_deck(deck, deck_size);
    shuffle_deck(deck, deck_size);
    print_hand(deck, hand_size, row_size);

    free(deck);
}

int main(const int argc, char *argv[]) {
    process_arguments(argc, argv);

    const struct timeval tv = get_time();
    srand(tv.tv_usec * tv.tv_sec);

    generate_and_print_hand(deck_size);

    return 0;
}
