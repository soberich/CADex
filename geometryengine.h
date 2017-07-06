#ifndef GEOMETRYENGINE_H
#define GEOMETRYENGINE_H

#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>

#include "figure.h"
#include "tetraedr.h"
#include "hexaedr.h"

class GeometryEngine : protected QOpenGLFunctions
{
public:
    GeometryEngine() = delete;
    GeometryEngine(Figure *);
    virtual ~GeometryEngine();
private:
    QOpenGLBuffer arrayBuf;
    QOpenGLBuffer indexBuf;
    void initGeometry();
public:
    Figure * figure;
    void drawGeometry(QOpenGLShaderProgram *program);
private:
    struct VertexData vertices[];
    unsigned short indices[];
};

#endif // GEOMETRYENGINE_H
