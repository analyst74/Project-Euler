#include <iostream>
#include <list>
using namespace std;


void insert(list<int> &sortedList, int element, int maxSize) 
{
    list<int>::iterator it = sortedList.begin();
    //cout << "products.begin() = " << (int) *it << endl;
    
    if ((int)sortedList.size() > 0)
        while ((int)*it < element)
            it++;
            
    //cout << "inserting " << element << " into position " << (int)*it << endl;
    sortedList.insert(it, element);
    
    if ( (int)sortedList.size() > maxSize ) 
        sortedList.pop_front();
}

bool isPalindrome(int n, bool withLogging)
{
    int temp;
    list<int> digits;
    list<int>::iterator it1, it2;    
    
    while(n != 0)
    {
        temp = n % 10;
        digits.push_front(temp);
        n = n / 10;
    }
    
    if (withLogging)
    {
        cout << "evaluating: " << n << endl;
        it1 = digits.begin();
        do {
            cout << *it1 << " ";
            it1++;
        }while (it1 != digits.end());
        cout << endl;
    }
    
    it1 = digits.begin();
    it2 = digits.end();
    it2--;

    while (it1 != digits.end() && it2 != digits.begin())
    {
        if (withLogging)
        {
            cout << "comparing " << *it1 << " with " << *it2 << endl;
        }
        
        if (*it1 != *it2)
            return false;
            
        it1++;
        it2--;
    }
    
    return true;
}

int main()
{
    int i, j, result;
    result = 0;
    
    for (i = 999; i > 599; i--) 
    {
        for (j = 999; j > 599; j--)
        {
            if (i*j > result && isPalindrome(i*j, false))
            {
                cout << "found palindrome at " << i << " * " << j << " = " << i*j << endl;
                isPalindrome(i*j, true);
                result = i * j;
            }
        }
    }    
    
    cout << "largest palindrome number is " << result << endl;
}