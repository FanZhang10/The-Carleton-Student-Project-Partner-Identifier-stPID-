#include <QApplication>
#include <iostream>
#include "Database.h"
#include "manageprojectsview.h"
#include "logindialog.h"
#include <QDebug>
#include "project.h"
#include "student.h"

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    Database::getInstance();
    LoginDialog view;
    view.show();



    return a.exec();


}
