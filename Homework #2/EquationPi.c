#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void  pidefine ( int n)
{
    / * Calculate Pi * /
    
    float pi;
	int sig = 1;
	
	        for (int i=1; i =< n; ++i)
	        {
	        	pi = pi + sig/(2 * i + 1);
	        	sig = sig * -1;
	        }
	        printf("%f\n",4 * pi);
}

    void  main ( int argc, char * argv [])
    {
	char * a = argv [ 1 ];
    int c = Chanl (a);
	pidefine (c);
    }