#include "studentregister.h"
#include "ui_studentregister.h"

StudentRegister::StudentRegister(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StudentRegister)
{
    ui->setupUi(this);
}

StudentRegister::~StudentRegister()
{
    delete ui;
}