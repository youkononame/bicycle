#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <getopt.h>
#include "core/card.h"
#include "core/deck.h"
#include "games/baccarat.h"

constexpr int DEFAULT_ROW_SIZE = 4;
constexpr int DEFAULT_HAND_SIZE = 1;
constexpr int CARDS_PER_DECK = 52;

unsigned int seed;
int row_size = DEFAULT_ROW_SIZE;
int hand_size = DEFAULT_HAND_SIZE;
int deck_size = CARDS_PER_DECK;
bool shuffle = true;
bool baccarat = false;

void usage(const bool error) {
    fprintf(error ? stderr : stdout, "Usage: bicycle [options...]\n"
            " -r, --row-size <size> Maximum cards in a row\n"
            " -c, --cards <amount>  Number of cards to deal\n"
            " -d, --decks <amount>  Number of decks in the shoe\n"
            " -s, --seed <seed>     Seed used for shuffling the deck\n"
            " -b, --baccarat        Play a game of baccarat\n"
            " -n, --no-shuffle      Deal from an un-shuffled deck\n"
            " -h, --help            Display this help message\n");
    exit(error ? EXIT_FAILURE : EXIT_SUCCESS);
}

struct timeval get_time(void) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv;
}

bool strtoint(int *dest, const char *str) {
    char *endptr;
    const int value = strtol(str, &endptr, 10);
    if (endptr == str || *endptr != '\0') {
        return false;
    }

    *dest = value;
    return true;
}

void process_arguments(const int argc, char *argv[]) {
    static struct option long_options[] = {
        {"row-size", required_argument, nullptr, 'r'},
        {"cards", required_argument, nullptr, 'c'},
        {"decks", required_argument, nullptr, 'd'},
        {"seed", required_argument, nullptr, 's'},
        {"no-shuffle", no_argument, nullptr, 'n'},
        {"baccarat", no_argument, nullptr, 'b'},
        {"help", no_argument, nullptr, 'h'}
    };

    int ch;
    while ((ch = getopt_long(argc, argv, "r:c:d:s:nbh", long_options, nullptr)) != -1) {
        switch (ch) {
            case 'r':
                if (!strtoint(&row_size, optarg) || hand_size < 1) {
                    fprintf(stderr, "Row size must be at least 1.\n");
                    usage(true);
                }
                break;
            case 'c':
                if (!strtoint(&hand_size, optarg) || hand_size < 1) {
                    fprintf(stderr, "Hand size must be at least 1.\n");
                    usage(true);
                }
                break;
            case 'd':
                if (!strtoint(&deck_size, optarg) || deck_size * CARDS_PER_DECK < CARDS_PER_DECK) {
                    fprintf(stderr, "You must have at least 1 deck in the shoe.\n");
                    usage(true);
                }
                deck_size *= CARDS_PER_DECK;
                break;
            case 's':
                const unsigned int base_seed = seed;
                if (!strtoint(&seed, optarg) || seed == base_seed) {
                    fprintf(stderr, "Invalid seed.\n");
                    usage(true);
                }
                break;
            case 'n':
                shuffle = false;
                break;
            case 'b':
                baccarat = true;
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

int main(const int argc, char *argv[]) {
    seed = get_time().tv_usec;
    process_arguments(argc, argv);
    srand(seed);

    Card *deck = malloc(deck_size * sizeof(Card));

    generate_deck(deck, deck_size);
    if (shuffle)
        shuffle_deck(deck, deck_size);

    if (baccarat)
        play_baccarat(deck, deck_size);
    else
        deal_cards(deck, deck_size, hand_size, row_size, shuffle, 0);

    free(deck);
    return 0;
}
