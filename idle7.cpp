//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
//1번
int main()
{
    int num = -48;
    int total = 0;
    int length = 0;
    int sum = 0;
    const char* string;

    printf("길이를 입력하시오 : ");
    scanf("%d", &length);
    string = (char *)malloc(length * sizeof(char));
    printf("입력받을 문자열 : ");
    scanf("%s", string);

    //위 아래로 두 블럭을 함수로 나눠보기

    for (int i = 0; i < length; i++) {
        sum = num + string[i];
        if (1 <= sum && sum <= 9) {
            printf("%d = %d + %d\n", sum, num, string[i]);
            total = total + sum;
        }
    }
    printf("합계 : %d", total);
    free(string)
    return 0;
}
*/

//2번
int main()
{
    int binaryLength;
    int res = 0;
    int m = 1;
    char* binary;
    int* multi;
    int* decimal;

    printf("길이 입력 : ");
    scanf("%d", &binaryLength);

    binary = (char*)malloc(binaryLength * sizeof(char));
    multi = (int*)malloc(binaryLength * sizeof(int));
    decimal = (int*)malloc(binaryLength * sizeof(int));

    printf("이진수 입력(max : %d) : ", binaryLength);
    scanf("%s", binary);
    //scanf_s("%s", binary, sizeof(binary));    윈도우에서

    for (int i = 0; i < binaryLength - 1; i++)
        m *= 2;
    for (int j = 0; j < binaryLength; j++) {
        multi[j] = m;
        m = m / 2;
    }
    for (int k = 0; k < binaryLength; k++) {
        if (binary[k] == '1')
            decimal[k] = multi[k];
        else if (binary[k] == '0')
            decimal[k] = 0;
    }
    for (int k = 0; k < binaryLength; k++)
        res += decimal[k];
    printf("10진수로 변환 : %d\n", res);
    free(binary);
    free(multi);
    free(decimal);
    return 0;
}