// objectmodel.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "base.h"

void test_base_model();

int _tmain(int argc, _TCHAR* argv[])
{
    test_base_model();

    getchar();
	return 0;
}

void test_base_model()
{
    Base b1(1000);
    cout << "����b1����ʼ�ڴ��ַ��" << &b1 << endl;
    cout << "type_info��Ϣ��" << ((int*)*(int*)(&b1) - 1) << endl;
    RTTICompleteObjectLocator local = *((RTTICompleteObjectLocator*)*((int*)*(int*)(&b1) - 1));
    string classname(local.typeInfo->name());
    cout << classname.c_str() << endl;
    cout << "�麯�����ַ��\t\t\t" << (int*)(&b1) << endl;
    cout << "�麯���� �� ��1��������ַ��\t" << (int*)*(int*)(&b1) << "\t������������ַ��" << (int*)*((int*)*(int*)(&b1)) << endl;
    cout << "�麯���� �� ��2��������ַ��\t" << ((int*)*(int*)(&b1) + 1) << "\t";
    typedef void(*Fun)(void);
    Fun pFun = (Fun)*(((int*)*(int*)(&b1)) + 1);
    pFun();
    //b1.print();
    cout << endl;
    cout << "�Ʋ����ݳ�ԱiBase��ַ��\t\t" << ((int*)(&b1) + 1) << "\tͨ����ַȡֵiBase��ֵ��" << *((int*)(&b1) + 1) << endl;
    cout << "Base::getIBase(): " << b1.getIBase() << endl;

    b1.instanceCount();
    cout << "��̬����instanceCount��ַ�� " << b1.instanceCount << endl;
}