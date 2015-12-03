#include "distributor.h"
#include "team.h"
Distributor::Distributor(const QMap< int,QList< QPair<int,int> > >& pciParam) : pci(pciParam)
{

}

const QList<Team*>& Distributor::distributeTeams(const int minSize,const int maxSize){


    QList<int> remainingStudents = pci.keys();

    int numTeams = pci.keys().count()/minSize;


     QList<Team*> teams = createTopRowTeams(numTeams,remainingStudents);


     return teams;
 }


int Distributor::calculateTeamWeight(Team team)
{
    QList<int> pciValues;
    QList<int> teamMembers = team.getTeamMembers();

    for(int i=0; i<teamMembers.count();i++){
        teamMembers.at(i);

    }
    //total =(team.getTeamMembers().at(i));
    return -1;
}

int Distributor::assignStudentToTeam(int studentID, QList<Team*> teams)
{
    return -1;
}

const QList<Team*>& Distributor::createTopRowTeams(int numTeams,QList<int>& remainingStudents)
{
     QList< Team* > topRow;
     QList< QPair<int,int> > pairs;
     for (int i = 0; i< pci.keys().count();)
     return topRow;
}

bool Distributor::insert(QList<QPair<int,int> >& pci,const QPair<int,int>& pair){
    bool inserted = false;
    for (int i = 0; i < pci.count() && !inserted; i++)
    {
        if (pci.at(i).second > pair.second)
        {
            if (i > 0)
            {
                pci.insert(i-1,pair);
                inserted = true;
            }
            else break;
        }
    }

    if (!inserted)
        pci.insert(0,pair);

    return inserted;
}
