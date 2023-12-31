#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 51

//使一个数组逆序
void reverse(char *str) {
    int i, j;
    int len = strlen(str);
    for (i = 0, j = len - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

//程序主算法，用两个数组实现大数相加
void add(char *num1, char *num2, char *result) {
    int carry = 0;
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxLen = len1 > len2 ? len1 : len2;
    
    for (int i = 0; i < maxLen; i++) {
        int digit1 = 0, digit2 = 0;
        if (i < len1) {
            digit1 = num1[i] - '0'; //char转int
        }
        if (i < len2) {
            digit2 = num2[i] - '0'; //char转int
        }
        
        int sum = digit1 + digit2 + carry;
        result[i] = sum % 10 + '0'; //加和结果，并将int转char
        carry = sum / 10;   //进位数
    }
    
    if (carry) {
        result[maxLen] = carry + '0';
        result[maxLen + 1] = '\0';
    } else {
        result[maxLen] = '\0';
    }
    
    reverse(result);
}

int main() {
    char num1[MAX_DIGITS];
    char num2[MAX_DIGITS];
    char result[MAX_DIGITS + 1];
    scanf("%s", num1);
    scanf("%s", num2);
    
    reverse(num1);
    reverse(num2);
    
    add(num1, num2, result);
    
    printf("%s", result);
    
    return 0;
}
