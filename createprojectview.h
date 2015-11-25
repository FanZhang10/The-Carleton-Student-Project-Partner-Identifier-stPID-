#ifndef CREATEPROJECTVIEW_H
#define CREATEPROJECTVIEW_H
#include <QObject>
#include "createprojectviewcontroller.h"
#include <QDialog>
#include <qabstractbutton.h>

namespace Ui {
class CreateProjectView;
}

class CreateProjectView : public QDialog
{
    Q_OBJECT

public:
    explicit CreateProjectView(QWidget *parent = 0);
    const QString getProjectDescription();
    const QString getProjectTitle();
    const int& getProjectTeamMin();
    const int& getProjectTeamMax();

    ~CreateProjectView();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::CreateProjectView *ui;
    CreateProjectViewController *createProjectViewController;

};

#endif // CREATEPROJECTVIEW_H
