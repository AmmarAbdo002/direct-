#include <iostream>
using namespace std;
void exactSolution();

int main()
{
    exactSolution();
}

//! بتحط قيم المصفوفه
void setMatrix(double Matrix[3][4])
{
    cout << "Enter x1 values: " << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "num " << i + 1 << ": ";
        cin >> Matrix[i][0];
    }
    cout << "\n-------------------------------------------\n";
    cout << "Enter x2 values: " << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "num " << i + 1 << ": ";
        cin >> Matrix[i][1];
    }
    cout << "\n-------------------------------------------\n";
    cout << "Enter x3 values: " << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "num " << i + 1 << ": ";
        cin >> Matrix[i][2];
    }
    cout << "\n-------------------------------------------\n";
    cout << "Enter result values: " << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "num " << i + 1 << ": ";
        cin >> Matrix[i][3];
    }
}
//! بتعدل المصفوفه بحيث يبقي فيها 3 اصفار
void operationsMatrix(double Matrix[3][4])
{
    //! بتصفر اول قيمه في الصف الثاني
    //! factor1   (هو المعامل اللي بيجعل اول قيمه في الصف التاني = اول قيمه في الصف الاول (علشان ناتج الطرح يبقي صفر
    double factor1 = (Matrix[1][0] / Matrix[0][0]);
    for (int i = 0; i < 4; i++)
    {
        Matrix[1][i] -= (factor1 * Matrix[0][i]);
    }
    //! بتصفر اول قيمه في الصف الثالث
    //! factor2   (هو المعامل اللي بيجعل اول قيمه في الصف الثالث = اول قيمه في الصف الاول (علشان ناتج الطرح يبقي صفر
    double factor2 = (Matrix[2][0] / Matrix[0][0]);
    for (int i = 0; i < 4; i++)
    {
        Matrix[2][i] -= (factor2 * Matrix[0][i]);
    }
    //! بتصفر تاني قيمه في الصف الثالث
    //! factor3   (هو المعامل اللي بيجعل تاني قيمه في الصف الثالث = تاني قيمه في الصف تاني (علشان ناتج الطرح يبقي صفر
    double factor3 = (Matrix[2][1] / Matrix[1][1]);
    for (int i = 0; i < 4; i++)
    {
        Matrix[2][i] -= (factor3 * Matrix[1][i]);
    }
}
//! to print values of x1,x2,x3
void print(double x1, double x2, double x3)

{
    cout << "\n___________________________________________\n";
    cout << "___________________________________________\n\n";
    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;
    cout << "x3 = " << x3 << endl;
}
//! GaussEliminationMethod
void exactSolution()
{
    double Matrix[3][4];
    setMatrix(Matrix);
    operationsMatrix(Matrix);
    double x1 = 0, x2 = 0, x3 = 0;
    //! x بعوض علطول في المصفوفه كل صف بيطلع
    x3 = Matrix[2][3] / Matrix[2][2];
    x2 = (Matrix[1][3] - (Matrix[1][2] * x3)) / Matrix[1][1];
    x1 = (Matrix[0][3] - (Matrix[0][2] * x3) - (Matrix[0][1] * x2)) / Matrix[0][0];
    print(x1, x2, x3);
}
