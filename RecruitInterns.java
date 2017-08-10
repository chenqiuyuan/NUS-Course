/**
     *======================================================================
     * Course:    Design and Analysis of Algorithms,
     *            Data Structures and Algorithms
     *            Summer 2015, School of Computing, NUS
     *            Skeleton Code provided by Jonathan
     *
     * Student:   [student's name]
     * Tutorial:  G2 (for example) 
     * Program:   Name of Program, 
     * Language:  Java
     * Purpose:   Skeleton code for Programming Assignment 1.
     *            Student MUST use the skeleton code and fill
     *            in the implementation code necessary to make
     *            it work.
     *      
     *            NOTE: The method findStableMarriage()  
     *                  MUST NOT be modified.
     *
     *========================================================================
*/

import java.util.*;

class RecruitInterns	//this class name must be the same as the file name!
{	
	static int[][] men_women=new int[500][500];
	static int[][] women_men=new int[500][500];
	static int[][] inverse=new int[500][500];
//	static int[][] stack=new int[100][100];
	static int[] s=new int[500];
	
	static int[] match=new int[500];
	static int[] in_match=new int[500];
	static int[] TempMark=new int[500];
	
	static int womanIndex;
	static int manIndex;
	
	static int size=0;
	static int total=0;
//	static int front=0,rear=0;
	
//	private static int pop(int Index,int[][] a){
//		
//		return a[manIndex][--size];
//	}
//	
//	private static void push(int Index,int[][] a,int num){
//		a[manIndex][size++]=num;
//	}
	private static void push(int[] a,int num){
		a[size++]=num;
	}
	
	private static int pop(int[] a){
		return a[--size];
	}
	
//	private static void insert(int Index,int[][] a,int num){
//		
//		a[Index][((rear++)%100)]=num;
//	}
//	
//	private static int remove(int Index,int[][] a){
//		return a[Index][((front++)%100)];
//	}
	
	private static void initializeEachPersonFree()
	{
		
		for(int i=0;i<N;i++){
			in_match[i]=-1;
			match[i]=-1;
			TempMark[i]=0;
		}

		
		for(int i=0;i<N;i++){			
			for(int j=0;j<N;j++){
				int num=xxx.nextInt();
				men_women[i][j]=num;
				
			}
		}
		
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				int num=xxx.nextInt();
				women_men[i][j]=num;
			}
		}
		
		
		
//		for(int i=0;i<N;i++){
//			
//			Scanner m=new Scanner(System.in);
//			String mm=m.toString();
//			String[] S=mm.split(" ");
//			for(int j=0;j<N;j++){
//				int num = Integer.parseInt(S[j]);
//				men_women[i][j]=num;
//			}
//		}	
		
		
//		for(int i=0;i<N;i++){
//			Scanner m=new Scanner(System.in);
//			String mm=m.toString();
//			String[] S=mm.split(" ");
//			
//			for(int j=0;j<N;j++){
//				int num = Integer.parseInt(S[j]);
//				women_men[i][j]=num;
//			}
//		}
		
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				men_women[i][j]=men_women[i][j]-1;
				women_men[i][j]=women_men[i][j]-1;
			}
		}
		
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				inverse[i][women_men[i][j]]=j;
			}
		}
		
		for(int i=N-1;i>=0;i--){
			push(s,i);
		}
		
	}

	//return true if there is a man who is free and has not proposed anyone
	private static boolean someManIsFreeAndHasNotProposed()
	{
//		for(int i=0;i<N;i++){
//			if(match[i]==-1){
//				return true;
//			}
//		}
//		
//		return false;
		if(total==N){
			return false;
		}else{
			return true;
		}
	}

	//return the index of the man who is free and has not proposed anyone
	private static int chooseThatMan()
	{
//		int i;
//		for(i=0;i<N;i++){
//			if( match[i] == -1 )break;
//		}
//		return i;
		return pop(s);
	}

	//return the index of the first woman on Man #manIndex's list whom he has not yet proposed
	private static int firstWomanOnManList(int manIndex)
	{
		
		
		return men_women[manIndex][TempMark[manIndex]++];
		
	}

	//return true iff woman #womanIndex is free
	private static boolean isFree(int womanIndex)
	{
		if(in_match[womanIndex] != -1){
			return false;
		}else{
			return true;
		}

	}

	//assign Man #manIndex and Woman #womanIndex to be engaged
	private static void assign(int manIndex,int womanIndex)
	{
		match[manIndex]=womanIndex;
		in_match[womanIndex]=manIndex;
		total++;
	}

	//return true iff Woman #womanIndex prefers Man #firstManIndex to Man #secondManIndex
	private static boolean prefers(int womanIndex,int firstManIndex,int secondManIndex)
	{
		int i,j;
		if( inverse[womanIndex][firstManIndex] < inverse[womanIndex][secondManIndex] ){
			return true;
		}else{
			return false;
		}
		
		
	}

	//set Man #manIndex to be free
	private static void setFree(int manIndex)
	{
	
		
		match[manIndex]=-1;
		push(s,manIndex);
		total--;
	}

	//return the index of man who is the fiance of Woman #womanIndex
	private static int fiance(int womanIndex)
	{
		return in_match[womanIndex];
	}

	//Man #manIndex get rejected by Woman #womanIndex
	private static void rejected(int manIndex,int womanIndex)
	{
		push(s,manIndex);
	}

	private static void findStableMarriage()
	{
		//Initialize each person to be free.
		initializeEachPersonFree(); 
		//while (some man is free and hasn't proposed to every woman)
		while (someManIsFreeAndHasNotProposed())
		{
			//Choose such a man m
			
			int freeMan = chooseThatMan();
			//w = 1st woman on m's list to whom m has not yet proposed
			int firstWoman = firstWomanOnManList(freeMan);
			
			//System.out.println(freeMan);
			//System.out.println(fiance(firstWoman));
			//System.out.println(men_women[0][0]);
			//System.out.println(firstWomanOnManList(freeMan));
			
			
			//if (w is free)
			if (isFree(firstWoman)) 
			{
				//assign m and w to be engaged
				assign(freeMan,firstWoman);
			}
			//else if (w prefers m to her fiancé m')
			else if (prefers(firstWoman,freeMan,fiance(firstWoman)))
			{
				
				//assign m and w to be engaged, and m' to be free
				setFree(fiance(firstWoman)); assign(freeMan,firstWoman);
			//else
			} else
			{
				//w rejects m
				rejected(freeMan,firstWoman);
			}
			
			//for(int i=0;i<N;i++){
			//	System.out.print(i+" ");
			//	System.out.print(match[i]+"\n");
				
			//}
		
			
		}
	}
	
	static Scanner xxx=new Scanner(System.in);
	static int N;
	
	public static void main(String[] args)
	{
		int times;
		times=xxx.nextInt();
	
		
		for(int i=0;i<times;i++){
			N=xxx.nextInt();
			findStableMarriage();
			for(int x=0;x<N;x++){
				System.out.print((x+1)+" ");
				System.out.print((match[x]+1)+"\n");
			}
		}
		xxx.close();
		
	
	
		//System.out.println(isFree(2));
		
	}
}

