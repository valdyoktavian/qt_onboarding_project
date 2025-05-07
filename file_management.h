#ifndef FILE_MANAGEMENT_H
#define FILE_MANAGEMENT_H

#include <QString>
#include <QFile>

class file_management
{
public:
    file_management();
    ~file_management();

    static void save_file(QString space, QString units, QString model, float radius, float width);
    static std::tuple<QString, QString, QString, float, float> load_file(QString filepath);
};

#endif // FILE_MANAGEMENT_H
