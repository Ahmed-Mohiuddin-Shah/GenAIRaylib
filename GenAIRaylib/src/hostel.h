#include <iostream>
#include <vector>
#include "texttable.hpp" // External library class header file for creating tables in console

#include "nlohmann/json.hpp"
#include "FileReader.h"

using JSON = nlohmann::json;

class Hostel
{
private:
    std::string hostelName;
    std::string hostelAddress;
    std::string hostelPhoneNumber;
    std::string hostelEmail;
    bool seriousMode;

public:
    Hostel();

    Hostel(std::string hostelName, std::string hostelAddress, std::string hostelPhoneNumber, std::string hostelEmail);

    Hostel(JSON hostelInfoJson);

    JSON toJson();

    void setHostelName(std::string hostelName);

    void setHostelAddress(std::string hostelAddress);

    void setHostelPhoneNumber(std::string hostelPhoneNumber);

    void setHostelEmail(std::string hostelEmail);

    std::string getHostelName();

    std::string getHostelAddress();

    std::string getHostelPhoneNumber();

    std::string getHostelEmail();

    void setMode(int mode);

    bool getMode();

    void displayHostelInfo();

};