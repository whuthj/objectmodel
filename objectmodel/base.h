#pragma once

#include<iostream>

class Base
{
public:
    Base(int n)
    {
        iBase = n;
        cout << "Base " << endl;
    }

    virtual ~Base(void)
    {
        cout << "~Base " << endl;
    }

    int getIBase() const
    {
        cout << "getIBase " << endl;
        return iBase;
    }

    static int instanceCount()
    {
        cout << "instanceCount " << endl;
        return count;
    }

    virtual void print() const
    {
        cout << "print " << iBase << endl;
    }

protected:
    int iBase;
    static int count;
};

__declspec(selectany) int Base::count = 0;