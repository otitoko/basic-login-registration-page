#include <stdio.h>
#include <stdbool.h>

char login_or_register;
bool new_user;
char username[20];
char password[64];

void printInitialPrompt();

int main(){
	printInitialPrompt();
	scanf("%c",&new_user);
	if(login_or_register=='l'){
		new_user=false;
	}
	else{
		new_user=true;
	}

	return 0;


}



void printInitialPrompt(){
	printf("Welcome to the Otitoko Login and Registration service.\n");
	printf("Would you like to login or register?\n");
	printf("(L)ogin					(R)egister");
}
void login(){
	printf("Enter your username: ");
	scanf("%c",&username);
	printf("\nEnter your password: ");
	scanf("%c",&password);
}
void signIn(){
	printf("Enter your username: ");
	scanf("%c",&username);
	printf("\nEnter your password: ");
	scanf("%c",&password);
}

void register_to_file(){
	FILE *fileptr;

	fileptr = fopen("private-data.txt","a");
	fprintf(fileptr, "%c,%c\n",&username,&password);

	fclose(fileptr);
}




