#include "regexmodelloader.h"
#include <string>
#include <fstream>
#include <streambuf>
#include <regex>
#include <QByteArray>
#include <QDebug>
RegexModelLoader::RegexModelLoader()
{

}

std::vector<MODEL_VERTEX> RegexModelLoader::loadVertecies(std::string file)
{
    //Regex for parsing vertex.
    //Credit to https://github.com/Galarius/obj-regex-parser/blob/master/RegexObjParser/gmodel.cpp
    auto const VERTEX_REGEX = "v\\s*(-?[0-9]+\\.[0-9]*e-\\d+|-?[0-9]*e-\\d+|-?[0-9]+\\.[0-9]*|-?[0-9])\\s*(-?[0-9]+\\.[0-9]*e-\\d+|-?[0-9]*e-\\d+|-?[0-9]+\\.[0-9]*|-?[0-9])\\s*(-?[0-9]+\\.[0-9]*e-\\d+|-?[0-9]*e-\\d+|-?[0-9]+\\.[0-9]*|-?[0-9])";
    //Stack allocate a vector to store our vertecies in.
    //Load .obj File
    std::ifstream objFile(file);
    //Read from buffer
    std::string rawData((std::istreambuf_iterator<char>(objFile)),std::istreambuf_iterator<char>());
    std::regex reg(VERTEX_REGEX);
    //The C++11 STL provides us with a nice iterator we can use to iterate through our capture groups
    auto startCaptureGroupIter = std::sregex_iterator(rawData.begin(),rawData.end(),reg);
    auto endCaptureGroupIter = std::sregex_iterator();

    //Iterate through each match
    for(std::sregex_iterator iter = startCaptureGroupIter; iter != endCaptureGroupIter; iter++){
        std::smatch capture = *iter;
        std::string capture_string = capture.str();
        //Now We Parse each line and cast our X,Y,Z to numerical values.
        //Split on single space and them double space
        //float x = static_cast<float>(this->split(this->split(capture_string,"  ").at(1)," ").at(0)); //This is a weird parse but basically the <T> in our obj is delimited by two spaces


        std::regex vr("\\w*+[^ ]++");
        auto istartCaptureGroupIter = std::sregex_iterator(capture_string.begin(),capture_string.end(),vr);
        auto iendCaptureGroupIter = std::sregex_iterator();

        for(std::sregex_iterator jter = istartCaptureGroupIter; iter != iendCaptureGroupIter; jter++){
            std::smatch captures = *iter;
            std::string capture_strings = captures.str();
            QByteArray stl_qt_conversionz = QByteArray::fromStdString(capture_strings);
            qDebug() << stl_qt_conversionz;
        }

        QByteArray stl_qt_conversion = QByteArray::fromStdString(this->split(capture_string,"\\w*+[^ ]++").at(1));
        qDebug() << stl_qt_conversion;
    }
}

//http://stackoverflow.com/questions/9435385/split-a-string-using-c11
std::vector<std::__cxx11::string> RegexModelLoader::split(const std::__cxx11::string &input, const std::__cxx11::string &token)
{
    std::regex tokenMatch(token,std::regex_constants::extended);
    std::sregex_token_iterator
            first{input.begin(),input.end(),tokenMatch,-1},
            last;

    return {first,last};
}
