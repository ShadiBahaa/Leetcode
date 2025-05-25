class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        for (int i = 1; i * i <= n; ++i) {
            squares.push_back(i * i);
        }

        queue<pair<int, int>> q;
        vector<bool> visited(n + 1, false);
        q.push({n, 0});
        visited[n] = true;

        while (!q.empty()) {
            auto [curr, steps] = q.front();
            q.pop();

            if (curr == 0) return steps;

            for (int square : squares) {
                if (curr - square < 0) break;

                if (!visited[curr - square]) {
                    visited[curr - square] = true;
                    q.push({curr - square, steps + 1});
                }
            }
        }

        return -1; // Should never reach here
    }
};
