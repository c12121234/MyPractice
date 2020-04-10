#ifndef MYVIDEOWIDGET_H
#define MYVIDEOWIDGET_H

#include <QObject>
#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QGLShaderProgram>

class MyVideoWidget : public QOpenGLWidget,protected QOpenGLFunctions
{
    Q_OBJECT
public:
    MyVideoWidget(QWidget* parent = nullptr);
    ~MyVideoWidget();

    // QOpenGLWidget interface
protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
private:
    //shader程序
    QGLShaderProgram m_program;
    //shader中yuv變數
    GLuint unis[3] = {0};

    GLuint texs[3] = {0};

    unsigned char *datas[3] = { 0 };

    int width = 240;
    int height = 128;
};

#endif // MYVIDEOWIDGET_H
