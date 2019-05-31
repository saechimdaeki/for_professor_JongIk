#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class edge{
public:
    int v1,v2,cost;
};
vector<edge> e;
vector<edge> result; //MST�� ���Ե� ������. ������������ ���ĵ�.
long long Allcost; //MST�� ������ ����
int n,m;
class union_find{
public:
    vector<int> p;        //�θ� �����ϴ� ����
    vector<int> set_size; //�� ���տ� ��� ���ؽ��� �����ϴ°�
    void init(int cnt){   //�׷����� ��� ��尡 �����ϴ���
        p.reserve(10001);
        for(int i=0; i<10001; i++){
            p[i]=i;
            set_size.push_back(1);
        }
    }
    int find_root(int v){
        if(v == p[v]) return v; //�ڽ��� ��Ʈ��� �ǹ��̹Ƿ�
        return find_root(p[v]);//�ڽ��� �θ� Ÿ�� ��� �˻�
    }
    bool same_set(int v1,int v2){return find_root(v1) == find_root(v2);}
    void Union(int v1,int v2){ //v1�� v2�� ���� ������ �ϳ��� �������� ��ħ
        int s1 = find_root(v1);
        int s2 = find_root(v2);
        if(s1 == s2) return;
        if(set_size[s1]<set_size[s2]){
            p[s1] = s2;
            set_size[s2] += set_size[s1];
        
        }else{
            p[s2] = s1;
            set_size[s1] += set_size[s2];
            
        }
    }
};

bool comp(const edge& e1,const edge& e2){ return e1.cost<e2.cost; }

void kruskal(){
    union_find uf;
    uf.init(n);
    for(auto k: e){
        if(!uf.same_set(k.v1,k.v2)){ //v1�� v2�� ���� �����̾ƴҶ���
            uf.Union(k.v1, k.v2); //v1�� v2�� ������������ �����
            cout<<k.cost<<" ";
            Allcost += k.cost;//MST�� cost�� ����������.
            result.push_back(k); //��� MST���Ϳ� ���ο� ����(���翧��) �߰�
            if(result.size() == n-1) //������ ���� ���ؽ��� ������ 1�� ������ MST�ϼ��Ȱ�
                return;
        }
    }
}
int main(){
    cin>>n>>m; //n�� ���ؽ� m�� ������ ��
    for(int i=0; i<m; i++){
        edge ee;
        cin>>ee.v1>>ee.v2>>ee.cost;
        e.push_back(ee);
    }
    sort(e.begin(),e.end(),comp); //������ ��� ������������ ����
	
	
	
	kruskal();

    cout<<Allcost<<endl;

    return 0;
}
