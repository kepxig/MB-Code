#include <iostream>
using namespace std;
#define MAX 100
int res_num;
// ���Ԫ���ݴ���res������
int res[MAX];
int p = 0;
// ��n���в��
void resolve(int n, int min_factor = 1);
void resolve(int n, int min_factor)
{
    if (n <= 0)
    { // ����
        for (int i = 0; i < p; i++)
            cout << res[i] << " ";
        cout << endl;
        res_num++;
    }

    for (int i = min_factor; i <= n; i++)
    { // �˴��޸�
        res[p] = i;
        p++;               // p++ ��˳��洢�������Ԫ��
        resolve(n - i, i); // �˴��޸�
        p--;               // ���б����У�ִ������һ�У���һ��forѭ�����ܻ���
    }
}
int main()
{
    while (1)
    {
        int n;
        cin >> n;
        resolve(n, 1);
        cout << "total num of res:\t" << res_num << endl;
        res_num = 0;
    }
    return 0;
}