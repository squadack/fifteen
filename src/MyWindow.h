#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QtGui>
#include <QDebug>
#include <QAction>
#include <QMainWindow>
#include "MyScene.h"
#include "GraphicsView.h"

class MyWindow : public QMainWindow
{
	Q_OBJECT;
public:
	MyWindow(QWidget *parent = nullptr);
	~MyWindow();
private:
	QTimer *timer;
};

#endif
