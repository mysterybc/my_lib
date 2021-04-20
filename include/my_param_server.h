#pragma once
//ros
#include <ros/ros.h>
//c++
#include <string>
#include <vector>
#include <iostream>
//my lib
#include "my_debug_info.h"

namespace my_lib{
    /**
     * @brief  get param from param server
     * @param: node_name
     *         car_id
     *         total_car_num
     *         tf_ns
     *         my_ip
     *         host_ip
     *         total_ip
     */
    class ParamServer{
    public:
        void GetParam(std::string node_name);

        std::string my_ip;
        std::string host_ip;
        std::string tf_ns;
        int car_id;
        int total_car_number;
        bool is_simulation;
        std::string localization_topic;
        std::vector<std::string> total_ip;
    };
    //end of struct ParamServer

}
//end of namespace my_lib