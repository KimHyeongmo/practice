//거듭제곱 찾기

#include <stdio.h>
int main() {
	long long num;
	fscanf(stdin,"%lld",&num);
	if(num == (num & (-num)))
		printf("Yes");
	else
		printf("No");
}
/////////////////////////////////////////
#include <stdio.h>
#include <stdbool.h>
int main() {
	unsigned int special;
	unsigned int count;
	unsigned int count2;
	int out = 1;
	bool t = false;
	fscanf(stdin,"%d",&special);
	count = ~special + 1;
	count2 = special^count;
	if(count2 == (count << 1))
	{
		printf("Yes");
	}
	else
		printf("No");
	
}
