// ScriptTimer.h
// class and functions for running time interval script calls

class Timer
{
public:
	Timer()
	{
		mFired = false;
	}

	~Timer()
	{
		//process_.Dispose();
	}

	void Init(const char* fn, int delay, bool recur)
	{
		mFunction = std::string(fn);
		mDelay = delay;
		mRecur = recur;
		mStartTime = dbTimer(); // set the start time immediately
	}

	bool ShouldFire(int elapsed)
	{
		if( (mStartTime + mDelay) < elapsed )
			return true;

		return false;
	}

	int    GetDelay()    { return mDelay; }
	bool   GetRecur()    { return mRecur; }

	bool   HasFired()    { return mFired; }

	void SetDelay(int value)     { mDelay = value;    }
	void SetRecur(bool r)        { mRecur = r;        }
	void SetStartTime(int time)  { mStartTime = time; mFired = false; }

	bool Fire() // execute the function
	{
		mFired = true;

		return ExecuteString(v8::String::New(mFunction.c_str()),
                  v8::String::New("(timer)"),
                  true,
                  true); 
	}

private:
	std::string mFunction;	// name of function to execute
	int mDelay;			// time to wait in ms
	int mStartTime;     // time in ms that it was created
	bool mRecur;		// does this timer keep going or execute only once
	bool mFired;        // has it fired already?
};

// global vector of timers
std::vector<Timer*> timerCache;

int AddTimer(Timer* timer)
{
	timerCache.push_back(timer);

	return timerCache.size() - 1;
}

// just delete the pointer and mark null (leave index alone)
void RemoveTimer(int idx)
{
	if(timerCache.size() > idx && !timerCache.empty())
	{
		SAFE_DELETE(timerCache[idx]);
	}
}

void ProcessTimers()
{
	std::vector<Timer*>::iterator it = timerCache.begin();
	while(it != timerCache.end())
	{
		if((*it) != NULL)
		{
			if((*it)->ShouldFire(dbTimer()) && !(*it)->HasFired())
			{
				// fire timer
				if((*it)->Fire())
				{			
					// if a recuring reset the time on it
					if((*it)->GetRecur())
					{
						(*it)->SetStartTime(dbTimer());
					}
					else
					{
						// not recuring, remove it from the cache
						RemoveTimer(it-timerCache.begin());
					}
				}
				else
				{
					// function failed to fire
					consoleBuffer.push_front("Error: Function failed to fire!");
				}
			}
		}

		it++;
	}
}

v8::Handle<v8::Value> setTimeout(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	// first arg is function name
	v8::String::Utf8Value str(args[0]);
    const char* cstr = ToCString(str);

	// second arg is delay
	int delay = args[1]->Int32Value();

	Timer* t = new Timer();
	t->Init(cstr, delay, false);

	int timerID = AddTimer(t);

	//delete t;

	return v8::Int32::New(timerID);
}

v8::Handle<v8::Value> setInterval(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	// first arg is function name
	v8::String::Utf8Value str(args[0]);
    const char* cstr = ToCString(str);

	// second arg is delay
	int delay = args[1]->Int32Value();

	Timer* t = new Timer();
	t->Init(cstr, delay, true);

	int timerID = AddTimer(t);

	//delete t;

	return v8::Int32::New(timerID);
}

// turns off the recur of the interval
v8::Handle<v8::Value> clearInterval(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int timerIdx = args[0]->Int32Value();

	RemoveTimer(timerIdx);

	/*
	if(timerCache.size() > timerIdx)
	{
		// free up memory for the timer
		SAFE_DELETE(timerCache[timerIdx]);
		//delete timerCache[timerIdx];
		//timerCache[timerIdx] = NULL;
		//timerCache[timerIdx]->SetRecur(false);
	}*/

	return v8::Undefined();
}

// removes a timeout, doesn't wait for it to tick again
v8::Handle<v8::Value> clearTimeout(const v8::Arguments& args)
{
	v8::HandleScope handle_scope;

	int timerIdx = args[0]->Int32Value();

	RemoveTimer(timerIdx);

	return v8::Undefined();
}

void RegisterScriptTimer(v8::Handle<v8::ObjectTemplate> &global)
{
	global->Set(v8::String::New("setTimeout"), v8::FunctionTemplate::New(setTimeout));
	global->Set(v8::String::New("setInterval"), v8::FunctionTemplate::New(setInterval));
	global->Set(v8::String::New("clearInterval"), v8::FunctionTemplate::New(clearInterval));
	global->Set(v8::String::New("clearTimeout"), v8::FunctionTemplate::New(clearTimeout));
}