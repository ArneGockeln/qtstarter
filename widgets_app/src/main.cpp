#include <QtCore>
#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[]) {

	Q_INIT_RESOURCE( resources );
	QApplication app(argc, argv);

	// set icon
	QIcon appIcon;
	appIcon.addFile(":/AppIcon");
	app.setWindowIcon( appIcon );

	// load main window
	MainWindow wnd;
	wnd.show();

	return app.exec();
	
}