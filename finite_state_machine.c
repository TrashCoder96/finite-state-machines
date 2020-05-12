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

struct FiniteStateMachine *compile_finite_state_machine(char *pattern, int pattern_size) {
    struct FiniteStateMachine *machine = (struct FiniteStateMachine*)malloc(sizeof(struct FiniteStateMachine));
    struct State *startState = (struct State*)malloc(sizeof(struct State));
    startState->number = 0;
    startState->nextStates = newMap();
    struct State *previousState = startState;
    for (int i = 1; i < pattern_size; i++) {
        struct State *state = (struct State*)malloc(sizeof(struct State));
        state->number = i;
        state->nextStates = newMap();
        put(previousState->nextStates, pattern[i - 1], state);
    }
    return NULL;
}
