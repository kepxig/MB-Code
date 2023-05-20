#include <iostream>
using namespace std;
#define MAX 100
int res_num;
// 拆分元素暂存在res数组中
int res[MAX];
int p = 0;
// 将n进行拆分
void resolve(int n, int min_factor = 1);
void resolve(int n, int min_factor)
{
    if (n <= 0)
    { // 出口
        for (int i = 0; i < p; i++)
            cout << res[i] << " ";
        cout << endl;
        res_num++;
    }

    for (int i = min_factor; i <= n; i++)
    { // 此处修改
        res[p] = i;
        p++;               // p++ 来顺序存储各个拆分元素
        resolve(n - i, i); // 此处修改
        p--;               // 此行必须有，执行完这一行，下一次for循环才能回退
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