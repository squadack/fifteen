#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QtGui>

class GraphicsView : public QGraphicsView
{
	Q_OBJECT;

public slots:
	void Rotate();
};

#endif