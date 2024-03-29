// ***********************************************************************************
// ���������������: 1986��92�
// ����������: ���������� ����� �1986��92QI
// ����: mlt_lcd.h 
// ����������:  ������ � ��� MT�12864J. ����������������� ����� 8�8 �����. 
// ����������:  Armcc 5.03.0.76 �� ��������� Keil uVision 4.72.1.0 
// ***********************************************************************************

#ifndef __MLT_FONT_H
  #define __MLT_FONT_H


// ����� ��������� � ������� ��������� MicroElektronika GLCD Font Creator 1.2.0.0 (���������� ������ ��� ����������� ����������)
// http://www.mikroe.com/glcd-font-creator/
// ��� �������� ������ ������� ������ 8�8
// ��� �������� ������ ������� ���������: Generate Code For Use With -> mikroC GLCD Lib

// ������� ��������� ��������, ������������ ��� ������� ������.
#define MLT_FONT_MIN_CODE  32
#define MLT_FONT_MAX_CODE  255

static const char MLT_Font [] = 
{
  0,   0,   0,   0,   0,   0,   0,   0,  // space 32   0x20
	
0x00, 0x00, 0x00, 0xDF, 0xDF, 0x00, 0x00, 0x00,  // !  0x21
0x00, 0x07, 0x07, 0x00, 0x07, 0x07, 0x00, 0x00,  // "  0x22
0x24, 0x24, 0xFF, 0x24, 0xFF, 0x24, 0x24, 0x00,  // #  0x23
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // $  0x24
0x00, 0x63, 0x33, 0x18, 0x0C, 0x66, 0x63, 0x00,  // %  0x25
0x60, 0xF6, 0x9F, 0x89, 0x9F, 0x76, 0xD8, 0x00,  // &  0x26
0x00, 0x00, 0x00, 0x07, 0x07, 0x00, 0x00, 0x00,  // '  0x27
0x00, 0x3C, 0x7E, 0xC3, 0x81, 0x81, 0x00, 0x00,  // (  0x28
0x00, 0x81, 0x81, 0xC3, 0x7E, 0x3C, 0x00, 0x00,  // )  0x29
0x08, 0x2A, 0x1C, 0x7F, 0x1C, 0x2A, 0x08, 0x00,  // *  0x2A
0x00, 0x18, 0x18, 0x7E, 0x7E, 0x18, 0x18, 0x00,  // +  0x2B
0x00, 0x00, 0x80, 0xE0, 0x60, 0x00, 0x00, 0x00,  // ,  0x2C
0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00,  // -  0x2D
0x00, 0x00, 0x00, 0x60, 0x60, 0x00, 0x00, 0x00,  // .  0x2E
0x00, 0x00, 0xC0, 0xF0, 0x3C, 0x0F, 0x03, 0x00,  // /  0x2F

	
 62, 127, 113,  89,  77, 127,  62,   0,  // 0     48   0x30
 64,  66, 127, 127,  64,  64,   0,   0,  // 1          0x31
 98, 115,  89,  73, 111, 102,   0,   0,  // 2          0x32
 34,  99,  73,  73, 127,  54,   0,   0,  // 3          0x33
 24,  28,  22,  83, 127, 127,  80,   0,  // 4          0x34
 39, 103,  69,  69, 125,  57,   0,   0,  // 5          0x35
 60, 126,  75,  73, 121,  48,   0,   0,  // 6          0x36
  3,   3, 113, 121,  15,   7,   0,   0,  // 7          0x37
 54, 127,  73,  73, 127,  54,   0,   0,  // 8          0x38
  6,  79,  73, 105,  63,  30,   0,   0,  // 9          0x39
                                                         

0x00, 0x00, 0x00, 0x66, 0x66, 0x00, 0x00, 0x00,  // :     58   0x3A
0x00, 0x00, 0x80, 0x66, 0x66, 0x00, 0x00, 0x00,  // ;          0x3B
0x00, 0x00, 0x08, 0x14, 0x22, 0x41, 0x00, 0x00,  // <          0x3C
0x00, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x00,  // =          0x3D
0x00, 0x00, 0x41, 0x22, 0x14, 0x08, 0x00, 0x00,  // >          0x3E
0x00, 0x02, 0x03, 0x69, 0x6D, 0x07, 0x02, 0x00,  // ?          0x3F
   0,    0,    0,    0,    0,    0,    0,    0,  // @          0x40


124, 126,  19,  19, 126, 124,   0,   0,  // A     65   0x41 
 65, 127, 127,  73,  73, 127,  54,   0,  // B          0x42
 28,  62,  99,  65,  65,  99,  34,   0,  // C          0x43
 65, 127, 127,  65,  99,  62,  28,   0,  // D          0x44
 65, 127, 127,  73,  93,  65,  99,   0,  // E          0x45
 65, 127, 127,  73,  29,   1,   3,   0,  // F          0x46
 28,  62,  99,  65,  81, 115, 114,   0,  // G          0x47
127, 127,   8,   8, 127, 127,   0,   0,  // H          0x48
  0,  65, 127, 127,  65,   0,   0,   0,  // I          0x49
 48, 112,  64,  65, 127,  63,   1,   0,  // J          0x4A
 65, 127, 127,   8,  28, 119,  99,   0,  // K          0x4B
 65, 127, 127,  65,  64,  96, 112,   0,  // L          0x4C
127, 127,  14,  28,  14, 127, 127,   0,  // M          0x4D
127, 127,   6,  12,  24, 127, 127,   0,  // N          0x4E
 28,  62,  99,  65,  99,  62,  28,   0,  // O          0x4F
 65, 127, 127,  73,   9,  15,   6,   0,  // P          0x50
 30,  63,  33, 113, 127,  94,   0,   0,  // Q          0x51
 65, 127, 127,   9,  25, 127, 102,   0,  // R          0x52
 38, 111,  77,  89, 115,  50,   0,   0,  // S          0x53
  3,  65, 127, 127,  65,   3,   0,   0,  // T          0x54
 63, 127,  96,  96, 127,  63,   0,   0,  // U          0x55
 31,  63,  96,  96,  63,  31,   0,   0,  // V          0x56
127, 127,  48,  24,  48, 127, 127,   0,  // W          0x57
 99, 103,  60,  24,  60, 103,  99,   0,  // X          0x58
  7,  79, 120, 120,  79,   7,   0,   0,  // Y          0x59
 71,  99, 113,  89,  77, 103, 115,   0,  // Z          0x5A
                                                         
  0,   0,   0,   0,   0,   0,   0,   0,  // [     91   0x5B
  0,   0,   0,   0,   0,   0,   0,   0,  // BackSlash  0x5C
  0,   0,   0,   0,   0,   0,   0,   0,  // ]          0x5D
  0,   0,   0,   0,   0,   0,   0,   0,  // ^          0x5E
  0,   0,   0,   0,   0,   0,   0,   0,  // _          0x5F
  0,   0,   0,   0,   0,   0,   0,   0,  // `          0x60

 32, 116,  84,  84,  60, 120,  64,   0,  // a     97   0x61
 65, 127,  63,  72,  72, 120,  48,   0,  // b          0x62
 56, 124,  68,  68, 108,  40,   0,   0,  // c          0x63
 48, 120,  72,  73,  63, 127,  64,   0,  // d          0x64
 56, 124,  84,  84,  92,  24,   0,   0,  // e          0x65
 72, 126, 127,  73,   3,   2,   0,   0,  // f          0x66
 76,  94,  82,  82, 124,  62,   2,   0,  // g          0x67
 65, 127, 127,   8,   4, 124, 120,   0,  // h          0x68
  0,  68, 125, 125,  64,   0,   0,   0,  // i          0x69
 48, 112,  64,  64, 125,  61,   0,   0,  // j          0x6A
 65, 127, 127,  16,  56, 108,  68,   0,  // k          0x6B
  0,  65, 127, 127,  64,   0,   0,   0,  // l          0x6C
124, 124,  24,  56,  28, 124, 120,   0,  // m          0x6D
124, 124,   4,   4, 124, 120,   0,   0,  // n          0x6E
 56, 124,  68,  68, 124,  56,   0,   0,  // o          0x6F
 68, 120, 124,  84,  20,  28,   8,   0,  // p          0x70
  8,  28,  20,  84, 120, 124,  64,   0,  // q          0x71
 68, 124, 120,  76,   4,  28,  24,   0,  // r          0x72
 72,  92,  84,  84, 116,  36,   0,   0,  // s          0x73
  0,   4,  62, 127,  68,  36,   0,   0,  // t          0x74
 60, 124,  64,  64,  60, 124,  64,   0,  // u          0x75
 28,  60,  96,  96,  60,  28,   0,   0,  // v          0x76
 60, 124, 112,  56, 112, 124,  60,   0,  // w          0x77
 68, 108,  56,  16,  56, 108,  68,   0,  // x          0x78
 76,  92,  80,  80, 124,  60,   0,   0,  // y          0x79
 76, 100, 116,  92,  76, 100,   0,   0,  // z          0x7A
                                                         
  0,   0,   0,   0,   0,   0,   0,   0,  // {     123  0x7B
  0,   0,   0,   0,   0,   0,   0,   0,  // |          0x7C
  0,   0,   0,   0,   0,   0,   0,   0,  // }          0x7D
  0,   0,   0,   0,   0,   0,   0,   0,  // ~          0x7E
  0,   0,   0,   0,   0,   0,   0,   0,  //            0x7F
  0,   0,   0,   0,   0,   0,   0,   0,  // �          0x80
  0,   0,   0,   0,   0,   0,   0,   0,  //            0x81
  0,   0,   0,   0,   0,   0,   0,   0,  // �          0x82
  0,   0,   0,   0,   0,   0,   0,   0,  // ?          0x83
  0,   0,   0,   0,   0,   0,   0,   0,  // �          0x84
  0,   0,   0,   0,   0,   0,   0,   0,  // �          0x85
  0,   0,   0,   0,   0,   0,   0,   0,  // �          0x86
  0,   0,   0,   0,   0,   0,   0,   0,  // �          0x87
  0,   0,   0,   0,   0,   0,   0,   0,  // ?          0x88
  0,   0,   0,   0,   0,   0,   0,   0,  // �          0x89
  0,   0,   0,   0,   0,   0,   0,   0,  // S          0x8A
  0,   0,   0,   0,   0,   0,   0,   0,  // �          0x8B
  0,   0,   0,   0,   0,   0,   0,   0,  // ?          0x8C
  0,   0,   0,   0,   0,   0,   0,   0,  //            0x8D
  0,   0,   0,   0,   0,   0,   0,   0,  // Z          0x8E
  0,   0,   0,   0,   0,   0,   0,   0,  //            0x8F
  0,   0,   0,   0,   0,   0,   0,   0,  //            0x90
  0,   0,   0,   0,   0,   0,   0,   0,  // �          0x91
  0,   0,   0,   0,   0,   0,   0,   0,  // �          0x92
  0,   0,   0,   0,   0,   0,   0,   0,  // �          0x93
  0,   0,   0,   0,   0,   0,   0,   0,  // �          0x94 
  0,   0,   0,   0,   0,   0,   0,   0,  // �    149   0x95
  0,   0,   0,   0,   0,   0,   0,   0,  // �          0x96
  0,   0,   0,   0,   0,   0,   0,   0,  // �          0x97
  0,   0,   0,   0,   0,   0,   0,   0,  //            0x98
  0,   0,   0,   0,   0,   0,   0,   0,  // �          0x99
  0,   0,   0,   0,   0,   0,   0,   0,  // s          0x9A
  0,   0,   0,   0,   0,   0,   0,   0,  // �          0x9B
  0,   0,   0,   0,   0,   0,   0,   0,  // ?          0x9C
  0,   0,   0,   0,   0,   0,   0,   0,  //            0x9D
  0,   0,   0,   0,   0,   0,   0,   0,  // z          0x9E
  0,   0,   0,   0,   0,   0,   0,   0,  // Y          0x9F
  0,   0,   0,   0,   0,   0,   0,   0,  // �          0xA0
  0,   0,   0,   0,   0,   0,   0,   0,  // ?          0xA1
  0,   0,   0,   0,   0,   0,   0,   0,  // ?          0xA2
  0,   0,   0,   0,   0,   0,   0,   0,  // ?          0xA3
  0,   0,   0,   0,   0,   0,   0,   0,  // �          0xA4
  0,   0,   0,   0,   0,   0,   0,   0,  // ?          0xA5
  0,   0,   0,   0,   0,   0,   0,   0,  // �          0xA6
  0,   0,   0,   0,   0,   0,   0,   0,  // �          0xA7
  0,   0,   0,   0,   0,   0,   0,   0,  // ?          0xA8
  0,   0,   0,   0,   0,   0,   0,   0,  // �          0xA9
  0,   0,   0,   0,   0,   0,   0,   0,  // ?          0xAA
  0,   0,   0,   0,   0,   0,   0,   0,  // �          0xAB
  0,   0,   0,   0,   0,   0,   0,   0,  // �          0xAC
  0,   0,   0,   0,   0,   0,   0,   0,  // �          0xAD
  0,   0,   0,   0,   0,   0,   0,   0,  // �          0xAE
  0,   0,   0,   0,   0,   0,   0,   0,  // ?          0xAF
0x00, 0x00, 0x06, 0x09, 0x09, 0x06, 0x00, 0x00,  // �  0xB0
  0,   0,   0,   0,   0,   0,   0,   0,  // �          0xB1
  0,   0,   0,   0,   0,   0,   0,   0,  // ?          0xB2
  0,   0,   0,   0,   0,   0,   0,   0,  // ?          0xB3
  0,   0,   0,   0,   0,   0,   0,   0,  // ?          0xB4
  0,   0,   0,   0,   0,   0,   0,   0,  // �          0xB5
  0,   0,   0,   0,   0,   0,   0,   0,  // �          0xB6
  0,   0,   0,   0,   0,   0,   0,   0,  // �          0xB7
  0,   0,   0,   0,   0,   0,   0,   0,  // ?          0xB8
  0,   0,   0,   0,   0,   0,   0,   0,  // ?          0xB9
  0,   0,   0,   0,   0,   0,   0,   0,  // ?          0xBA
  0,   0,   0,   0,   0,   0,   0,   0,  // �          0xBB
  0,   0,   0,   0,   0,   0,   0,   0,  // ?          0xBC
  0,   0,   0,   0,   0,   0,   0,   0,  // ?          0xBD
  0,   0,   0,   0,   0,   0,   0,   0,  //            0xBE 
  0,   0,   0,   0,   0,   0,   0,   0,  //            0xBF 

124, 126,  19,  19, 126, 124,   0,   0,  // �    192   0xC0
 65, 127, 127,  73,  73, 121,  51,   0,  // �          0xC1
 65, 127, 127,  73,  73, 127,  54,   0,  // �          0xC2
 65, 127, 127,  65,   1,   3,   3,   0,  // �          0xC3
120, 126,  55,  51,  55, 126, 120,   0,  // �          0xC4
 65, 127, 127,  73,  93,  65,  99,   0,  // �          0xC5
 99,  20, 127, 127,  20,  99,   0,   0,  // �          0xC6
 99,  99,  73,  73, 107, 127,  54,   0,  // �          0xC7
127, 127,  48,  24,  12, 127, 127,   0,  // �          0xC8
127, 127,  48,  27,  12, 127, 127,   0,  // �          0xC9
 65, 127, 127,   8,  28, 119,  99,   0,  // �          0xCA
 96, 127,  31,   3, 127, 127,  65,   0,  // �          0xCB
127, 127,  14,  28,  14, 127, 127,   0,  // �          0xCC
127, 127,   8,   8, 127, 127,   0,   0,  // �          0xCD
 28,  62,  99,  65,  99,  62,  28,   0,  // �          0xCE
127, 127,   3,   3, 127, 127,   0,   0,  // �          0xCF
 65, 127, 127,  73,   9,  15,   6,   0,  // �          0xD0
 28,  62,  99,  65,  65,  99,  34,   0,  // �          0xD1
  3,  65, 127, 127,  65,   3,   0,   0,  // �          0xD2
 99, 103,  60,  24,  12,   7,   3,   0,  // �          0xD3
 30,  82, 127, 127,  82,  30,   0,   0,  // �          0xD4
 99, 103,  60,  24,  60, 103,  99,   0,  // �          0xD5
 63,  63,  32,  32,  63,  63,  96,   0,  // �          0xD6
 15,  31,  24,  88, 127, 127,  64,   0,  // �          0xD7
127, 127,  96, 127,  96, 127, 127,   0,  // �          0xD8
 63,  32,  63,  63,  32,  63,  96,   0,  // �          0xD9
  1, 127, 127,  72,  72, 120,  48,   0,  // �          0xDA
127, 127,  72,  72, 120,   0, 127,   0,  // �          0xDB
127, 127,  72,  72, 120,  48,   0,	 0,  // �          0xDC
 54,  99,  73,  73, 107, 127,  62,   0,  // �          0xDD
127,   8,  62,  99,  65,  99,  62,   0,  // �          0xDE
102, 127,  25,   9, 127, 127,  65,   0,  // �          0xDF
                                                       
 32, 116,  84,  84,  60, 120,  64,   0,  // �    224   0xE0
 48, 124,  74,  74, 122,  49,   0,   0,  // �          0xE1
 68, 124, 124,  84,  84,  40,   0,   0,  // �          0xE2
 68, 124, 124,  68,  12,   8,   0,   0,  // �          0xE3
 96,  56,  52,  52,  56,  96,   0,   0,  // �          0xE4
 56, 124,  84,  84,  92,  24,   0,   0,  // �          0xE5
 68,  40, 124, 124,  40,  68,   0,   0,  // �          0xE6
 46,  68,  84,  84, 124,  40,   0,   0,  // �          0xE7
124, 124,  32,  16, 124, 124,   0,   0,  // �          0xE8
124, 124,  33,  17, 124, 124,   0,   0,  // �          0xE9
 68, 124, 124,  16,  56, 108,  68,   0,  // �          0xEA
 64, 120,  12,   4, 124, 124,  64,   0,  // �          0xEB
120, 124,   8,  16,   8, 124, 120,   0,  // �          0xEC
124, 124,  16,  16, 124, 124,   0,   0,  // �          0xED
 56, 124,  68,  68, 124,  56,   0,   0,  // �          0xEE
124, 124,   4,   4, 124, 124,   0,   0,  // �          0xEF
 68, 120, 124,  84,  20,  28,   8,   0,  // �          0xF0
 56, 124,  68,  68, 108,  40,   0,   0,  // �          0xF1
  8,  68, 124, 124,  68,   8,   0,   0,  // �          0xF2
 76,  92,  80,  80, 124,  60,   0,   0,  // �          0xF3
  8,  84, 124, 124,  84,   8,   0,   0,  // �          0xF4
 68, 108,  56,  16,  56, 108,  68,   0,  // �          0xF5
 60,  60,  32,  60,  60,  96,   0,   0,  // �          0xF6
 28,  16,  80, 124, 124,  64,   0,   0,  // �          0xF7
124,  64, 124,  64, 124,   0,   0,   0,  // �          0xF8
 60,  32,  60,  32,  60,  96,   0,   0,  // �          0xF9
 68,  60,  80,  80, 112,  32,   0,   0,  // �          0xFA
 64,  60,  80,  80,  32,   0, 124,   0,  // �          0xFB
 64,  60,  80,  80,  80,  32,   0,   0,  // �          0xFC
 40,  68,  84,  84,  56,   0,   0,   0,  // �          0xFD
124,  16,  56,  68,  68,  56,   0,   0,  // �          0xFE
 64,  40,  20,  20, 124, 124,   0,   0   // �    255   0xFF
};

//static const uint8_t cursor[8]= {  8,  28,  62, 127,  28,  28,  28,  28};
       
// 68, 124, 125,  84,  84,  69, 108,   0,  // �
// 56, 125,  84,  84,  93,  24,   0,   0,  // �  
       
#endif 

