#include <stdio.h>
int addArray( int array[ ],int n );
int main( )
{
    int data[] = {0,1,2,3,4,5,6,7,8,9}; 
    int size = sizeof(data) / sizeof(data[0]);
    printf("结果是:%d\n",addArray( data, size ));
    return 0;
} 

int addArray( int array[],int n )
{
  int sum = 0;
    int i;
    for( i=0; i<n; i++) 
    {
    sum=array[i];
    }
    return sum;
}
