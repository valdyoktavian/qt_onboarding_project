#include "dialog.h"
#include "cylinder.h"
#include "visuals.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    QFile file(":/style/style.qss");  // 👈 important: note the `:/`
    if (file.open(QFile::ReadOnly | QFile::Text)) {
        QString styleSheet = file.readAll();
        a.setStyleSheet(styleSheet);  // Applies to all widgets, including QGraphicsView
    } else {
        qWarning() << "Failed to load stylesheet!";
    }

    Dialog w;
    w.show();
    return a.exec();
}
