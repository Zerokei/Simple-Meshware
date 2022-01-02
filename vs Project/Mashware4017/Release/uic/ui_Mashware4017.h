/********************************************************************************
** Form generated from reading UI file 'Mashware4017.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MASHWARE4017_H
#define UI_MASHWARE4017_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "myopenglwidget.h"

QT_BEGIN_NAMESPACE

class Ui_Mashware4017Class
{
public:
    QAction *openFile;
    QAction *moveUp;
    QAction *moveDown;
    QAction *moveRight;
    QAction *moveLeft;
    QAction *turnUp;
    QAction *turnDown;
    QAction *turnRight;
    QAction *turnLeft;
    QAction *fill;
    QAction *manual;
    QAction *magnify;
    QAction *narrow;
    QAction *save;
    QAction *sparse;
    QAction *encrypt;
    QAction *line;
    QAction *smooth;
    QWidget *centralWidget;
    MyOpenGLWidget *openGLWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QMenu *menu_5;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *Mashware4017Class)
    {
        if (Mashware4017Class->objectName().isEmpty())
            Mashware4017Class->setObjectName(QString::fromUtf8("Mashware4017Class"));
        Mashware4017Class->resize(988, 718);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../images/Marmoset Toolbag.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Mashware4017Class->setWindowIcon(icon);
        openFile = new QAction(Mashware4017Class);
        openFile->setObjectName(QString::fromUtf8("openFile"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../images/171127-200.png"), QSize(), QIcon::Normal, QIcon::Off);
        openFile->setIcon(icon1);
        moveUp = new QAction(Mashware4017Class);
        moveUp->setObjectName(QString::fromUtf8("moveUp"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../images/R-C (1).png"), QSize(), QIcon::Normal, QIcon::Off);
        moveUp->setIcon(icon2);
        moveDown = new QAction(Mashware4017Class);
        moveDown->setObjectName(QString::fromUtf8("moveDown"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../images/R-C.png"), QSize(), QIcon::Normal, QIcon::Off);
        moveDown->setIcon(icon3);
        moveRight = new QAction(Mashware4017Class);
        moveRight->setObjectName(QString::fromUtf8("moveRight"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../images/7dd98d1001e9390117e784b671ec54e737d19654.png"), QSize(), QIcon::Normal, QIcon::Off);
        moveRight->setIcon(icon4);
        moveLeft = new QAction(Mashware4017Class);
        moveLeft->setObjectName(QString::fromUtf8("moveLeft"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("../images/R-C (2).png"), QSize(), QIcon::Normal, QIcon::Off);
        moveLeft->setIcon(icon5);
        turnUp = new QAction(Mashware4017Class);
        turnUp->setObjectName(QString::fromUtf8("turnUp"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("../images/s4.png"), QSize(), QIcon::Normal, QIcon::Off);
        turnUp->setIcon(icon6);
        turnDown = new QAction(Mashware4017Class);
        turnDown->setObjectName(QString::fromUtf8("turnDown"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("../images/1640074043897.png"), QSize(), QIcon::Normal, QIcon::Off);
        turnDown->setIcon(icon7);
        turnRight = new QAction(Mashware4017Class);
        turnRight->setObjectName(QString::fromUtf8("turnRight"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("../images/1640074205253.png"), QSize(), QIcon::Normal, QIcon::Off);
        turnRight->setIcon(icon8);
        turnLeft = new QAction(Mashware4017Class);
        turnLeft->setObjectName(QString::fromUtf8("turnLeft"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8("../images/s6.png"), QSize(), QIcon::Normal, QIcon::Off);
        turnLeft->setIcon(icon9);
        fill = new QAction(Mashware4017Class);
        fill->setObjectName(QString::fromUtf8("fill"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8("../images/fill.png"), QSize(), QIcon::Normal, QIcon::Off);
        fill->setIcon(icon10);
        manual = new QAction(Mashware4017Class);
        manual->setObjectName(QString::fromUtf8("manual"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8("../images/manual.png"), QSize(), QIcon::Normal, QIcon::Off);
        manual->setIcon(icon11);
        magnify = new QAction(Mashware4017Class);
        magnify->setObjectName(QString::fromUtf8("magnify"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8("../images/images.png"), QSize(), QIcon::Normal, QIcon::Off);
        magnify->setIcon(icon12);
        narrow = new QAction(Mashware4017Class);
        narrow->setObjectName(QString::fromUtf8("narrow"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8("../images/sub.png"), QSize(), QIcon::Normal, QIcon::Off);
        narrow->setIcon(icon13);
        save = new QAction(Mashware4017Class);
        save->setObjectName(QString::fromUtf8("save"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8("../images/save-1779882-1518534.png"), QSize(), QIcon::Normal, QIcon::Off);
        save->setIcon(icon14);
        sparse = new QAction(Mashware4017Class);
        sparse->setObjectName(QString::fromUtf8("sparse"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8("../images/clustering.png"), QSize(), QIcon::Normal, QIcon::Off);
        sparse->setIcon(icon15);
        encrypt = new QAction(Mashware4017Class);
        encrypt->setObjectName(QString::fromUtf8("encrypt"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8("../images/Cartoon-of-AMR-grids-with-two-levels-of-factor-2-refinement-The-coarsest-grid-covers-the.png"), QSize(), QIcon::Normal, QIcon::Off);
        encrypt->setIcon(icon16);
        line = new QAction(Mashware4017Class);
        line->setObjectName(QString::fromUtf8("line"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8("../images/R-C (3).png"), QSize(), QIcon::Normal, QIcon::Off);
        line->setIcon(icon17);
        smooth = new QAction(Mashware4017Class);
        smooth->setObjectName(QString::fromUtf8("smooth"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8("../images/png-transparent-circle-white-circle-white-monochrome-black-thumbnail.png"), QSize(), QIcon::Normal, QIcon::Off);
        smooth->setIcon(icon18);
        centralWidget = new QWidget(Mashware4017Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        openGLWidget = new MyOpenGLWidget(centralWidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        openGLWidget->setGeometry(QRect(30, 50, 841, 541));
        Mashware4017Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Mashware4017Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 988, 25));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        menu_5 = new QMenu(menuBar);
        menu_5->setObjectName(QString::fromUtf8("menu_5"));
        Mashware4017Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Mashware4017Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Mashware4017Class->addToolBar(Qt::LeftToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Mashware4017Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Mashware4017Class->setStatusBar(statusBar);
        toolBar = new QToolBar(Mashware4017Class);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        Mashware4017Class->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_5->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menu->addAction(openFile);
        menu->addAction(save);
        menu_2->addAction(moveUp);
        menu_2->addAction(moveDown);
        menu_2->addAction(moveRight);
        menu_2->addAction(moveLeft);
        menu_2->addAction(turnUp);
        menu_2->addAction(turnDown);
        menu_2->addAction(turnRight);
        menu_2->addAction(turnLeft);
        menu_2->addAction(magnify);
        menu_2->addAction(narrow);
        menu_3->addAction(manual);
        menu_4->addAction(fill);
        menu_4->addAction(line);
        menu_5->addAction(sparse);
        menu_5->addAction(encrypt);
        menu_5->addAction(smooth);
        mainToolBar->addAction(moveUp);
        mainToolBar->addAction(moveDown);
        mainToolBar->addAction(moveRight);
        mainToolBar->addAction(moveLeft);
        mainToolBar->addSeparator();
        mainToolBar->addAction(magnify);
        mainToolBar->addAction(narrow);
        mainToolBar->addSeparator();
        mainToolBar->addAction(turnUp);
        mainToolBar->addAction(turnDown);
        mainToolBar->addAction(turnLeft);
        mainToolBar->addAction(turnRight);
        mainToolBar->addSeparator();
        toolBar->addAction(openFile);
        toolBar->addAction(save);
        toolBar->addSeparator();
        toolBar->addAction(line);
        toolBar->addAction(fill);
        toolBar->addSeparator();
        toolBar->addAction(sparse);
        toolBar->addAction(encrypt);
        toolBar->addAction(smooth);
        toolBar->addSeparator();
        toolBar->addAction(manual);
        toolBar->addSeparator();

        retranslateUi(Mashware4017Class);

        QMetaObject::connectSlotsByName(Mashware4017Class);
    } // setupUi

    void retranslateUi(QMainWindow *Mashware4017Class)
    {
        Mashware4017Class->setWindowTitle(QCoreApplication::translate("Mashware4017Class", "Mashware4017", nullptr));
        openFile->setText(QCoreApplication::translate("Mashware4017Class", "\346\211\223\345\274\200", nullptr));
#if QT_CONFIG(shortcut)
        openFile->setShortcut(QCoreApplication::translate("Mashware4017Class", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        moveUp->setText(QCoreApplication::translate("Mashware4017Class", "\344\270\212\347\247\273", nullptr));
#if QT_CONFIG(tooltip)
        moveUp->setToolTip(QCoreApplication::translate("Mashware4017Class", "\344\270\212\347\247\273", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        moveUp->setShortcut(QCoreApplication::translate("Mashware4017Class", "W", nullptr));
#endif // QT_CONFIG(shortcut)
        moveDown->setText(QCoreApplication::translate("Mashware4017Class", "\344\270\213\347\247\273", nullptr));
#if QT_CONFIG(tooltip)
        moveDown->setToolTip(QCoreApplication::translate("Mashware4017Class", "\344\270\213\347\247\273", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        moveDown->setShortcut(QCoreApplication::translate("Mashware4017Class", "S", nullptr));
#endif // QT_CONFIG(shortcut)
        moveRight->setText(QCoreApplication::translate("Mashware4017Class", "\345\217\263\347\247\273", nullptr));
#if QT_CONFIG(tooltip)
        moveRight->setToolTip(QCoreApplication::translate("Mashware4017Class", "\345\217\263\347\247\273", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        moveRight->setShortcut(QCoreApplication::translate("Mashware4017Class", "D", nullptr));
#endif // QT_CONFIG(shortcut)
        moveLeft->setText(QCoreApplication::translate("Mashware4017Class", "\345\267\246\347\247\273", nullptr));
#if QT_CONFIG(tooltip)
        moveLeft->setToolTip(QCoreApplication::translate("Mashware4017Class", "\345\267\246\347\247\273", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        moveLeft->setShortcut(QCoreApplication::translate("Mashware4017Class", "A", nullptr));
#endif // QT_CONFIG(shortcut)
        turnUp->setText(QCoreApplication::translate("Mashware4017Class", "\345\220\221\344\270\212\347\277\273\350\275\254", nullptr));
#if QT_CONFIG(shortcut)
        turnUp->setShortcut(QCoreApplication::translate("Mashware4017Class", "Alt+Up", nullptr));
#endif // QT_CONFIG(shortcut)
        turnDown->setText(QCoreApplication::translate("Mashware4017Class", "\345\220\221\344\270\213\347\277\273\350\275\254", nullptr));
#if QT_CONFIG(shortcut)
        turnDown->setShortcut(QCoreApplication::translate("Mashware4017Class", "Alt+Down", nullptr));
#endif // QT_CONFIG(shortcut)
        turnRight->setText(QCoreApplication::translate("Mashware4017Class", "\345\220\221\345\217\263\347\277\273\350\275\254", nullptr));
#if QT_CONFIG(shortcut)
        turnRight->setShortcut(QCoreApplication::translate("Mashware4017Class", "Alt+Right", nullptr));
#endif // QT_CONFIG(shortcut)
        turnLeft->setText(QCoreApplication::translate("Mashware4017Class", "\345\220\221\345\267\246\347\277\273\350\275\254", nullptr));
#if QT_CONFIG(tooltip)
        turnLeft->setToolTip(QCoreApplication::translate("Mashware4017Class", "\345\220\221\345\267\246\347\277\273\350\275\254", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        turnLeft->setShortcut(QCoreApplication::translate("Mashware4017Class", "Alt+Left", nullptr));
#endif // QT_CONFIG(shortcut)
        fill->setText(QCoreApplication::translate("Mashware4017Class", "\345\241\253\345\205\205\346\230\276\347\244\272", nullptr));
#if QT_CONFIG(tooltip)
        fill->setToolTip(QCoreApplication::translate("Mashware4017Class", "\345\241\253\345\205\205\346\230\276\347\244\272", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        fill->setShortcut(QCoreApplication::translate("Mashware4017Class", "F", nullptr));
#endif // QT_CONFIG(shortcut)
        manual->setText(QCoreApplication::translate("Mashware4017Class", "\344\275\277\347\224\250\346\214\207\345\215\227", nullptr));
#if QT_CONFIG(shortcut)
        manual->setShortcut(QCoreApplication::translate("Mashware4017Class", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        magnify->setText(QCoreApplication::translate("Mashware4017Class", "\346\224\276\345\244\247", nullptr));
#if QT_CONFIG(tooltip)
        magnify->setToolTip(QCoreApplication::translate("Mashware4017Class", "\346\224\276\345\244\247", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        magnify->setShortcut(QCoreApplication::translate("Mashware4017Class", "Shift+Up", nullptr));
#endif // QT_CONFIG(shortcut)
        narrow->setText(QCoreApplication::translate("Mashware4017Class", "\347\274\251\345\260\217", nullptr));
#if QT_CONFIG(tooltip)
        narrow->setToolTip(QCoreApplication::translate("Mashware4017Class", "\347\274\251\345\260\217", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        narrow->setShortcut(QCoreApplication::translate("Mashware4017Class", "Shift+Down", nullptr));
#endif // QT_CONFIG(shortcut)
        save->setText(QCoreApplication::translate("Mashware4017Class", "\344\277\235\345\255\230", nullptr));
#if QT_CONFIG(tooltip)
        save->setToolTip(QCoreApplication::translate("Mashware4017Class", "\344\277\235\345\255\230", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        save->setShortcut(QCoreApplication::translate("Mashware4017Class", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        sparse->setText(QCoreApplication::translate("Mashware4017Class", "\347\250\200\347\226\217", nullptr));
#if QT_CONFIG(tooltip)
        sparse->setToolTip(QCoreApplication::translate("Mashware4017Class", "\347\250\200\347\226\217", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        sparse->setShortcut(QCoreApplication::translate("Mashware4017Class", "Q", nullptr));
#endif // QT_CONFIG(shortcut)
        encrypt->setText(QCoreApplication::translate("Mashware4017Class", "\345\212\240\345\257\206", nullptr));
#if QT_CONFIG(tooltip)
        encrypt->setToolTip(QCoreApplication::translate("Mashware4017Class", "\345\212\240\345\257\206", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        encrypt->setShortcut(QCoreApplication::translate("Mashware4017Class", "E", nullptr));
#endif // QT_CONFIG(shortcut)
        line->setText(QCoreApplication::translate("Mashware4017Class", "\347\272\277\346\235\241\346\230\276\347\244\272", nullptr));
#if QT_CONFIG(tooltip)
        line->setToolTip(QCoreApplication::translate("Mashware4017Class", "\347\272\277\346\235\241\346\230\276\347\244\272", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        line->setShortcut(QCoreApplication::translate("Mashware4017Class", "L", nullptr));
#endif // QT_CONFIG(shortcut)
        smooth->setText(QCoreApplication::translate("Mashware4017Class", "\345\205\211\346\273\221", nullptr));
#if QT_CONFIG(tooltip)
        smooth->setToolTip(QCoreApplication::translate("Mashware4017Class", "\345\205\211\346\273\221", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        smooth->setShortcut(QCoreApplication::translate("Mashware4017Class", "Z", nullptr));
#endif // QT_CONFIG(shortcut)
        menu->setTitle(QCoreApplication::translate("Mashware4017Class", "\345\274\200\345\247\213", nullptr));
        menu_2->setTitle(QCoreApplication::translate("Mashware4017Class", "\347\274\226\350\276\221", nullptr));
        menu_3->setTitle(QCoreApplication::translate("Mashware4017Class", "\345\270\256\345\212\251", nullptr));
        menu_4->setTitle(QCoreApplication::translate("Mashware4017Class", "\346\230\276\347\244\272", nullptr));
        menu_5->setTitle(QCoreApplication::translate("Mashware4017Class", "\351\253\230\347\272\247\346\223\215\344\275\234", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("Mashware4017Class", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Mashware4017Class: public Ui_Mashware4017Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MASHWARE4017_H
