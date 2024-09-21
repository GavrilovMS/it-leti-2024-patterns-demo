#include <iostream>

#include <spdlog/spdlog.h>
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

int main(int, char**){
    rapidjson::Document doc;
    doc.SetObject();
    doc.AddMember("test", 123, doc.GetAllocator());
    rapidjson::StringBuffer buffer;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buffer);
    doc.Accept(writer);

    std::cout << buffer.GetString() << std::endl;
    return 0;
}
