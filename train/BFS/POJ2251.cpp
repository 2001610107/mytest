
/*
 * 问题描述：一个有许多障碍物的3D的迷宫，给起点和终点，问你是否能从起点走到终点，如果能最快要几分钟（移动一步一分钟）；能够走到输出时间，否则输出Trapped。
 *
 * 提交状态： AC.
 *
 * AC 结果： Memory: 378K Time: 47MS
 *
 * 解题方法1：进行三维（六个方向）的bfs，一层层往外搜，遇到终止条件就结束搜索。
 *
 * 解题方法2 （可选）：
 *
 * 出错次数：3
 *
 * 错误原因 （可选）：
 *
 * 心得体会 （可选）：
 */


#include<iostream>
#include<queue>
#include<cstring>
#define maxn 35
using namespace std;

bool used[maxn][maxn][maxn];
int L, R, C;
char map[maxn][maxn][maxn];
int dir[6][3] = { {0,0,1},{0,0,-1},{1,0,0},{-1,0,0},{0,1,0},{0,-1,0} };
typedef struct {
	int x, y, z;
	int step;

}node;
node S; //Æðµã
node E;  //ÖÕµã

int BFS(node start)
{
	queue<node>q;
	q.push(start);
	while (!q.empty())
	{
		node temp = q.front();
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			node new_node;
			new_node.x = temp.x + dir[i][0];
			new_node.y = temp.y + dir[i][1];
			new_node.z = temp.z + dir[i][2];
			new_node.step = temp.step + 1;
			if (!used[new_node.x][new_node.y][new_node.z] && new_node.x >= 1 && new_node.x <= L && new_node.y >= 1 && new_node.y <=R && new_node.z >= 1 && new_node.z <= C && map[new_node.x][new_node.y][new_node.z] != '#')
			{
				used[new_node.x][new_node.y][new_node.z] = 1;
				if (map[new_node.x][new_node.y][new_node.z] == 'E')
					return new_node.step;
				q.push(new_node);
			}
		}
	}
	return -1;
}
int main()
{
	while (cin >> L >> R >> C)
	{
		if (L == 0 && R == 0 && C == 0)
			break;
		memset(used, 0, sizeof(used));
		for (int i = 1; i <= L; i++)
		{
			for (int j = 1; j <= R; j++)
			{
				for (int k = 1; k <= C; k++)
				{
					cin >> map[i][j][k];
					if (map[i][j][k] == 'S')
					{
						S.x = i;
						S.y = j;
						S.z = k;
						S.step = 0;
					}
					if (map[i][j][k] == 'E')
					{
						E.x = i;
						E.y = j;
						E.z = k;
					}

				}
			}
		}
		int t = BFS(S);
		if (t != -1)
		{
			cout << "Escaped in " << t << " minute(s)." << endl;
		}
		else
			cout << "Trapped!" << endl;
	}
	return 0;
}
