#ifndef Board_h
#define Board_h
#include <vector>
#include "Square.h"
#include "MapGen.h"
#include "MonsterList.h"
#include <cmath>

typedef unsigned int uint;

static int multipliers[4][8] = {
	{ 1, 0, 0, -1, -1, 0, 0, 1 },
	{ 0, 1, -1, 0, 0, -1, 1, 0 },
	{ 0, 1, 1, 0, 0, -1, -1, 0 },
	{ 1, 0, 0, 1, -1, 0, 0, -1 }
	};

enum direction {
	upLeft = 0,
	up = 1,
	upRight = 2,
	left = 3,
	right = 4,
	downLeft  = 5 ,
	down =6,
	downRight =7,
	numDirections = 8
};

class Board {
	MapGen* map;
	Player* player;
	//CaveGen* cave;
    std::vector<Square*> squares;
	std::vector < std::vector<Square*> > gameboard; // 2d vector map
	std::vector < Monster* > monsterList; // differnt entity li
	RandomNum* random = new RandomNum();
    bool upToDate;
    bool inProgress;
    int stepCounter;
    int delay;

    void endTurn();
    void reset();

    void catchUp();
    void behind();

	void lightPlayer(int,int); // lights player on pos x,y

	//C++ shadowcasting implementation - Bj�rn Bergstr�m [bjorn.bergstrom@roguelikedevelopment.org]
	//with code from http://www.roguebasin.com/index.php?title=C%2B%2B_shadowcasting_implementation

	void setVisited(uint,uint,bool);

	void setVisible(uint x, uint y, visibility); //sets the visibility of the cell at the given position.
	bool isOpaque(uint x, uint y) const; //retruns whether the given position holds an opaque cell
	void castLight(uint x, uint y, uint radius, uint row, float startSlope, float endSlope, uint xx, uint xY, uint yx, uint yy,visibility vis);
	void monsterView(uint x, uint y, uint radius, uint row, float startSlope, float endSlope, uint xx, uint xY, uint yx, uint yy,int m);
    void doFov(uint x, uint y);
	void doFov(uint x, uint y,uint radius,visibility vis);
	void doMonsterFov(uint x, uint y,int m);
	bool currentlyViewed(int, int);

	void combat(Monster* m,bool); //bool if player is attacking

	Monster* monsterAt(int, int);
	void spawnMonster();
	void spawnHandler(); //uses step handler to spawn items.

	// Monster Ai Logic
	void MonsterIdle(int);
	void MonsterAi(int); // takes an integer for the index of monsterList
	void monsterHandler();

public:
    Board();
	Board(int);

    void draw();
    void handle(unsigned char);

    void check();

    bool isUpToDate() const;
	bool canMove(int,int);
	bool canMove(int, int, bool);
    ~Board();
};

#endif
