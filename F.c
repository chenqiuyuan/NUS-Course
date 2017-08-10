	#include <stdio.h>
	#include <stdlib.h>
	
	int tot;
	int answer[10001];
	struct node
	{
		int value;
		int left;
		int right;
		int father;
	};

	node find_root(int n,node N[]){
		for(int i = 1;i <= n;i++){
			if(N[i].father == -2){
				return N[i];
			}
		}
	}
	
	void pre_order(node n, node N[]){		
		if (n.value == -1)
		{
			return;
		}
		answer[++tot]=n.value;
		//printf("%d ", n.value);
		pre_order(N[n.left],N);
		pre_order(N[n.right],N);
	}
	
	void in_order(node n, node N[]){
		if (n.value == -1)
		{
			return;
		}
		in_order(N[n.left],N);		
		answer[++tot]=n.value;
		//printf("%d ", n.value);
		in_order(N[n.right],N);
	}
	
	void post_order(node n, node N[]){
		if (n.value == -1)
		{
			return;
		}
		post_order(N[n.left],N);
		post_order(N[n.right],N);
		answer[++tot]=n.value;
		//printf("%d ", n.value);
	}
	void display(int n) {
		for (int i = 1;i<n;i++) {
			printf ("%d ",answer[i]);
		}
		printf ("%d\n",answer[n]); 
	}
	/*
	void level_order(node n,node N[],int a[]){
		if (n.value == -1)
		{
			return;
		}
		int left_id,right_id;
		left_id = (2*n.id)+1;
		right_id = (2*n.id)+2;
		a[left_id] = n.left;
		N[n.left].id = left_id;
		a[right_id] = n.right;
		N[n.right].id = right_id;
		level_order(N[n.left],N,a);
		level_order(N[n.right],N,a);
	}
	*/
	int main(int argc, char const *argv[])
	{
		int a[10001];
		int b[10001];
		int n;
		scanf("%d",&n);

		for (int i = 1; i <= n; ++i)
		{
			a[i] == getchar();
		}

		for (int i = 1; i <= n; ++i)
		{
			b[i] == getchar();
		}

		for (int i = 1; i <= n; ++i)
		{
			printf("%d %d\n",a[i],b[i] );
		}

		
		return 0;
	}
