#pragma once
#include "../HeaderFiles/Control.h"


Control::Control()
{
	gUI = new GUI();
}




void Control::Run()
{
	Event CurrentEvent;
	while (gUI->Is_Open())
	{
		while (gUI->PollNextEvent(CurrentEvent))
		{
			switch (CurrentEvent.type)
			{
				//Activate close button
				case Event::Closed:
				{
					gUI->CloseWindow();
					break;
				}
				case Event::KeyReleased:
				{
					if (CurrentEvent.key.code == Keyboard::Escape)
					{
						gUI->CloseWindow();
					}
					break;
				}
				default:
				{
					gUI->RunPage(CurrentEvent);
					break;
				}
			}
		}
		gUI->ClearWindow();
		gUI->DrawPage();
	}
}