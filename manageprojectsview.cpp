#include "manageprojectsview.h"
#include "ui_manageprojectsview.h"
#include "project.h"
#include "manageprojectscontroller.h"

ManageProjectsView::ManageProjectsView(QWidget *parent) :QDialog(parent),
    ui(new Ui::ManageProjectsView),
    manageProjectsController(new ManageProjectsController(this))

{

    ui->setupUi(this);

    manageProjectsController->displayAllProjects();

    /*
     QStringList projectTitles;

    for (int i = 0; i < 50;i++)
    {
        projectTitles << QString("Project %1").arg(i);
    }
    ui->projectsList->addItems(projectTitles);
    */

    ui->projectName->setText("Project Name");
    ui->projectDescription->setText("Project Description");
    ui->viewTextBrowser->setText("view students or view details or view results");


}

 int ManageProjectsView::updateProjectsList(QStringList &projects){
     ui->projectsList->addItems(projects);
 }


ManageProjectsView::~ManageProjectsView()
{
    delete ui;
}


void ManageProjectsView::on_projectsList_doubleClicked(const QModelIndex &index)
{
    index.data().toInt();
}


int ManageProjectsView::updateDetailedView(Project &project)
{
  ui->projectName->setText(project.getTitle());
}
