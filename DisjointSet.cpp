#include<iostream>
using namespace std;
int max2;//c++�� max�Լ��� �� ���ļ�. 

typedef struct _node* nodeptr;
typedef struct _node{
       nodeptr headp;
       nodeptr next;
}node;

void make_Set(nodeptr N){//n������ �̷����༮ ��������. 
     N->headp = N;
     N->next  = NULL;
}

nodeptr find_Set(nodeptr N){//N�� ���� ���� ã�� 
     if(N->headp == N) return N;
     return find_Set(N->headp);
}

nodeptr find_tail(nodeptr N){//taile�� ã�ƾ� ������ head���̰� �ϴϱ�  
       nodeptr preptr= NULL;
       nodeptr ptr = N;
       
       while(ptr){
              preptr = ptr;    
              ptr = ptr->next;                                 
       }
       
       return preptr;
}
void Union(nodeptr L, nodeptr R){/// L +R ������ 
     nodeptr headL = find_Set(L);
     nodeptr headR = find_Set(R);
     
     if(headL == headR) return;
     
     nodeptr tail = find_tail(L);//taileã�� 
     
     tail->next = headR;
     headR->headp = headL;//������ HEAD ���̱� ��ǥ�ϴ� ���� �ٲٴ�  
}
int count_friends(nodeptr N, int sum){
     if(N->next) return count_friends(N->next, sum+1);
     return sum;
}

void result(node N[], int size){
     int friends = 0;
     for(int i = 0; i<size; i++){ //n�̷�Ʈ�� 
          if((N[i].headp != NULL) && find_Set(&N[i]) == &N[i]){
               friends = count_friends(&N[i], 1);
               if(max2 <= friends) max2 = friends;
          }
     }
}
             

int main(){
    int n,m;
    cin>>n>>m;
    node N[n];
    for(int i = 0; i<n; i++) 
	N[i].headp = NULL;
    
    int tempL; int tempR;
    for(int i = 0; i<m; i++){
            cin>>tempL>>tempR;
            tempL--; tempR--;
            
            if(!N[tempL].headp) 
			make_Set(&N[tempL]);
            if(!N[tempR].headp) 
			make_Set(&N[tempR]);
            
            Union(&N[tempL], &N[tempR]);
    }
    result(N, n);
	cout<<max2;
    
    return 0;
}
