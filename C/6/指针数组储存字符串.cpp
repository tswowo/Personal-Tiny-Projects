#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, i;
    printf("Enter the number of strings: ");
    scanf("%d", &n); // ��ȡ��Ҫ�洢���ַ�������
    char *strArray[n]; // ����ָ������
    strArray[1]="QWERT";
    strArray[2]="ASDFG";
    strArray[3]="ZXCVB";
    printf("%s\n%s\n%s",strArray[1],strArray[2],strArray[3]);
    return 0;
}

