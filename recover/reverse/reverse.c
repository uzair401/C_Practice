#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("usage: ./reverse [input] [output]\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("cannot open input\n");
        return 1;
    }

    const int HEADER_SIZE = sizeof(WAVHEADER);
    WAVHEADER header;
    fread(&header, HEADER_SIZE, 1, input);

    if (check_format(header) == 1)
    {
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        return 1;
    }

    fwrite(&header, HEADER_SIZE, 1, output);

    int block_size = get_block_size(header);

    uint16_t buffer;

    fseek(input, 0, SEEK_END);

    while (ftell(input) > HEADER_SIZE)
    {
        // write blocks in reverse
        fseek(input, -2, SEEK_CUR);
        fread(&buffer, sizeof(buffer), 1, input);
        fwrite(&buffer, sizeof(buffer), 1, output);
        fseek(input, -2, SEEK_CUR);
    }

    fclose(input);
    fclose(output);
}

int check_format(WAVHEADER header)
{
    if (header.format[0] == 'W' && header.format[1] == 'A' && header.format[2] == 'V' && header.format[3] == 'E')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int get_block_size(WAVHEADER header)
{
    int block_size = 0;
    block_size = header.numChannels * (header.bitsPerSample * 0.125);
    return block_size;
}