#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED

#define SCREEN_WIDTH 120
#define SCREEN_HEIGHT 71

#define APP_BACKCOLOR 8
#define APP_FORECOLOR 15
#define APP_TITLEBACKCOLOR 1
#define APP_TITLEFORECOLOR 15
#define APP_ERRORCOLOR 4
#define APP_OKCOLOR 2
#define APP_DELAY 1000

void msj1(const char *mensaje,int forecolor,int backcolor,int y);
void setColors(int foreColor = APP_FORECOLOR, int backColor = APP_BACKCOLOR);
void bar(int foreColor, int backColor, int y=SCREEN_HEIGHT, int width=SCREEN_WIDTH);
void title(const char *mensaje, int foreColor = APP_TITLEFORECOLOR, int backColor = APP_TITLEBACKCOLOR);
void msj(const char *mensaje, int foreColor = APP_FORECOLOR, int backColor = APP_BACKCOLOR, int y = SCREEN_HEIGHT);
void delline(int line, int foreColor = APP_FORECOLOR, int backColor = APP_BACKCOLOR);
#endif // UI_H_INCLUDED
