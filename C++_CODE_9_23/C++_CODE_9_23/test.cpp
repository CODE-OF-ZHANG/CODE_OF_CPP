#define _CRT_SECURE_NO_WARNINGS 1
#include<graphics.h>
#include<conio.h>

//int main()
//{
//	initgraph(400, 400);
//	circle(200, 200, 100);
//	outtextxy(170, 200, _T("图书馆"));
//	_getch();
//	closegraph();
//
//	return 0;
//}


//#include <graphics.h>  
//#include <conio.h>
//#include <stdio.h>
//#include <math.h>
//#include <time.h>
//#define  PI 3.1415926
//#define  WIDTH 800   // 画面宽度
//#define  HEIGHT 600  // 画面高度度
//
//float offsetAngle = PI / 6; // 左右枝干和父枝干偏离的角度
//float shortenRate = 0.65;  // 子枝干比父枝干变短的倍数
//int isShowAnimation = 1; // 是否显示树生成的过程动画
//
//// 把[inputMin,inputMax]范围的input变量，映射为[outputMin,outputMax]范围的output变量
//float mapValue(float input, float inputMin, float inputMax, float outputMin, float outputMax)
//{
//	float output;
//	if ((input - inputMin) < 0.000001) // 防止除以零的bug
//		output = outputMin;
//	else
//		output = (input - inputMin) * (outputMax - outputMin) / (inputMax - inputMin) + outputMin;
//	return output;
//}
//
//// 生成[min,max]之间的随机小数
//float randBetween(float min, float max)
//{
//	float t = rand() / double(RAND_MAX); // 生成[0,1]的随机小数
//	// 调用mapValue函数，把值范围从[0,1]映射到[min,max]
//	float r = mapValue(t, 0, 1, min, max);
//	return r;
//}
//
//// 枝干生成和绘制递归函数
//// 输入参数：枝干起始x y坐标，枝干长度，枝干角度，枝干绘图线条宽度，第几代
//void brunch(float x_start, float y_start, float length, float angle, float thickness, int generation)
//{
//	// 利用三角函数求出当前枝干的终点x,y坐标
//	float x_end, y_end;
//	x_end = x_start + length * cos(angle);
//	y_end = y_start + length * sin(angle);
//
//	// 画线条枝干
//	setlinestyle(PS_SOLID, thickness); // 设定当前枝干线宽
//	// 设置枝干为灰褐色，主树干最黑，子枝干逐渐变亮
//	COLORREF  color = HSVtoRGB(15, 0.75, 0.4 + generation * 0.05);
//	setlinecolor(color); // 设定当前枝干颜色
//
//	line(x_start, y_start, x_end, y_end); // 画出当前枝干（画线）
//
//	// 求出子枝干的代数
//	int childGeneration = generation + 1;
//	// 生成左、右、中间三个子枝干的长度，逐渐变短，并有一定随机性
//	float childLength = shortenRate * length;
//	float leftChildLength = childLength * randBetween(0.9, 1.1);
//	float rightChildLength = childLength * randBetween(0.9, 1.1);
//	float centerChildLength = childLength * randBetween(0.8, 1.1);
//
//	// 当子枝干长度大于2，并且代数小于等于10，递归调用产生子枝干
//	if (childLength >= 2 && childGeneration <= 9)
//	{
//		// 生成子枝干的粗细，逐渐变细
//		float childThickness = thickness * 0.8;
//		if (childThickness < 2) // 枝干绘图最细的线宽为2
//			childThickness = 2;
//
//		// 一定概率产生左、右、中子枝干
//		if (randBetween(0, 1) < 0.95)
//			brunch(x_end, y_end, leftChildLength, angle + offsetAngle * randBetween(0.5, 1), childThickness, childGeneration);
//		if (randBetween(0, 1) < 0.95)
//			brunch(x_end, y_end, rightChildLength, angle - offsetAngle * randBetween(0.5, 1), childThickness, childGeneration);
//		if (randBetween(0, 1) < 0.85)
//			brunch(x_end, y_end, centerChildLength, angle + offsetAngle / 5 * randBetween(-1, 1), childThickness, childGeneration);
//	}
//	else // 最末端绘制樱花，画一个粉色填充圆
//	{
//		setlinestyle(PS_SOLID, 1); // 线宽
//		// 樱花粉色HSVtoRGB(325,0.3,1)，有一定随机性
//		COLORREF  color = HSVtoRGB(randBetween(300, 350), randBetween(0.2, 0.3), 1);
//		setlinecolor(color); // 设定线条颜色
//		setfillcolor(color); // 设定填充颜色
//		if (childLength <= 4) // 如果子枝干长度小于等于4
//			fillcircle(x_end, y_end, 2); // 圆的半径为2（再小就看不清了）
//		else
//			fillcircle(x_end, y_end, childLength / 2); // 画一个圆，半径为子枝干长度的一半
//	}
//
//	if (isShowAnimation) // 如果为1，绘制樱花树生成的过程动画
//	{
//		FlushBatchDraw(); // 批量绘制
//		Sleep(1); // 暂停
//	}
//}
//
//void startup()  // 初始化
//{
//	srand(time(0)); // 随机初始化
//	initgraph(WIDTH, HEIGHT); // 新开一个画面
//	setbkcolor(RGB(255, 255, 255)); // 白色背景
//	cleardevice(); // 清屏
//	BeginBatchDraw(); // 开始批量绘制
//	brunch(WIDTH / 2, HEIGHT, 0.45 * HEIGHT * shortenRate, -PI / 2, 15 * shortenRate, 1); // 递归函数调用
//	FlushBatchDraw(); // 批量绘制
//}
//
//void update()  // 每帧更新
//{
//	MOUSEMSG m;
//	if (MouseHit())
//	{
//		m = GetMouseMsg();
//		if (m.uMsg == WM_MOUSEMOVE) // 当鼠标移动时，设定递归函数的参数
//		{
//			// 鼠标从左到右，左右子枝干偏离父枝干的角度逐渐变大
//			offsetAngle = mapValue(m.x, 0, WIDTH, PI / 10, PI / 4);
//			// 鼠标从上到下，子枝干比父枝干的长度缩短的更快
//			shortenRate = mapValue(m.y, 0, HEIGHT, 0.7, 0.3);
//		}
//		if (m.uMsg == WM_LBUTTONDOWN) // 当鼠标左键点击时，以当前参数开始绘制一棵新数
//		{
//			cleardevice(); // 清屏
//			brunch(WIDTH / 2, HEIGHT, 0.45 * HEIGHT * shortenRate, -PI / 2, 15 * shortenRate, 1); // 递归调用
//			FlushBatchDraw(); // 批量绘制
//		}
//		if (m.uMsg == WM_RBUTTONDOWN) // 当鼠标右键点击时，切换是否显示过程动画
//		{
//			if (isShowAnimation == 1)
//				isShowAnimation = 0;
//			else if (isShowAnimation == 0)
//				isShowAnimation = 1;
//		}
//	}
//}
//
//int main() // 主函数
//{
//	startup();  // 初始化 	
//	while (1)  // 重复循环
//		update();  // 每帧更新
//	return 0;
//}


/*	*************************
 *	程序名称：	LoveSnow - 表白程序
 *	********* 说明 **********
 *	需要自己提供一张大小为 640×480 的图片(img.jpg)在项目根目录下
 *	大小可以在程序内更改，图片名字也可以。
 *	*************************/
#include <graphics.h>

#define MAX_STAR 500			// 雪花数量上限
#define SCREEN_WIDTH 640		// 屏幕宽度
#define SCREEN_HEIGHT 480		// 屏幕高度
#define MAX_STEP 3				// 雪花每次移动最高步长
#define MAX_RADIUS 3			// 雪花最大半径
#define IMGNAME _T("XXXX.jpg")	// 图片名字

using namespace std;

// 图片转数组（这个有很大优化空间的，需要识别彩色照片可以看这）
int imgList[SCREEN_HEIGHT][SCREEN_WIDTH] = { 0 };

// 雪花状态
enum STATUS
{
	STOP = 0,	// 不动
	UP,			// 向上
	DOWN,		// 向下
	LEFT,		// 向左
	RIGHT,		// 向右
	RANDOM,		// 随机
	ALL_STATUS	// 记录状态总数
};
struct STAR
{
	int x;				// 雪花的 x 坐标
	int y;				// 雪花的 y 坐标
	enum STATUS stat;	// 雪花状态
	unsigned radius;	// 雪花的半径
	int step;			// 雪花每次移动的步长
	int color;			// 雪花的颜色
};
struct SqList
{
	struct STAR* elems; // 顺序表的基地址
	int length;			// 顺序表的长度
	int size;			// 顺序表的空间
};

// 顺序表的接口
bool initList(SqList& L);
bool listAppend(SqList& L, struct STAR e);
bool listDelete(SqList& L, int i);
void destroyList(SqList& L);

bool initList(SqList& L)
{
	L.elems = new struct STAR[MAX_STAR];
	if (!L.elems) return false;
	L.length = 0;
	L.size = MAX_STAR;
	return true;
}
bool listAppend(SqList& L, struct STAR e)
{
	if (L.length == L.size) return false;	// 存储空间已满
	L.elems[L.length] = e;
	L.length++;								// 表长加 1
	return true;
}
bool listDelete(SqList& L, int i)
{
	if (i < 0 || i >= L.length) return false;
	if (i == L.length - 1)
	{										// 删除最后一个元素
		L.length--;
		return true;
	}
	for (int j = i; j < L.length - 1; j++)
	{
		L.elems[j] = L.elems[j + 1];		// 删除位置的后续元素一次往前移
	}
	L.length--;
	return true;
}
void destroyList(SqList& L)
{
	if (L.elems) delete[]L.elems;			// 释放存储空间
	L.length = 0;
	L.size = 0;
}

/************************************
* 功能：移动雪花，并在指定区域留下雪痕
* 输入参数：
* L - 雪花对象
* i - 雪花在全局数组中的下标
* 返回值：无
************************************/
void MoveStar(SqList& L, int i)
{
	// 留下雪痕
	if (L.elems[i].stat == DOWN)
	{
		if (imgList[L.elems[i].y][L.elems[i].x] == 1)
		{
			L.elems[i].y += L.elems[i].step;
			L.elems[i].x -= 2;
		}
	}
	if (L.elems[i].stat == UP)
	{
		if (imgList[L.elems[i].y][L.elems[i].x] == 1)
		{
			L.elems[i].y -= L.elems[i].step;
			L.elems[i].x -= 2;
		}
	}
	if (L.elems[i].stat == LEFT)
	{
		if (imgList[L.elems[i].y][L.elems[i].x] == 1) L.elems[i].x -= L.elems[i].step;
	}
	if (L.elems[i].stat == RIGHT)
	{
		if (imgList[L.elems[i].y][L.elems[i].x] == 1) L.elems[i].x += L.elems[i].step;
	}

	if (L.elems[i].stat == STOP) return;
	// 擦除原来的雪花
	setfillcolor(BLACK);
	solidcircle(L.elems[i].x, L.elems[i].y, L.elems[i].radius);
	if (L.elems[i].stat == DOWN)
	{
		L.elems[i].y += L.elems[i].step;
		L.elems[i].x -= 2;
		if (L.elems[i].x < 0) L.elems[i].x = SCREEN_WIDTH;
		if (L.elems[i].y > SCREEN_HEIGHT) L.elems[i].y = 0;
		//if(L.elems[i].y>SCREEN_HEIGHT) listDelete(L, i);	// 这段代码可以让飘出屏幕外的雪花消亡
	}
	else if (L.elems[i].stat == UP)
	{
		L.elems[i].y -= L.elems[i].step;
		L.elems[i].x -= 2;
		if (L.elems[i].x < 0) L.elems[i].x = SCREEN_WIDTH;
		if (L.elems[i].y < 0) L.elems[i].y = SCREEN_HEIGHT;
		//if(L.elems[i].y<0) listDelete(L, i);
	}
	else if (L.elems[i].stat == LEFT)
	{
		L.elems[i].x -= L.elems[i].step;
		if (L.elems[i].x > 0) L.elems[i].x = SCREEN_WIDTH;
		//if(L.elems[i].x<0) listDelete(L, i);
	}
	else if (L.elems[i].stat == RIGHT)
	{
		L.elems[i].x += L.elems[i].step;
		if (L.elems[i].x > SCREEN_HEIGHT) L.elems[i].x = 0;
		//if(L.elems[i].x>SCREEN_WIDTH) listDelete(L, i);
	}
	setfillcolor(L.elems[i].color);
	solidcircle(L.elems[i].x, L.elems[i].y, L.elems[i].radius);
}


///************************************
//* 功能：初始化雪花
//* 输入参数：
//* i - 雪花在全局数组中的下标
//* 返回值：无
//************************************/
//void initStar(struct STAR& _star)
//{
//	int rgb = 0;
//	//rand() 得到随机数范围 0 - 32767 RAND_MAX
//	_star.x = rand() % SCREEN_WIDTH;		// x 范围 0 - SCREEN_WIDTH
//	_star.y = rand() % SCREEN_HEIGHT;		// y 范围 0 - SCREEN_HEIGHT
//	//_star.stat = STATUS(rand() % 6);		// 雪花状态：随机
//	_star.stat = DOWN;						// 雪花状态：向下
//	_star.radius = 1 + rand() % MAX_RADIUS; // 半径控制 1 - MAX_RADIUS
//	_star.step = rand() % MAX_STEP + 1;		// 步长 1 - MAX_STEP
//	rgb = 255 * _star.step / MAX_STEP;		// RGB：0 - 255
//	_star.color = RGB(rgb, rgb, rgb);
//}
//
//
//int main()
//{
//	bool quit = false;
//	struct STAR star;
//	SqList starList;
//
//	// 初始化屏幕
//	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT);
//
//	// 初始化图片
//	IMAGE img(SCREEN_WIDTH, SCREEN_HEIGHT);
//	//loadimage(&img, IMGNAME);
//	SetWorkingImage(&img);	// 设置 img为绘制设备
//	setbkcolor(WHITE);
//	cleardevice();
//	settextcolor(BLACK);
//	settextstyle(120, 55, _T("黑体"));
//	outtextxy(100, 150, _T("比特冬哥"));
//	//outtextxy(100, 250, _T("有一个家"));
//	COLORREF color;			// 记录像素颜色
//	BYTE r, b, g;			// 记录像素RGB
//
//	for (int y = 0; y < SCREEN_HEIGHT; y++)
//	{
//		for (int x = 0; x < SCREEN_WIDTH; x++)
//		{
//			color = getpixel(x, y);		// 获取像素颜色
//			r = GetRValue(color);
//			b = GetBValue(color);
//			g = GetGValue(color);
//			if (r < 200 && b < 200 && g < 200)
//			{							// 判断需留下“雪痕”的数组位置
//				imgList[y][x] = 1;
//			}
//		}
//	}
//
//	SetWorkingImage();	// 设置回默认绘制设备
//	cleardevice();
//
//	// 初始化保存雪花状态的顺序表
//	initList(starList);
//
//	for (int i = 0; i < MAX_STAR; i++)
//	{
//		initStar(star);
//		listAppend(starList, star);
//	}
//
//	for (int i = 0; i < starList.length; i++)
//	{
//		setfillcolor(starList.elems[i].color);
//		solidcircle(starList.elems[i].x, starList.elems[i].y,
//			starList.elems[i].radius);
//	}
//
//	while (quit == false)
//	{
//		for (int i = 0; i < starList.length; i++)
//		{
//			MoveStar(starList, i);
//		}
//
//		if (starList.length == 0)
//		{	// 若设置雪花离开屏幕后消亡，则会触发此退出
//			quit = true;
//		}
//		Sleep(50);
//	}
//	system("pause");
//	closegraph();
//	return 0;
//}
