// objectmodel.cpp : 定义控制台应用程序的入口点。
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
    cout << "对象b1的起始内存地址：" << &b1 << endl;
    cout << "type_info信息：" << ((int*)*(int*)(&b1) - 1) << endl;
    RTTICompleteObjectLocator local = *((RTTICompleteObjectLocator*)*((int*)*(int*)(&b1) - 1));
    string classname(local.typeInfo->name());
    cout << classname.c_str() << endl;
    cout << "虚函数表地址：\t\t\t" << (int*)(&b1) << endl;
    cout << "虚函数表 — 第1个函数地址：\t" << (int*)*(int*)(&b1) << "\t即析构函数地址：" << (int*)*((int*)*(int*)(&b1)) << endl;
    cout << "虚函数表 — 第2个函数地址：\t" << ((int*)*(int*)(&b1) + 1) << "\t";
    typedef void(*Fun)(void);
    Fun pFun = (Fun)*(((int*)*(int*)(&b1)) + 1);
    pFun();
    //b1.print();
    cout << endl;
    cout << "推测数据成员iBase地址：\t\t" << ((int*)(&b1) + 1) << "\t通过地址取值iBase的值：" << *((int*)(&b1) + 1) << endl;
    cout << "Base::getIBase(): " << b1.getIBase() << endl;

    b1.instanceCount();
    cout << "静态函数instanceCount地址： " << b1.instanceCount << endl;
}