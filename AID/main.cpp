#include "mainwindow.h"

#include <QApplication>
#include <QCommandLineParser>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QGuiApplication::setApplicationDisplayName(MainWindow::tr("Image Viewer"));
    QCommandLineParser commandLineParser;
    commandLineParser.addHelpOption();
    commandLineParser.addPositionalArgument(MainWindow::tr("[file]"), MainWindow::tr("Image file to open."));
    commandLineParser.process(QCoreApplication::arguments());
    MainWindow w;
    if (!commandLineParser.positionalArguments().isEmpty()
        && !w.loadFile(commandLineParser.positionalArguments().front())) {
        return -1;
    }
    w.show();
    return app.exec();
}
