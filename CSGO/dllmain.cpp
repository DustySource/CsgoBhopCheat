// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <iostream>
#include <string>
#include "mmsystem.h"
#include <fstream>
#pragma comment(lib, "winmm.lib")
uintptr_t dwLocalPlayer = 0xDB558C;
uintptr_t m_fFlags = 0x104;
uintptr_t dwForceJump = 0x527A9AC;
uintptr_t FreezeTime = 0x20;
uintptr_t dwForceAttack = 0x3200FC4;
/*
*
* 
* Simple CSGO BHOP Cheat (does have a streamproof overlay that opens
* with a CreateProcessA function however i am not releasing it rn so there might be random stuff that does nothing that wouldve been connected to that)
* 
*/
int  main()
{
    PlaySound(TEXT("C:\\Users\\zacka\\Music\\copypasta.wav"), NULL, SND_FILENAME | SND_ASYNC);
    FILE* fnull;
    AllocConsole();
    freopen_s(&fnull, "CONOUT$", "w", stdout);


    HANDLE p = GetCurrentProcess();
  
    STARTUPINFOA si;
    PROCESS_INFORMATION pi;

    // set the size of the structures
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // start the program up
    CreateProcessA("C:\\Users\\zacka\\source\\repos\\LegitOverlayx3\\x64\\Release\\LegitOverlayx3.exe",   // the path
        NULL,        // Command line
        NULL,           // Process handle not inheritable
        NULL,           // Thread handle not inheritable
        FALSE,          // Set handle inheritance to FALSE
        0,              // No creation flags
        NULL,           // Use parent's environment block
        NULL,           // Use parent's starting directory 
        &si,            // Pointer to STARTUPINFO structure
        &pi             // Pointer to PROCESS_INFORMATION structure (removed extra parentheses)
    );
    

 


    DWORD base;
  uintptr_t  m_iHealth = 0x100;

  base = (DWORD)GetModuleHandle("client.dll");

 
      HWND  window = FindWindow("csgo", nullptr);


   
    uintptr_t lPlayer = *(DWORD*)(base + dwLocalPlayer);
    if (lPlayer == NULL) {
        while (lPlayer == NULL) {
            lPlayer = *(DWORD*)(base + dwLocalPlayer);
        }
   }
    
    

      
        std::cout << p;

        
      
        while (!GetAsyncKeyState(VK_END)) {
       
           
            uintptr_t lPlayer = *(DWORD*)(base + dwLocalPlayer);
            if (lPlayer == NULL) {
                while (lPlayer == NULL) {
                    lPlayer = *(DWORD*)(base + dwLocalPlayer);
                }
            }

          




         

            if (GetAsyncKeyState(VK_F1)) {
                std::cout << p;
            }
        
            
          
            BYTE flag = *(BYTE*)(lPlayer + m_fFlags);

            if (GetAsyncKeyState(VK_SPACE) && flag & (1 << 0))
            {
              
                *(DWORD*)(base + dwForceJump) = 6;
               

            }



            if (GetAsyncKeyState(VK_DELETE)) {
                std::cout << *(int*)(lPlayer + m_iHealth);
            }
           
            

        }


      

   


    

    


}


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH: CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)main, NULL, NULL, NULL);

    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

