#include "MyWindow.h"

int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	MyWindow window(nullptr);
	window.show();
	
	return app.exec();
}