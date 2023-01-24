#include <stdio.h>
#include <string.h>
#include <conio.h>

void read_data(char user_string[], int *L, int *X, int *Y);
void leftjust(char str[], int L, int X, int Y);
void rightjust(char str[], int L, int X, int Y);
void centerjust(char str[], int L, int X, int Y);

main() {
	char str1[81];
   int x, y, len;

   read_data(str1, &len, &x, &y);
   leftjust(str1, len, x, y);
   getch();
   rightjust(str1, len, x, y);
   getch();
   centerjust(str1, len, x, y);

   getch();
   return 0;
}

void read_data(char str[], int *L, int *X, int *Y)
{
   int xx, yy;
	textcolor(7);textbackground(0);clrscr();
   printf("STRING = ");
   xx = wherex(); yy = wherey();
   do
   {
   	gotoxy(xx,yy);clreol();gets(str);
   } while (strlen(str)>80);
   printf("LENGTH = ");
   xx = wherex(); yy = wherey();
   do
   {
   	gotoxy(xx,yy);clreol();scanf("%d", L);
   } while (*L<=strlen(str) && *L>=80);

   printf("X     : ");
   xx = wherex(); yy = wherey();
   do
   {
   	gotoxy(xx,yy);clreol();scanf("%d", X);
   } while (*X<0 && *X>80);
   printf("Y     : ");
   xx = wherex(); yy = wherey();
   do
   {
   	gotoxy(xx,yy);clreol();scanf("%d", Y);
   } while (*Y<0 && *Y>25);
}

void leftjust(char str[], int L, int X, int Y)
{
   int i;
	char temp[81];

   temp[0] = '\0';
   strcpy(temp, str);
	for (i=0; i<L-strlen(str); i++)
   	strcat(temp, " ");
   temp[strlen(temp)] = '\0';

   textcolor(7);textbackground(0);clrscr();
   gotoxy(X,Y);textcolor(0);textbackground(7);
   cprintf("%s\n",temp);
}

void rightjust(char str[], int L, int X, int Y)
{
   int i;
	char temp[81];

	temp[0] = '\0';
   for (i=0; i<L-strlen(str); i++)
   	strcat(temp, " ");
   temp[L-strlen(str)] = '\0';
   strcat(temp, str );
   temp[strlen(temp)] = '\0';

   textcolor(7);textbackground(0);clrscr();
   gotoxy(X,Y);textcolor(0);textbackground(7);
   cprintf("%s\n",temp);
}

void centerjust(char str[], int L, int X, int Y)
{
   int i, col;
	char temp[81];

	col = (L - strlen(str)) / 2;
   temp[0] = '\0';
   for (i=0; i<col; i++)
   	strcat(temp, " ");
   temp[col] = '\0';
   strcat(str, temp);
   temp[strlen(temp)] = '\0';
   strcat(temp, str);

   textcolor(7);textbackground(0);clrscr();
   gotoxy(X, Y);textcolor(0);textbackground(7);
   cprintf("%s\n",temp);
}
