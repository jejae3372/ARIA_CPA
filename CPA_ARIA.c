#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

typedef unsigned char Byte;

#define NUM_TRACE 1000
#define NUM_POINTS 5830
#define start_pt 0
#define end_pt 800
const Byte Sbox[4][256] = {
	// S-box type 1
{
  0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
  0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
  0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
  0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
  0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
  0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
  0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
  0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
  0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
  0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
  0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
  0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
  0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
  0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
  0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
  0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16},
  // S-box type 2
{
  0xe2, 0x4e, 0x54, 0xfc, 0x94, 0xc2, 0x4a, 0xcc, 0x62, 0x0d, 0x6a, 0x46, 0x3c, 0x4d, 0x8b, 0xd1,
  0x5e, 0xfa, 0x64, 0xcb, 0xb4, 0x97, 0xbe, 0x2b, 0xbc, 0x77, 0x2e, 0x03, 0xd3, 0x19, 0x59, 0xc1,
  0x1d, 0x06, 0x41, 0x6b, 0x55, 0xf0, 0x99, 0x69, 0xea, 0x9c, 0x18, 0xae, 0x63, 0xdf, 0xe7, 0xbb,
  0x00, 0x73, 0x66, 0xfb, 0x96, 0x4c, 0x85, 0xe4, 0x3a, 0x09, 0x45, 0xaa, 0x0f, 0xee, 0x10, 0xeb,
  0x2d, 0x7f, 0xf4, 0x29, 0xac, 0xcf, 0xad, 0x91, 0x8d, 0x78, 0xc8, 0x95, 0xf9, 0x2f, 0xce, 0xcd,
  0x08, 0x7a, 0x88, 0x38, 0x5c, 0x83, 0x2a, 0x28, 0x47, 0xdb, 0xb8, 0xc7, 0x93, 0xa4, 0x12, 0x53,
  0xff, 0x87, 0x0e, 0x31, 0x36, 0x21, 0x58, 0x48, 0x01, 0x8e, 0x37, 0x74, 0x32, 0xca, 0xe9, 0xb1,
  0xb7, 0xab, 0x0c, 0xd7, 0xc4, 0x56, 0x42, 0x26, 0x07, 0x98, 0x60, 0xd9, 0xb6, 0xb9, 0x11, 0x40,
  0xec, 0x20, 0x8c, 0xbd, 0xa0, 0xc9, 0x84, 0x04, 0x49, 0x23, 0xf1, 0x4f, 0x50, 0x1f, 0x13, 0xdc,
  0xd8, 0xc0, 0x9e, 0x57, 0xe3, 0xc3, 0x7b, 0x65, 0x3b, 0x02, 0x8f, 0x3e, 0xe8, 0x25, 0x92, 0xe5,
  0x15, 0xdd, 0xfd, 0x17, 0xa9, 0xbf, 0xd4, 0x9a, 0x7e, 0xc5, 0x39, 0x67, 0xfe, 0x76, 0x9d, 0x43,
  0xa7, 0xe1, 0xd0, 0xf5, 0x68, 0xf2, 0x1b, 0x34, 0x70, 0x05, 0xa3, 0x8a, 0xd5, 0x79, 0x86, 0xa8,
  0x30, 0xc6, 0x51, 0x4b, 0x1e, 0xa6, 0x27, 0xf6, 0x35, 0xd2, 0x6e, 0x24, 0x16, 0x82, 0x5f, 0xda,
  0xe6, 0x75, 0xa2, 0xef, 0x2c, 0xb2, 0x1c, 0x9f, 0x5d, 0x6f, 0x80, 0x0a, 0x72, 0x44, 0x9b, 0x6c,
  0x90, 0x0b, 0x5b, 0x33, 0x7d, 0x5a, 0x52, 0xf3, 0x61, 0xa1, 0xf7, 0xb0, 0xd6, 0x3f, 0x7c, 0x6d,
  0xed, 0x14, 0xe0, 0xa5, 0x3d, 0x22, 0xb3, 0xf8, 0x89, 0xde, 0x71, 0x1a, 0xaf, 0xba, 0xb5, 0x81},
  // inverse of S-box type 1
{
  0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb,
  0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb,
  0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e,
  0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25,
  0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92,
  0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84,
  0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06,
  0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b,
  0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73,
  0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e,
  0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b,
  0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4,
  0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f,
  0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef,
  0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61,
  0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d},
  // inverse of S-box type 2
{
  0x30, 0x68, 0x99, 0x1b, 0x87, 0xb9, 0x21, 0x78, 0x50, 0x39, 0xdb, 0xe1, 0x72, 0x09, 0x62, 0x3c,
  0x3e, 0x7e, 0x5e, 0x8e, 0xf1, 0xa0, 0xcc, 0xa3, 0x2a, 0x1d, 0xfb, 0xb6, 0xd6, 0x20, 0xc4, 0x8d,
  0x81, 0x65, 0xf5, 0x89, 0xcb, 0x9d, 0x77, 0xc6, 0x57, 0x43, 0x56, 0x17, 0xd4, 0x40, 0x1a, 0x4d,
  0xc0, 0x63, 0x6c, 0xe3, 0xb7, 0xc8, 0x64, 0x6a, 0x53, 0xaa, 0x38, 0x98, 0x0c, 0xf4, 0x9b, 0xed,
  0x7f, 0x22, 0x76, 0xaf, 0xdd, 0x3a, 0x0b, 0x58, 0x67, 0x88, 0x06, 0xc3, 0x35, 0x0d, 0x01, 0x8b,
  0x8c, 0xc2, 0xe6, 0x5f, 0x02, 0x24, 0x75, 0x93, 0x66, 0x1e, 0xe5, 0xe2, 0x54, 0xd8, 0x10, 0xce,
  0x7a, 0xe8, 0x08, 0x2c, 0x12, 0x97, 0x32, 0xab, 0xb4, 0x27, 0x0a, 0x23, 0xdf, 0xef, 0xca, 0xd9,
  0xb8, 0xfa, 0xdc, 0x31, 0x6b, 0xd1, 0xad, 0x19, 0x49, 0xbd, 0x51, 0x96, 0xee, 0xe4, 0xa8, 0x41,
  0xda, 0xff, 0xcd, 0x55, 0x86, 0x36, 0xbe, 0x61, 0x52, 0xf8, 0xbb, 0x0e, 0x82, 0x48, 0x69, 0x9a,
  0xe0, 0x47, 0x9e, 0x5c, 0x04, 0x4b, 0x34, 0x15, 0x79, 0x26, 0xa7, 0xde, 0x29, 0xae, 0x92, 0xd7,
  0x84, 0xe9, 0xd2, 0xba, 0x5d, 0xf3, 0xc5, 0xb0, 0xbf, 0xa4, 0x3b, 0x71, 0x44, 0x46, 0x2b, 0xfc,
  0xeb, 0x6f, 0xd5, 0xf6, 0x14, 0xfe, 0x7c, 0x70, 0x5a, 0x7d, 0xfd, 0x2f, 0x18, 0x83, 0x16, 0xa5,
  0x91, 0x1f, 0x05, 0x95, 0x74, 0xa9, 0xc1, 0x5b, 0x4a, 0x85, 0x6d, 0x13, 0x07, 0x4f, 0x4e, 0x45,
  0xb2, 0x0f, 0xc9, 0x1c, 0xa6, 0xbc, 0xec, 0x73, 0x90, 0x7b, 0xcf, 0x59, 0x8f, 0xa1, 0xf9, 0x2d,
  0xf2, 0xb1, 0x00, 0x94, 0x37, 0x9f, 0xd0, 0x2e, 0x9c, 0x6e, 0x28, 0x3f, 0x80, 0xf0, 0x3d, 0xd3,
  0x25, 0x8a, 0xb5, 0xe7, 0x42, 0xb3, 0xc7, 0xea, 0xf7, 0x4c, 0x11, 0x33, 0x03, 0xa2, 0xac, 0x60}
};

const Byte KRK[3][16] = {
  {0x51, 0x7c, 0xc1, 0xb7, 0x27, 0x22, 0x0a, 0x94, 0xfe, 0x13, 0xab, 0xe8, 0xfa, 0x9a, 0x6e, 0xe0}, 
  {0x6d, 0xb1, 0x4a, 0xcc, 0x9e, 0x21, 0xc8, 0x20, 0xff, 0x28, 0xb1, 0xd5, 0xef, 0x5d, 0xe2, 0xb0}, 
  {0xdb, 0x92, 0x37, 0x1d, 0x21, 0x26, 0xe9, 0x70, 0x03, 0x24, 0x97, 0x75, 0x04, 0xe8, 0xc9, 0x0e}
};

const float HW_8[256] = {
0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 
1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 
1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 
2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 
1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 
2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 
2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 
3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 
1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 
2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 
2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 
3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 
2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 
3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 
3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 
4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8 };

const int proba_table[16][4] = {
    {0, 0, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}, {0, 0, 1, 1},
    {0, 1, 0, 0}, {0, 1, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 1},
    {1, 0, 0, 0}, {1, 0, 0, 1}, {1, 0, 1, 0}, {1, 0, 1, 1},
    {1, 1, 0, 0}, {1, 1, 0, 1}, {1, 1, 1, 0}, {1, 1, 1, 1}
};

float Pearson_corr(float* x, float* y, int n){
    float sum_x = 0.0; float sum_y = 0.0;
    float sum_xy = 0.0; float sum_x2 = 0.0;
    float sum_y2 = 0.0;
    float a, b; // a가 분자 b가 분모
    for(int i = 0; i < n; i++){
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x2 += x[i] * x[i];  
        sum_y2 += y[i] * y[i];
    }
    a = n * sum_xy - sum_x * sum_y;
    b = sqrtf((n * sum_x2 - sum_x * sum_x)*(n * sum_y2 - sum_y * sum_y));

    if (b != 0){
        return fabsf(a / b);    //절댓값으로 리턴
    }
    printf("Division Error");
    return 0;   // 분모가 0
}


float **Trace_array(){
    float **array;
    FILE *file = fopen("CTF-4-ARIA-trace.bin", "rb");
    if (file == NULL) {
        perror("Cannot allocate memory");
        fclose(file);
        exit(1);
    }
    fseek(file, 16, SEEK_SET); //16bytes passing
    // 행에 대한 메모리 할당
    array = (float **)malloc(NUM_TRACE * sizeof(float *));
    if (array == NULL) {
        perror("Cannot allocate memory");
        fclose(file);
        free(array);
        exit(1);
    }
    // 각 행에 대한 열에 대한 메모리 할당
    for (int i = 0; i < NUM_TRACE; i++) {
        array[i] = (float *)malloc(NUM_POINTS * sizeof(float));
        if (array[i] == NULL) {
            perror("Cannot allocate memory");
            for (int j = 0; j < i; j++) {
                free(array[j]);
            }
            free(array);
            fclose(file);
            exit(1);
        }
    }
    //4byte --> float
    Byte buffer[4];
    for (int i = 0; i < NUM_TRACE; i++) {
        for (int j = 0; j < NUM_POINTS; j++) {
            if (fread(buffer, sizeof(Byte), 4, file) != 4) {
                perror("file read error");
                for (int k = 0; k < NUM_TRACE; k++) {
                    free(array[k]);
                }
                free(array);
                fclose(file);
                exit(1);
            }
            //float 값 저장
            float value = *((float *)buffer);
            array[i][j] = value;
        }
    }
    fclose(file);
    return array;
}

void fileToArray(Byte byteArray[NUM_TRACE][16]) {
    FILE* fp = fopen("CTF-4-ARIA-plain.bin", "rb");
    if (fp == NULL) {
        printf("Cannot open file\n");
        exit(1);
    }
    fseek(fp, 16, SEEK_SET);
    for(int i = 0; i < NUM_TRACE; i++){
        size_t bytesRead = fread(byteArray[i], 1, 16, fp);
        if (bytesRead < 16) {
            if (feof(fp)) {
                printf("EOF\n");
            } else if (ferror(fp)) {
                perror("File Read error");
            }
            break;
        }
    }
    fclose(fp);
}

void DL(const Byte *i, Byte *o)
{
	Byte T;
  
	T = i[ 3] ^ i[ 4] ^ i[ 9] ^ i[14];
	o[ 0] = i[ 6] ^ i[ 8] ^ i[13] ^ T;
	o[ 5] = i[ 1] ^ i[10] ^ i[15] ^ T;
	o[11] = i[ 2] ^ i[ 7] ^ i[12] ^ T;
	o[14] = i[ 0] ^ i[ 5] ^ i[11] ^ T;
	T = i[ 2] ^ i[ 5] ^ i[ 8] ^ i[15];
	o[ 1] = i[ 7] ^ i[ 9] ^ i[12] ^ T;
	o[ 4] = i[ 0] ^ i[11] ^ i[14] ^ T;
	o[10] = i[ 3] ^ i[ 6] ^ i[13] ^ T;
	o[15] = i[ 1] ^ i[ 4] ^ i[10] ^ T;
	T = i[ 1] ^ i[ 6] ^ i[11] ^ i[12];
	o[ 2] = i[ 4] ^ i[10] ^ i[15] ^ T;
	o[ 7] = i[ 3] ^ i[ 8] ^ i[13] ^ T;
	o[ 9] = i[ 0] ^ i[ 5] ^ i[14] ^ T;
	o[12] = i[ 2] ^ i[ 7] ^ i[ 9] ^ T;
	T = i[ 0] ^ i[ 7] ^ i[10] ^ i[13];
	o[ 3] = i[ 5] ^ i[11] ^ i[14] ^ T;
	o[ 6] = i[ 2] ^ i[ 9] ^ i[12] ^ T;
	o[ 8] = i[ 1] ^ i[ 4] ^ i[15] ^ T;
	o[13] = i[ 3] ^ i[ 6] ^ i[ 8] ^ T;
}


void RK1_DL_table(Byte byteArray[NUM_TRACE][16], Byte return_table[256][NUM_TRACE], int byte_idx){

    int temp0;
    Byte known_1R_key[16] = {0xCB, 0x00, 0x16, 0xA7, 0x91, 0xAA, 0x00, 0x47, 
                              0x4D, 0xA2, 0xD8, 0x00, 0x00, 0x2B, 0xC8, 0x83};

    //o[ 0] = i[ 6] ^ i[ 8] ^ i[13] ^ i[ 3] ^ i[ 4] ^ i[ 9] ^ i[14]
    if(byte_idx == 6){
        for(int RK1_6_candi = 0; RK1_6_candi < 256; RK1_6_candi++){
            for(int Plain_idx = 0; Plain_idx < NUM_TRACE; Plain_idx++){
                temp0 = Sbox[2][(RK1_6_candi ^ byteArray[Plain_idx][6])] ^ Sbox[0][(known_1R_key[8] ^ byteArray[Plain_idx][8])] ^ \
                        Sbox[1][(known_1R_key[13] ^ byteArray[Plain_idx][13])] ^ Sbox[3][(known_1R_key[3] ^ byteArray[Plain_idx][3])] ^ \
                        Sbox[0][(known_1R_key[4] ^ byteArray[Plain_idx][4])] ^ Sbox[1][(known_1R_key[9] ^ byteArray[Plain_idx][9])] ^ \
                        Sbox[2][(known_1R_key[14] ^ byteArray[Plain_idx][14])];
                return_table[RK1_6_candi][Plain_idx] = temp0;    
            }
        }
    }
    //o[ 5] = i[ 1] ^ i[10] ^ i[15] ^ i[ 3] ^ i[ 4] ^ i[ 9] ^ i[14]
    else if(byte_idx == 1){
        for(int RK1_1_candi = 0; RK1_1_candi < 256; RK1_1_candi++){
            for(int Plain_idx = 0; Plain_idx < NUM_TRACE; Plain_idx++){
                temp0 = Sbox[1][(RK1_1_candi ^ byteArray[Plain_idx][1])] ^ Sbox[2][(known_1R_key[10] ^ byteArray[Plain_idx][10])] ^ \
                        Sbox[3][(known_1R_key[15] ^ byteArray[Plain_idx][15])] ^ Sbox[3][(known_1R_key[3] ^ byteArray[Plain_idx][3])] ^ \
                        Sbox[0][(known_1R_key[4] ^ byteArray[Plain_idx][4])] ^ Sbox[1][(known_1R_key[9] ^ byteArray[Plain_idx][9])] ^ \
                        Sbox[2][(known_1R_key[14] ^ byteArray[Plain_idx][14])];
                return_table[RK1_1_candi][Plain_idx] = temp0;    
            }
        }
    }
    //o[14] = i[ 0] ^ i[ 5] ^ i[11] ^ i[ 3] ^ i[ 4] ^ i[ 9] ^ i[14]
    else if(byte_idx == 11){
        for(int RK1_11_candi = 0; RK1_11_candi < 256; RK1_11_candi++){
            for(int Plain_idx = 0; Plain_idx < NUM_TRACE; Plain_idx++){
                temp0 = Sbox[3][(RK1_11_candi ^ byteArray[Plain_idx][11])] ^ Sbox[0][(known_1R_key[0] ^ byteArray[Plain_idx][0])] ^ \
                        Sbox[1][(known_1R_key[5] ^ byteArray[Plain_idx][5])] ^ Sbox[3][(known_1R_key[3] ^ byteArray[Plain_idx][3])] ^ \
                        Sbox[0][(known_1R_key[4] ^ byteArray[Plain_idx][4])] ^ Sbox[1][(known_1R_key[9] ^ byteArray[Plain_idx][9])] ^ \
                        Sbox[2][(known_1R_key[14] ^ byteArray[Plain_idx][14])];
                return_table[RK1_11_candi][Plain_idx] = temp0;    
            }
        }
    }
    //o[ 6] = i[ 2] ^ i[ 9] ^ i[12] ^ i[ 0] ^ i[ 7] ^ i[10] ^ i[13];
    else{
        for(int RK1_12_candi = 0; RK1_12_candi < 256; RK1_12_candi++){
            for(int Plain_idx = 0; Plain_idx < NUM_TRACE; Plain_idx++){
                temp0 = Sbox[0][(RK1_12_candi ^ byteArray[Plain_idx][12])] ^ Sbox[2][(known_1R_key[2] ^ byteArray[Plain_idx][2])] ^ \
                        Sbox[1][(known_1R_key[9] ^ byteArray[Plain_idx][9])] ^ Sbox[0][(known_1R_key[0] ^ byteArray[Plain_idx][0])] ^ \
                        Sbox[3][(known_1R_key[7] ^ byteArray[Plain_idx][7])] ^ Sbox[2][(known_1R_key[10] ^ byteArray[Plain_idx][10])] ^ \
                        Sbox[1][(known_1R_key[13] ^ byteArray[Plain_idx][13])];
                return_table[RK1_12_candi][Plain_idx] = temp0;    
            }
        }
    }
}


void find_1R_Key(Byte byteArray[NUM_TRACE][16], Byte R1table[256][NUM_TRACE], int byte_idx, Byte R1_key[16]){
    Byte temp0, temp1, interm_value;
    float hw_interm[NUM_TRACE], pt_interm[NUM_TRACE];
    Byte RK1_max, RK2_max;
    float max_corr, temp_corr;
    float glo_max = 0.0;
    float glo_sec = 0.0;

    float **point_array = Trace_array();  

    for(int RK1_candi = 0; RK1_candi < 256; RK1_candi++){
        for(int RK2_candi = 0; RK2_candi < 256; RK2_candi++){
            max_corr = 0;
            for(int Point_idx = start_pt; Point_idx < end_pt; Point_idx++){
                for(int Plain_idx = 0; Plain_idx < NUM_TRACE; Plain_idx++){
                    temp0 = R1table[RK1_candi][Plain_idx];
                    temp1 = temp0 ^ RK2_candi;

                    //예측한 1R 출력값에 대해 2R 1byte 예측 --> Sbox 출력 : 중간값
                    if(byte_idx == 6){                  //o[0] => 1R 6-th byte
                        interm_value = Sbox[2][temp1];
                    }
                    else if(byte_idx == 1){       // o[1] => 1R 1-th byte
                        interm_value = Sbox[3][temp1];
                    }
                    else{            //o[6], o[14] => 1R 11-th, 12-th byte
                        interm_value = Sbox[0][temp1];  
                    }
                            
                    hw_interm[Plain_idx] = HW_8[interm_value];
                    pt_interm[Plain_idx] = point_array[Plain_idx][Point_idx];
                }
                temp_corr = Pearson_corr(hw_interm, pt_interm, NUM_TRACE);
                if(temp_corr > max_corr){
                    max_corr = temp_corr;
                }
            }
            if (max_corr > glo_max) {
                glo_sec = glo_max;
                glo_max = max_corr;
                RK1_max = RK1_candi;
                RK2_max = RK2_candi;
                R1_key[byte_idx] = RK1_candi;
            }
            else if(max_corr > glo_sec){
                glo_sec = max_corr;
            }
        }
    }
    printf("\n[%d-th 1Rk] RK1_max : %02x, RK2_max : %02x, max_corr : %0.3f ratio : %0.3f", byte_idx, RK1_max, RK2_max, glo_max, glo_max/glo_sec);
    for (int i = 0; i < NUM_TRACE; i++) {
        free(point_array[i]);
    }
    free(point_array);
}

void Gen_DL_table(Byte byteArray[NUM_TRACE][16], Byte RK_list[16], int Round){
    Byte state[NUM_TRACE][16];
    for(int tr_idx = 0; tr_idx < NUM_TRACE; tr_idx++){
        for(int idx = 0; idx < 16; idx ++){
            state[tr_idx][idx] = byteArray[tr_idx][idx] ^ RK_list[idx];
            if((Round % 2) == 1){
                state[tr_idx][idx] = Sbox[idx % 4][state[tr_idx][idx]];
            }
            else{
                state[tr_idx][idx] = Sbox[(idx + 2) % 4][state[tr_idx][idx]];
            }
        }

        DL(state[tr_idx], byteArray[tr_idx]);
    }
}

void find_RK(Byte DL_table[NUM_TRACE][16], Byte RK_list[5][16], int round){
    Byte temp, IV;
    float max_corr, temp_corr;
    float hw_iv[NUM_TRACE], pt_iv[NUM_TRACE];   
    int start_point[4] = {0, 800, 2400, 4100};
    float** point_array = Trace_array();

    for(int byte_idx = 0; byte_idx < 16; byte_idx ++){
        float glo_max = 0;
        float glo_sec = 0;
        for(int R2_candi = 0; R2_candi < 256; R2_candi ++){
            max_corr = 0;
            for(int pt_idx = start_point[round - 2]; pt_idx < start_point[round - 2] + 1000; pt_idx ++){
                for(int tr_idx = 0; tr_idx < NUM_TRACE; tr_idx ++){
                    temp = DL_table[tr_idx][byte_idx] ^ R2_candi;
                    if((round % 2) == 1){
                        IV = Sbox[byte_idx % 4][temp];
                    }
                    else{
                        IV = Sbox[(byte_idx + 2) % 4][temp];
                    }
                    hw_iv[tr_idx] = HW_8[IV];
                    pt_iv[tr_idx] = point_array[tr_idx][pt_idx];
                }
                temp_corr = Pearson_corr(hw_iv, pt_iv, NUM_TRACE);  
                if(temp_corr > max_corr){
                    max_corr = temp_corr;
                }    
            }
            if(max_corr > glo_max){
                glo_sec = glo_max;
                glo_max = max_corr;
                RK_list[round - 1][byte_idx] = R2_candi;
            }
            else if(max_corr > glo_sec){
                glo_sec = max_corr;
            }
        }
        printf("[%d-th key] %02x , Ratio: %0.5f", byte_idx, RK_list[round-1][byte_idx], glo_max/glo_sec);
        printf("\n");
    }
    printf("[Round %d Key] : ", round);
    for(int k = 0; k < 16; k ++){
        printf("0x%02x, ", RK_list[round - 1][k]);
    }
    printf("\n");

    for (int i = 0; i < NUM_TRACE; i++) {
        free(point_array[i]);
    }
    free(point_array); 
}

void RotXOR (const Byte *s, int n, Byte *t)
{
	int i, q;
  
	q = n/8; n %= 8;
	for (i = 0; i < 16; i++) {
		t[(q+i) % 16] ^= (s[i] >> n);
		if (n != 0) t[(q+i+1) % 16] ^= (s[i] << (8-n));
	}
}

void RotLXOR (const Byte *s, int n, Byte *t)
{
	int i, q;
  
	q = n/8; n %= 8;
	for (i = 0; i < 16; i++) {
		t[(i + 1) % 16] ^= (s[(i + 3) % 16] << 3);
		if (n != 0) t[i] ^= (s[(i + 3) % 16] >> (8-n));
	}
}

void byteToBinary(Byte byteArray[16], int bitArray[128]) {
    for (int i = 0; i < 16; i++) {
        for (int j = 7; j >= 0; j--) {
            bitArray[i * 8 + (7 - j)] = (byteArray[i] & (1 << j)) ? 1 : 0;
        }
    }
}
void Binarytobyte(Byte ByteArray[16], int bitArray[128]){
    for (int i = 0; i < 16; i++) {
        Byte value = 0; 
        for (int j = 0; j < 8; j++) {
            value = (value << 1) | bitArray[i * 8 + j]; 
        }
        ByteArray[i] = value;
    }
}

void gen_W0_candi(Byte RK1[16], Byte RK5[16], Byte W0_table[16][16]){
    Byte T[16] = {0};
    Byte T_shift[16] = {0};
    Byte W_0[16];
    Byte W_1[16];
    int T_str[128] = {0};

    for(int j = 0; j < 16; j ++){
        T[j] = RK1[j] ^ RK5[j];
    }

    RotLXOR(T, 19, T_shift);

    byteToBinary(T_shift, T_str); //T<<<19 (bin)

    for(int idx = 0; idx < 16; idx++){
        Byte W_1_shift[16] = {0};
        int W[128] = {0};   
        W[0] = proba_table[idx][3];
        W[1] = proba_table[idx][2];
        W[2] = proba_table[idx][1];
        W[3] = proba_table[idx][0];
        for(int bit_idx = 0; bit_idx < 31; bit_idx++){
            W[(0 + 12 * (bit_idx + 1)) % 128] = W[(0 + 12 * bit_idx) % 128] ^ T_str[(0 + 12 * (bit_idx + 1)) % 128];
            W[(1 + 12 * (bit_idx + 1)) % 128] = W[(1 + 12 * bit_idx) % 128] ^ T_str[(1 + 12 * (bit_idx + 1)) % 128];
            W[(2 + 12 * (bit_idx + 1)) % 128] = W[(2 + 12 * bit_idx) % 128] ^ T_str[(2 + 12 * (bit_idx + 1)) % 128];
            W[(3 + 12 * (bit_idx + 1)) % 128] = W[(3 + 12 * bit_idx) % 128] ^ T_str[(3 + 12 * (bit_idx + 1)) % 128];
        }
        Binarytobyte(W_1, W);
        RotXOR(W_1, 19, W_1_shift);
        for(int i = 0; i < 16; i++){
            W_0[i] = W_1_shift[i] ^ RK1[i];
        }
        
        for(int byte_idx = 0; byte_idx < 16; byte_idx++){
            W0_table[idx][byte_idx] = W_0[byte_idx];
        }
    }
}

void gen_W0_candi_2(Byte known_T[16], Byte RK_list[4][16], Byte W0_table[16][16]){
    Byte T[16] = {0};
    Byte RK2_shifted[16] = {0};Byte RK3_shifted[16] = {0};Byte RK4_shifted[16] = {0};
    Byte W_0[16];
    int T_str[128] = {0};

    RotXOR(RK_list[1], 19, RK2_shifted);
    RotXOR(RK_list[2], 38, RK3_shifted);
    RotXOR(RK_list[3], 57, RK4_shifted);

    //known_T = W0 ^ (W0 >> 76)
    for(int idx = 0; idx < 16; idx++){
        known_T[idx] = RK_list[0][idx] ^ RK2_shifted[idx] ^ RK3_shifted[idx] ^ RK4_shifted[idx];       
    }
    
    byteToBinary(known_T, T_str);           

    for(int idx = 0; idx < 16; idx++){
        int W[128] = {0};   
        W[0] = proba_table[idx][3];
        W[1] = proba_table[idx][2];
        W[2] = proba_table[idx][1];
        W[3] = proba_table[idx][0];
        for(int bit_idx = 0; bit_idx < 31; bit_idx++){
            W[(0 + 76 * (bit_idx + 1)) % 128] = W[(0 + 76 * bit_idx) % 128] ^ T_str[(0 + 76 * (bit_idx + 1)) % 128];
            W[(1 + 76 * (bit_idx + 1)) % 128] = W[(1 + 76 * bit_idx) % 128] ^ T_str[(1 + 76 * (bit_idx + 1)) % 128];
            W[(2 + 76 * (bit_idx + 1)) % 128] = W[(2 + 76 * bit_idx) % 128] ^ T_str[(2 + 76 * (bit_idx + 1)) % 128];
            W[(3 + 76 * (bit_idx + 1)) % 128] = W[(3 + 76 * bit_idx) % 128] ^ T_str[(3 + 76 * (bit_idx + 1)) % 128];
        }
        Binarytobyte(W_0, W);
        
        for(int byte_idx = 0; byte_idx < 16; byte_idx++){
            W0_table[idx][byte_idx] = W_0[byte_idx];
        }
    }
}

void validate_mk(Byte W0_table[16][16], Byte RK1[16]){
    Byte state[16], out_state[16];
    for(int idx_1 = 0; idx_1 < 16; idx_1 ++){
        for(int byte_idx = 0; byte_idx < 16; byte_idx ++){
            state[byte_idx] = W0_table[idx_1][byte_idx] ^ KRK[0][byte_idx];
            state[byte_idx] = Sbox[byte_idx % 4][state[byte_idx]];
        }
        Byte W1_candi[16] = {0};
        DL(state, out_state);
        RotXOR(out_state, 19, W1_candi);
        for(int i = 0; i < 16; i++){
            out_state[i] = W0_table[idx_1][i] ^ W1_candi[i];
        }
        int flag = 0;
        for(int byte_idx = 0; byte_idx < 16; byte_idx ++){
            if(out_state[byte_idx] != RK1[byte_idx]){
                flag = 1;
            }
        }
        if(flag == 0){
            printf("find correct master key!\n");
            for(int byte_idx = 0; byte_idx < 16; byte_idx ++){
                printf("%02x ",  W0_table[idx_1][byte_idx]);
            }
            printf("\n");
        }
    }
}

//R1 key : cb d3 16 a7 91 aa 4d 47 4d a2 d8 76 ce 2b c8 83
//R2 key : ba e3 64 1f 9e 99 65 fc 3d ed 67 ea 8d 51 5e a7 
//R3 key : 3f 16 f4 e9 dc 1d 98 32 e0 e3 64 7a 13 e1 18 fe 
//R4 key : 10 a0 db a0 09 ee 84 dd d0 cd 60 61 33 22 62 66
//R5 key : 25 27 59 81 2f 6c 7c ca 81 97 92 33 08 8a 28 cd

int main(){
    Byte byteArray[NUM_TRACE][16];
    Byte RK1table[256][NUM_TRACE];
    Byte DLtable[NUM_TRACE][16] = {0};
    Byte RK_list[5][16];
    Byte W0_table[16][16];
    double execution_time;
    Byte known_T[16];


    Byte known_1R[16] = {0xCB, 0xD3, 0x16, 0xA7, 0x91, 0xAA, 0x4D, 0x47, 
                        0x4D, 0xA2, 0xD8, 0x76, 0xCE, 0x2B, 0xC8, 0x83};

    for(int idx = 0; idx < 16; idx ++){
        RK_list[0][idx] = known_1R[idx];
    }

    fileToArray(byteArray);

    //Find 1R Key
    clock_t start_time = clock();
    int byte_idx[4] = {1, 6, 11, 12};
    for(int i = 0; i < 4; i ++){
        RK1_DL_table(byteArray, RK1table, byte_idx[i]);
        find_1R_Key(byteArray, RK1table, byte_idx[i], RK_list[0]);
    }
    clock_t end_time =  clock();

    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", execution_time);

    printf("\n");
    for(int j = 0; j < 16; j ++){
        printf("%02x ", RK_list[0][j]);
    }
    printf("\n");

    //Find Other Round Keys
    clock_t start_time1 = clock();
    for(int r_idx = 1; r_idx < 5; r_idx ++){
        Gen_DL_table(byteArray, RK_list[r_idx - 1], r_idx);
        find_RK(byteArray, RK_list, r_idx + 1);
    }
    clock_t end_time2 = clock();
    execution_time = (double)(end_time2 - start_time1) / CLOCKS_PER_SEC;
    printf("Find Rk time: %f seconds\n", execution_time);

    start_time1 = clock();
    gen_W0_candi(RK_list[0], RK_list[4], W0_table);
    //gen_W0_candi_2(known_T, RK_list, W0_table);   //use only 1~4 Round keys
    validate_mk(W0_table, RK_list[0]);
    end_time2 =  clock();
    execution_time = (double)(end_time2 - start_time1) / CLOCKS_PER_SEC;
    printf("Find Mk time: %f seconds\n", execution_time);

    return 0;
}
