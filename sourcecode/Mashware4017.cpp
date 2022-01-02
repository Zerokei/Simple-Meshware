#include "Mashware4017.h"

bool hav_sparse;
bool hav_smooth_or_encrypt;

Mashware4017::Mashware4017(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::Mashware4017Class)
{
    ui->setupUi(this);
    setCentralWidget(ui->openGLWidget);
    ui->statusBar->showMessage(QString::fromLocal8Bit("打开成功！"));
    ui->toolBar->setIconSize(QSize(24, 24));
    ui->mainToolBar->setIconSize(QSize(24, 24));
}
QString fileName;
void Mashware4017::on_openFile_triggered()
{

    // open file
    
    fileName = QFileDialog::getOpenFileName(this, tr("Open File"), tr("../models"), tr("Text File (*.ply)"));

    std::cout << "File Path: " << fileName.toStdString().data() << std::endl;

    if (fileName.isEmpty()) {
        QMessageBox mesg;
        mesg.warning(this, "Warning", "no file!");
    }
    else {
        char* ch;
        QByteArray ba = fileName.toLatin1();
        ch = ba.data();
        ui->openGLWidget->loadModel(ch);
    }
    ui->statusBar->showMessage(QString::fromLocal8Bit("打开成功！"));
    hav_sparse = false;
    hav_smooth_or_encrypt = false;
}


void Mashware4017::on_save_triggered() {
    if (fileName.isEmpty()) {
        QMessageBox mesg;
        mesg.warning(this, "Warning", "no file!");
        return;
    }
    QString savefileName = QFileDialog::getSaveFileName(this, "Open File", "", "Text File(*.ply)");

    std::cout << "File Path: " << savefileName.toStdString().data() << std::endl;

    if (savefileName.isEmpty()) {
        QMessageBox mesg;
        mesg.warning(this, "Warning", "fail to save file!");
    }
    else {
        char* ch;
        QByteArray ba = savefileName.toLatin1();
        ch = ba.data();
        ui->openGLWidget->saveModel(ch);
    }
    ui->statusBar->showMessage(QString::fromLocal8Bit("保存成功！"));
}

void Mashware4017::on_fill_triggered() {
    if (fileName.isEmpty()) {
        QMessageBox mesg;
        mesg.warning(this, "Warning", "no file!");
        return;
    }
    ui->openGLWidget->toFill();
    ui->statusBar->showMessage(QString::fromLocal8Bit("填充显示"));
}
void Mashware4017::on_line_triggered() {
    if (fileName.isEmpty()) {
        QMessageBox mesg;
        mesg.warning(this, "Warning", "no file!");
        return;
    }ui->openGLWidget->toLine();
    ui->statusBar->showMessage(QString::fromLocal8Bit("线框显示"));
}

void Mashware4017::on_moveUp_triggered() {
    if (fileName.isEmpty()) {
        QMessageBox mesg;
        mesg.warning(this, "Warning", "no file!");
        return;
    }
    ui->openGLWidget->moveUp();
    ui->statusBar->showMessage(QString::fromLocal8Bit("向上移动"));
}
void Mashware4017::on_moveDown_triggered() {
    if (fileName.isEmpty()) {
        QMessageBox mesg;
        mesg.warning(this, "Warning", "no file!");
        return;
    }
    ui->openGLWidget->moveDown();
    ui->statusBar->showMessage(QString::fromLocal8Bit("向下移动"));
}
void Mashware4017::on_moveLeft_triggered() {
    if (fileName.isEmpty()) {
        QMessageBox mesg;
        mesg.warning(this, "Warning", "no file!");
        return;
    }
    ui->openGLWidget->moveLeft();
    ui->statusBar->showMessage(QString::fromLocal8Bit("向左移动"));
}
void Mashware4017::on_moveRight_triggered() {
    if (fileName.isEmpty()) {
        QMessageBox mesg;
        mesg.warning(this, "Warning", "no file!");
        return;
    }
    ui->openGLWidget->moveRight();
    ui->statusBar->showMessage(QString::fromLocal8Bit("向右移动"));
}

void Mashware4017::on_turnUp_triggered() {
    if (fileName.isEmpty()) {
        QMessageBox mesg;
        mesg.warning(this, "Warning", "no file!");
        return;
    }
    ui->openGLWidget->turnUp();
    ui->statusBar->showMessage(QString::fromLocal8Bit("向上转"));
}
void Mashware4017::on_turnDown_triggered() {
    if (fileName.isEmpty()) {
        QMessageBox mesg;
        mesg.warning(this, "Warning", "no file!");
        return;
    }
    ui->openGLWidget->turnDown();
    ui->statusBar->showMessage(QString::fromLocal8Bit("向下转"));
}
void Mashware4017::on_turnLeft_triggered() {
    if (fileName.isEmpty()) {
        QMessageBox mesg;
        mesg.warning(this, "Warning", "no file!");
        return;
    }
    ui->openGLWidget->turnLeft();
    ui->statusBar->showMessage(QString::fromLocal8Bit("向左转"));
}
void Mashware4017::on_turnRight_triggered() {
    if (fileName.isEmpty()) {
        QMessageBox mesg;
        mesg.warning(this, "Warning", "no file!");
        return;
    }
    ui->openGLWidget->turnRight();
    ui->statusBar->showMessage(QString::fromLocal8Bit("向右转"));
}

void Mashware4017::on_narrow_triggered() {
    if (fileName.isEmpty()) {
        QMessageBox mesg;
        mesg.warning(this, "Warning", "no file!");
        return;
    }
    ui->openGLWidget->turnSmaller();
    ui->statusBar->showMessage(QString::fromLocal8Bit("缩小"));
}
void Mashware4017::on_magnify_triggered() {
    if (fileName.isEmpty()) {
        QMessageBox mesg;
        mesg.warning(this, "Warning", "no file!");
        return;
    }
    ui->openGLWidget->turnBigger();
    ui->statusBar->showMessage(QString::fromLocal8Bit("放大"));
}


void Mashware4017::on_sparse_triggered() {
    if (hav_smooth_or_encrypt) {
        QMessageBox mesg;
        mesg.warning(this, "Warning", QString::fromLocal8Bit("ooops! 因为稀疏所用的算法会使图像破碎，与加密及平滑算法不兼容，很抱歉您不能再使用稀疏算法"));
        return;
    }
    if (fileName.isEmpty()) {
        QMessageBox mesg;
        mesg.warning(this, "Warning", "no file!");
        return;
    }
    hav_sparse = true;
    ui->openGLWidget->turnSparse();
    ui->statusBar->showMessage(QString::fromLocal8Bit("稀疏"));
}
void Mashware4017::on_encrypt_triggered() {
    if (hav_sparse) {
        QMessageBox mesg;
        mesg.warning(this, "Warning", QString::fromLocal8Bit("ooops! 因为稀疏所用的算法会使图像破碎，与加密算法不兼容，很抱歉您不能再使用加密算法"));
        return;
    }
    hav_smooth_or_encrypt = true;
    if (fileName.isEmpty()) {
        QMessageBox mesg;
        mesg.warning(this, "Warning", "no file!");
        return;
    }
    ui->openGLWidget->turnEncrypt();
    ui->statusBar->showMessage(QString::fromLocal8Bit("加密"));
}
void Mashware4017::on_smooth_triggered() {
    if (fileName.isEmpty()) {
        QMessageBox mesg;
        mesg.warning(this, "Warning", "no file!");
        return;
    }
    hav_smooth_or_encrypt = true;
    ui->openGLWidget->turnSmooth();
    ui->statusBar->showMessage(QString::fromLocal8Bit("光滑"));
}

void Mashware4017::on_manual_triggered() {
    char* msg = 
        "欢迎使用Mashware4017!\n \
        现在你可以打开model文件夹下的ply模型进行载入 \n \
        然后使用wasd进行上下左右的移动\n \
        你也可以进行缩小和放大的操作\n \
        同时，我们也支持对模型进行旋转\n \
        你也可以切换显示的模式\n \
        操作完毕后，可以对图像进行保存\n \
        最重要的，你可以进行网格的稀疏和加密\n \
        需要注意，该功能存在操作限制：\n \
        - 在稀疏后不能进行加密\n \
        为您带来了一些困扰，十分抱歉Orz\n \
        "
    ;
    QMessageBox::question(this,
        QString::fromLocal8Bit("使用手册"),
        QString::fromLocal8Bit(msg),
        QMessageBox::Ok | QMessageBox::Cancel,
        QMessageBox::Ok);
    ui->statusBar->showMessage(QString::fromLocal8Bit("使用手册"));
}