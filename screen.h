#define UNICODE 
//function declartion
enum COLORS{BLACK=30,RED,GREEN,YELLOW,BLUE,MAGENTA,CYAN,WHITE};
#define bg(c) (c+10)
#define COL 80
#define BAR "\u2590"
void clearScreen(void);
void setColors(short ,short);
void resetColors(void);
void barChart(int []);
