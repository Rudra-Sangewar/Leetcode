#include <iostream>
#include <cmath>
using namespace std;

class Solution 
{  
private:  
    bool is_square(int n)
    {  
        int sqrt_n = (int)(sqrt(n));  
        return (sqrt_n * sqrt_n == n);  
    }
    
public:
    int numSquares(int n) 
    {  
        // Case 1: Perfect square
        if (is_square(n)) 
            return 1;  
        
        // Case 2: Check Legendre condition (4^k * (8m + 7))
        while ((n & 3) == 0)  // n % 4 == 0
            n >>= 2;  
        
        if ((n & 7) == 7)     // n % 8 == 7
            return 4;
        
        // Case 3: Check if answer is 2
        int sqrt_n = (int)(sqrt(n)); 
        for (int i = 1; i <= sqrt_n; i++)
        {  
            if (is_square(n - i * i)) 
                return 2;  
        }  
        
        // Case 4: Otherwise 3
        return 3;  
    }  
};

int main()
{
    Solution obj;
    
    int n;
    cout << "Enter number: ";
    cin >> n;
    
    cout << "Minimum number of perfect squares: " << obj.numSquares(n) << endl;
    
    return 0;
}