
#include<stdio.h>
#include<string.h>

char *encryption(char[]);
char *decryption(char[]);
 
int main(){
   int Choice;
   char Message[255];
   char *C_Text;
   
   
   printf("Enter you message for Encryption/Decryption:\n");
   scanf("%[^\n]", Message);
   printf("Your message is: %s", Message);
   
   do{
		printf("\npress 1 for Encryption \npress 2 for Decryption \npress 0 for Exit \n");
    	scanf("%d", &Choice);
		
		switch(Choice){
    		case 1:
    			C_Text = encryption(Message);
    			break;
    		case 2:
    			C_Text = decryption(Message);
    			break;
    		case 0:
    			break;
    		default:
    			printf("\nEnter valid choice\n");
    			break;  	
		} 	
   	} while(Choice != 0);	  
	   return 0;	
 }
 
char *encryption(char cipher_Text[]){
	int Key;
	int i;
	
	printf("Enter the key for encryption: ");
	scanf("%d", &Key);
	
	for(i = 0; i < strlen(cipher_Text); i++){
		if(cipher_Text[i] >= 'A' && cipher_Text[i] <= 'z'){
			cipher_Text[i] = (cipher_Text[i] - 97 + Key) %26 + 97 ;
			if(cipher_Text[i] > 'z'){
				cipher_Text[i] = cipher_Text[i] - 26;	
			}

		}
	}
	printf("Your Encrypted message is: %s", cipher_Text);
	return cipher_Text;
}
	
	


char *decryption(char cipher_Text[]){
	int Key;
	int i;
	char cipher[255];
	
	printf("Enter the key for decryption: ");
	scanf("%d", &Key);
	
	//With key
	if( Key >= 1 && Key <=26){
		for(i = 0; i < strlen(cipher_Text); i++){
			if(cipher_Text[i] >= 'A' && cipher_Text[i] <= 'z'){
				cipher_Text[i] = (cipher_Text[i] - 97 - Key) %26 + 97 ;
				if(cipher_Text[i] > 'z'){
					cipher_Text[i] = cipher_Text[i] - 26;
				}	
			}
		}
		printf("Your Encrypted message is: %s", cipher_Text);
		return cipher_Text;
	}
		
//without key
	for(Key = 1; Key < 26; Key++){
		for(i = 0; i < strlen(cipher_Text); i++){
			if(cipher_Text[i] >= 'A' && cipher_Text[i] <= 'z'){
				cipher[i] = (cipher_Text[i] - 97 + Key) % 26 + 97;
				if(cipher[i] < 'A'){
					cipher[i] = cipher_Text[i] + 26; 
					
				}
			}
		}
	printf("\nDecrypted message is: %s", cipher);
	}
	return cipher_Text;
}

