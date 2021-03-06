/*
 * 问题描述：输入长度为n的m个字符串，每个字符串由A，C，G，T组成。按照每个字符串的逆序数大小一次输出每个字符串。
 *
 * 解题方法：“most sorted”是指逆序数最小；相反，“least sorted”是指逆序数最大；每输入一行字符串就统计该行字符串的逆序数，以逆序数由小到大进行排序输出。
 *
 * 提交状态： AC .
 *
 * AC 结果： Memory: 212K Time: 47MS
 *
 * 出错次数：5
 *
 * 错误原因 （可选）：对多重循环的条件出现把握控制不好
 *
 * 心得体会 （可选）：这道题虽然花了不少时间，但是还是有收获的，debug能力在不断提升
 */

#include"iostream"
#include"string"

using namespace std;
typedef struct DNAdata {
    char name[51];
    int x;
    DNAdata() {
        x = 0;
    }
} DNAdata;

void SwapDNA(DNAdata* a, DNAdata* b) {
    DNAdata tempDNA;
    tempDNA = *a;
    *a = *b;
    *b = tempDNA;
}


void solution(int n, int m, DNAdata DNA[]) {
    char temp;
    for (int i = 0; i <m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> DNA[i].name[j];
        }
        for (int j = 0; j <n; j++)
        {
            temp = DNA[i].name[j];
            for (int k = j+1; k <n; k++)
            {
                if (temp> DNA[i].name[k])
                {
                    ++DNA[i].x;
                }
            }
        }
    }
    for (int i = 0; i !=m; i++) {
        for (int j = i; j > 0 && DNA[j - 1].x > DNA[j].x; --j) {
            SwapDNA(&DNA[j - 1], &DNA[j]);
        }
    }
    for (int i = 0; i <m; i++) {
        for (int j = 0; j <n; j++) {
            cout << DNA[i].name[j];
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    DNAdata DNA[101];
    cin >> n >> m;
    solution(n, m, DNA);
}
