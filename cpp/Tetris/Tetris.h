#pragma once

#include <vector>
#include <graphics.h>
#include "Block.h"

using namespace std;

class Tetris {
public:
	Tetris(int rows, int cols, int left, int top, int blockSize);
	void init(); // ��ʼ��
	void play(); // �_ʼ�Α�

private:
	void ketEvent();
	void updateWindow();
	int getDelay(); // ���ؾ�����һ�ε��ô˺�����ʱ��
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
	bool update; // �Ƿ����
	vector<vector<int>> map;

	int rows;
	int cols;
	int leftMargin;
	int topMargin;
	int blockSize;
	IMAGE imgBg;

	Block* curBlock;
	Block* nextBlock;
	Block bakBlock; // ��ǰ���鱸�ݷ���

	int score; // ��ǰ����
	int highestScore;
	int level; // ��ǰ�ؿ�
	int lineCount; // ��ǰ�Ѿ������˶�����
	bool gameOver; // ��Ϸ�Ƿ����

	IMAGE imgOver;
	IMAGE imgWin;
};