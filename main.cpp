#include <cstdlib>
#define WINVER 0x0500
#include <iostream>
#include <windows.h>

void LeftClick ( )
{  
  INPUT Input={0};
  Input.type      = INPUT_MOUSE;
  Input.mi.dwFlags  = MOUSEEVENTF_LEFTDOWN;
  SendInput(1,&Input,sizeof(INPUT));

  ZeroMemory(&Input,sizeof(INPUT));
  Input.type      = INPUT_MOUSE;
  Input.mi.dwFlags  = MOUSEEVENTF_LEFTUP;
  SendInput(1,&Input,sizeof(INPUT));
}

void RighClick ( )
{  
  INPUT Input={0};
  Input.type      = INPUT_MOUSE;
  Input.mi.dwFlags  = MOUSEEVENTF_RIGHTDOWN;
  SendInput(1,&Input,sizeof(INPUT));

  ZeroMemory(&Input,sizeof(INPUT));
  Input.type      = INPUT_MOUSE;
  Input.mi.dwFlags  = MOUSEEVENTF_RIGHTUP;
  SendInput(1,&Input,sizeof(INPUT));
}
void MiddleClick (bool cm)
{
 if (!cm)
 {
 INPUT Input={0};  
 Input.type = INPUT_MOUSE;
 Input.mi.dwFlags = MOUSEEVENTF_MIDDLEDOWN;
 SendInput(1,&Input,sizeof(INPUT));  
 }else{
 INPUT Input={0};  
 Input.type = INPUT_MOUSE;
 Input.mi.dwFlags = MOUSEEVENTF_MIDDLEUP;
 SendInput(1,&Input,sizeof(INPUT));    
 }
}


int main(int argc, char *argv[])
{
     bool cd = false, cr= false, cm = false;
    unsigned int latence = 15;
    SetConsoleTitle("MOUSE Simulator");
    POINT mouse;
    std::cout << "------------------------------------------------------------------\n";
    std::cout << "--------------------------INSTRUCOES------------------------------\n";
    std::cout << "------------------------------------------------------------------\n\n";
    std::cout << "-\tuse os direcionais A S D W para mover o cursor\t\t-\n";
    std::cout << "-\tJ para click direito K para esquerdo L para meio\t-\n";
    std::cout << "-\t+ ou - para aumentar ou diminuir a velocidade\t\t-\n";
    std::cout << "-\t\t\tuse Q para Sair\t\t\t\t-\n \t\tpressione enter para continuar\t\n";
    std::cout << "------------------------------------------------------------------\n";
    std::cin.get(); 
    
    while(true)
    {
    GetCursorPos(&mouse);
 
    if (GetAsyncKeyState('W'))
           SetCursorPos(mouse.x,mouse.y-10);
    if (GetAsyncKeyState('S'))
           SetCursorPos(mouse.x,mouse.y+10);    
    if (GetAsyncKeyState('A'))
           SetCursorPos(mouse.x-10,mouse.y);
    if (GetAsyncKeyState('D'))
           SetCursorPos(mouse.x+10,mouse.y);
           
    if (GetAsyncKeyState('L'))
               MiddleClick(cm);
           
    if (GetAsyncKeyState('J'))
               LeftClick();
               
    if (GetAsyncKeyState('K'))
               RighClick();

    if (GetAsyncKeyState('Q'))
            break;   
             
     if (GetAsyncKeyState(VK_ADD))
     {
          if(latence == 999)
               std::cout << " Error valor minumo ja obtido \n\n\n\n\n\n\n\n\n\n\n";              
          else
               --latence;
     }

     if (GetAsyncKeyState(VK_SUBTRACT))
     {
          if(latence == 2)
               std::cout << " Error valor maximo ja obtido\n\n\n\n\n\n\n\n\n\n\n";               
          else
               ++latence;
     }
      Sleep(latence);  
    }
    
    return EXIT_SUCCESS;
}
