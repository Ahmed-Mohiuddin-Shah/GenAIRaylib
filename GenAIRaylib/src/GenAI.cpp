#include "GenAI.h"

GenAI::GenAI()
{
    this->seriousMode = true;
}

GenAI::GenAI(JSON genAIInfoJson)
{
    this->seriousMode = genAIInfoJson["s_mode"];
}

JSON GenAI::toJson()
{
    JSON genAIInfoJson;

    genAIInfoJson["mode"] = getMode();

    return genAIInfoJson;
}

void GenAI::setMode(int mode)
{
    seriousMode = mode;
}

bool GenAI::getMode()
{
    return seriousMode;
}