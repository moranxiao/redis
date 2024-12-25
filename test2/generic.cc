#include <sw/redis++/redis++.h>
#include <iostream>
#include <string>
#include <chrono>

#include "../utility.hpp"

using namespace std;

void test1(sw::redis::Redis& redis)
{
    cout << "get/set/mset" << endl;
    redis.flushdb();
    
    redis.set("key1","111");
    redis.set("key2", "222");
    redis.mset({make_pair("key3","3333"),make_pair("key4","4444")});

    auto value1 = redis.get("key1");
    cout << "key1:" << value1.value() << endl;

    auto value2 = redis.get("key2");
    cout << "key2:" << value2.value() << endl;

    auto value3 = redis.get("key3");
    cout << "key3:" << value2.value() << endl;

    auto value4 = redis.get("key4");
    cout << "key4:" << value4.value() << endl;

    auto value5 = redis.get("key5");
    if(value5) cout << "key5:" << value5.value() << endl;
}

void test2(sw::redis::Redis& redis)
{
    cout << "exists" << endl;
    redis.flushall();

    redis.set("key1","1111");

    cout << redis.exists("key1") << endl;
    cout << redis.exists("key2") << endl;
}

void test3(sw::redis::Redis& redis)
{
    cout << "keys" << endl;
    redis.flushall();

    redis.mset({make_pair("hehe",111),make_pair("haha",222),make_pair("hallo",3),make_pair("hello",3)});
    vector<string> result;
    redis.keys(R"(h?h*)",back_inserter(result));
    Print(result);
}

void test4(sw::redis::Redis& redis)
{
    using namespace std::chrono_literals;
    cout << "expire/ttl" << endl;
    redis.flushall();

    redis.set("key","111");
    
    redis.expire("key",std::chrono::seconds(10));
    std::this_thread::sleep_for(2s);
    long long seconds = redis.ttl("key");
    cout << seconds << endl;
}

void test5(sw::redis::Redis& redis)
{
    cout << "type" << endl;
    redis.flushall();

    redis.set("key1", "11");
    cout << "key1 type:" << redis.type("key1") << endl;
    
    redis.hset("key2","hehe","1");
    cout << "key2 type:" << redis.type("key2") << endl;

    redis.lpush("key3","haha");
    cout << "key3 type:" << redis.type("key3") << endl;

    redis.sadd("key4","111");
    cout << "key4 type:" << redis.type("key4") << endl;

    redis.zadd("key5", {make_pair("z1",50),make_pair("z2",69)});
    cout << "key5 type:" << redis.type("key5") << endl;

}

void test6(sw::redis::Redis& redis)
{
    cout << "del" << endl;
    redis.flushall();

    redis.mset({make_pair("key1", "aaa"),make_pair("key2","bbb")});

    vector<string> delArray = {"key1","key3", "key2"};
    cout << redis.del(delArray.begin(),delArray.end()) << endl;
    
}

int main()
{
    sw::redis::Redis redis("tcp://1.94.136.155:6379");
    
    // test1(redis);
    // test2(redis);
    // test3(redis);
    // test4(redis);
    // test5(redis);
    test6(redis);
    return 0;
}