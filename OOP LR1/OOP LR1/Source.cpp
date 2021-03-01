#include <iostream>

using namespace std;
class RNUM
{
private:

    double value;

public:

    RNUM() 
    { 
        value = 0; 
    }
    RNUM(double numb) 
    { 
        value = numb; 
    }

    ~RNUM() {};

    void SetValue(double value)
    {
        this->value = value;
    }

    double GetValue()
    {
        return value;
    }

    int IntPart()
    {
        int numb = value;
        return numb;
    }

    double DecPart()
    {
        double dp = value - IntPart();
        while (true)
        {
            dp *= 10;
            if ((int)(dp+0.5) % 10 == 0)
            {
                break;
            }
        }
        return dp / 10;
    }

    double NewNumb(int a, int b)
    {
        int count = 0;
        double decimal = b;
        double dec2_part = decimal;
        for (int k = 0;; k++)
        {
            count++;
                if ((int)dec2_part / 10 != 0)
                {
                    dec2_part /= 10;
                }
                else
                {
                    break;
                }
        }
       for (int i = 0; i < count; i++)
            decimal /= 10;
        return a + decimal;
    }
};


int main()
{
    RNUM num;
    double numb;
    int integer, decimal;
    cout << "Enter a number: ";
    cin >> numb;
    num.SetValue(numb);
    cout << "Int part: " << num.IntPart() << endl;
    cout << "Decimal part: " << num.DecPart() << endl;
    cout << endl << "Enter int part of the new number: ";
    cin >> integer;
    cout << endl << "Enter decimal part of the new number: ";
    cin >> decimal;
    cout << "New number: " << num.NewNumb(integer, decimal) << endl;
}
