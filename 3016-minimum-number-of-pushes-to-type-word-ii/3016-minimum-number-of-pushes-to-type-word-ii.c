#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int minimumPushes(char* word) {
    int freq[26] = {0};

    for (int i = 0; word[i] != '\0'; i++) {
        freq[word[i] - 'a']++;
    }

    qsort(freq, 26, sizeof(int), compare);

    int totalPushes = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] == 0) break;

        int pushesPerChar = (i / 8) + 1;
        totalPushes += freq[i] * pushesPerChar;
    }

    return totalPushes;
}