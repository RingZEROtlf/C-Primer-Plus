// hotel.h -- character constants and all function prototypes in List_9_10_hotel.c
#define QUIT        5
#define HOTEL1      180.00
#define HOTEL2      225.00
#define HOTEL3      255.00
#define HOTEL4      355.00
#define DISCOUNT    0.95
#define STARS       "****************************************"
// output menu list
int menu(void);
// return days ordered
int getnights(void);
// calculate fare according to fare rate and days lived
// and output result
void showprice(double rate, int nights);