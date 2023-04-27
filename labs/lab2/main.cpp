#include<iostream>
#include<vector>
#include<cmath>
#include <locale>

using namespace std;

class Vector{
    private:
        vector<double> v;           // вектор
        int d;                      // размер вектора

    public:
        Vector(int n=0){            // конструктор n-мерного вектора заполненного нулями
            d=n; v.resize(d,0);
        }

        void read_Vector(){         // ввод вектора с клавиатуры
            for(int i=0;i<d;i++){
                cin>>v[i];
            }
        }

        void print_Vector(){        // вывод вектора
            for(int i=0;i<d;i++){
                cout<<v[i]<<" ";
            }
            cout<<endl;
        }

        Vector operator+(const Vector &a){    // операция сложения векторов
            Vector sum(d);
            for(int i=0;i<d;i++){
                sum.v[i]=v[i]+a.v[i];
            }
            return sum;
        }

        Vector operator-(const Vector &a){    // операция вычитания векторов
            Vector diff(d);
            for(int i=0;i<d;i++){
                diff.v[i]=v[i]-a.v[i];
            }
            return diff;
        }

        double operator*(const Vector &a){    // операция скалярного произведения векторов
            double dot=0;
            for(int i=0;i<d;i++){
                dot+=v[i]*a.v[i];
            }
            return dot;
        }

        Vector operator*(const double &a){    // операция умножения вектора на число
            Vector prod(d);
            for(int i=0;i<d;i++){
                prod.v[i]=v[i]*a;
            }
            return prod;
        }

        Vector operator/(const double &a){    // операция деления вектора на число
            Vector div(d);
            for(int i=0;i<d;i++){
                div.v[i]=v[i]/a;
            }
            return div;
        }
};

int main()
{

    setlocale(LC_ALL,"RUSSIAN");
    Vector a(3), b(3);
    cout<<"Введите первые векторные значения: ";    a.read_Vector();
    cout<<"Введите значения второго вектора:";    b.read_Vector();
    cout<<"Сумма векторов: ";    (a+b).print_Vector();
    cout<<"Разность векторов: ";    (a-b).print_Vector();
    cout<<"Точечное произведение векторов ";    cout<<(a*b)<<endl;
    cout<<"Произведение вектора и скаляра : ";    (b*3).print_Vector();
    cout<<"Частное вектора и скаляра : ";    (b/2).print_Vector();

    return 0;
}
