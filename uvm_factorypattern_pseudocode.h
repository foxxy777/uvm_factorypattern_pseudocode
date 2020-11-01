#pragma once

#include <iostream>
#include <map>
using namespace std;

class object {
public:
    virtual void print() {};

};

class obj_d1 :public object {
public:
    obj_d1() {//���캯��
        cout << "use user-defined constructor of obj_d1" << endl;
    };
    virtual void print() {
        cout << "obj_d1 instance already constructed" << endl;
    };


};

class obj_d2 :public object {
public:
    obj_d2() {//���캯��
        cout << "use user-defined constructor of obj_d2" << endl;
    };
    virtual void print() {
        cout << "obj_d2 instance already constructed" << endl;
    };
    //typedef objectregistry<obj_d2> this_type;//ȷʵ�ǲ����Լ������Լ���Ь�Ӱ��Լ�������

};


template<typename T1>
class objectproxy {
public:
    virtual T1 createobj() {
        T1 t1;
        return t1;
    };

};

template<typename T1>
class objectwrapper : public objectproxy<T1> {
public:
    virtual T1 createobj() {
        cout << "createobj of ojectwrapper" << endl;
        T1 t1;
        t1.print();
        return t1;
    };

};


template<typename T1>
class objectregistry : public objectproxy<T1> {
private:
    objectregistry() {
        T1 t1;
        cout << "create T1 in objectregistry" << endl;
    };
    static inline objectregistry<T1>* me = NULL; //  �����ֱ�ˣ�ʹ��C++17������inline �Ϳ��Խ�static��ָ��������ָ����NULL ���ֶ���Ҳ̫ƫ��

public:
    static objectregistry<T1>* get() {//get()ͨ������ģʽ���������������registry<>�ĵ���
        if (me == NULL)
        {  
            me = new objectregistry();
            cout << "��õ���objectregistry" << endl;


            return me;
        }
        else
        {
            return me;
        }
    };

    static T1 createObj() {
        T1 t_h;
        return t_h;
    };//׼��������������new



};





















/// <summary>
/// /////////////////�ڴ���һ�µ���ģʽ����������ʵ��
/// </summary>
class singleton {
private:
    singleton() {
        cout << "test" << endl;
    };
    static singleton* ptr;// = NULL;//��Ҫ��cpp�����������ptr = NULL;��Ȼ�ᱨ�����Ҳ�����ͷ�ļ���������
    public:
        static singleton* get() {
            if (ptr == NULL) {
                ptr = new singleton();
                return ptr;
            }
            else
                return ptr;
        };
        void func();
};



