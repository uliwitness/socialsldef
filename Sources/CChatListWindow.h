#pragma once

#include "CWindow.h"
#include "CFileSpec.h"

class CListManagerWindowAttachment;

class CChatListWindow : public CWindow {
public:
	CChatListWindow(CCommandHandler* parent = NULL);

	virtual void CreateWindow();
	
	virtual void HandleCommand(OSType command, short menuID, short itemIndex);
	
protected:
	CListManagerWindowAttachment *mList;
};