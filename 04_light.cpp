/*
 * 题目内容
 *	未点亮路段长度
 * 题目描述:
 *	在一段路径上，一共有N(N ∈ [1, 100000])座路灯，已知路灯间距均为100m。
 *	现给出每个路灯的照亮范围light[i]且照亮范围在区间[1, 100 * N]内。
 *	求出该段路中，总共未照亮的路段长度。
 * 示例1
 *	输入: N = 2, light[] = [50,50]
 *	输出: 0
 * 示例2：
 *	输入: N = 6, light[] = [ 350, 40, 10, 150, 20, 10]
 *	输出: 40
 * 链接：https://leetcode-cn.com/circle/discuss/EIKoLV/
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

using range = struct {
	int sp;
	int ep;
};

bool cmplift(const range& a, const range& b) {
	/*
	 * 升序
	**/
	if (a.sp < b.sp) {
		return true;
	}
	else {
		return false;
	}
}

int nightlight(vector<int> rLight)
{
	int lenNight = 0;
	int liftBorder  = 0;

	int sLight = 100;
	int nLight = rLight.size();

	int sRoad = 0;
	int eRoad = (nLight - 1) * sLight;

	range tRange;
	vector<range> inRange;

	/*
	 * 构建区间
	**/
	for (int i = 0; i < nLight; i++) {
		tRange.sp = i * sLight - rLight[i];
		tRange.ep = i * sLight + rLight[i];
		if (tRange.sp < sRoad) {
			tRange.sp = sRoad;
		}
		if (tRange.ep > eRoad) {
			tRange.ep = eRoad;
		}
		inRange.push_back(tRange);
	}
	/*
	 * 起点升序
	**/
	sort(inRange.begin(), inRange.end(), cmplift);
	
	liftBorder =  inRange.begin()->ep;
	for(vector<range>::iterator it = inRange.begin()+1; it != inRange.end(); it++) {
		/*
		 * 计算黑区
		**/
		if (it->sp > liftBorder) {
			lenNight = lenNight + (it->sp - liftBorder);
		}
		/*
		 * 右边界维护
		**/
		liftBorder = max(liftBorder, it->ep);
	}
	return lenNight;
}

int main(int argc, char *argv[])
{
	int nLight;
	int tLight;
	vector<int> rLight;

	scanf("%d", &nLight);
	for (int i = 0; i < nLight; i++) {
		scanf("%d", &tLight);
		rLight.push_back(tLight);
	}

	printf("%d\n", nightlight(rLight));
	return 0;
}
