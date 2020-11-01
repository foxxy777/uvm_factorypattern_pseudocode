#include "uvm_factorypattern_pseudocode.h"

int main() {
    
    //前面这部分是proxy模式实现的，关键点是我们先造一个代理类objectwrapper，然后通过指定字符串来调用这个创建好的类对象，从而建造我们要的对象

    objectwrapper<obj_d1> obj_wrapper1; //(1)使用proxy模式，只造出个wrapper，而不是先造obj

    map<string, objectwrapper<obj_d1>> map1; // 用map来模仿sv里的联合数组
    auto temp_pr = make_pair("obj_d1", obj_wrapper1);
    auto map_ptr = map1.insert(temp_pr);//往这个联合数组里面放东西，key放字符串"obj_d1"，内容放刚才造出来的wrapper
    map<string, objectwrapper<obj_d1>> ::iterator itr;
    itr = map1.find("obj_d1");
    if (itr != map1.end()) //在联合数组里面找到我们要造的类名"obj_d1"
    {
        (map1.at("obj_d1")).createobj(); //然后根据这个类名来在wrapper中真正地造出我们要的类obj_d1
    }

    //下面是factory机制实现的
    
    //singleton* s0 = singleton::get();

    objectregistry<obj_d1>* s1 = objectregistry<obj_d1>::get();//与上面第(1)步相对应,但这里直接做了个单例出来，比起每建一个对象就用一次wrapper要高级
    //map<objectregistry<obj_d1>,objectregistry<obj_d1 > factory_map;//C里面没有办法直接地做出key类型不同的关联数组，所以factory这部分的C++代码模拟不出来的，接下来就只能直接用口说了

    

    return 0;
}
