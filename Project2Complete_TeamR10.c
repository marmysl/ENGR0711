#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

//Project 2: Part A and B
//R10: Maria Mysliwiec, Sead Niksic, Elizabeth Mountz 
//This program displays a menu of the inventory with item number, fruit, quantity of each fruit
// and selling and discount price for each fruit

// global variables
int quantity[20];
char fruit[10][20];
float selling[20];
float discount[20];

// printmenu function: formats the output of the inventory information
void printmenu(int num, char fruit[10][20], int quantity[20], float selling[20], float discount[20]) {
	int count;
	printf("\n******************************");
	printf("\n Item \t Fruit \t \t \t Quantity \t Price \t \t Sale");
	
	//prints information for each fruit using for loop
	for(count = 0; count<num; ++count){
		printf("\n %d \t %s \t \t %d \t \t $ %.2f \t $ %.2f", count, fruit[count], quantity[count] , selling[count], discount[count]);
	}
	printf("\n******************************\n");
}

// item_choice function: checks if user input is valid
int item_choice(int num){
	int fruitNum;
		do {
			printf("Please enter item to purchase: ");
			scanf("%d", &fruitNum);
		} while	(fruitNum > 4 || fruitNum < 0);
	return fruitNum;
}

// quant_choice function: prompts user to enter quantity of fruit to be purchased
int quant_choice(int fruitNum){
	int item_quantity=0;
		
	//loop will continue to prompt user for a quantity until the value in the appropriate region is entered
		do {
			printf("Please enter quantity [%d available]: ", quantity[fruitNum]);
			scanf("%d",&item_quantity);
		} while (item_quantity < 0 || item_quantity > quantity[fruitNum]);
	return item_quantity;
}

// update function: changes fruit quantity total in quantity array 
void update(int fruitNum, int item_quantity, int quantity[20]){
	quantity[fruitNum]= quantity[fruitNum] - item_quantity;
}

// uchoice function: prompts user to enter y or n and checks for user error 
char uchoice(void){
	char response;
		do {
			printf("Buy more fruit? (y/n): ");
			scanf(" %c",&response);
			response=tolower(response); // tolower function converts entered character to lowercase
		} while (response != 'y' && response != 'n');	// if user entered a character not equal to Y or N, loop repeats
	return response; 
}

int main() {
	//identify all variables
	char fname[100], response;
	FILE *fp, *fp2;
	int file_place, count = 0, fruitNum, item_quantity, purchasedquantity[5]={0,0,0,0,0};
	float total[20], sum=0;
	
	//print out introduction text
	printf("\nWelcome to Mena Mart.");
	printf("\nOne-stop shop for the best fruit in town!");
	printf("\nCustomer of the month: Francisca!\n");
	
	// do-while loop checks that the file entered exists
	
	do {
		printf("Please enter file name: ");
		scanf("%s", fname);
		fp = fopen(fname,"r");
	} while(fp == NULL);
	
	//print the name of the file that user wants to open
	printf("\n\nFile Selected: \"%s\"",fname);	
	
	//put information into separate arrays
	while (1) { //file_place holds the file scanning variable
			file_place = fscanf(fp,"%s %d %f %f", fruit[count], &quantity[count], &selling[count], &discount[count]);
			if(file_place == EOF) { break; }
			count = count +1;
			}	
	
	do {
		//call printmenu function	
		printmenu(count, fruit, quantity, selling, discount);
	
		//call item_choice function, which returns fruitNum variable (fruit index)
		fruitNum=item_choice(count);
	
		// call quant_choice function, which returns item_quantity variable  (quantity purchased by user)
		item_quantity=quant_choice(fruitNum);
		
		// call update function
		update(fruitNum, item_quantity, quantity);
	
		// update user basket for receipt; purchasedquantity array contains each amount purchased per fruit 
		purchasedquantity[fruitNum]=purchasedquantity[fruitNum]+item_quantity;
	
		// call uchoice function, which returns user response
		response = uchoice();
	
	} while (response == 'y'); // repeats process if user wants to purchase more fruit
	
	// Display Receipt
	printf("Thank you for shopping!\n\n");
	printf("Receipt\n");
	
	// for loop calculates total price for fruit purchased
	for (int j=0; j < count; j++) {	
		total[j]=discount[j]*purchasedquantity[j]; //price per each type of fruit
		sum = sum + total[j]; // total price
		
		if (purchasedquantity[j] > 0) { //will show user amount of fruit they purchased and its cost
			printf("Purchased %d %s for a total of $ %.2f\n",purchasedquantity[j],fruit[j],total[j]);
		}
	}
		printf("\t\tTotal = $%.2f",sum); // display total
	
	// Create file that will contain updated quantities of fruit in the same format as inventory.txt
	fp2=fopen("updated.txt","w");
	fprintf(fp2,"\n******************************");
	fprintf(fp2,"\n Item \t Fruit \t \t \t Quantity \t Price \t \t Sale");
	
	for(count = 0; count<5; ++count){
		fprintf(fp2, "\n %d \t %s \t \t %d \t \t $ %.2f \t $ %.2f", count, fruit[count], quantity[count] , selling[count], discount[count]);
	}
	fprintf(fp2, "\n******************************\n");
	
	//Close files
	fclose(fp2);
	fclose(fp);
	
	return(0);
}
