#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QString>
#include <QStringList>

#include "cylinder.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

    float get_radius();
    float get_width();
    float get_type();
    void set_type();

    void update_cylinder();

private slots:
    void space_changed(int index);

    void model_changed(int index);

    void save_button_response();

    void set_radius();

    void set_width();

    void load_button_reponse();

private:
    Ui::Dialog *ui;
    Cylinder *cylinder;
    QStringList space_lst;
    QStringList units_lst;
    QStringList model_lst;
};

#endif // DIALOG_H
