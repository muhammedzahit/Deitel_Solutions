/*
8.25 (Printing Letters for Various ASCII Codes) Write a program that inputs an ASCII code and
prints the corresponding character. Modify this program so that it generates all possible three-digit
codes in the range 000 to 255 and attempts to print the corresponding characters. What happens
when this program is run?
8.26 (Write Your Own Character-Handling Functions) Using the ASCII character chart in
Appendix B as a guide, write your own versions of the character-handling functions in Fig. 8.1.
*/
#include <stdio.h>
int main(){
    int a;
    char b;
    scanf("%c",&b);
    a = b;
    if ( (a<= 90 && a>= 65) || ( a>= 97 && a<= 122 ) ){
        printf("Your entered a letter.");
    }
    else if ( (a<= 57 && a>= 48) ){
        printf("Your entered a digit.");
    }
    else if ( (a<= 15 && a>= 1) || ( a>= 26 && a<= 64 ) || ( a>= 91 && a<= 96 ) || ( a>= 123 && a<= 126 ) ){
        printf("Your entered a punctuation character.");
    }
    return 0;
}