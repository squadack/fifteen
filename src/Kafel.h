#ifndef KAFEL_H
#define KAFEL_H

#include <QtGui>
#include <QString>
#include <QColor>

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
			QGraphicsItem *parent = nullptr)
		: QGraphicsPixmapItem(parent),
		label(lab),
		number(num),
		font("Comic Sans MS", 20)
	{
		kolor.setRgba(col);
	}
	
	QRectF boundingRect() const
	{
		return QRectF(0, 0, Bok, Bok);
	}
	
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
	{
		QGraphicsPixmapItem::paint(painter, option, widget);
// 		painter->fillRect(0, 0, Bok, Bok, kolor);
		painter->setFont(font);
		painter->drawText(boundingRect(), Qt::AlignCenter, label);
	}
	
	
	int Number() const 
	{
		return number;
	}
};


#endif