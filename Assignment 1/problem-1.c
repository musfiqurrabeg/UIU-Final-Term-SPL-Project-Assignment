#include<stdio.h>

// Functions
int is_fibonacci(int x);
int count_odd_digits(int x);
int is_warrior(int x);
void list_fibonacci_warriors(int limit);



int main() {
    int n;
    printf("\nEnter the upper range: ");
    scanf("%d", &n);
    printf("\n");
    list_fibonacci_warriors(n);
    return 0;
}

// Function Part.
int is_fibonacci(int x) {
    int a = 0, b = 1, temp;
    while (b < x) {
        temp = a + b;
        a = b;
        b = temp;
    }
    return (b == x);
}

int count_odd_digits(int x) {
    if (x == 0) return 0;
    return (x % 10) % 2 + count_odd_digits(x / 10);
}

int is_warrior(int x) {
    if (is_fibonacci(x) && (count_odd_digits(x) % 2 == 0)) {
        return 1;
    } else {
        return 0;
    }
}
void list_fibonacci_warriors(int limit) {
    printf("Amicable number pairs within the range %d: ", limit);
    for (int i = 1; i <= limit; i++) {
        if (is_warrior(i)) {
            printf("%d, ", i);
        }
    }
    printf("\n\n");
}
