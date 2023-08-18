/*A code on C Programming for Hotel Management*/
#include<stdio.h> /*header files*/
#include<conio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
void begin(); /*function declarations*/
void site_scene();
void show_details();
void feedback();
void restaurant();
void book_room();
void extra_facilities();
int billprice;
int main(){
	char name[20],address[100],email[100];
	int billprice=0,days;
	long phno;
	printf("Please enter your details before you move ahead.\n");
	FILE *fp;
	fp=fopen("customer.txt", "w+");
	printf("please enter your name:");
	gets(name);
	printf("enter your address:"); 
	gets(address);
	printf("Enter your phone no:");
	scanf("%ld", &phno);
	printf("enter your email_id:");
	fflush(stdin);
	gets(email);
	printf("How many days you want to stay: ");
	scanf("%d", &days);
	fprintf(fp,"--------------CUSTOMER DETAILS----------------");
	fprintf(fp,"\nName: %s",name);
	fprintf(fp,"\nAddress: %s",address);
	fprintf(fp,"\nEmail: %s",email);
	fprintf(fp,"\nPhone Number: %ld",phno);
	fprintf(fp,"\nNo. of days of stay: %d",days);
	fclose(fp);
    begin();
    return 0;
 }
void begin(void){
 int decide;
 printf("\n*********************WELCOME TO CITY LAKE************************\n");
 printf("\n How can we help you?\n\n");
 printf("\n1.about us\n2.Book a room\n3.Site_scene\n4.Restaurant\n5.Extra Facilities\n6.show my details\n7.Feedback\n8.check out\n9.Exit\n");
 scanf("%d",&decide);
 switch(decide)
 {
 case 1:
	 printf("CITY LAKE RESORT\n");
	 printf("Our resort is situated besides a beautiful water body.");
	 printf("Our resort provides adventurous activities like Jungle Safari, Horse riding , and much more. ");
	 printf("Enjoying the spectacular sunset by relaxing on our rugged cottages");
	 printf("is the memorable experience you could enjoy only at CITY LAKE RESORT. \n");
	 printf("Clean and Comfortable room, Hot and Cold Water facilities, beautiful garden, family environment, local food are our salient features.");
	 printf("We hope you enjoy your stay!\n");
	 begin();
	 break;
 
 case 2:
	 book_room();
	 begin();
	 break;
 case 3:
 	site_scene();
    begin();
    break;
 case 4:
 	restaurant();
    begin();
    break;
 case 5:
 	extra_facilities();
    begin();
    break;
 case 6:
 	show_details();
    begin();
    break;
 case 7:
 	feedback();
    printf("Thank you for your valuable suggestions!\n");
    begin();
    break;
 case 8:
	 printf("Visit again!");
	 printf("Thank you for trusting our service.\n");
	 break;
 case 9:
 	exit(1);
 }
}
void book_room(void){
    system("cls");
    int room_no;
    FILE *fp;
	fp=fopen("customer.txt", "a+");
	
 	printf("\nWhat type of room do u want to book?\n");
	printf("\n1.Basic Room(Double bed, Attached Showerroom , Essential Furniture ,Electronic items:Tv,DVD,AC,Telephone) Rs 1000\n2.Deluxe room(Basic+Lake side view,2 rooms) Rs 2000\n3.Super Deluxe room(villa) Rs 3000\n4.I don't want to choose anything\n");
    int type_of_rooms;
	char ch,c;
    scanf("%d",&type_of_rooms);
    fflush(stdin);
	printf("\nDo you accept this room?(y/n)\n");
	fflush(stdin);
	scanf("%c",&c);
	if (c=='y'){
		if(type_of_rooms==1){
			system("cls");
			printf("\nYou choose basic room. Enjoy your stay\n");
			srand(time(0));
			room_no=(rand()%(201-100+1))+100;
			printf("your room no is %d", room_no);
			char roomtype[50];
			fprintf(fp,"Room type: basic",roomtype);
			billprice += 1000;
			
		    begin();
		}
		else if(type_of_rooms==2){
			system("cls");
			printf("\nYou choose deluxe room. Enjoy your stay\n");
			srand(time(0));
			room_no=(rand()%(301-202+1))+202;
			printf("your room no is %d", room_no);
			fprintf(fp,"Room type: deluxe");
			billprice += 2000;
			
		    begin();
	    }
	    else if(type_of_rooms==3){
	    	system("cls");
			printf("\nYou choose super deluxe room. Enjoy your stay\n");
			srand(time(0));
			room_no=(rand()%(401-302+1))+302;
			printf("your room no is %d", room_no);
			fprintf(fp,"Room type: super deluxe");
			billprice += 3000;
			
		    begin();
		}
		else if(type_of_rooms==4){
			system("cls");
			printf("\nYou choose no room.\n");
			begin();
		}
		else{
			begin();
		}
		
	}
	else if (c=='n'){
		begin();
	}
	
	fclose(fp);
}
void site_scene(void){
	 system("cls");
	 int p;
	 
	 FILE *fp;
	fp=fopen("customer.txt", "a+");
	while(1){
	
	 printf("\nWhich program do you want to choose?\n");
	 printf("\n 1.Jungle Safari(Rs 1000) \n 2.Sunset point(Rs 2000)\n 3.Horse ride(Rs 800) \n 4.Laser show(Rs 1000)\n ");
	 scanf("%d",&p);
	 switch(p){
	 case 1:
	 system("cls");
	 printf("\nYou choose jungle Safari\n");
	 
	 fprintf(fp,"jungle safari");
	 billprice += 1000;
	 char a;
		printf("Do you want to add other site scene(y/n)?");
		fflush(stdin);
		scanf("%c", &a);
		if(a=='y' ||a=='Y'){
		continue;
		}
		else{
			begin();
			break;
		}
	 
	 break;
	 case 2:
	 printf("\nYou choose sunset point\n");
	 fprintf(fp,"sunset point");
	 billprice += 2000;
	 char a1;
		printf("Do you want to add other site scene(y/n)?");
		fflush(stdin);
		scanf("%c", &a1);
		if(a1=='y' ||a1=='Y'){
		continue;
		}
		else{
			begin();
			break;
		}
	 break;
	 case 3:
	 printf("\nYou choose Horse ride\n");
	 billprice+= 800;
	 fprintf(fp,"horse ride");
	 char a2;
		printf("Do you want to add other site scene(y/n)?");
		fflush(stdin);
		scanf("%c", &a);
		if(a2=='y' ||a2=='Y'){
		continue;
		}
		else{
			begin();
			break;
		}
	 break;
	 case 4:
	 printf("\nYou choose laser show\n");
	 billprice+= 1000;
	 fprintf(fp,"laser show");
	 char a3;
		printf("Do you want to add other site scene(y/n)?");
		fflush(stdin);
		scanf("%c", &a);
		if(a3=='y' ||a3=='Y'){
		continue;
		}
		else{
			begin();
			break;
		}
	 break;
	 default:
	 begin();
	 
	 fclose(fp);
    }
}
}
void show_details(void){
 system("cls");
 char details[500];
 FILE *fp;
 fp=fopen("customer.txt", "a+");
 
 if(fp == NULL){
 printf("file cant be opened\n");
 }
 else{
 	printf("You can view your details in the customer.txt file!");
 	
    printf("Totalbill:%d\n",billprice);
    begin();
 }
 fclose(fp);
}
void feedback(void){
 system("cls");
 char complain[500];
 int rate;
 
 FILE *fp1;
 fp1 = fopen("feedback.txt","a+");
 if(fp1 == NULL){
 printf("file cant be opened\n");
 }
 while(1){
 
 printf("please enter your complaints or suggestions: ");
 fflush(stdin);
 gets(complain);
 fputs(complain,fp1);

	 printf("\nhow much do you rate us:\n1-Poor\n2-Satisfactory\n3-Very Good\n4-Excellent\n5-ExtraOrdinary\n");
	 scanf("%d",&rate);
	 switch(rate)
	 {
	 case 1:
	 	fprintf(fp1,"\nRatings:Poor");
	    break;
	 case 2:
	 	fprintf(fp1,"\nRatings:Satisfactory");
	    break;
	 case 3:
	 	fprintf(fp1,"\nRatings:Very Good");
	    break;
	 case 4:
	 	fprintf(fp1,"\nRatings:Excellent");
	    break;
	 case 5:
	 	fprintf(fp1,"\nRatings:Extraordinary");
	    break;
	 default:
	 	printf("Enter number from 1 to 5");
	 	continue;
    }
    printf("Thank you for your valuable feedback!\n");
    break;
}
fclose(fp1);
}
void restaurant(){
	int choice1,choice2;
	FILE *fp;
	fp=fopen("customer.txt", "a+");
	while (1){
	printf("select your cuisine:\n1.North Indian\n2.South Indian\n3.Chinese\n4.Italian\n");
	printf("Enter your choice:");
	scanf("%d", &choice1);
	if (choice1==1){
		printf("Choose the available options\n1.Paneer bhurji Rs200\n2.Butter Naan Rs80\n3.Biryani Rs250\n");
		scanf("%d", &choice2);
		if (choice2==1){
			billprice+=200;
		
		}
		else if(choice2==2){
			billprice+=80;
		
		}
		else{
		    billprice+=250;
		}
		char a;
		printf("Do you want to add other food items?");
		scanf("%c", &a);
		if(a=='y'){
			continue;
		}
		else{
			begin();
			break;
		}	
	}
	else if(choice1==2){
		printf("Choose the available options\n1.Masala dosa Rs200\n2.Steam Idli Rs50\n3.Uttapam Rs150\n");
		scanf("%d", &choice2);
		if (choice2==1){
			billprice+=200;
		}
		else if(choice2==2){
			billprice+=50;
		}
		else{
		    billprice+=150;
		
		}
		char a;
		printf("Do you want to add other food items?");
		fflush(stdin);
		scanf("%c", &a);
		if(a=='y'){
			continue;
		}
		else{
			begin();
			break;
		}	
	}
	else if(choice1==3){
	    printf("Choose the available options\n1.Manchurian Rs250\n2.Noodles Rs200\n3.Chinese Bhel Rs250\n");
		scanf("%d", &choice2);
		if (choice2==1){
			billprice+=250;
			
		}
		else if(choice2==2){
			billprice+=200;
			
		}
		else{
		    billprice+=250;
		    
		}
		char a;
		printf("Do you want to add other food items?");
		scanf("%c", &a);
		if(a=='y'){
			continue;
		}
		else{
			begin();
			break;
		}
}
	
	else{
		printf("Choose the available options\n1.Pizza Rs250\n2.Pasta Rs120\n3.Macroni Rs200\n");
		scanf("%d", &choice2);
		if (choice2==1){
			billprice+=250;
			
		}
		else if(choice2==2){
			billprice+=120;
			
		}
		else{
		    billprice+=200;
		    
		}
		char a;
		printf("Do you want to add other food items?");
		fflush(stdin);
		scanf("%c", &a);
		if(a=='y' ||a=='Y'){
		continue;
		}
		else{
			begin();
			break;
		}
		
    }
	}
	fclose(fp);
}
void extra_facilities(){
 	printf("\nWhich facilities do want to choose?\n");
	printf("\n1.Game Zone Rs 800\n2.GYM Rs 300\n3.Theater Rs 350\n4.I don't want to choose anything\n");
    int facility;
	
	char ch,c;
	FILE *fp;
	fp=fopen("customer.txt", "a+");
    scanf("%d",&facility);
    fflush(stdin);
		if(facility==1){
			system("cls");
			printf("\nEnjoy gaming!");
			billprice += 800;
			
		    begin();
		}
		else if(facility==2){
			system("cls");
			printf("\nHappy Workout,Stay fit!\n");
			billprice += 300;
			
		    begin();
	    }
	    else if(facility==3){
	    	system("cls");
			printf("\nEnjoy Your movie!\n");
			billprice += 350;
			
		    begin();
		}
		else if(facility==4){
			begin();
		}
		else{
			begin();
		}
		fclose(fp);
	}


			

