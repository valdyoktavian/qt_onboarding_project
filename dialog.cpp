#include "dialog.h"
#include "./ui_dialog.h"
#include "visuals.h"
#include "file_management.h"
#include <QFileDialog>
#include <QStatusBar>
#include "graphicsview.h"

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
    QGraphicsScene* new_scene = new QGraphicsScene;
    this->scene = new_scene;
    this->scene->clear();
    ui->graphicsView->setScene(this->scene);

    // connections
    connect (ui->line_radius, &QLineEdit::textChanged, this, &Dialog::set_radius);
    connect (ui->line_width, &QLineEdit::textChanged, this, &Dialog::set_width);
    connect (ui->cbox_model, &QComboBox::currentIndexChanged, this, &Dialog::model_changed);
    connect (ui->cbox_space, &QComboBox::currentIndexChanged, this, &Dialog::space_changed);
    connect (ui->btn_save, &QPushButton::clicked, this, &Dialog::save_button_response);
    connect (ui->btn_load, &QPushButton::clicked, this, &Dialog::load_button_reponse);
    connect (ui->radio_free, &QRadioButton::clicked, this, &Dialog::radio_free_response);
    connect (ui->radio_square, &QRadioButton::clicked, this, &Dialog::radio_square_response);
    connect (ui->radio_none, &QRadioButton::clicked, this, &Dialog::radio_none_response);

    // graphics view stuff
    GraphicsView* customView = new GraphicsView(this);
    customView->setScene(new QGraphicsScene(this));  // create and set scene
    customView->setMouseTracking(true);
    customView->scene = this->scene;

    ui->gridLayout->replaceWidget(ui->graphicsView, customView);

    // Optional: clean up and assign if you plan to use ui->graphicsView later
    ui->graphicsView->deleteLater();
    ui->graphicsView = customView;

    ui->radio_none->setChecked(true);
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
    Visuals::change_visuals(this->cylinder, ui, this->scene);
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
    Visuals::change_visuals(this->cylinder, ui, this->scene);
}

void Dialog::save_button_response()
{
    QString space =  ui->cbox_space->currentText();
    QString units = ui->cbox_units->currentText();
    QString model = ui->cbox_model->currentText();
    float radius = this->cylinder->get_radius();
    float width = this->cylinder->get_width();

    file_management::save_file(space, units, model, radius, width);
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
    if (ui->line_radius->text().isEmpty())
    {
        ui->status_radius->setText("");
        return;
    }
    bool ok = false;
    int new_radius = ui->line_radius->text().toInt(&ok);
    if (!ok)
    {
        ui->status_radius->setText("Invalid Input! Please enter a number.");
        this->cylinder->set_radius(0);
    }
    this->cylinder->set_radius(new_radius);

    Visuals::change_visuals(this->cylinder, ui, this->scene);
}
void Dialog::set_width()
{
    if (ui->line_width->text().isEmpty())
    {
        ui->status_width->setText("");
        return;
    }
    bool ok = false;
    int new_width = ui->line_width->text().toInt(&ok);
    if (!ok or new_width < 0)
    {
        ui->status_width->setText("Invalid Input! Please enter a number.");
        this->cylinder->set_width(0);
    }
    this->cylinder->set_width(new_width);

    Visuals::change_visuals(this->cylinder, ui, this->scene);
}

void Dialog::set_type()
{
    QString space =  ui->cbox_space->currentText();
    QString model = ui->cbox_model->currentText();

    this->cylinder->set_type(space, model);
}

void Dialog::load_button_reponse(){
    QString filePath = QFileDialog::getOpenFileName(
        this,
        "Open JSON File",
        "",
        "JSON Files (*.json);;All Files (*)"
        );

    if (filePath.isEmpty()) {
        qDebug() << "No file selected.";
        return;
    }
    std::tuple<QString, QString, QString, float, float> new_values = file_management::load_file(filePath);

    ui->cbox_space->setCurrentText(std::get<0>(new_values));
    ui->cbox_units->setCurrentText(std::get<1>(new_values));
    ui->cbox_model->setCurrentText(std::get<2>(new_values));
    ui->line_radius->setText(QString::number(std::get<3>(new_values), 'f', 0));
    ui->line_width->setText(QString::number(std::get<4>(new_values), 'f', 0));

    this->cylinder->set_radius(std::get<3>(new_values));
    this->cylinder->set_width(std::get<4>(new_values));
    this->cylinder->set_type(std::get<0>(new_values), std::get<2>(new_values));

    Visuals::change_visuals(this->cylinder, ui, this->scene);
}

void Dialog::radio_free_response(){
    GraphicsView* gv = qobject_cast<GraphicsView*>(ui->graphicsView);
    if (gv) {
        gv->type = 0;  // ✅ access your custom field
    }
}

void Dialog::radio_square_response(){
    // GraphicsView* gv = qobject_cast<GraphicsView*>(ui->graphicsView);
    // if (gv) {
    //     gv->type = 1;  // ✅ access your custom field
    // }
}

void Dialog::radio_circle_response(){
    GraphicsView* gv = qobject_cast<GraphicsView*>(ui->graphicsView);
    if (gv) {
        gv->type = 2;  // ✅ access your custom field
    }
}

void Dialog::radio_line_response(){
    GraphicsView* gv = qobject_cast<GraphicsView*>(ui->graphicsView);
    if (gv) {
        gv->type = 3;  // ✅ access your custom field
    }
}

void Dialog::radio_eraser_response(){
    GraphicsView* gv = qobject_cast<GraphicsView*>(ui->graphicsView);
    if (gv) {
        gv->type = 4;  // ✅ access your custom field
    }
}

void Dialog::radio_none_response(){
    GraphicsView* gv = qobject_cast<GraphicsView*>(ui->graphicsView);
    if (gv) {
        gv->type = 5;  // ✅ access your custom field
    }
}




