# parsonsDIWire
Parsons MFA Industrial Design DIWire bender built from Pensa's open source plans

    *Team:
        Tim Ronco
        Joonas Kystila
        Matt Calahan
        Lisa Marks
        Carson Lai
        Mike Soroka

    *Software Block Diagram
        DIWire.ino
            maintain syncronization with modules and external control
        BenderPinDuckAndMove.ino
            controls movement of solenoid
        benderPinMovement.ino
            applies angle change to bender pin motor
        WireFeed.ino
            advances wire position
        zMotorBend.ino
            3D bend control 
        