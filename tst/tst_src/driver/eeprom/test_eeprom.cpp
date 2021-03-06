#include <catch2/catch.hpp>

#include <inttypes.h>

extern "C" {
#include "driver/eeprom/eeprom.h"
#include "MOCK_eeprom_hardware_mapping.h"
}

#include <iostream>


//TEST_CASE("test_internal_eeprom", "[eeprom]") {
    //test_init();

	//REQUIRE(sizeof(block) == EEPROM_BLOCK_SIZE);

	//eeprom_init(&eeprom_unittest);

	//get sentinel
	//REQUIRE(eeprom_unittest.current.read_position == 48);

	/*//get position
	uint16_t res = eeprom_get_latest_data_position((enum internal_eeprom_data_type)3, 2, 1);
	REQUIRE(res == 32);



	//write
	uint8_t data_dummy[BLOCK_DATA_SIZE] = {0x01, 0x02, 0x03};
	struct block block eeprom_data_to_block(&data_dummy, BLOCK_DATA_SIZE);
	eeprom_write_block(&block, (enum internal_eeprom_data_type)7, 0, 0);

	//read
	uint8_t data_res[BLOCK_DATA_SIZE];
	struct block block_res;
	eeprom_get_block((enum internal_eeprom_data_type)7, 0, &block_res);
	eeprom_data_to_block(&block_res, &data_res, BLOCK_DATA_SIZE);

	//check
	for (int n = 1; n < BLOCK_SIZE; ++n) {
		REQUIRE(data_res[n] == data_dummy[n]);
	}

	//write
	uint8_t data_dummy_2[16] = { 0x01, 0x04, 0x05, 0x06 };
	eeprom_write_block(&data_dummy_2);

	//read
	uint8_t data_res_2[16];
	eeprom_get_block(1, 0, &data_res_2);

	//check
	for (int n = 1; n < BLOCK_SIZE; ++n) {
		REQUIRE(data_res_2[n] == data_dummy_2[n]);
	}*/

//}
