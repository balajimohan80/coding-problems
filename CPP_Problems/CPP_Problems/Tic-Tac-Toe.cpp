#include<iostream>
#include<vector>

//frequently
//https://leetcode.com/problems/design-tic-tac-toe/

class TicTacToe {
public:
	TicTacToe(size_t n) : nSize(n), is_Player_Win(0), winning_Player_ID(-1), mat(n, std::vector<unsigned char>(n, 0)) {};

	int move(size_t row, size_t col, char player_id);

private:
	const size_t nSize;
	bool is_Player_Win;
	char winning_Player_ID;
	std::vector<std::vector<unsigned char>> mat;

	bool horizontal_Scan(size_t row, char player_ID) const {
		for (size_t i = 0; i < nSize; i++) {
			if (mat[row][i] != player_ID)
				return false;
		}
		return true;
	}

	bool vertical_Scan(size_t col, char player_ID) const {
		for (size_t i = 0; i < nSize; i++) {
			if (mat[i][col] != player_ID) {
				return false;
			}
		}
		return true;
	}

	bool leftmost_Diagnal_Scan(char player_ID) const {
		for (size_t i = 0; i < nSize; i++) {
			if (mat[i][i] != player_ID) {
				return false;
			}
		}
		return true;
	}

	bool rightmost_Diagnal_Scan(char player_ID) const {
		size_t right_Most = nSize - 1;
		for (size_t i = 0; i < nSize; i++, --right_Most) {
			if (mat[i][right_Most] != player_ID) {
				return false;
			}
		}
		return true;
	}
};

int TicTacToe::move(size_t row, size_t col, char player_id) {
	if (is_Player_Win) {
		return (winning_Player_ID == player_id) ? 1 : 0;
	}
	mat[row][col] = player_id;
	is_Player_Win = horizontal_Scan(row, player_id) || vertical_Scan(col, player_id) ||
		leftmost_Diagnal_Scan(player_id) || rightmost_Diagnal_Scan(player_id);
	if (is_Player_Win) winning_Player_ID = player_id;
	return is_Player_Win ? static_cast<int>(player_id) : 0;
}


int main() {
	TicTacToe Tic(3);
	std::cout << Tic.move(0, 0, 2) << "\n";
	std::cout << Tic.move(2, 0, 2) << "\n";
	std::cout << Tic.move(1, 0, 2) << "\n";
	return 0;
}
