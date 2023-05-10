#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BigInt {

    char *number;

} BigInt;

BigInt* addBigInt(BigInt *n1, BigInt *n2) {

    BigInt *n3 = (BigInt*) malloc(sizeof(BigInt));

    int carry = 0;
    int len1 = strlen(n1->number)-1;
    int len2 = strlen(n2->number)-1;
    char *sum;

    int iteration = 0;

    printf("len1 = %d, len2 = %d\n", len1, len2);
    printf("n1->number = %s, n2->number = %s\n", n1->number, n2->number);

    while ((len1 >= 0) || (len2 >= 0)) {

        iteration++;

        int digitsSum = carry;

        if (len1 >= 0) {

            digitsSum += n1->number[len1] - '0';
            len1--;
        }

        if (len2 >= 0) {

            digitsSum += n2->number[len2] - '0';
            len2--;
        }

        carry = digitsSum / 10;
        digitsSum = digitsSum % 10;

        printf("digits sum = %d\n", digitsSum);
        printf("carry = %d\n", carry);

        char ch[1];
        sprintf(ch, "%d", digitsSum);

        if (iteration == 1) {

            sum = (char*) malloc(1*sizeof(char));
            sum[0] = ch[0];
        }

        else {

            char *temp = (char*) malloc((strlen(sum)+1)*sizeof(char));
            for (int i = 0; i < (strlen(sum)+1); i++) {

                if (i == 0) {

                    temp[i] = ch[0];
                }

                else {

                    temp[i] = sum[i-1];
                }
            }

            //sum = realloc(sum, strlen(temp)+1*sizeof(char));
            sum = temp;
        }

        printf("sum = %s\n", sum);
    }

    if (carry != 0) {

        char ch[1];
        sprintf(ch, "%d", carry);

        char *temp = (char*) malloc((strlen(sum)+1)*sizeof(char));
        for (int i = 0; i < (strlen(sum)+1); i++) {

            if (i == 0) {

                temp[i] = ch[0];
            }

            else {

                temp[i] = sum[i];
            }
        }

        //sum = realloc(sum, strlen(temp)*sizeof(char));
        sum = temp;
        printf("sum = %s\n", sum);
    }

    n3->number = (char*) malloc(strlen(sum)*sizeof(char));
    n3->number = sum;

    return n3;
}

int main() {

    BigInt *n1 = (BigInt*) malloc(sizeof(BigInt));
    BigInt *n2 = (BigInt*) malloc(sizeof(BigInt));

    // safe
    // char str[] = "32432";
    // n1->number = (char*) malloc(strlen(str)*sizeof(char));
    // n1->number = str;
    n1->number = "222";
    n2->number = "111";
    BigInt *n3 = addBigInt(n1, n2);

    printf("%s\n", n1->number);
    printf("%s\n", n2->number);
    printf("%s\n", n3->number);
    
	return 0;
}