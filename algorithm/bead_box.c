#include <stdio.h>
long long box_size[30];
int main() {
	long long bead;
	int box_number;
	fscanf(stdin,"%lld %d",&bead,&box_number);
	for(int i = 0; i < box_number; i++)
	{
		fscanf(stdin,"%lld",&box_size[i]);
	}
	long long count = 0;
	for(int i = box_number-1; i >= 0; i--)
	{
		count += bead/box_size[i];
		bead = bead%box_size[i];
	}
	printf("%lld",count);
	
	
	return 0;
}
