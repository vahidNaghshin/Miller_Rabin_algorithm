#include <iostream>
#include <stdio.h>
#include <cmath>
#include <random>

// unsigned long long int create_random_numbers(unsigned long long int n)
// {
//     unsigned long long int ran;
//     unsigned seed = time(0);

//     srand(seed);
//         ran =  (rand() % (n - 1));
//         // std::cout <<" : " << ran << std::endl << std::endl;
//     return ran;
// }

void factorization(unsigned long long int& q, unsigned long long int& k)
{
    do
    {
        q = q / 2;
        k++;
    } while(q%2 == 0);
}


bool residue_test(unsigned long long int& n, unsigned long long int& a, unsigned long long int& q, unsigned long long int& power, unsigned long long int& k)
{
    power = std::pow(a,q);
    bool b=false;    
    
    for (int i=0; i<k; i++){
        power = std::pow(a, std::pow(2, i)*q);
        std::cout << "<-->" << power<<"  "<<power%n <<std::endl;
        if ((i==0 && (power%n) == 1) || (((power%n) == n-1)))
        {
            b=true;
        }
    }
    
    return b;
    
}

void test(unsigned long long int n)
{
    unsigned long long int a;
    
    if (n%2 == 0 && n > 2)
        std::cout << "The number entered is Composite!" << std::endl;
    else
    {
        unsigned long long int k = 0;
        unsigned long long int q = n - 1, power=0;
        bool t;
        printf("Enter a number between 0 and %llu (start smaller numbers) as witness: \n", n-1);
        std::cin >> a;
        
        factorization(q, k);
        printf("q=%llu and k=%llu in n-1=2^k q \n", q, k);
        // when the number a is determined by the user
        t = residue_test(n, a, q, power, k);
        
        if (t==true)
            std::cout << "Inconclusive" << std::endl;
        else
            std::cout << "Composite" << std::endl;
    }
}



int main()
{
    unsigned long long int n;
    
    std::cout << "Please enter the number for primality: " << std::endl;
    std::cin >> n;
    test(n);
    
    return 0;
}
