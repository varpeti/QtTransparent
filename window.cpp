#include "window.h"

int execQApp()
{
    char *argv[] = {"window", NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;
    QApplication app(argc,argv);
    QWindow mainWindow;

    QFont font ("Courier", 30, 100);
    mainWindow.showFullScreen();
    return app.exec();
}

QWindow::QWindow(QWidget *parent) : QWidget(parent)
{ 
    QSize size = qApp->screens()[0]->size();
    setGeometry(0, 0, size.width(), size.height());
    setAutoFillBackground(false);
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint | Qt::WindowTransparentForInput | Qt::X11BypassWindowManagerHint);
    QTimer::singleShot(1, this, SLOT(callback()));
    updateTime = 0;
}

void QWindow::callback()
{
    updateTime++;
    if (updateTime>2)
    {
        update();
        updateTime=0;
    }
    
    cursorPos = QCursor::pos();
    QTimer::singleShot(20, this, SLOT(callback()));
}


void QWindow::paintEvent(QPaintEvent *)
{   

    const QColor red(255, 050, 05);
    const QColor green(050, 255, 05);
    const QColor blue(05, 050, 255);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(105, 225, 225, 0));

    QPen pen;
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(2);
    pen.setColor(QColor(255, 255, 255, 255));
    pen.setCapStyle(Qt::RoundCap);
    painter.setPen(pen);

    QFont font("DroidSansBold", 34, QFont::Bold, false);
    painter.setFont(font);

    painter.drawText(100,100, (std::to_string(cursorPos.x())+" "+std::to_string(cursorPos.y())).c_str());
}