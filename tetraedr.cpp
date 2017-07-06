#include "tetraedr.h"
#define _HEIGHT_ ((std::sqrt(3)) / 4))
Tetraedr::Tetraedr()
{
    verticesNum = indicesNum = 12;

    verteces = new VertexData [verticesNum] {
            // 0
            {QVector3D( 1.0f,  1.0f,  1.0f), QVector2D(0.0f, 0.0f)},
            {QVector3D(-1.0f, -1.0f,  1.0f), QVector2D(0.5f, 0.0f)},
            {QVector3D(-1.0f,  1.0f, -1.0f), QVector2D(0.25f, _HEIGHT_},

            // 1
            {QVector3D( 1.0f,  1.0f,  1.0f), QVector2D(0.0f, 0.0f)},
            {QVector3D(-1.0f, -1.0f,  1.0f), QVector2D(0.5f, 0.0f)},
            {QVector3D( 1.0f, -1.0f, -1.0f), QVector2D(0.25f, _HEIGHT_},

            // 2  !DBC, !CBD, !BDC- transparent, CDB.
            {QVector3D(-1.0f,  1.0f, -1.0f), QVector2D(0.0f, 0.0f)},
            {QVector3D( 1.0f, -1.0f, -1.0f), QVector2D(0.5f, 0.0f)},
            {QVector3D(-1.0f, -1.0f,  1.0f), QVector2D(0.25f, _HEIGHT_},

            // bottom
            {QVector3D( 1.0f,  1.0f,  1.0f), QVector2D(1.0f, 1.0f)},
            {QVector3D(-1.0f,  1.0f, -1.0f), QVector2D(1.0f, 1.0f)},
            {QVector3D( 1.0f, -1.0f, -1.0f), QVector2D(1.0f, 1.0f)}
        };

    indices = new unsigned short [indicesNum] {
         0,  1,  2,       // Face 0
         3,  4,  5,       // Face 1
         6,  7,  8,       // Face 2
         9, 10, 11       // bottom
    };
}

Tetraedr::~Tetraedr()
{
    delete verteces;
    delete indices;
}
