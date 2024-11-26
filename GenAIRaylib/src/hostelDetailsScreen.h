#pragma once

void hostelDetailsScreen() {
	using namespace variables;

	while (!layerChangedHandler())
	{
		// --------- Logic -----------------

		// --------- Drawing GUI -----------
		BeginDrawing();
		ClearBackground(H_DARK_GREY);
		drawCustomBodyText("Hostel DEETS:", Vector2{ 0, 0 }, variables::headings, 1, WHITE);
		/*drawCustomBodyText(TextFormat("Hostel Name          : %s", hostelName.c_str()), Vector2{0, 140}, variables::labels, 1, variables::H_BLUE);
		drawCustomBodyText(TextFormat("Hostel Address       : %s", hostelAddress.c_str()), Vector2{ 0, 170 }, variables::labels, 1, variables::H_BLUE);
		drawCustomBodyText(TextFormat("Hostel Phone Number  : %s", hostelPhNo.c_str()), Vector2{ 0, 200 }, variables::labels, 1, variables::H_BLUE);
		drawCustomBodyText(TextFormat("Hostel Email         : %s", hostelEmail.c_str()), Vector2{ 0, 230 }, variables::labels, 1, variables::H_BLUE);*/
		guiOverlay();
		EndDrawing();
	}
}