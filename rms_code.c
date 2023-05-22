#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void menu(void);
int import_codes(char[]);
int import_names(char[]);
void ticket_reservation(void);
void ticket_cancellation();
void ticket_availability();
void trains_details();
void food_service(float);
void medical_service();
void book_service(float);
void tickets(int);
void _2s(int);
void _1AC(int);
void _2AC(int);
void _3AC(int);
void _S(int);
int reserve(char[]);
void seats(int);
int search(char[],int);
int total_seats();
int reserved_seats();
struct trains
{
	char train[30];
	char temp[30];
}t;
struct ticket
{
	char name[60];
	char age[5];
	char ticket[30];
	char reserved[30];
}s;
char reserved[60][5];
void main()
{
	printf("\t\t\t ***WELCOME*** \t\t\t\n");
	printf("\n\t\t----TELANGANA RAILWAY SERVICES----\t\t\n");
	menu();
}
void menu()
{
	printf("\n\tOUR SERVICES\n");
	printf("\n\t1-< Tickets Booking >\n");
	printf("\n\t2-< Ticket cancellation >\n");
	printf("\n\t3-< Ticket availability >\n");
	printf("\n\t4-< Trains details >\n");
	printf("\n\t5-< Food service >\n");
	printf("\n\t6-< Book service >\n");
	printf("\n\t7-< Medical emergency >\n");
	int key;
	printf("\n\tPress key corresponding to your requirement:");
	scanf("%d",&key);
	if(key==1)
		ticket_reservation();
	else if( key==2)
		ticket_cancellation();
	else if(key==3)
		ticket_availability(); 
	else if(key==4)
		trains_details();
	else if(key==5)
		food_service(0);
	else if(key==6)
		book_service(0);
	else if(key==7)
		medical_service();
	else
		printf("Select one among 1 to 8"); 
}
void ticket_reservation()
{
	int n;
	char train_code[5],train_name[30];
	printf("\n\tSearch by train number or train name\n");
	printf("\n\t1-< Train number >\n");
	printf("\n\t2-< Train name >\n");
	printf("\n\tEnter key:");
	scanf("%d",&n);
	if(n==1)
	{
		printf("\n\tEnter train code:");
		scanf("%s",train_code);
		int c;
		if(c=import_codes(train_code))
			tickets(c-1);
		else
		{
		printf("\n\tDo you want to exit :");
		char con[5];
		scanf("%s",con);
		if(!strcmpi(con,"yes"))
			exit(0);
		else
			menu();
		}
	}
	else if(n==2)
	{
		printf("\n\tEnter train name: ");
		scanf("%s",train_name);
		int c;
		if(c=import_names(train_name))
			tickets(c-1);
		else
		{
			printf("\n\tDo you want to exit :");
			char con[5];
			scanf("%s",con);
			if(!strcmpi(con,"yes"))
				exit(0);
			else
				menu();
		}
	}
	else
		printf("\n\tPlease enter valid key");
}
int import_codes(char train_code[])
{
	FILE *fptr1;
	struct trains t[60];
	int i=0,j=0;
	char check[5];
	fptr1=fopen("Train_Codes.txt","r");
	if(fptr1==NULL)
	{
		printf("File is not opened\n");
		exit(0);
	}
	else
	{
		strcpy(check,"NotExist");
		while((fscanf(fptr1,"%s",t[j].temp))!=EOF)
		{
			strcpy(t[i++].train,t[j].temp);
			j++;
		}
		for(i=0;i<6;i++)
		{
			if(!strcmpi(t[i].train,train_code))
			{
				strcpy(check,"Exist");
				printf("\n\tDo you want to book tickets for this train of code %s yes/no :",train_code);
				char con[5];
				scanf("%s",con);
				if(!strcmpi(con,"yes"))
					return i+1;	
				else
					return 0;
			}
		}
		if(!strcmpi(check,"NotExist"))
		{
			printf("\n\tNo train is found with this reference\n");
			return 0;
		}
	}
}
int import_names(char train_name[])
{
	FILE *fptr2;
	struct trains t[60];
	int i=0,j=0;
	char check[5];
	fptr2=fopen("Train_Names.txt","r");
	if(fptr2==NULL)
	{
		printf("File is not opened\n");
		exit(0);
	}
	else
	{
		strcpy(check,"NotExist");
		while((fscanf(fptr2,"%s",t[j].temp))!=EOF)
		{
			strcpy(t[i++].train,t[j].temp);
			j++;
		}
		for(i=0;i<6;i++)
		{
			if(!strcmpi(t[i].train,train_name))
			{
				strcpy(check,"Exist");
				printf("\n\tDo you want to book tickets for this train of name %s yes/no :",train_name);
				char con[5];
				scanf("%s",con);
				if(!strcmpi(con,"yes"))
					return i+1;	
				else
					return 0;
			}
		}
		if(!strcmpi(check,"NotExist"))
		{
			printf("\n\tNo train is found with this reference\n");
			return 0;
		}
	}
}
void tickets(int c)
{
	int key,n;
	printf("\n\t1-< 2S >\n");
	printf("\n\t2-< 1AC >\n");
	printf("\n\t3-< 2AC >\n");
	printf("\n\t4-< 3AC >\n");
	printf("\n\t5-< Sleeper >\n");
	printf("\n\tSelect category:");
	scanf("%d",&key);
	if(key==1)
		_2s(c);
	else if(key==2)
		_1AC(c);
	else if(key==3)
		_2AC(c);
	else if(key==4)
		_3AC(c);
	else if(key==5)
		_S(c);
	else
		printf("\n\tEnter valid key\n");
}
void _2s(int c)
{
	FILE *fptr3;
	struct trains t[60];
	int i=0,j=0;
	char check[5];
	fptr3=fopen("Train_2S.txt","r");
	if(fptr3==NULL)
	{
		printf("File is not opened\n");
		exit(0);
	}
	else
	{
		strcpy(check,"NotExist");
		while((fscanf(fptr3,"%s",t[j].temp))!=EOF)
		{
			strcpy(t[i++].train,t[j].temp);
			j++;
		}
	}
	for(i=0;i<6;i++)
	{
		if(c==i)
		{
			printf("\n\tHow many seats you want to reserve:");
			int n;
			scanf("%d",&n);
			seats(n);
			printf("\n\tTotal cost == %d\n",n*atoi(t[i].train));
			break;
		}
	}
	char con[5];
    printf("\n\tDo you want to exit yes/no :");
    scanf("%s",&con);
    if(!strcmpi(con,"yes"))
    	exit(0);
    else
    	menu();
}
void _1AC(int c)
{
	FILE *fptr3;
	struct trains t[60];
	int i=0,j=0;
	char check[5];
	fptr3=fopen("Train_1AC.txt","r");
	if(fptr3==NULL)
	{
		printf("File is not opened\n");
		exit(0);
	}
	else
	{
		strcpy(check,"NotExist");
		while((fscanf(fptr3,"%s",t[j].temp))!=EOF)
		{
			strcpy(t[i++].train,t[j].temp);
			j++;
		}
	}
	for(i=0;i<6;i++)
	{
		if(c==i)
		{
			printf("\n\tHow many seats you want to reserve:");
			int n;
			scanf("%d",&n);
			seats(n);
			printf("\n\tTotal cost == %d\n",n*atoi(t[i].train));
			break;
		}
	}
	char con[5];
    printf("\n\tDo you want to exit yes/no :");
    scanf("%s",&con);
    if(!strcmpi(con,"yes"))
    	exit(0);
    else
    	menu();
}
void _2AC(int c)
{
	FILE *fptr3;
	struct trains t[60];
	int i=0,j=0;
	char check[5];
	fptr3=fopen("Train_2AC.txt","r");
	if(fptr3==NULL)
	{
		printf("File is not opened\n");
		exit(0);
	}
	else
	{
		strcpy(check,"NotExist");
		while((fscanf(fptr3,"%s",t[j].temp))!=EOF)
		{
			strcpy(t[i++].train,t[j].temp);
			j++;
		}
	}
	for(i=0;i<6;i++)
	{
		if(c==i)
		{
			printf("\n\tHow many seats you want to reserve:");
			int n;
			scanf("%d",&n);
			seats(n);
			printf("\n\tTotal cost == %d\n",n*atoi(t[i].train));
			break;
		}
	}
	char con[5];
    printf("\n\tDo you want to exit yes/no :");
    scanf("%s",&con);
    if(!strcmpi(con,"yes"))
    	exit(0);
    else
    	menu();
}
void _3AC(int c)
{
	FILE *fptr3;
	struct trains t[60];
	int i=0,j=0;
	char check[5];
	fptr3=fopen("Train_3AC.txt","r");
	if(fptr3==NULL)
	{
		printf("File is not opened\n");
		exit(0);
	}
	else
	{
		strcpy(check,"NotExist");
		while((fscanf(fptr3,"%s",t[j].temp))!=EOF)
		{
			strcpy(t[i++].train,t[j].temp);
			j++;
		}
	}
	for(i=0;i<6;i++)
	{
		if(c==i)
		{
			printf("\n\tHow many seats you want to reserve:");
			int n;
			scanf("%d",&n);
			seats(n);
			printf("\n\tTotal cost == %d\n",n*atoi(t[i].train));
			break;
		}
	}
	char con[5];
    printf("\n\tDo you want to exit yes/no :");
    scanf("%s",&con);
    if(!strcmpi(con,"yes"))
    	exit(0);
    else
    	menu();
}
void _S(int c)
{
	FILE *fptr3;
	struct trains t[60];
	int i=0,j=0;
	char check[5];
	fptr3=fopen("Train_S.txt","r");
	if(fptr3==NULL)
	{
		printf("File is not opened\n");
		exit(0);
	}
	else
	{
		strcpy(check,"NotExist");
		while((fscanf(fptr3,"%s",t[j].temp))!=EOF)
		{
			strcpy(t[i++].train,t[j].temp);
			j++;
		}
	}
	for(i=0;i<6;i++)
	{
		if(c==i)
		{
			printf("\n\tHow many seats you want to reserve:");
			int n;
			scanf("%d",&n);
			seats(n);
			printf("\n\tTotal cost == %d\n",n*atoi(t[i].train));
			break;
		}
	}
	char con[5];
    printf("\n\tDo you want to exit yes/no :");
    scanf("%s",&con);
    if(!strcmpi(con,"yes"))
    	exit(0);
    else
    	menu();
}
void seats(int n)
{
	struct trains t[200];
	struct ticket s[200];
	FILE *fptr,*fptr1;
	int k,i=0,j=0;
	fptr=fopen("Seats.txt","r");
	if(fptr==NULL)
	{
		printf("File is not opened\n");
		exit(0);
	}
	else
	{
		while((fscanf(fptr,"%s",t[j].temp))!=EOF)
		{
			strcpy(t[i++].train,t[j].temp);
			j++;
		}
		i=0;
		for(k=0;k<j;k++)
		{	
			int c;
			if(c=reserve(t[k].train) && search(t[k].train,i) && i<n)
			{
				strcpy(s[i].ticket,t[k].train);
				i++;
			}
		}
		for(k=0;k<n;k++)
		{
			printf("\n\tPerson-%d- name :",k+1);
			scanf("%s",s[k].name);
			printf("\n\tPerson-%d- age :",k+1);
			scanf("%s",s[k].age);
		} 
		printf("\n\tYour tickets are successfully booked and seats are\n");
		for(i=0;i<n;i++)
			printf("\n\t%s----%s\n",s[i].name,s[i].ticket);
		FILE *fptr1;
		int i=0,j=0;
		fptr1=fopen("Reserved.txt","r");
		if(fptr1==NULL)
		{
			printf("File is not opened\n");
			exit(0);
		}
		else
		{
			while((fscanf(fptr1,"%s",s[j].reserved))!=EOF)
				j++;
		}
		fclose(fptr1);
		for(i=0;i<n;i++)
			strcpy(s[j++].reserved,s[i].ticket);
		fptr1=fopen("Reserved.txt","w");
		for(i=0;i<j;i++)
			fprintf(fptr1,"%s\n",s[i].reserved);
		fclose(fptr1);
	}
	fclose(fptr);
}
int reserve(char seat[])
{
	struct ticket s[200];
	FILE *fptr;
	int i=0,j=0;
	fptr=fopen("Reserved.txt","r");
	if(fptr==NULL)
	{
		printf("File is not opened\n");
		exit(0);
	}
	else
	{
		while((fscanf(fptr,"%s",s[j].reserved))!=EOF)
			j++;
	}
	fclose(fptr);
	for(i=0;i<j;i++)
	{
		if(!strcmpi(s[i].reserved,seat))
			return 0;
	}
	return 1;
}
int search(char seat[],int i)
{
	struct ticket s[200];
	int j=0;
	for(j=0;j<i;j++)
	{
		if(!strcmpi(s[j].ticket,seat))
			return 0;
	}
	return 1;
} 

void ticket_cancellation()
{
	int n,i;
	struct ticket s[30];
	printf("\n\tHow many tickets you want to cancel:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n\tTicket-%-:",i+1);
		scanf("%s",&s[i].ticket);
	}
	FILE *fptr;
	int j=0;
	fptr=fopen("Reserved.txt","r");
	if(fptr==NULL)
	{
		printf("File is not opened\n");
		exit(0);
	}
	else
	{
		while((fscanf(fptr,"%s",s[j].reserved))!=EOF)
			j++;
	}
	fclose(fptr);
	for(i=0;i<j;i++)
	{
		int k;
		for(k=0;k<n;k++)
		{
			if(!strcmpi(s[i].reserved,s[k].ticket))
			{
				strcpy(s[i].reserved,"");
			}
		}
	}
	fptr=fopen("Reserved.txt","w");
	for(i=0;i<j;i++)
	{	
		if(!strcmpi(s[i].reserved,""))
			continue;
		else
			fprintf(fptr,"%s\n",s[i].reserved);
	} 
	printf("\n\tYour tickets cancelled");
	char con[5];
    printf("\n\tDo you want to exit yes/no :");
    scanf("%s",&con);
    if(!strcmpi(con,"yes"))
    	exit(0);
    else
    	menu();
}
void trains_details()
{
	struct trains t[1000];
	FILE *fptr;
	int i,j;
	fptr=fopen("Train_details.txt","r");
	if(fptr==NULL)
	{
		printf("File is not opened\n");
		exit(0);
	}
	else
	{
		int i=0,j=0;
		while((fscanf(fptr,"%s",t[j].temp))!=EOF)
		{
			strcpy(t[i++].train,t[j].temp);
			j++;
		}
		int c=0;
		printf("\n\t----------------------------------------------------------------------------------------");
		printf("\n\t\t\t\t\tTRAINS----DETAILS");
		printf("\n\t----------------------------------------------------------------------------------------");
		printf("\n\tTRAIN CODE\tTRAIN NAME\t\tTIMIGS\t\t\tBOR-DES\t\tCHARGES");
		printf("\n\t----------------------------------------------------------------------------------------\n\n\t");
		for(i=0;i<j;i++)
		{
			if(c==0 )
			{
				printf("\n%s\t",t[i].train);
				c++;
			}
			else if(c==4)
			{
				printf("%s",t[i].train);
				c=0;
			}
			else
			{
				printf("%s\t\t",t[i].train);
				c++;
			}
		}
		fclose(fptr);
	}
	char con[5];
	printf("\n\n\tDo you want to exit: ");
	scanf("%s",&con);
	if(!strcmpi(con,"yes"))
		exit(0);
	else
		menu();
}
void ticket_availability()
{
	char train_ref[200];
	printf("\n\tEnter train code or train name: ");
	scanf("%s",&train_ref);
	printf("\n\tNo.of tickets available for this train of refernce %s  : %d seats",train_ref,total_seats()-reserved_seats());
}
int total_seats()
{
	struct trains t[200];
	FILE *fptr;
	int i=0,j=0;
	fptr=fopen("Seats.txt","r");
	if(fptr==NULL)
	{
		printf("File is not opened\n");
		exit(0);
	}
	else
	{
		i=0;
		int j=0;
		while((fscanf(fptr,"%s",t[j].temp))!=EOF)
		{
			strcpy(t[i++].train,t[j].temp);
			j++;
		}
		fclose(fptr);
		return j;
	}
}
int reserved_seats()
{
	struct trains t[200];
	FILE *fptr;
	int i=0,j=0;
	fptr=fopen("Seats.txt","r");
	if(fptr==NULL)
	{
		printf("File is not opened\n");
		exit(0);
	}
	else
	{
		i=0;
		int k=0;
		while((fscanf(fptr,"%s",t[k].temp))!=EOF)
		{
			strcpy(t[i++].train,t[k].temp);
			j++;
		}
		fclose(fptr);
		return k;
	}
}
void food_service(float cost)																
{
    int n,a,choice;
    printf("\n\tS.No\tfood-type\tPrice\t\tfood_item \n");
	printf("\n\t1\tLunch/Dinner\tRs100.00\tchicken Biryani\n");
	printf("\t\t\t\tRs50.00\t\tcurd rice\n");
	printf("\t2\tBreakfast\tRs30.00\t\tIdli,Vada,Dosa\n");
	printf("\t\t\t\tRs20.00\t\tpoori,upma\n");
	printf("\t3\tDrink\t\tRs20.00\t\tbuttermilk,tea\n");
	printf("\t\t\t\tRs30.00\t\tCooldrinks \n");
	printf("\t4\tsnacks\t\tRs20.00\t\tpopcorn ,chips\n");
    printf("\t\t \t\tRs30.00\t\tbiscuits,choclates\n");
	printf(" \t\t\t\tRs30.00\t\tIce cream\n");
	printf("\n\tSelect Your Option from Above Menu : ");
	scanf("%d",&n);
	if(n==1)
	{
           printf("\n\tselect which food item you want:\n");
           printf("\n\t1 chickenbiryani\t2 curd rice\n");
           printf("\n\tEnter your choice:");
           scanf("%d",&choice);  
	   if(choice==1)
           {
              cost+=100;;
           }
           else
           {
               cost+=50.00;
           }
	   printf("\n\tDo you want to add-on?(1-Yes, 2-No)");
	   scanf("%d",&a);
	   if (a==1)
	   {									
              food_service(cost);
	   }
	   else
           {				
             printf("\n\tThe Total is Rs%.2f\n\n",cost);
           }    
        }
	else if(n==2)
        { 
            printf("\n\tselect Which food item you want:\n");
            printf("\n\t1Idli\t2vada\t3Dosa\t4poori\t5upma\n");
            printf("\nEnter your choice:");
            scanf("%d",&choice); 
            if(choice==1 || choice==2 || choice==3)
            {
                cost+=30.00;
            }
            else
            {
                 cost+=20;
            }
	    printf("\n\tDo you want to add-on?(1-Yes, 2-No)");
	    scanf("%d",&a);
	    if (a==1)
	    {									
	       food_service(cost);
	    }
	    else
            {					
               printf("\n\tThe Total is Rs%.2f\n\n",cost);
            }
        }
        else if(n==3)  
        { 
           printf("\n\tselect which drink you want\n");
	   printf("\n\t1buttermilk\t2tea\t3cooldrinks\n");
           printf("\n\tEnter your choice:");
           scanf("%d",&choice);
           if(choice==1 || choice==2)
           {
              cost+=20;
           }
           else
           {
               cost+=30;
           }
	   printf("\n\tDo you want to add-on?(1-Yes, 2-No)");
	   scanf("%d",&a);
	   if (a==1)
	   {										
	      food_service(cost);
	   }
	   else
	   {					
               printf("\n\tThe Total is Rs%.2f\n\n",cost); 
           } 
        }
        else if(n==4)
        {
	   printf("\n\tSelect snacks you want:\n");
           printf("\n\t1popcorn\t2chips\t3biscuits\t4choclates\t5Icecream\n");
           printf("\nEnter your choice:");
	   scanf("%d",&choice);
           if(choice==1 || choice==2)
           {
               cost+=20;
           }
           else
           {
               cost+=30;
           }
	   printf("\n\tDo you want to add-on?(1-Yes, 2-No)");
	   scanf("%d",&a);
	   if(a==1)
	   {									
	      food_service(cost);
	   }
	   else
	   {					
               printf("\n\tThe Total is Rs%.2f\n\n",cost); 
           }  
        }
        else
        {
           printf("\n\tPlease select among 1 to 4:");
        }
    char con[5];
    printf("\n\tDo you want to exit yes/no :");
    scanf("%s",con);
    if(!strcmp(con,"yes"))
    	exit(0);
    else
    	menu();
}
void medical_service()																
{
	int n;
	printf("\n\tS.No\t\tHOSPITAL\t\t\tADDRESS\t\t\t\tCONTACT\n");
	printf("\n\t1\t\tMedicover Hospital\t\tHITECH City,Hyderabad\t\t040 3306 4381");
	printf("\n\t2\t\tAditya Hospital\t\t\tHanamkonda, Warangal\t\t040 3911 1333");
	printf("\n\t3\t\tKadimi Hospital\t\t\tGollegudam,Nalgonda\t\t741 0037 4369");
	printf("\n\t4\t\tApollo Hospitals\t\tKondapur,Hyderabad\t\t410 0373 0067");
	printf("\n\t5\t\tYeshoda Hospitals\t\tMalakpet, Hyderabad\t\t040 4567 4567\n");                       
	printf("\n\tPlese pick the hospital near to your location: ");
	scanf("%d",&n);
	if(n==1)
	{
           printf("\n\n\t-----calling-----");
           printf("\n\n\tPlease Wait for some time your call reached us");
    }
    else if(n==2)
	{
           printf("\n\n\t-----calling-----");
           printf("\n\n\tPlease Wait for some time your call reached us");
    }
    else if(n==3)
	{
           printf("\n\n\t-----calling-----");
           printf("\n\n\tPlease Wait for some time your call reached us");
    }
    else if(n==4)
	{
           printf("\n\n\t-----calling-----");
           printf("\n\n\tPlease Wait for some time your call reached us");
    }
    else if(n==5)
	{
           printf("\n\n\t-----calling-----");
           printf("\n\n\tPlease Wait for some time your call reached us");
    }
    else
        printf("\n\n\tplease Select among 1 to 5");
    char con[5];
    printf("\n\tDo you want to exit yes/no :");
    scanf("%s",&con);
    if(!strcmpi(con,"yes"))
    	exit(0);
    else
    	menu();
}
void book_service(float cost)																
{
	printf("\n\t<<Take a good book>>\n");
    int n,a;
    printf("\n\tS.No\t\tBOOKS\t\t\t\tPRICE\n");
    printf("\n\t1\t\tThe piligrim's Progress\t\tRs100.00 ");
    printf("\n\t2\t\tWings of fire\t\t\tRs130.00 ");
    printf("\n\t3\t\tMission of India\t\tRs120.00 ");
    printf("\n\t4\t\tSpirit of India\t\t\tRs130.00");
    printf("\n\t5\t\tThe luminous minds\t\tRs100.00 \n");                      
	printf("\n\tSelect a book from the above : ");
	scanf("%d",&n);
	if(n==1)
	{
        printf("\n\tPlease Enter how many books you want:");
    	scanf("%d",&n);    
	   	cost+=n*100.00;
	   	printf("\n\tDo you want to add-on?(1-Yes, 2-No)");
	   	scanf("%d",&a);
	   	if (a==1)
	   		book_service(cost);
	   else
           	printf("\n\tTotal cost is Rs%.2f\n\n",cost);   
    }
	else if(n==2)
    { 
	    printf("\n\tPlease Enter how many books you want :");
	    scanf("%d",&n);
        cost+= n*130.00;
	    printf("\n\tDo you want to add-on?(1-Yes, 2-No)");
	    scanf("%d",&a);
	    if (a==1)
	    	book_service(cost);
	    else
        	printf("\n\t Total cost is Rs%.2f\n\n",cost);
    }
    else if(n==3)  
    { 
	   printf("\n\tPlease Enter how many books you want :");
	   scanf("%d",&n);
	   cost+= n*120.00;
	   printf("\n\tDo you want to add-on?(1-Yes, 2-No)");
	   scanf("%d",&a);
	   if (a==1)
			book_service(cost);
	   else
	   		printf("\n\tThe Total cost is Rs%.2f\n\n",cost); 
    }
    else if(n==4)
    {
	   printf("\n\tPlease Enter how many books you want :");
	   scanf("%d",&n);
	   cost+=n*130.00;
	   printf("\n\tDo you want to add-on?(1-Yes, 2-No)");
	   scanf("%d",&a);
	   if(a==1)								
	   		book_service(cost);
	   else
	   		printf("\n\tThe Total cost is Rs%.2f\n\n",cost);
    }
    else if(n==5)
    { 
	    printf("\n\tPlease Enter how many books you want :");
	    scanf("%d",&n);
            cost+= n*1200.00;
	    printf("\n\tDo you want to add-on?(1-Yes, 2-No)");
	    scanf("%d",&a);
	    if (a==1)
	    	book_service(cost);
	    else
            printf("\n\tThe Total cost is Rs%.2f\n\n",cost);
    }
    else
        printf("please select among 1 to 5");
    char con[5];
    printf("\n\tDo you want to exit yes/no :");
    scanf("%s",&con);
    if(!strcmpi(con,"yes"))
    	exit(0);
    else
    	menu();
}

    
