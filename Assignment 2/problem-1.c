#include <stdio.h>

int countWords(char *str);
int getMiddleWord(char str[]);
int isDragon(char str[]);

int main() {
    char str[100];
    fgets(str, sizeof(str), stdin);
    if (isDragon(str))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}

int countWords(char *str) {
    int count = 0, inWord = 0;
    while (*str) {
        if (*str == ' ') inWord = 0;
        else if (!inWord) {
            inWord = 1;
            count++;
        }
        str++;
    }
    return count;
}

int getMiddleWord(char str[]) {
    int totalWords = countWords(str);
    int middleIndex = (totalWords / 2) + 1;
    int count = 0, i = 0;
    while (str[i]) {
        if ((i == 0 || str[i - 1] == ' ') && str[i] != ' ') {
            count++;
            if (count == middleIndex) return i;
        }
        i++;
    }
    return -1;
}

int isDragon(char str[]) {
    int index = getMiddleWord(str);
    if (index == -1) return 0;
    
    if (str[index] != '?' || str[index + 1] == ' ')
        return 0;
    
    int i = index + 1;
    while (str[i] && str[i] != ' ' && str[i] != '#') {
        if (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')))
            return 0;
        i++;
    }
    
    return (str[i] == '#');
}
