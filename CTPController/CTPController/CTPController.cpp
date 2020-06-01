// CTPController.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <Windows.h>
#include <time.h>

int _tmain(int argc, TCHAR *argv[])
{
	printf("main start.\n");

	HANDLE hendEvent = NULL;
	SECURITY_ATTRIBUTES sa;
	sa.nLength = sizeof(sa);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;

	hendEvent = CreateEvent(&sa, TRUE, FALSE, NULL);

	TCHAR        lpHandle[20];
	memset(lpHandle, 0, sizeof(lpHandle));
	wsprintf(lpHandle, _T("%X"), hendEvent);


	HANDLE hTimeHandle = CreateEvent(NULL, FALSE, FALSE, NULL);

	STARTUPINFO si = { sizeof(si) };
	PROCESS_INFORMATION pi;

	SECURITY_ATTRIBUTES saProcess, saThread;

	saProcess.nLength = sizeof(saProcess);
	saProcess.lpSecurityDescriptor = NULL;
	saProcess.bInheritHandle = TRUE;

	saThread.nLength = sizeof(saThread);
	saThread.lpSecurityDescriptor = NULL;
	saThread.bInheritHandle = TRUE;

	while (TRUE)
	{
		time_t nowtime;
		nowtime = time(NULL); //获取日历时间  		
		struct tm local;
		localtime_s(&local, &nowtime);  //获取当前系统时间 

		switch (local.tm_hour)
		{
		case 13:
			if (local.tm_min == 26)
			{
				BOOL bResult = ::CreateProcess(_T("风行期货进击系统.exe"), lpHandle, &saProcess, &saThread, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
				if (!bResult)
				{
					printf("13:26 CreateProcess Failed.\n");
					WaitForSingleObject(hTimeHandle, 1000 * 60 * 3);
				}
				printf("13:26 CreateProcess Successful.\n");
				WaitForSingleObject(hTimeHandle, 1000 * 60 * 100);
			}
			break;
		case 15:
			if(local.tm_min == 10)
			{
				SetEvent(hendEvent);//终止子进程
				printf("15:10 SetEvent\n");
				unsigned long unInterval = 1000;
				unInterval = unInterval * 60 * 60;
				unInterval = unInterval * 5;
				unInterval = unInterval + 1000 * 60 * 30;
				WaitForSingleObject(hTimeHandle, unInterval);
				ResetEvent(hendEvent);
			}
			break;

		case 20:
			if (local.tm_min == 56)
			{
				BOOL bResult = ::CreateProcess(_T("风行期货进击系统.exe"), lpHandle, &saProcess, &saThread, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
				if (!bResult)
				{
					printf("20:56 CreateProcess Failed.\n");
					WaitForSingleObject(hTimeHandle, 1000 * 60 * 3);
				}
				printf("20:56 CreateProcess Successful.\n");

				unsigned long unInterval = 1000;
				unInterval = unInterval * 60 * 60;
				unInterval = unInterval * 5;
				unInterval = unInterval + 1000 * 60 * 40;

				WaitForSingleObject(hTimeHandle, unInterval);
			}
			break;

		case 2:
			if (local.tm_min == 40)
			{
				SetEvent(hendEvent);//终止子进程
				printf("2:40 SetEvent\n");

				unsigned long unInterval = 1000;
				unInterval = unInterval * 60 * 60;
				unInterval = unInterval * 6;
				unInterval = unInterval + 1000 * 60 * 10;

				WaitForSingleObject(hTimeHandle, unInterval);
				ResetEvent(hendEvent);
			}
			break;
		case 8:
			if (local.tm_min == 56)
			{
				BOOL bResult = ::CreateProcess(_T("风行期货进击系统.exe"), lpHandle, &saProcess, &saThread, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
				if (!bResult)
				{
					printf("8:56 CreateProcess Failed.\n");
					WaitForSingleObject(hTimeHandle, 1000 * 60 * 3);
				}
				printf("8:56 CreateProcess Successful.\n");

				unsigned long unInterval = 1000;
				unInterval = unInterval * 60 * 60;
				unInterval = unInterval * 2;
				unInterval = unInterval + 1000 * 60 * 40;
				WaitForSingleObject(hTimeHandle, unInterval);
			}

			break;

		case 11:
			if (local.tm_min == 40)
			{
				SetEvent(hendEvent);//终止子进程
				printf("11:40 SetEvent\n");

				unsigned long unInterval = 1000;
				unInterval = unInterval * 60 * 60;
				unInterval = unInterval * 1;
				unInterval = unInterval + 1000 * 60 * 40;
				WaitForSingleObject(hTimeHandle, unInterval);
				ResetEvent(hendEvent);
			}
			break;

		default:
			break;
		}
	}

	printf("CTP Controller END \n");



	//BOOL bResult = ::CreateProcess(_T("ChildProcess.exe"), lpHandle, &saProcess, &saThread, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
	//if (!bResult)
	//{
	//	printf("CreateProcess Failed.\n");
	//}

	//printf("Sleep 10 seconds.\n");

	//Sleep(10000);

	//printf("SetEvent end \n");
	//SetEvent(hendEvent);

	//printf("END \n");
	return 0;
}

