#include <stdbool.h>
#include <string.h>
#include "hashmap.c"

struct FiniteStateMachine {
    struct State *currentState;
};

struct State {
    int number;
    struct HashMap *nextStates;
};

struct Alphabet {
    char *alphabetSeq;
    int size;
};

/*
  TODO insert description of sigma function from Tomas Cormen book
*/
int sigma(char *str, int str_size, char *pattern, int pattern_size) {
    int prefixSiffixSize = 0;
    char *startOfPrefix = pattern;
    char *startOfSuffix = &str[str_size - 1];
    int result = 0;
    while (str_size - prefixSiffixSize >= 0 && prefixSiffixSize <= pattern_size) {
        if (strncmp(startOfPrefix, startOfSuffix, prefixSiffixSize) == 0 && prefixSiffixSize > result) {
            result = prefixSiffixSize;
        }
        startOfSuffix = &str[str_size - prefixSiffixSize - 1];
        prefixSiffixSize++;
    }
    return result;
}

struct Alphabet *getAlphabet(char *pattern, int pattern_size) {
    char *alphabetSeq = malloc(pattern_size * sizeof(char));
    char countOfAlphabetSymbols = 0;
    char symbol = pattern[0];
    alphabetSeq[0] = symbol;
    for (int i = 0; i < pattern_size; i++) {
        int aphabetSize = 0;
        bool found = false;
        while ((int)alphabetSeq[aphabetSize] != 0 && aphabetSize < pattern_size) {
            if (alphabetSeq[aphabetSize] == pattern[i]) {
                found = true;
                break;
            }
            aphabetSize++;
        }
        if (!found) {
            alphabetSeq[aphabetSize] = pattern[i];
            countOfAlphabetSymbols++;
        }
    }
    struct Alphabet *alphabet = malloc(sizeof(struct Alphabet));
    alphabet->alphabetSeq = alphabetSeq;
    alphabet->size = countOfAlphabetSymbols;
    return alphabet;
}

struct FiniteStateMachine *compile_finite_state_machine(char *pattern, int pattern_size) {
    struct Alphabet *alphabet = getAlphabet(pattern, pattern_size);
    struct FiniteStateMachine *machine = malloc(sizeof(struct FiniteStateMachine));
    
    //allocates states array
    struct State states[pattern_size + 1];

    states[0].number = 0;
    states[0].nextStates = newMap();

    char substr[pattern_size];
    for (int i = 1; i <= pattern_size; i++) { //pattern
        //create new state
        states[i].number = i;
        states[i].nextStates = newMap();
        //connect previous state and current new one
        put(states[i - 1].nextStates, pattern[i - 1], &states[i]);
        for (int j = 0; j < alphabet->size; j++) { //alphabet
            if (pattern[i ] != alphabet->alphabetSeq[j]) {
                substr[i - 1] = alphabet->alphabetSeq[j];
                put(states[i].nextStates, alphabet->alphabetSeq[j], &states[sigma(substr, i, pattern, pattern_size)]);
            }
        }
    }
    free(substr);
    return NULL;
}
