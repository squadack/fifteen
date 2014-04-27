#include "MyWindow.h"

MyWindow::MyWindow(QWidget *parent)
	:QMainWindow(parent)
{
	resize(800, 600);
	QWidget *central = new QWidget(this);
	this->setCentralWidget(central);
	QHBoxLayout *layout = new QHBoxLayout();

	QVBoxLayout *buttonLayout = new QVBoxLayout();
	QPushButton *buttonA = new QPushButton();
	QPushButton *buttonB = new QPushButton();
	QPushButton *buttonC = new QPushButton();
	buttonA->setText("&Check");
	buttonB->setText("&Rotate");
	buttonC->setText("E&xit");
	buttonLayout->addWidget(buttonA);
	buttonLayout->addWidget(buttonB);
	buttonLayout->addWidget(buttonC);
	
	QAction *quitGame = new QAction("Everybody", this);
	QAction *quitGame1 = new QAction("dance", this);
	QAction *quitGame2 = new QAction("now!", this);
	connect(quitGame, SIGNAL(triggered()), qApp, SLOT(quit()));
	connect(quitGame1, SIGNAL(triggered()), qApp, SLOT(quit()));
	connect(quitGame2, SIGNAL(triggered()), qApp, SLOT(quit()));
	connect(buttonC, SIGNAL(clicked()), quitGame, SLOT(trigger()));
	
	QMenu *menuA = new QMenu("&File");
	menuA->addAction(quitGame);
	menuA->addAction(quitGame1);
	menuA->addAction(quitGame2);
	this->menuBar()->addMenu(menuA);
	
	GraphicsView *view = new GraphicsView();
	connect(buttonB, SIGNAL(clicked()), view, SLOT(Rotate()));
	MyScene *scene = new MyScene();
	connect(buttonA, SIGNAL(clicked()), scene, SLOT(check()));
	view->setScene(scene);
	layout->addWidget(view);
	layout->addLayout(buttonLayout);
	
	central->setLayout(layout);
}