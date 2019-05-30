#include<iostream>
using namespace std;
double dfx(double x,double y)
{
	return y - 2 * x / y;
}
void Euler()
{
	double x0,x1, y0,y1, h, N,yp,yc;
	int n = 1;
	cout << "输入初始的 x0  y0  h  N" << endl;
	cin >> x0 >> y0 >> h >> N;
	while (1)
	{
		x1 = x0 + h;
		yp = y0 + h * dfx(x0, y0);
		yc = y0 + h * dfx(x1, yp);
		y1 = (yp + yc) / 2;
		cout << " x" << n << "   y" << n << endl;
		cout << x1 << "  " << y1 << endl;
		cout << endl;
		if (n == N)
			break;
		else
		{
			x0 = x1;
			y0 = y1;
			n++;
		}
	}
}
void Longe_kutta()
{
	double x0, x1, y0, y1, h, N, K1,K2,K3,K4;
	int n = 1;
	cout << "输入初始的 x0  y0  h  N" << endl;
	cin >> x0 >> y0 >> h >> N;
	while (1)
	{
		x1 = x0 + h;
		K1 =dfx(x0,y0);
		K2 = dfx(x0 + h / 2, y0 + h / 2*K1);
		K3 = dfx(x0 + h / 2, y0 + h / 2 * K2);
		K4 = dfx(x1, y0 + h * K3);
		y1 = y0 + h * (K1 + 2*K2 + 2*K3 + K4) / 6;
		cout << " x" << n << "   y" << n << endl;
		cout << x1 << "  " << y1 << endl;
		cout << endl;
		if (n == N)
			break;
		else
		{
			x0 = x1;
			y0 = y1;
			n++;
		}
	}

}
int main()
{
	int a;
	while (1)
	{	
		cout << "1.改进的欧拉公式\n2.四阶龙格·库卡公式" << endl;
		cin >> a;
		if (a == 1)
			Euler();
		else if (a == 2)
			Longe_kutta();
		else
			break;
	}
	return 0;
}