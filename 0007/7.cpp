#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> primes;
    list<int>::iterator it;
    bool isPrime;
        
    for (int i=2; primes.size() < 10002; i++)
    {
        it = primes.begin();
        isPrime = true;
        while(isPrime && *it < i/2 && it != primes.end())
        {
            if (i % *it ==0)
                isPrime = false;
                
            it++;
        }
        
        if (isPrime)
            primes.push_back(i);            
    }
    
    it = primes.end();
    it--;
    cout << "10001st prime is " << *it << endl;
}