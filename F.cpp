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
		if (n.value == 0)
		{
			return;
		}
		
		if(n.left != -1)post_order(N[n.left],N);
		if(n.right != -1)post_order(N[n.right],N);
		answer[tot++]=n.value;
		//printf("%d ", n.value);
	}
	
	void display(int n) {
		for (int i = 1;i<n;i++) {
			printf ("%d ",answer[i]);
		}
		printf ("%d\n",answer[n]); 
	}
	
	void pre_in_to_post(node N[],int pre[],int in[],int n){
		if(pre[2] == 0 || in[2] == 0){
			N[pre[1]].value = pre[1];
			return;
		}
		
		int left,right;
		int count;
		int middle;
		int left_pre[10001];
		int left_in[10001];
		int right_pre[10001];
		int right_in[10001];
		int i = 1;
		
		middle = pre[1];
		N[middle].value = middle;
		while(in[i] != middle){
			//截取左子树 
			
			left_pre[i] = pre[i+1];
			left_in[i] = in[i];
			i++;
		}
		//没有左子树的情况 
		if(i == 1){
			N[middle].left = -1;
			right = pre[2];
			N[middle].right = right;
			N[right].father = middle;
			N[right].value = right;
		}
		//有左子树 
		if(i > 1){
			left = pre[2];
			N[middle].left = left;
			N[left].father = middle;
			N[left].value = left;
		//把左边遍历完了后的第二个为右子树的根 
			if(pre[i+1] != 0){
		//如果有右子树 
				right = pre[i+1]; 
				N[middle].right = right;
				N[right].father = middle;
				N[right].value = right;
			}else{
		//没有右子树 
				N[middle].right = -1;
			}
		} 
	
		i++;
		int j=1;
		while(i <= n){
			//截取右子树
			right_pre[j] = pre[i];
			
			right_in[j] = in[i];
			i++;
			j++;
		}
		
		 
		if(N[middle].left != -1)pre_in_to_post(N,left_pre,left_in,n);
		if(N[middle].right != -1)pre_in_to_post(N,right_pre,right_in,n);
		 
		
	}
	/*
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
		node N[10001];
		int a[10001];
		int b[10001];
		int n;
		scanf("%d",&n);	
		for (int i = 1; i <= 10000; ++i)
		{
			a[i] = 0;
			b[i] = 0;
		}
		
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d",&a[i]);
		}
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d",&b[i]);
		}
		
		for(int i = 1;i <= n; i++){
			N[i].value = 0;
			N[i].left = -1;
			N[i].right = -1;
			N[i].father = -2;
		}
		
		pre_in_to_post(N,a,b,n);
		
		node x;
		x = find_root(n,N);
		
		tot=1;
		post_order(x,N);
		display(n);
		
		for(int i = 1;i <= n;i++){
			printf("%d %d %d\n",N[i].value,N[i].left,N[i].right);
		}
		
		
		return 0;
	}
