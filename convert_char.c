#include <stdio.h>

char convert_char(char c){
    if (c >= 'a' && c <= 'z'){
        c -= 32;
        printf("轉換後為：%c\n", c);
        return c;
    }
    else if (c >= 'A' && c <= 'Z'){
        c += 32;
        printf("轉換後為：%c\n", c);
        return c;
    }
    else{
        printf("超過範圍，無法轉換\n");
    }
    return 0;
}

int main(){
    char c;
    printf("請輸入字母：");
    scanf("%c", &c);
    convert_char(c);
    return 0;
}