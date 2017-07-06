#include "geometryengine.h"

GeometryEngine::GeometryEngine(Figure * __figure)
    : indexBuf(QOpenGLBuffer::IndexBuffer), figure(__figure)
{
    initializeOpenGLFunctions();
    // Generate 2 VBOs
    arrayBuf.create();
    indexBuf.create();
    // Initializes geometry and transfers it to VBOs
    initGeometry();
}

GeometryEngine::~GeometryEngine()
{
    arrayBuf.destroy();
    indexBuf.destroy();
    delete figure;
}

void GeometryEngine::initGeometry()
{
    // Transfer vertex data to VBO 0
    arrayBuf.bind();
    arrayBuf.allocate(figure->verteces, figure->verticesNum * sizeof(VertexData));
    // Transfer index data to VBO 1
    indexBuf.bind();
    indexBuf.allocate(figure->indices, figure->indicesNum * sizeof(unsigned short));
}

void GeometryEngine::drawGeometry(QOpenGLShaderProgram *program)
{
    // Tell OpenGL which VBOs to use
    arrayBuf.bind();
    indexBuf.bind();

    // Otstup
    quintptr offset = 0;

    // Tell OpenGL programmable pipeline how to locate vertex position data
    int vertexLocation = program->attributeLocation("a_position");
    program->enableAttributeArray(vertexLocation);
    program->setAttributeBuffer(vertexLocation, GL_FLOAT, offset, 3, sizeof(VertexData));

    offset += sizeof(QVector3D);

    // Tell OpenGL programmable pipeline how to locate vertex texture coordinate data
    int texcoordLocation = program->attributeLocation("a_texcoord");
    program->enableAttributeArray(texcoordLocation);
    program->setAttributeBuffer(texcoordLocation, GL_FLOAT, offset, 2, sizeof(VertexData));

    // Draw cube geometry using indices from VBO 1
    glDrawElements(GL_TRIANGLE_STRIP, figure->indicesNum, GL_UNSIGNED_SHORT, 0);
}
