#include <QtCore>
#include <QGuiApplication>
#include <QtQuick/QQuickView>

#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QDebug>

int main(int argc, char *argv[]) {

	Q_INIT_RESOURCE( resources );
	QGuiApplication app(argc, argv);
	QCoreApplication::setApplicationName(CMAKE_DEF_APP_NAME);
	QCoreApplication::setApplicationVersion(CMAKE_DEF_PROJECT_VERSION);
	QCoreApplication::setOrganizationName(CMAKE_DEF_ORG_COMPANY);
	QCoreApplication::setOrganizationDomain(CMAKE_DEF_ORG_DOMAIN);

	// Command Line Arguments
	QCommandLineParser cli;
	cli.setApplicationDescription(CMAKE_DEF_APP_NAME);
	cli.addHelpOption();
	cli.addVersionOption();

	QCommandLineOption cliOption( QStringList() << "c" << "cli", QCoreApplication::translate("main", "Run in cli mode only.") );
	cli.addOption( cliOption );

	// Process CLI Arguments
	cli.process( app );

	// set icon
	QIcon appIcon;
	appIcon.addFile(":/AppIcon");
	app.setWindowIcon( appIcon );

	if ( cli.isSet( "cli" ) ) {
		qInfo() << "Cli mode only";

		return EXIT_SUCCESS;
	} else {
		// Set qml file
		QQuickView viewer;
		viewer.setSource(QUrl("qrc:/views/main.qml"));
		viewer.show();

		return app.exec();
	}
}