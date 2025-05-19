#include <stdio.h>
#include <stdlib.h>


int fakultaet(int x) {
	if(x > 1) {
		return x * fakultaet(x-1);
	}else {
		return 1;
	}
}


int binominalkoeffizient(int n, int k)
{
    if(( n < 0 )|| (n > 12)) return -1;
    if((k > n)|| (k < 0)) return 0; 
    return (fakultaet(n)/(fakultaet(k)*fakultaet(n-k)));
    
}

int main(int argc, char *argv[])
{

    for(int n = 0; n < (atoi(argv[1])); n++)
    {
        for(int k = 0; k <= n ; k++ )
        {
            printf("%5d", binominalkoeffizient(n, k));
        }
        printf("\n");
    }



}