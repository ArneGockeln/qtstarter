#include <QtCore>
#include <QGuiApplication>
#include <QtQuick/QQuickView>

int main(int argc, char *argv[]) {

  QGuiApplication app(argc, argv);

  // Set qml file
  QQuickView viewer;
  viewer.setSource(QUrl("qrc:/views/main.qml"));
  viewer.show();

  return app.exec();
}