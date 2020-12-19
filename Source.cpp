#include <iostream>
#include "Citizen.h"
#include "District.h"
#include "ElectionRound.h"
#include "Party.h"

void addDistrict(ElectionRound& electionRound);
void addCitizen(ElectionRound& electionRound);
void addParty(ElectionRound& electionRound);
void addDistrictMOCK(ElectionRound &electionRound, char *name, int representativeNum);
void addCitizenMOCK(ElectionRound& electionRound, char *name, char* id, int districtNum);
void addPartyMOCK(ElectionRound& electionRound, char *name,  char *id);
void setCitizenAsPartyRepresentiveMOCK(ElectionRound& electionRound, char * representiveId, int partyId, int districtId);
void setCitizenAsPartyRepresentive(ElectionRound& electionRound);
void printAllDistricts(ElectionRound& electionRound);
void printAllCitizens(ElectionRound& electionRound);
void printAllParties(ElectionRound& electionRound);
void voteMOCK(ElectionRound& electionRound, char *citizenId, int partyId);
void vote(ElectionRound& electionRound);
void showElectionResults(ElectionRound& electionRound);
bool isValidCitizen(const char *action, Citizen* citizen);
bool isValidParty(const char *action, Party* party);

using namespace std;

const int MAX_STRING_LEN = 100;

int main()
{
    int option = 0;
    int day =1, month=2, year=2;
//	cout << "enter elections date DD MM YYYY ";
//	cin >> day >> month >> year;
    ElectionRound electionRound(day, month, year);
    addDistrictMOCK(electionRound,const_cast<char*>("A"),4);
    addDistrictMOCK(electionRound,const_cast<char*>("B"),10);
    addDistrictMOCK(electionRound,const_cast<char*>("C"),2);

    addCitizenMOCK(electionRound,const_cast<char*>("A1"),const_cast<char*>("11"),1);
    addCitizenMOCK(electionRound,const_cast<char*>("A2"),const_cast<char*>("12"),1);
    addCitizenMOCK(electionRound,const_cast<char*>("A3"),const_cast<char*>("13"),1);
    addCitizenMOCK(electionRound,const_cast<char*>("A4"),const_cast<char*>("14"),1);
    addCitizenMOCK(electionRound,const_cast<char*>("A5"),const_cast<char*>("15"),1);

    addCitizenMOCK(electionRound,const_cast<char*>("B1"),const_cast<char*>("21"),2);
    addCitizenMOCK(electionRound,const_cast<char*>("B2"),const_cast<char*>("22"),2);
    addCitizenMOCK(electionRound,const_cast<char*>("B3"),const_cast<char*>("23"),2);
    addCitizenMOCK(electionRound,const_cast<char*>("B4"),const_cast<char*>("24"),2);
    addCitizenMOCK(electionRound,const_cast<char*>("B5"),const_cast<char*>("25"),2);
    addCitizenMOCK(electionRound,const_cast<char*>("B6"),const_cast<char*>("26"),2);
    addCitizenMOCK(electionRound,const_cast<char*>("B7"),const_cast<char*>("27"),2);
    addCitizenMOCK(electionRound,const_cast<char*>("B8"),const_cast<char*>("28"),2);
    addCitizenMOCK(electionRound,const_cast<char*>("B9"),const_cast<char*>("29"),2);
    addCitizenMOCK(electionRound,const_cast<char*>("B10"),const_cast<char*>("210"),2);

    addCitizenMOCK(electionRound,const_cast<char*>("C1"),const_cast<char*>("31"),3);
    addCitizenMOCK(electionRound,const_cast<char*>("C2"),const_cast<char*>("32"),3);

    addPartyMOCK(electionRound,const_cast<char*>("one"),const_cast<char*>("12"));
    addPartyMOCK(electionRound,const_cast<char*>("two"),const_cast<char*>("21"));
    addPartyMOCK(electionRound,const_cast<char*>("three"),const_cast<char*>("22"));

    setCitizenAsPartyRepresentiveMOCK(electionRound,const_cast<char*>("11"),1,1);
    setCitizenAsPartyRepresentiveMOCK(electionRound,const_cast<char*>("14"),1,1);

    setCitizenAsPartyRepresentiveMOCK(electionRound,const_cast<char*>("23"),2,2);
    setCitizenAsPartyRepresentiveMOCK(electionRound,const_cast<char*>("24"),2,2);
    setCitizenAsPartyRepresentiveMOCK(electionRound,const_cast<char*>("25"),2,2);
    setCitizenAsPartyRepresentiveMOCK(electionRound,const_cast<char*>("26"),2,2);
    setCitizenAsPartyRepresentiveMOCK(electionRound,const_cast<char*>("15"),2,1);

    setCitizenAsPartyRepresentiveMOCK(electionRound,const_cast<char*>("31"),3,3);
    setCitizenAsPartyRepresentiveMOCK(electionRound,const_cast<char*>("32"),3,3);
    setCitizenAsPartyRepresentiveMOCK(electionRound,const_cast<char*>("27"),3,2);
    setCitizenAsPartyRepresentiveMOCK(electionRound,const_cast<char*>("28"),3,2);
    setCitizenAsPartyRepresentiveMOCK(electionRound,const_cast<char*>("29"),3,2);
    setCitizenAsPartyRepresentiveMOCK(electionRound,const_cast<char*>("210"),3,2);
    setCitizenAsPartyRepresentiveMOCK(electionRound,const_cast<char*>("13"),3,1);


    printAllDistricts(electionRound);
    printAllParties(electionRound);
    printAllCitizens(electionRound);


    voteMOCK(electionRound,const_cast<char*>("13"),1);
    voteMOCK(electionRound,const_cast<char*>("14"),1);
    voteMOCK(electionRound,const_cast<char*>("15"),1);

    voteMOCK(electionRound,const_cast<char*>("23"),2);
    voteMOCK(electionRound,const_cast<char*>("24"),2);
    voteMOCK(electionRound,const_cast<char*>("25"),2);
    voteMOCK(electionRound,const_cast<char*>("11"),2);


    voteMOCK(electionRound,const_cast<char*>("31"),3);
    voteMOCK(electionRound,const_cast<char*>("32"),3);
    voteMOCK(electionRound,const_cast<char*>("26"),3);
    voteMOCK(electionRound,const_cast<char*>("27"),3);
    voteMOCK(electionRound,const_cast<char*>("28"),3);
    voteMOCK(electionRound,const_cast<char*>("29"),3);
    voteMOCK(electionRound,const_cast<char*>("210"),3);




    //addCitizenMOCK()
    while (option != 10) {
        cout << "enter one of the options-" << endl
             << "1 - add district" << endl
             << "2- add citizen" << endl
             << "3- add party" << endl
             << "4- add citizen as party representive" << endl
             << "5- show all districts" << endl
             << "6- show all citizens" << endl
             << "7- show all parties" << endl
             << "8- vote" << endl
             << "9- show election results" << endl
             << "10- exit the program" << endl;
        cin >> option;
        switch (option)
        {
            case 1:
                addDistrict(electionRound);
                break;
            case 2:
                addCitizen(electionRound);
                break;
            case 3:
                addParty(electionRound);
                break;
            case 4:
                setCitizenAsPartyRepresentive(electionRound);
                break;
            case 5:
                printAllDistricts(electionRound);
                break;
            case 6:
                printAllCitizens(electionRound);
                break;
            case 7:
                printAllParties(electionRound);
                break;
            case 8:
                vote(electionRound);
            case 9:
                showElectionResults(electionRound);
            case 10:
                break;
        }

    }
}

void addDistrictMOCK(ElectionRound &electionRound, char *name, int representativeNum) {
    District *district = new District(name, representativeNum);
    electionRound.addDistrict(district);
}

void addDistrict(ElectionRound &electionRound) {
    char name[MAX_STRING_LEN];
    int representativeNum;
    cout << "enter name and number of representative ";
    cin >> name >> representativeNum;
    District *district = new District(name, representativeNum);
    electionRound.addDistrict(district);
}

void addCitizenMOCK(ElectionRound& electionRound, char *name, char* id, int districtNum) {
    int birthYear = 1992;
    District* district = electionRound.getDistrictByID(districtNum);
    Citizen* citizen = new Citizen(name, id, birthYear, district);
    electionRound.addCitizen(citizen);
}

void addCitizen(ElectionRound& electionRound) {
    char name[MAX_STRING_LEN];
    char id[MAX_STRING_LEN];
    int birthYear, districtNum;
    cout << "enter name, id, birth year and district number ";
    cin >> name >> id >> birthYear >> districtNum;
    District* district = electionRound.getDistrictByID(districtNum);
    Citizen* citizen = new Citizen(name, id, birthYear, district);
    electionRound.addCitizen(citizen);
}

void addPartyMOCK(ElectionRound& electionRound, char*name, char* id) {

    Citizen* head = electionRound.getCitizenByID(id);
    if (! isValidCitizen("addParty", head)) return;
    Party* party = new Party(name, head);
    electionRound.addParty(party);
    head->setIsPartyMember();
}

void addParty(ElectionRound& electionRound) {
    char name[MAX_STRING_LEN];
    char id[MAX_STRING_LEN];
    cout << "enter name and the party head's id ";
    cin >> name >> id;
    Citizen* head = electionRound.getCitizenByID(id);
    if (! isValidCitizen("addParty", head)) return;
    Party* party = new Party(name, head);
    electionRound.addParty(party);
    head->setIsPartyMember();
}

void setCitizenAsPartyRepresentiveMOCK(ElectionRound& electionRound, char* representiveId, int partyId, int districtId) {
    Citizen *citizen = electionRound.getCitizenByID(representiveId);
    if (! isValidCitizen("setCitizenAsPartyRepresentive", citizen)) return;
    citizen->setIsPartyMember();
    Party *party = electionRound.getPartyByID(partyId);
    if (! isValidParty("setCitizenAsPartyRepresentive", party)) return;
    party->addRepresentive(districtId, citizen);
}

void setCitizenAsPartyRepresentive(ElectionRound& electionRound) {
    char representiveId[MAX_STRING_LEN];
    int partyId;
    int districtId;
    cout << "enter representive ID, party ID, district ID ";
    cin >> representiveId >> partyId >> districtId;
    Citizen *citizen = electionRound.getCitizenByID(representiveId);
    if (! isValidCitizen("setCitizenAsPartyRepresentive", citizen)) return;
    citizen->setIsPartyMember();
    Party *party = electionRound.getPartyByID(partyId);
    if (! isValidParty("setCitizenAsPartyRepresentive", party)) return;
    party->addRepresentive(districtId, citizen);
}


void printAllDistricts(ElectionRound& electionRound) {
    electionRound.printAllDistricts();
}

void printAllCitizens(ElectionRound& electionRound) {
    electionRound.printAllCitizens();
}

void printAllParties(ElectionRound& electionRound) {
    electionRound.printAllParties();
}

void voteMOCK(ElectionRound& electionRound, char *citizenId, int partyId){
    Citizen* voter = electionRound.getCitizenByID(citizenId);
    District* district=voter->getDistrict();
    district->addVote(voter, partyId);
    Party* party = electionRound.getPartyByID(partyId);
    if (! isValidParty("vote", party)) return;
    party->increaseNumberOfVotes();
}

void vote(ElectionRound& electionRound){
    char citizenId[MAX_STRING_LEN];
    int partyId;
    cout << "enter citizen ID, party ID";
    cin >> citizenId >> partyId;
    Citizen* voter = electionRound.getCitizenByID(citizenId);
    District* district=voter->getDistrict();
    district->addVote(voter, partyId);
    Party* party = electionRound.getPartyByID(partyId);
    if (! isValidParty("vote", party)) return;
    party->increaseNumberOfVotes();
}

void showElectionResults(ElectionRound& electionRound){
    District* district;
    Party* party, *winningParty;
    char* headName;
    int numOfExistsPartiesInDistrict, *numOfRepresantivesPerParty=nullptr, *electionResults;
    float *percentagePerParty=nullptr;
    for (int i = 0; i < electionRound.getDistrictLogSize(); ++i) {

        district = electionRound.getDistricts()[i];
        winningParty = electionRound.getPartyByID(district->getWinningParty());
        headName = winningParty->getPartyHead()->getName();
        cout << "* District Name- " << district->getName() << endl
             << "    Num of representive- " << district->getRepresentativeNum() << endl
             << "    head of the winning party- " << headName << endl
             << "    vote percentage- "  << district->getVotePercentage() <<"%"<< endl;
        electionResults = district->getElectionResults();
        percentagePerParty = district->getPercentagePerParty();
        numOfRepresantivesPerParty = district->getNumOfRepresantivesPerParty(numOfExistsPartiesInDistrict);
        winningParty->increaseNumberOfWinningRepresentives(district->getRepresentativeNum());
        for (int j = 0; j < electionRound.getPartiesLogSize(); ++j) {
            cout << "       party " << (j + 1) << "-" << endl;
            if (j < numOfExistsPartiesInDistrict)
            {
                cout << "        number of voters -" << electionResults[j] << endl
                     << "        percentage of all votes - " << percentagePerParty[j] << "%" << endl;
                if (numOfRepresantivesPerParty[j] > 0) {
                    cout << "        represantives - " << endl;
                    party = electionRound.getPartyByID(j + 1);
                    party->printNRepresantive(i, numOfRepresantivesPerParty[j]);
                }
            }
            else {
                cout << "        number of voters" << " - 0" << endl
                     << "        percentage of all votes - 0%" << endl;
            }
        }
    }

    Party** parties = electionRound.getSortedParties();
    for (int i = 0; i < electionRound.getPartiesLogSize(); i++) {
        cout << "* party " << parties[i]->getName() << "-" << endl
             << "   head name -" << (parties[i]->getPartyHead()->getName()) << endl
             << "   winning number of represantives-  " << parties[i]->getNumberOfWinningRepresantives() << endl
             << "   total number of votes from all districts- "<< parties[i]->getNumberOfVotes() << endl;
    }

    delete[] percentagePerParty;
    delete[] numOfRepresantivesPerParty;
    delete[] parties;
}

bool isValidCitizen(const char *action, Citizen* citizen){
    if (citizen == NULL) {
        cout << action << " -there is no such citizen." << endl;
        return false;
    }
    if (citizen->getIsPartyMember()){
        cout << action << " -already set as represantive or head." << endl;
        return false;
    }
    return true;
}

bool isValidParty(const char *action, Party* party){
    if (party == NULL) {
        cout << action << " -there is no such party." << endl;
        return false;
    }
    return true;
}