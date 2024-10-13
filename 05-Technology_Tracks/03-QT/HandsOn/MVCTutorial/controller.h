#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "viewFrames.h"
#include "model.h"

class controller : public QObject
{
    Q_OBJECT
public:
    controller(MainWindow* view, model* xModel);

private:
    MainWindow* dView;
    model* dModel;
private slots:
    void mAttemptLoginAndRedirect();
    void mAttemptAddingEmployee();
    void mRegisterSignals();
};

#endif // CONTROLLER_H
