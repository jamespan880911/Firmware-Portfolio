#include <stdio.h>
#include <string.h>

void swap_char(char *a, char *b){
    char temp = ' ';
    temp = *a;
    *a = *b;
    *b = temp;
}
char *reverse_string(char *x){
    int n = strlen(x);
    for (int i = 0; i < n / 2; i++){
        swap_char(&x[i], &x[n-i-1]);
    }
    return x;
}

int main(){
    char str[] = "hello";
    reverse_string(str);
    printf("%s\n", str);
    return 0;
}