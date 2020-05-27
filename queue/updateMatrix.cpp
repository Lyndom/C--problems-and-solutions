/*
542. 01 矩阵
给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。

两个相邻元素间的距离为 1 。

示例 1:
输入:

0 0 0
0 1 0
0 0 0
输出:

0 0 0
0 1 0
0 0 0
示例 2:
输入:

0 0 0
0 1 0
1 1 1
输出:

0 0 0
0 1 0
1 2 1
注意:

给定矩阵的元素个数不超过 10000。
给定矩阵中至少有一个元素是 0。
矩阵中的元素只在四个方向上相邻: 上、下、左、右。

*/

vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector< pair<int, int> > dirs = { make_pair(-1,0) , make_pair(1,0), make_pair(0, -1), make_pair(0,1) };
        int len1 = matrix.size();
        int len2 = matrix[0].size();
        queue<pair<int, int> > q;
        for (int i = 0; i < len1; i++)
        {
            for(int j = 0; j < len2; j++)
            {
                if (matrix[i][j] == 0)
                {
                    q.push(make_pair(i, j));
                }
                else
                {
                    matrix[i][j] = INT_MAX;
                }
            }
        }
        int x, y;
        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();
            for (auto dir : dirs)
            {
                x = cur.first + dir.first;
                y = cur.second + dir.second;
                if (x < 0 || x >= len1 || y < 0 || y >= len2 || matrix[x][y] <= matrix[cur.first][cur.second] + 1)
                {
                    continue;
                }
                q.push(make_pair(x, y));
                matrix[x][y] = matrix[cur.first][cur.second] + 1;

            }
        }
        return matrix;
    }