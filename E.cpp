	#include <stdio.h>
	#include <stdlib.h>
	
	int tot;
	int answer[10001];
	struct node
	{
	//	int id; 
		int value;
		int left;
		int up;
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
	
	// void pre_order(node n, node N[]){		
	// 	if (n.value == -1)
	// 	{
	// 		return;
	// 	}
	// 	answer[++tot]=n.value;
	// 	pre_order(N[n.left],N);
	// 	pre_order(N[n.right],N);
	// }
	
	// void in_order(node n, node N[]){
	// 	if (n.value == -1)
	// 	{
	// 		return;
	// 	}
	// 	in_order(N[n.left],N);		
	// 	answer[++tot]=n.value;
	// 	in_order(N[n.right],N);
	// }
	
	// void post_order(node n, node N[]){
	// 	if (n.value == -1)
	// 	{
	// 		return;
	// 	}
	// 	post_order(N[n.left],N);
	// 	post_order(N[n.right],N);
	// 	answer[++tot]=n.value;
	// }
	void display(int n) {
		for (int i = 1;i<n;i++) {
			printf ("%d ",answer[i]);
		}
		printf ("%d\n",answer[n]); 
	}
	int rear = 0,head = 0;
	int t = 2;
	int queue[10001];
	void first_queue(node n,node N[]){
		if (n.value == 0 ||n.value == -1)
		{
			return;
		}
		int a;
		if(n.left != -1 && n.left != 0)queue[head++] = n.left;
		if(n.right != -1 && n.right != 0)queue[head++] = n.right;
		if(rear < head)a = queue[rear++];
		first_queue(N[a],N);
	}

	void second_queue(){

	}
	
	// void level_order(node n,node N[],int a[]){
	// 	if (n.value == -1 ||n.id == 0)
	// 	{
	// 		return;
	// 	}
	// 	int left_id,right_id;
	// 	left_id = (2*n.id);
	// 	right_id = (2*n.id)+1;
	// 	if(n.left != 0 & n.left != -1){
	// 		a[left_id] = n.left;
	// 		N[n.left].id = left_id;
	// 	}
	// 	if(n.right != 0 & n.right != -1){
	// 		a[right_id] = n.right;
	// 		N[n.right].id = right_id;
	// 	}
		
	// 	level_order(N[n.left],N,a);
	// 	level_order(N[n.right],N,a);
	// }
	
	int main(int argc, char const *argv[])
	{
		node N[10001];
		int n;
		scanf("%d",&n);
		int a,b,c;	
		for (int i = 1; i <= n; i++){
		//	N[i].id = 0;
	    	N[i].value = 0;
			N[i].left = 0;
			N[i].right = 0; 
	    	N[i].father = -2;
		}
		
		N[0].value = 0;
		
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d %d", &a, &b, &c);
			N[a].value=a;
			if(b != -1){
				N[a].left = b;
				N[b].father = a;
			}
			if(c != -1){
				N[a].right = c;
				N[c].father = a;
			}
		}
		
		node nn; 
		nn = find_root(n,N);
		answer[1] = nn.value;
		first_queue(nn,N);
		rear = 0;
		while(rear < head){
			answer[t++] = queue[rear++];
		}
		display(n);
		// nn.id = 1;
		/*
		tot=0;
		pre_order(nn,N);
		display(n);	
		tot=0;
		in_order(nn,N);
		display(n);		
		tot=0;
		post_order(nn,N);
		display(n);
		*/
		
		// int num[10001];
		// for(int i = 1; i < 10001; ++i){
		// 	num[i] = -1;
		// }
		// num[1]=nn.value;
		// level_order(nn,N,num);
		
//		for (int i = 0; i < n; ++i)
//		{
//			printf("%d %d %d\n", N[i].value, N[i].left, N[i].right);
//		}
		
		// for(int i = 1,j = 1; i < 10001; ++i){
		// 	if(num[i] != -1 & num[i] != 0){
		// 		answer[j++] = num[i];
		// 	}
		// }
		// display(n);
		
		return 0;
	}
