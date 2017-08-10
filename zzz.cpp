/**
     *======================================================================
     * Course:    Design and Analysis of Algorithms
     *            Data Structures and Algorithms
     *            Summer 2015, School of Computing, NUS
     *            Skeleton Code provided by Jonathan
     *
     * Student:   [student's name]
     * Tutorial:  G2 (for example) 
     * Program:   Name of Program, 
     * Language:  C++
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

#include <vector>
#include <cstdio>
using namespace std;

//int  stack[501];
int top;
int  stack[501];
int N;
int  men_women[501];
	int  women_men[501];

   bool  Bool[501];
   int  man[501][501];
   int  women[501][501];
   int  BranchT[501];

   int inverse[501][501];
 
   int Fiance[501];
void initializeEachPersonFree()
{
	top=0;
   for(int i=0;i<N;i++){
       Bool[i] = true;
       BranchT[i] = -1;
       Fiance[i]=-1;
       stack[++top]=i;
   }

   for(int i=0;i<N;i++){
       for(int j=0;j<N;j++){
           inverse[i][women[i][j]]=j;
       }
   }
}

//return true iff there is a man who is free and has not proposed anyone
bool someManIsFreeAndHasNotProposed()
{
	if  (top!=0) {
        return true;
    }
    return false;
}

//return the index of the man who is free and has not proposed anyone
int chooseThatMan()
{
	return stack[top--];
}

//return the index of the first woman on Man #manIndex's list whom he has not yet proposed
int firstWomanOnManList(int manIndex)
{
				//for(int i=0;i<N;i++){
			//	System.out.print(i+" ");
			//	System.out.print(match[i]+"\n");
				
			//}
	int temp1; 
    ++BranchT[manIndex];
    temp1=BranchT[manIndex];
    return man[manIndex][temp1];
	return 1;
}

//return true iff woman #womanIndex is free
bool isFree(int womanIndex)
{
	return Bool[womanIndex];
}

//assign Man #manIndex and Woman #womanIndex to be engaged
void assign(int manIndex,int womanIndex)
{
	men_women[manIndex]=womanIndex;
 	Bool[womanIndex]=false;
    Fiance[womanIndex]=manIndex;
}

//return true iff Woman #womanIndex prefers Man #firstManIndex to Man #secondManIndex
bool prefers(int womanIndex,int firstManIndex,int secondManIndex)
{
	if(inverse[womanIndex][firstManIndex]<inverse[womanIndex][secondManIndex]){
         return true;
     }
     else 
	 	return false;
}

//set Man #manIndex to be free
void setFree(int manIndex)
{
	men_women[manIndex]=-1;
      stack[++top]=manIndex;
}

//Man #manIndex get rejected by Woman #womanIndex
void rejected(int manIndex,int womanIndex)
{
	stack[++top]=manIndex;
}

//return the index of man who is the fiance of Woman #womanIndex
int fiance(int womanIndex)
{
	return Fiance[womanIndex];
}

void findStableMarriage()
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
		//if (w is free)
		if (isFree(firstWoman)) 
		{
			//assign m and w to be engaged
			assign(freeMan,firstWoman);
		}
		//else if (w prefers m to her fiance¨¬? m')
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
	}
}

int main()
{
     int times;
	 scanf ("%d",&times);
     for(int i=0;i<times;i++){
     	scanf ("%d",&N);
 
         for(int j=0;j<N;j++){
             for(int k=0;k<N;k++){
             	scanf ("%d",&man[j][k]);               
                 man[j][k]--;
             }
         }
         for(int j=0;j<N;j++){
             for(int k=0;k<N;k++){
             	scanf ("%d",&women[j][k]);
                 
                 women[j][k]--;
             }
         }
         findStableMarriage();   
         for(int temp1=0;temp1<N;temp1++){
             men_women[temp1]++;
               int temp2=temp1+1;            
				printf ("%d %d\n",temp2,men_women[temp1]);
         }
     }
	return 0;
}
