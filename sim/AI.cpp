// AI.cpp
//Implementation of the AI class.
//Represents a player in the game.
//Contains four strategies for the AI to use to make moves.
//Michael Hanlon, Alex Frasca Jan 2018

#include "AI.hpp"

AI::AI(int player) {
//Initializes AI
	initializeArsenal(player);
	done = false;
}

Move AI::choose_random_highest_move(Board board, int player, ofstream &record) {
//Strategy 2. Chooses a random move, prioritizing moves with bigger pieces.
	vector<Move> resultlist;
	resultlist.clear();
	vector<Piece> currpiece;
	currpiece.clear();
	Move move = Move();
	int s = arsenal.size();
	int currsize;
	cout << player << " : " << s << endl;
	//create the vector of all possible unique moves
	for (int i = 0; i < s; i++) {
		currpiece = arsenal[i];
		currsize = currpiece.size();
		for (int x = 0; x < 20; x++) {
			for (int y = 0; y < 20; y++) {
				for (int possmove = 0; possmove < currsize; possmove++) {
					if (board.isLegalMove(currpiece[possmove], x, y)) {
						move = Move(currpiece[possmove], x, y);
						resultlist.push_back(move);
					}
				}
			}
		}
	}
	int length = resultlist.size();
	if (arsenal.size() == 21 && player == 4 && length != 58) {
		for (int i = 0; i < length; i++) {
			resultlist[i].ReturnPiece().print();
			cout << endl;
		}
	}
	record << player << ":" << length << ",";
	cout << player << " : " << length << endl;
	if (length == 0) {
		done = true; //no moves left
		return Move(); //returns a blank move to avoid error
	}

	Move biggest = resultlist[0];
	//find the biggest piece
	for (int i = 1; i < length; i++) {
		if (biggest.ReturnPiece().size() < resultlist[i].ReturnPiece().size())
			biggest = resultlist[i];
	}
	//make the list consist of only the biggest pieces
	for (int i = 0; i < resultlist.size(); i++) {
		if (resultlist[i].ReturnPiece().size() < biggest.ReturnPiece().size()) {
			resultlist.erase(resultlist.begin() + i);
			i--;
		}

	}

	length = resultlist.size();
	int u = rand() % length;
	Piece result = resultlist[u].ReturnPiece();
	int type = result.getType();

	for (size_t i = 0; i < arsenal.size(); i++) {
		if (arsenal[i][0].getType() == type) {
			arsenal.erase(arsenal.begin() + i); // removes the chosen piece from arsenal
		}
	}
	if (arsenal.size() == 0) {
		done = true;
	}
	return resultlist[u];
}

Move AI::choose_random_move_from_vector(Board board, int player, ofstream &record) {
	//Strategy 1. Chooses a random move out of all possible moves. 
	vector<Move> resultlist;
	resultlist.clear();
	vector<Piece> currpiece;
	Move move = Move();
	int s = arsenal.size();
	int currsize;
	cout << player << " : " << s << endl;

	for (int i = 0; i < s; i++) {
		currpiece = arsenal[i];
		currsize = currpiece.size();
		for (int x = 0; x < 20; x++) {
			for (int y = 0; y < 20; y++) {
				for (int possmove = 0; possmove < currsize; possmove++) {
					if (board.isLegalMove(currpiece[possmove], x, y)) {
						move = Move(currpiece[possmove], x, y);
						resultlist.push_back(move);
					}
				}
			}
		}
	}
	int length = resultlist.size();
	if (s == 21 && player == 4 && length != 58) {
		for (int i = 0; i < length; i++) {
			resultlist[i].ReturnPiece().print();
			cout << endl;
		}
	}

	record << player << ":" << length << ",";
	cout << player << " : " << length << endl;

	if (length == 0) {
		done = true; //no moves left
		return Move(); //returns a blank move to avoid error
	}
	int u = rand() % length;
	Piece result = resultlist[u].ReturnPiece();
	int type = result.getType();
	for (size_t i = 0; i < arsenal.size(); i++) {
		if (arsenal[i][0].getType() == type) {
			arsenal.erase(arsenal.begin() + i); // removes the chosen piece from arsenal
		}

	}
	if (arsenal.size() == 0) {
		done = true;
	}
	return resultlist[u];
}

Move AI::aim_for_center(Board board, int player, ofstream &record) {
//Strategy 3. Prioritizes moves with bigger pieces & moves closer to the center.
	vector<Move> resultlist;
	resultlist.clear();
	vector<Piece> currpiece;
	currpiece.clear();
	Move move = Move();
	int s = arsenal.size();
	int currsize;
	cout << player << " : " << s << endl;
	//create the vector of all possible unique moves
	for (int i = 0; i < s; i++) {
		currpiece = arsenal[i];
		currsize = currpiece.size();
		for (int x = 0; x < 20; x++) {
			for (int y = 0; y < 20; y++) {
				for (int possmove = 0; possmove < currsize; possmove++) {
					if (board.isLegalMove(currpiece[possmove], x, y)) {
						move = Move(currpiece[possmove], x, y);
						resultlist.push_back(move);
					}
				}
			}
		}
	}
	int length = resultlist.size();

	record << player << ":" << length << ",";
	cout << player << " : " << length << endl;
	if (length == 0) {
		done = true; //no moves left
		return Move(); //returns a blank move to avoid error
	}

	Move biggest = resultlist[0];
	//find the biggest piece
	for (int i = 1; i < length; i++) {
		if (biggest.ReturnPiece().size() < resultlist[i].ReturnPiece().size())
			biggest = resultlist[i];
	}
	//make the list consist of only the biggest pieces
	for (int i = 0; i < resultlist.size(); i++) {
		if (resultlist[i].ReturnPiece().size() < biggest.ReturnPiece().size()) {
			resultlist.erase(resultlist.begin() + i);
			i--;
		}
	}

	//removes all but the highest priority moves
	int lowestpriority = 10000;
	vector<Move>::iterator it = resultlist.begin();
	while(it != resultlist.end()) {
		(*it).priority = abs(10 - (*it).ReturnX()) * abs(10 - (*it).ReturnY());
		if ((*it).priority <= lowestpriority) {
			lowestpriority = (*it).priority;
			it++;
		}
		else
			it = resultlist.erase(it);
	}
	it = resultlist.begin();
	while (it != resultlist.end()) {
		if ((*it).priority > lowestpriority)
			it = resultlist.erase(it);
		else
			it++;
	}

	int u = rand() % resultlist.size();
	int type = resultlist[u].ReturnPiece().getType();
	for (size_t i = 0; i < arsenal.size(); i++) {
		if (arsenal[i][0].getType() == type) {
			arsenal.erase(arsenal.begin() + i); // removes the chosen piece from arsenal
		}

	}
	return resultlist[u];
}

Move AI::aim_for_corner(Board board, int player, ofstream &record) {
//Strategy 4. Priotitzies bigger moves and moves closer to the player's starting corner.
	vector<Move> resultlist;
	resultlist.clear();
	vector<Piece> currpiece;
	currpiece.clear();
	Move move = Move();
	int s = arsenal.size();
	int currsize;
	cout << player << " : " << s << endl;
	//create the vector of all possible unique moves
	for (int i = 0; i < s; i++) {
		currpiece = arsenal[i];
		currsize = currpiece.size();
		for (int x = 0; x < 20; x++) {
			for (int y = 0; y < 20; y++) {
				for (int possmove = 0; possmove < currsize; possmove++) {
					if (board.isLegalMove(currpiece[possmove], x, y)) {
						move = Move(currpiece[possmove], x, y);
						resultlist.push_back(move);
					}
				}
			}
		}
	}
	int length = resultlist.size();

	record << player << ":" << length << ",";
	cout << player << " : " << length << endl;
	if (length == 0) {
		done = true; //no moves left
		return Move(); //returns a blank move to avoid error
	}

	Move biggest = resultlist[0];
	//find the biggest piece
	for (int i = 1; i < length; i++) {
		if (biggest.ReturnPiece().size() < resultlist[i].ReturnPiece().size())
			biggest = resultlist[i];
	}
	//make the list consist of only the biggest pieces
	for (int i = 0; i < resultlist.size(); i++) {
		if (resultlist[i].ReturnPiece().size() < biggest.ReturnPiece().size()) {
			resultlist.erase(resultlist.begin() + i);
			i--;
		}
	}

	//removes all but the highest priority moves
	int lowestpriority = 10000;
	vector<Move>::iterator it = resultlist.begin();
	//caluculate aim
	int aimx;
	int aimy;
	if (player == 1) {
		aimx = 0;
		aimy = 0;
	}
	else if (player == 2) {
		aimx = 0;
		aimy = 19;
	}
	else if (player == 3) {
		aimx = 19;
		aimy = 19;
	}
	else {
		aimx = 19;
		aimy = 0;
	}
	while (it != resultlist.end()) {
		(*it).priority = abs(aimx - (*it).ReturnX()) * abs(aimy - (*it).ReturnY());
		if ((*it).priority <= lowestpriority) {
			lowestpriority = (*it).priority;
			it++;
		}
		else
			it = resultlist.erase(it);
	}
	it = resultlist.begin();
	while (it != resultlist.end()) {
		if ((*it).priority > lowestpriority)
			it = resultlist.erase(it);
		else
			it++;
	}

	int u = rand() % resultlist.size();
	int type = resultlist[u].ReturnPiece().getType();
	for (size_t i = 0; i < arsenal.size(); i++) {
		if (arsenal[i][0].getType() == type) {
			arsenal.erase(arsenal.begin() + i); // removes the chosen piece from arsenal
		}

	}
	return resultlist[u];
}

bool AI::isDone() {
//Checks if the AI is done (has no mvoes left).
	return done;
}

int AI::returnArsenalSize() {
//Returns the number of pieces left for the player.
	return arsenal.size();
}

void AI::reset(int player) {
//Resets the AI player.
	initializeArsenal(player);
	done = false;
}

bool AI::isUnique(vector<Piece> prevpieces, Piece currpiece) {
//Checks if a piece is unique in a vector of pieces.
	for (size_t i = 0; i < prevpieces.size(); i++) {
		if (currpiece.isEqual(prevpieces[i])) {
			return false;
		}
	}
	return true;
}

void AI::initializeArsenal(int player) {
//Sets the AI's arsenal to all 21 unique pieces.
	arsenal.clear();
	Piece piece;
	vector<Piece> currpieces;
	for (int i = 0; i < 21; i++) {
		piece = Piece(i, player);
		for (int reflect = 0; reflect < 2; reflect++) {
			for (int rotate = 0; rotate < 4; rotate++) {
				if (isUnique(currpieces, piece)) {
					currpieces.push_back(piece);
				}
				piece.rotate(90);
			}
			piece.reflect(false);
		}

		arsenal.push_back(currpieces);
		currpieces.clear();
	}
}

void AI::test() {
//prints the arsenal, for testing purposes.
	for (size_t i = 0; i < arsenal.size(); i++) {
		for (size_t j = 0; j < arsenal[i].size(); j++) {
			arsenal[i][j].print();
		}
		cout << "-------------------" << endl;
	}
}
