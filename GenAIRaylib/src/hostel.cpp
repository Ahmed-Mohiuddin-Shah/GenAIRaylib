#include "hostel.h"

Hostel::Hostel()
{
    this->seriousMode = true;
}

Hostel::Hostel(std::string hostelName, std::string hostelAddress, std::string hostelPhoneNumber, std::string hostelEmail)
{
    this->hostelName = hostelName;
    this->hostelAddress = hostelAddress;
    this->hostelPhoneNumber = hostelPhoneNumber;
    this->hostelEmail = hostelEmail;
    this->seriousMode = true;
}

Hostel::Hostel(JSON hostelInfoJson)
{
    this->hostelName = hostelInfoJson["hostel_name"];
    this->hostelAddress = hostelInfoJson["hostel_address"];
    this->hostelPhoneNumber = hostelInfoJson["hostel_ph_no"];
    this->hostelEmail = hostelInfoJson["hostel_email"];

    this->seriousMode = hostelInfoJson["mode"];

}

JSON Hostel::toJson()
{
    JSON hostelJSON;

    hostelJSON["hostel_name"] = getHostelName();
    hostelJSON["hostel_address"] = getHostelAddress();
    hostelJSON["hostel_ph_no"] = getHostelPhoneNumber();
    hostelJSON["hostel_email"] = getHostelEmail();

    hostelJSON["mode"] = getMode();
    
    return hostelJSON;
}

void Hostel::setHostelName(std::string hostelName)
{
    this->hostelName = hostelName;
}

void Hostel::setHostelAddress(std::string hostelAddress)
{
    this->hostelAddress = hostelAddress;
}

void Hostel::setHostelPhoneNumber(std::string hostelPhoneNumber)
{
    this->hostelPhoneNumber = hostelPhoneNumber;
}

void Hostel::setHostelEmail(std::string hostelEmail)
{
    this->hostelEmail = hostelEmail;
}

std::string Hostel::getHostelName()
{
    return hostelName;
}

std::string Hostel::getHostelAddress()
{
    return hostelAddress;
}

std::string Hostel::getHostelPhoneNumber()
{
    return hostelPhoneNumber;
}

std::string Hostel::getHostelEmail()
{
    return hostelEmail;
}

void Hostel::setMode(int mode)
{
    seriousMode = mode;
}

bool Hostel::getMode()
{
    return seriousMode;
}

void Hostel::displayHostelInfo()
{
    using namespace std;
    cout << "--------------- Hostel Deets -------------------" << endl;
    cout << "Hostel Name: " << hostelName << endl;
    cout << "Hostel Address: " << hostelAddress << endl;
    cout << "Hostel Phone Number: " << hostelPhoneNumber << endl;
    cout << "Hostel Email: " << hostelEmail << endl;
}