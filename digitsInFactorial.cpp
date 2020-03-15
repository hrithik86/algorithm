// A C++ program to find the number of digits in a factorial 
#include <bits/stdc++.h> 
using namespace std; 

//naive solution
int findDigits(int n) 
{ 
	if (n < 0) 
		return 0; 

	if (n <= 1) 
		return 1; 

	double digits = 0; 
	for (int i=2; i<=n; i++) 
		digits += log10(i); 

	return floor(digits) + 1; 
} 

//using formula
long long findDigitsFormula(int n) 
{ 
    if (n < 0) 
        return 0; 
  
    if (n <= 1) 
        return 1; 
  
    // Using Kamenetsky formula to calculate the number of digits f(x) = n* log10(( n/ e)) + log10(2*pi*n)/2
    double x = ((n * log10(n / M_E) + log10(2 * M_PI * n) / 2.0)); 
  
    return floor(x) + 1; 
} 

int main() 
{ 
	cout << findDigits(100) << endl; 
	cout << findDigitsFormula(50000000) << endl;
	return 0; 
} 
