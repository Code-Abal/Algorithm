using namespace std;
#include <iostream>
#include <queue>
#include <vector>

inline int getChar();
inline int readChar();
inline void readString(char* out);
template <class T = int>
inline T readInt();
template <class T>
inline void writeInt(T x, char end = 0);
inline void writeChar(int x);
inline void writeString(const char* s);
constexpr int kInBufSize = 1 << 18;
constexpr int kOutBufSize = 1 << 18;

const int INF = 1e9 + 1004;
const int MAX_N = 504;

vector<pair<int, int>> graph[MAX_N];
vector<int> predist[MAX_N];
int visited_remove[MAX_N];
int dist[MAX_N];

int N, M, start, target;

int init();
void dijkstra(int start);
void remove_dijkstra_path(int node);
void print();
void remove_path();

int init()
{
	N = readInt();
	M = readInt();
	if (N == 0 && M == 0) return 0;
	start = readInt();
	target = readInt();

	for (int i = 0; i < MAX_N; i++) { graph[i].clear(); predist[i].clear();}

	for (int i = 0; i < M; i++)
	{
		int from = readInt();
		int to = readInt();
		int cost = readInt();
		graph[from].push_back({ cost, to });
	}
	return 1;
}

void dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	fill(dist, dist + MAX_N, INF);

	dist[start] = 0;
	// first = cost, second = to(node)
	pq.push({ dist[start], start });

	while (!pq.empty())
	{
		auto cur = pq.top(); pq.pop();
		if (dist[cur.second] != cur.first) continue;
		for (const auto& next : graph[cur.second])
		{
			if (dist[next.second] > dist[cur.second] + next.first)
			{
				dist[next.second] = dist[cur.second] + next.first;
				pq.push({ dist[next.second], next.second });
				predist[next.second].clear();
				predist[next.second].push_back(cur.second);
			}
			else if (dist[next.second] == dist[cur.second] + next.first) 
				predist[next.second].push_back(cur.second);
		}
	}
}

void remove_dijkstra_path(int node)
{
	if (node == start) return;
	if (visited_remove[node]) return;

	visited_remove[node] = true;

	for (int next : predist[node])
	{
		for (int idx = 0; idx < graph[next].size(); idx++)
		{
			if (graph[next][idx].second == node)
			{
				graph[next].erase(graph[next].begin() + idx);
				break;
			}
		}
		remove_dijkstra_path(next);
	}
}

void remove_path()
{
	fill(visited_remove, visited_remove + MAX_N, false);
	remove_dijkstra_path(target);
}

void print()
{
	if (dist[target] == INF) cout << "-1\n";
	else cout << dist[target] << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (init())
	{
		dijkstra(start);
		if (dist[target] == INF) { print(); continue; }
		remove_path();
		dijkstra(start);
		print();
	}
	return 0;
}

/* FastIO */
// https://github.com/justiceHui/AlgorithmImplement/blob/master/misc/FastInput.cpp
inline int getChar() {
	static char buf[kInBufSize];
	static int len = 0, pos = 0;
	if (pos == len) pos = 0, len = fread(buf, 1, kInBufSize, stdin);
	if (pos == len) return -1;
	return buf[pos++];
}
inline int readChar() {
	int c = getChar();
	while (c <= 32) c = getChar();
	return c;
}
inline void readString(char* out) {
	int c = getChar();
	while (c <= 32) c = getChar();
	do {
		*(out++) = c;
		c = getChar();
	} while (c > 32);
	*out = 0;
}
template <class T>
inline T readInt() {
	int s = 1, c = readChar();
	T x = 0;
	if (c == '-') s = -1, c = getChar();
	while ('0' <= c && c <= '9') x = x * 10 + c - '0', c = getChar();
	return s == 1 ? x : -x;
}
static int write_pos = 0;
static char write_buf[kOutBufSize];
inline void writeChar(int x) {
	if (write_pos == kOutBufSize)
		fwrite(write_buf, 1, kOutBufSize, stdout), write_pos = 0;
	write_buf[write_pos++] = x;
}
template <class T>
inline void writeInt(T x, char end) {
	if (x < 0) writeChar('-'), x = -x;
	char s[24];
	int n = 0;
	while (x || !n) s[n++] = '0' + x % 10, x /= 10;
	while (n--) writeChar(s[n]);
	if (end) writeChar(end);
}
inline void writeString(const char* s) {
	while (*s) writeChar(*s++);
}
struct Flusher {
	~Flusher() {
		if (write_pos) fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
	}
} flusher;
