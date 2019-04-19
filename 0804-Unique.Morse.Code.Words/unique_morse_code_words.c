/*----------------------------------------------------------------------------
 *
 * unique_morse_code_words.c
 *
 *----------------------------------------------------------------------------
 */

static char *morse[] = {
    ".-",    "-...",  "-.-.",   "-..",    ".",    "..-.",    "--.",    "....",
    "..",    ".---",  "-.-",    ".-..",   "--",   "-.",      "---",    ".--.",
    "--.-",  ".-.",   "...",    "-",      "..-",  "...-",    ".--",    "-..-",
    "-.--",  "--.."
};

#define MAX_WORDS    101

int
uniqueMorseRepresentations(char **words, int wordsSize)
{
    long long mark[MAX_WORDS] = { 0 };
    int count = 0;

    for (int i = 0; i < wordsSize; i++) {
        long long mask = 0;
        char *m = words[i];

        while (*m) {
            char *p = morse[*m - 'a'];
            while (*p) {
                if (*p == '.') {
                    mask = (mask << 1) | 1;
                } else {
                    mask <<= 1;
                }
                p++;
            }
            m++;
        }

        int idx = 0;
        for (/* void */; idx < count; idx++) {
            if (mask == mark[idx]) {
                break;
            }
        }

        if (idx == count) {
            mark[count++] = mask;
        }
    }

    return count;
}
