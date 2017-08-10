	#include <stdio.h>
	#include <stdlib.h>
	
	int tot;
	int answer[10001];
	struct node
	{
		int id;
		int value;
		int left;
		int right;
		int father;
	};

	void initialize(node N[],int num){
		for (int i = 1; i <= num; i++){
			N[i].id = 0;
	    	N[i].value = 0;
			N[i].left = 0;
			N[i].right = 0; 
	    	N[i].father = -2;
		}
	}

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
		for (int i=1;i<n;i++) {
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
		node N[10001];
		int n;
		scanf("%d",&n);

		int a,b,c;
		initialize(N,n);
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d %d %d" , &a, &b, &c);
			N[a].value = a;
			if(b != -1)N[a].left = b;
			if(c != -1)N[a].right = c; 		
			N[b].father = a;
			N[c].father = a;
		}
		node nn; 
		nn = find_root(n,N);
	
		tot=0;
		pre_order(nn,N);
		display(n);
		//printf("\n");
		tot=0;
		in_order(nn,N);
		display(n);
		//printf("\n");
		
		tot=0;
		post_order(nn,N);
		display(n);
		//printf("\n");
//		int num[10000];
//		for(int i = 0; i < 10000; ++i){
//			num[i] = -1;
//		}
//		num[0]=nn.value;
//		level_order(nn,N,num);
	
//		for (int i = 0; i < n; ++i)
//		{
//			printf("%d %d %d\n", N[i].value, N[i].left, N[i].right);
//		}
//		for(int i = 0; i < 10000; ++i){
//			if(num[i] != -1)printf("%d ",num[i]);
//		}
		return 0;
	}
12
12 -1 -1
11 -1 12
9 -1 11
8 -1 9
3 -1 5
2 -1 -1
1 2 3
5 4 -1
4 10 -1
10 -1 -1
6 1 7
7 -1 8

14
1 -1 2
2 -1 3
3 -1 4
4 -1 5
5 -1 6
6 -1 7
7 -1 8
8 -1 9
9 -1 10
10 -1 11
11 -1 12
12 -1 13
13 -1 14
14 -1 -1

5
3 2 1
2 5 4
5 -1 -1
4 -1 -1
1 -1 -1

8
1 2 3 4 5 6 7 8
3 2 5 4 6 1 7 8

6
1 2 3 4 5 6
2 3 4 1 5 6

4
1 2 3 4
2 3 1 4

