#include<iostream>
#include<math.h>
using namespace std;

long long int pow(long long int a, long long int b,
									long long int P)
{
	if (b == 1)
		return a;

	return (((long long int)pow(a, b)) % P);
}

int main()
{
	long long int P, G, x, a, y, b, ka, kb;
	P = 23; 
	cout<<"The value of P "<<P<<"\n";
	G=9;
	cout<<"The value of G "<<G;
	a = 4;
	cout<<"\nThe private key a for Alice"<<a;
	x = pow(G, a, P); 
	b = 3; 
	cout<<"\nThe private key b for Bob :"<<b;
	y = pow(G, b, P); 
	ka = pow(y, a, P); 
	kb = pow(x, b, P); 
	cout<<"\nSecret key for the Alice is :"<<ka;
	cout<<"\nSecret Key for the Bob is :"<<kb;
	
	return 0;
}

