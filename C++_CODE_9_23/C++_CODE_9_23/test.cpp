#define _CRT_SECURE_NO_WARNINGS 1
#include<graphics.h>
#include<conio.h>

//int main()
//{
//	initgraph(400, 400);
//	circle(200, 200, 100);
//	outtextxy(170, 200, _T("ͼ���"));
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
//#define  WIDTH 800   // ������
//#define  HEIGHT 600  // ����߶ȶ�
//
//float offsetAngle = PI / 6; // ����֦�ɺ͸�֦��ƫ��ĽǶ�
//float shortenRate = 0.65;  // ��֦�ɱȸ�֦�ɱ�̵ı���
//int isShowAnimation = 1; // �Ƿ���ʾ�����ɵĹ��̶���
//
//// ��[inputMin,inputMax]��Χ��input������ӳ��Ϊ[outputMin,outputMax]��Χ��output����
//float mapValue(float input, float inputMin, float inputMax, float outputMin, float outputMax)
//{
//	float output;
//	if ((input - inputMin) < 0.000001) // ��ֹ�������bug
//		output = outputMin;
//	else
//		output = (input - inputMin) * (outputMax - outputMin) / (inputMax - inputMin) + outputMin;
//	return output;
//}
//
//// ����[min,max]֮������С��
//float randBetween(float min, float max)
//{
//	float t = rand() / double(RAND_MAX); // ����[0,1]�����С��
//	// ����mapValue��������ֵ��Χ��[0,1]ӳ�䵽[min,max]
//	float r = mapValue(t, 0, 1, min, max);
//	return r;
//}
//
//// ֦�����ɺͻ��Ƶݹ麯��
//// ���������֦����ʼx y���֦꣬�ɳ��ȣ�֦�ɽǶȣ�֦�ɻ�ͼ������ȣ��ڼ���
//void brunch(float x_start, float y_start, float length, float angle, float thickness, int generation)
//{
//	// �������Ǻ��������ǰ֦�ɵ��յ�x,y����
//	float x_end, y_end;
//	x_end = x_start + length * cos(angle);
//	y_end = y_start + length * sin(angle);
//
//	// ������֦��
//	setlinestyle(PS_SOLID, thickness); // �趨��ǰ֦���߿�
//	// ����֦��Ϊ�Һ�ɫ����������ڣ���֦���𽥱���
//	COLORREF  color = HSVtoRGB(15, 0.75, 0.4 + generation * 0.05);
//	setlinecolor(color); // �趨��ǰ֦����ɫ
//
//	line(x_start, y_start, x_end, y_end); // ������ǰ֦�ɣ����ߣ�
//
//	// �����֦�ɵĴ���
//	int childGeneration = generation + 1;
//	// �������ҡ��м�������֦�ɵĳ��ȣ��𽥱�̣�����һ�������
//	float childLength = shortenRate * length;
//	float leftChildLength = childLength * randBetween(0.9, 1.1);
//	float rightChildLength = childLength * randBetween(0.9, 1.1);
//	float centerChildLength = childLength * randBetween(0.8, 1.1);
//
//	// ����֦�ɳ��ȴ���2�����Ҵ���С�ڵ���10���ݹ���ò�����֦��
//	if (childLength >= 2 && childGeneration <= 9)
//	{
//		// ������֦�ɵĴ�ϸ���𽥱�ϸ
//		float childThickness = thickness * 0.8;
//		if (childThickness < 2) // ֦�ɻ�ͼ��ϸ���߿�Ϊ2
//			childThickness = 2;
//
//		// һ�����ʲ������ҡ�����֦��
//		if (randBetween(0, 1) < 0.95)
//			brunch(x_end, y_end, leftChildLength, angle + offsetAngle * randBetween(0.5, 1), childThickness, childGeneration);
//		if (randBetween(0, 1) < 0.95)
//			brunch(x_end, y_end, rightChildLength, angle - offsetAngle * randBetween(0.5, 1), childThickness, childGeneration);
//		if (randBetween(0, 1) < 0.85)
//			brunch(x_end, y_end, centerChildLength, angle + offsetAngle / 5 * randBetween(-1, 1), childThickness, childGeneration);
//	}
//	else // ��ĩ�˻���ӣ������һ����ɫ���Բ
//	{
//		setlinestyle(PS_SOLID, 1); // �߿�
//		// ӣ����ɫHSVtoRGB(325,0.3,1)����һ�������
//		COLORREF  color = HSVtoRGB(randBetween(300, 350), randBetween(0.2, 0.3), 1);
//		setlinecolor(color); // �趨������ɫ
//		setfillcolor(color); // �趨�����ɫ
//		if (childLength <= 4) // �����֦�ɳ���С�ڵ���4
//			fillcircle(x_end, y_end, 2); // Բ�İ뾶Ϊ2����С�Ϳ������ˣ�
//		else
//			fillcircle(x_end, y_end, childLength / 2); // ��һ��Բ���뾶Ϊ��֦�ɳ��ȵ�һ��
//	}
//
//	if (isShowAnimation) // ���Ϊ1������ӣ�������ɵĹ��̶���
//	{
//		FlushBatchDraw(); // ��������
//		Sleep(1); // ��ͣ
//	}
//}
//
//void startup()  // ��ʼ��
//{
//	srand(time(0)); // �����ʼ��
//	initgraph(WIDTH, HEIGHT); // �¿�һ������
//	setbkcolor(RGB(255, 255, 255)); // ��ɫ����
//	cleardevice(); // ����
//	BeginBatchDraw(); // ��ʼ��������
//	brunch(WIDTH / 2, HEIGHT, 0.45 * HEIGHT * shortenRate, -PI / 2, 15 * shortenRate, 1); // �ݹ麯������
//	FlushBatchDraw(); // ��������
//}
//
//void update()  // ÿ֡����
//{
//	MOUSEMSG m;
//	if (MouseHit())
//	{
//		m = GetMouseMsg();
//		if (m.uMsg == WM_MOUSEMOVE) // ������ƶ�ʱ���趨�ݹ麯���Ĳ���
//		{
//			// �������ң�������֦��ƫ�븸֦�ɵĽǶ��𽥱��
//			offsetAngle = mapValue(m.x, 0, WIDTH, PI / 10, PI / 4);
//			// �����ϵ��£���֦�ɱȸ�֦�ɵĳ������̵ĸ���
//			shortenRate = mapValue(m.y, 0, HEIGHT, 0.7, 0.3);
//		}
//		if (m.uMsg == WM_LBUTTONDOWN) // �����������ʱ���Ե�ǰ������ʼ����һ������
//		{
//			cleardevice(); // ����
//			brunch(WIDTH / 2, HEIGHT, 0.45 * HEIGHT * shortenRate, -PI / 2, 15 * shortenRate, 1); // �ݹ����
//			FlushBatchDraw(); // ��������
//		}
//		if (m.uMsg == WM_RBUTTONDOWN) // ������Ҽ����ʱ���л��Ƿ���ʾ���̶���
//		{
//			if (isShowAnimation == 1)
//				isShowAnimation = 0;
//			else if (isShowAnimation == 0)
//				isShowAnimation = 1;
//		}
//	}
//}
//
//int main() // ������
//{
//	startup();  // ��ʼ�� 	
//	while (1)  // �ظ�ѭ��
//		update();  // ÿ֡����
//	return 0;
//}


/*	*************************
 *	�������ƣ�	LoveSnow - ��׳���
 *	********* ˵�� **********
 *	��Ҫ�Լ��ṩһ�Ŵ�СΪ 640��480 ��ͼƬ(img.jpg)����Ŀ��Ŀ¼��
 *	��С�����ڳ����ڸ��ģ�ͼƬ����Ҳ���ԡ�
 *	*************************/
#include <graphics.h>

#define MAX_STAR 500			// ѩ����������
#define SCREEN_WIDTH 640		// ��Ļ���
#define SCREEN_HEIGHT 480		// ��Ļ�߶�
#define MAX_STEP 3				// ѩ��ÿ���ƶ���߲���
#define MAX_RADIUS 3			// ѩ�����뾶
#define IMGNAME _T("XXXX.jpg")	// ͼƬ����

using namespace std;

// ͼƬת���飨����кܴ��Ż��ռ�ģ���Ҫʶ���ɫ��Ƭ���Կ��⣩
int imgList[SCREEN_HEIGHT][SCREEN_WIDTH] = { 0 };

// ѩ��״̬
enum STATUS
{
	STOP = 0,	// ����
	UP,			// ����
	DOWN,		// ����
	LEFT,		// ����
	RIGHT,		// ����
	RANDOM,		// ���
	ALL_STATUS	// ��¼״̬����
};
struct STAR
{
	int x;				// ѩ���� x ����
	int y;				// ѩ���� y ����
	enum STATUS stat;	// ѩ��״̬
	unsigned radius;	// ѩ���İ뾶
	int step;			// ѩ��ÿ���ƶ��Ĳ���
	int color;			// ѩ������ɫ
};
struct SqList
{
	struct STAR* elems; // ˳���Ļ���ַ
	int length;			// ˳���ĳ���
	int size;			// ˳���Ŀռ�
};

// ˳���Ľӿ�
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
	if (L.length == L.size) return false;	// �洢�ռ�����
	L.elems[L.length] = e;
	L.length++;								// ���� 1
	return true;
}
bool listDelete(SqList& L, int i)
{
	if (i < 0 || i >= L.length) return false;
	if (i == L.length - 1)
	{										// ɾ�����һ��Ԫ��
		L.length--;
		return true;
	}
	for (int j = i; j < L.length - 1; j++)
	{
		L.elems[j] = L.elems[j + 1];		// ɾ��λ�õĺ���Ԫ��һ����ǰ��
	}
	L.length--;
	return true;
}
void destroyList(SqList& L)
{
	if (L.elems) delete[]L.elems;			// �ͷŴ洢�ռ�
	L.length = 0;
	L.size = 0;
}

/************************************
* ���ܣ��ƶ�ѩ��������ָ����������ѩ��
* ���������
* L - ѩ������
* i - ѩ����ȫ�������е��±�
* ����ֵ����
************************************/
void MoveStar(SqList& L, int i)
{
	// ����ѩ��
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
	// ����ԭ����ѩ��
	setfillcolor(BLACK);
	solidcircle(L.elems[i].x, L.elems[i].y, L.elems[i].radius);
	if (L.elems[i].stat == DOWN)
	{
		L.elems[i].y += L.elems[i].step;
		L.elems[i].x -= 2;
		if (L.elems[i].x < 0) L.elems[i].x = SCREEN_WIDTH;
		if (L.elems[i].y > SCREEN_HEIGHT) L.elems[i].y = 0;
		//if(L.elems[i].y>SCREEN_HEIGHT) listDelete(L, i);	// ��δ��������Ʈ����Ļ���ѩ������
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
//* ���ܣ���ʼ��ѩ��
//* ���������
//* i - ѩ����ȫ�������е��±�
//* ����ֵ����
//************************************/
//void initStar(struct STAR& _star)
//{
//	int rgb = 0;
//	//rand() �õ��������Χ 0 - 32767 RAND_MAX
//	_star.x = rand() % SCREEN_WIDTH;		// x ��Χ 0 - SCREEN_WIDTH
//	_star.y = rand() % SCREEN_HEIGHT;		// y ��Χ 0 - SCREEN_HEIGHT
//	//_star.stat = STATUS(rand() % 6);		// ѩ��״̬�����
//	_star.stat = DOWN;						// ѩ��״̬������
//	_star.radius = 1 + rand() % MAX_RADIUS; // �뾶���� 1 - MAX_RADIUS
//	_star.step = rand() % MAX_STEP + 1;		// ���� 1 - MAX_STEP
//	rgb = 255 * _star.step / MAX_STEP;		// RGB��0 - 255
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
//	// ��ʼ����Ļ
//	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT);
//
//	// ��ʼ��ͼƬ
//	IMAGE img(SCREEN_WIDTH, SCREEN_HEIGHT);
//	//loadimage(&img, IMGNAME);
//	SetWorkingImage(&img);	// ���� imgΪ�����豸
//	setbkcolor(WHITE);
//	cleardevice();
//	settextcolor(BLACK);
//	settextstyle(120, 55, _T("����"));
//	outtextxy(100, 150, _T("���ض���"));
//	//outtextxy(100, 250, _T("��һ����"));
//	COLORREF color;			// ��¼������ɫ
//	BYTE r, b, g;			// ��¼����RGB
//
//	for (int y = 0; y < SCREEN_HEIGHT; y++)
//	{
//		for (int x = 0; x < SCREEN_WIDTH; x++)
//		{
//			color = getpixel(x, y);		// ��ȡ������ɫ
//			r = GetRValue(color);
//			b = GetBValue(color);
//			g = GetGValue(color);
//			if (r < 200 && b < 200 && g < 200)
//			{							// �ж������¡�ѩ�ۡ�������λ��
//				imgList[y][x] = 1;
//			}
//		}
//	}
//
//	SetWorkingImage();	// ���û�Ĭ�ϻ����豸
//	cleardevice();
//
//	// ��ʼ������ѩ��״̬��˳���
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
//		{	// ������ѩ���뿪��Ļ����������ᴥ�����˳�
//			quit = true;
//		}
//		Sleep(50);
//	}
//	system("pause");
//	closegraph();
//	return 0;
//}
