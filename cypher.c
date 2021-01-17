#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
void encrypt(uint32_t charCount, uint32_t key) {
    printf("Enter the text: ");
    char *ch = malloc(8 * charCount);
    scanf("%s", ch);
    getchar();
    ch[charCount] = '\0';
    unsigned int keyCopy = key;
    char keyBinary[33];
    int index = 31;
    while (key > 0) {
        keyBinary[index] = key % 2 + '0';
        key /= 2;
        index--;
    }
    keyBinary[32] = '\0';
    unsigned int indexes =( 8 * charCount)- 1;
    int store = 8 * charCount;
    char *copy = malloc(8 * charCount);
    int cc = 8 * charCount + 1;
    for (int i = charCount-1; i >= 0;i--) {
        int l = ch[i];

            int in = 0;
            while (l > 0) {
                copy[indexes] = l % 2 + '0';
                l /= 2;
                indexes--;
                in++;
            }
            while (in < 8) {
                copy[indexes] = '0';
                indexes--;
                in++;
            }
        }

    copy[(charCount * 8)] = '\0';


    char *final = malloc(8 * charCount);
    int indexe = 0;
    for (int j = 0; j < strlen(copy); j++) {
        int i = j;
        if (i > 31){
            i = i - 31;
        }
        if (copy[j] == '\0') {
            break;

        } else {
            int l = copy[j] - 48;
            int c = keyBinary[i] - 48;
            if ((i >= 0) && (i < 8)) {
               final[indexe] = (c ^= l)  + '0';
                indexe++;
            }
            if ((i >= 8) && (i < 16)) {
                final[indexe] = (c ^= l) + '0';
                indexe++;
            }
            if ((i >= 16) && (i < 24)) {
                final[indexe] = (c^= l) + '0';
                indexe++;
            }
            if ((i >= 24) && (i < 32)) {
                final[indexe] = (c ^= l) + '0' ;
                indexe++;
            }
        }

    }
    final[charCount * 8] = '\0';
    printf("The encrypted string is: ");
    for (int i = 0; i < strlen(final); i++){
        if (final[i] == '\0'){
            break;
        }
        printf("%c", final[i]);

    }
}






void decrypt(uint32_t charCount, uint32_t key){

}

int main() {
    char choice;
    while(1) {
        printf("\nWelcome to Cipher\n"
               "-----------------\nA-Encrypt Text\n"
               "B-Decrypt Text\n"
               "C-Find Key\n"
               "D-Exit\n"
               "-----------------");
        printf("\nSelect an option: ");

        scanf("%c", &choice);
        if (choice == 'D'){
            exit(1);
        }
        uint32_t charCount;
        uint32_t key;
        if (choice == 'A'){
            printf("Enter the number of charecters to encrpyt: ");
            scanf("%u", &charCount);
            printf("Enter the key: ");
            scanf("%u", &key);
            encrypt(charCount, key);
            fflush(stdin);
        }
        if (choice == 'B'){
            printf("Enter the number of characters to decrypt: ");
            scanf("%u", &charCount);
            printf("Enter the key: ");
            scanf("%u", &key);
            decrypt(charCount, key);
        }

    }

    return 0;
}