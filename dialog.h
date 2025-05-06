#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QString>
#include <QStringList>

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

private slots:
    void on_cbox_space_currentIndexChanged(int index);

    void on_cbox_units_currentIndexChanged(int index);

    void on_cbox_model_currentIndexChanged(int index);

    void on_btn_save_clicked();

    void on_txtbox_para1_textChanged();

    void on_txtbox_para2_textChanged();

private:
    Ui::Dialog *ui;
    QStringList space_lst;
    QStringList units_lst;
    QStringList model_lst;

    void change_visuals();
    void create_visuals(QString space, QString unit, QString model);

    float radius;
    float width;
};

#endif // DIALOG_H
