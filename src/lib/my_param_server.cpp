#include "my_param_server.h"

using namespace my_lib;
void ParamServer::GetParam(std::string node_name)
{
    Debug::DebugLogger logger;

    //获取group空间名
    ros::NodeHandle nh;
    std::string namespace_;
    namespace_ = nh.getNamespace();

    //依次获取所有param
    //1. car id
    if(!nh.getParam(namespace_+"/car_id",car_id)){
        car_id = 1;
        logger.WARNINFO("%s FAILED TO GET CAR ID",node_name.c_str());
        logger.WARNINFO("%s RESET CAR ID TO 1",node_name.c_str());
    }
    logger.init_logger(car_id);

    //2.car num
    if(!nh.getParam("/total_car_number",total_car_number)){
        logger.WARNINFO(car_id,"%s FAILED TO GET TOTAL CAR NUMBER",node_name.c_str());
    }

    //3.tf ns
    if(!nh.getParam(namespace_+"/tf_ns",tf_ns)){
        logger.WARNINFO(car_id,"%s FAILED TO GET TF FRAME",node_name.c_str());
    }

    //4.my ip
    if(!nh.getParam(namespace_+"/my_ip_address",my_ip)){
        logger.WARNINFO(car_id,"%s FAILED TO GET MY IP",node_name.c_str());
    }


    //5. host ip
    if(!nh.getParam("/host_ip_address",host_ip)){
        logger.WARNINFO(car_id,"%s FAILED TO GET HOST IP",node_name.c_str());
    }

    //6. total ip
    if(!nh.getParam("/total_robot_ip",total_ip)){
        logger.WARNINFO(car_id,"%s FAILED TO GET TOTAL ROBOT IP",node_name.c_str());
    }

    //7. is simulation
    if(!nh.getParam("/is_simulation",is_simulation)){
        is_simulation = true;
        logger.WARNINFO(car_id,"%s FAILED TO GET SIMULATION FLAG",node_name.c_str());
        logger.WARNINFO(car_id,"DEFAULT SET SIMULATION MODE",node_name.c_str());
    }
    //8. localization topic
    if(!nh.getParam("/localization_topic",localization_topic)){
        localization_topic = "odom";
        logger.WARNINFO(car_id,"%s FAILED TO GET LOCALIZATION TOPOIC",node_name.c_str());
        logger.WARNINFO(car_id,"DEFAULT SET  TO ODOM",node_name.c_str());
    }

    logger.DEBUGINFO(car_id," %s get param success!! ",node_name.c_str());

}