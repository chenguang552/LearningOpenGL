#ifndef QTSGLWIDGET_H
#define QTSGLWIDGET_H

#include <QtOpenGL>
#include <GL/GLU.h>
#include <QImage>
#include <QDebug>

class QtSGLWidget: public QGLWidget
{
    Q_OBJECT
public:
    QtSGLWidget(QWidget* parent);

protected:
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();

    void loadGLTextures();


    void keyPressEvent( QKeyEvent *e );
    void keyReleaseEvent( QKeyEvent *e );

    //鼠标点击事件
    void mousePressEvent(QMouseEvent* event);
    //鼠标移动事件
    void mouseMoveEvent(QMouseEvent *event);
    //鼠标释放事件
    void mouseReleaseEvent(QMouseEvent *event);

    void wheelEvent(QWheelEvent*event);

private:
    GLfloat xRot = 0, yRot = 0, zRot = 0;
    GLuint texture[3] = {0};

    GLfloat zoom = -6.0;
    // 光源
    GLfloat lightAmbient[4] = { 0.5, 0.5, 0.5, 1.0 };       // 半亮白色环境光
    GLfloat lightDiffuse[4] = { 1.0, 1.0, 1.0, 1.0 };       // 最亮的漫射光
    GLfloat lightPosition[4] = { 0.0, 0.0, 2.0, 1.0 };      // 光源位置

    bool m_move;
    QPoint m_startPoint;
    QPoint m_windowPoint;

    int moveXRot, moveYRot;

};

#endif // QTSGLWIDGET_H
