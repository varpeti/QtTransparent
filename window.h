#ifndef __WINDOW_H_
#define __WINDOW_H_

#include <iostream>
#include <sstream>
#include <fstream>

#include <QWidget>
#include <QDesktopWidget>
#include <QPainter>
#include <QGuiApplication>
#include <QApplication>
#include <QScreen>
#include <QTimer>
#include <QImage>
#include <QMouseEvent>
#include <QDebug>

class QWindow : public QWidget
{
    Q_OBJECT
    public:
        explicit QWindow(QWidget *parent = 0);

    protected:
        void paintEvent(QPaintEvent *event);
        void mouseMoveEvent(QMouseEvent* event);

    private:
         QPoint cursorPos;
         short updateTime;

    signals:

    public slots:
        void callback();
};


int execQApp();

#endif