//#define _CRT_SECURE_NO_WARNINGS
//#include <cstdio>
//#include <utility>
//#include <queue>
//#include <algorithm>
//using namespace std;
//
//long long ACM(vector<int>, vector< vector<int> > graph, vector<int>, int, int);
//
//int main(void)
//{
//	int T;
//	scanf("%d", &T);
//
//	while (T--)
//	{
//		int N, K, W;
//		scanf("%d %d", &N, &K); // N : �ǹ����� ,  K : ��Ģ����
//
//		vector<int> ct; // construction time
//		vector< vector<int> > graph; // u -> v ����
//		vector<int> degree;
//		degree.resize(N + 1);
//		graph.resize(N + 1);
//		for (int i = 0; i < N; i++)
//		{
//			int time;
//			scanf("%d", &time);
//			ct.push_back(time);
//		}
//
//		while (K--)
//		{
//			int u, v;
//			scanf("%d %d", &u, &v);
//			graph[u].push_back(v);
//			degree[v]++;
//		}
//
//		scanf("%d", &W);
//
//		printf("%lld\n", ACM(ct, graph, degree, N, W));
//	}
//	return 0;
//}
//
//long long ACM(vector<int> ct, vector< vector<int> > graph, vector<int> degree, int N, int W)
//{
//	/*  ���������� 0�ξֵ�κ��� �����ؼ�
//	������ ������ ���������� -1��Ű�鼭 ����ð� ����
//	*/
//	vector<long long> res; // return res[W]
//	queue<int> zeroDegree;
//	res.resize(N + 1);
//
//	for (int i = 1; i <= N; i++) //�ʱ�ȭ ,, W�� ó������ ���������� 0�ξֵ� �� �ϳ��ϼ���..
//		res[i] = (long long)ct[i - 1];
//
//	for (int i = 1; i <= N; i++)
//		if (!degree[i])
//			zeroDegree.push(i);
//
//	while (!zeroDegree.empty())
//	{
//		int cur = zeroDegree.front();
//		zeroDegree.pop();
//		if (cur == W)
//			return res[W];
//
//		int len = graph[cur].size();
//		for (int i = 0; i < len; i++)
//		{
//			int next = graph[cur][i];
//			res[next] = max(res[next], res[cur] + (long long)ct[next - 1]);
//			degree[next]--;
//			if (!degree[next])
//			{
//				zeroDegree.push(next);
//				if (next == W)
//					return res[W];
//			}
//		}
//	}
//
//	return res[W];
//}