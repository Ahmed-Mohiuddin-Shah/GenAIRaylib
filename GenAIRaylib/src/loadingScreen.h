#pragma once

variables::FileLoadStatus loadGenAIConfig() {

	std::this_thread::sleep_for(std::chrono::seconds(3));  // HEHE Delay for Funsies :)

	using namespace variables;
	if (!FileReader::checkIfFileExists(ProjectInfo::fileName)) {
		return DOES_NOT_EXIST;
	}
	try
	{
		fileContent = FileReader::readFromFile(ProjectInfo::fileName);
		return LOADED_SUCCESSFULLY;
	}
	catch (const std::exception&)
	{
		return FAILED_TO_LOAD;
	}
}

void loadingScreen() {
	using namespace variables;
	using namespace std::chrono_literals;

	std::future<FileLoadStatus> f = std::async(std::launch::async, loadGenAIConfig);
	
	int textGenDelay = int(targetFPS / 2);
	int textGenCounter = 0;

	std::string randomLoadingText = getRandomString(true);

	while (f.wait_for(1us) != std::future_status::ready)
	{
		// --------- Logic -----------------

		if (textGenCounter > textGenDelay) {
			randomLoadingText = getRandomString(true);
			textGenCounter = 0;
		}
		else {
			textGenCounter++;
		}

		// --------- Drawing GUI -----------
		BeginDrawing();
		ClearBackground(H_DARK_GREY);
		drawCustomText(randomLoadingText.c_str(), Vector2{ 400, 600 }, labels, 1, H_WHITE);
		animateBugCatGIF(Vector2{ 0, 400 });
		EndDrawing();
	}

	f.wait();
	FileLoadStatus fileStatus = f.get();

	switch (fileStatus)
	{
	case variables::DOES_NOT_EXIST:
		currentLayer = HOME_SCREEN;   // TODO: Change to FATAL_ERROR_SCREEN
		break;
	case variables::LOADED_SUCCESSFULLY:

		try
		{
			genAIInfoJson = JSON::parse(fileContent);
			genAIInstance = GenAI(genAIInfoJson);
		}
		catch (const std::exception e)
		{
			fatalErrorMessage = e.what() + std::string("\nFileContent: ") + fileContent + std::string("\ngenAIJSON") + genAIInfoJson.dump() + std::string("\nIssue In Gen AI JSON Text File\nExit Porgram and create a new one.\nOr if you have a copy of HostelData.txt then restore from there");
			currentLayer = FATAL_ERROR_SCREEN;
			return;
		}

		globalShouldShowSuccessPopup = true;
		successPopupMessage = "Config Loaded Successfully!!";
		currentLayer = HOME_SCREEN;
		break;
	case variables::FAILED_TO_LOAD:
		currentLayer = FATAL_ERROR_SCREEN;
		break;
	}
}