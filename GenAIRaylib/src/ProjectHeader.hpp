#pragma once

#define _CRT_SECURE_NO_WARNINGS

// --------------------------
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
#include <algorithm>


// Includes for MultiThreading
#include <future>
#include <chrono>
#include <thread>

// Includes for File Handling
#include "nlohmann/json.hpp"
#include "FileReader.h"

using JSON = nlohmann::json;

namespace ProjectInfo
{
	// Project Info
	const char* appName = "Hostel Management System";

	// Defaults for file handling
	std::string fileName = "config.json";
}

// Include for Hostel Class
#include "GenAI.h"

GenAI genAIInstance;

// Includes For GUI APP
#include "raylib.h"
#include "variabledefinitions.h"
#include "helperfunctions.h"

// Include for GUI elements Classes
#include "GUIElementsClasses.hpp"

// Include for Custom Library
#include "flavortext.h"

// Includes for Screen layers
#include "overlay.h"
#include "loadingScreen.h"
#include "fatalErrorScreen.h"
#include "createNewHostelScreen.h"
#include "homeScreen.h"
#include "hostelDetailsScreen.h"
#include "exitScreen.h"