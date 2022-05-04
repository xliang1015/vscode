/*
 * 题目
 *  寻个找满足瑕疵度的最长元音子字符串。
 *  元音字母: aeiou
 * 输入：
 *  flaw [0, 65535]
 *  string (0, 65535]
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int findaeiou(int flaw, string instr)
{
    int idxs = 0, idxe = 0;
    int mlen = 0, tlen = 0;

    const string aeiou = { "aeiou" };

    transform(instr.begin(), instr.end(), instr.begin(), ::tolower);

    for (int i = 0; i < instr.length(); i++) {
        for (int j = 0; j < aeiou.length(); j++) {
            if (instr[i] == aeiou[j]) {
                if (tlen < flaw) { // 长度不够
                    idxe = i;
                } else if (tlen > flaw) { // 长度过长
                    idxs = i;
                } else { // 找到合适
                    if (mlen < tlen) {
                        mlen = tlen;
                    }
                }
                break;
            } else {
                tlen++;
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