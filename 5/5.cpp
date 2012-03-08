#include <iostream>
#include <map>
#include <math.h>
using namespace std;

int primes[8] = { 2, 3, 5, 7, 11, 13, 17, 19 };

map<int, int> getPrime(int num)
{
    map<int, int> primeCount;
    for (int i=0; i<8; i++)
    {
        primeCount[primes[i]] = 0;
        while (num % primes[i] == 0)
        {
            primeCount[primes[i]] = primeCount[primes[i]] + 1;
            num = num / primes[i];
        }
    }
    
    return primeCount;
}

int main()
{
    int result = 1;
    bool divisible;
    map<int, int> primeCount, tempPrimeCount;
    
    // here is the theory
    // 1, break down each number to prime
    // 2, record the number of minimum prime, 
    //   i.e. 20 would be 1 x 5 and 2 x 2 (two 2s)
    // 3, do this for each number between 1 to 20
    //   raising the minimum as we find them
    // 4, find out the product of all the minimum primes
    primeCount = getPrime(20);
    for (int i=19; i>1; i--)
    {
        tempPrimeCount = getPrime(i);
        for (int j=0; j<8; j++)
        {
            if (tempPrimeCount[primes[j]] > primeCount[primes[j]])
                primeCount[primes[j]] = tempPrimeCount[primes[j]];
        }
    }    
    for (int j=0; j<8; j++)
    {
        cout << "primeCount for " << primes[j] << " is " << primeCount[primes[j]] << endl;
        result = result * (pow(primes[j], primeCount[primes[j]]));
        cout << "result = " << result << endl;
    }
    
    cout << "result = " << result << endl;
}