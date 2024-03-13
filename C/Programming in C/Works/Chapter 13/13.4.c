#include <stdio.h>

void copyFile(const char *sourceFileName, const char *targetFileName) {
    FILE *sourceFile, *targetFile;
    char ch;

    // 打开源文件
    sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL) {
        printf("Failed to open the source file.\n");
        return;
    }

    // 打开目标文件
    targetFile = fopen(targetFileName, "w");
    if (targetFile == NULL) {
        printf("Failed to create/open the target file.\n");
        fclose(sourceFile);
        return;
    }

    // 复制源文件内容到目标文件
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, targetFile);
    }

    // 关闭文件
    fclose(sourceFile);
    fclose(targetFile);

    printf("File copied successfully.\n");
}

int main() {
    char sourceFileName[100], targetFileName[100];

    // 输入源文件名
    printf("Enter the source file name: ");
    scanf("%s", sourceFileName);

    // 输入目标文件名
    printf("Enter the target file name: ");
    scanf("%s", targetFileName);

    // 调用复制文件函数
    copyFile(sourceFileName, targetFileName);

    return 0;
}