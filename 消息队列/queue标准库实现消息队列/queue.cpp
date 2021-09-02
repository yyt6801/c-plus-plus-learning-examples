#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

int main(int argc, char **argv)
{
	queue<string> q;
	//q.size()//返回队列 / 堆大小
	//q.empty()// 返回队列 / 堆是否为空
	//q.push(x) / q.pop()    //在队列中插入一个元素为x，弹出队头 / 堆顶元素。
	//q.front() / q.back()    //返回队列队头 / 队尾元素，优先队列不支持此操作。

	q.push("Hello World!111");
	q.push("China222");
	q.push("China333");
	q.push("China444");
	q.push("China555");
	cout << q.size() << endl;

	while (!q.empty()) {
		cout << q.front() << endl;
		q.pop(); //重复使用时，用这个初始化
	}
	return 0;
}