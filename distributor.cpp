#include "distributor.h"
#include "team.h"

Distributor::Distributor(const QMap< int,QList< QPair<int,int> > >& pciParam) : pci(pciParam)
{

}

 const QList<Team*>& Distributor::distributeTeams(const int minSize,const int maxSize){
     QList <Team*>* teams = new QList<Team*>;


     int numTeams = pci.keys().count()/minSize;

     for (int i = 0; i < numTeams; i++){
         //QPair<int,int> pair = pci.value(pci.keys.at(i));
     }

     return *teams;
 }


int Distributor::calculateTeamWeight(Team team)
{
    QList<int> total;
    QList<Student*> teamMembers = team.getTeamMembers();
        for(int i=0;i<teamMembers.count();i++){
        int a = 0;
        }
        //total =(team.getTeamMembers().at(i));
 return -1;
}

int Distributor::assignStudentToTeam(int studentID, QList<Team*> teams)
{
    return -1;
}

