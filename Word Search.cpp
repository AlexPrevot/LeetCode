class Solution {
public:

    bool exist(vector<vector<char>>& board, string& word, int x, int y, int idx) {
        if (idx >= word.size()) return true;
        if (x >= board.size() || y >= board[0].size()) return false;
        if (x < 0 || y < 0) return false;

        if (board[x][y] != word[idx]) return false;

        char curr = board[x][y];
        board[x][y] = '!';

        bool in = false;

        in = in || exist(board, word, x + 1, y, idx + 1);
        in = in || exist(board, word, x, y + 1, idx + 1);
        in = in || exist(board, word, x - 1, y, idx + 1);
        in = in || exist(board, word, x, y - 1, idx + 1);

        board[x][y] = curr;

        return in;
    }

    bool exist(vector<vector<char>>& board, string& word) {
        int N = word.size();
        int left = word.find_first_not_of(word[0]);
        int right = N - word.find_last_not_of(word[N - 1]);
        if (left > right) reverse(begin(word), end(word));

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (exist(board, word, i, j, 0)) return true;
            }
        }

        return false;
    }
};