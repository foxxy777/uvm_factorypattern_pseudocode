#include "uvm_factorypattern_pseudocode.h"

int main() {
    
    //ǰ���ⲿ����proxyģʽʵ�ֵģ��ؼ�������������һ��������objectwrapper��Ȼ��ͨ��ָ���ַ�����������������õ�����󣬴Ӷ���������Ҫ�Ķ���

    objectwrapper<obj_d1> obj_wrapper1; //(1)ʹ��proxyģʽ��ֻ�����wrapper������������obj

    map<string, objectwrapper<obj_d1>> map1; // ��map��ģ��sv�����������
    auto temp_pr = make_pair("obj_d1", obj_wrapper1);
    auto map_ptr = map1.insert(temp_pr);//�����������������Ŷ�����key���ַ���"obj_d1"�����ݷŸղ��������wrapper
    map<string, objectwrapper<obj_d1>> ::iterator itr;
    itr = map1.find("obj_d1");
    if (itr != map1.end()) //���������������ҵ�����Ҫ�������"obj_d1"
    {
        (map1.at("obj_d1")).createobj(); //Ȼ����������������wrapper���������������Ҫ����obj_d1
    }

    //������factory����ʵ�ֵ�
    
    //singleton* s0 = singleton::get();

    objectregistry<obj_d1>* s1 = objectregistry<obj_d1>::get();//�������(1)�����Ӧ,������ֱ�����˸���������������ÿ��һ���������һ��wrapperҪ�߼�
    //map<objectregistry<obj_d1>,objectregistry<obj_d1 > factory_map;//C����û�а취ֱ�ӵ�����key���Ͳ�ͬ�Ĺ������飬����factory�ⲿ�ֵ�C++����ģ�ⲻ�����ģ���������ֻ��ֱ���ÿ�˵��

    

    return 0;
}
