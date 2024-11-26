#pragma once
#include <raylib.h>
#include <stdlib.h>
#include <corecrt_math.h>

class ImageGene {
private:
    Vector2 position;
    Vector2 size;
    float rotation;  // New attribute for rotation
    Color color;
    float opacity;
    Image shape;
public:

    // Constructor for random initialization
    ImageGene(const Image& shapeTemplate, const Image& originalImage, const int maxSize, const int canvasWidth, const int canvasHeight);

    // Mutation method
    void mutate();
};
