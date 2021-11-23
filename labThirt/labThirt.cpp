// labThirt.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
using namespace std;
VOID MultiThread();
int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    cout << "Погодь"<<endl;
    MultiThread();
    cout << "Все" << endl;
    return 0;
}

VOID MultiThread()
{
    HANDLE hEvent = CreateEvent(0, TRUE, FALSE, TEXT("name"));
    if (hEvent)
    {
        if (GetLastError() != ERROR_ALREADY_EXISTS)
        {
            PROCESS_INFORMATION pi;
            memset(&pi, 0, sizeof(pi));
            WCHAR fileName[MAX_PATH] = { 0 };
            GetModuleFileName(0, fileName, MAX_PATH);
            STARTUPINFO si;
            memset(&si, 0, sizeof(si));
            for (int i = 0; i < 3; i++) {
                CreateProcess(fileName, 0, 0, 0, FALSE, CREATE_NEW_CONSOLE, 0, 0, &si, &pi);
                Sleep(10000);
                CloseHandle(pi.hProcess);
            }
        }
        else
        {
            for (int j = 1; j <= 10; j++)
            {
                printf("Counter: %d\n", j);
                Sleep(1000);
            }
        }
        CloseHandle(hEvent);
    }
}