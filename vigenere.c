#include<stdio.h>
#include <ctype.h>
#include<string.h>
char Vigenere(char letter, char key);
int main(){
	char input[200];
	char passphrase[200];
	
	printf("Enter your sentence:");
	scanf("%s",input);
	printf("Enter the key:");
	scanf("%s", passphrase);
	
	int passlen=strlen(passphrase);
	
	for(int i = 0; input[i] != '\0'; ++i){
		int ch=i%passlen;
		input[i]=Vigenere(input[i],passphrase[ch]);
	}
	printf("Encrypted message: %s", input);
	return 0;
}

char Vigenere(char letter, char key){
	key=tolower(key);

			if((letter>='a'&& letter <='z'-key+96)||(letter>='A'&& letter <='Z'-key+96))
				return letter+key-96;
			
			else if((letter >= 'a' && letter <= 'z')||(letter>='A'&& letter <='Z'))
				return letter+key-97-25;
	return letter;
}