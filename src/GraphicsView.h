#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QtGui>

class GraphicsView : public QGraphicsView
{
	Q_OBJECT;
// public:
// 	void keyPressEvent(QKeyEvent *keyEvent)
// 	{
// 		scene()->keyPressEvent(keyEvent);
// 		update();
// 	}
public slots:
	void Rotate()
	{
		rotate(20.0);
	}
};

#endif