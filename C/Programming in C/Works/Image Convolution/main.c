
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cv.h"
#define MAX_FILENAME_SIZE 255

BMPImage* Convolution2D(BMPImage* img, float kernel[3][3]) {
    // Create a new BMPImage structure to store the convolved image
    BMPImage* convdImg = (BMPImage*)malloc(sizeof(BMPImage));
    convdImg->width = img->width;  // Set the width of the convolved image
    convdImg->height = img->height;  // Set the height of the convolved image
    convdImg->channels = img->channels;  // Set the number of channels of the convolved image
    convdImg->imageData = (PixelBlock*)malloc(sizeof(PixelBlock) * img->width * img->height);  // Allocate memory to store the convolved image data

    int i, j, k, l;  // Loop counters
    int sumR, sumG, sumB;  // Variables for accumulating the convolution result
    int kernelSize = 3;  // Size of the convolution kernel
    int kernelOffset = kernelSize / 2;  // Offset of the convolution kernel to align its center with the current pixel

    // Iterate over each pixel of the image
    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            sumR = 0;
            sumG = 0;
            sumB = 0;

            // Perform convolution on the surrounding pixels within the range of the kernel
            for (k = -kernelOffset; k <= kernelOffset; k++) {
                for (l = -kernelOffset; l <= kernelOffset; l++) {
                    int x = i + k;  // Row coordinate of the corresponding position in the kernel
                    int y = j + l;  // Column coordinate of the corresponding position in the kernel

                    // Check if the current position is within the image boundaries
                    if (x >= 0 && x < img->height && y >= 0 && y < img->width) {
                        int pixelIndex = x * img->width + y;  // Calculate the index of the current pixel in the image data array
                        // Multiply the corresponding pixel value in the kernel with the color value of the corresponding pixel and accumulate
                        sumR += img->imageData[pixelIndex].R * kernel[k + kernelOffset][l + kernelOffset];
                        sumG += img->imageData[pixelIndex].G * kernel[k + kernelOffset][l + kernelOffset];
                        sumB += img->imageData[pixelIndex].B * kernel[k + kernelOffset][l + kernelOffset];
                    }
                }
            }

            int pixelIndex = i * img->width + j;  // Calculate the index of the current pixel in the convolved image data array
            // Save the convolved pixel value into the image data array of the convolved image
            convdImg->imageData[pixelIndex].R = sumR;
            convdImg->imageData[pixelIndex].G = sumG;
            convdImg->imageData[pixelIndex].B = sumB;
        }
    }

    return convdImg;  // Return the convolved image
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
