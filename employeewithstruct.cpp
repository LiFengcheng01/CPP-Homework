#include <iostream>
using namespace std;
typedef struct date
{
	string year;
	string month;
} DATE;
typedef struct employee
{
	string name;
	string ecodes;
	float sal;
	DATE birthday;
	float otsal;
	float tax;
	float truesal;	
} EMP; 
bool fullflag=0;
int index=0;
int search(EMP *employ);
int deleteinfo(int deleteindex);
int searchonce(EMP *employ);
void printemp();
//show the function menus
void showMenu()
{		if(fullflag)
			cout << "##���ݿ�����##" <<endl<<endl;
        cout << "0:Ա����Ϣ¼��" << endl;
        cout << "1:����������ѯ" << endl;
        cout << "2:ɾ��Ա����Ϣ" << endl;
        cout << "3:���������Ϣ" << endl;
        cout << "4:�޸�Ա����Ϣ" << endl;
        cout << "e:�˳�" << endl;
}

//define the global variable to store employee information
EMP employ[100];
int main()
{
        while(true)
        	{    
                showMenu();
                char fs = ' ';
                cout << "#��ѡ����:";
                cin >> fs;
				if (fs=='0')
                {
					system("cls");
                	cout<<"#��������Ϣ,��ʽΪ������ ���� ������� �����·� ���� �Ӱ๤��,������������ݣ�Ctrl+Z+Enter������"<<endl;
                	while(cin>>employ[index].name>>employ[index].ecodes>>employ[index].birthday.year>>employ[index].birthday.month>>employ[index].sal>>employ[index].otsal)
						{			
									if((employ[index].sal+employ[index].otsal)>3500.0)		
									employ[index].tax=(employ[index].sal+employ[index].otsal-3500.0)*0.05;
									else 
									employ[index].tax=0;
									employ[index].truesal=employ[index].sal+employ[index].otsal-employ[index].tax;
									index++;
                      	         	if(index>99)
                       	                {
                                            break;
                                        }
                		}
                        system("cls");
        		}
				else if (fs=='1')
                {
                	system("cls");
                	cout<<"#����������,�ɲ�ѯ�������ݣ�Ctrl+Z+Enter������"<<endl;;
                	search(employ);
                	system("cls");
				}
              	else if (fs=='2')
                {	
                	system("cls");
					char flag=' '; 
                	int deleteindex;
                	errorpoint1: 
                	cout<<"#��������Ҫɾ����Ա������ "<<endl; 
                	deleteindex=searchonce(employ);
                	if(deleteindex==-1)
                		goto errorpoint1;
					cout<<"#��ȷ��Ҫɾ����һ����Ϣ��������yȷ��,�������������ַ�ȡ����"<<endl;
					cin>>flag;
					if(flag=='y')
						deleteinfo(deleteindex);
					system("cls");
                }
                else if (fs=='3')
                {	
                	system("cls");
					printemp();
					cout<<"#�����������������"<<endl; 
					getchar();
					getchar();
					system("cls");
            	}
            	else if (fs=='4')
                {	
                	int m;
                	system("cls");
                	errorpoint2: 
              		cout<<"#��������Ҫ�޸ĵ�Ա������ "<<endl; 
                	m=searchonce(employ);
                	if(m==-1)
                		goto errorpoint2;
					cout<<"#�������µ���Ϣ,��ʽΪ������ ���� ������� �����·� ���� �Ӱ๤��"<<endl;
              		cin>>employ[m].name>>employ[m].ecodes>>employ[m].birthday.year>>employ[m].birthday.month>>employ[m].sal>>employ[m].otsal; 
                		if((employ[m].sal+employ[m].otsal)>3500.0)		
							employ[m].tax=(employ[m].sal+employ[m].otsal-3500.0)*0.05;
						else 
							employ[m].tax=0;
						employ[m].truesal=employ[m].sal+employ[m].otsal-employ[m].tax;
                		system("cls");
            	}
  				else if (fs=='e')
                	break;
                if(index>99)
       				fullflag=1;
                else
                    fullflag=0;
                cin.clear();
			}
} 
int search(EMP *employ)
{	
	int i,f=0;
	string M;
	while(cin>>M)
	{	
		f=0;
		for(i=0;i<index;i++)
			if(employ[i].name==M)
			{
				cout<<employ[i].name<<" "<<employ[i].ecodes<<" "<<employ[i].birthday.year<<" "<<employ[i].birthday.month<<" "<<employ[i].sal<<" "<<employ[i].otsal<<" "<<employ[i].tax<<" "<<employ[i].truesal<<endl;
				f=1;
				break;
			} 
		if(!f)
		cout<<"#���ݿ���û��������Ϣ"<<endl;
	}
	return 0; 
}
int deleteinfo(int deleteindex)
{
	for(int i=deleteindex;i<index-1;i++)
		employ[i]=employ[i+1];
	index--; 
}
int searchonce(EMP *employ)
{	
	int i,f=0;
	string M;
	cin>>M;
	for(i=0;i<index;i++)
		if(employ[i].name==M)
		{
			cout<<employ[i].name<<" "<<employ[i].ecodes<<" "<<employ[i].birthday.year<<" "<<employ[i].birthday.month<<" "<<employ[i].sal<<" "<<employ[i].otsal<<" "<<employ[i].tax<<" "<<employ[i].truesal<<endl;
			f=1; 
			break; 
		} 
		if(!f)
		{ 
		 	cout<<"#���ݿ���û��������Ϣ"<<endl;
		 	return -1; 
		} 
	return i; 	
}
void printemp()
{
	for(int i=0;i<index;i++)	
		cout<<employ[i].name<<" "<<employ[i].ecodes<<" "<<employ[i].birthday.year<<" "<<employ[i].birthday.month<<" "<<employ[i].sal<<" "<<employ[i].otsal<<" "<<employ[i].tax<<" "<<employ[i].truesal<<endl;
}




 

