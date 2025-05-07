#include "dialog.h"
#include "./ui_dialog.h"
#include "visuals.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFileInfo>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog), cylinder(new Cylinder(0,0,0))
{
    ui->setupUi(this);

    space_lst.append("3D");
    space_lst.append("2D");


    units_lst.append("m");
    units_lst.append("mm");

    model_lst.append("U");
    model_lst.append("B");
    model_lst.append("T");

    ui->cbox_space->addItems(space_lst);
    ui->cbox_units->addItems(units_lst);
    ui->cbox_model->addItems(model_lst);

    this->cylinder->set_radius(0);
    this->cylinder->set_width(0);
    this->cylinder->set_type("3D", "U");

    // resets the scene since sometimes it shows a cylinder at the start for some reason
    QGraphicsScene* scene = new QGraphicsScene;
    scene->clear();
    ui->graphicsView->setScene(scene);

    // connections
    connect (ui->line_radius, &QLineEdit::textChanged, this, &Dialog::set_radius);
    connect (ui->line_width, &QLineEdit::textChanged, this, &Dialog::set_width);
    connect (ui->cbox_model, &QComboBox::currentIndexChanged, this, &Dialog::model_changed);
    connect (ui->cbox_space, &QComboBox::currentIndexChanged, this, &Dialog::space_changed);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::space_changed(int index)
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

    this->cylinder->set_type(ui->cbox_space->currentText(), ui->cbox_model->currentText());
    Visuals::change_visuals(this->cylinder, ui);
}

void Dialog::model_changed(int index)
{
    Q_UNUSED(index);
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
    this->cylinder->set_type(ui->cbox_space->currentText(), ui->cbox_model->currentText());
    Visuals::change_visuals(this->cylinder, ui);
}

void Dialog::on_btn_save_clicked()
{
    QJsonObject object;
    object["Space"] =  ui->cbox_space->currentText();
    object["Units"] = ui->cbox_units->currentText();
    object["Model"] = ui->cbox_model->currentText();
    object["Radius"] = this->cylinder->get_radius();
    object["Width/Height"] = this->cylinder->get_width();

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

float Dialog::get_radius()
{
    return this->cylinder->get_radius();
}
float Dialog::get_width()
{
    return this->cylinder->get_width();
}
void Dialog::set_radius()
{
    bool ok = false;
    int new_radius = ui->line_radius->text().toInt(&ok);
    if (!ok)
        this->cylinder->set_radius(0);
    this->cylinder->set_radius(new_radius);

    Visuals::change_visuals(this->cylinder, ui);
}
void Dialog::set_width()
{
    bool ok = false;
    int new_width = ui->line_width->text().toInt(&ok);
    if (!ok)
        this->cylinder->set_width(new_width);
    this->cylinder->set_width(new_width);

    Visuals::change_visuals(this->cylinder, ui);
}

void Dialog::set_type()
{
    QString space =  ui->cbox_space->currentText();
    QString model = ui->cbox_model->currentText();

    this->cylinder->set_type(space, model);
}

