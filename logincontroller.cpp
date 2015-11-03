#include "logincontroller.h"
#include <QString>
#include "studentprojectregisterview.h"
#include "manageprojectsview.h"
#include <QDebug>
#include "logindialog.h"
#include "studentregister.h"
LoginController::LoginController( LoginDialog *login): QObject(), loginDialog(login)
{

}


int LoginController::authenticate(QString &userName, QString &password, bool boolStudent)
{

    if(QString("11") == userName)
    {
        return 1;
    } else {
        return 0;
    }

}

int LoginController::goToStudentView(QString &userName){
    //transition view
    transition(true);
    return 0;
}

int LoginController::goToAdminView(QString &userName){
    //transition view
    transition(false);
    return 0;
}
int LoginController::goToStudentRegisterView(){
    //transition view
    loginDialog->close();
    StudentRegister rview;
    rview.exec();

    return 0;
}
void LoginController::transition(bool student)
{

    loginDialog->close();
    if(student){
        studentProjectRegisterView sview;
        sview.exec();
    }
    else{
        ManageProjectsView mview;
        mview.exec();
    }


}
