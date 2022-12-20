#pragma once

#include <vector>
#include <graphics.h>
#include "Block.h"

using namespace std;

class Tetris {
public:
	Tetris(int rows, int cols, int left, int top, int blockSize);
	void init(); // 初始化
	void play(); // 開始游戲

private:
	void ketEvent();
	void updateWindow();
	int getDelay(); // 返回距离上一次调用此函数的时间
	void drop();
	void clearLine();
	void moveLeftRight(int offset);
	void rotate();
	void drawScore();
	void checkOver();
	void saveScore();
	void displayOver();

private:
	int delay;
	bool update; // 是否更新
	vector<vector<int>> map;

	int rows;
	int cols;
	int leftMargin;
	int topMargin;
	int blockSize;
	IMAGE imgBg;

	Block* curBlock;
	Block* nextBlock;
	Block bakBlock; // 当前方块备份方块

	int score; // 当前分数
	int highestScore;
	int level; // 当前关卡
	int lineCount; // 当前已经消除了多少行
	bool gameOver; // 游戏是否结束

	IMAGE imgOver;
	IMAGE imgWin;
};