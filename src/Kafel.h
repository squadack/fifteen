#ifndef KAFEL_H
#define KAFEL_H

#include <QtGui>
#include <QString>
#include <QColor>
#include <QGraphicsPixmapItem>

class Kafel : public QGraphicsPixmapItem
{
// 	Q_OBJECT;
	QString label;
	QColor kolor;
    qint32 number;
	QFont font;
public:
	static const qint32 Bok = 100;
	
	Kafel(qint32 num,
			QRgb col = qRgb(0, 255, 0),
			QString lab = "",
			QGraphicsItem *parent = nullptr);
	
	QRectF boundingRect() const;
	
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	
	qint32 Number() const;

};


#endif
