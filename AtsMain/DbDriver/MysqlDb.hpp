/*
 * MysqlDb.hpp
 *
 *      Author: ruanbo
 */

#ifndef DB_MYSQLDB_HPP_
#define DB_MYSQLDB_HPP_


#include <comm/comm.hpp>
#include "utils/Buffer.hpp"

#include "ctp/ThostFtdcUserApiStruct.h"

#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>


#include <cppconn/driver.h>
#include <cppconn/connection.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/metadata.h>
#include <cppconn/warning.h>



using MysqlConnPtr = std::tr1::shared_ptr<sql::Connection>;
using MysqlStatementPtr = std::tr1::shared_ptr<sql::Statement>;
using MysqlResPtr = std::tr1::shared_ptr<sql::ResultSet>;
using MysqlPreStatePtr = std::tr1::shared_ptr<sql::PreparedStatement>;

//using MysqlStatementPtr = std::tr1::shared_ptr<sql::Statement>;

class MysqlDb : public NonCopyable
{
private:
    sql::Driver *_driver;
    MysqlConnPtr _conn;
    MysqlStatementPtr _stmt;
    MysqlResPtr _res;
    MysqlPreStatePtr _pstmt;

    BufferPtr _buffer;

    string _db_addr;
    string _db_user;
    string _db_passwd;

    string _db_name;

public:
    MysqlDb(const string& addr, const string& user, const string& passwd);
    virtual ~MysqlDb();

public:
    bool init();
    void unit();

    bool isOk();
    void reconnect();

private:
    bool init_sql();

    bool execute_sql(const string& sql);

    MysqlResPtr execute_query(const string& query_sql);

    int execute_pre_update(const MysqlPreStatePtr& pre_stat);

    template<typename ... Args>
    string string_format(const string& format, Args ... args)
    {
        size_t size = 1 + snprintf(nullptr, 0, format.c_str(), args ...);
        while(size >= _buffer->size())
        {
            _buffer->append();
        }
        _buffer->tozero();

        snprintf(_buffer->data(), size, format.c_str(), args ...);
        return string(_buffer->data(), _buffer->data() + size);
    }

public:
    bool check_name_registered(const string& name);
    bool register_user(const string& name, const string& passwd, time_t time=0);
    int get_uid(const string& name, const string& passwd);

public:
    bool setttlement_confirm(const string& date, time_t t);
    bool is_settlement_confirmed(const string& date);

public:
    bool tick_data(const CThostFtdcDepthMarketDataField* tick);
};


using MysqlDbPtr = std::tr1::shared_ptr<MysqlDb>;


#endif /* SERVER_DB_MYSQLDB_HPP_ */
