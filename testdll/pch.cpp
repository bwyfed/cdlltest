// pch.cpp: 与预编译标头对应的源文件
#include <iostream>
#include "pch.h"

using namespace std;
// 当使用预编译的头时，需要使用此源文件，编译才能成功。

void getStructData(TEMP_INFO* pTI) {
	cout << "in C++, getStructData" << endl;
	// 保存结构体信息
	pTI->nChannelID = 110;
	pTI->nAction = 2;
	const char szName[128] = "self-define-event";
	//strncpy_s(pTI->szName, szName, strnlen_s(szName, 128));
	pTI->PTS = 1583378254787;
	pTI->nEventID = 2345;
	pTI->nPresetID = 43215;
	pTI->nSequence = 54321;
	pTI->nEventRelevanceID = 5432;
	/*for (int i = 0; i < 100; i++) {
		pTI->byReserved[i] = 100 - i;
	}*/
	return;
}