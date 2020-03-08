#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QtGui>
#include <QGraphicsView>

class GraphicsView : public QGraphicsView
{
	Q_OBJECT;

public slots:
	void Rotate();
};

#endif
