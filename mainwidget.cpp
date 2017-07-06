#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QOpenGLWidget(parent),
    geometries(0),
    texture(0),
    angularSpeed(0)
{
}

MainWidget::~MainWidget()
{
    // Make sure the context is current
    // when deleting the texture and the buffers.
    makeCurrent();
    delete texture;
    delete geometries;
    doneCurrent();
}

void MainWidget::mousePressEvent(QMouseEvent *e)
{
    // Save mouse press position
    mousePressPosition = QVector2D(e->localPos());
}

void MainWidget::mouseReleaseEvent(QMouseEvent *e)
{
    // Mouse release position - mouse press position
    QVector2D diff = QVector2D(e->localPos()) - mousePressPosition;

    // Rotation axis is perpendicular to the mouse position difference vector
    QVector3D n = QVector3D(diff.y(), diff.x(), 0.0f).normalized();

    // Accelerate angular speed relative to the length of the mouse sweep
    float acc = diff.length() / 100.0f;

    // Calculate new rotation axis as weighted sum
    rotationAxis = (rotationAxis * angularSpeed + n * acc).normalized();

    // Increase angular speed
    angularSpeed += acc;
}

void MainWidget::timerEvent(QTimerEvent *)
{
    // Decrease angular speed (friction)
    angularSpeed *= 0.99f;

    // Stop rotation when speed goes below threshold
    if (angularSpeed < 0.01f) {
        angularSpeed = 0.0f;
    } else {
        // Update rotation
        rotation = QQuaternion::fromAxisAndAngle(rotationAxis, angularSpeed) * rotation;

        // Request an update
        update();
    }
}

void MainWidget::initializeGL()
{
    initializeOpenGLFunctions();

    glClearColor(0, 0, 0, 1);

    initShaders();
    initTextures();

    // Enable depth buffer
    glEnable(GL_DEPTH_TEST);

    // Enable back face culling
    glEnable(GL_CULL_FACE);
    if(nullptr == geometries)
        geometries = new GeometryEngine(new Tetraedr);

    // QBasicTimer is faster than QTimer
    timer.start(12, this);
}

void MainWidget::initShaders()
{
    // Compile vertex shader
    if (!program.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/Shaders/vertshader.glsl"))
        close();

    // Compile fragment shader
    if (!program.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/Shaders/fragshader.glsl"))
        close();

    // Link shader pipeline
    if (!program.link())
        close();

    // Bind shader pipeline for use
    if (!program.bind())
        close();
}

void MainWidget::initTextures()
{
    // Load image
    texture = new QOpenGLTexture(QImage(":/background.png").mirrored());

    // Set nearest filtering mode for texture minification
    texture->setMinificationFilter(QOpenGLTexture::Nearest);

    // Set bilinear filtering mode for texture magnification
    texture->setMagnificationFilter(QOpenGLTexture::Linear);

    // Wrap texture coordinates by repeating
    // f.ex. texture coordinate (1.s1, 1.2) is same as (0.1, 0.2)
    texture->setWrapMode(QOpenGLTexture::Repeat);
}

void MainWidget::resizeGL(int w, int h)
{
    // Calculate aspect ratio
    float aspect = float(w) / float(h ? h : 1);

    // Set near plane to 3.0, far plane to 7.0, field of view 45 degrees
    const float zNear = 1.0f, zFar = 50.0f, fov = 45.0f;

    // Reset projection
    projection.setToIdentity();

    // Set perspective projection
    projection.perspective(fov, aspect, zNear, zFar);
}

void MainWidget::paintGL()
{
    // Clear color and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    texture->bind();

    // Calculate model view transformation
    QMatrix4x4 matrix;
    matrix.translate(0.0f, 0.0f, -5.0f * scaling);
    matrix.rotate(rotation);

    // Set modelview-projection matrix
    program.setUniformValue("mvp_matrix", projection * matrix);

    // Use texture unit 0 which contains cube.png
    program.setUniformValue("texture", 0);
    geometries->drawGeometry(&program);
    update();
}

void MainWidget::pickedHexaedr()
{
    delete geometries;
    geometries = new GeometryEngine(new Hexaedr);
    //geometries->drawGeometry(&program);
    paintGL();
}

void MainWidget::pickedTetraedr()
{
    delete geometries;
    geometries = new GeometryEngine(new Tetraedr);
    //geometries->drawGeometry(&program);
    paintGL();
}

void MainWidget::pickedOctaedr()
{
    delete geometries;
    geometries = new GeometryEngine(new Octaedr);
    //geometries->drawGeometry(&program);
    paintGL();
}

void MainWidget::wheelEvent(QWheelEvent* event)
{
     float numDegrees = -event->delta() / 8.0f;
     float numSteps = numDegrees / 15.0f;
     scaling *= std::pow(1.125f, numSteps);
     scaling = scaling > 0.8f ? scaling : 0.8f;
     scaling = scaling < 9.0f ? scaling : 9.0f;
     paintGL();
}
