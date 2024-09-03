#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BUFFER_SIZE 1024

typedef struct {
    char riff[4];        // "RIFF"
    uint32_t size;       // File size - 8
    char wave[4];        // "WAVE"
    char fmt[4];         // "fmt "
    uint32_t fmt_size;   // Size of the fmt chunk (16 for PCM)
    uint16_t audio_fmt;  // Audio format (1 for PCM)
    uint16_t channels;   // Number of channels
    uint32_t sample_rate;// Sampling rate
    uint32_t byte_rate;  // Bytes per second
    uint16_t block_align;// Block alignment
    uint16_t bits_per_sample; // Bits per sample
    char data[4];        // "data"
    uint32_t data_size;  // Size of the data chunk
} WAV_HEADER;

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }

    char *infile = argv[1];
    char *outfile = argv[2];

    FILE *inptr = fopen(infile, "rb");
    if (inptr == NULL) {
        printf("Could not open %s.\n", infile);
        return 1;
    }

    WAV_HEADER header;
    fread(&header, sizeof(WAV_HEADER), 1, inptr);

    if (header.audio_fmt != 1) {
        printf("Only PCM audio format is supported.\n");
        fclose(inptr);
        return 1;
    }

    FILE *outptr = fopen(outfile, "wb");
    if (outptr == NULL) {
        printf("Could not create %s.\n", outfile);
        fclose(inptr);
        return 1;
    }

    fwrite(&header, sizeof(WAV_HEADER), 1, outptr);

    // ...

// Reversing the audio data
uint16_t buffer[BUFFER_SIZE];
uint32_t samples_read = 0;
uint32_t samples_total = header.data_size / sizeof(buffer[0]);

// Move the input file pointer to the start of the audio data
fseek(inptr, sizeof(WAV_HEADER), SEEK_SET);

while (samples_read < samples_total) {
    uint32_t samples_to_read = samples_total - samples_read;
    if (samples_to_read > BUFFER_SIZE) {
        samples_to_read = BUFFER_SIZE;
    }

    uint32_t bytes_to_read = samples_to_read * sizeof(buffer[0]);
    uint32_t bytes_read = fread(buffer, 1, bytes_to_read, inptr);

    if (bytes_read != bytes_to_read) {
        printf("Error reading from %s.\n", infile);
        fclose(inptr);
        fclose(outptr);
        return 1;
    }

    // Reverse the samples within each block
    for (int i = 0; i < samples_to_read / 2; i++) {
        uint16_t temp = buffer[i];
        buffer[i] = buffer[samples_to_read - i - 1];
        buffer[samples_to_read - i - 1] = temp;
    }

    // Write the reversed block of audio data to the output file
    fwrite(buffer, bytes_read, 1, outptr);

    // Move the input file pointer back by two block sizes
    fseek(inptr, -2 * bytes_to_read, SEEK_CUR);

    samples_read += samples_to_read;
}

// ...

    fclose(inptr);
    fclose(outptr);

    return 0;
}
