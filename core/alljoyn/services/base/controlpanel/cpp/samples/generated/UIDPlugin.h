#ifndef UID_PLUGIN_H__
#define UID_PLUGIN_H_

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
#define IN  0
#define OUT 1
 
#define LOW  0
#define HIGH 1

#define 	GPIO2  		2 	/* P1-03 */
#define 	GPIO3  		3 	/* P1-05 */
#define 	GPIO4  		4 	/* P1-07 */
#define 	GPIO14 		14 	/* P1-08 */
#define 	GPIO15		15	/* P1-10 */
#define 	GPIO17		17	/* P1-11 */
#define 	GPIO18		18 	/* P1-12 */
#define 	GPIO27		27	/* P1-13 */
#define 	GPIO22		22	/* P1-15 */
#define 	GPIO23		23	/* P1-16 */
#define 	GPIO24		24	/* P1-18 */
#define 	GPIO10		10	/* P1-19 */
#define 	GPIO9		9	/* P1-21 */
#define 	GPIO25		25	/* P1-22 */
#define 	GPIO11		11	/* P1-23 */
#define 	GPIO8		8	/* P1-24 */
#define 	GPIO7		7	/* P1-26 */	

#define 	LED1 		GPIO4
#define		LED2		GPIO17
#define		LED3		GPIO22
#define		LED4		GPIO10
#define		LED5		GPIO9
#define 	LED6		GPIO11
#define 	BUZZER		GPIO8
#define		SWITCH		GPIO7

#define BUFFER_MAX 3
#define DIRECTION_MAX 35
#define VALUE_MAX 30

namespace UIDAddons {

/**
 * implements UID Raspberry GPIO utilities
 * Exporting, setting direction, writing and reading values to/from GPIO Pins
 */
class UIDRPiGPIO  {

    public:
        UIDRPiGPIO();

        ~UIDRPiGPIO();

	int Export(int);   

	int Unexport(int);

	int Direction(int,int);

	int Read(int);

	int Write(int,int);

};

class UIDBerryClip {

public:
    UIDBerryClip();

    ~UIDBerryClip();

   int TurnOn(int);     

   int TurnOff(int);
 
   int Status(int);
     
};

} //namespace uid

#endif /* UID_PLUGIN_H_ */
