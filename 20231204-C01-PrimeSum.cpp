#include <iostream>
#include <algorithm>
using namespace std;

using namespace std;

int isPrime(int N)
{
    if (N < 2) {       /*小於2的數非質數*/
        return 0;
    } else {
        if (N == 2)
            return 1;
        for (int i = 2; i < N; i++)
        {
            if (N % i == 0)
                return 0;
        }
        return 1;
    }
}

int main()
{
    int q=3;
    // pair of integers
    pair<int, int> arr[q];

    // fill array with  num
    arr[0] = {1,3};
    arr[1] = {2,4};
    arr[2] = {3,5};

    int max_prime = 2000000;
    int A[max_prime];
    
    cout << "Generate Prime ARRAY..." << endl;
    int j=0;
    for(int i = 2; i < max_prime; i++) {
        if (isPrime(i) == 1){
           A[j]=i;
           j++;
        }
    }

    for (int i =0; i< j; i++)
    {
        cout << A[i] << endl;
    }
    cout << "--------------------" << endl;
 
    int SumOfPrime;
    for (int i =0; i< q; i++)
    {
         SumOfPrime = 0;

         for (int j = (arr[i].first-1); j< (arr[i].second); j++)
         {
              SumOfPrime = SumOfPrime + A[j];
         }
         cout << SumOfPrime << endl;
         
    }

}
