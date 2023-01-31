#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<windows.h>

char name[20];
int prize[]={0,20000,40000,80000,160000,320000,640000,1250000,2500000,5000000,10000000,10000000};
static int qno=1;

void start()
{
    printf("\n\t\t\t\tWELCOME TO KAUN BANEGA CROREPATI.\n");
    printf("\n To Answer any question : \t\t\t\tAvailable lifelines :\n\n");
    printf("  Press 'a' to choose option A.\t\t\t\t 1.Double Dip.\n");
    printf("  Press 'b' to choose option B.\t\t\t\t 2.Expert Opinion.\n");
    printf("  Press 'c' to choose option C.\t\t\t\t 3.Replace Question.\n");
    printf("  Press 'd' to choose option D.\t\t\t\t 4.Audience Poll.\n");
    printf("\n\t\tTo Choose a lifeline in any Question press 'L' .\n\n");
    printf("\n Enter your name : ");
    gets(name);
    printf("\n");
    system("cls");
}

struct ques
{
	char q[100];
	char o1[75];
	char o2[75];
	char a[5];
}q1;
static int lline = 4;

void head()
{
    printf("\n\t\t\t\tWELCOME TO KAUN BANEGA CROREPATI.\n");
    printf("\nContestant Name : %s\t\t",name);
    printf("Prize money Won : %d\t\tRemaining lifelines : %d\n\n",prize[qno-1],lline);
}

void display()
{
	puts(q1.q);
	puts(q1.o1);
	puts(q1.o2);
}

int correct()
{

	printf("\n\nCORRECT ANSWER,  YOU WON Rs.%d .\n", prize[qno]);
	return 1;
}

int wrong()
{

	printf("\nWRONG ANSWER.\n");

	return 0;

}
int doubleDip()
{
    char a,b;
    printf("Enter 1st answer : \n");
    scanf("%c", &a);
    a=toupper(a);

    fflush(stdin);

    if(a==q1.a[0])
        return correct();
    else
    {
        printf("Wrong! Enter 2nd answer : \n");
        scanf("%c",&b);
        b=toupper(b);
        fflush(stdin);

        if(b==q1.a[0])
            return correct();
        else
            return wrong();
    }
}
int expertOpinion()
{
    char ans;
    printf("The Expert's advice recommends you to go with Option : %c .\n",q1.a[0]);
    printf("Enter your answer : ");
    scanf("%c",&ans);
    ans=toupper(ans);
    fflush(stdin);

    if(ans==q1.a[0])
        return correct();
    else
        return wrong();
}
int replaceQuestion()
{
    char ans;
    printf("\nBefore moving to the next question choose any one of the options of this question : ");
    scanf("%c",&ans);
    ans=toupper(ans);

    fflush(stdin);

    if(ans==q1.a[0])
        printf("It was the Correct Answer .\n");
    else
        printf("Wrong Answer, Correct option is : %c .\n\n",q1.a[0]);

    printf("Replaced Question is :\n\n");
    printf("Q%d.Which of these is the title of a film starring Akshay Kumar and Sonakshi Sinha?\n",qno);
    printf("\nA.Bajirao mastani\tB.Rowdy Rathore\nC.Khiladi 786\t\tD.Lakshmi Bomb\n");
    printf("\nEnter your answer : \n");
    scanf("%c",&ans);
    ans=toupper(ans);
    fflush(stdin);

    if(ans=='B')
        return correct();
    else
        return wrong();
}
int audiencePoll()
{
    printf("Audience Poll started!\nAudience have voted their opinion on the given question : \n");
    int vote1,vote2,vote3,vote4;
    char ans;
    if(q1.a[0]=='A')
    {
        vote1=57;
        vote2=31;
        vote3=8;
        vote4=4;
    }
    else if(q1.a[0]=='B')
    {
        vote1=31;
        vote2=57;
        vote3=8;
        vote4=4;
    }
    else if(q1.a[0]=='C')
    {
        vote1=8;
        vote2=31;
        vote3=57;
        vote4=4;
    }
    else
    {
        vote1=4;
        vote2=31;
        vote3=8;
        vote4=57;
    }
    printf("Option A = %d% \tOption B = %d% \n\nOption C = %d% \tOption D = %d%",vote1,vote2,vote3,vote4);
    printf("\nEnter your answer : ");
    scanf("%c",&ans);
    ans=toupper(ans);
    fflush(stdin);

    if(ans==q1.a[0])
        return correct();
    else
        return wrong();
}
int lifeline()
{
    int val;
	static int twoChances = 1, expOpinion = 1, repQues = 1,audPoll=1;
	lline--;

	printf("\nWhich lifeline would you like to use from the following?\n");
    if(twoChances==1)
        printf("1.Double Dip\t");
    if(expOpinion==1)
        printf("2.Expert Opinion\t");
    if(repQues==1)
        printf("3.Replace Question\t");
    if(audPoll==1)
        printf("4.Audience Poll");
    printf("\n");
    int ans;
    scanf("%d",&ans);
    fflush(stdin);
   if(ans==1 && twoChances == 1)
  {
        twoChances = 0;
       val= doubleDip();
  }
  else if(ans==2 && expOpinion == 1)
  {
        expOpinion = 0;
       val= expertOpinion();
  }
  else if(ans==3 && repQues == 1)
  {
        repQues = 0;
       val= replaceQuestion();
  }
  else if(ans==4 && audPoll == 1)
  {
        audPoll = 0;
       val= audiencePoll();
  }
    return val;
}


void getques(FILE *fptr)
{

	fgets(q1.q,100,(FILE*)fptr);
	fgets(q1.o1,75,(FILE*)fptr);
	fgets(q1.o2,75,(FILE*)fptr);
	fgets(q1.a,5,(FILE*)fptr);

	display();
}

int getans( char ans)
{
	if(ans==q1.a[0])
		return correct();

	else  return wrong();
}
void win()
{
	char c;
	FILE *fpt;

	fpt=fopen("WIN.txt","r");
    printf("\nCONGRATULATIONS %s! YOU HAVE WON THE GAME AND WILL LEAVE WITH %d Rs AS CASH PRIZE.",name,prize[qno-1]);

    c = fgetc(fpt);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fpt);
    }
    fclose(fpt);

}
void lose()
{
	char c;
	FILE *fpt;
	fpt=fopen("LOSE.txt","r");

	if(qno==2)
    printf("\nSORRY %s! YOU HAVE LOST THE GAME AND WILL LEAVE WITH 0 Rs. BETTER LUCK NEXT TIME.\n",name);
    else
    printf("\nSORRY %s! YOU HAVE LOST THE GAME AND WILL LEAVE WITH %d Rs. BETTER LUCK NEXT TIME.\n",name,prize[qno-1]);

    c = fgetc(fpt);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fpt);
    }
    fclose(fpt);

}


int main()
{

	FILE *fptr;
	fptr=fopen("KBC.txt","r");

	char a1;
	int cont;
	start();

	do
	{
		head();
		printf("Q%d.",qno);
		getques(fptr);
		printf("Enter your answer or type 'L' to choose a lifeline : ");
		scanf("%c",&a1);
		getchar();

		a1=toupper(a1);
		if(a1=='A' || a1=='B' || a1=='C' || a1=='D')
		cont=getans(a1);
		else
        cont=lifeline();


        qno++;
        Sleep(1500);
        system("cls");

}while(cont==1 && !(feof(fptr)));


    if(cont==0){

        qno--;
		lose();
    }
	else
        win();


	fclose(fptr);
	return 0;
}


