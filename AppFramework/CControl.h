#pragma once

#include <Controls.h>

class CWindow;

#include "EAutoPositionFlags.h"

class CControl {
public:
	CControl(CWindow* wd, Rect* box, Str255 title, SInt16 value, SInt16 min, SInt16 max, SInt16 procID);
	virtual ~CControl() { DisposeControl(mControlHandle); mControlHandle = NULL; }
	
	void AutoPositionInWindow();
	
	void SetAutoPositionFlags(EAutoPositionFlags flags) { mAutoPositionFlags = flags; }
	
	virtual void Activate();
	virtual void Deactivate();
	
	virtual void HandleClick(ControlPartCode) {}

	virtual void HandleMouseDown(const EventRecord& event);
	
protected:
	EAutoPositionFlags mAutoPositionFlags;
	short mLeftDistance;
	short mRightDistance;
	short mTopDistance;
	short mBottomDistance;
	ControlHandle mControlHandle;
	CControl *mNext;
	
	friend class CWindow;
};