#pragma once

#include "CCommandHandler.h"
#include "EAutoPositionFlags.h"

class CWindow;

// Class for attaching your own "Views" to a window that can't be controls (e.g. because they
// need to use other controls).
class CWindowAttachment : public CCommandHandler {
public:
	CWindowAttachment(CWindow *wd);
	virtual ~CWindowAttachment() {}
	
	// Port is already set up for you here. BeginUpdate has been called, EndUpdate will be called after.
	virtual void Draw() {}
	
	// Return true if the click was in your object and the click should not be passed on to the next attachment.
	virtual bool HandleMouseDown(const EventRecord &) { return false; }
	
	virtual void ResizedWindowFrom(Point) {}
	
	virtual void Activate() {}
	virtual void Deactivate() {}
	
	void SetAutoPositionFlags(EAutoPositionFlags flags) { mAutoPositionFlags = flags; }

protected:
	void ResizedFromOldToNewWindowRect(Rect *box, Point oldSize, Rect *newWdRect);

	CWindowAttachment *mNext;
	CWindow *mWindow;
	EAutoPositionFlags mAutoPositionFlags;
		
	friend class CWindow;
};
