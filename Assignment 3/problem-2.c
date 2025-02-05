#include <stdio.h>

// Faltu Funtions
int number_of_words(char str[]);
int nth_word_length(char str[], int n);
int is_prime(int number);
int is_spell(char str[]);


int main() {
    char str[1000];
    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    int len = 0;
    while (str[len] != '\0') len++;
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    if (is_spell(str)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}


int number_of_words(char str[]) {
    int count = 0, i = 0;
    while (str[i] != '\0') {
        if ((i == 0 || str[i - 1] == ' ') && str[i] != ' ') {
            count++;
        }
        i++;
    }
    return count;
}

int nth_word_length(char str[], int n) {
    int count = 0, length = 0, i = 0;
    while (str[i] != '\0') {
        if ((i == 0 || str[i - 1] == ' ') && str[i] != ' ') {
            count++;
            if (count == n) {
                length = 0;
                while (str[i] != ' ' && str[i] != '\0') {
                    length++;
                    i++;
                }
                return length;
            }
        }
        i++;
    }
    return 0;  
}

int is_prime(int number) {
    if (number < 2) return 0;
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) return 0;
    }
    return 1;
}

int is_spell(char str[]) {
    int words = number_of_words(str);
    int spell_number = 0;


    for (int i = 1; i <= words; i++) {
        int length = nth_word_length(str, i);
        if (length > 9) return 0;  
        spell_number = spell_number * 10 + length;
    }

    return is_prime(spell_number);
}