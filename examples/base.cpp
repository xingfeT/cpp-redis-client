#include "../src/cpp_redis_client.h"
#include <iostream>
#include <string>

int main()
{
    // 创建Redis连接
    CppRedisClient::RedisClient redisObj("localhost");

    // key string 和 value string
    const std::string key = "cpp_redis_client_test_key";
    const std::string value = "cpp_redis_client_test_value";

    // 设置key-value
    redisObj.set(key, value);

    // 根据key获取value，返回CppRedisClient::StringReply
    CppRedisClient::StringReply reply = redisObj.get(key);

    // CppRedisClient::StringReply重载了<<操作符，输出cpp_redis_client_test_value
    std::cout << reply << std::endl;

    // CppRedisClient::StringReply重载了==操作符，可以直接和std::string进行==比较
    assert(reply == value);

    // RedisClient::toString()返回std::string
    std::string getValue = reply.toString();
    std::cout << getValue << std::endl;

    // 删除key
    redisObj.del(key);

    // 再次获取value，返回null StringReply，可以用isNull()判断当前StringReply是否为null
    reply = redisObj.get(key);
    std::cout << reply.isNull() << std::endl;

    return 0;
}
