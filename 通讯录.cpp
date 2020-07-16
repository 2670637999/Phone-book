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
/**��ʼ����ϵ��**/
void CreatePerson(Data * data){
	ifstream ifs;
	ifs.open("Person.xml",ios::in|ios::binary);
	if(ifs.is_open()){
		cout << "�ļ��򿪳ɹ�,���ڶ�������" << endl;
		string buf;
		cout << "���ڶ�ȡ����" << endl;
		cout << "���ڶ�ȡ�Ա�" << endl;
		cout << "���ڶ�ȡ����" << endl;
		cout << "���ڶ�ȡ�绰" << endl;
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
		cout << "��ȡ���" <<endl;
		ifs.close();
		
	}else{
		
		ofstream ofs;
		cout << "�ļ�������,���ڳ�ʼ���ļ�����" << endl;
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

/*�����ϵ��*/
void AddPerson(Data * data){
	if(data->sum == MAX){
		cout << "ͨѶ¼����: "<<endl;
		return;
	}else{
		string name;
		string sex;
		string age;
		string addr;
		string phone;
		cout << "����������: "<< endl;
		cin >> name;
		for (int i = 0; i < MAX; i++)
		{
			if(name == data->person[i].name){
				cout << "�Ѵ��ڸ�����" <<endl;
				system("pause");
				return;
			}	
		}
		data->person[data->sum].name = name;
		cout << "�������Ա�: "<< endl;
		cin >> sex;
		data->person[data->sum].sex = sex;
		cout << "����������: "<< endl;
		cin >> age;
		data->person[data->sum].age = age;
		cout << "������绰: "<< endl;
		cin >> phone;
		for (int i = 0; i < MAX; i++)
		{
			if(phone == data->person[i].phone){
				cout << "�Ѵ��ڸú���" <<endl;
				cout << "������ֹ����" << endl;
				system("pause");
				return;
			}	
		}
		data->person[data->sum].phone = phone;
		cout << "���������ϵ��... "<< endl;
		data->sum += 1;
		system("pause");
	}
}
/*ɾ����ϵ��*/
void deletePerson(Data * data){
	string name;
	cout << "������Ҫɾ������ϵ��: "<< endl;
	cin >> name;
	for (int i = 0; i < MAX; i++)
	{
		if(name != data->person[i].name){
			cout << "�����ڸ���ϵ��,�޷�ɾ��" <<endl;
			break;
		}else if(name == data->person[i].name){
			data->person[i].name = "";
			data->person[i].sex = "";
			data->person[i].age = "";
			data->person[i].phone = "";
			cout << "��ɾ����ϵ��... "<< endl;
			data->sum -= 1;
			break;
		}
	}
	system("pause");
}
/*������ϵ��*/
void lookupPerson(Data * data){
	string name;
	cout << "������Ҫ���ҵ���ϵ��: "<< endl;
	cin >> name;
	for (int i = 0; i < MAX; i++)
	{
		if(name == data->person[i].name){
			cout << "\n����\t�Ա�\t����\t�绰" << endl;
			cout << "------------------------------------" << endl;
			cout << data->person[i].name << "\t" << data->person[i].sex <<
			"\t" << data->person[i].age <<"\t"<< data->person[i].phone <<endl;
		}else if(name != data->person[i].name){
			cout << "���޴���" <<endl;
			system("pause");
			return;
		}
	}
	cout << "\n\n��ѯ���"<<endl;
	system("pause");
	
}
/*�޸���ϵ��*/
void modifyPerson(Data * data){
	string name;
	cout << "������Ҫ�޸ĵ���ϵ��: "<< endl;
	cin >> name;
	for (int i = 0; i < MAX; i++)
	{
		if(name == data->person[i].name){
			string inputString;
			cout << "�޸���? (����)(�Ա�)(����)(�绰):  "<< endl;
			cin >> inputString;
			if(inputString == "����"){
				string inputName;
				cout << "�޸�����Ϊ? :  "<< endl;
				cin >> inputName;
				data->person[i].name = inputName;
				cout << "\n�޸����"<<endl;
				system("pause");
			}else if(inputString == "�Ա�"){
				string inputSex;
				cout << "�޸��Ա�Ϊ? :  "<< endl;
				cin >> inputSex;
				data->person[i].sex = inputSex;
				cout << "\n�޸����"<<endl;
				system("pause");
			}else if(inputString == "����"){
				string inputAge;
				cout << "�޸�����Ϊ? :  "<< endl;
				cin >> inputAge;
				data->person[i].age = inputAge;
				cout << "\n�޸����"<<endl;
				system("pause");
			}else if(inputString == "�绰"){
				string inputPhone;
				cout << "�޸ĵ绰Ϊ? :  "<< endl;
				cin >> inputPhone;
				data->person[i].phone = inputPhone;
				cout << "\n�޸����"<<endl;
				system("pause");
			}
		}else if(name != data->person[i].name){
			cout << "���޴���" <<endl;
			system("pause");
			return;
		}
	}
}
/*�����ϵ��*/
void emptyData(Data * data){
	short inputValue;
	cout << "ȷ��Ҫ���������ϵ����? [1]��  [2]�� : "<< endl;
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
		cout << "���������������..."<< endl;
		system("pause");
	}else if(inputValue == 0){
		
	}
}
/*��ʾͨѶ¼*/
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
		cout << "|-[1]�����ϵ��-|" <<endl;	
		cout << "+---------------+" <<endl;
		cout << "|-[2]��ʾ��ϵ��-|" <<endl;	
		cout << "+---------------+" <<endl;
		cout << "|-[3]ɾ����ϵ��-|" <<endl;	
		cout << "+---------------+" <<endl;
		cout << "|-[4]������ϵ��-|" <<endl;	
		cout << "+---------------+" <<endl;
		cout << "|-[5]�޸���ϵ��-|" <<endl;	
		cout << "+---------------+" <<endl;
		cout << "|-[6]�����ϵ��-|" <<endl;	
		cout << "+---------------+" <<endl;
		cout << "|-[0]���沢�˳�-|" <<endl;	
		cout << "+---------------+" <<endl;
		cout << "��������ز���: ";
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
			cout << "���ڱ������ݲ��˳�����...\n"<<endl;
			break;
		}else if(inputValue == 1){
			AddPerson(data1);

		}else if(inputValue == 2){
			if(data.sum == 0){
				cout << "ͨѶ¼�ǿյ�" <<endl;
				system("pause");
			}else{
				cout << "\n����\t�Ա�\t����\t�绰" << endl;
				for (int i = 0; i < data.sum; i++)
				{
					cout << "------------------------------------" << endl;
					cout << data.person[i].name <<"\t"<< data.person[i].sex <<"\t" << data.person[i].age <<"\t" << data.person[i].phone << endl;
				}
				cout << "\n����ϵ�� = " << data.sum <<endl;
				cout << endl;
				system("pause");
			}
		}else if(inputValue == 3){
			if(data.sum == 0){
				cout << "ͨѶ¼�ǿյ�" <<endl;
				system("pause");
			}else{
				deletePerson(data1);	
			}
		}else if(inputValue == 4){
			if(data.sum == 0){
				cout << "ͨѶ¼�ǿյ�" <<endl;
				system("pause");
			}else{
				lookupPerson(data1);	
			}
		}else if(inputValue == 5){
			if(data.sum == 0){
				cout << "ͨѶ¼�ǿյ�" <<endl;
				system("pause");
			}else{
				modifyPerson(data1);
			}
		}else if(inputValue == 6){
			if(data.sum == 0){
				cout << "ͨѶ¼�ǿյ�" <<endl;
				system("pause");
			}else{
				emptyData(data1);
			}
		}else{
			cout << "������Ч����,����������" <<endl; 
			system("pause");
		}
	}
}
int main(){
	showMenu();	
	return 0;
}