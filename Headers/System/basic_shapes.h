//
// Created by pollo on 4/28/2022.
//

#ifndef BOOMBOOMENGINE_BASIC_SHAPES_H
#define BOOMBOOMENGINE_BASIC_SHAPES_H

#pragma once

#include <string>
#include "shape.h"

namespace BoomBoom
{

    Shape createRainbowTriangle();

    Shape createRainbowQuad();

    Shape createColorQuad(Coord r, Coord g, Coord b);

    Shape createTextureQuad(Coord nx=1, Coord ny=1);

    Shape createColorCircle(unsigned int steps, Coord r, Coord g, Coord b);

    Shape createAxis(Coord length = 1);

    Shape createGridXY(unsigned int Nx, unsigned int Ny, Coord z=0, Coord r=0, Coord g=0, Coord b=0);

    Shape createRainbowCube();

    Shape createColorCube(Coord r, Coord g, Coord b);

    Shape createRainbowNormalsCube();

    Shape createColorNormalsCube(Coord r, Coord g, Coord b);

}

#endif //BOOMBOOMENGINE_BASIC_SHAPES_H
