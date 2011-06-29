// main entry point for exe
// can load up any javascript you want here, or leave it all to the game
// here you could have stuff common to all games

// load up the game
load("Example1 - Basic3D/main.js");
//load("Example2 - Simple Maze/main.js");
//load("Dungeons Deep/deepMain.js");
//load("Miner/main.js");

// **REQUIRED** function, this takes place just before LoopGDK begins
// in this file just a stub to be overwritten by game instance
function onBeforeGameLoop() { }

// **REQUIRED** function, this takes place inside LoopGDK
function onRenderFrame() { }

// **REQUIRED** happens after LoopGDK before return to windows
// in this file just a stub to be overwritten by game instance
function onGameShutdown() { }