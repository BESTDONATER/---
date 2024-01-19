#include <iostream>
#include <conio.h>
#include <random>
#include <time.h>

using namespace std;
char table[3][3];
bool step;
char name1[20];
char name2[20];
void instruction()
{
 cout << "\t\t*Хрестики-нулики*\n\n";
 cout << "Правила:\n";
 cout << "Грають двоє гравців на полі 3х3\n";
 cout << "Виграє той, хто збере виграшну комбінацію\n";
 cout << "Вигляд поля:\n";

 int l = 0;

 for (int i = 0; i < 3; i++)
 {
  for (int j = 0; j < 3; j++)
  {
   cout << "|" << l+1 << ' ';
   table[i][j] = char(49+l);
   l++;
  }
  cout << '|';
  cout << endl;
 }


 cout << "Для початку гри нажміть клавішу\n";

 getch();
}
bool input()
{

 for (int i = 0; i < 3; i++)
 {
  for (int j = 0; j < 3; j++)
  {
   cout << "|" << table[i][j] << ' ';

  }
  cout << '|';
  cout << endl;
 }

 cout << endl;

 if (step)
  cout << "Ходить: " << name1 << endl;
 else cout << "Ходить: " << name2 << endl;
 int n;
 cin >> n;
 if (n<1 || n>9)
 {
  return false;
 }
 int i, j;
 if (n % 3 == 0)
 {
  i = (n / 3) - 1;
  j = 2;
 }
 else
 {
  j = (n % 3) - 1;
  i = n / 3;
 }
 if (table[i][j] == 'O' || table[i][j] == 'X')
  return false;

 if (step)
 {
  table[i][j] = 'X';
  step = false;
 }
 else
 {
  table[i][j] = 'O';
  step = true;
 }

 return true;
}
bool win()
{
 for (int i = 0; i < 3; i++)
 {
  if ((table[i][0] == table[i][1]) && (table[i][0] == table[i][2]))
   return false;
  else if ((table[0][i] == table[1][i]) && (table[0][i] == table[2][i]))
   return false;
  else if ((table[0][0] == table[1][1] && table[0][0] == table[2][2]) || (table[0][2] == table[1][1] && table[0][2] == table[2][0]))
   return false;

 }

}

int main()
{
 setlocale(LC_ALL, "Ukraine");

 instruction();
 system("cls");

 cout << "Введіть імя 1 гравця:";
 cin.getline(name1, 20);
 cout << "Введіть імя 2 гравця:";
 cin.getline(name2, 20);
 srand(time(NULL));
 if (rand() & 1)
  step = true;
 else step = false;

 while (win())
 {
  system("cls");
  if ( !input() )
  {
   cout << "Ви ввели неправильні дані, повторіть";
   getch();
  }

 }

 system("cls");
 if (step)
  cout << "Переміг " << name2 << endl;
 else cout << "Переміг " << name1 << endl;
 getch();
 return 0;
}