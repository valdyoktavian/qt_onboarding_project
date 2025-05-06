#include "dialog.h"
#include "./ui_dialog.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFileInfo>


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    space_lst.append("2D");
    space_lst.append("3D");

    units_lst.append("m");
    units_lst.append("mm");

    model_lst.append("U");
    model_lst.append("B");
    model_lst.append("T");

    ui->cbox_space->addItems(space_lst);
    ui->cbox_units->addItems(units_lst);
    ui->cbox_model->addItems(model_lst);

    radius = 0;
    width = 0;

    // resets the scene since sometimes it shows a cylinder at the start for some reason
    QGraphicsScene* scene = new QGraphicsScene;
    scene->clear();
    ui->graphicsView->setScene(scene);

    // qInfo() << "test, radius and width are: " << radius << width;

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::create_visuals(QString space, QString unit, QString model)
{   if (radius == 0 || width == 0)
    {
        qInfo() << "radius or width is 0";
        return;
    }


    if (space == "2D")
    {
        QGraphicsScene* scene = new QGraphicsScene;
        // circle
        scene->addRect(0, 0, 256, 192, Qt::NoPen, QBrush(Qt:: lightGray));
        scene->addEllipse(256/2-this->radius/2, 192/2-this->radius/2, this->radius, this->radius, QPen(Qt::black), QBrush(Qt::gray));
        ui->graphicsView->setScene(scene);
    }
    else
    {
        if (model == "U")
        {
            // make the default cylinder
            // qInfo() << "test, radius and width are: " << radius << width;

            QGraphicsScene* scene = new QGraphicsScene;
            int y = this->radius + this->width;
            // Bottom ellipse (cylinder bottom)
            scene->addEllipse(50, y, this->radius*2, this->radius/2, QPen(Qt::black), QBrush(Qt::lightGray));

            // Body (cylinder body)
            scene->addRect(50, y - this->width + this->radius/4, this->radius*2, this->width, QPen(Qt::lightGray), QBrush(Qt::lightGray));

            // Top ellipse (cylinder top)
            scene->addEllipse(50, y - this->width, this->radius*2,  this->radius/2, QPen(Qt::black), QBrush(Qt::gray));

            ui->graphicsView->setScene(scene);
        }
        else
        {
            // make the long cylinder
            QGraphicsScene* scene = new QGraphicsScene;

            int x = this->radius + this->width;
            // Bottom ellipse (cylinder bottom)
            scene->addEllipse(x, 100, this->radius/2, this->radius*2, QPen(Qt::black), QBrush(Qt::lightGray));

            // Body (cylinder body)
            scene->addRect(x-this->width + this->radius/4, 100, this->width, this->radius*2, QPen(Qt::lightGray), QBrush(Qt::lightGray));

            // Top ellipse (cylinder top)
            scene->addEllipse(x - this->width, 100, this->radius/2, this->radius*2, QPen(Qt::black), QBrush(Qt::gray));

            ui->graphicsView->setScene(scene);
        }
    }
}

void Dialog::change_visuals()
{
    QString space = ui->cbox_space->currentText();
    QString unit  = ui->cbox_units->currentText();
    QString model = ui->cbox_model->currentText();

    qDebug() << "Space:" << space;
    qDebug() << "Unit:" << unit;
    qDebug() << "Model:" << model;

    QGraphicsScene* scene = new QGraphicsScene;
    scene->clear();
    ui->graphicsView->setScene(scene);

    create_visuals(space, unit, model);
}

void Dialog::on_cbox_space_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    if (ui->cbox_space->currentText() == "2D")
        {
            QString t = "T";
            ui->cbox_model->setCurrentText(t);
        }
    else if(ui->cbox_space->currentText() == "3D" && ui->cbox_model->currentText() == "T")
        {
            QString u = "U";
            ui->cbox_model->setCurrentText(u);
        }
    change_visuals();
}


void Dialog::on_cbox_units_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    change_visuals();
}


void Dialog::on_cbox_model_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    change_visuals();

    if(ui->cbox_model->currentText() == "T")
    {
        QString a = "2D";
        ui->cbox_space->setCurrentText(a);
    }
    else
    {
        QString b = "3D";
        ui->cbox_space->setCurrentText(b);
    }
}



void Dialog::on_btn_save_clicked()
{
    QJsonObject object;
    object["Space"] =  ui->cbox_space->currentText();
    object["Units"] = ui->cbox_units->currentText();
    object["Model"] = ui->cbox_model->currentText();
    object["Radius"] = this->radius;
    object["Width/Height"] = this->width;

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


void Dialog::on_txtbox_para1_textChanged()
{
    bool ok = false;
    this->radius = ui->txtbox_para1->toPlainText().toInt(&ok);
    if (!ok)
    {
        qInfo() << "Invalid radius has been inputed!";
        this->radius = 0;
    }
    change_visuals();
}



void Dialog::on_txtbox_para2_textChanged()
{
    bool ok = false;
    this->width = ui->txtbox_para2->toPlainText().toInt(&ok);
    if (!ok)
    {
        qInfo() << "Invalid width has been inputed!";
        this->width = 0;
    }
    change_visuals();
}

