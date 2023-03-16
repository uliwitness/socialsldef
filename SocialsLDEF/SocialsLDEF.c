#include <Controls.h>
#include <QuickDraw.h>
#include <SetUpA4.h>
#include <A4Stuff.h>
#include <math.h>
#include "SocialsLDEF.h"
#include "SocialsLDEFData.h"

pascal void main(short message, Boolean selected, Rect *cellVisRect, Cell theCell, short dataOffset,
				 short dataLen, ListHandle theList) {
	EnterCodeResource();
	
	switch (message) {
		case lInitMsg:
			if ((**theList).cellSize.v < 34 + 30) {
				(**theList).cellSize.v = 34 + 30;
			}
			break;
			
		case lDrawMsg:
			if (dataLen == 0) {
				return;
			}
			{
			GrafPtr currentPort;
			GetPort(&currentPort);
			RgnHandle oldClip = NewRgn();
			PenState state = {};
			struct SocialsEntry *data = NULL;
			Rect cellRect = {0,0,0,0};
			Rect iconRect = {0,0,0,0};
			LRect(&cellRect, theCell, theList);
			iconRect = cellRect;
			FontInfo fontInfo = {};
			short topOffset = 4;
			data = (struct SocialsEntry *) ((*(**theList).cells) + dataOffset);
			iconRect.left += 4;
			iconRect.right = iconRect.left + 32;
			iconRect.top += topOffset;
			iconRect.bottom = iconRect.top + 32;
			GetClip(oldClip);
			GetPenState(&state);
			ClipRect(cellVisRect);
			
			TextSize(9);
			GetFontInfo(&fontInfo);
			
			ForeColor(whiteColor);
			PaintRect(&cellRect);
			ForeColor(blackColor);
			TextFace(bold);
			short textV = iconRect.top + fontInfo.ascent;
			MoveTo(iconRect.right + 4, textV);
			DrawString(data->userName);
			TextFace(normal);
			if (data->avatar) {
				HLock((Handle)data->avatar);
				if (data->avatarPixelData) {
					HLock(data->avatarPixelData);
					(**data->avatar).baseAddr = *data->avatarPixelData;
				}
				CopyBits((const BitMap *)(*data->avatar),
                         &currentPort->portBits,
                         &(**data->avatar).bounds,
                         &iconRect,
                         ditherCopy,
                         NULL);
				if (data->avatarPixelData) {
					HUnlock(data->avatarPixelData);
				}
				HUnlock((Handle)data->avatar);
			} else {
				PaintRect(&iconRect);
			}
			
			short messageLen = dataLen - sizeof(struct SocialsEntry) + 1;			
			Rect messageRect = cellRect;
			messageRect.top = textV + fontInfo.descent + fontInfo.leading;
			messageRect.left = iconRect.right + 4;
			TETextBox(data->message, messageLen,
                      &messageRect,
                      teJustLeft);
			
			if (selected) {
				LMSetHiliteMode(LMGetHiliteMode() & ~(1 << 7));
				InvertRect(&cellRect);
			}
			
			SetClip(oldClip);
			DisposeRgn(oldClip);
			SetPenState(&state);
			break;
		}
		
		case lHiliteMsg: {
			RgnHandle oldClip = NewRgn();
			PenState state = {};
			
			GetClip(oldClip);
			GetPenState(&state);
			ClipRect(cellVisRect);
			
			LMSetHiliteMode(LMGetHiliteMode() & ~(1 << 7));
			InvertRect(cellVisRect);
			
			SetClip(oldClip);
			DisposeRgn(oldClip);
			SetPenState(&state);
			break;
		}
			
		case lCloseMsg:
			break;
	}
	
	ExitCodeResource();
}