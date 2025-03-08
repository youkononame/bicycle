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
bool shuffle = true;

void usage(const bool error) {
    fprintf(error ? stderr : stdout, "Usage: bicycle [options...]\n"
                    " -r, --row-size <size> Maximum cards in a row\n"
                    " -c, --cards <amount>  Number of cards to deal\n"
                    " -d, --decks <amount>  Number of decks in the shoe\n"
                    " -n, --no-shuffle      Deal from an un-shuffled deck\n"
                    " -h, --help            Display this help message\n");
    exit(error ? EXIT_FAILURE : EXIT_SUCCESS);
}

struct timeval get_time(void) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv;
}

int strtoint(const char *str) {
    char *endptr;
    const int value = strtol(str, &endptr, 10);
    if (endptr == str || *endptr != '\0') {
        usage(true);
    }

    return value;
}

void process_arguments(const int argc, char *argv[]) {
    static struct option long_options[] = {
        {"row-size", required_argument, nullptr, 'r'},
        {"cards", required_argument, nullptr, 'c'},
        {"decks", required_argument, nullptr, 'd'},
        {"no-shuffle", no_argument, nullptr, 'n'},
        {"help", no_argument, nullptr, 'h'}
    };

    int ch;
    while ((ch = getopt_long(argc, argv, "r:c:d:nh", long_options, nullptr)) != -1) {
        switch (ch) {
            case 'r':
                row_size = strtoint(optarg);
                if (hand_size < 1) {
                    fprintf(stderr, "Row size must be at least 1.\n");
                    usage(true);
                }
                break;
            case 'c':
                hand_size = strtoint(optarg);
                if (hand_size < 1) {
                    fprintf(stderr, "Hand size must be at least 1.\n");
                    usage(true);
                }
                break;
            case 'd':
                deck_size = strtoint(optarg) * CARDS_PER_DECK;
                if (deck_size < CARDS_PER_DECK) {
                    fprintf(stderr, "You must have at least 1 deck in the shoe.\n");
                    usage(true);
                }
                break;
            case 'n':
                shuffle = false;
                break;
            case 'h':
                usage(false);
                break;
            default:
                usage(true);
                break;
        }
    }
}

void generate_and_print_hand() {
    Card *deck = malloc(deck_size * sizeof(Card));

    generate_deck(deck, deck_size);
    if (shuffle)
        shuffle_deck(deck, deck_size);
    deal_cards(deck, deck_size, hand_size, row_size, shuffle, 0);

    free(deck);
}

int main(const int argc, char *argv[]) {
    process_arguments(argc, argv);

    const struct timeval tv = get_time();
    srand(tv.tv_usec * tv.tv_sec);

    generate_and_print_hand();

    return 0;
}
