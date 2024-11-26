#include <stdio.h>  //p101
#include <stdlib.h>

int main();
int for1(void);
int dowhile1(void);

int main(){
for1();
dowhile1();
return 0;
}

int for1(void)
{
    int n,i,sum=0;
    printf("\ninput n:");
    scanf("%d",&n);
    getchar();
    for(i=1;i<=n;i++){
        sum=sum+i;
    }
printf("summary = %d\n",sum);
printf("i = %d\n",i);
return 0;
}

int dowhile1(void)
{
    int n,i=1,sum=0;
    printf("input n:");
    scanf("%d",&n);
    getchar();
    do{
        sum=sum+i;
        i++;
    }
    while (i<=n);
    
printf("summary = %d\n",sum);
printf("i = %d",i);
return 0;
}

/* ChatGPT提供的算法
通过对数组元素进行两两相加，然后将结果再与下一个元素相加，最终得到总和。
#include <stdio.h>

int cLinearitySum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = cLinearitySum(arr, n);
    printf("Sum: %d\n", sum);
    return 0;
}

*/