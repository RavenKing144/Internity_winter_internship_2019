#include<iostream>
#include<cmath>
using namespace std;

#define X3(x1, x2) ((7 - 3 * (x1) + (x2)) / 10)
#define X1(x2, x3) ((6 - 5 * (x2) + 4 * (x3)) / 10)
#define X2(x1, x3) ((9 - 4 * (x1) + (x3)) / 10)

int main()
{
    double allowed_error;
    double x1 = 0, x2 = 0, x3 = 0,y1 =0,y2 = 0,y3 =0;
    int count  =0;
    cout<<"Enter allowed error value: "<<endl;
    cin>>allowed_error;
    printf("\nx1\t\tx2\t\tx3");
    printf("\n%f\t%f\t%f", x1, x2, x3);

    do
    {
        y1 = X1(x2,x3);
        y2 = X2(y1,x3);
        y3 = X3(y1,y2);

        if(fabs(y1-x1)<allowed_error && fabs(y2-x2)<allowed_error && fabs(y3-x3)<allowed_error )
        {
            cout<<endl<<endl<<"x1 = "<<y1<<endl;
            cout<<"x2 = "<<y2<<endl;
            cout<<"x3 = "<<y3<<endl;
            count=1;
        }
        else
        {
            x1 = y1;
            x2 = y2;
            x3 = y3;
            printf("\n%f\t%f\t%f", x1, x2, x3);
        }
    }while(count!=1);
    return 0;
}
