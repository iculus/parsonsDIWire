# parsonsDIWire
Parsons MFA Industrial Design DIWire bender built from Pensa's open source plans

    Team:
        Tim Ronco
        Joonas Kystila
        Matt Calahan
        Lisa Marks
        Carson Lai
        Mike Soroka



## Software Block Diagram
    DIWire.ino
        master, maintain syncronization with modules and external control
    BenderPinDuckAndMove.ino
        controls movement of solenoid
    benderPinMovement.ino
        applies angle change to bender pin motor
    WireFeed.ino
        advances wire position
    zMotorBend.ino
        3D bend control to be implemented later

    to add later:
        motor control module
        2D vector software
        3D vector software
        joystick control software 
        rhinocerous direct drive software
         