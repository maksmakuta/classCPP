#include <ClassParser.h>

ClassParser::ClassParser(const std::string& data){
    this->name = this->parseClass(data);
    this->vars = this->parseVars(data);
}

string ClassParser::getName(){return this->name;}
std::vector<Variable> ClassParser::getVars(){return this->vars;}

string ClassParser::parseClass(cstr data){
    return data.substr(0,data.find('('));
}
std::vector<string> ClassParser::split(const char *str, char c){
    std::vector<string> result;
    do{
        const char *begin = str;
        while(*str != c && *str) str++;
        result.emplace_back(begin, str);
    } while (0 != *str++);
    return result;
}
std::vector<Variable> ClassParser::parseVars(cstr data){
    std::vector<Variable> tmpV;
    int s = (int)data.find('(');
    string tmp = data.substr( s+1,data.size() - s - 2);
    std::vector<string> tokens = split(tmp.c_str(),',');
    for(cstr str : tokens){
        std::vector<string> vTokens = split(str.c_str(),' ');
        Variable tmpVar(vTokens[0],vTokens[1]);
        tmpV.push_back(tmpVar);
    }
    return tmpV;
}
