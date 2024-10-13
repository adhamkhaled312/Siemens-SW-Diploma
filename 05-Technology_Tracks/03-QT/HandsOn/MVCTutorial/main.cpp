#include "viewFrames.h"
#include "model.h"
#include "controller.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    model *m = model::getInstance("employees.db");
    controller c(&w,m);

    w.show();
    return a.exec();
}
