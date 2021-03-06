#ifndef UNIT_TEST

#include "Parser.h"
#include "Commands.h"


extern struct command uart_commands[];


char get_command(char* args, uint8_t args_length){
	
	//ensure there is something in the buffer
	while(!uart0_available());
	
	char command = uart0_getc();
    
    if(command == '\n')
		return command;
	
	//flush character following command
	while(!uart0_available());
	char symbol = uart0_getc();
	if(symbol == '\n')
		return command;
	
	uint16_t n=0;
	
	do{
		//error too long argument
		if(n >= args_length){
			
			//add string end character
			*(args + n - 1) = '\0';
			
			return 0;
		}
			
		while(!uart0_available());
		
		*(args + n) = uart0_getc();
		
		++n;
		
	} while(*(args + n -1) != '\n');
	
	//add string end character
	*(args + n - 1) = '\0';
	
	return command;
}

void execute_command(const char command, const char* arg){
	
	//search known commands
	for(int n=0; n < commands_count; ++n){
		
		//command known?
		if(command == uart_commands[n].symbol){
			
			//execute
			uart_commands[n].function_ptr(arg);
			return;
		}
	}
	//not found
	uart0_putc(command);
	uart0_puts(" :Command not known: h for help\n");
}


void handle_uart_input(){
	char args[MAX_ARG_LENGHT] = {0};
	char command = get_command((char*)args, MAX_ARG_LENGHT);
	execute_command(command, (char*)args);
}

#endif
