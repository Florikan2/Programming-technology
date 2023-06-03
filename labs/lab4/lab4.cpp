# include <iostream>
# include <stdlib.h>
# include <ctime>
# include <locale.h>
# include <conio.h>
using namespace std;



class Matrix
{

private:

int n;
int m;
int ** mas;

public:
Matrix (int, int);
~ Matrix ();

void show ();

};


Matrix :: Matrix (int _k, int _l)
{
n = _k;
m = _l;
mas = new int * [n];
for (int i = 0; i <n; i)
mas [i] = new int [m];
srand (time (NULL));
for (int i = 0; i <n; i)
for (int j = 0; j <m; j)
mas [i] [j] = rand () -10;
}

Matrix :: ~ Matrix ()
{
for (int i = 0; i <m; i)
delete [] mas [i];

delete [] mas;
}




void Matrix :: show ()
{
cout << "Вид матрицы: \ n";
for (int i = 0; i <n; i) {
cout << '\ n';
for (int j = 0; j <m; j)
cout << mas [i] [j] << "" << "\ t";
cout << "\ n";}

}







class Vector
{


private:
int n; int * arr;

public:

Vector (int);
~ Vector ();

void print ();
};


Vector :: Vector (int _n)
{
n = _n;
arr = new int [n];
for (int i = 0; i <n; i)
arr [i] = rand ();
}


Vector :: ~ Vector () {delete [] arr;}


void Vector :: print ()
{
cout << "Наш вектор:";
for (int i = 0; i <n; i)
cout << arr [i] << "";
cout << "\ n";
}
int main ()
{
setlocale (LC_ALL, "Russian");
int k;
int l;
cout << "Введите кол-во строк матрицы:";
cin >> k;
cout << "Введите кол-во столбцов матрицы:";
cin >> l;
int n;
cout << "Введите размер вектора:"; cin >> n;
Vector obj (n);


Matrix Obj (k,l)

a=1;
while (a! = 0)
{
cout << "Меню" << endl

<< "<1-Вывод матрицы> \ n"
<< "<2-Вывод вектора> \ n"

<< "<0-выход из программы> \ n";




cout << endl;

cout << "Сделайте выбор:";
cin >> a;
cout << "\ n";
switch (a) {

case 1:
Obj.show ();
 break;

case 2:

obj.print ();
 break;

}
}
getch ();
return 0;
}
