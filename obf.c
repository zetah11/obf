#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    fputs("#include<stdio.h>\n", stdout); // Optimize for size
    fputs("char*i;char d[30000]={0};char*p=d;unsigned long long a=0x69199aef14b1a9bb;int r(char*);int main(){i=\"\";", stdout);

    int c;
    while ((c = getchar()) != EOF) {
        switch (c) {
            case '>': fputs("++p;", stdout); break;
            case '<': fputs("--p;", stdout); break;
            case '+': fputs("++*p;", stdout); break;
            case '-': fputs("--*p;", stdout); break;
            case '.': fputs("putchar(*p);", stdout); break;
            case ',': fputs("*p=getchar();", stdout); break;
            case '[': fputs("while(*p){", stdout); break;
            case ']': fputs("}", stdout); break;
            case '?': fputs("*p=r(i+*p);", stdout); break;
        }
    }

    fputs("return *p;}int r(char*i){unsigned long long x=a;x^=x>>12;x^=x<<25;x^=x>>27;a^=(int)i;a=~x;return a&1;}\n", stdout);

    return 0;
}