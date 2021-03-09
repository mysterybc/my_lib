#pragma once
#include "iostream"
#include "cstdio"
#include "string"
#include "vector"
#include <stdarg.h>
#include "ros/ros.h"

/**
 *  @description: this file is used for debug infomation 
 * */

namespace Debug{
    
    struct DebugLogger{
        /**
         * 调用这四个
         * 
         * */
        void DEBUGINFO(int id, const char *pszFmt, ...);

        void WARNINFO(int id,const char *pszFmt, ...);

        void DEBUGINFO(const char *pszFmt, ...);

        void WARNINFO(const char *pszFmt, ...);
        /**
         * 调用这四个
         * 
         * */
        /**
         * 用于初始化哪个车输出debug信息
         */
        void init_logger(int id);

        private:

        std::string format(const char *pszFmt, ...);

        std::string format_debug_msg(int id,const std::string &msg);

        std::string format_warn_msg(int id,const std::string &msg);

        std::string format_debug_msg(const std::string &msg);

        std::string format_warn_msg(const std::string &msg);

        bool should_output(int id);
        bool should_i_output;
    };


}

extern Debug::DebugLogger logger;


#include "my_debug_info.h"
#include "time.h"


namespace Debug{
    void DebugLogger::init_logger(int id){
        ros::NodeHandle nh;
        should_i_output = should_output(id);
    }

    std::string format(const char *pszFmt, ...)
    {
        std::string str;
        va_list args;
        va_start(args, pszFmt);
        {
            char data[100];
            vsnprintf(data, 100, pszFmt, args);
            str.assign(data);
        }
        va_end(args);
        return str;
    }

    std::string DebugLogger::format_debug_msg(int id,const std::string &msg){
        return "\033[40;37m[car " + std::to_string(id) + "] : " + msg + "\033[0m\n";
    }

    std::string DebugLogger::format_warn_msg(int id,const std::string &msg){
        return "\033[40;31m[car " + std::to_string(id) + "] : " + msg + "\033[0m\n";
    }

    std::string DebugLogger::format_debug_msg(const std::string &msg){
        return "\033[40;37m[unknow] : " + msg + "\033[0m\n";
    }

    std::string DebugLogger::format_warn_msg(const std::string &msg){
        return "\033[40;31m[unknow] : " + msg + "\033[0m\n";
    }

    void DebugLogger::DEBUGINFO(int id, const char *pszFmt, ...){
        if(!should_i_output){
            return ;
        }
        std::string str;
        va_list args;
        va_start(args, pszFmt);
        {
            char data[100];
            vsnprintf(data, 100, pszFmt, args);
            str.assign(data);
        }
        va_end(args);
        printf("%s",format_debug_msg(id,str).c_str());
    }

    void DebugLogger::WARNINFO(int id,const char *pszFmt, ...){
        if(!should_i_output){
            return ;
        }
        std::string str;
        va_list args;
        va_start(args, pszFmt);
        {
            char data[100];
            vsnprintf(data, 100, pszFmt, args);
            str.assign(data);
        }
        va_end(args);
        printf("%s",format_warn_msg(id,str).c_str());
    }

    void DebugLogger::DEBUGINFO(const char *pszFmt, ...){
        std::string str;
        va_list args;
        va_start(args, pszFmt);
        {
            char data[100];
            vsnprintf(data, 100, pszFmt, args);
            str.assign(data);
        }
        va_end(args);
        printf("%s",format_debug_msg(str).c_str());
    }

    void DebugLogger::WARNINFO(const char *pszFmt, ...){
        std::string str;
        va_list args;
        va_start(args, pszFmt);
        {
            char data[100];
            vsnprintf(data, 100, pszFmt, args);
            str.assign(data);
        }
        va_end(args);
        printf("%s",format_warn_msg(str).c_str());
    }

    bool DebugLogger::should_output(int id){
        ros::NodeHandle nh;
        std::vector<int> idList;
        nh.getParam("/debug_output_id",idList);
        if(std::find(idList.begin(),idList.end(),id) != idList.end()){
            return true;
        }
        return false;
    }

}