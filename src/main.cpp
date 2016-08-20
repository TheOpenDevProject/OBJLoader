#include <QCoreApplication>
#include <regexmodelloader.h>
int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);

       /* QFile file;
        file.setFileName("src/FinalBaseMesh.obj");
        QByteArray fileBuffer;
        if(file.open(QFile::ReadOnly)){
                fileBuffer = file.readAll();
                std::regex reg("v\\s*(-?[0-9]+\\.[0-9]*e-\\d+|-?[0-9]*e-\\d+|-?[0-9]+\\.[0-9]*|-?[0-9])\\s*(-?[0-9]+\\.[0-9]*e-\\d+|-?[0-9]*e-\\d+|-?[0-9]+\\.[0-9]*|-?[0-9])\\s*(-?[0-9]+\\.[0-9]*e-\\d+|-?[0-9]*e-\\d+|-?[0-9]+\\.[0-9]*|-?[0-9])");
                std::string str = fileBuffer.toStdString();
                auto start_iter = std::sregex_iterator(str.begin(),str.end(),reg);
                auto end_iter = std::sregex_iterator();

                qDebug() << "Found n(" << std::distance(start_iter,end_iter) << ") Normals";


                //Itterate over the matches
                for(std::sregex_iterator iter = start_iter; iter != end_iter; iter++){
                    std::smatch capture = *iter; //Get the current capture
                    std::string match_str = capture.str();
                    QByteArray stl_qt_conversion = QByteArray::fromStdString(match_str);
                    qDebug() << QByteArray(stl_qt_conversion);
                }

        }else{
            qDebug() << "Error Opening File:" << file.errorString() << QDir::currentPath();
        }
       */
        RegexModelLoader r;
        r.loadVertecies("src/FinalBaseMesh.obj");
    return a.exec();
}
