#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "vertexdata.h"
#include "geometryengine.h"
#include "hexaedr.h"
#include "tetraedr.h"
#include "octaedr.h"

#include <QOpenGLWidget>
#include <QMatrix4x4>
#include <QQuaternion>
#include <QBasicTimer>
#include <QOpenGLTexture>
#include <QMouseEvent>
#include <math.h>

class GeometryEngine;

class MainWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();
    QOpenGLShaderProgram program;
    GeometryEngine *geometries;
    void pickedHexaedr();
    void pickedTetraedr();
    void pickedOctaedr();
    void wheelEvent(QWheelEvent* event);
protected:
    void mousePressEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;
    void timerEvent(QTimerEvent *e) override;

    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    void initShaders();
    void initTextures();

private:
    int m_colorAttr;
    QBasicTimer timer;
    QOpenGLTexture *texture;
    QMatrix4x4 projection;
    QVector2D mousePressPosition;
    QVector3D rotationAxis;
    float angularSpeed;
    QQuaternion rotation;
    float scaling = 1.0f;
};

#endif // MAINWIDGET_H
