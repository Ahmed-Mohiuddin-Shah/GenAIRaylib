#include "ImageGene.h"

ImageGene::ImageGene(const Image& shapeTemplate, const Image& originalImage, const int maxSize, const int canvasWidth, const int canvasHeight) {
        position = { (float)(rand() % canvasWidth), (float)(rand() % canvasHeight) };
        size = { (float)(rand() % maxSize), (float)(rand() % maxSize) };
        rotation = (float)(rand() % 360);  // Random rotation angle in degrees
        opacity = (float)(rand() % 100) / 100.0f;
        shape = shapeTemplate;

        // Set color based on original image at the center
        Vector2 center = { position.x + size.x / 2, position.y + size.y / 2 };
        color = GetImageColor(originalImage, (int)center.x, (int)center.y);
}

void ImageGene::mutate() {
    position.x += rand() % 20 - 10;
    position.y += rand() % 20 - 10;
    size.x += rand() % 10 - 5;
    size.y += rand() % 10 - 5;
    rotation += rand() % 30 - 15;  // Small random change in rotation
    rotation = fmod(rotation, 360.0f);  // Ensure rotation stays within 0-360 degrees
    opacity += (float)(rand() % 20 - 10) / 100.0f;
}
