#include <iostream>
#include <iomanip>
#include <locale>


using namespace std;

int main()
{

setlocale(LC_ALL,"RUSSIAN");
    int rows    = 0,      // строки
        columns = 0;      // столбцы

    cout << "Введите количество строк матрицы: ";
    cin >> rows;

    cout << "Введите количество столбцов матрицы: ";
    cin >> columns;

    // объявление двумерного динамического массива
    int **matrix = new int* [rows];
        for (int count = 0; count < 2; count++)
            matrix[count] = new int [columns];

    // заполнение матрицы
    for (int ix = 0; ix < rows; ix++ )
        for (int jx = 0; jx < columns; jx++)
        {
            cout << "matrix[" << (ix + 1) << "][" << (jx + 1) << "] = ";
            cin  >> matrix[ix][jx];
        }

    // объявление одномерного динамического массива
    int *vector = new int [columns];
    cout << "Введите элементы вектора:\n";

    // заполнение вектора
    for (int ix = 0; ix < columns; ix++ )
    {
        cout << "vector[" << (ix + 1) << "] = ";
        cin >> vector[ix];
    }

    cout << "\nВведенная матрица:\n";
    for (int ix = 0; ix < rows; ix++ )
    {
        for (int jx = 0; jx < columns; jx++)
        {
            cout << setw(4) << matrix[ix][jx];
        }
        cout << endl;
    }

    cout << "\nВведенный вектор:\n";
    for (int ix = 0; ix < columns; ix++ )
    {
        cout << setw(4) << vector[ix] << endl;
    }

    // объявление одномерного динамического массива
    int *out = new int [columns];
    // умножение элементов матрицы на вектор
    for (int ix = 0; ix < rows; ix++)
    {
        out[ix] = 0;
        for (int jx = 0; jx < columns; jx++)
            out[ix] += matrix[ix][jx] * vector[jx];
    }

    cout << "\результирующий вектор:\n";
    for (int ix = 0; ix < rows; ix++ )
    {
        cout << setw(4) << out[ix] << endl;
    }


    // высвобождение памяти отводимой под двумерный динамический массив:
        for (int count = 0; count < rows; count++)
            delete [] matrix[count];

    // высвобождение памяти отводимой под одномерный динамический массив
    delete [] vector;
    delete [] out;

    return 0;
}
