/*
 * 题目
 *  寻个找满足瑕疵度的最长元音子字符串。
 *  元音字母: aeiou
 * 输入：
 *  flaw [0, 65535]
 *  string (0, 65535]
 */
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int findaeiou(int flaw, string instr)
{
    int idxt = 0;
    int adds = 0, adde = 0;
    int icnt = 0, idxr = 0, idxl = 0;

    vector<int> idaeiou;
    const string aeiou = { "aeiou" };

    transform(instr.begin(), instr.end(), instr.begin(), ::tolower);

    idxt = 0;
    for (int i = 0; i < instr.length(); i++) {
        for (int j = 0; j < aeiou.length(); j++) {
            if (instr[i] == aeiou[j]) {
                idaeiou.push_back(i - idxt);
                idxt = i + 1;
                break;
            }
        }
    }

    adds = 0, adde = 0;
    icnt = 0, idxr = 0, idxl = 0;
    while (1) {
        if (adds - adde == flaw || adds - adde < flaw) {
            if (adds - adde == flaw) {
                cout << "find: " << icnt << endl;
            }
            icnt++;
            idxr++;
            adds = adds + idaeiou[idxr];
            if (idxr + 1 == idaeiou.size()) {
                break;
            }
        }
        if (adds - adde > flaw) {
            icnt--;
            idxl++;
            adde = adde + idaeiou[idxl];
            if (idxl + 1 == idaeiou.size()) {
                break;
            }
        }
    }
    return 0;
}
int main(int argc, char* argv[])
{
    int flaw;
    string instr;

    cin >> flaw;
    cin >> instr;

    findaeiou(flaw, instr);
    return 0;
}
