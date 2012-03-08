#include <iostream>
using namespace std;


int main()
{
    int sumOfSquare=0, squareOfSum=0;
    
    for (int i=1; i<101; i++)
    {
        sumOfSquare += i * i;
        squareOfSum += i;
    }
    squareOfSum = squareOfSum * squareOfSum;
    
    cout << "sum of square is " << sumOfSquare << endl;
    cout << "square of sum is " << squareOfSum << endl;
    cout << "diff is " << squareOfSum - sumOfSquare << endl;    
}