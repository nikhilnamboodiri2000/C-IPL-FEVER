/*Code Author: Devansh Shah & Nikhil Namboodiri
  Guided by: Professor Vaibhav Vasani
  College: K.J. Somaiya College Of Engineering
  Date: 06/05/2019*/ 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>      
#include<time.h> 	//Used for using time functions in program

typedef struct player   //Defining structure to store player and team details
{
 char tname[40];        //Team name
 char pname[6][40];     //Player name
 int pruns[6];          //Player Runs
 int pwickets[6];       //Plater Wickets
 int truns;             //Team Runs
 int twickets;          //Team Wickets
 int t_wins;            //Team Wins
 int t_losses;          //Team Losses
}A;

//Defining functions for various Purposes
void display(A );
int match(A ,A );
A input(A );
void intro();
void result();
void trophy();

A p[3];
int i,j,k,c=0;
int tempo;
char ch;
A temp;

int main()
{
	intro();
	//Input Team Details
	printf("Please Enter Character as first input not a number\n");
	p[0]=input(p[0]);
	p[1]=input(p[1]);
	p[2]=input(p[2]);

	system("cls || clear");

	//Initializing variables
	p[0].t_wins=0;
	p[0].t_losses=0;
	p[1].t_wins=0;
	p[1].t_losses=0;
	p[2].t_wins=0;
	p[2].t_losses=0;

	//Matches begins

	srand(time(NULL));//Used for initializing rand function 

		for(i=0;i<2;i++)
		{
			for(j=i;j<2;j++)
			{
				printf("Match Between %s and %s\n",p[i].tname,p[j+1].tname);
				k=match(p[i],p[j+1]);
				//Counting Wins and Losses
				if(k==1)
				{
					p[j+1].t_wins++;
					p[i].t_losses++;
				}
				else
				{
					p[i].t_wins++;
					p[j+1].t_losses++;
				}

				printf("Enter '0' for next match\n");
				scanf("%d",&tempo);
				printf("\n");
				if(tempo==0)
				k++;
				else
				exit(0);
			}
		}
		for(i=0;i<2;i++)
		{
			for(j=i;j<2;j++)
			{
				printf("Match Between %s and %s\n",p[i].tname,p[j+1].tname);
				k=match(p[i],p[j+1]);
				if(k==1)
				{
					p[j+1].t_wins++;
					p[i].t_losses++;
				}
				else
				{
					p[i].t_wins++;
					p[j+1].t_losses++;
				}
				if(k<4)
				{
					printf("Enter '0' for next match\n");
					scanf("%d",&tempo);
					printf("\n");
					if(tempo==0)
					{
						k++;
					}
					else
					{
						printf("Wrong input\n");
						exit(0);
					}
				}
			}
		}

	for(i=0;i<2;i++)
	{
		for(j=i;j<2;j++)
		{
			if(p[j].t_wins==p[j+1].t_wins)
			{
				printf("Match Between %s and %s\n",p[j].tname,p[j+1].tname);
				k=match(p[i],p[j+1]);
				if(k==1)
				{
					p[j+1].t_wins++;
					p[i].t_losses++;
				}
				else
				{
					p[i].t_wins++;
					p[j+1].t_losses++;
				}
			}
		}
	}
	printf("Click space key to Display Results\n"); //Click Space Then Click Enter
	getc(stdin);
	scanf("%c",&ch);
	if(ch==32)
	{
		//Final Results

    		printf("FINAL RESULTS\n");
		printf("\n\n");
		for(i=0;i<3;i++)
		{
			printf("%s won %d Matches and lost %d matches\n",p[i].tname,p[i].t_wins,p[i].t_losses);
		}

		for(i=0;i<3;i++)
		{
			for(j=0;j<3-i-1;j++)
			{
				if(p[j].t_wins<p[j+1].t_wins)
				{
					temp=p[j];
					p[j]=p[j+1];
					p[j+1]=temp;
				}
			}
		}
		result();
	}
	else
	{
		printf("Wrong input\n");
		exit(0);
	}
return 0;
}

void intro()
	{
	int a;
		printf("\t\t\t\t**********WELCOME EVERYONE TO THE NDT20 LEAGUE**********\n\n\n");
		printf("The project was made by:\n1.DEVANSH SHAH 1811111\n2.NIKHIL NAMBOODIRI 1811126\nGuided by: Proffesor Vaibhav Vasani\nCollege: KJSCE\nDate of Performance: 06/05/2019\n\n\n");
		printf("\t\t\t\t\t***********DISCLAIMER**********\n\n");
		printf("ALL PLAYERS APPEARING IN THIS LEAGUE ARE FICTITIOUS\n");
		printf("ANY RESEMBALNCE TO REAL PERSONS,PLAYING WELL OR BAD ,IS PURELY COINCIDENTAL.\n");
		printf("THIS PROGRAM IS A REALISTIC DEPICTION OF THE IPL LEAGUE NONE OF WHAT YOU ARE SEEING IS ACTUALLY HAPPENING\n\n\n\n");
		printf("\t\t\t\t\t******INSTRUCTIONS******\n");
		printf("1.The user is required to enter the team name\n");
		printf("2.The user is required to then enter the names of four batsmen and two bowlers\n");
		printf("3.The user has to press 0 to see the results of succeeding match\n");
		printf("4.The ranking of each team will be displayed at the end based on the results\n\n");

	}

A input(A a)
  {
	int i;
	int temp1;
	printf("Enter team Name\n");
	scanf("%d",&temp1);
	scanf("%[^\n]",a.tname);
	printf("Enter Details for the team %s\n",a.tname);
	printf("Enter the name of 4 Batsmen\n");
	for(i=0;i<4;i++)
	{
		scanf("%d",&temp1);
		scanf("%[^\n]",a.pname[i]);
	}
	printf("Enter the name of 2 bowlers\n");
	for(i=4;i<6;i++)
	{
		scanf("%d",&temp1);
		scanf("%[^\n]",a.pname[i]);
	}
	printf("\n");
	return a;
  }
int match(A a,A b)
  {
	int i,j;

	//rand function generates random values in a specified range
	a.twickets=0;
	for(i=4;i<6;i++)
	{
		a.pwickets[i]=rand()%3+1;
		a.twickets+=a.pwickets[i];
	}
	b.twickets=0;
	for(i=4;i<6;i++)
	{
		b.pwickets[i]=rand()%3+1;
		b.twickets+=b.pwickets[i];
	}
	a.truns=0;
	for(i=0;i<b.twickets;i++)
	{
		a.pruns[i]=rand()%61;
		a.truns+=a.pruns[i];
	}
	b.truns=0;
	for(i=0;i<a.twickets;i++)
	{
		b.pruns[i]=rand()%61;
		b.truns+=b.pruns[i];
	}

	printf("____________________________________________________________________________________________________________________________________________________________________\n");
	display(a);
	display(b);

	if(b.truns>a.truns)
	{
		printf("%s won the match\n\n\n",b.tname);
		return 1;
	}
	else
	{
		printf("%s won the match\n\n\n",a.tname);
		return 0;
	}
	printf("____________________________________________________________________________________________________________________________________________________________________\n");


}

void display(A a)
{
int k,i;
	printf("Team: %s\n",a.tname);
	printf("Team runs: %d\n",a.truns);
	printf("Wickets taken by Team: %d\n",a.twickets);
	printf("\t\t\t\tPlayer Name\t\t\t\tPlayer Runs\t\t\t\tPlayer Wickets\n");
	for(k=0;k<4;k++)
	{
		printf("\t\t\t\t%s",a.pname[k]);
		for(i=0;i<15-strlen(a.pname[k]);i++)
		{
			printf(" ");
		}
		printf("\t\t\t\t%d\n",a.pruns[k]);
	}
	for(k=4;k<6;k++)
	{
		printf("\t\t\t\t%s",a.pname[k]);
		for(i=0;i<15-strlen(a.pname[k]);i++)
		{
			printf(" ");
		}
		printf("\t\t\t\t%d",a.pruns[k]);
		for(i=0;i<13;i++)
		{
			printf(" ");
		}
		printf("\t\t\t\t%d\n",a.pwickets[k]);
	}
    }

void result()
{
	printf("\n\n");
	
	//Displaying Final Ranks
	printf("----------Ranking----------\n");
	printf("1st : %s\n",p[0].tname);
	printf("2nd : %s\n",p[1].tname);
	printf("3rd : %s\n\n\n",p[2].tname);
	printf("*********************  NDT20LEAGUE WON BY %s  ********************\n\n",p[0].tname);
	
	//Printing Trophy 
	trophy();
	printf("\n\n");


}
void trophy()
{
	int i,j,k,c,h1,h2,c1,space1,space2,space3;
	int space=4;
	for(i=0;i<5;i++)
	{
		for(k=0;k<20;k++)
		{
			printf(" ");
		}
		for(j=0;j<space;j++)
		{
			printf(" ");
		}
		for(j=0;j<=i;j++)
		{
			printf("* ");
		}
		printf("\n");
		space--;
	}
	space=20;
	for(i=0;i<2;i++)
	{
		for(j=0;j<space;j++)
		{
		printf(" ");
		}
		for(k=0;k<5;k++)
		{
			printf("* ");
		}
		printf("\n");
	}
	space=18;
	c=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<space;j++)
		{
			printf(" ");
		}
		for(k=0;k<7+c;k++)
		{
			printf("* ");
		}
		space=space-2;
		c=c+2;
		printf("\n");
	}

	space=11;
	space1=7;
	space2=0;
	space3=4;
	c=0;
	c1=4;
	for(i=0;i<7;i++)
	{
		if(i<=3)
		{
			for(h1=0;h1<space;h1++)
			{
				printf(" ");
			}
			printf("** ");
			space=space-2;
			for(j=0;j<c;j++)
			{
				printf(" ");
			}
			for(k=0;k<11;k++)
			{
				printf("* ");
			}
			c=c+2;

			for(h2=0;h2<space2;h2++)
			{
				printf(" ");
			}
			printf("**");
			space2=space2+2;
			printf("\n");
		}
		else
		{
			for(h1=0;h1<space1;h1++)
			{
				printf(" ");
			}
			printf("** ");
			space1=space1+2;
			for(j=0;j<c1;j++)
			{
				printf(" ");
			}
			for(k=0;k<11;k++)
			{
				printf("* ");
			}
			c1=c1-2;

			for(h2=0;h2<space3;h2++)
			{
				printf(" ");
			}
			printf("**");
			space3=space3-2;
			printf("\n");
		}
	}
	space=14;
	c=0;
	for(i=0;i<4;i++)
	{
		for(j=0;j<space;j++)
		{
			printf(" ");
		}
		for(k=0;k<11-c;k++)
		{
			printf("* ");
		}
		space=space+2;
		c=c+2;
		printf("\n");
	}
	space=22;
	for(i=0;i<5;i++)
	{
		for(j=0;j<space;j++)
		{
		printf(" ");
		}
		for(k=0;k<3;k++)
		{
			printf("* ");
		}
		printf("\n");
	}
	space=6;
	c=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<space;j++)
		{
			printf(" ");
		}
		for(k=0;k<19+c;k++)
		{
			printf("* ");
		}
		c=c+2;
		space=space-2;
		printf("\n");
	}

}
