#include <stdio.h>

int main() {
    int num;
    scanf("%d", &num);

    int div3 = (num % 3 == 0);
    int div5 = (num % 5 == 0);
    int div7 = (num % 7 == 0);

    if (div3 && div5 && div7) {
        printf("3 5 7\n");
    } else if (div3 && div5) {
        printf("3 5\n");
    } else if (div3 && div7) {
        printf("3 7\n");
    } else if (div5 && div7) {
        printf("5 7\n");
    } else if (div3) {
        printf("3\n");
    } else if (div5) {
        printf("5\n");
    } else if (div7) {
        printf("7\n");
    } else {
        printf("n\n");
    }

    return 0;
}