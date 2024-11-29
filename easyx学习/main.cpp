#include <stdio.h>
#include <graphics.h>

MOUSEMSG shubiao;

//定义魔方
int r[9] = { 1,1,1,1,1,1,1,1,1 };
int u[9] = { 2,2,2,2,2,2,2,2,2 };
int f[9] = { 3,3,3,3,3,3,3,3,3 };
int l[9] = { 4,4,4,4,4,4,4,4,4 };
int d[9] = { 5,5,5,5,5,5,5,5,5 };
int b[9] = { 6,6,6,6,6,6,6,6,6 };
int k[3] = { -1,-1,-1 };//缓冲

//定义储存魔方
int rr[9] = { 1,1,1,1,1,1,1,1,1 };
int uu[9] = { 2,2,2,2,2,2,2,2,2 };
int ff[9] = { 3,3,3,3,3,3,3,3,3 };
int ll[9] = { 4,4,4,4,4,4,4,4,4 };
int dd[9] = { 5,5,5,5,5,5,5,5,5 };
int bb[9] = { 6,6,6,6,6,6,6,6,6 };

//旋转魔方一个面
void hhh(int x[]) {
	int y[9] = { 0 };
	for (int i = 0;i < 9;i++) {
		y[i] = x[i];
	}
	x[0] = y[6];
	x[1] = y[3];
	x[2] = y[0];
	x[3] = y[7];
	x[5] = y[1];
	x[6] = y[8];
	x[7] = y[5];
	x[8] = y[2];
	return;
}

//公式R
void R() {
	hhh(r);
	k[0] = f[2];
	k[1] = f[5];
	k[2] = f[8];

	f[2] = d[2];
	f[5] = d[5];
	f[8] = d[8];

	d[2] = b[6];
	d[5] = b[3];
	d[8] = b[0];

	b[6] = u[2];
	b[3] = u[5];
	b[0] = u[8];

	u[2] = k[0];
	u[5] = k[1];
	u[8] = k[2];
}

void R2() {
	R();
	R();
}

void R3() {
	R();
	R();
	R();
}

//公式U
void U() {
	hhh(u);
	k[0] = f[0];
	k[1] = f[1];
	k[2] = f[2];

	f[0] = r[0];
	f[1] = r[1];
	f[2] = r[2];

	r[0] = b[0];
	r[1] = b[1];
	r[2] = b[2];

	b[0] = l[0];
	b[1] = l[1];
	b[2] = l[2];

	l[0] = k[0];
	l[1] = k[1];
	l[2] = k[2];
}

void U2() {
	U();
	U();
}

void U3() {
	U();
	U();
	U();
}

//公式F
void F() {
	hhh(f);
	k[0] = u[6];
	k[1] = u[7];
	k[2] = u[8];

	u[6] = l[8];
	u[7] = l[5];
	u[8] = l[2];

	l[8] = d[2];
	l[5] = d[1];
	l[2] = d[0];

	d[2] = r[0];
	d[1] = r[3];
	d[0] = r[6];

	r[0] = k[0];
	r[3] = k[1];
	r[6] = k[2];
}

void F2() {
	F();
	F();
}

void F3() {
	F();
	F();
	F();
}

//公式L
void L() {
	hhh(l);
	k[0] = f[0];
	k[1] = f[3];
	k[2] = f[6];

	f[0] = u[0];
	f[3] = u[3];
	f[6] = u[6];

	u[0] = b[8];
	u[3] = b[5];
	u[6] = b[2];

	b[8] = d[0];
	b[5] = d[3];
	b[2] = d[6];

	d[0] = k[0];
	d[3] = k[1];
	d[6] = k[2];
}

void L2() {
	L();
	L();
}

void L3() {
	L();
	L();
	L();
}

//公式D
void D() {
	hhh(d);
	k[0] = f[6];
	k[1] = f[7];
	k[2] = f[8];

	f[6] = l[6];
	f[7] = l[7];
	f[8] = l[8];

	l[6] = b[6];
	l[7] = b[7];
	l[8] = b[8];

	b[6] = r[6];
	b[7] = r[7];
	b[8] = r[8];

	r[6] = k[0];
	r[7] = k[1];
	r[8] = k[2];
}

void D2() {
	D();
	D();
}

void D3() {
	D();
	D();
	D();
}

//公式B
void B() {
	hhh(b);
	k[0] = u[0];
	k[1] = u[1];
	k[2] = u[2];

	u[0] = r[2];
	u[1] = r[5];
	u[2] = r[8];

	r[2] = d[8];
	r[5] = d[7];
	r[8] = d[6];

	d[8] = l[6];
	d[7] = l[3];
	d[6] = l[0];

	l[6] = k[0];
	l[3] = k[1];
	l[0] = k[2];
}

void B2() {
	B();
	B();
}

void B3() {
	B();
	B();
	B();
}

//公式x
void x() {
	R();
	L3();
	k[0] = f[1];
	k[1] = f[4];
	k[2] = f[7];

	f[1] = d[1];
	f[4] = d[4];
	f[7] = d[7];

	d[1] = b[7];
	d[4] = b[4];
	d[7] = b[1];

	b[7] = u[1];
	b[4] = u[4];
	b[1] = u[7];

	u[1] = k[0];
	u[4] = k[1];
	u[7] = k[2];
}

void x2() {
	x();
	x();
}

void x3() {
	x();
	x();
	x();
}

//公式y
void y() {
	U();
	D3();
	k[0] = f[3];
	k[1] = f[4];
	k[2] = f[5];

	f[3] = r[3];
	f[4] = r[4];
	f[5] = r[5];

	r[3] = b[3];
	r[4] = b[4];
	r[5] = b[5];

	b[3] = l[3];
	b[4] = l[4];
	b[5] = l[5];

	l[3] = k[0];
	l[4] = k[1];
	l[5] = k[2];
}

void y2(){
	y();
	y();
}

void y3() {
	y();
	y();
	y();
}

//公式z
void z() {
	F();
	B3();
	k[0] = u[3];
	k[1] = u[4];
	k[2] = u[5];

	u[3] = l[7];
	u[4] = l[4];
	u[5] = l[1];

	l[7] = d[5];
	l[4] = d[4];
	l[1] = d[3];

	d[5] = r[1];
	d[4] = r[4];
	d[3] = r[7];

	r[1] = k[0];
	r[4] = k[1];
	r[7] = k[2];
}

void z2() {
	z();
	z();
}

void z3() {
	z();
	z();
	z();
}

//绘图魔方正面
void huahua(int x,int y,int z[]) {
	int dx[8] = {143,143,-286,143,143,-286,143,143};
	int dy[8] = {0,0,143,0,0,143,0,0};
	for (int i = 0;i < 9;i++) {
		if (z[i] == 1) {
			setfillcolor(RED);
		}
		else if (z[i] == 2) {
			setfillcolor(WHITE);
		}
		else if (z[i] == 3) {
			setfillcolor(GREEN);
		}
		else if (z[i] == 4) {
			setfillcolor(RGB(245, 110, 12));
		}
		else if (z[i] == 5) {
			setfillcolor(YELLOW);
		}
		else if (z[i] == 6) {
			setfillcolor(BLUE);
		}
		else if (z[i] == -1) {
			setfillcolor(BLACK);
		}
		setlinestyle(PS_SOLID, 5);
		fillrectangle(x, y,x+143,y+143);
		x += dx[i];
		y += dy[i];
	}
}

//绘图魔方上面
void huahua1(int x,int y,int z[]) {
	int dx[8] = { 143,143,-337,143,143,-337,143,143 };
	int dy[8] = { 0,0,51,0,0,51,0,0 };
	for (int i = 0;i < 9;i++) {
		if (z[i] == 1) {
			setfillcolor(RED);
		}
		else if (z[i] == 2) {
			setfillcolor(WHITE);
		}
		else if (z[i] == 3) {
			setfillcolor(GREEN);
		}
		else if (z[i] == 4) {
			setfillcolor(RGB(245, 110, 12));
		}
		else if (z[i] == 5) {
			setfillcolor(YELLOW);
		}
		else if (z[i] == 6) {
			setfillcolor(BLUE);
		}
		else if (z[i] == -1) {
			setfillcolor(BLACK);
		}
		setlinestyle(PS_SOLID, 5);
		POINT pts[] = { {x, y}, {x + 143, y}, {x+92,y+51},{x - 51, y + 51}};
		fillpolygon(pts, 4);
		x += dx[i];
		y += dy[i];
	}
}

//绘图魔方侧面
void huahua2(int x, int y, int z[]) {
	int dx[8] = { 51,51,-102,51,51,-102,51,51 };
	int dy[8] = { -51,-51,245,-51,-51,245,-51,-51 };
	for (int i = 0;i < 9;i++) {
		if (z[i] == 1) {
			setfillcolor(RED);
		}
		else if (z[i] == 2) {
			setfillcolor(WHITE);
		}
		else if (z[i] == 3) {
			setfillcolor(GREEN);
		}
		else if (z[i] == 4) {
			setfillcolor(RGB(245,110,12));
		}
		else if (z[i] == 5) {
			setfillcolor(YELLOW);
		}
		else if (z[i] == 6) {
			setfillcolor(BLUE);
		}
		else if (z[i] == -1) {
			setfillcolor(BLACK);
		}
		setlinestyle(PS_SOLID, 5);
		POINT pts[] = { {x, y}, {x + 51, y-51}, {x + 51,y + 92},{x, y + 143} };
		fillpolygon(pts, 4);
		x += dx[i];
		y += dy[i];
	}
}


//绘图主界面
void hua666() {
	setfillcolor(WHITE);
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	settextstyle(100, 0, _T("Consolas"));
	setlinestyle(PS_SOLID, 5);
	char c[2][20] = { "自由模式","引导还原模式" };
	if (200 < shubiao.x && shubiao.x < 200+1040 && 100 < shubiao.y && shubiao.y < 100+240) {
		setfillcolor(RGB(195, 195, 195));
		if (shubiao.uMsg == WM_LBUTTONDOWN) {
			setlinecolor(RGB(195, 195, 195));
			setfillcolor(RGB(110, 110, 110));
		}
	}
	fillrectangle(200, 100, 200 + 1040, 100 + 240);
	outtextxy(200 + (1040 - textwidth(c[0])) / 2, 100 + (240 - textheight(c[0])) / 2, c[0]);
	setfillcolor(WHITE);
	setlinecolor(WHITE);
	if (200 < shubiao.x && shubiao.x < 200 + 1040 && 440 < shubiao.y && shubiao.y < 440 + 240) {
		setfillcolor(RGB(195, 195, 195));
		if (shubiao.uMsg == WM_LBUTTONDOWN) {
			setlinecolor(RGB(195, 195, 195));
			setfillcolor(RGB(110, 110, 110));
		}
	}
	fillrectangle(200, 440, 200 + 1040, 440 + 240);
	outtextxy(200 + (1040 - textwidth(c[1])) / 2, 440 + (240 - textheight(c[0])) / 2, c[1]);
	setfillcolor(WHITE);
	setlinecolor(WHITE);
}

//绘图按钮
void huahuahua() {
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	settextstyle(50,0, _T("Consolas"));
	setfillcolor(WHITE);
	setlinestyle(PS_SOLID, 5);
	int x = 850, y = 41;
	int dx[2] = { 180,-540 };
	int dy[2] = { 0,72 };
	char c[30][20] = 
	{"R","R'","R2",
		"U","U'","U2",
		"F","F'","F2",
		"L","L'","L2",
		"D","D'","D2",
		"B","B'","B2",
	    "x","x'","x2",
		"y","y'","y2", 
		"z","z'","z2",
	    "重置魔方","一键打乱","撤销一步"};
	int k = 0;
	for (int i = 0;i < 9;i++) {
		for (int j = 0;j < 3;j++,k++) {
			if (x < shubiao.x && shubiao.x < x + 100 && y < shubiao.y && shubiao.y < y + 50) {
				setfillcolor(RGB(195, 195, 195));
				if (shubiao.uMsg == WM_LBUTTONDOWN) {
					setlinecolor(RGB(195, 195, 195));
					setfillcolor(RGB(110, 110, 110));
				}
			}
			fillrectangle(x, y, x + 100, y + 50);
			setfillcolor(WHITE);
			setlinecolor(WHITE);
			outtextxy(x+(100-textwidth(c[k])) / 2, y, c[k]);
			x += dx[0];
			y += dy[0];
		}
		x += dx[1];
		y += dy[1];
	}
	settextstyle(25, 0, _T("Consolas"));
	if (x < shubiao.x && shubiao.x < x + 100 && y < shubiao.y && shubiao.y < y + 50) {
		setfillcolor(RGB(195, 195, 195));
		if (shubiao.uMsg == WM_LBUTTONDOWN) {
			setlinecolor(RGB(195, 195, 195));
			setfillcolor(RGB(110, 110, 110));
		}
	}
	fillrectangle(x, y, x + 100, y + 50);
	setfillcolor(WHITE);
	setlinecolor(WHITE);
	outtextxy(x + (100 - textwidth(c[k])) / 2, y+(50-textheight(c[k]))/2, c[k]);
	k++;
	x += dx[0];
	y += dy[0];
	if (x < shubiao.x && shubiao.x < x + 100 && y < shubiao.y && shubiao.y < y + 50) {
		setfillcolor(RGB(195, 195, 195));
		if (shubiao.uMsg == WM_LBUTTONDOWN) {
			setlinecolor(RGB(195, 195, 195));
			setfillcolor(RGB(110, 110, 110));
		}
	}
	fillrectangle(x, y, x + 100, y + 50);
	setfillcolor(WHITE);
	setlinecolor(WHITE);
	outtextxy(x + (100 - textwidth(c[k])) / 2, y + (50 - textheight(c[k])) / 2, c[k]);
	k++;
	x += dx[0];
	y += dy[0];
	if (x < shubiao.x && shubiao.x < x + 100 && y < shubiao.y && shubiao.y < y + 50) {
		setfillcolor(RGB(195, 195, 195));
		if (shubiao.uMsg == WM_LBUTTONDOWN) {
			setlinecolor(RGB(195, 195, 195));
			setfillcolor(RGB(110, 110, 110));
		}
	}
	fillrectangle(x, y, x + 100, y + 50);
	setfillcolor(WHITE);
	setlinecolor(WHITE);
	outtextxy(x + (100 - textwidth(c[k])) / 2, y + (50 - textheight(c[k])) / 2, c[k]);
}

//判断是否还原
int panduanhuanyuan() {
	int k = 1;
	if (!(r[0] == r[1] && r[1] == r[2] && r[2] == r[3] && r[3] == r[4] && r[4] == r[5] && r[5] == r[0])) k = 0;
	if (!(u[0] == u[1] && u[1] == u[2] && u[2] == u[3] && u[3] == u[4] && u[4] == u[5] && u[5] == u[0])) k = 0;
	if (!(f[0] == f[1] && f[1] == f[2] && f[2] == f[3] && f[3] == f[4] && f[4] == f[5] && f[5] == f[0])) k = 0;
	if (!(l[0] == l[1] && l[1] == l[2] && l[2] == l[3] && l[3] == l[4] && l[4] == l[5] && l[5] == l[0])) k = 0;
	if (!(d[0] == d[1] && d[1] == d[2] && d[2] == d[3] && d[3] == d[4] && d[4] == d[5] && d[5] == d[0])) k = 0;
	if (!(b[0] == b[1] && b[1] == b[2] && b[2] == b[3] && b[3] == b[4] && b[4] == b[5] && b[5] == b[0])) k = 0;
	return k;
}

//偷梁换柱大法
void huanzhu() {
	for (int i = 0;i < 9;i++) {
		rr[i] = r[i];
		uu[i] = u[i];
		ff[i] = f[i];
		ll[i] = l[i];
		dd[i] = d[i];
		bb[i] = b[i];
	}
}

//当然是主函数啦
int main() {
	int k = 0,huanyuan=0,daluan=0,yibu=0,woc=0;
	initgraph(1440, 780);
	BeginBatchDraw();
	for (;;) {
		shubiao = GetMouseMsg();
		//判断是否还原
		if (daluan != 0 && huanyuan == 1) {
			settextcolor(WHITE);
			cleardevice();
			settextstyle(300, 0, _T("Consolas"));
			outtextxy(0 + (1440 - textwidth("你成功了")) / 2, 0 + (780 - textheight("你成功了")) / 2, "你成功了");
			if (shubiao.uMsg == WM_LBUTTONDOWN) {
				daluan = 0;
				huanyuan = 0;
			}
		}
		if (shubiao.uMsg == WM_LBUTTONDOWN&&k==0) {
			if (200 < shubiao.x && shubiao.x < 200 + 1040 && 100 < shubiao.y && shubiao.y < 100 + 240) {
				k = 1;
			}
			if (200 < shubiao.x && shubiao.x < 200 + 1040 && 440 < shubiao.y && shubiao.y < 440 + 240) {
				k = 2;
				for (int i = 0;i < 9;i++) {
					r[i] = -1;
					u[i] = -1;
					f[i] = -1;
					l[i] = -1;
					d[i] = -1;
					b[i] = -1;
				}
				r[4] = 1;
				u[4] = 2;
				f[4] = 3;
				l[4] = 4;
				d[4] = 5;
				b[4] = 6;
			}
		}
		if (shubiao.uMsg == WM_LBUTTONDOWN&&k==1) {
			//R
			if (850< shubiao.x && shubiao.x <950 && 60 - 19 < shubiao.y && shubiao.y <110 - 19) {
				R();
				yibu = 1;
			}
			else if (1030< shubiao.x && shubiao.x <1130 && 60 - 19 < shubiao.y && shubiao.y <110 - 19) {
				R3();
				yibu = 2;
			}
			else if (1210< shubiao.x && shubiao.x <1310 && 60 - 19 < shubiao.y && shubiao.y <110 - 19) {
				R2();
				yibu = 3;
			}
			//U
			else if (850 < shubiao.x && shubiao.x < 950 && 132 - 19 < shubiao.y && shubiao.y < 182 - 19) {
				U();
				yibu = 4;
			}
			else if (1030 < shubiao.x && shubiao.x < 1130 && 132 - 19 < shubiao.y && shubiao.y < 182 - 19) {
				U3();
				yibu = 5;
			}
			else if (1210 < shubiao.x && shubiao.x < 1310 && 132 - 19 < shubiao.y && shubiao.y < 182 - 19) {
				U2();
				yibu = 6;
			}
			//F
			else if (850 < shubiao.x && shubiao.x < 950 && 204 - 19 < shubiao.y && shubiao.y < 254 - 19) {
				F();
				yibu = 7;
			}
			else if (1030 < shubiao.x && shubiao.x < 1130 && 204 - 19 < shubiao.y && shubiao.y < 254 - 19) {
				F3();
				yibu = 8;
			}
			else if (1210 < shubiao.x && shubiao.x < 1310 && 204 - 19 < shubiao.y && shubiao.y < 254 - 19) {
				F2();
				yibu = 9;
			}
			//L
			else if (850 < shubiao.x && shubiao.x < 950 && 276 - 19 < shubiao.y && shubiao.y < 326 - 19) {
				L();
				yibu = 10;
			}
			else if (1030 < shubiao.x && shubiao.x < 1130 && 276 - 19 < shubiao.y && shubiao.y < 326 - 19) {
				L3();
				yibu = 11;
			}
			else if (1210 < shubiao.x && shubiao.x < 1310 && 276 - 19 < shubiao.y && shubiao.y < 326 - 19) {
				L2();
				yibu = 12;
			}
			//D
			else if (850 < shubiao.x && shubiao.x < 950 && 348 - 19 < shubiao.y && shubiao.y < 398 - 19) {
				D();
				yibu = 13;
			}
			else if (1030 < shubiao.x && shubiao.x < 1130 && 348 - 19 < shubiao.y && shubiao.y < 398 - 19) {
				D3();
				yibu = 14;
			}
			else if (1210 < shubiao.x && shubiao.x < 1310 && 348 - 19 < shubiao.y && shubiao.y < 398 - 19) {
				D2();
				yibu = 15;
			}
			//B
			else if (850 < shubiao.x && shubiao.x < 950 && 420 - 19 < shubiao.y && shubiao.y < 470 - 19) {
				B();
				yibu = 16;
			}
			else if (1030 < shubiao.x && shubiao.x < 1130 && 420 - 19 < shubiao.y && shubiao.y < 470 - 19) {
				B3();
				yibu = 17;
			}
			else if (1210 < shubiao.x && shubiao.x < 1310 && 420 - 19 < shubiao.y && shubiao.y < 470 - 19) {
				B2();
				yibu = 18;
			}
			//x
			else if (850 < shubiao.x && shubiao.x < 950 &&  492 - 19 < shubiao.y && shubiao.y < 542 - 19) {
				x();
				yibu = 19;
			}
			else if (1030 < shubiao.x && shubiao.x < 1130 &&  492 - 19 < shubiao.y && shubiao.y < 542 - 19) {
				x3();
				yibu = 20;
			}
			else if (1210 < shubiao.x && shubiao.x < 1310 &&  492 - 19 < shubiao.y && shubiao.y < 542 - 19) {
				x2();
				yibu = 21;
			}
			//y
			else if (850 < shubiao.x && shubiao.x < 950 && 564 - 19 < shubiao.y && shubiao.y < 614 - 19) {
				y();
				yibu = 22;
			}
			else if (1030 < shubiao.x && shubiao.x < 1130 && 564 - 19 < shubiao.y && shubiao.y < 614 - 19) {
				y3();
				yibu = 23;
			}
			else if (1210 < shubiao.x && shubiao.x < 1310 && 564 - 19 < shubiao.y && shubiao.y < 614 - 19) {
				y2();
				yibu = 24;
			}
			//z
			else if (850 < shubiao.x && shubiao.x < 950 && 636 - 19 < shubiao.y && shubiao.y < 686 - 19) {
				z();
				yibu = 25;
			}
			else if (1030 < shubiao.x && shubiao.x < 1130 && 636 - 19 < shubiao.y && shubiao.y < 686 - 19) {
				z3();
				yibu = 26;
			}
			else if (1210 < shubiao.x && shubiao.x < 1310 && 636 - 19 < shubiao.y && shubiao.y < 686 - 19) {
				z2();
				yibu = 27;
			}
			//清空
			else if (850 < shubiao.x && shubiao.x < 950 && 708 - 19 < shubiao.y && shubiao.y < 758 - 19) {
				huanzhu();
				if (panduanhuanyuan()) {
					woc = 1;
				}
				else {
					woc = 0;
				}
				for (int i = 0;i < 9;i++) {
					r[i] = 1;
					u[i] = 2;
					f[i] = 3;
					l[i] = 4;
					d[i] = 5;
					b[i] = 6;
				}
				daluan = 0;
				yibu = 28;
			}
			//一键打乱
			else if (1030 < shubiao.x && shubiao.x < 1130 && 708 -19 < shubiao.y && shubiao.y < 758 - 19 ) {
				huanzhu();
				for (int i = 0;i < 114514;i++) {
					int random = (rand() % 6) + 1;
					if (random == 1) R();
					else if (random == 2) U();
					else if (random == 3) F();
					else if (random == 4) L();
					else if (random == 5) D();
					else if (random == 6) B();
				}
				daluan++;
				yibu = 29;
			}
			else if (1210 < shubiao.x && shubiao.x < 1310 && 708 - 19 < shubiao.y && shubiao.y < 758 - 19) {
				if (yibu == 1) {
					R3();
				}
				else if (yibu == 2) {
					R();
				}
				else if (yibu == 3) {
					R2();
				}
				else if (yibu == 4) {
					U3();
				}
				else if (yibu == 5) {
					U();
				}
				else if (yibu == 6) {
					U2();
				}
				else if (yibu == 7) {
					F3();
				}
				else if (yibu == 8) {
					F();
				}
				else if (yibu == 9) {
					F2();
				}
				else if (yibu == 10) {
					L3();
				}
				else if (yibu == 11) {
					L();
				}
				else if (yibu == 12) {
					L2();
				}
				else if (yibu == 13) {
					D3();
				}
				else if (yibu == 14) {
					D();
				}
				else if (yibu == 15) {
					D2();
				}
				else if (yibu == 16) {
					B3();
				}
				else if (yibu == 17) {
					B();
				}
				else if (yibu == 18) {
					B2();
				}
				else if (yibu == 19) {
					x3();
				}
				else if (yibu == 20) {
					x();
				}
				else if (yibu == 21) {
					x2();
				}
				else if (yibu == 22) {
					y3();
				}
				else if (yibu == 23) {
					y();
				}
				else if (yibu == 24) {
					y2();
				}
				else if (yibu == 25) {
					z3();
				}
				else if (yibu == 26) {
					z();
				}
				else if (yibu == 27) {
					z2();
				}
				else if (yibu == 28) {
					for (int i = 0;i < 9;i++) {
						r[i] = rr[i];
						u[i] = uu[i];
						f[i] = ff[i];
						l[i] = ll[i];
						d[i] = dd[i];
						b[i] = bb[i];
					}
					if (woc == 0) {
						daluan = 1;
					}
					else {
						daluan = 0;
					}
				}
				else if (yibu == 29) {
					for (int i = 0;i < 9;i++) {
						r[i] = rr[i];
						u[i] = uu[i];
						f[i] = ff[i];
						l[i] = ll[i];
						d[i] = dd[i];
						b[i] = bb[i];
					}
					daluan = 0;
				}
				yibu = 0;
			}
		}
		if (panduanhuanyuan() && daluan==1) {
			huanyuan = 1;
		}
		if (k == 0) {
			hua666();
		}
		else if (k == 1&&!(daluan==1&&huanyuan==1)) {
			cleardevice();
			huahua1(242, 99, u);
			huahua2(518, 252, r);
			huahua(89,252, f);
			huahuahua();
		}
		else if (k == 2) {
			cleardevice();
			huahua1(242, 99, u);
			huahua2(518, 252, r);
			huahua(89, 252, f);
		}
		FlushBatchDraw();
	}
	EndBatchDraw();
}