#include <iostream>
#include <string.h>
#include <regex>
#include <fstream>
using namespace std;
#define MAX 1000

short inputValue;

struct Person{
	string name;
	string sex;
	string age;
	string phone;
};
struct Data{
	Person person[MAX];
	int sum;
};
/**初始化联系人**/
void CreatePerson(Data * data){
	ifstream ifs;
	ifs.open("Person.xml",ios::in|ios::binary);
	if(ifs.is_open()){
		cout << "文件打开成功,正在读出数据" << endl;
		string buf;
		cout << "正在读取姓名" << endl;
		cout << "正在读取性别" << endl;
		cout << "正在读取年龄" << endl;
		cout << "正在读取电话" << endl;
		while (getline(ifs,buf))
		{

			regex nameRx("<name>(.*)</name>");
			regex sexRx("<sex>(.*)</sex>");
			regex ageRx("<age>(.*)</age>");
			regex phoneRx("<phone>(.*)</phone>");
			smatch m;
			if(regex_search(buf,m,nameRx)){
				for (auto it = m.begin(); it != m.end(); it++){
					data->person[data->sum].name = *it;
				}
			}
			if(regex_search(buf,m,sexRx)){
				for (auto it = m.begin(); it != m.end(); it++){
					data->person[data->sum].sex = *it;
				}
			}
			if(regex_search(buf,m,ageRx)){
				for (auto it = m.begin(); it != m.end(); it++){
					data->person[data->sum].age = *it;
				}
			}    
			if(regex_search(buf,m,phoneRx)){
				for (auto it = m.begin(); it != m.end(); it++){
					data->person[data->sum].phone = *it;
				}
				data->sum += 1;
			}
		}
		cout << "读取完成" <<endl;
		ifs.close();
		
	}else{
		
		ofstream ofs;
		cout << "文件不存在,正在初始化文件数据" << endl;
		ofs.open("Person.xml",ios::out|ios::binary);
		for (int i = 0; i < data->sum; i++)
		{		
			ofs << "<name>" << data->person[i].name << "</name>\n";
			ofs << "<sex>" << data->person[i].name << "</sex>\n";
			ofs << "<age>" << data->person[i].name << "</age>\n";
			ofs << "<phone>" << data->person[i].name << "</phone>\n";
			ofs << "\n";
		}
		ofs.close();
		
	}
}

/*添加联系人*/
void AddPerson(Data * data){
	if(data->sum == MAX){
		cout << "通讯录已满: "<<endl;
		return;
	}else{
		string name;
		string sex;
		string age;
		string addr;
		string phone;
		cout << "请输入姓名: "<< endl;
		cin >> name;
		for (int i = 0; i < MAX; i++)
		{
			if(name == data->person[i].name){
				cout << "已存在该姓名" <<endl;
				system("pause");
				return;
			}	
		}
		data->person[data->sum].name = name;
		cout << "请输入性别: "<< endl;
		cin >> sex;
		data->person[data->sum].sex = sex;
		cout << "请输入年龄: "<< endl;
		cin >> age;
		data->person[data->sum].age = age;
		cout << "请输入电话: "<< endl;
		cin >> phone;
		for (int i = 0; i < MAX; i++)
		{
			if(phone == data->person[i].phone){
				cout << "已存在该号码" <<endl;
				cout << "正在终止操作" << endl;
				system("pause");
				return;
			}	
		}
		data->person[data->sum].phone = phone;
		cout << "正在添加联系人... "<< endl;
		data->sum += 1;
		system("pause");
	}
}
/*删除联系人*/
void deletePerson(Data * data){
	string name;
	cout << "请输入要删除的联系人: "<< endl;
	cin >> name;
	for (int i = 0; i < MAX; i++)
	{
		if(name != data->person[i].name){
			cout << "不存在该联系人,无法删除" <<endl;
			break;
		}else if(name == data->person[i].name){
			data->person[i].name = "";
			data->person[i].sex = "";
			data->person[i].age = "";
			data->person[i].phone = "";
			cout << "已删除联系人... "<< endl;
			data->sum -= 1;
			break;
		}
	}
	system("pause");
}
/*查找联系人*/
void lookupPerson(Data * data){
	string name;
	cout << "请输入要查找的联系人: "<< endl;
	cin >> name;
	for (int i = 0; i < MAX; i++)
	{
		if(name == data->person[i].name){
			cout << "\n姓名\t性别\t年龄\t电话" << endl;
			cout << "------------------------------------" << endl;
			cout << data->person[i].name << "\t" << data->person[i].sex <<
			"\t" << data->person[i].age <<"\t"<< data->person[i].phone <<endl;
		}else if(name != data->person[i].name){
			cout << "查无此人" <<endl;
			system("pause");
			return;
		}
	}
	cout << "\n\n查询完毕"<<endl;
	system("pause");
	
}
/*修改联系人*/
void modifyPerson(Data * data){
	string name;
	cout << "请输入要修改的联系人: "<< endl;
	cin >> name;
	for (int i = 0; i < MAX; i++)
	{
		if(name == data->person[i].name){
			string inputString;
			cout << "修改项? (姓名)(性别)(年龄)(电话):  "<< endl;
			cin >> inputString;
			if(inputString == "姓名"){
				string inputName;
				cout << "修改姓名为? :  "<< endl;
				cin >> inputName;
				data->person[i].name = inputName;
				cout << "\n修改完毕"<<endl;
				system("pause");
			}else if(inputString == "性别"){
				string inputSex;
				cout << "修改性别为? :  "<< endl;
				cin >> inputSex;
				data->person[i].sex = inputSex;
				cout << "\n修改完毕"<<endl;
				system("pause");
			}else if(inputString == "年龄"){
				string inputAge;
				cout << "修改年龄为? :  "<< endl;
				cin >> inputAge;
				data->person[i].age = inputAge;
				cout << "\n修改完毕"<<endl;
				system("pause");
			}else if(inputString == "电话"){
				string inputPhone;
				cout << "修改电话为? :  "<< endl;
				cin >> inputPhone;
				data->person[i].phone = inputPhone;
				cout << "\n修改完毕"<<endl;
				system("pause");
			}
		}else if(name != data->person[i].name){
			cout << "查无此人" <<endl;
			system("pause");
			return;
		}
	}
}
/*清空联系人*/
void emptyData(Data * data){
	short inputValue;
	cout << "确定要清空所有联系人吗? [1]是  [2]否 : "<< endl;
	cin >> inputValue;
	if(inputValue == 1){
		for (int i = 0; i < MAX; i++)
		{
			data->person[i].name="";
			data->person[i].sex="";
			data->person[i].age="";
			data->person[i].phone="";
		}
		data->sum = 0;
		cout << "正在清空所有数据..."<< endl;
		system("pause");
	}else if(inputValue == 0){
		
	}
}
/*显示通讯录*/
void showMenu(){
	Data data;
	Data * data1 = &data;
	data.sum = 0;
	CreatePerson(data1);
	system("pause");
	while (true)
	{
		system("cls");
		cout << "+---------------+" <<endl;
		cout << "|-[1]添加联系人-|" <<endl;	
		cout << "+---------------+" <<endl;
		cout << "|-[2]显示联系人-|" <<endl;	
		cout << "+---------------+" <<endl;
		cout << "|-[3]删除联系人-|" <<endl;	
		cout << "+---------------+" <<endl;
		cout << "|-[4]查找联系人-|" <<endl;	
		cout << "+---------------+" <<endl;
		cout << "|-[5]修改联系人-|" <<endl;	
		cout << "+---------------+" <<endl;
		cout << "|-[6]清空联系人-|" <<endl;	
		cout << "+---------------+" <<endl;
		cout << "|-[0]保存并退出-|" <<endl;	
		cout << "+---------------+" <<endl;
		cout << "请输入相关操作: ";
		cin >> inputValue;
		if(inputValue == 0){
			ofstream ofs;
			ofs.open("Person.xml",ios::out|ios::binary);
			for (int i = 0; i < data.sum; i++)
			{
				if(data1->sum==0){
					ofs << "<name>" << data1->person[i].name << "</name>\n";
				}else if(data1->sum>0){
					ofs << "\n<name>" << data1->person[i].name << "</name>\n";
				}
				ofs << "<sex>" << data1->person[i].sex << "</sex>\n";
				ofs << "<age>" << data1->person[i].age << "</age>\n";
				ofs << "<phone>" << data1->person[i].phone << "</phone>\n";
			}
			cout << "正在保存数据并退出程序...\n"<<endl;
			break;
		}else if(inputValue == 1){
			AddPerson(data1);

		}else if(inputValue == 2){
			if(data.sum == 0){
				cout << "通讯录是空的" <<endl;
				system("pause");
			}else{
				cout << "\n姓名\t性别\t年龄\t电话" << endl;
				for (int i = 0; i < data.sum; i++)
				{
					cout << "------------------------------------" << endl;
					cout << data.person[i].name <<"\t"<< data.person[i].sex <<"\t" << data.person[i].age <<"\t" << data.person[i].phone << endl;
				}
				cout << "\n总联系人 = " << data.sum <<endl;
				cout << endl;
				system("pause");
			}
		}else if(inputValue == 3){
			if(data.sum == 0){
				cout << "通讯录是空的" <<endl;
				system("pause");
			}else{
				deletePerson(data1);	
			}
		}else if(inputValue == 4){
			if(data.sum == 0){
				cout << "通讯录是空的" <<endl;
				system("pause");
			}else{
				lookupPerson(data1);	
			}
		}else if(inputValue == 5){
			if(data.sum == 0){
				cout << "通讯录是空的" <<endl;
				system("pause");
			}else{
				modifyPerson(data1);
			}
		}else if(inputValue == 6){
			if(data.sum == 0){
				cout << "通讯录是空的" <<endl;
				system("pause");
			}else{
				emptyData(data1);
			}
		}else{
			cout << "输入无效命令,请重新输入" <<endl; 
			system("pause");
		}
	}
}
int main(){
	showMenu();	
	return 0;
}