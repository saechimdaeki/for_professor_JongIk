#include <iostream>
#include <algorithm>
#include<cstring> 
using namespace std;
const int INF = 987654321;//�̰ű׳�  ǥ���Ѱ���  infinite 
int N;
pair<int, int> matrix[100];
int cache[100][100];
//left~right���� �����ϴµ� ���cost
int yoonseo(int left, int right)
{
        if (left == right)
               return 0;
        int &result = cache[left][right];
        if (result != -1)
            return result;
        result = INF;
        for (int i = left; i < right; i++)
               //�� �κ����� ������
               result = min(result, yoonseo(left, i) + yoonseo(i + 1, right) + matrix[left].first*matrix[i].second*matrix[right].second);
        return result;
}
int main()
{
        cin >> N;
        for (int i = 0; i < N; i++)
               cin >> matrix[i].first >> matrix[i].second;
        memset(cache, -1, sizeof(cache));
        cout << yoonseo(0, N - 1) << endl;
        return 0;

}
