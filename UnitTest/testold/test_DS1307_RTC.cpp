#include <catch2/catch.hpp>

#include <iostream>

#include "J:/MeineDaten/Projekte/ElektronikProjekte/HochbeetSteuerung/Firmware/Firmware/RbCtlMPLABX.X/DS1307_RTC.h"



TEST_CASE("Test min year", "[DS1307_RTC]") {
	REQUIRE(DS1307_MIN_YEAR == 2020);
}


TEST_CASE("DS1307_set_time", "[DS1307_RTC]") {
	struct tm newTM{0, 32, 12, 6, 0, 9, 120};
	//DS1307_set_time(&newTM);
}




