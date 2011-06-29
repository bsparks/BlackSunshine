// basic recreation of the standard 3d app from the wizard

// required function, this takes place just before LoopGDK begins
function onBeforeGameLoop()
{
	// in this application we are going to create some 3D objects
	// and position them on screen

	// when starting a Dark GDK program it is useful to set global
	// application properties, we begin by turning the sync rate on,
	// this means we control when the screen is updated, we also set
	// the maximum rate to 60 which means the maximum frame rate will
	// be set at 60 frames per second
	dbSyncOn();
	dbSyncRate(60);

	// set our random seed to a value from the timer, this will help
	// to ensure each time we run our program the random values appear
	// more random
	dbRandomize(dbTimer());

	// make some 3D objects
	for (var i=1; i<50; i++)
	{
		// make a sphere
		dbMakeObjectSphere(i, 1);

		// position the object in a random location
		dbPositionObject(i, dbRnd(20), dbRnd(20), dbRnd(20));

		// adjust scaling
		dbScaleObject(i, 100 + dbRnd(400), 100 + dbRnd(400), 100 + dbRnd(400));

		// give the object a color
		dbColorObject(i, dbRGB(dbRnd(255), dbRnd(255), dbRnd(255)));

		// increase specular power
		dbSetObjectSpecularPower(i, 255);

		// turn off ambient lighting for this object
		dbSetObjectAmbient(i, 0);
	}
	
	// move our camera back so we can view the objects
	dbPositionCamera(10, 10, -20);
}

// required function, this takes place inside LoopGDK
function onRenderFrame()
{
	dbText(0, 0, "Use the up and down arrow keys to move the camera.");
    dbText(0, 20, dbScanCode());
	
	// move the camera forwards
	if(dbUpKey())
		dbMoveCamera(0, 1);
		
	// move the camera backwards
	if(dbDownKey())
		dbMoveCamera(0, -1);
		
	// rotate all of our objects
	for(var i=1; i<50; i++)
		dbRotateObject(i, dbObjectAngleX(i) + 0.1, dbObjectAngleY(i) + 0.2, dbObjectAngleZ(i) + 0.3);
		
	// here we make a call to update the contents of the screen
	//dbSync();
}

// happens after LoopGDK before return to windows
function onGameShutdown()
{
	// cleanup objects if they still exist
	for(var i=1; i<50; i++) {
		if(dbObjectExist(i))
			dbDeleteObject(i);
	}
}