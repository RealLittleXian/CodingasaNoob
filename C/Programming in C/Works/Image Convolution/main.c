
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cv.h"
#define MAX_FILENAME_SIZE 255

BMPImage* Convolution2D(BMPImage* img, float kernel[3][3]) {
    BMPImage* convdImg = (BMPImage*)malloc(sizeof(BMPImage));
    convdImg->width = img->width;
    convdImg->height = img->height;
    convdImg->channels = img->channels;
    convdImg->imageData = (PixelBlock*)malloc(sizeof(PixelBlock) * img->width * img->height);

    int i, j, k, l;
    int sumR, sumG, sumB;
    int kernelSize = 3;
    int kernelOffset = kernelSize / 2;

    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            sumR = 0;
            sumG = 0;
            sumB = 0;

            for (k = -kernelOffset; k <= kernelOffset; k++) {
                for (l = -kernelOffset; l <= kernelOffset; l++) {
                    int x = i + k;
                    int y = j + l;

                    if (x >= 0 && x < img->height && y >= 0 && y < img->width) {
                        int pixelIndex = x * img->width + y;
                        sumR += img->imageData[pixelIndex].R * kernel[k + kernelOffset][l + kernelOffset];
                        sumG += img->imageData[pixelIndex].G * kernel[k + kernelOffset][l + kernelOffset];
                        sumB += img->imageData[pixelIndex].B * kernel[k + kernelOffset][l + kernelOffset];
                    }
                }
            }

            int pixelIndex = i * img->width + j;
            convdImg->imageData[pixelIndex].R = sumR;
            convdImg->imageData[pixelIndex].G = sumG;
            convdImg->imageData[pixelIndex].B = sumB;
        }
    }

    return convdImg;
}


int main(int argc, char* argv[])
{
    printf("Enter the name of the BMP file here: ");
    char name[MAX_FILENAME_SIZE];
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove the newline character from input

    BMPImage* img = LoadBMPImage(name);
    if (img == NULL) {
        printf("Error: Unable to load the BMP file.\n");
        return 1;
    }
    printf("Loaded successfully.\n");

    BMPImage* convdImg;
    float kernel[3][3];

    // Contour Extraction
    kernel[0][0] = -1.0 / 8;
    kernel[0][1] = -1.0 / 8;
    kernel[0][2] = -1.0 / 8;
    kernel[1][0] = -1.0 / 8;
    kernel[1][1] = 1.0;
    kernel[1][2] = -1.0 / 8;
    kernel[2][0] = -1.0 / 8;
    kernel[2][1] = -1.0 / 8;
    kernel[2][2] = -1.0 / 8;
    convdImg = Convolution2D(img, kernel);
    if (SaveBMPImage("outline.bmp", convdImg)) {
        printf("Output outline.bmp successfully.\n");
    } else {
        printf("Unable to output outline.bmp.\n");
    }
    free(convdImg->imageData);
    free(convdImg);

    // Gaussian Blur
    kernel[0][0] = 0.089;
    kernel[0][1] = 0.112;
    kernel[0][2] = 0.089;
    kernel[1][0] = 0.112;
    kernel[1][1] = 0.100;
    kernel[1][2] = 0.112;
    kernel[2][0] = 0.089;
    kernel[2][1] = 0.112;
    kernel[2][2] = 0.089;
    convdImg = Convolution2D(img, kernel);
    if (SaveBMPImage("gaussian.bmp", convdImg)) {
        printf("Output gaussian.bmp successfully.\n");
    } else {
        printf("Unable to output gaussian.bmp.\n");
    }
    free(convdImg->imageData);
    free(convdImg);

    // Sculpture Style
    kernel[0][0] = -1.0 / 2;
    kernel[0][1] = 0;
    kernel[0][2] = 0;
    kernel[1][0] = 0;
    kernel[1][1] = 0;
    kernel[1][2] = 0;
    kernel[2][0] = 0;
    kernel[2][1] = 0;
    kernel[2][2] = 1.0 / 2;
    convdImg = Convolution2D(img, kernel);
    if (SaveBMPImage("sculpture.bmp", convdImg)) {
        printf("Output sculpture.bmp successfully.\n");
    } else {
        printf("Unable to output sculpture.bmp.\n");
    }
    free(convdImg->imageData);
    free(convdImg);

    free(img->imageData);
    free(img);

    return 0;
}
