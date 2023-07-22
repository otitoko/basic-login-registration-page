#include <stdio.h>
#include <string.h>
//**
//0. REIGSTRATION WORKS	 
//1. upon registration, check for duplicate usernames
//2. upon login, check for username and for matching password
//3. hashing+encryption
//
//
//
//
//notes: how to store the info? linked list? check data algorithms
//
//
//
char login_or_register;


char username[20];
char password[64];

void printInitialPrompt();
void login();
void signIn();
void register_to_file();

int main(){
	printInitialPrompt();
	scanf("%c",&login_or_register);
	getchar();
	if(login_or_register=='l'){
		login();
	}
	else if(login_or_register=='r'){
		signIn();
	}
	else{
		printf("Please enter a valid choice\n");
		printInitialPrompt();

	return 0;
	}
}


void printInitialPrompt(){
	printf("Welcome to the Otitoko Login and Registration service.\n");
	printf("Would you like to login or register?\n");
	printf("(L)ogin					(R)egister\n");
}
void login(){
	printf("Enter your username: ");
	fgets(username, sizeof(username),stdin);
	printf("\nEnter your password: ");
	fgets(password,sizeof(password),stdin);
}
void signIn(){
	printf("Enter your username: ");
	fgets(username, sizeof(username),stdin);
	username[strcspn(username, "\n")]= '\0';

	printf("\nEnter your password: ");
	fgets(password, sizeof(password),stdin);
	password[strcspn(password, "\n")]= '\0';

	register_to_file(username,password);
}

void register_to_file(){
	FILE *fileptr;

	fileptr = fopen("private-data.txt","a");
	fprintf(fileptr, "%s,%s\n",&username,&password);

	fclose(fileptr);
}




