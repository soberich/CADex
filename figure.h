#ifndef FIGURE_H
#define FIGURE_H

#include <vertexdata.h>

class Figure
{
public:
    Figure();
    struct VertexData * verteces;
    unsigned short * indices, indicesNum, verticesNum;
};

#endif // FIGURE_H
