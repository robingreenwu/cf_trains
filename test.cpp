#define _CRT_SECURE_NO_WARNINGS 1
#ifndef STUDENTNAMESPACE_H
#define STUDENTNAMESPACE_H
#include <bits/stdc++.h>
using namespace std;
namespace mynumber {
	typedef struct aaa {
		int number;
		string name;
		string major;
		int ave;
	}student;
	void add_student(student*& stu_arr, int& stu_num, int number, string name, string major, int ave);
	void delete_student(student*& stu_arr, int& stu_num);
	void display(student* stu_arr, int stu_num);
	void display(int stu_num, student* stu_arr, int max_ave = 100, int min_ave = 0);
}
#endif	
namespace mynumber {
	void add_student(student*& stu_arr, int& stu_num, int number, string name, string major, int ave) {
		student* new_stu_arr = new student[stu_num + 1];
		int idx = 0;
		student* new_stu = new student;
		for (int i = 0; i < stu_num; i++) {
			new_stu_arr[i] = stu_arr[i];
		}
		new_stu_arr[stu_num] = { number,name,major,ave };
		delete[]stu_arr;
		stu_arr = new_stu_arr;

	}
	void delete_student(student*& stu_arr, int& stu_num) {
		int del_num;
		cout << "请输入要删除的学生学号: ";
		cin >> del_num;
		int idx = -1;
		for (int i = 0; i < stu_num - 1; i++) {
			if (stu_arr[i].number == del_num) {
				idx = i; break;
			}
		}
		if (idx == -1) {
			cout << "找不到这位学生！┭┮﹏┭┮" << '\n';
			return;
		}
		stu_num--;
		student* new_stu_arr = new student[stu_num];
		for (int i = 0, j = 0; i < stu_num + 1; i++) {
			if (i != idx)
			{
				new_stu_arr[j] = stu_arr[i];
				j++;
			}
		}
		delete[]stu_arr;
		stu_arr = new_stu_arr;
		cout << "学生信息删除成功啦！(*^▽^*)" << "\n";
	}
	void display(student* stu_arr, int stu_num) {
		if (stu_num == 0) {
			cout << "坏嘟嘟了！o(╥﹏╥)o没有学生信息" << "\n";
		}
		for (int i = 0; i < stu_num; i++) {
			cout << "学号： " << stu_arr[i].number << "\n";
			cout << "名字： " << stu_arr[i].name << "\n";
			cout << "专业： " << stu_arr[i].major << "\n";
			cout << "均分： " << stu_arr[i].ave << "\n";
			cout << "\n";
		}
	}
	void display(int stu_num, student* stu_arr, int max_ave, int min_ave ) {
		if (stu_num == 0) {
			cout << "坏嘟嘟了！o(╥﹏╥)o没有学生信息" << "\n";
		}
		for (int i = 0; i < stu_num; i++) {
			if (stu_arr[i].ave >= min_ave && stu_arr[i].ave <= max_ave)
			{
				cout << "学号： " << stu_arr[i].number << "\n";
				cout << "名字： " << stu_arr[i].name << "\n";
				cout << "专业： " << stu_arr[i].major << "\n";
				cout << "均分： " << stu_arr[i].ave << "\n";
				cout << "\n";
			}
		}
	}
}
using namespace mynumber;
int main() {
	using namespace mynumber;
	student* stu_arr = nullptr;
	int stu_num = 0;
	int op;
	while (true) {
		cout << "请选择您的操作呀！(*^▽^*)" << "\n";
		cout << "1.添加学生" << "\n";
		cout << "2.删除学生" << "\n";
		cout << "3.显示所有学生信息" << "\n";
		cout << "4.显示部分学生信息" << "\n";
		cout << "0.退出选项" << "\n";
		cout << "请开始您的选择吧！~o( =∩ω∩= )m" << "\n";
		cin >> op;
		switch (op) {
		case 1:
			cin >> stu_num;
			for (int i = 0; i < stu_num; i++)
			{
				int new_number;
				string new_name;
				string new_major;
				int new_ave;
				cout << "请输入学生的学号: ";
				cin >> new_number;
				cout << "请输入学生的姓名: ";
				cin >> new_name;
				cout << "请输入学生的专业: ";
				cin >> new_major;
				cout << "请输入学生的平均分: ";
				cin >> new_ave;
				add_student(stu_arr, i, new_number, new_name, new_major, new_ave);
			}
			cout << "学生信息添加成功啦！(*^▽^*)" << "\n";
			break;
		case 2:
			delete_student(stu_arr, stu_num);
			break;
		case 3:
			display(stu_arr, stu_num);
			break;
		case 4:
			int maxn, minn;
			cout << "您想要学生均分的最大值：" << "\n";
			cin >> maxn;
			cout << "您想要学生均分的最小值" << "\n";
			cin >> minn;
			display(stu_num, stu_arr, maxn, minn);
			break;
		case 0:
			delete[]stu_arr;
			return 0;
		default:
			cout << "怎么是无效的命令呀？o(╥﹏╥)o" << "\n";
			break;
		}
	}
	return 0;
}
