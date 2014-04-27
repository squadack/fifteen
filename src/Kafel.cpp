#include "Kafel.h"

Kafel::Kafel(qint32 num,
		QRgb col,
		QString lab,
		QGraphicsItem *parent)
	: QGraphicsPixmapItem(parent),
	label(lab),
	number(num),
	font("Comic Sans MS", 20)
{
	kolor.setRgba(col);
}

QRectF Kafel::boundingRect() const
{
	return QRectF(0, 0, Bok, Bok);
}

void Kafel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	QGraphicsPixmapItem::paint(painter, option, widget);
// 	painter->fillRect(0, 0, Bok, Bok, kolor);
	painter->setFont(font);
	painter->drawText(boundingRect(), Qt::AlignCenter, label);
}

qint32 Kafel::Number() const 
{
	return number;
}