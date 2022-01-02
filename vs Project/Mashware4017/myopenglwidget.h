#pragma once

#include "mymodel.h"
#include <QWidget>
#include <QopenGLWidget>
#include <QopenGLFunctions_4_4_Core>

class MyOpenGLWidget : public QOpenGLWidget, QOpenGLFunctions_4_4_Core {
	Q_OBJECT
public:
	explicit MyOpenGLWidget(QWidget* parent = nullptr);

	void loadModel(const char* filename);
	void saveModel(const char* filename);

	void turnUp();
	void turnDown();
	void turnLeft();
	void turnRight();

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	
	void turnBigger();
	void turnSmaller();

	void toLine();
	void toFill();

	void turnSparse();
	void turnEncrypt();
	void turnSmooth();
protected:
	virtual void initializeGL();
	virtual void resizeGL(int w, int h);
	virtual void paintGL();

	unsigned int compileShader(const int type, const std::string& source);
	unsigned int createShader(const std::string& vertexShader, const std::string& fragmentShader);

signals:
};