#include <iostream>
#include <vector>

#include "nlohmann/json.hpp"
#include "FileReader.h"

using JSON = nlohmann::json;

class GenAI
{
private:
    bool seriousMode;

public:
    GenAI();

    GenAI(JSON genAIInfoJson);

    JSON toJson();

    void setMode(int mode);

    bool getMode();
};