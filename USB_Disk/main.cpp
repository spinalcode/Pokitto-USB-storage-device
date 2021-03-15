#include "Pokitto.h"
#include "USBMSD_SD.h"

 
using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PB = Pokitto::Buttons;

void init() {
    PD::persistence = true;
    PD::adjustCharStep = 0;
    
    PB::update();
    while(PB::aBtn()){
        PB::update();
    }
        
    
    PD::setColor(2);
    PD::print("---------------------------\n");
    //PD::print("           _     ___     __\n");
    //PD::print(" \\    //\\ |_)|\\ | | |\\ |/__\n");
    //PD::print("  \\/\\//--\\| \\| \\|_|_| \\|\\_|\n");
    PD::print(".  ..__..__ .  .._..  ..__\n"); 
    PD::print("|  |[__][__)|\\ | | |\\ |[ __\n");
    PD::print("|/\\||  ||  \\| \\|_|_| \\|[__]\n");
    PD::print("---------------------------\n");
    PD::setColor(1);
    PD::print("Use at own risk!\n");
    PD::print("We take  no  responsibility\n");
    PD::print("for any damage  incurred to\n");
    PD::print("either your  Pokitto(TM) or\n");
    PD::print("your   Micro SD(TM)   card,\n");
    PD::print("resulting from  the  use of\n");
    PD::print("this software.\n");
    PD::print("\n");
    PD::setColor(3);
    PD::print("Please make  sure  you have\n");
    PD::print("backed up your  card before\n");
    PD::print("continuing.\n");
    PD::print("\n");
    PD::setColor(4);
    PD::print("(A) Continue     (B) Cancel\n");
    PD::update();

    int option = 0;
    while(option == 0){
        PB::update();
        if(PB::aBtn()) option = 1;
        if(PB::bBtn()) option = 2;
    }

    if(option == 1){
        PD::clear();
        PD::setColor(5);
        PD::print("\n");
        PD::print("  .--------------------.\n");
        PD::print("  | .----------------. |\n");
        PD::print("  | |                | |\n");
        PD::print(" _| |  _   ,--()     | |_\n");
        PD::print("(_  | (_)-'-.------|>|  _)\n");
        PD::print("  | |        `--[]   | |\n");
        PD::print("  | |                | |\n");
        PD::print("  | `----------------' |\n");
        PD::print("  |    _          .-.  |\n");
        PD::print("  |  _| |_   .-. ( A ) |\n");
        PD::print("  | [_ o _] ( B ) '-'  |\n");
        PD::print("  |   |_|    '-'       |\n");
        PD::print("  |       ___          |\n");
        PD::print("  |      (___)         |\n");
        PD::print("  | .----------------. |\n");
        PD::print("  | |                | |\n");
        PD::print("  `-'                `-'\n");
    
        new USBMSD_SD(P0_9, P0_8, P0_6, P0_7); // P0_9, P0_8, P0_6, P0_7 = pins for SD card
    }
    
    if(option == 2) PC::jumpToLoader();
}

void update() {
}

