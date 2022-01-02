#pragma once

#include <QtWidgets/QMainWindow>
#include <QMenu>
#include <QAction>
#include <QTextEdit>
#include <QFileDialog> //file dialog
#include <QMessageBox> //message box
#include <QMainWindow>
#include "ui_Mashware4017.h"
#include <QLabel>

class Mashware4017 : public QMainWindow
{
    Q_OBJECT

public:
    Mashware4017(QWidget *parent = Q_NULLPTR);
private slots:
    void on_openFile_triggered();

    void on_save_triggered();
    
    void on_fill_triggered();
    void on_line_triggered();
    
    void on_moveUp_triggered();
    void on_moveDown_triggered();
    void on_moveLeft_triggered();
    void on_moveRight_triggered();
    
    void on_turnUp_triggered();
    void on_turnDown_triggered();
    void on_turnLeft_triggered();
    void on_turnRight_triggered();
    
    void on_manual_triggered();
    
    void on_narrow_triggered();
    void on_magnify_triggered();
    
    void on_sparse_triggered();
    void on_encrypt_triggered();
    void on_smooth_triggered();

private:
    Ui::Mashware4017Class *ui;
};
