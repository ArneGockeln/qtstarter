#include "mainwindow.h"

#include <QApplication>
#include <QScreen>
#include <QMenuBar>
#include <QMessageBox>

MainWindow::MainWindow() {
	setWindowTitle( QCoreApplication::applicationName() );

	auto screenRect = QGuiApplication::primaryScreen()->availableGeometry();

	int wnd_width   = 640;
	int wnd_height  = 480;

	// center on screen
	int wnd_x       = ( screenRect.width() / 2 ) - ( wnd_width / 2 );
	int wnd_y       = ( screenRect.height() / 2 ) - ( wnd_height / 2 );
	setGeometry( wnd_x, wnd_y, wnd_width, wnd_height );

	// setup menu bar
	QMenuBar* bar = new QMenuBar;
	setMenuBar(bar);

	// set about dialog
	QAction* action_about = new QAction(tr("&About"), this);
	connect(action_about, &QAction::triggered, this, [this](){
		QMessageBox::about(this, tr("About"), QCoreApplication::applicationName() + "\n" + QCoreApplication::applicationVersion());
	});

	QMenu* file = menuBar()->addMenu(tr("&File"));
	file->addAction(action_about);

	// macos specific settings
	setUnifiedTitleAndToolBarOnMac(true);
}