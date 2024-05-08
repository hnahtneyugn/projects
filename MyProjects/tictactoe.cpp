#include <iostream>
#include <vector>

using namespace std;

const int MAX = 3;

struct TTTBoard
{
    vector<vector<char>> board;
};

struct Coordinate {
    int x{-1};
    int y{-1};
};

istream& operator>>(istream& is, Coordinate& coordinate) {
    is >> coordinate.x >> coordinate.y;
    return is;
}

TTTBoard generateBoard() {
    TTTBoard board;
    board.board = vector<vector<char>>(3, vector<char>(3, ' '));
    return board;
}

void printBoard(const TTTBoard& board)
{
    cout << "-------------" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "| " << board.board[i][j] << " ";
		}
		cout << "|" << endl;
		cout << "-------------" << endl;
	}

}

bool isMovesLeft(const TTTBoard& board) 
{ 
    for (int i = 0; i<3; i++) 
        for (int j = 0; j<3; j++) 
            if (board.board[i][j]==' ') 
                return true; 
    return false; 
}

bool isGameOver(const TTTBoard& board) {
    // check rows
    for (int x = 0; x < 3; x++) {
        if (board.board[x][0] != ' ' && board.board[x][0] == board.board[x][1] && board.board[x][1] == board.board[x][2]) {
            return false;
        }
    }

    // check columns
    for (int y = 0; y < 3; y++) {
        if (board.board[0][y] != ' ' && board.board[0][y] == board.board[1][y] && board.board[1][y] == board.board[2][y]) {
            return false;
        }
    }

    // check main diagonal
    if (board.board[0][0] != ' ' && board.board[0][0] == board.board[1][1] && board.board[1][1] == board.board[2][2]) {
        return false;
    }

    // check other diagonal
    if (board.board[0][2] != ' ' && board.board[0][2] == board.board[1][1] && board.board[1][1] == board.board[2][0]) {
        return false;
    }

    // check draw
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (board.board[x][y] == ' ') {
                return true;
            }
        }
    }

    return false;
}


int checkbot(const TTTBoard& board, char bot) {
    // check rows
    for (int x = 0; x < 3; x++) {
        if (board.board[x][0] != ' ' && board.board[x][0] == board.board[x][1] && board.board[x][1] == board.board[x][2]) {
            return (board.board[x][0] == bot) ? 10 : -10;
        }
    }

    // check columns
    for (int y = 0; y < 3; y++) {
        if (board.board[0][y] != ' ' && board.board[0][y] == board.board[1][y] && board.board[1][y] == board.board[2][y]) {
            return (board.board[0][y] == bot) ? 10 : -10;
        }
    }

    // check main diagonal
    if (board.board[0][0] != ' ' && board.board[0][0] == board.board[1][1] && board.board[1][1] == board.board[2][2]) {
        return (board.board[0][0] == bot) ? 10 : -10;
    }

    // check other diagonal
    if (board.board[0][2] != ' ' && board.board[0][2] == board.board[1][1] && board.board[1][1] == board.board[2][0]) {
        return (board.board[0][2] == bot) ? 10 : -10;
    }

    return 0;
}

int minimax(const TTTBoard& board, bool isMax, char bot) {
    int score = checkbot(board, bot);

    if (score == 10)
        return score;

    if (score == -10)
        return score;

    if (isMovesLeft(board) == false) 
        return 0;

    if (isMax) {
        int best = -1000;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board.board[i][j] == ' ') {
                    
                    // Board[i][j] = bot;
                    TTTBoard nextBoard = board;
                    nextBoard.board[i][j] = bot;
                    
                    best = max(best, minimax(nextBoard, !isMax, bot));

                    // Board[i][j] = ' ';
                }
            }
        }
        return best;
    }

    else {
        int best = 1000;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board.board[i][j] == ' ') {
                                        
                    TTTBoard nextBoard = board;
                    nextBoard.board[i][j] = (bot == 'O') ? 'X':'O';
                    best = min(best, minimax(nextBoard, !isMax, bot));

                    // Board[i][j] = ' ';
                }
                    
            }
        }
        return best;
    }
}


Coordinate findbestMove(const TTTBoard& board, char bot) {
    int bestVal = -1000;
    Coordinate coordinate;
    coordinate.x = -1;
    coordinate.y = -1;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board.board[i][j] == ' ') {
                    // Board[i][j] = bot;
                    TTTBoard nextBoard = board;
                    nextBoard.board[i][j] = bot;
                    int moveVal = minimax(nextBoard, false, bot);

                    // Board[i][j] = ' ';

                if (moveVal > bestVal) {
                    coordinate.x = i;
                    coordinate.y = j;
                    bestVal = moveVal;
                }
            }
        }
    }
    
    return coordinate;
}

TTTBoard play_game(int gamemode) {
    Coordinate coordinate;
    TTTBoard board = generateBoard();
    char current = 'X', bot;
    bool isRunning = true;

    if (gamemode == 2) {
        bot = 'O';
    } else if (gamemode == 3) {
        bot = 'X';
    } else { // gamemode == 1
        bot = ' ';
    }

    printBoard(board);
    while (isRunning) { 
        if (current != bot) {
            cout << "Make your move:\n";
            cin >> coordinate;

            while (coordinate.x < 1 || coordinate.x > 3 || coordinate.y < 1 || coordinate.y > 3 || board.board[coordinate.x-1][coordinate.y-1] != ' ') {
                cout << "Please move again, comrade!\n";
                cin >> coordinate;      
            }

            int row = coordinate.x - 1;
            int col = coordinate.y - 1;

            board.board[row][col] = current;
        } else {
            Coordinate ans = findbestMove(board, bot);
            int r = ans.x, c = ans.y;
            board.board[r][c] = current;
        }

        printBoard(board);
        current = (current == 'X') ? 'O' : 'X';
        isRunning = isGameOver(board);
    }
    return board;
}

int evaluate(const TTTBoard& board) {
    // check rows
    for (int x = 0; x < 3; x++) {
        if (board.board[x][0] != ' ' && board.board[x][0] == board.board[x][1] && board.board[x][1] == board.board[x][2]) {
            return (board.board[x][0] == 'X') ? 1 : -1;
        }
    }

    // check columns
    for (int y = 0; y < 3; y++) {
        if (board.board[0][y] != ' ' && board.board[0][y] == board.board[1][y] && board.board[1][y] == board.board[2][y]) {
            return (board.board[0][y] == 'X') ? 1 : -1;
        }
    }

    // check main diagonal
    if (board.board[0][0] != ' ' && board.board[0][0] == board.board[1][1] && board.board[1][1] == board.board[2][2]) {
        return (board.board[0][0] == 'X') ? 1 : -1;
    }

    // check other diagonal
    if (board.board[0][2] != ' ' && board.board[0][2] == board.board[1][1] && board.board[1][1] == board.board[2][0]) {
        return (board.board[0][2] == 'X') ? 1 : -1;
    }

    return 0;
}

void print_menu()
{    
    cout << "Choose game mode:\n";
    cout << "1.Player(X) vs Player(O)\n";
    cout << "2.Player(X) vs Computer(O)\n";
    cout << "3.Computer(X) vs Player(O)\n";
}

int choose_game_mode()
{
    int gamemode = 0;
    cin >> gamemode;

    while (gamemode < 1 || gamemode > 3) {
        cout << "Invalid! Please choose again!\n";
        cin >> gamemode;
    }
    return gamemode;
}

int main() {
    print_menu();
    int gamemode = choose_game_mode();
    
    TTTBoard board = play_game(gamemode);

    int result = evaluate(board);
    cout << "Game over!";
    cout << (result > 0 ? "X wins!" : (result < 0 ? "O wins!" : "Draw!")) << "\n";
    return 0;
}
