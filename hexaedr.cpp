#include "hexaedr.h"

Hexaedr::Hexaedr() : Figure()
{
    verticesNum = 24;
    indicesNum = 34;

    // For cube we would need only 8 vertices but we have to
    // duplicate vertex for each face because texture coordinate
    // is different.
    verteces = new VertexData [verticesNum] {
        // back
        {QVector3D( 1.0f,  1.0f,  1.0f), QVector2D(0.0f, 0.0f)},
        {QVector3D(-1.0f,  1.0f,  1.0f), QVector2D(0.5f, 0.0f)},
        {QVector3D( 1.0f, -1.0f,  1.0f), QVector2D(0.0f, 0.5f)},
        {QVector3D(-1.0f, -1.0f,  1.0f), QVector2D(0.5f, 0.5f)},

        // east
        {QVector3D( 1.0f,  1.0f,  1.0f), QVector2D(0.0f, 0.0f)},
        {QVector3D( 1.0f, -1.0f,  1.0f), QVector2D(0.5f, 0.0f)},
        {QVector3D( 1.0f,  1.0f, -1.0f), QVector2D(0.0f, 0.5f)},
        {QVector3D( 1.0f, -1.0f, -1.0f), QVector2D(0.5f, 0.5f)},

        // front
        {QVector3D( 1.0f,  1.0f, -1.0f), QVector2D(0.5f, 0.5f)},
        {QVector3D( 1.0f, -1.0f, -1.0f), QVector2D(1.0f, 0.5f)},
        {QVector3D(-1.0f,  1.0f, -1.0f), QVector2D(0.5f, 1.0f)},
        {QVector3D(-1.0f, -1.0f, -1.0f), QVector2D(1.0f, 1.0f)},

        // west
        {QVector3D(-1.0f,  1.0f,  1.0f), QVector2D(0.5f, 0.5f)},
        {QVector3D(-1.0f,  1.0f, -1.0f), QVector2D(1.0f, 0.5f)},
        {QVector3D(-1.0f, -1.0f,  1.0f), QVector2D(0.5f, 1.0f)},
        {QVector3D(-1.0f, -1.0f, -1.0f), QVector2D(1.0f, 1.0f)},

        // bottom
        {QVector3D( 1.0f, -1.0f,  1.0f), QVector2D(0.5f, 0.5f)},
        {QVector3D(-1.0f, -1.0f,  1.0f), QVector2D(1.0f, 0.5f)},
        {QVector3D( 1.0f, -1.0f, -1.0f), QVector2D(0.5f, 1.0f)},
        {QVector3D(-1.0f, -1.0f, -1.0f), QVector2D(1.0f, 1.0f)},

        // top
        {QVector3D( 1.0f,  1.0f,  1.0f), QVector2D(0.0f, 0.0f)},
        {QVector3D( 1.0f,  1.0f, -1.0f), QVector2D(0.5f, 0.0f)},
        {QVector3D(-1.0f,  1.0f,  1.0f), QVector2D(0.0f, 0.5f)},
        {QVector3D(-1.0f,  1.0f, -1.0f), QVector2D(0.5f, 0.5f)}
    };

    // Indices for drawing cube faces using triangle strips.
    // Triangle strips can be connected by duplicating indices
    // between the strips. If connecting strips have opposite
    // vertex order then last index of the first strip and first
    // index of the second strip needs to be duplicated. If
    // connecting strips have same vertex order then only last
    // index of the first strip needs to be duplicated.
    indices = new unsigned short [indicesNum] {
         0,  1,  2,  3,  3,     // Face 0 - triangle strip ( v0,  v1,  v2,  v3)
         4,  4,  5,  6,  7,  7, // Face 1 - triangle strip ( v4,  v5,  v6,  v7)
         8,  8,  9, 10, 11, 11, // Face 2 - triangle strip ( v8,  v9, v10, v11)
        12, 12, 13, 14, 15, 15, // Face 3 - triangle strip (v12, v13, v14, v15)
        16, 16, 17, 18, 19, 19, // Face 4 - triangle strip (v16, v17, v18, v19)
        20, 20, 21, 22, 23      // Face 5 - triangle strip (v20, v21, v22, v23)
    };
}

Hexaedr::~Hexaedr()
{
    delete verteces;
    delete indices;
}
