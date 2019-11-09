#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#ifndef QT_NO_PRINTER
#include <QPrinter>
#endif

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
class QAction;
class QLabel;
class QMenu;
class QScrollArea;
class QScrollBar;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    bool loadFile(const QString &);
    ~MainWindow();

private slots:
    void open();
    void saveAs();
    void print();
    void zoomIn();
    void zoomOut();
    void normalSize();
    void fitToWindow();

private:
    void createActions();
    void updateActions();
    void setImage(const QImage &newImage);
    bool saveFile(const QString &fileName);
    void scaleImage(double factor);
    void adjustScrollBar(QScrollBar *scrollBar, double factor);

    Ui::MainWindow *ui;
    QImage image;
    QLabel *imageLabel;
    QScrollArea *scrollArea;
    double scaleFactor;

#ifndef QT_NO_PRINTER
    QPrinter printer;
#endif

    QAction *saveAsAct;
    QAction *printAct;
    QAction *copyAct;
    QAction *zoomInAct;
    QAction *zoomOutAct;
    QAction *normalSizeAct;
    QAction *fitToWindowAct;
};
#endif // MAINWINDOW_H
