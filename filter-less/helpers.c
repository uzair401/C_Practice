#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(i nt height, int width, RGBTRIPLE image[height][width])
{
    int num = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float number = (image[i][j].rgbtGreen + image[i][j].rgbtBlue + image[i][j].rgbtRed) / 3.0;
            num = round(number);
            image[i][j].rgbtGreen = num;
            image[i][j].rgbtRed = num;
            image[i][j].rgbtBlue = num;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed = 0;
    int sepiaGreen = 0;
    int sepiaBlue = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sepiaRed = round((0.393 * image[i][j].rgbtRed) + (0.189 * image[i][j].rgbtBlue) + (0.769 * image[i][j].rgbtGreen));
            sepiaGreen = round((0.349 * image[i][j].rgbtRed) + (0.168 * image[i][j].rgbtBlue) + (0.686 * image[i][j].rgbtGreen));
            sepiaBlue = round((0.272 * image[i][j].rgbtRed) + (0.131 * image[i][j].rgbtBlue) + (0.534 * image[i][j].rgbtGreen));
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtBlue = sepiaBlue;

        }
    }

}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    int radius = 1;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sum_red = 0;
            float sum_green = 0;
            float sum_blue = 0;
            float count = 0;

            for (int k = -radius; k <= radius; k++)
            {
                for (int l = -radius; l <= radius; l++)
                {
                    if (i + k >= 0 && i + k < height && j + l >= 0 && j + l < width)
                    {
                        sum_red += temp[i + k][j + l].rgbtRed;
                        sum_green += temp[i + k][j + l].rgbtGreen;
                        sum_blue += temp[i + k][j + l].rgbtBlue;
                        count++;
                    }
                }
            }

            image[i][j].rgbtRed = round(sum_red / count);
            image[i][j].rgbtGreen = round(sum_green / count);
            image[i][j].rgbtBlue = round(sum_blue / count);
        }
    }

}
