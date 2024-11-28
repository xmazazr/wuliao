#include <stdio.h>
#include <graphics.h>

//定义魔方
int r[9] = { 1,1,1,1,1,1,1,1,1 };
int u[9] = { 2,2,2,2,2,2,2,2,2 };
int f[9] = { 3,3,3,3,3,3,3,3,3 };
int l[9] = { 4,4,4,4,4,4,4,4,4 };
int d[9] = { 5,5,5,5,5,5,5,5,5 };
int b[9] = { 6,6,6,6,6,6,6,6,6 };
int k[3] = { -1,-1,-1 };

//旋转模仿一个面
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

//开始画画
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
		setlinestyle(PS_SOLID, 5);
		fillrectangle(x, y,x+143,y+143);
		x += dx[i];
		y += dy[i];
	}
}

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
		setlinestyle(PS_SOLID, 5);
		POINT pts[] = { {x, y}, {x + 143, y}, {x+92,y+51},{x - 51, y + 51}};
		fillpolygon(pts, 4);
		x += dx[i];
		y += dy[i];
	}
}

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
		setlinestyle(PS_SOLID, 5);
		POINT pts[] = { {x, y}, {x + 51, y-51}, {x + 51,y + 92},{x, y + 143} };
		fillpolygon(pts, 4);
		x += dx[i];
		y += dy[i];
	}
}

//又开始画画了
void huahuahua() {
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	settextstyle(50,0, _T("Consolas"));
	setfillcolor(WHITE);
	int x = 850, y = 60;
	int dx[2] = { 180,-540 };
	int dy[2] = { 0,72 };
	char c[29][10] = 
	{"R","R'","R2",
		"U","U'","U2",
		"F","F'","F2",
		"L","L'","L2",
		"D","D'","D2",
		"B","B'","B2",
	    "x","x'","x2",
		"y","y'","y2", 
		"z","z'","z2",
	    "重置魔方","一键打乱"};
	int k = 0;
	for (int i = 0;i < 9;i++) {
		for (int j = 0;j < 3;j++,k++) {
			fillrectangle(x, y, x + 100, y + 50);
			outtextxy(x+(100-textwidth(c[k])) / 2, y, c[k]);
			x += dx[0];
			y += dy[0];
		}
		x += dx[1];
		y += dy[1];
	}
	settextstyle(25, 0, _T("Consolas"));
	fillrectangle(x, y, x + 100, y + 50);
	outtextxy(x + (100 - textwidth(c[k])) / 2, y+(50-textheight(c[k]))/2, c[k]);
	k++;
	x += dx[0];
	y += dy[0];
	fillrectangle(x, y, x + 100, y + 50);
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

int main() {
	int k = 0,huanyuan=0,daluan=0;
	initgraph(1440, 780);
	BeginBatchDraw();
	while (1) {
		MOUSEMSG shubiao;
		shubiao = GetMouseMsg();
		//判断是否还原
		if (daluan == 1 && huanyuan == 1) {
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
			k = 1;
		}
		if (shubiao.uMsg == WM_LBUTTONDOWN&&k==1) {
			//R
			if (850< shubiao.x && shubiao.x <950 && 60< shubiao.y && shubiao.y <110 ) {
				R();
			}
			else if (1030< shubiao.x && shubiao.x <1130 && 60< shubiao.y && shubiao.y <110 ) {
				R3();
			}
			else if (1210< shubiao.x && shubiao.x <1310 && 60< shubiao.y && shubiao.y <110 ) {
				R2();
			}
			//U
			else if (850 < shubiao.x && shubiao.x < 950 && 132< shubiao.y && shubiao.y < 182) {
				U();
			}
			else if (1030 < shubiao.x && shubiao.x < 1130 && 132< shubiao.y && shubiao.y < 182) {
				U3();
			}
			else if (1210 < shubiao.x && shubiao.x < 1310 && 132< shubiao.y && shubiao.y < 182) {
				U2();
			}
			//F
			else if (850 < shubiao.x && shubiao.x < 950 && 204< shubiao.y && shubiao.y < 254) {
				F();
			}
			else if (1030 < shubiao.x && shubiao.x < 1130 && 204< shubiao.y && shubiao.y < 254) {
				F3();
			}
			else if (1210 < shubiao.x && shubiao.x < 1310 && 204< shubiao.y && shubiao.y < 254) {
				F2();
			}
			//L
			else if (850 < shubiao.x && shubiao.x < 950 && 276< shubiao.y && shubiao.y < 326) {
				L();
			}
			else if (1030 < shubiao.x && shubiao.x < 1130 && 276< shubiao.y && shubiao.y < 326) {
				L3();
			}
			else if (1210 < shubiao.x && shubiao.x < 1310 && 276< shubiao.y && shubiao.y < 326) {
				L2();
			}
			//D
			else if (850 < shubiao.x && shubiao.x < 950 && 348< shubiao.y && shubiao.y < 398) {
				D();
			}
			else if (1030 < shubiao.x && shubiao.x < 1130 && 348< shubiao.y && shubiao.y < 398) {
				D3();
			}
			else if (1210 < shubiao.x && shubiao.x < 1310 && 348< shubiao.y && shubiao.y < 398) {
				D2();
			}
			//B
			else if (850 < shubiao.x && shubiao.x < 950 && 420< shubiao.y && shubiao.y < 470) {
				B();
			}
			else if (1030 < shubiao.x && shubiao.x < 1130 && 420< shubiao.y && shubiao.y < 470) {
				B3();
			}
			else if (1210 < shubiao.x && shubiao.x < 1310 && 420< shubiao.y && shubiao.y < 470) {
				B2();
			}
			//x
			else if (850 < shubiao.x && shubiao.x < 950 &&  492< shubiao.y && shubiao.y < 542) {
				x();
			}
			else if (1030 < shubiao.x && shubiao.x < 1130 &&  492< shubiao.y && shubiao.y < 542) {
				x3();
			}
			else if (1210 < shubiao.x && shubiao.x < 1310 &&  492< shubiao.y && shubiao.y < 542) {
				x2();
			}
			//y
			else if (850 < shubiao.x && shubiao.x < 950 && 564< shubiao.y && shubiao.y < 614) {
				y();
			}
			else if (1030 < shubiao.x && shubiao.x < 1130 && 564< shubiao.y && shubiao.y < 614) {
				y3();
			}
			else if (1210 < shubiao.x && shubiao.x < 1310 && 564< shubiao.y && shubiao.y < 614) {
				y2();
			}
			//z
			else if (850 < shubiao.x && shubiao.x < 950 && 636< shubiao.y && shubiao.y < 686) {
				z();
			}
			else if (1030 < shubiao.x && shubiao.x < 1130 && 636< shubiao.y && shubiao.y < 686) {
				z3();
			}
			else if (1210 < shubiao.x && shubiao.x < 1310 && 636< shubiao.y && shubiao.y < 686) {
				z2();
			}
			//清空
			else if (850 < shubiao.x && shubiao.x < 950 && 708 < shubiao.y && shubiao.y < 758) {
				for (int i = 0;i < 9;i++) {
					r[i] = 1;
					u[i] = 2;
					f[i] = 3;
					l[i] = 4;
					d[i] = 5;
					b[i] = 6;
				}
				daluan = 0;
			}
			//一键打乱
			else if (1030 < shubiao.x && shubiao.x && 708 < shubiao.y && shubiao.y < 758) {
				for (int i = 0;i < 10000;i++) {
					int random = (rand() % 6) + 1;
					if (random == 1) R();
					else if (random == 2) U();
					else if (random == 3) F();
					else if (random == 4) L();
					else if (random == 5) D();
					else if (random == 6) B();
				}
				daluan = 1;
			}
		}
		if (panduanhuanyuan() && daluan==1) {
			huanyuan = 1;
		}
		if (k == 0) {
			
		}
		else if (k == 1&&!(daluan==1&&huanyuan==1)) {
			cleardevice();
			huahua1(222 + 20, 99, u);
			huahua2(498 + 20, 252, r);
			huahua(89,252, f);
			huahuahua();
		}
		FlushBatchDraw();
	}
	EndBatchDraw();
}