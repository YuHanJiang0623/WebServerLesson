#include <json/json.h>
#include <iostream>

using namespace std;
int main() {

    Json::Value root;
    root["hello"] = "world";

    std::cout << "root: " << root << std::endl;
    return 0;
}
