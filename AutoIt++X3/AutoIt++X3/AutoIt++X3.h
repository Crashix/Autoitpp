#ifndef __AUTOIT3_H
#define __AUTOIT3_H

#ifdef AUTOITX3_EXPORTS
#define AU3PP_API __declspec(dllexport) 
#else
#define AU3PP_API __declspec(dllimport) 
#endif




///////////////////////////////////////////////////////////////////////////////
//
// AutoItX v3
//
// Copyright (C)1999-2008:
//		- Jonathan Bennett <jon at autoitscript dot com>
//		- See "AUTHORS.txt" for contributors.
//
// This file is part of AutoItX.  Use of this file and the AutoItX DLL is subject
// to the terms of the AutoItX license details of which can be found in the helpfile.
//
// When using the AutoItX3.dll as a standard DLL this file contains the definitions,
// and function declarations required to use the DLL and AutoItX3.lib file.
//
///////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
	#define AU3_API extern "C"
#else
	#define AU3_API
#endif

// Definitions
#define AU3_INTDEFAULT			(-2147483647)	// "Default" value for _some_ int parameters (largest negative number)

//
// NOTE: This DLL is now using Unicode strings.  Only a few functions also have an
// ANSI version. If you require ANSI strings then please use an older version of AutoItX
// or ask about the subject on the forums at http://www.autoitscript.com/forum
//

//
// nBufSize
// When used for specifying the size of a resulting string buffer this is the number of CHARACTERS 
// in that buffer, including the null terminator.  For example:
//
// WCHAR szBuffer[10];
// AU3_ClipGetW(szBuffer, 10);
//
// The resulting string will be truncated at 9 characters with the the terminating null in the 10th.
//


///////////////////////////////////////////////////////////////////////////////
// Exported functions
///////////////////////////////////////////////////////////////////////////////

AU3_API void WINAPI AU3_Init(void);
AU3_API long AU3_error(void);

AU3_API long WINAPI AU3_AutoItSetOption(LPCWSTR szOption, long nValue);

AU3_API void WINAPI AU3_BlockInput(long nFlag);

AU3_API long WINAPI AU3_CDTray(LPCWSTR szDrive, LPCWSTR szAction);
AU3_API void WINAPI AU3_ClipGet(LPWSTR szClip, int nBufSize);
AU3_API void WINAPI AU3_ClipPut(LPCWSTR szClip);
AU3_API long WINAPI AU3_ControlClick(LPCWSTR szTitle, LPCWSTR szText, LPCWSTR szControl, LPCWSTR szButton, long nNumClicks, /*[in,defaultvalue(AU3_INTDEFAULT)]*/long nX, /*[in,defaultvalue(AU3_INTDEFAULT)]*/long nY);
AU3_API void WINAPI AU3_ControlCommand(LPCWSTR szTitle, LPCWSTR szText, LPCWSTR szControl, LPCWSTR szCommand, LPCWSTR szExtra, LPWSTR szResult, int nBufSize);
AU3_API void WINAPI AU3_ControlListView(LPCWSTR szTitle, LPCWSTR szText, LPCWSTR szControl, LPCWSTR szCommand, LPCWSTR szExtra1, LPCWSTR szExtra2, LPWSTR szResult, int nBufSize);
AU3_API long WINAPI AU3_ControlDisable(LPCWSTR szTitle, LPCWSTR szText, LPCWSTR szControl);
AU3_API long WINAPI AU3_ControlEnable(LPCWSTR szTitle, LPCWSTR szText, LPCWSTR szControl);
AU3_API long WINAPI AU3_ControlFocus(LPCWSTR szTitle, LPCWSTR szText, LPCWSTR szControl);
AU3_API void WINAPI AU3_ControlGetFocus(LPCWSTR szTitle, LPCWSTR szText, LPWSTR szControlWithFocus, int nBufSize);
AU3_API void WINAPI AU3_ControlGetHandle(LPCWSTR szTitle, /*[in,defaultvalue("")]*/LPCWSTR szText, LPCWSTR szControl, LPWSTR szRetText, int nBufSize);
AU3_API long WINAPI AU3_ControlGetPosX(LPCWSTR szTitle, LPCWSTR szText, LPCWSTR szControl);
AU3_API long WINAPI AU3_ControlGetPosY(LPCWSTR szTitle, LPCWSTR szText, LPCWSTR szControl);
AU3_API long WINAPI AU3_ControlGetPosHeight(LPCWSTR szTitle, LPCWSTR szText, LPCWSTR szControl);
AU3_API long WINAPI AU3_ControlGetPosWidth(LPCWSTR szTitle, LPCWSTR szText, LPCWSTR szControl);
AU3_API void WINAPI AU3_ControlGetText(LPCWSTR szTitle, LPCWSTR szText, LPCWSTR szControl, LPWSTR szControlText, int nBufSize);
AU3_API long WINAPI AU3_ControlHide(LPCWSTR szTitle, LPCWSTR szText, LPCWSTR szControl);
AU3_API long WINAPI AU3_ControlMove(LPCWSTR szTitle, LPCWSTR szText, LPCWSTR szControl, long nX, long nY, /*[in,defaultvalue(-1)]*/long nWidth, /*[in,defaultvalue(-1)]*/long nHeight);
AU3_API long WINAPI AU3_ControlSend(LPCWSTR szTitle, LPCWSTR szText, LPCWSTR szControl, LPCWSTR szSendText, /*[in,defaultvalue(0)]*/long nMode);
AU3_API long WINAPI AU3_ControlSetText(LPCWSTR szTitle, LPCWSTR szText, LPCWSTR szControl, LPCWSTR szControlText);
AU3_API long WINAPI AU3_ControlShow(LPCWSTR szTitle, LPCWSTR szText, LPCWSTR szControl);
AU3_API void WINAPI AU3_ControlTreeView(LPCWSTR szTitle, LPCWSTR szText, LPCWSTR szControl, LPCWSTR szCommand, LPCWSTR szExtra1, LPCWSTR szExtra2, LPWSTR szResult, int nBufSize);

AU3_API void WINAPI AU3_DriveMapAdd(LPCWSTR szDevice, LPCWSTR szShare, long nFlags, /*[in,defaultvalue("")]*/LPCWSTR szUser, /*[in,defaultvalue("")]*/LPCWSTR szPwd, LPWSTR szResult, int nBufSize);
AU3_API long WINAPI AU3_DriveMapDel(LPCWSTR szDevice);
AU3_API void WINAPI AU3_DriveMapGet(LPCWSTR szDevice, LPWSTR szMapping, int nBufSize);

AU3_API long WINAPI AU3_IniDelete(LPCWSTR szFilename, LPCWSTR szSection, LPCWSTR szKey);
AU3_API void WINAPI AU3_IniRead(LPCWSTR szFilename, LPCWSTR szSection, LPCWSTR szKey, LPCWSTR szDefault, LPWSTR szValue, int nBufSize);
AU3_API long WINAPI AU3_IniWrite(LPCWSTR szFilename, LPCWSTR szSection, LPCWSTR szKey, LPCWSTR szValue);

AU3_API long WINAPI AU3_IsAdmin(void);

AU3_API long WINAPI AU3_MouseClick(/*[in,defaultvalue("LEFT")]*/LPCWSTR szButton, /*[in,defaultvalue(AU3_INTDEFAULT)]*/long nX, /*[in,defaultvalue(AU3_INTDEFAULT)]*/long nY, /*[in,defaultvalue(1)]*/long nClicks, /*[in,defaultvalue(-1)]*/long nSpeed);
AU3_API long WINAPI AU3_MouseClickDrag(LPCWSTR szButton, long nX1, long nY1, long nX2, long nY2, /*[in,defaultvalue(-1)]*/long nSpeed);
AU3_API void WINAPI AU3_MouseDown(/*[in,defaultvalue("LEFT")]*/LPCWSTR szButton);
AU3_API long WINAPI AU3_MouseGetCursor(void);
AU3_API long WINAPI AU3_MouseGetPosX(void);
AU3_API long WINAPI AU3_MouseGetPosY(void);
AU3_API long WINAPI AU3_MouseMove(long nX, long nY, /*[in,defaultvalue(-1)]*/long nSpeed);
AU3_API void WINAPI AU3_MouseUp(/*[in,defaultvalue("LEFT")]*/LPCWSTR szButton);
AU3_API void WINAPI AU3_MouseWheel(LPCWSTR szDirection, long nClicks);

AU3_API long WINAPI AU3_Opt(LPCWSTR szOption, long nValue);

AU3_API unsigned long WINAPI AU3_PixelChecksum(long nLeft, long nTop, long nRight, long nBottom, /*[in,defaultvalue(1)]*/long nStep);
AU3_API long WINAPI AU3_PixelGetColor(long nX, long nY);
AU3_API void WINAPI AU3_PixelSearch(long nLeft, long nTop, long nRight, long nBottom, long nCol, /*default 0*/long nVar, /*default 1*/long nStep, LPPOINT pPointResult);
AU3_API long WINAPI AU3_ProcessClose(LPCWSTR szProcess);
AU3_API long WINAPI AU3_ProcessExists(LPCWSTR szProcess);
AU3_API long WINAPI AU3_ProcessSetPriority(LPCWSTR szProcess, long nPriority);
AU3_API long WINAPI AU3_ProcessWait(LPCWSTR szProcess, /*[in,defaultvalue(0)]*/long nTimeout);
AU3_API long WINAPI AU3_ProcessWaitClose(LPCWSTR szProcess, /*[in,defaultvalue(0)]*/long nTimeout);
AU3_API long WINAPI AU3_RegDeleteKey(LPCWSTR szKeyname);
AU3_API long WINAPI AU3_RegDeleteVal(LPCWSTR szKeyname, LPCWSTR szValuename);
AU3_API void WINAPI AU3_RegEnumKey(LPCWSTR szKeyname, long nInstance, LPWSTR szResult, int nBufSize);
AU3_API void WINAPI AU3_RegEnumVal(LPCWSTR szKeyname, long nInstance, LPWSTR szResult, int nBufSize);
AU3_API void WINAPI AU3_RegRead(LPCWSTR szKeyname, LPCWSTR szValuename, LPWSTR szRetText, int nBufSize);
AU3_API long WINAPI AU3_RegWrite(LPCWSTR szKeyname, LPCWSTR szValuename, LPCWSTR szType, LPCWSTR szValue);
AU3_API long WINAPI AU3_Run(LPCWSTR szRun, /*[in,defaultvalue("")]*/LPCWSTR szDir, /*[in,defaultvalue(1)]*/long nShowFlags);
AU3_API long WINAPI AU3_RunAsSet(LPCWSTR szUser, LPCWSTR szDomain, LPCWSTR szPassword, int nOptions);
AU3_API long WINAPI AU3_RunWait(LPCWSTR szRun, /*[in,defaultvalue("")]*/LPCWSTR szDir, /*[in,defaultvalue(1)]*/long nShowFlags);

AU3_API void WINAPI AU3_Send(LPCWSTR szSendText, /*[in,defaultvalue("")]*/long nMode);
AU3_API void WINAPI AU3_SendA(LPCSTR szSendText, /*[in,defaultvalue("")]*/long nMode);
AU3_API long WINAPI AU3_Shutdown(long nFlags);
AU3_API void WINAPI AU3_Sleep(long nMilliseconds);
AU3_API void WINAPI AU3_StatusbarGetText(LPCWSTR szTitle, /*[in,defaultvalue("")]*/LPCWSTR szText, /*[in,defaultvalue(1)]*/long nPart, LPWSTR szStatusText, int nBufSize);

AU3_API void WINAPI AU3_ToolTip(LPCWSTR szTip, /*[in,defaultvalue(AU3_INTDEFAULT)]*/long nX, /*[in,defaultvalue(AU3_INTDEFAULT)]*/long nY);

AU3_API void WINAPI AU3_WinActivate(LPCWSTR szTitle, /*[in,defaultvalue("")]*/LPCWSTR szText);
AU3_API long WINAPI AU3_WinActive(LPCWSTR szTitle, /*[in,defaultvalue("")]*/LPCWSTR szText);
AU3_API long WINAPI AU3_WinClose(LPCWSTR szTitle, /*[in,defaultvalue("")]*/LPCWSTR szText);
AU3_API long WINAPI AU3_WinExists(LPCWSTR szTitle, /*[in,defaultvalue("")]*/LPCWSTR szText);
AU3_API long WINAPI AU3_WinGetCaretPosX(void);
AU3_API long WINAPI AU3_WinGetCaretPosY(void);
AU3_API void WINAPI AU3_WinGetClassList(LPCWSTR szTitle, /*[in,defaultvalue("")]*/LPCWSTR szText, LPWSTR szRetText, int nBufSize);
AU3_API long WINAPI AU3_WinGetClientSizeHeight(LPCWSTR szTitle, /*[in,defaultvalue("")]*/LPCWSTR szText);
AU3_API long WINAPI AU3_WinGetClientSizeWidth(LPCWSTR szTitle, /*[in,defaultvalue("")]*/LPCWSTR szText);
AU3_API void WINAPI AU3_WinGetHandle(LPCWSTR szTitle, /*[in,defaultvalue("")]*/LPCWSTR szText, LPWSTR szRetText, int nBufSize);
AU3_API long WINAPI AU3_WinGetPosX(LPCWSTR szTitle, /*[in,defaultvalue("")]*/LPCWSTR szText);
AU3_API long WINAPI AU3_WinGetPosY(LPCWSTR szTitle, /*[in,defaultvalue("")]*/LPCWSTR szText);
AU3_API long WINAPI AU3_WinGetPosHeight(LPCWSTR szTitle, /*[in,defaultvalue("")]*/LPCWSTR szText);
AU3_API long WINAPI AU3_WinGetPosWidth(LPCWSTR szTitle, /*[in,defaultvalue("")]*/LPCWSTR szText);
AU3_API void WINAPI AU3_WinGetProcess(LPCWSTR szTitle, /*[in,defaultvalue("")]*/LPCWSTR szText, LPWSTR szRetText, int nBufSize);
AU3_API long WINAPI AU3_WinGetState(LPCWSTR szTitle, /*[in,defaultvalue("")]*/LPCWSTR szText);
AU3_API void WINAPI AU3_WinGetText(LPCWSTR szTitle, /*[in,defaultvalue("")]*/LPCWSTR szText, LPWSTR szRetText, int nBufSize);
AU3_API void WINAPI AU3_WinGetTitle(LPCWSTR szTitle, /*[in,defaultvalue("")]*/LPCWSTR szText, LPWSTR szRetText, int nBufSize);
AU3_API long WINAPI AU3_WinKill(LPCWSTR szTitle, /*[in,defaultvalue("")]*/LPCWSTR szText);
AU3_API long WINAPI AU3_WinMenuSelectItem(LPCWSTR szTitle, /*[in,defaultvalue("")]*/LPCWSTR szText, LPCWSTR szItem1, LPCWSTR szItem2, LPCWSTR szItem3, LPCWSTR szItem4, LPCWSTR szItem5, LPCWSTR szItem6, LPCWSTR szItem7, LPCWSTR szItem8);
AU3_API void WINAPI AU3_WinMinimizeAll();
AU3_API void WINAPI AU3_WinMinimizeAllUndo();
AU3_API long WINAPI AU3_WinMove(LPCWSTR szTitle, /*[in,defaultvalue("")]*/LPCWSTR szText, long nX, long nY, /*[in,defaultvalue(-1)]*/long nWidth, /*[in,defaultvalue(-1)]*/long nHeight);
AU3_API long WINAPI AU3_WinSetOnTop(LPCWSTR szTitle, /*[in,defaultvalue("")]*/LPCWSTR szText, long nFlag);
AU3_API long WINAPI AU3_WinSetState(LPCWSTR szTitle, /*[in,defaultvalue("")]*/LPCWSTR szText, long nFlags);
AU3_API long WINAPI AU3_WinSetTitle(LPCWSTR szTitle,/*[in,defaultvalue("")]*/ LPCWSTR szText, LPCWSTR szNewTitle);
AU3_API long WINAPI AU3_WinSetTrans(LPCWSTR szTitle, /*[in,defaultvalue("")]*/LPCWSTR szText, long nTrans);

AU3_API long WINAPI AU3_WinWait(LPCWSTR szTitle, /*[in,defaultvalue("")]*/LPCWSTR szText, /*[in,defaultvalue(0)]*/long nTimeout);
AU3_API long WINAPI AU3_WinWaitA(LPCSTR szTitle, /*[in,defaultvalue("")]*/LPCSTR szText, /*[in,defaultvalue(0)]*/long nTimeout);
AU3_API long WINAPI AU3_WinWaitActive(LPCWSTR szTitle, /*[in,defaultvalue("")]*/LPCWSTR szText, /*[in,defaultvalue(0)]*/long nTimeout);
AU3_API long WINAPI AU3_WinWaitActiveA(LPCSTR szTitle, /*[in,defaultvalue("")]*/LPCSTR szText, /*[in,defaultvalue(0)]*/long nTimeout);
AU3_API long WINAPI AU3_WinWaitClose(LPCWSTR szTitle, /*[in,defaultvalue("")]*/LPCWSTR szText, /*[in,defaultvalue(0)]*/long nTimeout);
AU3_API long WINAPI AU3_WinWaitCloseA(LPCSTR szTitle, /*[in,defaultvalue("")]*/LPCSTR szText, /*[in,defaultvalue(0)]*/long nTimeout);
AU3_API long WINAPI AU3_WinWaitNotActive(LPCWSTR szTitle, /*[in,defaultvalue("")]*/LPCWSTR szText, /*[in,defaultvalue(0)]*/long nTimeout);
AU3_API long WINAPI AU3_WinWaitNotActiveA(LPCSTR szTitle, /*[in,defaultvalue("")]*/LPCSTR szText, /*[in,defaultvalue(0)]*/long nTimeout);

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// CRASHIX Autoit Reborn C++   =)
//
// AUTOIT++ v1.0.0.0
// 15/12/2013
//
// This file is part of AutoItX.  Use of this file and the AutoItX DLL is subject
// to the terms of the AutoItX license details of which can be found in the helpfile.
//
// When using the AutoIt++X3.dll as a standard DLL this file contains the definitions,
// and function declarations required to use the DLL and AutoIt++X3.lib file.
///////////////////////////////////////////////////////////////////////////////
//Includes
#include <string>
#include <vector>




namespace AU3
{

	enum Run_opt_flag{STDIN_CHILD = 0x1, STDOUTCHILD = 0x2, STDERR_CHILD = 0x4, STDERR_MERGED = 0x8, STDIO_INHERIT_PARENT = 0x10,RUN_CREATE_NEW_CONSOLE = 0x10000};
	enum Win_State{WIN_EXISTS = 1, WIN_IS_VISIBLE = 2, WIN_IS_ENABLED = 4, WIN_IS_ACTIVE = 8, WIN_IS_MINIMIZED = 16, WIN_IS_MAXIMIZED = 32}; // For WinGetState()
	//define missing macro of winUsers.h
	#define SW_DISABLE 65
	#define SW_ENABLE 64



	AU3PP_API long error(void);
	
	AU3PP_API long AutoItSetOption(std::string szOption, long nValue = 0);

	AU3PP_API void BlockInput(long nFlag);

	AU3PP_API long CDTray(std::string szDrive, std::string szAction);
	AU3PP_API std::string ClipGet();
	AU3PP_API void ClipPut(std::string szClip);
	AU3PP_API long ControlClick(std::string szTitle, std::string szText, std::string szControl, std::string szButton = "left", long nNumClicks = 1, /*[in,defaultvalue(AU3_INTDEFAULT)]*/long nX = AU3_INTDEFAULT, /*[in,defaultvalue(AU3_INTDEFAULT)]*/long nY = AU3_INTDEFAULT);
	AU3PP_API std::string ControlCommand(std::string szTitle, std::string szText, std::string szControl, std::string szCommand, std::string szExtra = "");
	AU3PP_API std::string  ControlListView(std::string szTitle, std::string szText, std::string szControl, std::string szCommand, std::string szExtra1 = "", std::string szExtra2 = "");
	AU3PP_API long ControlDisable(std::string szTitle, std::string szText, std::string szControl);
	AU3PP_API long ControlEnable(std::string szTitle, std::string szText, std::string szControl);
	AU3PP_API long ControlFocus(std::string szTitle, std::string szText, std::string szControl);
	AU3PP_API long ControlGetHandle(std::string szTitle, std::string szText, std::string szControl);
	AU3PP_API std::vector<long> ControlGetPos(std::string szTitle, std::string szText, std::string szControl);
	AU3PP_API std::string ControlGetText(std::string szTitle, std::string szText, std::string szControl);
	AU3PP_API long ControlHide(std::string szTitle, std::string szText, std::string szControl);
	AU3PP_API long ControlMove(std::string szTitle, std::string szText, std::string szControl, long nX, long nY, /*[in,defaultvalue(-1)]*/long nWidth = -1, /*[in,defaultvalue(-1)]*/long nHeight = -1);
	AU3PP_API long ControlSend(std::string szTitle, std::string szText, std::string szControl, std::string szSendText, /*[in,defaultvalue(0)]*/long nMode = 0);
	AU3PP_API long ControlSetText(std::string szTitle, std::string szText, std::string szControl, std::string szControlText);
	AU3PP_API long ControlShow(std::string szTitle, std::string szText, std::string szControl);
	AU3PP_API std::string ControlTreeView(std::string szTitle, std::string szText, std::string szControl, std::string szCommand, std::string szExtra1 = "", std::string szExtra2 = "");

	AU3PP_API std::string DriveMapAdd(std::string szDevice, std::string szShare, long nFlags, /*[in,defaultvalue("")]*/std::string szUser = "", /*[in,defaultvalue("")]*/std::string szPwd = "");
	AU3PP_API long DriveMapDel(std::string szDevice);
	AU3PP_API std::string DriveMapGet(std::string szDevice);

	AU3PP_API long IniDelete(std::string szFilename, std::string szSection, std::string szKey);
	AU3PP_API std::string IniRead(std::string szFilename, std::string szSection, std::string szKey, std::string szDefault);
	AU3PP_API long IniWrite(std::string szFilename, std::string szSection, std::string szKey, std::string szValue);

	AU3PP_API long IsAdmin(void);

	AU3PP_API long MouseClick(/*[in,defaultvalue("LEFT")]*/std::string szButton = "left", /*[in,defaultvalue(AU3_INTDEFAULT)]*/long nX = AU3_INTDEFAULT, /*[in,defaultvalue(AU3_INTDEFAULT)]*/long nY = AU3_INTDEFAULT, /*[in,defaultvalue(1)]*/long nClicks = 1, /*[in,defaultvalue(-1)]*/long nSpeed = -1);
	AU3PP_API long MouseClickDrag(std::string szButton, long nX1, long nY1, long nX2, long nY2, /*[in,defaultvalue(-1)]*/long nSpeed = -1);
	AU3PP_API void MouseDown(/*[in,defaultvalue("LEFT")]*/std::string szButton);
	AU3PP_API long MouseGetCursor(void);
	AU3PP_API long MouseGetPosX(void);
	AU3PP_API long MouseGetPosY(void);
	AU3PP_API long MouseMove(long nX, long nY, /*[in,defaultvalue(-1)]*/long nSpeed = -1);
	AU3PP_API void MouseUp(/*[in,defaultvalue("LEFT")]*/std::string szButton);
	AU3PP_API void MouseWheel(std::string szDirection, long nClicks = 1);

	AU3PP_API long Opt(std::string szOption, long nValue);

	AU3PP_API unsigned long PixelChecksum(long nLeft, long nTop, long nRight, long nBottom, /*[in,defaultvalue(1)]*/long nStep = 1);
	AU3PP_API long PixelGetColor(long nX, long nY);
	AU3PP_API LPPOINT PixelSearch(long nLeft, long nTop, long nRight, long nBottom, long nCol, /*default 0*/long nVar = 0, /*default 1*/long nStep = 1);
	AU3PP_API long ProcessClose(std::string szProcess);
	AU3PP_API long ProcessExists(std::string szProcess);
	AU3PP_API long ProcessSetPriority(std::string szProcess, long nPriority);
	AU3PP_API long ProcessWait(std::string szProcess, /*[in,defaultvalue(0)]*/long nTimeout = 0);
	AU3PP_API long ProcessWaitClose(std::string szProcess, /*[in,defaultvalue(0)]*/long nTimeout = 0);
	AU3PP_API long RegDeleteKey(std::string szKeyname);
	AU3PP_API long RegDeleteVal(std::string szKeyname, std::string szValuename);
	AU3PP_API std::string RegEnumKey(std::string szKeyname, long nInstance);
	AU3PP_API std::string RegEnumVal(std::string szKeyname, long nInstance);
	AU3PP_API std::string RegRead(std::string szKeyname, std::string szValuename);
	AU3PP_API std::string RegReadVal(std::string path, std::string val, int valnumber = 50);
	AU3PP_API long RegWrite(std::string szKeyname, std::string szValuename, std::string szType, std::string szValue);
	AU3PP_API long Run(std::string szRun, /*[in,defaultvalue("")]*/std::string szDir = "", /*[in,defaultvalue(1)]*/Run_opt_flag nShowFlags = STDIN_CHILD);
	AU3PP_API long RunAsSet(std::string szUser, std::string szDomain, std::string szPassword, int nOptions);
	AU3PP_API long RunWait(std::string szRun, /*[in,defaultvalue("")]*/std::string szDir = "", /*[in,defaultvalue(1)]*/Run_opt_flag nShowFlags = STDIN_CHILD);

	AU3PP_API void Send(std::string szSendText, /*[in,defaultvalue("")]*/long nMode = 0);
	AU3PP_API void SendA(std::string szSendText, /*[in,defaultvalue("")]*/long nMode = 0);
	AU3PP_API long Shutdown(long nFlags = 1);
	AU3PP_API void Sleep(long nMilliseconds);
	AU3PP_API std::string StatusbarGetText(std::string szTitle, /*[in,defaultvalue("")]*/std::string szText = "", /*[in,defaultvalue(1)]*/long nPart = 1);

	AU3PP_API void ToolTip(std::string szTip, /*[in,defaultvalue(AU3_INTDEFAULT)]*/long nX = AU3_INTDEFAULT, /*[in,defaultvalue(AU3_INTDEFAULT)]*/long nY = AU3_INTDEFAULT);

	AU3PP_API void WinActivate(std::string szTitle, /*[in,defaultvalue("")]*/std::string szText = "");
	AU3PP_API long WinActive(std::string szTitle, /*[in,defaultvalue("")]*/std::string szText = "");
	AU3PP_API long WinClose(std::string szTitle, /*[in,defaultvalue("")]*/std::string szText = "");
	AU3PP_API long WinExists(std::string szTitle, /*[in,defaultvalue("")]*/std::string szText = "");
	AU3PP_API LPPOINT WinGetCaretPos(void);
	AU3PP_API std::string WinGetClassList(std::string szTitle, /*[in,defaultvalue("")]*/std::string szText = "");
	AU3PP_API std::vector<long> WinGetClientSize(std::string szTitle, /*[in,defaultvalue("")]*/std::string szText = "");
	AU3PP_API long WinGetHandle(std::string szTitle, /*[in,defaultvalue("")]*/std::string szText = "");
	AU3PP_API std::vector<long> WinGetPos(std::string szTitle, /*[in,defaultvalue("")]*/std::string szText = "");
	AU3PP_API long WinGetProcess(std::string szTitle, /*[in,defaultvalue("")]*/std::string szText = "");
	AU3PP_API long WinGetState(std::string szTitle, /*[in,defaultvalue("")]*/std::string szText = "");
	AU3PP_API std::string WinGetText(std::string szTitle, /*[in,defaultvalue("")]*/std::string szText = "");
	AU3PP_API std::string WinGetTitle(std::string szTitle, /*[in,defaultvalue("")]*/std::string szText = "");
	AU3PP_API long WinKill(std::string szTitle, /*[in,defaultvalue("")]*/std::string szText = "");
	AU3PP_API long WinMenuSelectItem(std::string szTitle, /*[in,defaultvalue("")]*/std::string szText, std::string szItem1,
																								std::string szItem2 = "",
																								std::string szItem3 = "",
																								std::string szItem4 = "",
																								std::string szItem5 = "",
																								std::string szItem6 = "",
																								std::string szItem7 = "",
																								std::string szItem8 = "");
	AU3PP_API void WinMinimizeAll();
	AU3PP_API void WinMinimizeAllUndo();
	AU3PP_API long WinMove(std::string szTitle, /*[in,defaultvalue("")]*/std::string szText, long nX, long nY, /*[in,defaultvalue(-1)]*/long nWidth = -1, /*[in,defaultvalue(-1)]*/long nHeight = -1);
	AU3PP_API long WinSetOnTop(std::string szTitle, /*[in,defaultvalue("")]*/std::string szText, long nFlag);
	AU3PP_API long WinSetState(std::string szTitle, /*[in,defaultvalue("")]*/std::string szText, long nFlags);
	AU3PP_API long WinSetTitle(std::string szTitle,/*[in,defaultvalue("")]*/ std::string szText, std::string szNewTitle);
	AU3PP_API long WinSetTrans(std::string szTitle, /*[in,defaultvalue("")]*/std::string szText, long nTrans);

	AU3PP_API long WinWait(std::string szTitle, /*[in,defaultvalue("")]*/std::string szText = "", /*[in,defaultvalue(0)]*/long nTimeout = 0);
	AU3PP_API long WinWaitActive(std::string szTitle, /*[in,defaultvalue("")]*/std::string szText = "", /*[in,defaultvalue(0)]*/long nTimeout = 0);
	AU3PP_API long WinWaitClose(std::string szTitle, /*[in,defaultvalue("")]*/std::string szText = "", /*[in,defaultvalue(0)]*/long nTimeout = 0);
	AU3PP_API long WinWaitNotActive(std::string szTitle, /*[in,defaultvalue("")]*/std::string szText = "", /*[in,defaultvalue(0)]*/long nTimeout = 0);






	// -----------------------------Image Search Section ----------------------


	AU3PP_API bool ImageSearchArea(std::string aImageFile ,int aLeft, int aTop, int aRight, int aBottom,int &x, int &y, bool resultPositionCenter = TRUE);
	//Only on primary screen
	AU3PP_API bool ImageSearch(std::string aImageFile ,int &x, int &y, bool resultPositionCenter = TRUE);



	// -----------------------------MemEd Section -----------------------------

	//Base address
	AU3PP_API DWORD GetBaseAdress(std::string baseName,/*[out]*/ HANDLE* pHandle = NULL); // baseName must be lowercase
	AU3PP_API DWORD GetBaseAdress(std::string processName,std::string windowName,/*[out]*/ HANDLE* pHandle = NULL);

	//Read
	template<typename T>
	T ReadMemory(HANDLE hProcess,DWORD lpBaseAddress,SIZE_T *lpNumberOfBytesRead = NULL){

		T value;

		ReadProcessMemory(hProcess,(void*)lpBaseAddress,&value,sizeof(value),lpNumberOfBytesRead);

		return value;

	}

	template<typename T>
	T ReadMemory(HANDLE hProcess,DWORD lpBaseAddress,std::vector<DWORD> offsets,SIZE_T *lpNumberOfBytesRead = NULL){

		if(!offsets.size()){
			return ReadMemory<T>(hProcess,lpBaseAddress,lpNumberOfBytesRead);
		}
		else{

			DWORD value; //next adress

			value = ReadMemory<DWORD>(hProcess,lpBaseAddress,lpNumberOfBytesRead);

			for (int i = 0; i < offsets.size() - 1; i++)
			{
				value = ReadMemory<DWORD>(hProcess,(value+offsets[i]),lpNumberOfBytesRead);
			}

			return ReadMemory<T>(hProcess,value+offsets[offsets.size() - 1],lpNumberOfBytesRead);

		}

	}

	//Write
	template<typename T>
	bool WriteMemory(HANDLE hProcess,DWORD lpBaseAddress,T value,SIZE_T *lpNumberOfBytesWritten = NULL){
		return WriteProcessMemory(hProcess,(void*)lpBaseAddress,&value,sizeof(value),lpNumberOfBytesWritten);
	}

	template<typename T>
	bool WriteMemory(HANDLE hProcess,DWORD lpBaseAddress,T valueToWrite,std::vector<DWORD> offsets,SIZE_T *lpNumberOfBytesWritten = NULL){

		if(!offsets.size()){
			return WriteMemory<T>(hProcess,lpBaseAddress,valueToWrite,lpNumberOfBytesWritten);
		}
		else{

			DWORD value; //next adress

			value = ReadMemory<DWORD>(hProcess,lpBaseAddress,lpNumberOfBytesWritten);

			for (int i = 0; i < offsets.size() - 1; i++)
			{
				value = ReadMemory<DWORD>(hProcess,(value+offsets[i]),lpNumberOfBytesWritten);
			}

			return WriteProcessMemory(hProcess,(void*)(value+offsets[offsets.size() - 1]),&valueToWrite,sizeof(valueToWrite),lpNumberOfBytesWritten);

		}

	}

}



#endif