#include "MyScene.h"

void MyScene::move(qint32 x)
{
	if ((0 <= free_space + x && free_space + x < 16) && !(free_space % 4 == 3 && x == 1) && !(free_space % 4 == 0 && x == -1))
	{
// 		qDebug() << "lolz " << free_space << " +x = " << free_space + x;
		auto temp = board[free_space]->pos();
		board[free_space]->setPos(board[free_space + x]->pos());
		board[free_space + x]->setPos(temp);
		
		Kafel *v = board[free_space];
		board[free_space] = board[free_space + x];
		board[free_space + x] = v;
		
		free_space += x;
	}
}

void MyScene::moveUp()
{
	move(4);
}
void MyScene::moveDown()
{
	move(-4);
}
void MyScene::moveLeft()
{
	move(1);
}
void MyScene::moveRight()
{
	move(-1);
}

MyScene::MyScene(QObject *parent)
		: QGraphicsScene(parent),
		free_space(15),
		obraz("../src/image.jpeg")
	{
		obraz = obraz.scaled(4 * Kafel::Bok, 4 * Kafel::Bok);
		for (qint32 i = 0; i < 15; i++)
		{
			board[i] = new Kafel(i, qRgb(0, 255 - 16 * i, 0), QString::number(i));
			board[i]->setPixmap(obraz.copy(i % 4 * Kafel::Bok, i / 4 * Kafel::Bok, Kafel::Bok, Kafel::Bok));
			addItem(board[i]);
			board[i]->setPos(((i % 4) - 2) * Kafel::Bok, ((i / 4) - 2) * Kafel::Bok);
		}
		board[15] = new Kafel(15, qRgb(255, 255, 255));
		board[15]->setPos(((15 % 4) - 2) * Kafel::Bok, ((15 / 4) - 2) * Kafel::Bok);
		addItem(board[15]);
	}
	
MyScene::~MyScene()
{
	for (Kafel *v : board)
		delete v;
}

void MyScene::check()
{
	for (qint32 i = 0; i < 16; i++)
	{
		if (i != board[i]->Number())
		return;
	}
	qDebug() << "JEST K";
}

void MyScene::keyPressEvent(QKeyEvent *keyEvent)
	{
		if (keyEvent->key() == Qt::Key_Up)
		{
			moveUp();
		}
		else if (keyEvent->key() == Qt::Key_Down)
		{
			moveDown();
		}
		else if (keyEvent->key() == Qt::Key_Left)
		{
			moveLeft();
		}
		else if (keyEvent->key() == Qt::Key_Right)
		{
			moveRight();
		}
	}