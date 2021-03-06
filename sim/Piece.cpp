/****************************************************************************************************************
 //  Piece.cpp (Implementation File)
 //
 //  Contents: Gives the implementation for the piece object.
 //  Author: Michael Hanlon, Alex Frasca
 //  Written: 11/19/17
 ****************************************************************************************************************/

#include <iostream>
#include "Piece.hpp"
#include <vector>

using namespace std;

Piece::Piece() {
    /*************************************************************************************************
     Pre: None
     Post: Piece object is initialized
     *************************************************************************************************/
    player = 1;
    height = 0;
    width = 0;
    coords[0][0] = 1;
    piecetype = -1;
} //constructor

Piece::Piece(int piece_type, int who) {
    /*************************************************************************************************
     Pre: None
     Post: Piece object is initialized with specifics
     *************************************************************************************************/
    player = who;
    initialize(piece_type);
} //end piece

void Piece::initialize(int piece_type) {
    /*************************************************************************************************
     Pre: None
     Post: Initializes piece as one of 21 possible pieces, stored as a 2D array
     *************************************************************************************************/
  piecetype = piece_type;
    switch(piece_type) {
        case 0:
            height = 1;
            width = 1;
            coords[0][0] = player;
            break;
        case 1:
            height = 1;
            width = 2;
            coords[0][0] = player;
            coords[0][1] = player;
            break;
        case 2:
            height = 2;
            width = 2;
            for(int i = 0; i < height; i++) {
                for(int j = 0; j < width; j++) {
                    coords[i][j] = player;
                }
            }
            coords[1][0] = 0;
            break;
        case 3:
            height = 1;
            width = 3;
            for(int i = 0; i < width; i++) {
                coords[0][i] = player;
            }
            break;
        case 4:
            height = 2;
            width = 2;
            for(int i = 0; i < height; i++) {
                for(int j = 0; j < width; j++) {
                    coords[i][j] = player;
                }
            }
            break;
        case 5:
            height = 2;
            width = 3;
            for(int i = 0; i < height; i++) {
                for(int j = 0; j < width; j++) {
                    coords[i][j] = player;
                }
            }
            coords[0][0] = 0;
            coords[0][2] = 0;
            break;
        case 6:
            height = 1;
            width = 4;
            for(int i = 0; i < width; i++) {
                coords[0][i] = player;
            }
            break;
        case 7:
            height = 2;
            width = 3;
            for(int i = 0; i < height; i++) {
                for(int j = 0; j < width; j++) {
                    coords[i][j] = player;
                }
            }
            coords[0][0] = 0;
            coords[0][1] = 0;
            break;
        case 8:
            height = 2;
            width = 3;
            for(int i = 0; i < height; i++) {
                for(int j = 0; j < width; j++) {
                    coords[i][j] = player;
                }
            }
            coords[0][0] = 0;
            coords[1][2] = 0;
            break;
        case 9:
            height = 2;
            width = 4;
            for(int i = 0; i < height; i++) {
                for(int j = 0; j < width; j++) {
                    coords[i][j] = player;
                }
            }
            coords[0][1] = 0;
            coords[0][2] = 0;
            coords[0][3] = 0;
            break;
        case 10:
            height = 3;
            width = 3;
            for(int i = 0; i < height; i++) {
                for(int j = 0; j < width; j++) {
                    coords[i][j] = player;
                }
            }
            coords[0][0] = 0;
            coords[0][2] = 0;
            coords[1][0] = 0;
            coords[1][2] = 0;
            break;
        case 11:
            height = 3;
            width = 3;
            for(int i = 0; i < height; i++) {
                for(int j = 0; j < width; j++) {
                    coords[i][j] = player;
                }
            }
            coords[0][1] = 0;
            coords[0][2] = 0;
            coords[1][1] = 0;
            coords[1][2] = 0;
            break;
        case 12:
            height = 2;
            width = 4;
            for(int i = 0; i < height; i++) {
                for(int j = 0; j < width; j++) {
                    coords[i][j] = player;
                }
            }
            coords[0][0] = 0;
            coords[1][2] = 0;
            coords[1][3] = 0;
            break;
        case 13:
            height = 3;
            width = 3;
            for(int i = 0; i < height; i++) {
                for(int j = 0; j < width; j++) {
                    coords[i][j] = player;
                }
            }
            coords[0][0] = 0;
            coords[0][1] = 0;
            coords[2][1] = 0;
            coords[2][2] = 0;
            break;
        case 14:
            height = 5;
            width = 1;
            for(int i = 0; i < height; i++) {
                coords[i][0] = player;
            }
            break;
        case 15:
            width = 2;
            height = 3;
            for(int i = 0; i < height; i++) {
                for(int j = 0; j < width; j++) {
                    coords[i][j] = player;
                }
            }
            coords[0][1] = 0;
            break;
        case 16:
            height = 3;
            width = 3;
            for(int i = 0; i < height; i++) {
                for(int j = 0; j < width; j++) {
                    coords[i][j] = player;
                }
            }
            coords[0][0] = 0;
            coords[1][2] = 0;
            coords[2][1] = 0;
            coords[2][2] = 0;
            break;
        case 17:
            width = 2;
            height = 3;
            for(int i = 0; i < height; i++) {
                for(int j = 0; j < width; j++) {
                    coords[i][j] = player;
                }
            }
            coords[1][1] = 0;
            break;
        case 18:
            height = 3;
            width = 3;
            for(int i = 0; i < height; i++) {
                for(int j = 0; j < width; j++) {
                    coords[i][j] = player;
                }
            }
            coords[0][0] = 0;
            coords[1][2] = 0;
            coords[2][0] = 0;
            coords[2][2] = 0;
            break;
        case 19:
            height = 3;
            width = 3;
            for(int i = 0; i < height; i++) {
                for(int j = 0; j < width; j++) {
                    coords[i][j] = player;
                }
            }
            coords[0][0] = 0;
            coords[0][2] = 0;
            coords[2][0] = 0;
            coords[2][2] = 0;
            break;
        case 20:
            height = 2;
            width = 4;
            for(int i = 0; i < height; i++) {
                for(int j = 0; j < width; j++) {
                    coords[i][j] = player;
                }
            }
            coords[0][0] = 0;
            coords[0][2] = 0;
            coords[0][3] = 0;
            break;
            
    } //end switch
} //end initialize

void Piece::rotate_180() {
    /*************************************************************************************************
     Pre: Piece has been initialized with a piece type
     Post: Piece is rotated 180 degrees
     *************************************************************************************************/
    int temp_coords[maxheight][maxwidth];
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            temp_coords[height - 1 - i][width - 1 - j] = coords[i][j];
        }
    }
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            coords[i][j] = temp_coords[i][j];
        }
    }
} //end rotate_180

void Piece::print() {
    /*************************************************************************************************
     Pre: Piece has been initialized with a piece type
     Post: Prints piece to console
     *************************************************************************************************/
    for(int i = 0; i < height; i++) {
        cout << endl;
        for(int j = 0; j < width; j++) {
            if(coords[i][j] == 1) {
                cout << "R";
            } else if(coords[i][j] == 2){
                cout << "Y";
            } else if(coords[i][j] == 3){
                cout << "G";
            } else if(coords[i][j] == 4){
                cout << "B";
            } else {
                cout << ".";
            }
        }
    }
    cout << endl;
} //end print

// Rotate piece by a certain number of degrees
void Piece::rotate(int degrees) {
    /*************************************************************************************************
     Pre: Piece has been initialized with a piece type
     Post: Piece is rotated a quarter, half, or three-quarter clockwise turn
     *************************************************************************************************/
    if(degrees == 180) {
        rotate_180();
    } else if(degrees == 90) {
        //switch width and height
        int temp_width = width;
        width = height;
        height = temp_width;
        
        //move squares
        int new_coords[maxheight][maxwidth];
        for(int i = 0; i < height; i++) {
            for(int j = 0; j < width; j++) {
                new_coords[i][j] = coords[width-j-1][i];
            }
        }
        for(int i = 0; i < height; i++) {
            for(int j = 0; j < width; j++) {
                coords[i][j] = new_coords[i][j];
            }
        }
    } else if(degrees == 270) {
        rotate_180();
        rotate(90);
    }
} //end rotate

void Piece::reflect(bool horiz) {
    /*************************************************************************************************
     Pre: Piece has been initialized with a piece type
     Post: Piece is reflected over either the horizontal or vertical axis, determined by horiz
     *************************************************************************************************/
    int new_coords[maxheight][maxwidth];
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            new_coords[i][j] = coords[i][width-j-1];
        }
    }
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            coords[i][j] = new_coords[i][j];
        }
    }
    if(horiz) {
        rotate_180();
    }
} //end reflect

int Piece::size() {
    /*************************************************************************************************
     Pre: Piece has been initialized with a piece type
     Post: Returns the number of squares in the piece
     *************************************************************************************************/
    int count = 0;
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(coords[i][j] != 0) {
                count++;
            }
        }
    }
    return count;
} //end size

//A function that returns the coordinates of each square in the piece as a 2d vector (list of (x,y) coordinates)
vector<vector<int> > Piece::getCoords() {
vector<vector<int> > points;
for(int i=0; i<height; i++){
	for(int j=0; j<width; j++){
		if(coords[i][j]!=0){
		  vector<int> currpoint;
		  currpoint.push_back(i);
		  currpoint.push_back(j);
		  points.push_back(currpoint);
		}
	}
 }
return points;
}


int Piece::getPlayer(){
  return player;
}

int Piece::getType(){
  return piecetype;
}

bool Piece::isEqual(Piece piece){
  if(getCoords() == piece.getCoords())
    return true;
  else
    return false;
}

bool Piece::hasSingleSymmetry() {
    return (piecetype == 2 || piecetype == 5 || piecetype == 8 || piecetype == 10 || piecetype == 11 || piecetype == 13 || piecetype == 16 || piecetype == 17);
}

bool Piece::hasDoubleSymmetry() {
    return (piecetype == 1 || piecetype == 3 || piecetype == 6 || piecetype == 14);
}

bool Piece::hasQuadSymmetry() {
    return (piecetype == 0 || piecetype == 4 || piecetype == 19);
}













