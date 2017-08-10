#include <stdio.h>
#include <stdlib.h>

struct node
{
	int num;
	int left;
	int right;
	int father;
};

void pre_order(){

}

void in_order(){

}

void post_order(){

}

int main(int argc, char const *argv[])
{
	node N[10000];
	int n;
	scanf("%d",&n);
	int a,b,c;

	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d %d" , &a, &b, &c);
		N[i].num=a;
		N[i].left=b;
		N[i].right=c;
	}



	pre_order();
	in_order();
	post_order();

	printf("%d,%d,%d\n", N[0].num, N[0].left, N[0].right);

	return 0;
}