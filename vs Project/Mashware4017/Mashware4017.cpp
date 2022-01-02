#include "Mashware4017.h"

bool hav_sparse;
bool hav_smooth_or_encrypt;

Mashware4017::Mashware4017(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::Mashware4017Class)
{
    ui->setupUi(this);
    setCentralWidget(ui->openGLWidget);
    ui->statusBar->showMessage(QString::fromLocal8Bit("�򿪳ɹ���"));
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
    ui->statusBar->showMessage(QString::fromLocal8Bit("�򿪳ɹ���"));
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
    ui->statusBar->showMessage(QString::fromLocal8Bit("����ɹ���"));
}

void Mashware4017::on_fill_triggered() {
    if (fileName.isEmpty()) {
        QMessageBox mesg;
        mesg.warning(this, "Warning", "no file!");
        return;
    }
    ui->openGLWidget->toFill();
    ui->statusBar->showMessage(QString::fromLocal8Bit("�����ʾ"));
}
void Mashware4017::on_line_triggered() {
    if (fileName.isEmpty()) {
        QMessageBox mesg;
        mesg.warning(this, "Warning", "no file!");
        return;
    }ui->openGLWidget->toLine();
    ui->statusBar->showMessage(QString::fromLocal8Bit("�߿���ʾ"));
}

void Mashware4017::on_moveUp_triggered() {
    if (fileName.isEmpty()) {
        QMessageBox mesg;
        mesg.warning(this, "Warning", "no file!");
        return;
    }
    ui->openGLWidget->moveUp();
    ui->statusBar->showMessage(QString::fromLocal8Bit("�����ƶ�"));
}
void Mashware4017::on_moveDown_triggered() {
    if (fileName.isEmpty()) {
        QMessageBox mesg;
        mesg.warning(this, "Warning", "no file!");
        return;
    }
    ui->openGLWidget->moveDown();
    ui->statusBar->showMessage(QString::fromLocal8Bit("�����ƶ�"));
}
void Mashware4017::on_moveLeft_triggered() {
    if (fileName.isEmpty()) {
        QMessageBox mesg;
        mesg.warning(this, "Warning", "no file!");
        return;
    }
    ui->openGLWidget->moveLeft();
    ui->statusBar->showMessage(QString::fromLocal8Bit("�����ƶ�"));
}
void Mashware4017::on_moveRight_triggered() {
    if (fileName.isEmpty()) {
        QMessageBox mesg;
        mesg.warning(this, "Warning", "no file!");
        return;
    }
    ui->openGLWidget->moveRight();
    ui->statusBar->showMessage(QString::fromLocal8Bit("�����ƶ�"));
}

void Mashware4017::on_turnUp_triggered() {
    if (fileName.isEmpty()) {
        QMessageBox mesg;
        mesg.warning(this, "Warning", "no file!");
        return;
    }
    ui->openGLWidget->turnUp();
    ui->statusBar->showMessage(QString::fromLocal8Bit("����ת"));
}
void Mashware4017::on_turnDown_triggered() {
    if (fileName.isEmpty()) {
        QMessageBox mesg;
        mesg.warning(this, "Warning", "no file!");
        return;
    }
    ui->openGLWidget->turnDown();
    ui->statusBar->showMessage(QString::fromLocal8Bit("����ת"));
}
void Mashware4017::on_turnLeft_triggered() {
    if (fileName.isEmpty()) {
        QMessageBox mesg;
        mesg.warning(this, "Warning", "no file!");
        return;
    }
    ui->openGLWidget->turnLeft();
    ui->statusBar->showMessage(QString::fromLocal8Bit("����ת"));
}
void Mashware4017::on_turnRight_triggered() {
    if (fileName.isEmpty()) {
        QMessageBox mesg;
        mesg.warning(this, "Warning", "no file!");
        return;
    }
    ui->openGLWidget->turnRight();
    ui->statusBar->showMessage(QString::fromLocal8Bit("����ת"));
}

void Mashware4017::on_narrow_triggered() {
    if (fileName.isEmpty()) {
        QMessageBox mesg;
        mesg.warning(this, "Warning", "no file!");
        return;
    }
    ui->openGLWidget->turnSmaller();
    ui->statusBar->showMessage(QString::fromLocal8Bit("��С"));
}
void Mashware4017::on_magnify_triggered() {
    if (fileName.isEmpty()) {
        QMessageBox mesg;
        mesg.warning(this, "Warning", "no file!");
        return;
    }
    ui->openGLWidget->turnBigger();
    ui->statusBar->showMessage(QString::fromLocal8Bit("�Ŵ�"));
}


void Mashware4017::on_sparse_triggered() {
    if (hav_smooth_or_encrypt) {
        QMessageBox mesg;
        mesg.warning(this, "Warning", QString::fromLocal8Bit("ooops! ��Ϊϡ�����õ��㷨��ʹͼ�����飬����ܼ�ƽ���㷨�����ݣ��ܱ�Ǹ��������ʹ��ϡ���㷨"));
        return;
    }
    if (fileName.isEmpty()) {
        QMessageBox mesg;
        mesg.warning(this, "Warning", "no file!");
        return;
    }
    hav_sparse = true;
    ui->openGLWidget->turnSparse();
    ui->statusBar->showMessage(QString::fromLocal8Bit("ϡ��"));
}
void Mashware4017::on_encrypt_triggered() {
    if (hav_sparse) {
        QMessageBox mesg;
        mesg.warning(this, "Warning", QString::fromLocal8Bit("ooops! ��Ϊϡ�����õ��㷨��ʹͼ�����飬������㷨�����ݣ��ܱ�Ǹ��������ʹ�ü����㷨"));
        return;
    }
    hav_smooth_or_encrypt = true;
    if (fileName.isEmpty()) {
        QMessageBox mesg;
        mesg.warning(this, "Warning", "no file!");
        return;
    }
    ui->openGLWidget->turnEncrypt();
    ui->statusBar->showMessage(QString::fromLocal8Bit("����"));
}
void Mashware4017::on_smooth_triggered() {
    if (fileName.isEmpty()) {
        QMessageBox mesg;
        mesg.warning(this, "Warning", "no file!");
        return;
    }
    hav_smooth_or_encrypt = true;
    ui->openGLWidget->turnSmooth();
    ui->statusBar->showMessage(QString::fromLocal8Bit("�⻬"));
}

void Mashware4017::on_manual_triggered() {
    char* msg = 
        "��ӭʹ��Mashware4017!\n \
        ��������Դ�model�ļ����µ�plyģ�ͽ������� \n \
        Ȼ��ʹ��wasd�����������ҵ��ƶ�\n \
        ��Ҳ���Խ�����С�ͷŴ�Ĳ���\n \
        ͬʱ������Ҳ֧�ֶ�ģ�ͽ�����ת\n \
        ��Ҳ�����л���ʾ��ģʽ\n \
        ������Ϻ󣬿��Զ�ͼ����б���\n \
        ����Ҫ�ģ�����Խ��������ϡ��ͼ���\n \
        ��Ҫע�⣬�ù��ܴ��ڲ������ƣ�\n \
        - ��ϡ����ܽ��м���\n \
        Ϊ��������һЩ���ţ�ʮ�ֱ�ǸOrz\n \
        "
    ;
    QMessageBox::question(this,
        QString::fromLocal8Bit("ʹ���ֲ�"),
        QString::fromLocal8Bit(msg),
        QMessageBox::Ok | QMessageBox::Cancel,
        QMessageBox::Ok);
    ui->statusBar->showMessage(QString::fromLocal8Bit("ʹ���ֲ�"));
}