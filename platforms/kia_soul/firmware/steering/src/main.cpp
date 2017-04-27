// Steering control ECU firmware
// 2014 Kia Soul Motor Driven Power Steering (MDPS) system


#include "arduino_init.h"
#include "debug.h"

#include "init.h"
#include "communications.h"
#include "steering_control.h"


int main( void )
{
    init_arduino( );

    init_globals( );

    init_devices( );

    init_communication_interfaces( );

    DEBUG_PRINTLN( "initialization complete" );

    while( true )
    {
        check_for_incoming_message( );

        check_for_controller_command_timeout( );

        check_for_operator_override( );

        publish_reports( );
    }
}
