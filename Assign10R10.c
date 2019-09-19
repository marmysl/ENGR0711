// HW 10
// R10: Elizabeth Mountz, Maria Mysliwiec, Sead Niksic

#include <stdio.h>
#include <ctype.h>

void description(void){
	printf("November 19, 2018\n\nGroup R10: Maria Mysliwiec, Elizabeth Mountz, Sead Niksic");
	printf("\n\nThe purpose of this program is to allow users to add, subtract, multiply, or divide two real numbers entered\
 from the keyboard.");
}

float choosenumber(int count){
	float num;
	printf("\n\nEnter a value for a number %d: ",count);
	scanf("%f",&num);
	return num; 
}

int menu(void){
	int menu_num;
	printf("\nSelect an operation to perform on two numbers entered.");
	printf("\n\n1) Addition\n2) Subtraction\n3) Multiplication\n4) Division");
	printf("\n\nEnter integer value for choice (1, 2, 3, or 4): ");
	scanf("%d",&menu_num);
	
	while (menu_num < 1 &&  menu_num > 5)  {
		printf("\nERROR: You must enter 1, 2, 3 or 4!");
		printf("\nPlease try again: ");
		scanf("%d",&menu_num);
	}
	
	return menu_num;
}

float operation(int menu_num, float num1, float num2){
	float output;
	switch (menu_num) {
		case 1:
			output=num1+num2;
			break;
		case 2:
			output=num1-num2;
			break;
		case 3:
			output=num1*num2;
			break;
		case 4:
			output=num1/num2;
			break;
		}	
	return output;
}

void result(int menu_num, float num1, float num2, float output){
	switch (menu_num) {
		case 1:
			printf("\n\nThe addition of %f + %f is: %f",num1,num2,output);
			break;
		case 2:
			printf("\n\nThe subtraction of %f - %f is: %f",num1,num2,output);
			break;
		case 3:
			printf("\n\nThe product %f * %f is: %f",num1,num2,output);
			break;
		case 4:
			printf("\n\nThe quotient %f // %f is: %f",num1,num2,output);
			break;
		}
	
	FILE *fp;
	fp = fopen("results.txt","w"); //created file 
	fprintf(fp,"The entered values are: %f and %f",num1,num2);
		switch (menu_num) {
		case 1:
			fprintf(fp,"\nThe operation you chose was %d, addition",menu_num);
			fprintf(fp,"\nThe result of this operation is: %f",output);
			break;
		case 2:
			fprintf(fp,"\nThe operation you chose was %d, subtraction",menu_num);
			fprintf(fp,"\nThe result of this operation is: %f",output);
			break;
		case 3:
			fprintf(fp,"\nThe operation you chose was %d, multiplication",menu_num);
			fprintf(fp,"\nThe result of this operation is: %f",output);
			break;
		case 4:
			fprintf(fp,"\nThe operation you chose was %d, division",menu_num);
			fprintf(fp,"\nThe result of this operation is: %f",output);
			break;
		}
}

int main(void) {
	float num1=0, num2=0, calculation;
	int count=1, menu_num;
	char response;
	
	do {
	
		// Call Function 1
		description();
	
		// Call Function 2 twice
		num1=choosenumber(count);
		count++;
		num2=choosenumber(count);
		
		// Call Function 3
		menu_num = menu();
	
		// Call Function 4
		calculation = operation(menu_num,num1,num2);
	
		// Call Function 5
		result(menu_num,num1,num2,calculation);
	
		printf("\n\nWould you like to use these numbers again (Y/N)? "); 
		scanf(" %c",&response);
		count++;
		
	} while (response == toupper('y'));
	
	

	return 0;
}
