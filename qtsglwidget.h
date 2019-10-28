#ifndef QTSGLWIDGET_H
#define QTSGLWIDGET_H

#include <QtOpenGL>
#include <GL/GLU.h>
#include <QImage>

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
private:
    GLfloat xRot = 0, yRot = 0, zRot = 0;
    GLuint texture[3] = {0};
};

#endif // QTSGLWIDGET_H
