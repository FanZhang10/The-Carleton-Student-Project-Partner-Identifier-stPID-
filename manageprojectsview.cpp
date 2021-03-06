#include "manageprojectsview.h"
#include "ui_manageprojectsview.h"
#include "project.h"
#include "Database.h"
#include "manageprojectscontroller.h"
#include "student.h"
#include <QDialog>
#include <QDebug>
#include "adminviewresultcontroller.h"
#include <QStringList>


ManageProjectsView::ManageProjectsView(QWidget *parent) :QDialog(parent),
    ui(new Ui::ManageProjectsView),
    manageProjectsController(ManageProjectsController::getInstance())

{
    manageProjectsController->setView(this);
    ui->setupUi(this);


    ui->projectName->setText("Project Name");
    ui->projectDescription->setText("Project Description");
    ui->viewTextBrowser->setText("view students or view details or view results");
    QPixmap  pixmap ;
    int w = ui->image->width();
    int h = ui->image->height();
    pixmap.load(":/images/carleton.jpeg");
    ui->image->setPixmap(pixmap.scaled(w,h,Qt::KeepAspectRatio));

    if(manageProjectsController->init())
    {
        ui->projectsList->setCurrentRow(0);

    }

}


int ManageProjectsView::updateProjectsList(QList<QString> &projectTitles){
    QString temp;
    for (int i = 0; i <projectTitles.count();i++)
    {
        temp =projectTitles.at(i);
        ui->projectsList->addItem(temp);
    }
}


ManageProjectsView::~ManageProjectsView()
{
    delete ui;
}




int ManageProjectsView::updateDetailedView(Project &project)
{
    QString title="Title: "+project.getTitle();

    ui->projectName->setText(title);
    QString num1;
    num1.setNum(project.getMinTeamSize());
    QString num2;
    num2.setNum(project.getMaxTeamSize());
    QString tempsStorage= "\n\nMinimum Team Size: "+ num1 + "\nMaximum Team Size: " + num2;
    QString description="Description: " +project.getDescription() + tempsStorage;
    ui->projectDescription->setText(description);
    QString temp;
    for(int i=0; i<project.getRegisteredStudents().count();i++)
    {

        temp += project.getRegisteredStudents().at(i)->getUsername() + "  ";

        ui->viewTextBrowser->setText(temp);

    }
    qDebug () << "Results available? " << project.resultsAreAvailable();
    ui->detailedResult->setDisabled(!project.resultsAreAvailable());
    ui->viewResultButton->setDisabled(!project.resultsAreAvailable());
}


void ManageProjectsView::on_projectsList_clicked(const QModelIndex &index)
{


    int indexVal = index.row();

    manageProjectsController->updateSelectedProject(indexVal);


}

int ManageProjectsView::setStudentList(Project &project){
    QString temp;
    for(int i=0; i<project.getRegisteredStudents().count();i++)
    {
        temp += project.getRegisteredStudents().at(i)->getUsername() + " ";
        ui->viewTextBrowser->setText(temp);


    }

}

int ManageProjectsView::setDetailedView(Project &project)
{

}



void ManageProjectsView::on_ViewStudentButton_clicked()
{
    //int indexVal = index.row();

    manageProjectsController->updateStudentList();




}


void ManageProjectsView::on_viewDetailButton_clicked()
{
    manageProjectsController->updateDetailedView();
}

void ManageProjectsView::on_viewResultButton_clicked()
{
    manageProjectsController->updateSummaryResults();
}


void ManageProjectsView::on_createProjectButton_clicked()
{
    manageProjectsController->goToCreateProjectView();
}

void ManageProjectsView::on_makeTeamsButton_clicked()
{


    if (manageProjectsController->makeTeams())
    {
        QMessageBox::information(this, tr("Team Builder"),
                                 tr("Teams Created!"),
                                 QMessageBox::Ok);
        ui->detailedResult->setDisabled(false);
        ui->viewResultButton->setDisabled(false);
    }


}



void ManageProjectsView::on_detailedResult_clicked()
{
    manageProjectsController->showDetailedResults();
}

void ManageProjectsView::updateSummaryResults(QList<Team*> teams)
{
    QString final;

    for(int i=0; i< teams.count(); i++)
    {
        QList<int> idList = teams.at(i)->getTeamMembers();
        QStringList nameList;

        for(int j=0; j<idList.count();j++){
            Student student = manageProjectsController->getStudent(idList.at(j));
            nameList.append(student.getUsername());
        }
        final+= "Team " + QString::number(i+1) + ": " + nameList.join(',') + "\n";
    }
    ui->viewTextBrowser->setText(final);
}

void ManageProjectsView::on_editProject_clicked()
{
    manageProjectsController->goToEditProject();
}
void ManageProjectsView::on_pushButton_clicked()
{
     manageProjectsController->goToLoginDialog();
}
