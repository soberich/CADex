#include <QApplication>
#include <QLabel>
#include <QSurfaceFormat>
#include "mainwindow.h"
#ifndef QT_NO_OPENGL
#include "mainwidget.h"
#endif

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    QSurfaceFormat::setDefaultFormat(format);

    app.setApplicationName("Polyhedrons");
    app.setApplicationVersion("0.1");
#ifndef QT_NO_OPENGL
    MainWindow w;
    w.show();
#else
    QLabel note("OpenGL Support required");
    note.show();
#endif
    return app.exec();
}
