#include<stdio.h>
#include<string.h>

struct Player
{
    char username[50];
    int vitality;
    int magic;
    int defence;
    int attack;
};
// Functions
int isPrime(int num);
int digitSum(int num);
int summation(int n);
int isSpectacular(int num);


int main() {
    struct Player player;

    printf("\nEnter player username: ");
    scanf("%[^\n]s", player.username);

    printf("Enter vitality: ");
    scanf("%d", &player.vitality);
    
    printf("Enter magic: ");
    scanf("%d", &player.magic);

    printf("Enter defence: ");
    scanf("%d", &player.defence);

    printf("Enter attack: ");
    scanf("%d", &player.attack);

    int total_stats = player.vitality + player.magic + player.defence + player.attack;
    if(isSpectacular(total_stats)) {
        printf("\n%d is a spectacular number \n", total_stats);
        printf("Luck value for player %s is %d\n\n", player.username, total_stats);
    } else {
        printf("\n%d is a not spectacular number \n", total_stats);
        printf("Luck value for player %s is %d\n\n", player.username, total_stats);
    }

    return 0;
}

int isPrime(int num){
    if (num < 2) {
        return 0;
    }
    for(int i = 2; i*i <= num; i++){
        if(num % 2 == 0){
            return 0;
        }
    }
    return 1;
}
int digitSum(int num){
    if(num == 0){
        return 0;
    }
    return (num % 10) + digitSum(num / 10);
}
int summation(int n){
    return (n * (n + 1)) / 2;
}
int isSpectacular(int num){
    if(!isPrime(num)) {
        return 0;
    }
    int sum_digits = digitSum(num);
    int total_sum = summation(sum_digits);
    int last_digit = num % 10;
    return (last_digit != 0 && total_sum % last_digit == 0);
}
