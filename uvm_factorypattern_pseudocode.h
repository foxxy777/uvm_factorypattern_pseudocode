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
    obj_d1() {//构造函数
        cout << "use user-defined constructor of obj_d1" << endl;
    };
    virtual void print() {
        cout << "obj_d1 instance already constructed" << endl;
    };


};

class obj_d2 :public object {
public:
    obj_d2() {//构造函数
        cout << "use user-defined constructor of obj_d2" << endl;
    };
    virtual void print() {
        cout << "obj_d2 instance already constructed" << endl;
    };
    //typedef objectregistry<obj_d2> this_type;//确实是不能自己拎着自己的鞋子把自己提起来

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
    static inline objectregistry<T1>* me = NULL; //  这里简直了，使用C++17就能用inline 就可以将static的指针在类内指定成NULL 这种东西也太偏了

public:
    static objectregistry<T1>* get() {//get()通过单例模式的懒汉方法来造个registry<>的单例
        if (me == NULL)
        {  
            me = new objectregistry();
            cout << "造好单例objectregistry" << endl;


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
    };//准备用来替代上面的new



};





















/// <summary>
/// /////////////////在此试一下单例模式的懒汉方法实现
/// </summary>
class singleton {
private:
    singleton() {
        cout << "test" << endl;
    };
    static singleton* ptr;// = NULL;//需要在cpp里面声明这个ptr = NULL;不然会报错，并且不能在头文件这里声明
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



