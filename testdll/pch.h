// pch.h: 这是预编译标头文件。
// 下方列出的文件仅编译一次，提高了将来生成的生成性能。
// 这还将影响 IntelliSense 性能，包括代码完成和许多代码浏览功能。
// 但是，如果此处列出的文件中的任何一个在生成之间有更新，它们全部都将被重新编译。
// 请勿在此处添加要频繁更新的文件，这将使得性能优势无效。

#ifndef PCH_H
#define PCH_H

// 添加要在此处预编译的标头
#include "framework.h"
typedef struct tagTEMP_INFO
{
	int                         nChannelID;				// 通道号
	int                         nAction;				// 1:开始 2:停止
	//char                        szName[128];			// 事件名称
	double                      PTS;					// 时间戳(单位是毫秒)
	//NET_TIME_EX                 UTC;					// 事件发生的时间
	int                         nEventID;				// 事件ID

	//EM_CLASS_TYPE               emClassType;			// 智能事件所属大类
	UINT						nPresetID;				// 事件触发的预置点号, 从1开始, 没有该字段,表示预置点未知
	//NET_MAN_TEMP_INFO			stManTempInfo;          // 区域内人员体温信息 
	//NET_VIS_SCENE_IMAGE			stVisSceneImage;		// 可见光全景图
	//NET_THERMAL_SCENE_IMAGE		stThermalSceneImage;	// 热成像全景图
	UINT						nSequence;				// 帧序号
	UINT						nEventRelevanceID;		// 事件关联ID
	//BYTE						byReserved[1020];		// 预留字段
} TEMP_INFO;
extern "C" _declspec(dllexport) void getStructData(TEMP_INFO* pTI);
#endif //PCH_H
