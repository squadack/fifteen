#ifndef MYSCENE_H
#define MYSCENE_H

#include <QtGui>
#include <QGraphicsScene>
#include "Kafel.h"

class MyScene : public QGraphicsScene
{
	Q_OBJECT;
	Kafel *board[16];
	qint32 free_space;
	QPixmap obraz;
	
	void move(qint32 x);
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

public:
	MyScene(QObject *parent = nullptr);
	~MyScene();
	
public slots:
	void check();
	
protected:
	void keyPressEvent(QKeyEvent *keyEvent);
	
};



#endif
