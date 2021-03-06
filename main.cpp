/*
 * main.cpp
 *
 *      Author: ruanbo
 */


#include "comm/Log.hpp"
#include "RunHelper.hpp"

#include "tests/test_head.hpp"

int main(int argc, const char *argv[])
{
    bool run_test = false;
    if(run_test)
    {
    	//测试入口
        test_entry();

        Log("\nend of main tests===");
        return 0;
    }

    LogTid();

    RunHelperPtr pRun = RunHelperPtr(new RunHelper());
    if(pRun->init() == false)
    {
        LogError("RunHelper failed");
        return 0;
    }

    pRun->run();

    Log("\n ==== end of main ==== ");
    return 0;
}





