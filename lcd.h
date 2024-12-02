
#ifndef LCD_H_
#define LCD_H_

#include "xparameters.h"
#include "xil_io.h"
#include "xil_types.h"
#include "xspi_l.h"
#include "xil_printf.h"

#define SPI_DC          XPAR_SPI_DC_BASEADDR
#define B_RS            0x00000001

#define SPI_DTR         XPAR_SPI_BASEADDR + XSP_DTR_OFFSET
#define SPI_DRR         XPAR_SPI_BASEADDR + XSP_DRR_OFFSET
#define SPI_IISR        XPAR_SPI_BASEADDR + XSP_IISR_OFFSET
#define SPI_SR          XPAR_SPI_BASEADDR + XSP_SR_OFFSET

#define cbi(reg, bitmask)       Xil_Out32(reg, Xil_In32(reg) & ~(u32)bitmask)
#define sbi(reg, bitmask)       Xil_Out32(reg, Xil_In32(reg) |= (u32)bitmask)
#define swap(type, i, j)        {type t = i; i = j; j = t;}

#define DISP_X_SIZE     239
#define DISP_Y_SIZE     319

struct _current_font
{
    u8* font;
    u8 x_size;
    u8 y_size;
    u8 offset;
    u8 numchars;
};

extern int fch; // Foreground color upper byte
extern int fcl; // Foreground color lower byte
extern int bch; // Background color upper byte
extern int bcl; // Background color lower byte

extern struct _current_font cfont;
extern u8 SmallFont[];
extern u8 BigFont[];
extern u8 SevenSegNumFont[];

u32 LCD_Read(char VL);
void LCD_Write_COM(char VL);  
void LCD_Write_DATA(char VL);
void LCD_Write_DATA16(char VH, char VL);
//void LCD_Write_DATA_(char VH, char VL);

void initLCD(void);
void setXY(int x1, int y1, int x2, int y2);
void setColor(u8 r, u8 g, u8 b);
void setColorBg(u8 r, u8 g, u8 b);
void clrXY(void);
void clrScr(void);

void drawHLine(int x, int y, int l);
void fillRect(int x1, int y1, int x2, int y2);

void setFont(u8* font);
void printChar(u8 c, int x, int y);
void lcdPrint(char *st, int x, int y);

#endif /* LCD_H_ */
