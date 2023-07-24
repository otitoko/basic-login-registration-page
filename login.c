#include <stdio.h>
#include <string.h>

#define MAX_FILE_LENGTH 1024
#define MAX_USERNAME_LENGTH 20
//**
//0. REIGSTRATION WORKS	 
//1. upon registration, check for duplicate usernames
//2. upon login, check for username and for matching password
//3. hashing+encryption
//
//
//a. separate usernames and passwords
//b. read through the usernames file and put it into an array
//c. loop through array to check for a string that matches the intended username
//
//notes: how to store the info? linked list? check data algorithms
//
//
//
char login_or_register;


char username[MAX_USERNAME_LENGTH];
char password[64];

void printInitialPrompt();
void login();
void signIn();
void register_to_file();
int check_for_duplicates(char username[MAX_USERNAME_LENGTH]);

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
	do{
	printf("Enter your username: ");
	fgets(username, sizeof(username),stdin);
	username[strcspn(username, "\n")]= '\0';
	}
	while(check_for_duplicates(username) == 1);
	

	printf("\nEnter your password: ");
	fgets(password, sizeof(password),stdin);
	password[strcspn(password, "\n")]= '\0';

	register_to_file(username,password);
}
/**
void check_for_file(FILE **fileptr, const char *FILENAME){
	if(*fileptr == NULL){
		return 0;
	}
	else{
		return 1;
	}
}
**/
int check_for_duplicates(char *username){
	FILE *fileptr;
	char username_file[MAX_FILE_LENGTH];

	
	fileptr = fopen("usernames.txt","r");

	while(fgets(username_file,MAX_FILE_LENGTH,fileptr) != NULL){
		username_file[strcspn(username_file,"\n")] = '\0';
		if(strstr(username_file,username) != NULL){
			printf("Username already in use.\n");
			fclose(fileptr);
			return 1;
		}
	}

	fclose(fileptr);

	return 0;


}

void register_to_file(){
	FILE *fileptr;

	fileptr = fopen("usernames.txt","a");
	fprintf(fileptr, "%s\n",&username);

	fclose(fileptr);

	fileptr = fopen("password.txt","a");
	fprintf(fileptr, "%s\n",&password);

	fclose(fileptr);
}




