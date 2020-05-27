/*
394. 字符串解码
给定一个经过编码的字符串，返回它解码后的字符串。

编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。

你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。

此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。

示例:

s = "3[a]2[bc]", 返回 "aaabcbc".
s = "3[a2[c]]", 返回 "accaccacc".
s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef".

*/

string decodeString(string s) {
	int count = 0;
	string tempS = "";
	stack<string> sStr;
	stack<int> sCount;
	string myStr = "";
	int myTime = 0;
	for (char a : s)
	{
		if (isdigit(a))
		{
			count = count * 10 + a - '0';
		}
		else if ('[' == a)
		{
			if (tempS != "")
			{
				sStr.push(tempS);
				tempS = "";
			}
			sCount.push(count);
			sStr.push("[");
			count = 0;
		}
		else if (']' == a)
		{
			myStr = "";
			myTime = sCount.top();
			sCount.pop();
			while (sStr.top() != "[")
			{
				tempS = sStr.top() + tempS;
				sStr.pop();
			}
			for (int i = 0; i < myTime; i++)
			{
				myStr += tempS;
			}
			sStr.pop();
			while (!sStr.empty() && sStr.top() != "[")
			{
				tempS = sStr.top();
				sStr.pop();
				myStr = tempS + myStr;
			}
			sStr.push(myStr);
			tempS = "";
		}
		else
		{
			tempS += a;
		}
	}
	if (sStr.empty())
	{
		return tempS;
	}
	return sStr.top() + tempS;
}