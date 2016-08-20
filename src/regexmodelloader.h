#ifndef REGEXMODELLOADER_H
#define REGEXMODELLOADER_H
#include "modelvertex.h"
#include "QString"
//A VERY CRUDE Model Loader using Regex.
class RegexModelLoader
{
public:
    RegexModelLoader();
    std::vector<MODEL_VERTEX> loadVertecies(std::string file);
private:
    std::vector<std::string> split(const std::string& input,const std::string& token);

};

#endif // REGEXMODELLOADER_H
