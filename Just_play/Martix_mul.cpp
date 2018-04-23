/*************************************************************************
	> File Name: a.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年08月23日 星期三 13时13分53秒
 ************************************************************************/

#include <iostream>
#include <omp.h>
#include <math.h>
#include <stdio.h>  
#include <time.h>  
#define MAX 2000  
using namespace std;
int A[MAX][MAX], B[MAX][MAX];
long long C[MAX][MAX];

void solve(int n)
{
	int i, j, t, k;
	float paralleltime, serialtime;
	double startTime, endTime;
	long long sum;

	for (i = 0; i<n; i++)
	{
		t = i + 1;
		for (j = 0; j<n; j++)
		{
			A[i][j] = t++;
			B[i][j] = 1;
		}
	}

	startTime = omp_get_wtime();
	sum = 0;
#pragma omp parallel shared(A,B,C) private(i,j,k)  
	{
#pragma omp for schedule(dynamic,50)  
		for (i = 0; i<n; i++)
		{
			for (j = 0; j<n; j++)
			{
				C[i][j] = 0;
				for (k = 0; k<n; k++)
				{
					C[i][j] += A[i][k] * B[k][j];
				}
			//	printf("C[%d][%d]=%d ThreadId = %d\n",i,j, C[i][j], omp_get_thread_num());
			}
			//printf("ThreadId = %d\n",omp_get_thread_num());
			
		}
	}

//	for (i = 0; i<n; i++)
//		for (j = 0; j<n; j++)
//			sum += C[i][j];

	endTime = omp_get_wtime();
	paralleltime = endTime - startTime;
//	cout << "矩阵C所有元素和为:" << sum <<" ";
		cout << "并行计算时间为:" << paralleltime << "s" << endl;

	startTime = omp_get_wtime();
	sum = 0;
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
		{
			C[i][j] = 0;
			for (k = 0; k<n; k++)
			{
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
//	for (i = 0; i<n; i++)
//		for (j = 0; j<n; j++)
//			sum += C[i][j];
	endTime = omp_get_wtime();
	serialtime = endTime - startTime;

	double relative_speedup = serialtime / paralleltime;

//	cout << "矩阵C所有元素和为:" << sum << " ";
	cout << "串行计算时间:" << serialtime << "s"<<endl;
	cout << "相对加速比为:" << relative_speedup ;

}


int main()
{
	int n;
	cout << "请输入矩阵的节数（整数N<=2000):";
	while (cin >> n)
	{
		cout << "你输入的矩阵节数为:"<<n<<endl;
			solve(n);
	}
	return 0;

}
