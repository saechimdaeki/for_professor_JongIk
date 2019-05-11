#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define FALSE 0
#define TRUE 1
 
int m;
int w[3][100] ;
 
int Weight(int k, int p) {
    if (p < 3) 
        return w[p][k];
    else
        return w[0][k] + w[2][k];
 }
 

 
void Print() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < m; j++)
            printf("%d ",w[i][j]);
        printf("\n");
    }
    printf("\n");
 }
 
 int Is_Compare(int op, int cp) {
 
 if (op == 0) {
    if (cp == 1 || cp == 2)
        return TRUE;
    else
        return FALSE;
 }
 else if (op == 1) {
    if (cp == 0 || cp == 2)
        return TRUE;
    else
        return FALSE;
 }
else if (op == 2) {
    if (cp == 0 || cp == 1)
        return TRUE;
    else
        return FALSE;
 }
 else if (op == 3) {
    if (cp == 1)
        return TRUE;
    else
        return FALSE;
 }
 else
    return FALSE;
}
 
int Pebble(int k, int p){
    
    int tmp = 0;
    int max = 0;
    int boolean;
    int q;
    
    if (k == 0)
        return Weight(k, p);
    else {
        max = -999;
        for (q = 0; q < 4; q++) {
            boolean = Is_Compare(p, q);
            if (boolean) {
                tmp = Pebble(k - 1, q);
                if (tmp > max)
                max = tmp;
            }
        }
    }
 return max + Weight(k, p);
}
 
 
int main() {
    
int value, max = -999;

cin>>m;

for(int i=0; i<3; i++)
{
	for(int j=1; j<=m; j++)
	cin>>w[i][j];
 } 

Print();
 
for (int p = 1; p <= 4; p++) {
    value = Pebble(m , p);
    if (max < value)
        max = value;
 }
 printf("Max is %d\n",max);
   
return 0;
}


