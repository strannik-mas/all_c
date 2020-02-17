#include"console_ctrl.h" 
#include"conio.h"

#define UP_ARROW	0x4800
#define DOWN_ARROW	0x5000
#define ENTER		0x0D
#define ESC			0x1B

int menu_drv(const wchar_t **options, int n, int sel_attr, int unsel_attr)

{
	int i, x=10, y=10, cur_sell=0, code;

	CursorVisible(FALSE);

	for(i=0; i<n; ++i)
		RTextXY(x,y+i,options[i],unsel_attr);

	RTextXY(x,y+cur_sell,options[cur_sell],sel_attr);
	do
	{
		code = _getch(); //ввод символа с консоли
		if(code==0 || code==0xE0) code = _getch()<<8; //управляющая клавиша
		RTextXY(x,y+cur_sell,options[cur_sell],unsel_attr); 
		switch(code)
		{
		case UP_ARROW:	if(--cur_sell < 0) cur_sell = n-1;
						break;
		case DOWN_ARROW:	if(++cur_sell >= n) cur_sell = 0;
							break;
		}
		RTextXY(x,y+cur_sell,options[cur_sell],sel_attr); 
	}while(code != ENTER && code != ESC);
	gotoxy(0, y+n+1); 
	CursorVisible(TRUE);
	return code == ENTER ? cur_sell : -1;

}
int main()
{
	wchar_t *options[]={L" Файл		",
						L" Правка	",
						L" Вид		",
						L" Вставка	",
						L" Справка	"};
	int r;

	setlocale(LC_CTYPE,".866");

	r = menu_drv(options,sizeof options / sizeof *options, 
		BACKGROUND(CYAN)|WHITE, BACKGROUND(WHITE)|BLACK); 
	textattr(0x07);
	printf("return value %d\n", r);
	return 0;
}