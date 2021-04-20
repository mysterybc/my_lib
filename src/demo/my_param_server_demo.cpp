#include "my_param_server.h"

int main(int argc,char** argv){
    ros::init(argc,argv,"my_param_server_demo");
    ros::NodeHandle nh;

    //init param
    std::string node_name = "test name server";

    //get param
    my_lib::ParamServer param_server;
    param_server.GetParam(node_name);

    std::cout << " car id is : " << param_server.car_id << std::endl;
    std::cout << " total car num is : " << param_server.total_car_num << std::endl;
    std::cout << " tf ns is : " << param_server.tf_ns << std::endl;
    std::cout << " my ip is : " << param_server.my_ip << std::endl;
    std::cout << " host ip is : " << param_server.host_ip << std::endl;
    for(auto id:param_server.debug_id){
        std::cout << " deug id is : " << id << std::endl;
    }
    for(auto ip:param_server.total_ip){
        std::cout << " total car ip is : " << ip << std::endl;
    }
    while(ros::ok());

    return 0;
    

}