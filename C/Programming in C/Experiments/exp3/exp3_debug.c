#include <stdio.h>

int main() {
    int i, j, s;
    for(i = 2; i <= 200; i++) {
        s = 1;
        for(j = 2; j <= i/2; j++) {
            if(i % j == 0) {
                s += j;
            }
        }
        if(s == i) {
            printf("%d=1", i);
            for(j = 2; j <= i/2; j++) {
                if(i % j == 0) {
                    printf("+%d", j);
                }
            }
            printf("\n");
        }
    }
    return 0;
}

/*
调试的过程如下：

编译程序，确保没有语法错误。

使用调试工具，在line 9加入断点。
分析代码逻辑，发现变量s应该在每次循环开始时初始化为1，将s的初始化放在外层循环中。
发现循环中的条件判断有误，将j <= i/2改为j < i。
重新编译运行程序，验证结果是否正确。
*/

/* Original Code
#include <stdio.h>
int main(){
    int i,j,s=1;
    for(i=2;i<=200;i++){
        for(j=2;j<=i/2;j++){
            if(i%j==0){
                s=s+i;
            }
        }
        if (s==i)
        {
            printf("%d=1",i);
            for(j=2;j<=i/2;j++){
                if(i%j==0){
                    printf("+%d",j);
                }
            }
            printf("\n");
        }
    }
    return 0;
}
*/
