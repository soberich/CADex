#include "octaedr.h"
Octaedr::Octaedr()
{

    verticesNum = 24;
    indicesNum = 34;

    // For parrallelogram the same comment here as for cube
    verteces = new VertexData [verticesNum] {
        // front
        {QVector3D( 1.6f,  0.7f,  1.0f), QVector2D(0.0f, 0.0f)},
        {QVector3D(-1.2f,  0.7f,  1.0f), QVector2D(0.5f, 0.0f)},
        {QVector3D( 1.2f, -0.7f,  1.0f), QVector2D(0.0f, 0.5f)},
        {QVector3D(-1.6f, -0.7f,  1.0f), QVector2D(0.5f, 0.5f)},

        // east
        {QVector3D( 1.6f,  0.7f,  1.0f), QVector2D(0.0f, 0.0f)},
        {QVector3D( 1.2f, -0.7f,  1.0f), QVector2D(0.5f, 0.0f)},
        {QVector3D( 1.6f,  0.7f, -1.0f), QVector2D(0.0f, 0.5f)},
        {QVector3D( 1.2f, -0.7f, -1.0f), QVector2D(0.5f, 0.5f)},

        // back
        {QVector3D( 1.6f,  0.7f, -1.0f), QVector2D(0.5f, 0.5f)},
        {QVector3D( 1.2f, -0.7f, -1.0f), QVector2D(1.0f, 0.5f)},
        {QVector3D(-1.2f,  0.7f, -1.0f), QVector2D(0.5f, 1.0f)},
        {QVector3D(-1.6f, -0.7f, -1.0f), QVector2D(1.0f, 1.0f)},

        // west
        {QVector3D(-1.2f,  0.7f,  1.0f), QVector2D(0.5f, 0.5f)},
        {QVector3D(-1.2f,  0.7f, -1.0f), QVector2D(1.0f, 0.5f)},
        {QVector3D(-1.6f, -0.7f,  1.0f), QVector2D(0.5f, 1.0f)},
        {QVector3D(-1.6f, -0.7f, -1.0f), QVector2D(1.0f, 1.0f)},

        // bottom
        {QVector3D( 1.2f, -0.7f,  1.0f), QVector2D(0.5f, 0.5f)},
        {QVector3D(-1.6f, -0.7f,  1.0f), QVector2D(1.0f, 0.5f)},
        {QVector3D( 1.2f, -0.7f, -1.0f), QVector2D(0.5f, 1.0f)},
        {QVector3D(-1.6f, -0.7f, -1.0f), QVector2D(1.0f, 1.0f)},

        // top
        {QVector3D( 1.6f,  0.7f,  1.0f), QVector2D(0.0f, 0.0f)},
        {QVector3D( 1.6f,  0.7f, -1.0f), QVector2D(0.5f, 0.0f)},
        {QVector3D(-1.2f,  0.7f,  1.0f), QVector2D(0.0f, 0.5f)},
        {QVector3D(-1.2f,  0.7f, -1.0f), QVector2D(0.5f, 0.5f)}
    };

    // For parrallelogram the same comment here as for cube
    indices = new unsigned short [indicesNum] {
         0,  1,  2,  3,  3,     // Face 0 - triangle strip ( v0,  v1,  v2,  v3)
         4,  4,  5,  6,  7,  7, // Face 1 - triangle strip ( v4,  v5,  v6,  v7)
         8,  8,  9, 10, 11, 11, // Face 2 - triangle strip ( v8,  v9, v10, v11)
        12, 12, 13, 14, 15, 15, // Face 3 - triangle strip (v12, v13, v14, v15)
        16, 16, 17, 18, 19, 19, // Face 4 - triangle strip (v16, v17, v18, v19)
        20, 20, 21, 22, 23      // Face 5 - triangle strip (v20, v21, v22, v23)
    };

    //    verticesNum = 24;
    //            indicesNum = 38;
    //    verteces = new VertexData [verticesNum] {
    //            // west-bottom-back
    //            {QVector3D( 0.0f, 0.0f, 1.0f), QVector2D(1.0f, 1.0f)}, // 22
    //            {QVector3D( 0.0f, 1.0f, 0.0f), QVector2D(1.0f, 1.0f)}, // 23
    //            {QVector3D( 1.0f, 0.0f, 0.0f), QVector2D(1.0f, 1.0f)},  // 23
    //            // east-top-back
    //            {QVector3D( 0.0f, 1.0f, 0.0f), QVector2D(0.0f, 0.0f)},      // 0
    //            {QVector3D( 1.0f, 0.0f, 0.0f), QVector2D(0.5f, 0.0f)},      // 1
    //            {QVector3D( 0.0f, 0.0f,-1.0f), QVector2D(0.25f, _HEIGHT_)}, // 2

    //            // east-top-front
    //            {QVector3D( 1.0f, 0.0f, 0.0f), QVector2D(0.0f, 0.0f)},     // 3
    //            {QVector3D( 0.0f, 0.0f,-1.0f), QVector2D(0.5f, 0.0f)},     // 4
    //            {QVector3D( 0.0f,-1.0f, 0.0f), QVector2D(0.25f, _HEIGHT_)}, // 5

    //            // east-bottom-front
    //            {QVector3D( 0.0f, 0.0f,-1.0f), QVector2D(0.0f, 0.0f)},     // 6
    //            {QVector3D( 0.0f,-1.0f, 0.0f), QVector2D(0.5f, 0.0f)},     // 7
    //            {QVector3D(-1.0f, 0.0f, 0.0f), QVector2D(0.25f, _HEIGHT_)}, // 8

    //            // east-bottom-back
    //            {QVector3D( 0.0f,-1.0f, 0.0f), QVector2D(1.0f, 1.0f)}, // 9
    //            {QVector3D(-1.0f, 0.0f, 0.0f), QVector2D(1.0f, 1.0f)}, // 10
    //            {QVector3D( 0.0f, 0.0f, 1.0f), QVector2D(1.0f, 1.0f)}, // 11

    //            // west-top-back
    //            {QVector3D(-1.0f, 0.0f, 0.0f), QVector2D(0.0f, 0.0f)}, // 12
    //            {QVector3D( 0.0f, 0.0f, 1.0f), QVector2D(0.5f, 0.0f)}, // 13
    //            {QVector3D( 0.0f, 1.0f, 0.0f), QVector2D(0.25f, _HEIGHT_)}, // 14

    //            // west-top-front
    //            {QVector3D( 0.0f, 0.0f, 1.0f), QVector2D(0.0f, 0.0f)}, // 15
    //            {QVector3D( 0.0f, 1.0f, 0.0f), QVector2D(0.5f, 0.0f)}, // 16
    //            {QVector3D(-1.0f, 0.0f, 0.0f), QVector2D(0.25f, _HEIGHT_)}, // 17

    //            // west-bottom-front
    //            {QVector3D( 0.0f, 1.0f, 0.0f), QVector2D(0.0f, 0.0f)}, // 18
    //            {QVector3D(-1.0f, 0.0f, 0.0f), QVector2D(0.5f, 0.0f)}, // 19
    //            {QVector3D( 0.0f, 0.0f,-1.0f), QVector2D(0.25f, _HEIGHT_)}
    //        };
    //    indices = new unsigned short [indicesNum] {
    //          0,  1,  2,  2,     // Face 0
    //      3,  3,  4,  5,  5,      // Face 1
    //      6,  6,  7,  8,  8,   // Face 2
    //      9,  9, 10, 11, 11,      // bottom
    //     12, 12, 13, 14, 14,      // Face 0
    //     15, 15, 16, 17, 17,     // Face 1
    //     18, 18, 19, 20, 20,    // Face 2
    //     21, 21, 22, 23       // bottom
    //    };

}

Octaedr::~Octaedr()
{
    delete verteces;
    delete indices;
}
