#ifndef _graphics_
#define _graphics_
#include<windows.h>
#include<math.h>
#include <vector>
#include <amp.h> 
#include <windowsx.h> 
#include <cmath>
#include <vector>
#include <iterator>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
vector<double> osx;
vector<double> osx1;
vector<double> osy;
bool logx = false; 
bool logy = false;
int xView;
int yView;
HPEN pen1;
HPEN pen2;

vector<double> vec3;
double (*F10)(double x1);

#define IDM_ABOUT 5
HINSTANCE hInstance; HINSTANCE hPrevInst;
LPSTR lpszArgs; int nWinMode;

LRESULT CALLBACK WindowFunc(HWND, UINT, WPARAM, LPARAM);
TCHAR szWinName[] = L"MyWindow";      
TCHAR szTitle[] = L"Программа";

class exemple
{
public:
	int qwe;
	HWND hwnd;
	vector<double> vec2;
	
	
	int  WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst,
		LPSTR lpszArgs, int nWinMode) {
		
		MSG msg;                   
		WNDCLASS wc;                               
			
		ZeroMemory(&wc, sizeof(wc));                             
		wc.hInstance = hInstance;                                       
		wc.lpszClassName = szWinName;                          
		wc.lpfnWndProc = WindowFunc;                           
		wc.style = CS_HREDRAW | CS_VREDRAW;             
		wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);          
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);             
		wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
		wc.lpszMenuName = NULL;                                 
		wc.cbClsExtra = 0;                                                 
		wc.cbWndExtra = 0;                                                
																		  
		if (!RegisterClass(&wc))                                         
		{                                    
			MessageBox(NULL, L"Окно нерегестрируется", L"Ошибка", MB_OK);
			return 1;
		}                                                           
																	
		hwnd = CreateWindow(                          
			szWinName,                                             
			szTitle,                                                       
			WS_OVERLAPPEDWINDOW,               
			100,                                                           
			100,                                                           
			800,                                                            
			600,                                                           
			HWND_DESKTOP,                                 
			NULL,                                                       
			hInstance,                                                  
			NULL);                                                   
		ShowWindow(hwnd, SW_SHOWNORMAL);      
											  
											  
		while (GetMessage(&msg, NULL, 0, 0))               
														
			DispatchMessage(&msg);                               
		return 0;                                                    
	}
	
};

vector<double> algor(double (*F)(double x), double min, double max) {
	vector<double> myvector1;
	vector<double>::iterator it;
	WCHAR s[100];
	double v, u, rr;
	int i, pp = 0;
	int t = 0;
	double abs1 = 0.2;
	double abs2 = 1;
	double sig = 0.3;

	abs2 = abs(sig * (F(max) - F(min)));




	if ((max > 0) && (min >= 0)) {
		while ((pow(10, pp)) <= (abs(max))) {
			pp++;
			v = pow(10, pp);
		}
		myvector1.push_back(0);
		myvector1.push_back(v);
	}
	else if ((max <= 0) && (min < 0)) {
		while ((pow(10, pp)) >= (abs(min))) {
			pp++;
			v = pow(10, pp);
		}
		myvector1.push_back(-v);
		myvector1.push_back(max);
	}
	else {
		while (((pow(10, pp)) >= (abs(min))) && ((pow(10, pp)) <= (abs(max)))) {
			pp++;
			v = pow(10, pp);
		}
		myvector1.push_back(0);
		myvector1.push_back(v);
	}

	int n = 3;
	u = abs1*(cbrt(max) - cbrt(min)); 
									 
	if (max > 0) {
		while ((pow(10, pp)) <= (abs(max))) {
			pp++;
			v = pow(10, pp);
		}
		myvector1.push_back(0);
		myvector1.push_back(v);
		it = myvector1.end() - 1;
		
		v = v/10;
		
		double G[11];
		do {
	
			if (abs(F(*it) - F(*(it - 1))) > abs2) {
				//cout << *(myvector1.end() - t-1) << endl;
				for (i = 1; i < 10; ++i) {
					myvector1.insert(myvector1.end() - i - t, *(myvector1.end() - 1 - t) - i*(v)); 
				}
			
				it = myvector1.end() - 1 - t; 
				
				for (i = 0; i <= 10; i++) {
					G[i] = F(*(it-i));
					if (G[i] == -INFINITY || G[i] == INFINITY) G[i] = 10000000000000;
				}
				int w = 0;
				int ww = 0;
				for (i = 10; i <= 0; i--) {
					if ((abs(G[i] - G[i-1]) < abs2) || G[i] == -INFINITY || G[i] == INFINITY ) //it+1 && (max>G[i-1])
						w += 1;
				}
				
				if (w >= 10) {
					i = 10;
					if (((G[i] - G[i-2]) < abs2) && ((G[i-2] - G[i-4]) < abs2) && ((G[i-4] - G[i-5]) < abs2) && ((G[i - 5] - G[i - 6]) < abs2) && ((G[i - 6] - G[i - 8]) < abs2) && ((G[i - 8] - G[i-10]) < abs2)) {//0 2 4 5 6 8 10
						ww = 1;
					}
					if (((G[i] - G[i - 2]) < abs2) && ((G[i - 2] - G[i - 4]) < abs2) && ((G[i - 4] - G[i - 6]) < abs2) && ((G[i - 6] - G[i - 8]) < abs2) && ((G[i - 8] - G[i - 10]) < abs2)) {//0 2 4 6 8 10
						ww = 2;
					}
					if (((G[i] - G[i - 5]) < abs2) && ((G[i - 5] - G[i - 6]) < abs2) && ((G[i - 6] - G[i - 8]) < abs2) && ((G[i - 8] - G[i - 10]) < abs2)) {//0 2 4 5 10
						ww = 3;
					}
					if (((G[i] - G[i - 2]) < abs2) && ((G[i - 2] - G[i - 4]) < abs2) && ((G[i - 4] - G[i - 5]) < abs2) && ((G[i - 5] - G[i - 10]) < abs2)) {//0 5 6 8 10
						ww = 4;
					}
					if (((G[i] - G[i - 5]) < abs2) && ((G[i - 5] - G[i - 10]) < abs2)) {//0 5 10
						ww = 5;
					}
					if ((G[i] - G[i - 10]) < abs2) {//0 10
						ww = 6;
					}
					switch (ww)
					{
					case 1: {
						myvector1.erase(it - 1);  
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 2);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 5);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 6);
						it = myvector1.end() - 1 - t;
						break;
					}
					case 2: {
						myvector1.erase(it - 1);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 2);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 3);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 4);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 5);
						it = myvector1.end() - 1 - t;
						break;
					}
					case 3: {
						myvector1.erase(it - 1);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 1);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 1);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 1);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 3);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 4);
						it = myvector1.end() - 1 - t;
						break;
					}
					case 4: {
						myvector1.erase(it - 1);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 2);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 4);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 4);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 4);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 4);
						it = myvector1.end() - 1 - t;
						break;
					}
					case 5: {
						myvector1.erase(it - 1);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 1);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 1);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 1);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 2);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 2);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 2);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 2);
						it = myvector1.end() - 1 - t;
						break;
					}
					case 6: {
						myvector1.erase(it - 1);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 1);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 1);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 1);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 1);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 1);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 1);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 1);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 1);
						it = myvector1.end() - 1 - t;
						break;
					}
					default:
						break;
					}
				}
				
				int w = 0;
				int ww = 0;
				for (i = 0; i < 10; i++) {
					if (F(*(it - i - 1)) == -INFINITY) { w += 1; }
					if (abs(F(*(it - i)) - F(*(it - i - 1))) < abs2) //it+1
						w += 1;
				}
				if (w == 10) {
					if (((F(*it) - F(*(it - 2))) < abs2) && ((F(*(it - 2)) - F(*(it - 4))) < abs2) && ((F(*(it - 4)) - F(*(it - 6))) < abs2) && ((F(*(it - 6)) - F(*(it - 8))) < abs2) && ((F(*(it - 8)) - F(*(it - 10))) < abs2)) {
						ww = 1;
					}
					if (((F(*it) - F(*(it - 5))) < abs2) && ((F(*(it - 5)) - F(*(it - 6))) < abs2) && ((F(*(it - 6)) - F(*(it - 10))) < abs2)) {
						ww = 2;
					}
					if (((F(*it) - F(*(it - 5))) < abs2) && ((F(*(it - 5)) - F(*(it - 8))) < abs2) && ((F(*(it - 8)) - F(*(it - 10))) < abs2)) {
						ww = 3;
					}
					if (((F(*it) - F(*(it - 4))) < abs2) && ((F(*(it - 4)) - F(*(it - 5))) < abs2) && ((F(*(it - 5)) - F(*(it - 10))) < abs2)) {
						ww = 4;
					}
					if (((F(*it) - F(*(it - 2))) < abs2) && ((F(*(it - 2)) - F(*(it - 5))) < abs2) && ((F(*(it - 5)) - F(*(it - 10))) < abs2)) {
						ww = 5;
					}
					if (((F(*it) - F(*(it - 5))) < abs2) && ((F(*(it - 5)) - F(*(it - 10))) < abs2)) {
						ww = 6;
					}
					if ((F(*it) - F(*(it - 10))) < abs2 || (F(*(it - 10)) == -INFINITY)) {
						ww = 7;
					}
					switch (ww)
					{
					case 1: {
						myvector1.erase(it - 1);  
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 2);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 3);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 4);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 5);
						it = myvector1.end() - 1 - t;
						break;
					}
					case 2: {
						myvector1.erase(it - 1);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 1);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 1);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 1);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 3);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 3);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 3);
						it = myvector1.end() - 1 - t;

						break;
					}
					case 3: {
						myvector1.erase(it - 1);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 1);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 1);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 1);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 2);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 2);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 3);
						it = myvector1.end() - 1 - t;

						break;
					}
					case 4: {
						myvector1.erase(it - 1);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 1);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 1);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 3);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 3);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 3);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 3);
						it = myvector1.end() - 1 - t;

						break;
					}
					case 5: {
						myvector1.erase(it - 1);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 2);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 2);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 3);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 3);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 3);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 3);
						it = myvector1.end() - 1 - t;
						break;
					}
					case 6: {
						myvector1.erase(it - 1);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 1);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 1);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 1);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 2);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 2);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 2);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 2);
						it = myvector1.end() - 1 - t;

						break;
					}
					case 7: {
						myvector1.erase(it - 1);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 1);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 1);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 1);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 1);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 1);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 1);
						it = myvector1.end() - 1 - t;
						myvector1.erase(it - 1);
						it = myvector1.end() - 1 - t;
						break;
					}
					default:
						break;
					}
				}
				else {
	
					
					for (i = 1; i < myvector1.size() - 1; i++) {
						it = myvector1.end() - 1 - i; 
						if (*it >= max) {
							myvector1.erase(it + 1);
							i = i - 1;
						}
					}
					abs2 = abs((F(*(myvector1.end() - 1)) - F(min))*sig);//abs2 = abs((F(*(myvector1.end()-1))-F(*myvector1.begin()))*0.3);
	
				}
				
				
				for (i = 1; i < myvector1.size() - 1; i++) {
					it = myvector1.end() - 1 - i; 
					if (*it >= max) {
						myvector1.erase(it + 1);
						i = i - 1;
					}
				}
				abs2 = abs((F(*(myvector1.end()-1)) - F(min))) * sig;
				
				it = myvector1.end() - 1 - t; 
				v = v / 10; 
				
				
			}
			else {
				it -= 1;
				t += 1;  
				if (*it != myvector1.front()) { 
					v = abs((*(it)-*(it - 1)) / 10);  
				}
				
			}
			
		} while (*it != myvector1.front());
		myvector1.shrink_to_fit();

		
		if (min > 0) {
			myvector1.insert(myvector1.begin(), min);
			for (i = 1; i < myvector1.size(); i++) {
				it = myvector1.begin() + i; 
				if (*it < min) {
					myvector1.erase(it);
					i = i - 1;
				}
			}
		}
	}
	if (min <0) {
		
		myvector1.push_back(-v);
		myvector1.push_back(0);
		it = myvector1.begin();
		v = 10;
		
		do {
			
			if (abs(F(*it) - F(*(it + 1))) > abs2) {
				for (i = 1; i < 10; ++i) {
					myvector1.insert(myvector1.begin() + i + t, *(myvector1.begin() + t) + i*(v));
				}
				
				it = myvector1.begin() + t; 

				int w = 0;
				int ww = 0;
				for (i = 0; i < 10; i++) {
					if (abs(F(*(it + i)) - F(*(it + i + 1))) < abs2) //it+1
						w += 1;
				}
				if (w == 10) {
					if (((F(*it) - F(*(it + 2))) < abs2) && ((F(*(it + 2)) - F(*(it + 4))) < abs2) && ((F(*(it + 4)) - F(*(it + 6))) < abs2) && ((F(*(it + 6)) - F(*(it + 8))) < abs2) && ((F(*(it + 8)) - F(*(it + 10))) < abs2)) {
						ww = 1;
					}
					if (((F(*it) - F(*(it + 5))) < abs2) && ((F(*(it + 5)) - F(*(it + 6))) < abs2) && ((F(*(it + 6)) - F(*(it + 10))) < abs2)) {
						ww = 2;
					}
					if (((F(*it) - F(*(it + 5))) < abs2) && ((F(*(it + 5)) - F(*(it + 8))) < abs2) && ((F(*(it + 8)) - F(*(it + 10))) < abs2)) {
						ww = 3;
					}
					if (((F(*it) - F(*(it + 4))) < abs2) && ((F(*(it + 4)) - F(*(it + 5))) < abs2) && ((F(*(it + 5)) - F(*(it + 10))) < abs2)) {
						ww = 4;
					}
					if (((F(*it) - F(*(it + 2))) < abs2) && ((F(*(it + 2)) - F(*(it + 5))) < abs2) && ((F(*(it + 5)) - F(*(it + 10))) < abs2)) {
						ww = 5;
					}
					if (((F(*it) - F(*(it + 5))) < abs2) && ((F(*(it + 5)) - F(*(it + 10))) < abs2)) {
						ww = 6;
					}
					if ((F(*it) - F(*(it - 10))) < abs2) {
						ww = 7;
					}
					switch (ww)
					{
					case 1: {
						myvector1.erase(it + 1);
						it = myvector1.begin(); 
						myvector1.erase(it + 2);
						it = myvector1.begin(); 
						myvector1.erase(it + 3);
						it = myvector1.begin();
						myvector1.erase(it + 4);
						it = myvector1.begin();
						myvector1.erase(it + 5);
						it = myvector1.begin();
						break;
					}
					case 2: {
						myvector1.erase(it + 1);
						it = myvector1.begin();
						myvector1.erase(it + 1);
						it = myvector1.begin();
						myvector1.erase(it + 1);
						it = myvector1.begin();
						myvector1.erase(it + 1);
						it = myvector1.begin();
						myvector1.erase(it + 3);
						it = myvector1.begin();
						myvector1.erase(it + 3);
						it = myvector1.begin();
						myvector1.erase(it + 3);
						it = myvector1.begin();
						break;
					}
					case 3: {
						myvector1.erase(it + 1);
						it = myvector1.begin();
						myvector1.erase(it + 1);
						it = myvector1.begin();
						myvector1.erase(it + 1);
						it = myvector1.begin();
						myvector1.erase(it + 1);
						it = myvector1.begin();
						myvector1.erase(it + 2);
						it = myvector1.begin();
						myvector1.erase(it + 2);
						it = myvector1.begin();
						myvector1.erase(it + 3);
						it = myvector1.begin();
						break;
					}
					case 4: {
						myvector1.erase(it + 1);
						it = myvector1.begin();
						myvector1.erase(it + 1);
						it = myvector1.begin();
						myvector1.erase(it + 1);
						it = myvector1.begin();
						myvector1.erase(it + 3);
						it = myvector1.begin();
						myvector1.erase(it + 3);
						it = myvector1.begin();
						myvector1.erase(it + 3);
						it = myvector1.begin();
						myvector1.erase(it + 3);
						it = myvector1.begin();

						break;
					}
					case 5: {
						myvector1.erase(it + 1);
						it = myvector1.begin();
						myvector1.erase(it + 2);
						it = myvector1.begin();
						myvector1.erase(it + 2);
						it = myvector1.begin();
						myvector1.erase(it + 3);
						it = myvector1.begin();
						myvector1.erase(it + 3);
						it = myvector1.begin();
						myvector1.erase(it + 3);
						it = myvector1.begin();
						myvector1.erase(it + 3);
						it = myvector1.begin();
						break;
					}
					case 6: {
						myvector1.erase(it + 1);
						it = myvector1.begin();
						myvector1.erase(it + 1);
						it = myvector1.begin();
						myvector1.erase(it + 1);
						it = myvector1.begin();
						myvector1.erase(it + 1);
						it = myvector1.begin();
						myvector1.erase(it + 2);
						it = myvector1.begin();
						myvector1.erase(it + 2);
						it = myvector1.begin();
						myvector1.erase(it + 2);
						it = myvector1.begin();
						myvector1.erase(it + 2);
						it = myvector1.begin();
						break;
					}
					default:
						break;
					}
				}
				else {
					
					for (i = 1; i < myvector1.size() - 1; i++) {
						it = myvector1.begin() + i; 
						if (*it <= min) {
							myvector1.erase(it - 1);
							i = i - 1;
						}
					}
					abs2 = abs(F(*myvector1.begin()) * 1);
				}
				it = myvector1.begin() + t; 
				v = v / 10;
				
			}
			else {
				it += 1;
				t += 1; 
				if (*it != myvector1.back()) {  
					v = abs((*(it)-*(it + 1)) / 10); 
				}
			}
			
		} while (*it != myvector1.back());


		myvector1.shrink_to_fit();
	}
	
	return myvector1;
}

HPEN ChosePen(const char(*color), const char(*style)) {
	HPEN hPen;
	if (color == "red") {
		if (style == "solid") {
			hPen = CreatePen(PS_SOLID, 0, RGB(255, 0, 0));
		}
		else if (style == "dash") {
			hPen = CreatePen(PS_DASH, 0, RGB(255, 0, 0));
		}
		else if (style == "dot") {
			hPen = CreatePen(PS_DOT, 0, RGB(255, 0, 0));
		}
		else if (style == "dashdot") {
			hPen = CreatePen(PS_DASHDOT, 0, RGB(255, 0, 0));
		}
	}
	if (color == "green") {
		if (style == "solid") {
			hPen = CreatePen(PS_SOLID, 0, RGB(0, 255, 0));
		}
		else if (style == "dash") {
			hPen = CreatePen(PS_DASH, 0, RGB(0, 255, 0));
		}
		else if (style == "dot") {
			hPen = CreatePen(PS_DOT, 0, RGB(0, 255, 0));
		}
		else if (style == "dashdot") {
			hPen = CreatePen(PS_DASHDOT, 0, RGB(0, 255, 0));
		}
	}
	if (color == "blue") {
		if (style == "solid") {
			hPen = CreatePen(PS_SOLID, 0, RGB(0, 0, 255));
		}
		else if (style == "dash") {
			hPen = CreatePen(PS_DASH, 0, RGB(0, 0, 255));
		}
		else if (style == "dot") {
			hPen = CreatePen(PS_DOT, 0, RGB(0, 0, 255));
		}
		else if (style == "dashdot") {
			hPen = CreatePen(PS_DASHDOT, 0, RGB(0, 0, 255));
		}
	}
	if (color == "black") {
		if (style == "solid") {
			hPen = CreatePen(PS_SOLID, 0, 0);
		}
		else if (style == "dash") {
			hPen = CreatePen(PS_DASH, 0, 0);
		}
		else if (style == "dot") {
			hPen = CreatePen(PS_DOT, 0, 0);
		}
		else if (style == "dashdot") {
			hPen = CreatePen(PS_DASHDOT, 0, 0);
		}
	}
	return hPen;
}

void ShowGraph(HDC hdc, vector<double>myvector, double(*F)(double x), double sx, double sy, int GraphWidth, int GraphHeight, const char(*color), const char(*style)) {
	int i;
	
	HPEN hPen = ChosePen(color, style);
	SelectObject(hdc, hPen);
	if (::logx && !(::logy)) { 
		double X1 = (log10(myvector.front()) - log10(::osx.front()))*GraphWidth / sx; 
		double Y1 = (F(myvector.front()) - ::osy.front())*GraphHeight / sy;
		MoveToEx(hdc, X1, Y1, NULL);
		for (i = 0; i < myvector.size(); i++)
		{
			double X = int((log10(myvector[i]) - log10(::osx.front()))*GraphWidth / sx) + 0.5; 
			double Y = int((F(myvector[i]) - ::osy.front())*GraphHeight / sy) + 0.5;
			LineTo(hdc, X, Y);
		}
	}
	else if (::logy && !(::logx)) { 
		double X1 = (myvector.front() - ::osx.front())*GraphWidth / sx; 
		double Y1 = (log10(F(myvector.front())) - log10(::osy.front()))*GraphHeight / sy;
		MoveToEx(hdc, X1, Y1, NULL);
		for (i = 0; i < myvector.size(); i++)
		{
			double X = int((myvector[i] - ::osx.front())*GraphWidth / sx) + 0.5;  
			double Y = int((log10(F(myvector[i])) - log10(::osy.front()))*GraphHeight / sy) + 0.5;
			LineTo(hdc, X, Y);
		}
	}
	else if (::logx && ::logy) { 
		double X1 = (log10(myvector.front()) - log10(::osx.front()))*GraphWidth / sx;  
		double Y1 = (log10(F(myvector.front())) - log10(::osy.front()))*GraphHeight / sy;
		MoveToEx(hdc, X1, Y1, NULL);
		for (i = 0; i < myvector.size(); i++)
		{
			double X = int((log10(myvector[i]) - log10(::osx.front()))*GraphWidth / sx) + 0.5; 
			double Y = int((log10(F(myvector[i])) - log10(::osy.front()))*GraphHeight / sy) + 0.5;
			LineTo(hdc, X, Y);
		}
	}
	else { 
		double X1 = (myvector.front() - ::osx.front())*GraphWidth / sx;  
		double Y1 = (F(myvector.front()) - ::osy.front())*GraphHeight / sy;
		MoveToEx(hdc, X1, Y1, NULL);
		for (i = 0; i < myvector.size(); i++)
		{
			double X = int((myvector[i] - ::osx.front())*GraphWidth / sx) + 0.5;  
			double Y = int((F(myvector[i]) - ::osy.front())*GraphHeight / sy) + 0.5;
			LineTo(hdc, X, Y);
		}
	}
}


void Mark(HDC hdc, PAINTSTRUCT ps, double **y, double min_x, double min_y, int n, double GraphWidth, double GraphHeight, double sx, double sy) {
	static HBRUSH hrect;
	int MARK = 2; 
	hrect = CreateSolidBrush(RGB(255, 0, 0));
	for (int i = 0; i < n; i++)
	{
		//int c =sign(i);
		double X = int((y[0][i] - min_x)*GraphWidth / sx + 0.5);
		double Y = int((y[1][i] - min_y)*GraphHeight / sy + 0.5);
		SetRect(&ps.rcPaint, int(X - MARK), int(Y - MARK), int(X + MARK), int(Y + MARK));
		
		FillRect(hdc, &ps.rcPaint, hrect);
	}
}


void vivod1(vector<double>vec1, double(*F)(double x), const char (*la1) = " ", const char (*la2)=" ") {
	int i;
	int scale = 2;
	WCHAR s[100];
	double min_x, max_x, min_y, max_y;
	min_x = max_x = vec1.front();
	min_y = max_y = F(vec1.front());
	int n = vec1.size();
	for (i = 1; i < vec1.size(); i++)
	{
		if (vec1[i] > max_x) max_x = vec1[i];
		else if (vec1[i] < min_x) min_x = vec1[i];
		if (F(vec1[i]) > max_y) max_y = F(vec1[i]);
		else if (F(vec1[i]) < min_y) min_y = F(vec1[i]);
	}
	double n1, n2, u01, un1, g1, g2, h, k1, k2max,k2min, z;
	int n3, p, k0, k2, v;
	int pp = 0;
	int pp1 = 0;
	
	
	if (la1 == "logx" || la2 == "logx") {
		::logx = true;
		k2max=k2min = 1;
		while (k2max < max_x) { k2max = k2max * 10; pp1++; }
		while (k2min > min_x) { k2min = k2min / 10; pp1--; }
		double tt=k2min;
		while (tt != k2max) {
			::osx.push_back(tt);
			tt = tt * 10;
		}
		::osx.push_back(tt);
	}
	else {
		
		::osx = algor(F, min_x, max_x);     
	}
	

	
	if (la1 == "logy" || la2 == "logy") {
		::logy = true;
		k2max = k2min = 1;
		while (k2max < max_y) { k2max = k2max * 10; pp1++; }
		while (k2min > min_y) { k2min = k2min / 10; pp1--; }
		double tt = k2min;
		while (tt != k2max) {
			::osy.push_back(tt);
			tt = tt * 10;
		}
		::osy.push_back(tt);
	}
	else {
		scale = 5;
		h = (max_y - min_y) / scale; 
		k1 = 1;
		while (k1 < h) { k1 = k1 * 10; pp++; }
		while (k1 > h) { k1 = k1 / 10; pp--; }

		if (5 * k1 <= h) { k1 = k1 * 5; }
		else if (2 * k1 <= h) { k1 = 2 * k1; }

		g1 = k1;
	
		min_y = (floor(min_y / g1))*g1; max_y = (ceil(max_y / g1))*g1;  n1 = (max_y - min_y) / g1;
		n3 = n1;
		n1 = (max_y - min_y) / n3;
		n3 += 1; 
		for (z = min_y, i = 0; i < n3; z += n1, i++) {
			::osy.push_back(z);
		} 
	}
}

	
	void vivod1(vector<double> vec1, vector<double> vec2, double(*F)(double x1, double x2)) {
		int i;
		int scale = 5;
		WCHAR s[100];
		double min_x, max_x, min_y, max_y,min_x1,max_x1;
		min_x = max_x = vec1.front();
		min_x1 = max_x1 = vec2.front();
		min_y = max_y = F(vec1.front(), vec2.front());
		int n = vec1.size();
		for (i = 1; i < vec1.size(); i++)
		{
			if (vec1[i] > max_x) max_x = vec1[i];
			else if (vec1[i] < min_x) min_x = vec1[i];
			if (vec2[i] > max_x1) max_x1 = vec2[i];
			else if (vec2[i] < min_x1) min_x1 = vec2[i];
			if (F(vec1[i], vec2[i]) > max_y) max_y = F(vec1[i], vec2[i]);
			else if (F(vec1[i], vec2[i]) < min_y) min_y = F(vec1[i], vec2[i]);
		}
		double n1, n2, u01, un1, g1, g2, h, k1, k2max, k2min, z;
		int n3, p, k0, k2, v;
		int pp = 0;
		int pp1 = 0;

	
	
	h = (max_x - min_x) / scale; 

	k1 = 1;
	while (k1 < h) { k1 = k1 * 10; pp++; }
	while (k1 > h) { k1 = k1 / 10; pp--; }

	if (5 * k1 <= h) { k1 = k1 * 5; }
	else if (2 * k1 <= h) { k1 = 2 * k1; }

	g1 = k1;
	
	min_x = (floor(min_x / g1))*g1; max_x = (ceil(max_x / g1))*g1;  n1 = (max_x - min_x) / g1;
	n3 = n1;
	n1 = (max_x - min_x) / n3;
	n3 += 1; 
	for (z = min_x, i = 0; i < n3; z += n1, i++) {
		::osx.push_back(z);
	}


										 
	h = (max_x1 - min_x1) / scale;

	k1 = 1;
	while (k1 < h) { k1 = k1 * 10; pp++; }
	while (k1 > h) { k1 = k1 / 10; pp--; }

	if (5 * k1 <= h) { k1 = k1 * 5; }
	else if (2 * k1 <= h) { k1 = 2 * k1; }
	
	g1 = k1;
	
	min_x = (floor(min_x / g1))*g1; max_x = (ceil(max_x / g1))*g1;  n1 = (max_x - min_x) / g1;
	n3 = n1;
	n1 = (max_x - min_x) / n3;
	n3 += 1; 
	for (z = min_x, i = 0; i < n3; z += n1, i++) {
		::osx1.push_back(z);
	}
												 
				


	scale = 5;
	h = (max_y - min_y) / scale; 
	
	k1 = 1;
	while (k1 < h) { k1 = k1 * 10; pp++; }
	while (k1 > h) { k1 = k1 / 10; pp--; }

	if (5 * k1 <= h) { k1 = k1 * 5; }
	else if (2 * k1 <= h) { k1 = 2 * k1; }

	g1 = k1;
	
	min_y = (floor(min_y / g1))*g1; max_y = (ceil(max_y / g1))*g1;  n1 = (max_y - min_y) / g1;
	n3 = n1;
	n1 = (max_y - min_y) / n3;
	n3 += 1; 
	
	for (z = min_y, i = 0; i < n3; z += n1, i++) {
		::osy.push_back(z);
	}
				
}
		


	
void vivod1(vector<double>vec1, double(*F)(double x), double(*F1)(double x), const char(*la1) = " ", const char(*la2) = " ") {
	
	int i;
	int scale = 2;
	WCHAR s[100];
	double min_x, max_x, min_y, max_y, min_y1, max_y1;
	min_x = max_x = vec1.front();
	min_y = max_y = F(vec1.front());
	min_y1 = max_y1 = F1(vec1.front());
	int n = vec1.size();
	for (i = 1; i < vec1.size(); i++)
	{
		if (vec1[i] > max_x) max_x = vec1[i];
		else if (vec1[i] < min_x) min_x = vec1[i];
		if (F(vec1[i]) > max_y) max_y = F(vec1[i]);
		else if (F(vec1[i]) < min_y) min_y = F(vec1[i]);
		if (F1(vec1[i]) > max_y1) max_y1 = F1(vec1[i]);
		else if (F1(vec1[i]) < min_y1) min_y1 = F1(vec1[i]);
	}
	if (min_y1 < min_y) min_y = min_y1;
	if (max_y1 > max_y)max_y = max_y1;
	double n1, n2, u01, un1, g1, g2, h, k1, k2max, k2min, z;
	int n3, p, k0, k2, v;
	int pp = 0;
	int pp1 = 0;

	
	if (la1 == "logx" || la2 == "logx") {
		::logx = true;
		k2max = k2min = 1;
		while (k2max < max_x) { k2max = k2max * 10; pp1++; }
		while (k2min > min_x) { k2min = k2min / 10; pp1--; }
		double tt = k2min;
		while (tt != k2max) {
			::osx.push_back(tt);
			tt = tt * 10;
		}
		::osx.push_back(tt);
	}
	else {
		::osx = algor(F1, min_x, max_x);   
		/*swprintf_s(s, TEXT("%.1lf"), min_x);
		TextOut(hdc, 100, 100, s, lstrlen(s));
		swprintf_s(s, TEXT("%.1lf"), max_x);
		TextOut(hdc, 200, 200, s, lstrlen(s));*/
	}

	

	if (la1 == "logy" || la2 == "logy") {
		::logy = true;
		k2max = k2min = 1;
		while (k2max < max_y) { k2max = k2max * 10; pp1++; }
		while (k2min > min_y) { k2min = k2min / 10; pp1--; }
		double tt = k2min;
		while (tt != k2max) {
			::osy.push_back(tt);
			tt = tt * 10;
		}
		::osy.push_back(tt);
	}
	else {
		scale = 5;
		h = (max_y - min_y) / scale; 

		k1 = 1;
		while (k1 < h) { k1 = k1 * 10; pp++; }
		while (k1 > h) { k1 = k1 / 10; pp--; }

		if (5 * k1 <= h) { k1 = k1 * 5; }
		else if (2 * k1 <= h) { k1 = 2 * k1; }
		
		g1 = k1;
		
		min_y = (floor(min_y / g1))*g1; max_y = (ceil(max_y / g1))*g1;  n1 = (max_y - min_y) / g1;
		n3 = n1;
		n1 = (max_y - min_y) / n3;
		n3 += 1; 
		for (z = min_y, i = 0; i < n3; z += n1, i++) {
			::osy.push_back(z);
		}
	}
}

void DrawGraph2(HDC hdc, PAINTSTRUCT ps, vector<double> myvector, double(*F)(double x), const char(*color) = "black", const char(*style) = "solid") {
	int i;
	vector<double>::iterator it;
	double min_x, max_x, min_y, max_y;
	int xView = ps.rcPaint.right - ps.rcPaint.left;
	int yView = ps.rcPaint.bottom - ps.rcPaint.top;
	int GraphWidth = xView - 100;
	int GraphHeight = yView - 50;

	SetMapMode(hdc, MM_ANISOTROPIC);
	SetWindowExtEx(hdc, xView, yView, NULL); 
	SetViewportExtEx(hdc, xView, -yView, NULL); 
	SetViewportOrgEx(hdc, 50, yView - 25, NULL); 

	MoveToEx(hdc, 0, 0, NULL);
	LineTo(hdc, 0, GraphHeight)/о;
	LineTo(hdc, GraphWidth, GraphHeight);

	MoveToEx(hdc, 0, 0, NULL);
	LineTo(hdc, GraphWidth, 0);//ось Х
	LineTo(hdc, GraphWidth, GraphHeight);

	MoveToEx(hdc, 0, 0, NULL); 

	HPEN hPen; 
	hPen = CreatePen(PS_SOLID, 0, 0);
	SelectObject(hdc, hPen);
	WCHAR s[100];

	double sx = abs(::osx.back() - ::osx.front());
	double sy = abs(::osy.back() - ::osy.front());

	HFONT hFont = CreateFont(15, 0, 0, 0, 0, 0, 0, 0, 
		DEFAULT_CHARSET,
		0, 0, 0, 0,
		L"Arial Bold"
	);
	SelectObject(hdc, hFont);
	
	it = ::osx.begin();
	if (::logx) { 
		sx = abs(log10(::osx.back()) - log10(::osx.front()));
		for (i = 0; i < ::osx.size(); i++) {
			int x = int((log10(*it) - log10(::osx.front()))*GraphWidth / sx + 0.5);
			swprintf_s(s, TEXT("%.1lf"), *it);
			TextOut(hdc, x - 5, -10, s, lstrlen(s));
			MoveToEx(hdc, x, 0, NULL);
			LineTo(hdc, x, -10);
			it += 1;
		}
	}
	else {
		for (i = 0; i < ::osx.size(); i++) {
			int x = int((*it - ::osx.front())*GraphWidth / sx + 0.5);
			swprintf_s(s, TEXT("%.1lf"), *it);
			TextOut(hdc, x - 5, -10, s, lstrlen(s));
			MoveToEx(hdc, x, 0, NULL);
			LineTo(hdc, x, -10);
			it += 1;
		}
	}
	
	it = ::osy.begin();
	if (::logy) { 
		sy = abs(log10(::osy.back()) - log10(::osy.front()));
		for (i = 0; i < ::osy.size(); i++) {
			int x = int((log10(*it) - log10(::osy.front()))*GraphHeight / sy + 0.5);
			swprintf_s(s, TEXT("%.1lf"), *it);
			TextOut(hdc, -40, x, s, lstrlen(s));
			MoveToEx(hdc, 0, x, NULL);
			LineTo(hdc, -10, x);
			it += 1;
		}
	}
	else {
		for (i = 0; i < ::osy.size(); i++) {
			int x = int((*it - ::osy.front())*GraphHeight / sy + 0.5);
			swprintf_s(s, TEXT("%.1lf"), *it);
			TextOut(hdc, -40, x, s, lstrlen(s));
			MoveToEx(hdc, 0, x, NULL);
			LineTo(hdc, -10, x);
			it += 1;
		}
	}


	
	::pen1 = ChosePen(color, style);
	ShowGraph(hdc, myvector, F, sx, sy, GraphWidth, GraphHeight,color,style);

}


void DrawGraph2(HDC hdc, PAINTSTRUCT ps, vector<double> myvector, double(*F)(double x), double(*F1)(double x), const char(*color) = "black", const char(*color1) = "black", const char(*style) = "solid", const char(*style1) = "solid") {
	int i;
	vector<double>::iterator it;
	double min_x, max_x, min_y, max_y;
	int xView = ps.rcPaint.right - ps.rcPaint.left;
	int yView = ps.rcPaint.bottom - ps.rcPaint.top;
	int GraphWidth = xView - 100;
	int GraphHeight = yView - 50;

	SetMapMode(hdc, MM_ANISOTROPIC);
	SetWindowExtEx(hdc, xView, yView, NULL);
	SetViewportExtEx(hdc, xView, -yView, NULL); 
	SetViewportOrgEx(hdc, 50, yView - 25, NULL);

	MoveToEx(hdc, 0, 0, NULL);
	LineTo(hdc, 0, GraphHeight);
	LineTo(hdc, GraphWidth, GraphHeight);

	MoveToEx(hdc, 0, 0, NULL);
	LineTo(hdc, GraphWidth, 0);
	LineTo(hdc, GraphWidth, GraphHeight);

	MoveToEx(hdc, 0, 0, NULL)

	HPEN hPen; //создаём перо
	hPen = CreatePen(PS_SOLID, 0, 0);
	SelectObject(hdc, hPen);
	WCHAR s[100];

	double sx = abs(::osx.back() - ::osx.front());
	double sy = abs(::osy.back() - ::osy.front());

	
	HFONT hFont = CreateFont(15, 0, 0, 0, 0, 0, 0, 0, 
		DEFAULT_CHARSET,
		0, 0, 0, 0,
		L"Arial Bold"
	);
	SelectObject(hdc, hFont);
	it = ::osx.begin();
	if (::logx) { 
		sx = abs(log10(::osx.back()) - log10(::osx.front()));
		for (i = 0; i < ::osx.size(); i++) {
			int x = int((log10(*it) - log10(::osx.front()))*GraphWidth / sx + 0.5);
			swprintf_s(s, TEXT("%.1lf"), *it);
			TextOut(hdc, x - 5, -10, s, lstrlen(s));
			MoveToEx(hdc, x, 0, NULL);
			LineTo(hdc, x, -10);
			it += 1;
		}
	}
	else {
		for (i = 0; i < ::osx.size(); i++) {
			int x = int((*it - ::osx.front())*GraphWidth / sx + 0.5);
			swprintf_s(s, TEXT("%.1lf"), *it);
			TextOut(hdc, x - 5, -10, s, lstrlen(s));
			MoveToEx(hdc, x, 0, NULL);
			LineTo(hdc, x, -10);
			it += 1;
		}
	}
	
	it = ::osy.begin();
	if (::logy) { 
		sy = abs(log10(::osy.back()) - log10(::osy.front()));
		for (i = 0; i < ::osy.size(); i++) {
			int x = int((log10(*it) - log10(::osy.front()))*GraphHeight / sy + 0.5);
			swprintf_s(s, TEXT("%.1lf"), *it);
			TextOut(hdc, -40, x, s, lstrlen(s));
			MoveToEx(hdc, 0, x, NULL);
			LineTo(hdc, -10, x);
			it += 1;
		}
	}
	else {
		for (i = 0; i < ::osy.size(); i++) {
			int x = int((*it - ::osy.front())*GraphHeight / sy + 0.5);
			swprintf_s(s, TEXT("%.1lf"), *it);
			TextOut(hdc, -40, x, s, lstrlen(s));
			MoveToEx(hdc, 0, x, NULL);
			LineTo(hdc, -10, x);
			it += 1;
		}
	}


	
	::pen1 = ChosePen(color, style);
	::pen2 = ChosePen(color1, style1);
	ShowGraph(hdc, myvector, F, sx, sy,GraphWidth,GraphHeight,color,style);
	ShowGraph(hdc, myvector, F1, sx, sy, GraphWidth, GraphHeight,color1,style1);
}


void DrawGraph2(HDC hdc, PAINTSTRUCT ps, vector<double> myvector, vector<double> myvector1, double(*F)(double x,double x1), const char(*color) = "black", const char(*style) = "solid") {
	int i;
	vector<double>::iterator it;
	double min_x, max_x, min_y, max_y;
	::xView = ps.rcPaint.right - ps.rcPaint.left;
	::yView = ps.rcPaint.bottom - ps.rcPaint.top;
	int GraphWidth = xView - 100;
	int GraphHeight = yView - 50;

	SetMapMode(hdc, MM_ANISOTROPIC);
	SetWindowExtEx(hdc, xView, yView, NULL); 
	SetViewportExtEx(hdc, xView, -yView, NULL);
	SetViewportOrgEx(hdc, 50, yView - 45, NULL);
	MoveToEx(hdc, 0, 0, NULL);
	LineTo(hdc, 0, GraphHeight);
	LineTo(hdc, GraphWidth, GraphHeight);

	MoveToEx(hdc, 0, 0, NULL);
	LineTo(hdc, GraphWidth, 0);
	LineTo(hdc, GraphWidth, GraphHeight);

	MoveToEx(hdc, 0, -20, NULL);
	LineTo(hdc, GraphWidth, -20);

	MoveToEx(hdc, 0, 0, NULL); 

	HPEN hPen; 
	hPen = CreatePen(PS_SOLID, 0, 0);
	SelectObject(hdc, hPen);
	WCHAR s[100];

	double sx = abs(::osx.back() - ::osx.front());
	double sx1 = abs(::osx1.back() - ::osx1.front());
	double sy = abs(::osy.back() - ::osy.front());

	HFONT hFont = CreateFont(15, 0, 0, 0, 0, 0, 0, 0, 
		DEFAULT_CHARSET,
		0, 0, 0, 0,
		L"Arial Bold"
	);
	SelectObject(hdc, hFont);
	
	it = ::osx.begin();
		for (i = 0; i < ::osx.size(); i++) {
			int x = int((*it - ::osx.front())*GraphWidth / sx + 0.5);
			swprintf_s(s, TEXT("%.1lf"), *it);
			TextOut(hdc, x - 5, -10, s, lstrlen(s));
			MoveToEx(hdc, x, 0, NULL);
			LineTo(hdc, x, -10);
			it += 1;
		}

		it = ::osx1.begin();
		for (i = 0; i < ::osx1.size(); i++) {
			int x = int((*it - ::osx1.front())*GraphWidth / sx1 + 0.5);
			swprintf_s(s, TEXT("%.1lf"), *it);
			TextOut(hdc, x - 5, -30, s, lstrlen(s));
			MoveToEx(hdc, x, -20, NULL);
			LineTo(hdc, x, -30);
			it += 1;
		}
	
	it = ::osy.begin();
	
		for (i = 0; i < ::osy.size(); i++) {
			int x = int((*it - ::osy.front())*GraphHeight / sy + 0.5);
			swprintf_s(s, TEXT("%.1lf"), *it);
			TextOut(hdc, -40, x, s, lstrlen(s));
			MoveToEx(hdc, 0, x, NULL);
			LineTo(hdc, -10, x);
			it += 1;
		}
	


		hPen = ChosePen(color, style);
		::pen1 = ChosePen(color, style);
		SelectObject(hdc, hPen);

		double X1 = (myvector.front() - ::osx.front())*GraphWidth / sx;  
		double Y1 = (F(myvector.front(), myvector1.front()) - ::osy.front())*GraphHeight / sy;
		MoveToEx(hdc, X1, Y1, NULL);
		for (i = 0; i < myvector.size(); i++)
		{
			double X = int((myvector[i] - ::osx.front())*GraphWidth / sx) + 0.5;  
			double Y = int((F(myvector[i], myvector1[i]) - ::osy.front())*GraphHeight / sy) + 0.5;
			LineTo(hdc, X, Y);
		}
}

void legend(HDC hdc, LPCWSTR name1) {
	int GraphWidth = ::xView - 100;
	int GraphHeight = ::yView - 50;
	WCHAR s[100];

	HPEN hPen = CreatePen(PS_SOLID, 0, 0);
	SelectObject(hdc, hPen);

	SetMapMode(hdc, MM_ANISOTROPIC); 
	SetWindowExtEx(hdc, ::xView, ::yView, NULL); 
	SetViewportExtEx(hdc, ::xView, -::yView, NULL); 
	SetViewportOrgEx(hdc, 50, yView - 25, NULL); 

	double starty = GraphHeight - 70;
	double startx = 20;
	Rectangle(hdc, startx, starty + 50, startx + 150, starty);

	SelectObject(hdc, ::pen1);
	MoveToEx(hdc, startx+10, starty+30, NULL);
	LineTo(hdc, startx + 50, starty + 30);
	swprintf_s(s, TEXT("%s"), name1);
	TextOut(hdc, startx+70, starty+40, s, lstrlen(s));
}


void legend(HDC hdc, LPCWSTR name1, LPCWSTR name2) {
	int GraphWidth = ::xView - 100;
	int GraphHeight = ::yView - 50;
	WCHAR s[100];

	HPEN hPen = CreatePen(PS_SOLID, 0, 0);
	SelectObject(hdc, hPen);

	SetMapMode(hdc, MM_ANISOTROPIC); 
	SetWindowExtEx(hdc, ::xView, ::yView, NULL); 
	SetViewportExtEx(hdc, ::xView, -::yView, NULL); 
	SetViewportOrgEx(hdc, 50, yView - 25, NULL); 

	double starty = GraphHeight - 100;
	double startx = 20;
	Rectangle(hdc, startx, starty + 80, startx + 150, starty);

	SelectObject(hdc, ::pen1);
	MoveToEx(hdc, startx + 10, starty + 30, NULL);
	LineTo(hdc, startx + 50, starty + 30);

	SelectObject(hdc, ::pen2);
	MoveToEx(hdc, startx + 10, starty + 50, NULL);
	LineTo(hdc, startx + 50, starty + 50);
	swprintf_s(s, TEXT("%s"), name1);
	TextOut(hdc, startx + 70, starty + 40, s, lstrlen(s));
	swprintf_s(s, TEXT("%s"), name2);
	TextOut(hdc, startx + 70, starty + 60, s, lstrlen(s));
}

vector<double> Func(vector<double> vec, double(*F)(double x)) {
	vector<double> resvec;
	for (int i = 0; i < vec.size(); i++) {
		resvec.push_back(F(vec[i]));
	}
	return resvec;
}

void SaveBMP(HDC hdc) {
	BITMAPFILEHEADER bfh; 
	BITMAPINFOHEADER bih;	
	BITMAPINFO bi;	
	void *pdwBits = NULL; 
	DWORD dwWB = 0; 
	HANDLE hFile = NULL; 

	//HBITMAP bmpMem = LoadBitmap(hInstance, MAKEINTRESOURCE(szWinName));
	HBITMAP bmpMem = CreateCompatibleBitmap(hdc, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));

						 
	pdwBits = (void *)GlobalAlloc(GMEM_FIXED, 800 * 600 * 4);

	
	memset(&bfh, 0, sizeof(BITMAPFILEHEADER));
	memset(&bih, 0, sizeof(BITMAPINFOHEADER));
	memset(&bi, 0, sizeof(BITMAPINFO));

	
	bfh.bfType = 0x4D42;                           
	bfh.bfOffBits = sizeof(bfh) + sizeof(bih);
	bfh.bfSize = bfh.bfOffBits + 800 * 600 * 4;   

												
	bih.biSize = sizeof(bih);                      
	bih.biBitCount = 32;                           
	bih.biCompression = BI_RGB;                    
	bih.biHeight = 600;
	bih.biWidth = 800;
	bih.biPlanes = 1;

	
	CopyMemory(&bi, &bih, sizeof(BITMAPINFOHEADER));

	
	GetDIBits(hdc, bmpMem, 0, 600, pdwBits, (LPBITMAPINFO)&bi, DIB_RGB_COLORS);

	
	hFile = CreateFile(L"save.bmp",
		GENERIC_WRITE,
		0,
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		(HANDLE)NULL);
	if (hFile == INVALID_HANDLE_VALUE) {
		if (pdwBits) GlobalFree(pdwBits);
		//SetWindowText(hwndMain, "Ошибка при открытии файла");
		return;
	}


	if (!WriteFile(hFile, (void *)&bfh, sizeof(BITMAPFILEHEADER), &dwWB, NULL)) {
		//SetWindowText(hwndMain, "Ошибка при записи BITMAPFILEHEADER");
		if (pdwBits) GlobalFree(pdwBits);
		return;
	}


	if (!WriteFile(hFile, (void *)&bih, sizeof(BITMAPINFOHEADER), &dwWB, NULL)) {
		//SetWindowText(hwndMain, "Ошибка при записи BITMAPINFOHEADER");
		if (pdwBits) GlobalFree(pdwBits);
		return;
	}


	if (!WriteFile(hFile, (void *)pdwBits, 800 * 600 * 4, &dwWB, NULL)) {
		//SetWindowText(hwndMain, "Ошибка при записи BITMAPINFOHEADER");
		if (pdwBits) GlobalFree(pdwBits);
		return;
	}

	CloseHandle(hFile);
	if (pdwBits) GlobalFree(pdwBits);
	return;
}
void DrawSpline(HDC hdc, PAINTSTRUCT ps, double **y, int n, int scaleX, int scaleY) {

	double *aa = new double[n];
	double *b = new double[n];
	double *c = new double[n];
	double *ha = new double[n];
	double *d = new double[n];
	double *k = new double[n];
	double *l = new double[n];
	double *r = new double[n];
	double *sa = new double[n];
	int i;
	double StepX, StepY;
	double min_x, max_x, min_y, max_y;
	int xView = ps.rcPaint.right - ps.rcPaint.left;
	int yView = ps.rcPaint.bottom - ps.rcPaint.top;
	int GraphWidth = xView - 100;
	int GraphHeight = yView - 50;

	SetMapMode(hdc, MM_ANISOTROPIC); 
	SetWindowExtEx(hdc, xView, yView, NULL); 
	SetViewportExtEx(hdc, xView, -yView, NULL); 
	SetViewportOrgEx(hdc, 50, yView - 25, NULL); 

	MoveToEx(hdc, 0, 0, NULL);
	LineTo(hdc, 0, GraphHeight);
	MoveToEx(hdc, 0, 0, NULL);
	LineTo(hdc, GraphWidth, 0);

	min_x = max_x = y[0][0];
	min_y = max_y = y[1][0];
	for (i = 1; i < n; i++)
	{
		if (y[0][i] > max_x) max_x = y[0][i];
		else if (y[0][i] < min_x) min_x = y[0][i];
		if (y[1][i] > max_y) max_y = y[1][i];
		else if (y[1][i] < min_y) min_y = y[1][i];
	}

	double hx = max_x - min_x;
	double hy = max_y - min_y;

	StepX = hx / scaleX; 
	StepY = hy / scaleY; 


	double sx = vivod(hdc, y, min_x, max_x, n, GraphWidth, 'x');
	double sy = vivod(hdc, y, min_y, max_y, n, GraphHeight, 'y');

	
	double X1 = int((y[0][0] - min_x)*GraphWidth / sx + 0.5);
	double Y1 = int((y[1][0] - min_y)*GraphHeight / sy + 0.5); //(bylo min_y, u0y)
	MoveToEx(hdc, X1, Y1, NULL);

	
	for (i = 2; i <= n - 1; i++) {
		k[1] = 0;
		l[1] = 0;

		ha[i - 1] = y[0][i] - y[0][i - 1];
		ha[i] = y[0][i + 1] - y[0][i];

		sa[i] = 2. * (ha[i] + ha[i - 1]);

		r[i] = 6. * ((y[1][i] - y[1][i - 1]) / ha[i] - (y[1][i - 1] - y[1][i - 2]) / ha[i - 1]); 

		k[i] = (r[i] - ha[i - 1] * k[i - 1]) / (sa[i] + ha[i - 1] * l[i - 1]); //s[i]-

		l[i] = ha[i] / (sa[i] + ha[i - 1] * l[i - 1]); 
	}

	c[n - 1] = k[n - 1];

	for (i = n - 2; i > 0; i--)
		c[i] = k[i] - l[i] * c[i + 1];

	
	for (i = 1; i <= n - 1; i++) {
		ha[i] = y[0][i] - y[0][i - 1];
		aa[i] = y[1][i - 1];
		b[i] = (y[1][i] - y[1][i - 1]) / ha[i] - ha[i] * (2 * c[i] + c[i + 1]) / 6.0;
		d[i] = (c[i + 1] - c[i]) / ha[i];
	}

	i = 1;
	double x1a = y[0][0];
	int x2;
	double y2 = 0;

	static HPEN hline;
	hline = CreatePen(PS_SOLID, 0, RGB(255, 0, 0)); 
	SelectObject(hdc, hline);

	
	do {
		do {
			y2 = aa[i] + b[i] * (x1a - y[0][i - 1]) + c[i] / 2 * pow((x1a - y[0][i - 1]), 2) + d[i] / 6 * pow((x1a - y[0][i - 1]), 3); 
			double XX = int((x1a - min_x)*GraphWidth / sx + 0.5);
			double YY = int((y2 - min_y)*GraphHeight / sy + 0.5); //(bylo y2-min_y)   
			LineTo(hdc, XX, YY);
			x1a = x1a + 0.001;
			x2 = static_cast<int> (x1a);
		} while (x2 != y[0][i]);

		i++;
		x1a = y[0][i - 1];
	} while (i != n);
	DeleteObject(hline);

	
}

void test(vector<double> vec2, double(*F)(double x)) {
	//for (int i = 0; i < 7; i++) {
		//vec1[i] = pow(i + 2, i+2 );
		//::vec3.push_back(i);
		//val.vec2[i] = i;
		//vec1[i] = i;
	//}
	::vec3 = vec2;
	::F10 = F;
}

LRESULT CALLBACK WindowFunc(HWND hwnd, UINT message,
	WPARAM wParam, LPARAM lParam) {
	//create(message);
	switch (message) {                                     
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);
		class exemple val;

		//vivod1(::vec3, ::F10);
		//DrawGraph2(hdc, ps, ::vec3, ::F10);
		
		int i;
		vector<double> vec1(7);
		vector<double> vec2;
		for (i = 0; i < 7; i++) {
			//vec1[i] = pow(i + 2, i+2 );
			//vec2[i] = i;
			vec2.push_back(i);
			//vec1[i] = i;
		}
		MoveToEx(hdc, 100, 100, NULL);
		LineTo(hdc,200, 200);
		//vec2 = Func(vec1, F1);
		vivod1(::vec3, ::F10);
		DrawGraph2(hdc, ps, ::vec3, ::F10); 
									   
		EndPaint(hwnd, &ps);
	}
	break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}

#endif
