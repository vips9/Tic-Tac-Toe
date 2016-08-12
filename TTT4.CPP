#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
void check();
void checkp();
void cpu();
void box(int,int,int,int);
void keys();
void player();
void play();
void initials();
void default_val();
char a[10]={'a','a','a','a','a','a','a','a','a','a'};
int r=1,x=1,y=1;
void default_val()
{

r=1,x=1,y=1;
for(int p=1;p<=9;p++)
a[p]='a';

}
void tutorial()
{
clrscr();
box(26,29,24,31);
keys();
gotoxy(31,10);
cout<<"X";
delay(2000);
gotoxy(25,14);
cout<<"O";
delay(2000);
gotoxy(25,10);
cout<<"X";
delay(2000);
gotoxy(28,10);
cout<<"O";
delay(2000);
gotoxy(31,14);
cout<<"X";
delay(2000);
gotoxy(25,12);
cout<<"O";
delay(2000);
gotoxy(28,12);
cout<<"X";
gotoxy(36,20);
cout<<"Computer wins";
delay(3000);
clrscr();
cout<<"\n\nPress any key to Play.... :";
getch();
play();
}
void exe()
{
for(int i=1;i<=9;i++)
{
if(a[i]=='a')
break;
}
if(i==10)
{
gotoxy(34,20);
cout<<"No one wins!!!";
gotoxy(37,21);
cout<<"**Draw**";
getch();
clrscr();
cout<<"\n\nWanna Play again(Press y else any key)...";
int c=getch();
if(c=='y'||c=='Y')
{
default_val();
play();
}
initials();
getch();
exit(9);
}
}
void initials()
{
clrscr();
int i,j=0,k=44;
char c[30]="VIPUL SRIVASTAVA";

for(i=1;c[i]!='\0';i++)
{

gotoxy(32,9);
cout<<"DEVELOPED BY:";

gotoxy(45,12);
cout<<"|";
gotoxy(k--,12);

j=0;
while(j<i)
{
cout<<c[j++];
cout<<"\a";
}
delay(400);
cout<<c[j];

if(c[j+1]!='\0')
clrscr();
}
gotoxy(45,12);
cout<<"|";
j=0;
gotoxy(29,12);
cout<<"VIPUL SRIVASTAVA|";
delay(400);
cout<<"J";
delay(400);
cout<<"S";
delay(400);
cout<<"S";

}
void play()
{
int c;

clrscr();
cout<<"Wanna make the first move or let computer make ?\n";
cout<<"Press C for computer,Y for yourself and any key to exit :";
c=getch();

clrscr();

box(26,29,24,31);
keys();
if(c=='C'||c=='c')
cpu();
else if(c=='Y'||c=='y')
player();
else
exit(22);
}


void check_coordinates()
{
if(r==1||r==2||r==3)
y=14;
else if(r==4||r==5||r==6)
y=12;
else if(r==7||r==8||r==9)
y=10;
if(r==1||r==4||r==7)
x=25;
else if(r==2||r==5||r==8)
x=28;
else if(r==3||r==6||r==9)
x=31;
gotoxy(x,y);
cout<<a[r];
if(a[r]=='O')
delay(2000);
check();
}
void player()
{
exe();
do{
r=getch();
if(r==13||r==27)
exit(4);
}while(r<49||r>57||a[r-48]=='X'||a[r-48]=='O');


for(int i=1;i<=9;i++)
{
if(r==(i+48))
{
r=i;
break;
}}

a[r]='O';
check_coordinates();
cpu();
}
void cpu()
{
exe();
do{
r=random(10);
}while(r==0||a[r]=='X'||a[r]=='O');

a[r]='X';
check_coordinates();
player();
}

void check()
{
for(int i=1;i<=7;i=i+3)
{
if((a[i]==a[i+1]&&a[i+1]==a[i+2])&&(a[i]=='X'||a[i]=='O'))
checkp();
}
for(i=1;i<=3;i++)
{
if((a[i]==a[i+3]&&a[i+3]==a[i+6])&&(a[i]=='X'||a[i]=='O'))
checkp();
}
if(((a[1]==a[5]&&a[5]==a[9])&&(a[1]=='X'||a[1]=='O'))||((a[3]==a[5]&&a[5]==a[7])&&(a[3]=='X'||a[3]=='O')))
checkp();
//turn_no++;
}


void box(int z,int b,int c,int v)
{
int j=10;
for(int i=0;i<=2;i++)
{
gotoxy(z,j);
cout<<"|";
gotoxy(b,j);
cout<<"|";
j=j+2;
}
for(i=c;i<=v;i++)
{
gotoxy(i,11);
cout<<"-";
gotoxy(i,13);
cout<<"-";
}}

void keys()
{
int i,j,k=14,l=1;
for(i=0;i<=2;i++)
{
gotoxy(55,k);
for(j=0;j<=2;j++)
{
cout<<(l++)<<"  ";
}
k=k-2;
}
box(56,59,54,61);
}

void checkp()
{
gotoxy(34,20);
if(a[r]=='X')
cout<<"Computer won the match";
else
cout<<"Player Won the match";
getch();
clrscr();
cout<<"\n\nWanna Play again(Press y else any key)...";
int c=getch();
if(c=='y'||c=='Y')
{
default_val();
play();
}
initials();
getch();
exit(1);
}


void main()
{
clrscr();
char c;
cout<<"\n\t\t\t\tTIC-tac-TOE\n\n";
cout<<"1. Tutorial\n2. Play\n3. Exit\n\n";
cout<<"Enter Your Choice(1-3)...";
do{
c=getche();
}while(c>51||c<49);

if(c==49)
tutorial();

else if(c==50)
play();

else if(c==51)
exit(7);

}
