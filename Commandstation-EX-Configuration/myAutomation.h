#include "myAliases.h"
#include "myDevices.h"


/* This is an automation example file.
 *  The presence of a file called "myAutomation.h" brings EX-RAIL code into
 *  the command station.
 *  The automation may have multiple concurrent tasks.
 *  A task may 
 *  - Act as a ROUTE setup macro for a user to drive over 
 *  - drive a loco through an AUTOMATION 
 *  - automate some cosmetic part of the layout without any loco.
 *  
 *  At startup, a single task is created to execute the startup sequence.
 *  This task may simply follow a route, or may START  
 *  further tasks (that is.. send a loco out along a route).
 *  
 *  Where the loco id is not known at compile time, a new task 
 *  can be created with the command:
 *  </ START [cab] route> 
 *  
 *  A ROUTE, AUTOMATION or SEQUENCE are internally identical in ExRail terms  
 *  but are just represented differently to a Withrottle user:
 *  ROUTE(n,"name") - as Route_n .. to setup a route through a layout
 *  AUTOMATION(n,"name") as Auto_n .. to send the current loco off along an automated journey
 *  SEQUENCE(n) is not visible to Withrottle.
 *  
 */
 		


AUTOSTART
  POWERON        // turn on track power
  DELAY(1000)    // delay required after Power ON
  //LCD(0, "16x2 LCD Display") // Display message on LCD
  //SCREEN(DSP_MAIN, 0, " Hello ") // Display message on OLED
  //SCREEN(DSP_MAIN, 1, "--------------------")
  
  CALL(PROC_PGM_CLOSE)
  CALL(PROC_01)
 // SETLOCO(1022)   // select some loco to enable 
 // FWD(20)
 CALL(PROC_RESET)
DONE     // This just ends the startup thread, leaving 2 others running.


   
ROUTE(RT_01, "Tor_2-A Stop")
  CALL(PROC_01)
DONE  

SEQUENCE(PROC_01)
  RED(SH1)
  CLOSE(TRN_01)
  ROUTE_ACTIVE(RT_01)
  ROUTE_INACTIVE(RT_02)
RETURN

ROUTE(RT_02, "Tor_2-A GO")
  GREEN(SH1a)
  THROW(TRN_01)
  ROUTE_ACTIVE(RT_02)
  ROUTE_INACTIVE(RT_01)
DONE  


// CV Programming
ROUTE(RT_PGM_OPEN,"Open CV PGM")
  CALL(PROC_PGM_OPEN)
DONE

ROUTE(RT_PGM_CLOSE,"Close CV PGM")
  CALL(PROC_PGM_CLOSE)
DONE

SEQUENCE(PROC_PGM_OPEN)
  ROUTE_HIDDEN(RT_PGM_OPEN)
  ROUTE_INACTIVE(RT_PGM_CLOSE)
  ROUTE_INACTIVE(RT_PGM_SH5)
RETURN

//AUTOSTART
SEQUENCE(PROC_PGM_CLOSE) 
  ROUTE_HIDDEN(RT_PGM_CLOSE)
  ROUTE_INACTIVE(RT_PGM_OPEN)
  ROUTE_HIDDEN(RT_PGM_SH5)
RETURN

#define CV_PROG_DELAY  DELAY(2000) 
ROUTE(RT_PGM_SH5, "PGM_SH5")
  // Aspect 1+ S1
  PARSE("<W 547 31>") 
  CV_PROG_DELAY
  PARSE("<W 548 4>") 
  CV_PROG_DELAY
  PARSE("<W 549 0>") 
  CV_PROG_DELAY
  PARSE("<W 550 0>") 
  DELAY(2000)
  // Aspect 1- S2
  PARSE("<W 551 31>") 
  CV_PROG_DELAY
  PARSE("<W 552 1>") 
  CV_PROG_DELAY
  PARSE("<W 553 0>") 
  CV_PROG_DELAY
  PARSE("<W 554 0>") 
  CV_PROG_DELAY
// Aspect 2+ S3
  PARSE("<W 555 31>") 
  CV_PROG_DELAY
  PARSE("<W 556 1>") 
  CV_PROG_DELAY
  PARSE("<W 557 1>") 
  CV_PROG_DELAY
  PARSE("<W 558 0>") 
  CV_PROG_DELAY
  // Aspect 2- S4
  PARSE("<W 559 31>") 
  CV_PROG_DELAY
  PARSE("<W 560 2>") 
  CV_PROG_DELAY
  PARSE("<W 561 2>") 
  CV_PROG_DELAY
  PARSE("<W 562 0>") 
  CV_PROG_DELAY
  // Aspect 3+ S5
  PARSE("<W 563 31>") 
  CV_PROG_DELAY
  PARSE("<W 564 2>") 
  CV_PROG_DELAY
  PARSE("<W 565 0>") 
  CV_PROG_DELAY
  PARSE("<W 566 0>") 
  CV_PROG_DELAY
  // Aspect 3- S10
  PARSE("<W 567 31>") 
  CV_PROG_DELAY
  PARSE("<W 568 9>") 
  CV_PROG_DELAY
  PARSE("<W 569 0>") 
  CV_PROG_DELAY
  PARSE("<W 570 0>") 
  CV_PROG_DELAY
  // Aspect 4+ S11
  PARSE("<W 571 31>") 
  CV_PROG_DELAY
  PARSE("<W 572 9>") 
  CV_PROG_DELAY
  PARSE("<W 573 8>") 
  CV_PROG_DELAY
  PARSE("<W 574 0>") 
  CV_PROG_DELAY
  // Aspect 4- S12
  PARSE("<W 575 31>") 
  CV_PROG_DELAY
  PARSE("<W 576 10>") 
  CV_PROG_DELAY
  PARSE("<W 577 2>") 
  CV_PROG_DELAY
  PARSE("<W 578 0>") 
  CV_PROG_DELAY
  // Aspect 5+ S13
  PARSE("<W 579 31>") 
  CV_PROG_DELAY
  PARSE("<W 580 10>") 
  CV_PROG_DELAY
  PARSE("<W 581 0>") 
  CV_PROG_DELAY
  PARSE("<W 582 0>") 
  CV_PROG_DELAY
  // Aspect 5- Sz
  PARSE("<W 583 31>") 
  CV_PROG_DELAY
  PARSE("<W 584 20>") 
  CV_PROG_DELAY
  PARSE("<W 585 16>") 
  CV_PROG_DELAY
  PARSE("<W 586 0>") 
  CV_PROG_DELAY
  // Aspect 6+ S1
  PARSE("<W 587 224>") 
  CV_PROG_DELAY
  PARSE("<W 588 64>") 
  CV_PROG_DELAY
  PARSE("<W 589 0>") 
  CV_PROG_DELAY
  PARSE("<W 590 0>") 
  CV_PROG_DELAY
  // Aspect 6- S2
  PARSE("<W 591 224>") 
  CV_PROG_DELAY
  PARSE("<W 592 32>") 
  CV_PROG_DELAY
  PARSE("<W 593 0>") 
  CV_PROG_DELAY
  PARSE("<W 594 0>") 
  CV_PROG_DELAY
  // Aspect 7+ S3
  PARSE("<W 595 224>") 
  CV_PROG_DELAY
  PARSE("<W 596 32>") 
  CV_PROG_DELAY
  PARSE("<W 597 32>") 
  CV_PROG_DELAY
  PARSE("<W 598 0>") 
  CV_PROG_DELAY
  // Aspect 7- S5
  PARSE("<W 599 224>") 
  CV_PROG_DELAY
  PARSE("<W 600 128>") 
  CV_PROG_DELAY
  PARSE("<W 601 0>") 
  CV_PROG_DELAY
  PARSE("<W 602 0>") 
  CV_PROG_DELAY
DONE  


SEQUENCE(PROC_RESET)
CLOSE(TRN_01)
CLOSE(TRN_02)
CLOSE(TRN_03)
CLOSE(TRN_04)
CLOSE(TRN_05)
CLOSE(TRN_06)
CLOSE(TRN_07)
CLOSE(TRN_08)
CLOSE(TRN_09)
CLOSE(TRN_10)
RETURN