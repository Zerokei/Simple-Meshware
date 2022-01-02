#include "myopenglwidget.h"

unsigned int shaderProgram;
unsigned int VBO;
unsigned int VAO;
float vertices[] = {
    -0.5f, -0.5f, -0.0f,
    0.5f, -0.5f, 0.6f,
    0.0f, 0.5f, 0.1f
};


const char* vertexShaderSource = 
    "#version 440 core\n"
    "layout (location = 0) in vec3 aPos;\n" 
    "void main()\n" 
    "{\n"
    " gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

const char* fragmentShaderSource = 
    "#version 440 core\n"
    "layout (location = 0) out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    " FragColor = vec4(0.5f, 0.0f, 0.0f, 1.0f);\n"  //rgb a
    "}\n\0";

unsigned int MyOpenGLWidget::compileShader(const int type, const std::string& source) {
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    /*Print error message*/
    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE) {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*)alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);
        std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment")<< " shader!" << std::endl;
        std::cout << message << std::endl;
    }

    return id;
}

unsigned int MyOpenGLWidget::createShader(const std::string& vertexShader, const std::string& fragmentShader) {
    unsigned int program = glCreateProgram();
    unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}


MyOpenGLWidget::MyOpenGLWidget(QWidget* parent)
    : QOpenGLWidget{ parent }
{

}

void MyOpenGLWidget::initializeGL()
{
    initializeOpenGLFunctions();

    shaderProgram = createShader(vertexShaderSource, fragmentShaderSource);

}

void MyOpenGLWidget::resizeGL(int w, int h)
{

}
MyModel* m_mod;
void MyOpenGLWidget::paintGL()
{
    if (m_mod) {
        glUseProgram(shaderProgram);
        m_mod->Draw();
    }
    else {
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    }
}


void MyOpenGLWidget::loadModel(const char* filepath) {
    makeCurrent();
    m_mod = new MyModel(filepath, QOpenGLContext::currentContext()->versionFunctions<QOpenGLFunctions_4_4_Core>());
    doneCurrent();
}

void MyOpenGLWidget::saveModel(const char* filename) {
    makeCurrent();
    m_mod->Save(filename);
    //int err = vcg::tri::io::ExporterOBJ<MyMesh>::Save(*m_mod, filename, 0);
    doneCurrent();
}


void MyOpenGLWidget::turnUp() {
    makeCurrent();
    m_mod->RotateToX();
    doneCurrent();
    update();
}
void MyOpenGLWidget::turnDown() {
    makeCurrent();
    m_mod->RotateToX_();
    doneCurrent();
    update();
}
void MyOpenGLWidget::turnLeft() {
    makeCurrent();
    m_mod->RotateToY_();
    doneCurrent();
    update();
}
void MyOpenGLWidget::turnRight() {
    makeCurrent();
    m_mod->RotateToY();
    doneCurrent();
    update();
}
void MyOpenGLWidget::moveUp() {
    makeCurrent();
    m_mod->MoveY();
    doneCurrent();
    update();
}
void MyOpenGLWidget::moveDown() {
    makeCurrent();
    m_mod->MoveY_();
    doneCurrent();
    update();
}
void MyOpenGLWidget::moveLeft() {
    makeCurrent();
    m_mod->MoveX_();
    doneCurrent();
    update();
}
void MyOpenGLWidget::moveRight() {
    makeCurrent();
    m_mod->MoveX();
    doneCurrent();
    update();
}
void MyOpenGLWidget::turnBigger() {
    makeCurrent();
    m_mod->MakeBigger();
    doneCurrent();
    update();
}
void MyOpenGLWidget::turnSmaller() {
    makeCurrent();
    m_mod->MakeSmaller();
    doneCurrent();
    update();
}


void MyOpenGLWidget::toLine() {
    makeCurrent();
    m_mod->ViewLine();
    doneCurrent();
    update();
}
void MyOpenGLWidget::toFill() {
    makeCurrent();
    m_mod->ViewFill();
    doneCurrent();
    update();
}

void MyOpenGLWidget::turnSparse() {
    makeCurrent();
    m_mod->Sparse();
    doneCurrent();
    update();
}
void MyOpenGLWidget::turnEncrypt() {
    makeCurrent();
    m_mod->Encrypt();
    doneCurrent();
    update();
}
void MyOpenGLWidget::turnSmooth() {
    makeCurrent();
    m_mod->MSmooth();
    doneCurrent();
    update();
}