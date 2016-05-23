#include<iostream>
#include<string.h>
using namespace std;
#define R 6    //参考模板
#define T 4    //待测模板
#define Min(a,b) ((a)<=(b)?(a):(b))

int main()
{
	int i, j, k;
	int r[R], t[T];
	int distance[T + 1][R + 1] = { {0, 0, 0, 0, 0, 0}, { 0, 2, 3, 5, 4, 1, 2 }, {0, 1, 4, 2, 7, 5, 1 }, {0, 5, 8, 4, 2, 1, 7 }, {0, 1, 2, 3, 4, 6, 5 } };
	int output[T+1][R+1];
	memset(output, 0, sizeof(output));
	
	//待测模板和参考模板
	/*for (i = 0; i < T; i++)
	{
		cin >> t[i];
	}
	for (i = 0; i < R; i++)
	{
		cin >> r[i];
	}
	*/

	//计算点与点之间的欧式距离
	//memset(distance, 0, sizeof(distance));
	//for (i = 1; i < T; i++)
	//{
	//	for (j = 1; j < R; j++)
	//	{
	//		distance[i][j] = (r[j - 1] - t[i - 1])*(r[j - 1] - t[i - 1]); 
	//	}
	//}

    //输出整个欧式距离的矩阵
	for (i = 1; i <= T; i++)
	{
		for (j = 1; j <= R; j++)
		{
			cout << distance[i][j] << '\t';
		}
		cout << endl;
	}	
	cout << endl;
	
	//DP过程，计算DTW距离
	output[0][0] = 0;
	for (i = 1; i <= T; i++)
	{
		
		for (j = 1; j <= R; j++)
		{
			if (i == 1 && j == 1)
			{
				output[i][j] = 2 * distance[1][1];
			}
			else if (i==1)
			{
				output[i][j] = output[i][j - 1] + distance[i][j];
			}
			else if (j == 1)
			{
				output[i][j] = output[i - 1][j] + distance[i][j];
			}
			else
			{
				output[i][j] = Min(Min(output[i - 1][j - 1] + 2 * distance[i][j], output[i][j - 1] + distance[i][j]), output[i - 1][j] + distance[i][j]);
			}
		}
	}

	//输出最后的DTW距离矩阵，其中output[NUM][NUM]为最终的DTW距离和
	for (i = 1; i <= T; i++)
	{
		for (j = 1; j <= R; j++)
		{
			cout << output[i][j] << '\t';
		}
		cout << endl;
	} 

	system("pause");
	return 0;
}