#include <iostream>

class TicTacToe
{
private:
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    bool player_is_x = true;
    bool playing = true;

    bool check_line(int pos, int step) const
    {
        char val = board[pos];
        pos += step;
        if (board[pos] != val) { return false; }
        pos += step;
        if (board[pos] != val) { return false; }
        return true;
    }

    bool check_win() const
    {
        for (int i = 0;  i < 3;  ++i) {
            // horizontal line?
            if (check_line(i*3, 1)) { return true; }
            // vertical line?
            if (check_line(i, 3)) { return true; }
        }
        // diagonals
        return check_line(0, 4) || check_line(2, 2);
    }

    bool check_draw() const
    {
        for (char c: board) {
            if (c == ' ') {
                return false;
            }
        }
        return true;
    }

    friend std::ostream& operator<<(std::ostream&, const TicTacToe&);

public:
    bool play_move(int index);
    void play();
};

bool TicTacToe::play_move(int index)
{
    if (index >= 0 && index < 9 && board[index] == ' ')
    {
        board[index] = player_is_x ? 'X' : 'O';
        player_is_x = !player_is_x;
        return true;
    }
    return false;
}

void TicTacToe::play()
{
    while (playing)
    {
        std::cout << *this;
        int input;
        std::cout << "Play your move " << (player_is_x ? 'X' : 'O') << std::endl;
        std::cin >> input;
        if (!std::cin || !play_move(input)) {
            std::cerr << "Input error or invalid move\n";
            return;
        }

        if (check_win())
        {
            std::cout << *this;
            std::cout << (player_is_x ? "X" : "O") << " wins the game!\n";
            break;
        }
        if (check_draw())
        {
            std::cout << "Draw!\n";
            break;
        };
    }
}

std::ostream& operator<<(std::ostream& os, const TicTacToe& game)
{
    for (int i = 0; i < 9; i++)
    {
        if (i == 1 || i == 2 || i == 4 || i == 5 || i == 7 || i == 8)
        {
            os << " | ";
        }
        os << game.board[i];
        if (i == 2 || i == 5)
        {
            os << std::endl;
            os << "---------" << std::endl;
        }
    }
    return os;
}

int main()
{
    TicTacToe game;
    game.play();
    return 0;
}