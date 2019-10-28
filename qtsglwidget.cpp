#include "qtsglwidget.h"

QtSGLWidget::QtSGLWidget(QWidget* parent):QGLWidget(parent){}

void QtSGLWidget::initializeGL()
{
    loadGLTextures();           // 载入纹理资源

    glEnable( GL_TEXTURE_2D );  // 启用纹理

    setGeometry( 0, 0, 200, 160 );

    glShadeModel(GL_SMOOTH);    // 启用阴影平滑

    // 清屏
    glClearColor(0.0, 0.0, 0.1, 0.0);

    glClearDepth(1.0);          // 设置深度缓存
    glEnable(GL_DEPTH_TEST);    // 启用深度测试
    glDepthFunc(GL_LEQUAL);     // 深度测试类型

    // glHint(GLenum target,GLenum mod) 该函数控制OpenGL在某一方面有解释的余地时，所采取的操作行为。
    // glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    // 如果OpenGL不能有效的支持透视修正参数差值，那么GL_DONT_CARE 和 GL_FASTEST可以执行颜色、纹理坐标的简单线性差值计算
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

}

void QtSGLWidget::resizeGL(int w, int h)
{
    if ( h == 0 )           // 确保屏幕不会消失（高度为0）
    {
        h = 1;
    }

    glViewport( 0, 0, (GLint)w, (GLint)h );                 // 重置Viewport
    glMatrixMode( GL_PROJECTION );                          // 选择投影矩阵
    glLoadIdentity();                                       // 重置投影矩阵

    gluPerspective( 45.0, (GLfloat)w/(GLfloat)h, 0.1, 100.0 );        // 建立透视投影矩阵。

    glMatrixMode( GL_MODELVIEW );                           // 选择模型观察矩阵
    glLoadIdentity();                                       // 重置模型观察矩阵
}

void QtSGLWidget::paintGL()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );   // 清除屏幕和深度缓存
    glLoadIdentity();                                       // 重置当前观察矩阵

    glTranslatef( 0.0,  0.0, -6.0 );                        // 相当于 以中心为参考点 移动画笔位置

    // 旋转
    xRot += 45;
    glRotatef( xRot,  1.0,  0.0,  0.0 );
    glRotatef( yRot,  0.0,  1.0,  0.0 );
    glRotatef( zRot,  0.0,  0.0,  1.0 );

    // 绑定所选纹理
    glBindTexture( GL_TEXTURE_2D, texture[0] );

    glBegin( GL_QUADS  );                                // 开始绘制  参数为要绘制的目标

    // 正方形 前面

//    glColor3f( 0.6, 0.2, 0.2 );                             // 填充颜色
    glTexCoord2f(0.0, 1.0 );glVertex3f( -1.0,   1.0,  1.0 );                         // 确定端点

//    glColor3f( 0.2, 0.6, 0.2 );
    glTexCoord2f(1.0, 1.0 );glVertex3f(  1.0,   1.0,  1.0 );

//    glColor3f( 0.2, 0.2, 0.6 );
    glTexCoord2f(1.0,  0.0 );glVertex3f(  1.0,  -1.0,  1.0 );

//    glColor3f( 0.2, 0.2, 0.6 );
    glTexCoord2f( 0.0, 0.0 );glVertex3f( -1.0,  -1.0,  1.0 );

    glEnd();

    glBindTexture( GL_TEXTURE_2D, texture[1] );

    glBegin( GL_QUADS );
    // 正方形 后面
//    glColor3f( 0.6, 0.2, 0.2 );
    glTexCoord2f(0.0, 1.0 );glVertex3f(  1.0,   1.0, -1.0 );

//    glColor3f( 0.2, 0.6, 0.2 );
    glTexCoord2f(1.0, 1.0 );glVertex3f( -1.0,   1.0, -1.0 );

//    glColor3f( 0.2, 0.2, 0.6 );
    glTexCoord2f(1.0,  0.0 );glVertex3f( -1.0,  -1.0, -1.0 );

//    glColor3f( 0.2, 0.2, 0.6 );
    glTexCoord2f( 0.0, 0.0 );glVertex3f(  1.0,  -1.0, -1.0 );

    // 正方形 左面
//    glColor3f( 0.6, 0.2, 0.2 );
    glTexCoord2f(0.0, 1.0 );glVertex3f( -1.0,   1.0, -1.0 );

//    glColor3f( 0.2, 0.6, 0.2 );
    glTexCoord2f(1.0, 1.0 );glVertex3f( -1.0,   1.0,  1.0 );

//    glColor3f( 0.2, 0.2, 0.6 );
    glTexCoord2f(1.0,  0.0 );glVertex3f( -1.0,  -1.0,  1.0 );

//    glColor3f( 0.2, 0.2, 0.6 );
    glTexCoord2f( 0.0, 0.0 );glVertex3f( -1.0,  -1.0, -1.0 );

    // 正方形 右面
//    glColor3f( 0.6, 0.2, 0.2 );
    glTexCoord2f(0.0, 1.0 );glVertex3f(  1.0,   1.0,  1.0 );

//    glColor3f( 0.2, 0.6, 0.2 );
    glTexCoord2f(1.0, 1.0 );glVertex3f(  1.0,   1.0, -1.0 );

//    glColor3f( 0.2, 0.2, 0.6 );
    glTexCoord2f(1.0,  0.0 );glVertex3f(  1.0,  -1.0, -1.0 );

//    glColor3f( 0.2, 0.2, 0.6 );
    glTexCoord2f( 0.0, 0.0 );glVertex3f(  1.0,  -1.0,  1.0 );

    // 正方形 上面
//    glColor3f( 0.6, 0.2, 0.2 );
    glTexCoord2f(0.0, 1.0 );glVertex3f( -1.0,   1.0, -1.0 );

//    glColor3f( 0.2, 0.6, 0.2 );
    glTexCoord2f(1.0, 1.0 );glVertex3f(  1.0,   1.0, -1.0 );

//    glColor3f( 0.2, 0.2, 0.6 );
    glTexCoord2f(1.0,  0.0 );glVertex3f(  1.0,   1.0,  1.0 );

//    glColor3f( 0.2, 0.2, 0.6 );
    glTexCoord2f( 0.0, 0.0 );glVertex3f( -1.0,   1.0,  1.0 );

    // 正方形 下面
//    glColor3f( 0.6, 0.2, 0.2 );
    glTexCoord2f(0.0, 1.0 );glVertex3f( -1.0,  -1.0,  1.0 );

//    glColor3f( 0.2, 0.6, 0.2 );
    glTexCoord2f(1.0, 1.0 );glVertex3f(  1.0,  -1.0,  1.0 );

//    glColor3f( 0.2, 0.2, 0.6 );
    glTexCoord2f(1.0,  0.0 );glVertex3f(  1.0,  -1.0, -1.0 );

//    glColor3f( 0.2, 0.2, 0.6 );
    glTexCoord2f( 0.0, 0.0 );glVertex3f( -1.0,  -1.0, -1.0 );

    glEnd();                                                // 绘制结束

//    glTranslatef(  3.0,  0.0,  0.0 );
}

void QtSGLWidget::loadGLTextures()
{
    QImage tex1, tex2, buf1, buf2;
    if ( !buf1.load( ":/Texture/0001.png" ) || !buf2.load(":/Texture/0002.png") )
    {
            qWarning( "Could not read image file, using single-color instead." );
            QImage dummy( 128, 128, QImage::Format_RGB32 );
            dummy.fill( Qt::green );
            buf1 = buf2 = dummy;
    }
    tex1 = QGLWidget::convertToGLFormat( buf1 );             // 转换图片格式
    tex2 = QGLWidget::convertToGLFormat( buf2 );

    glGenTextures( 2, &texture[0] );                        // 生成一个纹理


    glBindTexture( GL_TEXTURE_2D, texture[0] );             // 绑定一个2D的纹理
    // 创建纹理对象
    glTexImage2D( GL_TEXTURE_2D, 0, 3, tex1.width(), tex1.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, tex1.bits() );
    // 缩放滤波处理
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

    glBindTexture( GL_TEXTURE_2D, texture[1] );
    glTexImage2D( GL_TEXTURE_2D, 0, 3, tex2.width(), tex2.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, tex2.bits() );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
}