# Black-Jack-Cplusplus
## 概要：
	用C++ 物件導向的概念實作SokoBan（倉庫番）
  WASD為角色的移動鍵
	總行數：346行
## 地圖說明：
  牆壁：'/'
  箱子：'1'
  箱子的目的地：'2'
  
## 美編：
	gotoxy：清屏、cout

## 繪製：
	print_map()：顯示地圖畫面

## 玩家資料儲存：
	1.物件導向先寫bk.cpp、bk.h兩個檔案
  2.用<iostream>及<fstream>來讀取地圖檔(txt)
  3.用_kbhit()及_getch()來偵測玩家按鍵
