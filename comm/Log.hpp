/*
 * Log.hpp
 *
 *      Author: ruanbo
 */

#ifndef COMM_LOG_HPP_
#define COMM_LOG_HPP_


#ifndef DEBUG_MODE
    #define DEBUG_MODE
#endif


#include <stdio.h>
#include <stdarg.h>

#include <sys/syscall.h>

#define Log(...) { printf(__VA_ARGS__); printf("\n"); }
#define LogError(...) { printf("ERROR:"); printf(__VA_ARGS__); printf("\n"); }

#define LogLine(...) { printf(__VA_ARGS__); }

#define LogFunc {printf("%s\n", __FUNCTION__);}
#define LogFile {printf("%s\n", __FILE__);}

#define LogTid() {printf("%s:%s[threadid:%ld] \n", __FILE__, __FUNCTION__, syscall(__NR_gettid)); };


void LogDebug(const char* fmt, ...);

//#define LogError(...) { printf(__FILE__":%d ", __LINE__); printf("ERROR:"); printf(__VA_ARGS__); printf("\n"); }

#define DebugFileFunc {printf("[DEBUG TRACE] "); printf(__FILE__", %s:%d \n", __func__, __LINE__);}

#endif /* COMM_LOG_HPP_ */
