#include <QtCore>
#include <QGuiApplication>
#include <QtQuick/QQuickView>

int main(int argc, char *argv[]) {

	Q_INIT_RESOURCE( resources );
	QGuiApplication app(argc, argv);

	// Set qml file
	QQuickView viewer;
	viewer.setSource(QUrl("qrc:/views/main.qml"));
	viewer.show();

	// set icon
	QIcon appIcon;
	appIcon.addFile(":/AppIcon");
	app.setWindowIcon( appIcon );

	return app.exec();
	
}