#include "myvideowidget.h"
#include <QDebug>
#include <QFileDialog>
#include <QFile>
#include <QTimer>

//準備yuv數據
//ffmpeg -i input.mp4 -t 10 -s 240x128 -pix_fmt yuv420p out240x128.yuv
//自動加雙引號
#define GET_STR(x) #x
#define A_VER 3
#define T_VER 4

//頂點shader

const char *vString = GET_STR(
    attribute vec4 vertexIn;
    attribute vec2 textureIn;
    varying vec2 textureOut;
    void main(void)
    {
        gl_Position = vertexIn;
        textureOut = textureIn;
    }
);




//像素shader
const char *tString = GET_STR(
        varying vec2 textureOut;
        uniform sampler2D tex_y;
        uniform sampler2D tex_u;
        uniform sampler2D tex_v;
        void main(void)
        {
            vec3 yuv;
            vec3 rgb;
            yuv.x = texture2D(tex_y, textureOut).r;
            yuv.y = texture2D(tex_u, textureOut).r - 0.5;
            yuv.z = texture2D(tex_v, textureOut).r - 0.5;
            rgb = mat3(1.0, 1.0, 1.0,
                0.0, -0.39465, 2.03211,
                1.13983, -0.58060, 0.0) * yuv;
            gl_FragColor = vec4(rgb, 1.0);
        }

    );

QFile gFile;
FILE* fp;
MyVideoWidget::MyVideoWidget(QWidget *parent):
    QOpenGLWidget(parent)
{

}

MyVideoWidget::~MyVideoWidget()
{

}

void MyVideoWidget::initializeGL()
{
    qInfo()<<"initializeGL";
    //初始化opengl函數 由QOpenGLFunctions繼承
    initializeOpenGLFunctions();
    //program加載頂點和像素shader腳本
    qInfo()<<m_program.addShaderFromSourceCode(QGLShader::Fragment,tString);
    qInfo()<<m_program.addShaderFromSourceCode(QGLShader::Vertex,vString);

    //設置頂點座標變量
    m_program.bindAttributeLocation("vertexIn",A_VER);
    //設置材質座標
    m_program.bindAttributeLocation("textureIn",T_VER);


    //編譯shader
    qInfo()<<"program link() = "<<m_program.link();
    qInfo()<<"program bind() = "<<m_program.bind();

    //傳遞頂點和材質座標
    //頂點
    static const GLfloat ver[] = {
        -1.0f,-1.0f,
        1.0f,-1.0f,
        -1.0f,1.0f,
        1.0f,1.0f
    };
    //材質
    static const GLfloat tex[] = {
        0.0f,1.0f,
        1.0f,1.0f,
        0.0f,0.0f,
        1.0f,0.0f
    };
    //頂點
    glVertexAttribPointer(A_VER,2,GL_FLOAT,0,0,ver);
    glEnableVertexAttribArray(A_VER);

    //材質
    glVertexAttribPointer(T_VER,2,GL_FLOAT,0,0,tex);
    glEnableVertexAttribArray(T_VER);

    //從shader獲取材質
    unis[0] = m_program.uniformLocation("tex_y");
    unis[1] = m_program.uniformLocation("tex_u");
    unis[2] = m_program.uniformLocation("tex_v");

    //創建材質
    glGenTextures(3,texs);
    glBindTexture(GL_TEXTURE_2D, texs[0]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, width, height, 0, GL_RED, GL_UNSIGNED_BYTE, 0);

    //U
    glBindTexture(GL_TEXTURE_2D, texs[1]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, width/2, height / 2, 0, GL_RED, GL_UNSIGNED_BYTE, 0);

    //V
    glBindTexture(GL_TEXTURE_2D, texs[2]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, width / 2, height / 2, 0, GL_RED, GL_UNSIGNED_BYTE, 0);


    datas[0] = new unsigned char[width*height];		// Y
    datas[1] = new unsigned char[width*height/4];	//U
    datas[2] = new unsigned char[width*height/4];	//V

    fp = fopen("out240x128.yuv","rb");
    if(!fp)
    {
        qInfo()<<"file fail";
    }

    QTimer* timer = new QTimer(this);
    connect(timer,&QTimer::timeout,[this](){this->update();});
    timer->start(40);
}

void MyVideoWidget::resizeGL(int w, int h)
{
    qInfo()<<"resizeGL"<<w<<" "<<h;
}

void MyVideoWidget::paintGL()
{
    qInfo()<<"paintGL";
    if(feof(fp))
    {
        fseek(fp,0,SEEK_SET);
    }
    fread(datas[0],1,width*height,fp);
    fread(datas[1],1,width*height/4,fp);
    fread(datas[2],1,width*height/4,fp);

    //y
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D,texs[0]);
    glTexSubImage2D(GL_TEXTURE_2D,0,0,0,width,height,GL_RED,GL_UNSIGNED_BYTE,datas[0]);
    glUniform1i(unis[0],0);

    //u
    glActiveTexture(GL_TEXTURE0+1);
    glBindTexture(GL_TEXTURE_2D,texs[1]);
    glTexSubImage2D(GL_TEXTURE_2D,0,0,0,width/2,height/2,GL_RED,GL_UNSIGNED_BYTE,datas[1]);
    glUniform1i(unis[1],1);

    //v
    glActiveTexture(GL_TEXTURE0+2);
    glBindTexture(GL_TEXTURE_2D,texs[2]);
    glTexSubImage2D(GL_TEXTURE_2D,0,0,0,width/2,height/2,GL_RED,GL_UNSIGNED_BYTE,datas[2]);
    glUniform1i(unis[2],2);

    glDrawArrays(GL_TRIANGLE_STRIP,0,4);
}
