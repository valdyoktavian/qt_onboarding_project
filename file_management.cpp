#include "file_management.h"
#include <QJsonDocument>
#include <QDebug>
#include <QFileInfo>
#include <QJsonObject>
#include <QJsonArray>
#include <QIODevice>

file_management::file_management() {}

file_management::~file_management(){}

void file_management::save_file(QString space, QString units, QString model, float radius, float width)
{
    QJsonObject object;
    object["Space"] =  space;
    object["Units"] = units;
    object["Model"] = model;
    object["Radius"] = radius;
    object["Width"] = width;

    QJsonDocument doc(object);
    QFile file("Cylinder_Details.json");

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "Couldn't open file to write JSON!";
        return;
    }

    qDebug() << "Saved to:" << QFileInfo(file).absoluteFilePath();

    file.write(doc.toJson(QJsonDocument::Indented));
    file.close();
}

std::tuple<QString, QString, QString, float, float> file_management::load_file(QString filepath)
{
    QFile file(filepath);
    if (file.open(QIODevice::ReadOnly))
    {
        QByteArray bytes = file.readAll();
        file.close();

        QJsonParseError parse_error;
        QJsonDocument document = QJsonDocument::fromJson(bytes, &parse_error);

        if (parse_error.error != QJsonParseError::NoError)
        {
            qInfo() << "We have an error in the JSON File";
        }

        if (document.isObject())
        {
            QJsonObject object = document.object();
            QString space = object.value("Space").toString();
            QString units = object.value("Units").toString();
            QString model = object.value("Model").toString();
            float radius = object.value("Radius").toDouble();
            float width = object.value("Width").toDouble();
            return std::make_tuple(space, units, model, radius, width);
        }
    }
    return std::make_tuple("3D", "mm", "U", 0, 0);
}
