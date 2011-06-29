// DarkGDK - V8
// Ben (Warspawn)

#include <OIS.h>
#include "InputManager.h"

#include "GlobStruct.h"
// whenever using Dark GDK you must ensure you include the header file
#include "DarkGDK.h"

// include this main script file to use script engine
#include "ScriptEngine.h"

void OutException(const char * _caption, const char * _message) { ::MessageBox( NULL, _message, _caption, MB_OK | MB_ICONERROR | MB_TASKMODAL); }

input::InputManager* g_InputManager = nullptr;

// the main entry point for the application is this function
void DarkGDK ( void )
{    
    // init input mgr
    g_InputManager = new input::InputManager();
    g_InputManager->createInput((size_t) g_pGlob->hWnd);
    g_InputManager->setInputViewSize(dbScreenWidth(), dbScreenHeight());
    
    // init gui system
    g_GuiPlatform = new MyGUI::DirectXPlatform();
    g_GuiPlatform->initialise(dbGetDirect3DDevice());
    
    g_GuiPlatform->getDataManagerPtr()->addResourceLocation("./Common/gui", false);
    g_Gui = new MyGUI::Gui();
    g_Gui->initialise("core.xml");

    // initialize the script engine
	InitScriptEngine();

	v8::HandleScope handle_scope;
	// enter script context
	v8::Context::Scope context_scope(gScriptContext);

	// last chance callback to do anything before the main loop
	cbOnBeforeGameLoop->Call(gScriptContext->Global(), 0, NULL);

	int keyTimer = 0;
	int keyPressed = 0;
    int keyLast = 0;
	bool consoleActive = false;  

    int mouseClicked = 0;
    int mouseLast = 0;

    //g_Gui->load("console.layout");

   // dbHideMouse();
	// now we come to our main loop, we call LoopGDK so some internal
	// work can be carried out by the GDK
	while ( LoopGDK ( ) )
	{
        
        g_InputManager->captureInput();

		ProcessTimers();

		// execute the script call back for inside the loop
		cbOnRenderFrame->Call(gScriptContext->Global(), 0, NULL);

        g_GuiPlatform->getRenderManagerPtr()->drawOneFrame();
        /*
        // inform gui of mouse movement
        g_Gui->injectMouseMove(dbMouseX(), dbMouseY(), dbMouseZ());
        // inform gui of mouse clicks (and releases)
        mouseClicked = dbMouseClick();
        if(mouseClicked) {
            // if the mouse clicked isn't the same one it was before, indicate release of old one
            if(mouseClicked != mouseLast && mouseLast != 0) {
                g_Gui->injectMouseRelease(dbMouseX(), dbMouseY(), MyGUI::MouseButton::Enum(mouseLast-1));
            }
            mouseLast = mouseClicked;
            // inform gui of new mouse clicked (mouse clicks in DB are one off
            g_Gui->injectMousePress(dbMouseX(), dbMouseY(), MyGUI::MouseButton::Enum(mouseClicked-1));
        } else {
            if(mouseLast) {
                switch(mouseLast) {
                    case 1:
                        g_Gui->injectMouseRelease(dbMouseX(), dbMouseY(), MyGUI::MouseButton::Left);
                        break;
                    case 2:
                        g_Gui->injectMouseRelease(dbMouseX(), dbMouseY(), MyGUI::MouseButton::Right);
                        break;
                    default:
                        break;
                }
                mouseLast = 0;
            }
        }

        // inform gui of keys pressed
        keyPressed = dbScanCode();
        // what is 217? it comes up a lot on my keyboard...
        if(keyPressed != 0 && keyPressed != 217 && keyTimer < dbTimer()) {
            keyTimer = dbTimer() + 200;
            // if the last key pressed isn't this one (held down),
            // inform gui that the old key was released
            if(keyPressed != keyLast && keyLast != 0) {
                g_Gui->injectKeyRelease(MyGUI::KeyCode::Enum(keyLast));
            }
            keyLast = keyPressed;
            // inform gui of new key
            g_Gui->injectKeyPress(MyGUI::KeyCode::Enum(keyPressed), dbAsc(dbInKey()));

            // temp
            if(keyPressed == 41)
            {
                consoleActive = !consoleActive;
                dbClearEntryBuffer();
            }

            if(consoleActive && dbReturnKey())
		    {
			    keyTimer = dbTimer() + 200;
			    //char* entry = dbEntry();
			    consoleBuffer.push_front(dbEntry());
			    dbClearEntryBuffer(); // clear out the entry buffer...
			    ExecuteString(v8::String::New(consoleBuffer.front()),
                      v8::String::New("(console)"),
                      true,
                      true);
			    while(consoleBuffer.size() > 100)
			    {
				    consoleBuffer.pop_back();
			    }
		    }
        } else {
            // no key pressed, if there was one, release it
            if(keyLast) {
                g_Gui->injectKeyRelease(MyGUI::KeyCode::Enum(keyLast));
                keyLast = 0;
            }
        }*/
        

		if(dbScanCode() == 41 && keyTimer < dbTimer()) // ~ to open console
		{
			//dbText(0,0,"WTF");
			keyTimer = dbTimer() + 200;
			consoleActive = !consoleActive; // toggle
			dbClearEntryBuffer(); // clear out the entry buffer...
		}

		if(consoleActive && dbReturnKey() && keyTimer < dbTimer())
	    {
		    keyTimer = dbTimer() + 200;
		    //char* entry = dbEntry();
		    consoleBuffer.push_front(dbEntry());
		    dbClearEntryBuffer(); // clear out the entry buffer...
		    ExecuteString(v8::String::New(consoleBuffer.front()),
                  v8::String::New("(console)"),
                  true,
                  true);
		    while(consoleBuffer.size() > 100)
		    {
			    consoleBuffer.pop_back();
		    }
	    }

		if(consoleActive)
		{
			// display semi transparent box for "console"
			dbInk(dbRGB(0,0,0), dbRGB(0,0,0));
			dbBox(0,0,dbScreenWidth(), 160);
			dbInk(dbRGB(106, 90, 205), 0);
			dbBox(0,160, dbScreenWidth(), 180);
			dbInk(dbRGB(255,255,255), dbRGB(0,0,0));

			dbText(0, 160, ">");
			dbText(10, 160, dbEntry()); // main entry line always present
			int i = 0;
			while(i < consoleBuffer.size() && i < 8)
			{
				dbText(10, (160 - (20 * (i + 1))), ToCharString(consoleBuffer[i]));
				dbText(0, (160 - (20 * (i + 1))), ":");
				i++;
			}
		}

		dbSync();
        
	}

	// execute the script call back for after loop ends before shutdown
	cbOnGameShutdown->Call(gScriptContext->Global(), 0, NULL);

    if(g_InputManager) {
        g_InputManager->destroyInput();
        delete g_InputManager;
    }

    // cleanup gui
    if(g_Gui) {
        g_Gui->shutdown();
        delete g_Gui;
    }
    if(g_GuiPlatform) {
        g_GuiPlatform->shutdown();
        delete g_GuiPlatform;
    }

	// and now everything is ready to return back to Windows
	return;
}