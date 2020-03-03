#include <iostream>
using namespace std;

typedef int  (__stdcall *fAnalyzerDataCallBack)(void* pAlarmInfo, unsigned char *pBuffer, unsigned long dwBufSize);

__declspec(dllexport)
int __stdcall CLIENT_RealLoadPictureEx(int lLoginID, int nChannelID, fAnalyzerDataCallBack cbAnalyzerData) {
	cout << "CLIENT_RealLoadPictureEx" << endl;
	cout << "lLoginID:" << lLoginID << ",nChannelID:" << nChannelID << endl;
	int *pAlarmInfo = nullptr, alarmInfo = 110;
	pAlarmInfo = &alarmInfo;
	unsigned long dwBufSize = 10;
	unsigned char *pBuffer = new unsigned char[dwBufSize];
	for (int i = 0; i < dwBufSize - 1; i++) {
		pBuffer[i] = 'a' + i;
	}
	pBuffer[dwBufSize-1] = NULL;

	return cbAnalyzerData(pAlarmInfo, pBuffer, dwBufSize);
}