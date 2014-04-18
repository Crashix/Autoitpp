#ifndef __AUTOIT3_H
#define __AUTOIT3_H

#ifdef AUTOITX3_EXPORTS
#define AU3PP_API __declspec(dllexport) 
#else
#define AU3PP_API __declspec(dllimport) 
#endif

// Definitions
#define AU3_INTDEFAULT			(-2147483647)	// "Default" value for _some_ int parameters (largest negative number)

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