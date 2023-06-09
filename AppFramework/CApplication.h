#pragma once

#include "CCommandHandler.h"
#include "CFileSpec.h"
#include <Types.h>

class CApplicationDelegate : public CCommandHandler {
public:
	CApplicationDelegate(CCommandHandler* parent) : CCommandHandler(parent) {}

	virtual void StartUp() {}
	virtual void OpenUntitledDocument() {}
	virtual void OpenDocument(CFileSpec */*inFile*/) {}
	virtual bool ShouldShutDown() { return true; }
};

class CApplication : public CCommandHandler {
public:
	CApplication() : CCommandHandler(NULL), mDelegate(NULL), mQuit(false) {}

	void Run();
	
	virtual void HandleCommand(OSType command, short menuID, short itemIndex);
	virtual void UpdateCommand(OSType command, short menuID, short itemIndex);
	
	void SetDelegate(CApplicationDelegate * dele) { mDelegate = dele; }
	CApplicationDelegate* GetDelegate() { return mDelegate; }
	
	static CApplication* Singleton();

protected:
	void Initialize();
	void SendMenuChoice(short menuID, short itemIndex);
	void UpdateMenuItems();
	Boolean DequeueOneEvent(EventMask eventMask, EventRecord *outEvent);

	static pascal OSErr HandleODoc(const AppleEvent *theAppleEvent, AppleEvent *reply, unsigned long handlerRefcon);
	static pascal OSErr HandleOApp(const AppleEvent *theAppleEvent, AppleEvent *reply, unsigned long handlerRefcon);

	CApplicationDelegate	*mDelegate;
	Boolean 				mQuit;
	EventRecord				mCurrentEvent;
	Boolean 				mHaveAppleEvents;
	Boolean					mHaveWaitNextEvent;
};